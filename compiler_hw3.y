/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    // #define YYDEBUG 1
    // int yydebug = 1;
    
    #define FILE_NAME "hw3"
    #define STACK_SIZE 100
    #define SCOPE 10

    #define typeI 0
    #define typeB 1
    #define typeF 2
    #define typeS 3

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    typedef struct{
        int index;
        char* name;
        char* type;
        int lineno;
        char* element;
        int scope;
    }table_entry;

    table_entry table[100];

    FILE *file;

    int scope = 0;
    int block_entry[10];
    int total_entry ;

    int id_type, var_type;
    char type_flag[10];

    bool HAS_ERROR = false;

    int Find_scope, Find_index;
    char Find_type[10];
    char Variable[30];
    int type_flag_gen=0;

    void yyerror (char const *s)
    {
        if(strcmp(s,"int32")==0 || strcmp(s,"float32")==0){
            printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, s);
        }
        else{
            printf("error:%d: %s\n", yylineno, s);
        }
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol();
    static void insert_symbol(int, char*, char*, int, char*);
    static int lookup_symbol(char*, int);
    static void dump_symbol(int);
        
    /* code gen function */

    void get_return_type(char type[10]);
    void find_index_and_scope_andtype();
    void store_code_gen();
    void load_code_gen();
    void compare_result_code_gen(char compare_type[10]);
    void compare(char operator[10]);
    void return_code_gen();
    void arith_code_gen(char operator[10]);
    void type_casting();
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    int si_val;
    float f_val;
    float sf_val;
    char *s_val;
    char *id_val;
    /* ... */
}

/* Token without return */
%token VAR
%token INT FLOAT BOOL STRING
%token INC DEC GEQ LEQ EQL NEQ ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN
%token QUO_ASSIGN REM_ASSIGN LAND LOR NEWLINE PRINT PRINTLN IF ELSE FOR 
%token TRUE FALSE

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <si_val> SIGN_INT_LIT
%token <f_val> FLOAT_LIT
%token <sf_val> SIGN_FLOAT_LIT
%token <s_val> STRING_LIT
%token <id_val> ID

/* Nonterminal with return, which need to sepcify type */


/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : stmt stmts 
    |
;

stmts
    : stmt stmts
    | { dump_symbol(scope); }
;

stmt
    : declaration
    | print_stmt
    | error_stmt
    | if_stmt
    | for_stmt
    | pure_arithmetic
    | incdec_stmt
    | arithmetic_add_stmt
    | expression_stmt
    | block
    | NEWLINE
;

declaration
    : VAR ID INT literal_initial   NEWLINE  { insert_symbol( scope, $2, "int32", yylineno, "-"); 
                                                fprintf(file,"istore %d\n",lookup_symbol($2, scope));
                                            }
    | VAR ID STRING string_initial          { insert_symbol( scope, $2, "string", yylineno, "-"); 
                                                fprintf(file,"astore %d\n",lookup_symbol($2, scope));
                                            }
    | VAR ID FLOAT literal_initial NEWLINE  { insert_symbol( scope, $2, "float32", yylineno, "-"); 
                                                fprintf(file,"fstore %d\n",lookup_symbol($2, scope));
                                            }
    | VAR ID BOOL bool_initial NEWLINE      { insert_symbol( scope, $2, "bool", yylineno, "-"); }
    | VAR ID '[' INT_LIT ']' INT NEWLINE    {   printf("INT_LIT %d\n", $4);
                                                insert_symbol( scope, $2, "array", yylineno, "int32"); 
                                            }
    | VAR ID '[' INT_LIT ']' FLOAT NEWLINE  {   printf("INT_LIT %d\n", $4);
                                                insert_symbol( scope, $2, "array", yylineno, "float32"); 
                                            }
    | ID '[' INT_LIT    { 
                            printf("IDENT (name=%s, address=%d)\n", $1,lookup_symbol($1, scope));
                            printf("INT_LIT %d\n",$3);
                        } 
        ']' array_initial NEWLINE
    | ident assign NEWLINE
;

array_initial
    : assign
    |
;

bool_initial
    : '=' bool   
    |
;

literal_initial
    : '=' literal 
    |
;


string_initial
    : '=' '"' STRING_LIT '"' NEWLINE    {printf("STRING_LIT %s\n", $3);}
    | NEWLINE
;

incdec_stmt
    : ident INC         {   printf("INC\n");

                            if(id_type==typeI){
                                fprintf(file,"iload %d\n",Find_index);
                                fprintf(file,"ldc 1\n");
                                fprintf(file,"iadd\n");
                                fprintf(file,"istore %d\n",Find_index);
                            }
                            else if(id_type==typeF){
                                fprintf(file,"fload %d\n",Find_index);
                                fprintf(file,"ldc 1.000000\n");
                                fprintf(file,"fadd\n");
                                fprintf(file,"fstore %d\n",Find_index);
                            }
                            
                        }
    | ident DEC         {   printf("DEC\n");

                            if(id_type==typeI){
                                fprintf(file,"iload %d\n",Find_index);
                                fprintf(file,"ldc 1\n");
                                fprintf(file,"isub\n");
                                fprintf(file,"istore %d\n",Find_index);
                            }
                            else if(id_type==typeF){
                                fprintf(file,"fload %d\n",Find_index);
                                fprintf(file,"ldc 1.000000\n");
                                fprintf(file,"fsub\n");
                                fprintf(file,"fstore %d\n",Find_index);
                            }
                        }
;

print_stmt
    : PRINTLN { strcpy(type_flag,"int32"); } '(' expression ')' 
        {
            printf("PRINTLN %s\n",type_flag);

            fprintf(file,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file,"swap\n");
            if(strcmp(type_flag,"int32")==0){
                fprintf(file,"invokevirtual java/io/PrintStream/println(I)V\n");
            }
            else if(strcmp(type_flag,"float32")==0){
                fprintf(file,"invokevirtual java/io/PrintStream/println(F)V\n");
            }
        }

    | PRINT { strcpy(type_flag,"int32"); } '(' expression ')' 
        {
            printf("PRINT %s\n",type_flag);

            fprintf(file,"getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file,"swap\n");
            if(strcmp(type_flag,"int32")==0){
                fprintf(file,"invokevirtual java/io/PrintStream/println(I)V\n");
            }
            else if(strcmp(type_flag,"float32")==0){
                fprintf(file,"invokevirtual java/io/PrintStream/println(F)V\n");
            }
        }
;

pure_arithmetic
    : int_literal '+' int_literal       {printf("ADD\n");}
    | int_literal '-' int_literal       {printf("SUB\n");}
    | FLOAT_LIT '+' FLOAT_LIT   {
                                    printf("FLOAT_LIT %f\n",$1);
                                    printf("FLOAT_LIT %f\n",$3);
                                    printf("ADD\n");
                                }
    | FLOAT_LIT '-' FLOAT_LIT   {
                                    printf("FLOAT_LIT %f\n",$1);
                                    printf("FLOAT_LIT %f\n",$3);
                                    printf("SUB\n");
                                }
    | ID '+' INT_LIT            {
                                    printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                                    printf("INT_LIT %d\n", $3);
                                    printf("ADD\n");
                                }
    | invalid_arithmetic
;

invalid_arithmetic
    : INT_LIT '+' FLOAT_LIT     {
                                    printf("INT_LIT %d\n",$1);
                                    printf("FLOAT_LIT %f\n", $3);
                                    printf("error:%d: invalid operation: ADD (mismatched types int32 and float32)\n", yylineno+1);
                                    printf("ADD\n");
                                }
    | FLOAT_LIT '+' INT_LIT     {
                                    printf("FLOAT_LIT %f\n",$1);
                                    printf("INT_LIT %d\n", $3);
                                    printf("error:%d: invalid operation: ADD (mismatched types float32 and int32)\n", yylineno+1);
                                    printf("ADD\n");
                                }
    | INT_LIT '-' FLOAT_LIT     {
                                    printf("INT_LIT %d\n",$1);
                                    printf("FLOAT_LIT %f\n", $3);
                                    printf("error:%d: invalid operation: SUB (mismatched types int32 and float32)\n", yylineno+1);
                                    printf("SUB\n");
                                }
    | FLOAT_LIT '-' INT_LIT     {
                                    printf("FLOAT_LIT %f\n",$1);
                                    printf("INT_LIT %d\n", $3);
                                    printf("error:%d: invalid operation: SUB (mismatched types float32 and int32)\n", yylineno+1);
                                    printf("SUB\n");
                                }
    | INT_LIT '*' FLOAT_LIT     {
                                    printf("INT_LIT %d\n",$1);
                                    printf("FLOAT_LIT %f\n", $3);
                                    printf("error:%d: invalid operation: MUL (mismatched types int32 and float32)\n", yylineno+1);
                                    printf("MUL\n");
                                }
    | FLOAT_LIT '*' INT_LIT     {
                                    printf("FLOAT_LIT %f\n",$1);
                                    printf("INT_LIT %d\n", $3);
                                    printf("error:%d: invalid operation: MUL (mismatched types float32 and int32)\n", yylineno+1);
                                    printf("MUL\n");
                                }
    | ID '%' INT_LIT            {
                                    printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                                    printf("INT_LIT %d\n", $3);
                                    printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno+1);
                                    printf("REM\n");
                                } 
    | int_literal LAND bool     {
                                    printf("error:%d: invalid operation: (operator LAND not defined on int32)\n", yylineno+1);
                                    printf("LAND\n");
                                }
    | float_literal LAND bool        {
                                    printf("error:%d: invalid operation: (operator LAND not defined on float32)\n", yylineno+1);
                                    printf("LAND\n");
                                }
    | bool LOR expression       {
                                    yyerror("invalid operation: (operator LOR not defined on int32)");
                                    printf("LOR\n");
                                }
;

if_stmt
    : IF int_literal    {yyerror("int32");} block
    | IF float_literal  {yyerror("float32");} block
    | IF string_literal {yyerror("string");} block
    | IF id_term        {yyerror("int32");} block
    | IF expression block else_stmt
;

else_stmt
    : ELSE if_stmt
    | ELSE block
    |
;

for_stmt
    : FOR float_literal '{' {
                            printf("error:%d: non-bool (type float32) used as for condition\n", yylineno+1);
                            scope++;
                        } 
        stmts '}'  {scope--;}
    | FOR int_literal '{' {
                        printf("error:%d: non-bool (type int32) used as for condition\n", yylineno+1);
                        scope++;
                    } 
        stmts '}'  {scope--;}
    | FOR pure_arithmetic '{'   {
                                    printf("error:%d: non-bool (type int32) used as for condition\n", yylineno+1);
                                    scope++;
                                } 
        stmts '}'  {scope--;}
    | FOR for_expr block
;


for_expr
    : ident assign ';' ident comparsion_expression ';' arithmetic_add_stmt
    | ident assign ';' ident comparsion_expression ';' incdec_stmt
    | expression
;

assign
    : ADD_ASSIGN var    { printf("ADD_ASSIGN\n"); }
    | SUB_ASSIGN var    { printf("SUB_ASSIGN\n"); }
    | MUL_ASSIGN var    { printf("MUL_ASSIGN\n"); }
    | QUO_ASSIGN var    { printf("QUO_ASSIGN\n"); }
    | REM_ASSIGN var    { printf("REM_ASSIGN\n"); }
    | error_assign
;

error_assign
    : '=' var   { 
                    if(id_type != var_type) {
                        printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, table[id_type].type, table[var_type].type);
                    }
                    printf("ASSIGN\n"); 
                }
    | ADD_ASSIGN ID     {   
                            int tmp = -1;
                            for(int i=0; i<=scope; i++) {
                                if(lookup_symbol($2, i) != -1) 
                                    tmp = lookup_symbol($2, i);
                            }
                            if(tmp == -1)
                                printf("error:%d: undefined: %s\n", yylineno+1, $2);
                            printf("IDENT (name=%s, address=%d)\n", $2, tmp);
                            yyerror("cannot assign to int32");
                            printf("ADD_ASSIGN\n");
                        }
;

error_stmt
    : literal  assign
;

var
    : int_literal           {var_type = typeI; }
    | float_literal         {var_type = typeF; }
    | string_literal        {var_type = typeS; }
    | bool                  {var_type = typeB; }
    | expression
    | ID                    {
                                printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                                strcpy(type_flag,table[lookup_symbol($1,scope)].type);
                                var_type = lookup_symbol($1, scope);
                            }
    |
;

ident
    : ID    {   
                int tmp = -1;
                for(int i=0; i<=scope; i++) {
                    if(lookup_symbol($1, i) != -1) 
                        tmp = lookup_symbol($1, i);
                }
            
                if( tmp == -1 ){
                    printf("error:%d: undefined: %s\n", yylineno+1, $1);
                }
                else {
                    if( strcmp(table[tmp].type,"int32") == 0 ) {
                        id_type = typeI;
                    }
                    else if( strcmp(table[tmp].type,"float32") == 0 ) {
                        id_type = typeF;
                    }
                    else if( strcmp(table[tmp].type,"bool") == 0 ) {
                        id_type = typeB;
                    }
                    else if( strcmp(table[tmp].type,"string") == 0 ) {
                        id_type = typeS;
                    } 
                    printf("IDENT (name=%s, address=%d)\n", $1, tmp);    
                    strcpy(type_flag,table[tmp].type);                    
                }

                Find_index = tmp;
            }
;

block
    : '{' {scope++;} stmts '}'  { scope--; }
;

arithmetic_add_stmt
    : ID '+' ID       { 
                        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, scope));
                        if( strcmp(table[lookup_symbol($1, scope)].type,table[lookup_symbol($3, scope)].type) != 0 ) {
                            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno+1, table[lookup_symbol($1, scope)].type,table[lookup_symbol($3, scope)].type);
                        }
                        printf("ADD\n");

                        fprintf(file,"iload %d\n",lookup_symbol($1,scope));
                        fprintf(file,"iload %d\n",lookup_symbol($3,scope));
                        fprintf(file,"iadd\n");
                      }
    | ID '-' ID       { 
                        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, scope));
                        if( strcmp(table[lookup_symbol($1, scope)].type,table[lookup_symbol($3, scope)].type) != 0 ) {
                            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno+1, table[lookup_symbol($1, scope)].type,table[lookup_symbol($3, scope)].type);
                        }
                        printf("SUB\n"); 

                        fprintf(file,"iload %d\n",lookup_symbol($1,scope));
                        fprintf(file,"iload %d\n",lookup_symbol($3,scope));
                        fprintf(file,"isub\n");
                      }
    | arithmetic_mul_stmt
;

arithmetic_mul_stmt
    : ID '*' ID       {
                        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, scope));
                        if( strcmp(table[lookup_symbol($1, scope)].type,table[lookup_symbol($3, scope)].type) != 0 ) {
                            printf("error:%d: invalid operation: MUL (mismatched types %s and %s)\n", yylineno+1, table[lookup_symbol($1, scope)].type,table[lookup_symbol($3, scope)].type);
                        }
                        printf("MUL\n"); 

                        fprintf(file,"iload %d\n",lookup_symbol($1,scope));
                        fprintf(file,"iload %d\n",lookup_symbol($3,scope));
                        fprintf(file,"imul\n");
                      }
    | ID '/' ID       { 
                        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, scope));
                        if( strcmp(table[lookup_symbol($1, scope)].type,table[lookup_symbol($3, scope)].type) != 0 ) {
                            printf("error:%d: invalid operation: QUO (mismatched types %s and %s)\n", yylineno+1, table[lookup_symbol($1, scope)].type,table[lookup_symbol($3, scope)].type);
                        }
                        printf("QUO\n"); 

                        fprintf(file,"iload %d\n",lookup_symbol($1,scope));
                        fprintf(file,"iload %d\n",lookup_symbol($3,scope));
                        fprintf(file,"idiv\n");
                      }
    | ID '%' ID       { 
                        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, scope));
                        if( strcmp(table[lookup_symbol($3, scope)].type,"float32") == 0 ) {
                            printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno+1);
                        }
                        printf("REM\n"); 

                        fprintf(file,"iload %d\n",lookup_symbol($1,scope));
                        fprintf(file,"iload %d\n",lookup_symbol($3,scope));
                        fprintf(file,"irem\n");
                      }
;

expression_stmt
    : expression
;

expression
    : comparsion_expression expression     { strcpy(type_flag,"bool");}
    | lor_expression expression
    | add_expression
    | 
;

lor_expression
    : land_expression
    | LOR expression  { printf("LOR\n"); }
;

land_expression
    : LAND expression { printf("LAND\n"); }
;

comparsion_expression
    : expression '>' add_expression      { printf("GTR\n"); }
    | expression '<' add_expression      { printf("LSS\n"); }
    | expression GEQ add_expression      { printf("GEQ\n"); }
    | expression LEQ add_expression      { printf("LEQ\n"); }
    | expression EQL add_expression      { printf("EQL\n"); }
    | expression NEQ add_expression      { printf("NEQ\n"); }
    | expression add_expression
;

add_expression
    : add_expression '+' mul_expression  {
                                            printf("ADD\n"); 
                                            if(strcmp(type_flag,"int32")==0){
                                                fprintf(file,"iadd\n");
                                            }
                                            else if(strcmp(type_flag,"float32")==0){
                                                fprintf(file,"fadd\n");
                                            }
                                            
                                        }
    | add_expression '-' mul_expression  {
                                            printf("SUB\n"); 
                                            if(strcmp(type_flag,"int32")==0){
                                                fprintf(file,"isub\n");
                                            }
                                            else if(strcmp(type_flag,"float32")==0){
                                                fprintf(file,"fsub\n");
                                            }
                                        }
    | mul_expression
;

mul_expression
    : mul_expression '*' operand    {
                                        printf("MUL\n");
                                        if(strcmp(type_flag,"int32")==0){
                                                fprintf(file,"imul\n");
                                        }
                                        else if(strcmp(type_flag,"float32")==0){
                                            fprintf(file,"fmul\n");
                                        } 
                                    }
    | mul_expression '/' operand    {
                                        printf("QUO\n"); 
                                        if(strcmp(type_flag,"int32")==0){
                                            fprintf(file,"idiv\n");
                                        }
                                        else if(strcmp(type_flag,"float32")==0){
                                            fprintf(file,"fdiv\n");
                                        }
                                    }
    | mul_expression '%' operand    {   
                                        printf("REM\n"); 
                                        if(strcmp(type_flag,"int32")==0){
                                            fprintf(file,"irem\n");
                                        }
                                        else if(strcmp(type_flag,"float32")==0){
                                            fprintf(file,"frem\n");
                                        }
                                    }
    | operand
;

operand
    : '(' expression ')'
    | term
;

term
    : literal
    | sign_literal
    | literal_convert
    | string_literal
    | bool
    | id_term
;

bool
    : '!' bool      { printf("NOT\n"); strcpy(type_flag,"bool"); }  expression
    | TRUE          { printf("TRUE\n"); strcpy(type_flag,"bool"); }
    | FALSE         { printf("FALSE\n"); strcpy(type_flag,"bool");}
;


literal
    : int_literal      {strcpy(type_flag,"int32");}
    | float_literal    {strcpy(type_flag,"float32");}
;

int_literal
    : INT_LIT   {   printf("INT_LIT %d\n", $1); 
                    fprintf(file,"ldc %d\n",$1);
                }
;

float_literal
    : FLOAT_LIT     {   printf("FLOAT_LIT %f\n", $1); 
                        fprintf(file,"ldc %f\n",$1); 
                    }
;

sign_literal
    : SIGN_INT_LIT          {   
                                printf("INT_LIT %d\n", abs($1)); 
                                if( $1 >=0 )
                                    printf("POS\n");
                                else
                                    printf("NEG\n");
                            }
    | SIGN_FLOAT_LIT        {   
                                printf("FLOAT_LIT %f\n", fabs($1)); 
                                if( $1 >=0 )
                                    printf("POS\n");
                                else
                                    printf("NEG\n");
                            }
;

string_literal
    : '"' STRING_LIT '"'    { printf("STRING_LIT %s\n", $2); 
                                strcpy(type_flag,"string"); 
                                fprintf(file,"ldc %s\n",$2);
                            }
;

literal_convert
    : INT '(' ident ')'         { printf("F to I\n"); id_type = typeI; }
    | INT '(' FLOAT_LIT ')'     { printf("FLOAT_LIT %f\nF to I\n",$3);  }
    | FLOAT '(' ident ')'       { printf("I to F\n"); }
    | FLOAT '(' INT_LIT ')'     { printf("INT_LIT %d\nI to F\n",$3); id_type = typeI; }
;

id_term
    : ID    { 
                if(strcmp(table[lookup_symbol($1, scope)].type,"array")==0){
                    printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope)); 
                }
            } 
    '[' expression ']' {strcpy(type_flag,table[lookup_symbol($1, scope)].element);}

    | ID    {   int tmp = -1;
                for(int i=0; i<=scope; i++) {
                    if( lookup_symbol($1, i) != -1) 
                        tmp = lookup_symbol($1, i);
                }
                if( tmp == -1 ) {
                    printf("error:%d: undefined: %s\n", yylineno+1, $1);
                }
                else {
                    printf("IDENT (name=%s, address=%d)\n", $1, tmp); 
                    strcpy(type_flag,table[tmp].type);
                }
                
                if(strcmp(type_flag,"int32")==0)
                    fprintf(file,"iload %d\n",lookup_symbol($1,scope));
                else if(strcmp(type_flag,"float32")==0)
                    fprintf(file,"fload %d\n",lookup_symbol($1,scope));
            }
;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    char temp_name[20]=FILE_NAME;
    strcat(temp_name,".j");
    file = fopen(temp_name,"w");
    fprintf(file,".source hw3.j\n");
    fprintf(file,".class public Main\n");
    fprintf(file,".super java/lang/Object\n");
    fprintf(file,".method public static main([Ljava/lang/String;)V\n");
    fprintf(file,".limit stack %d\n",STACK_SIZE);
    fprintf(file,".limit locals %d\n",STACK_SIZE);

    create_symbol();
    yylineno = 0;
    yyparse();

    fprintf(file,"\treturn\n");
    fprintf(file,".end method\n");

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    if (HAS_ERROR) {
        remove("hw3.j");
    }
    return 0;
}

static void create_symbol() {
    total_entry=0;
    for(int i=0; i<10; i++) {
        block_entry[i] = 0;
    }
}

static void insert_symbol(int scope, char *id, char *type, int lineno, char *element) {
    for(int i=0; i<total_entry; i++) {
        if(strcmp(table[i].name,id) == 0 && table[i].scope == scope) {
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", lineno, id, table[i].lineno);
            return;
        }
    }
    table[total_entry].index = block_entry[scope];
    table[total_entry].name = id;
    table[total_entry].type = type;
    table[total_entry].lineno = lineno;
    table[total_entry].element = element;
    table[total_entry].scope = scope;
    printf("> Insert {%s} into symbol table (scope level: %d)\n", id, scope);
    block_entry[scope]++;
    total_entry++;
}

// return the address
static int lookup_symbol(char *id, int scope) {
    for(int i=0; i<total_entry; i++) {
        if( strcmp(id,table[i].name) == 0 ) {
            if(scope == table[i].scope)
                return i;
        }
    }
    return -1;
}

static void dump_symbol(int level) {
    printf("> Dump symbol table (scope level: %d)\n", level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(int i=0; i<total_entry; i++) {
        if(table[i].scope == level) {
            printf("%-10d%-10s%-10s%-10d%-10d%s\n",
            table[i].index, table[i].name, table[i].type, i, table[i].lineno, table[i].element);

            // delete data
            table[i].scope = -1;
        }
    }
    block_entry[level] = 0;
}


void get_return_type(char type[10]){
    if(strcmp(type,"int32")==0)
        type_flag_gen = 0;
    else if(strcmp(type,"float32")==0)
        type_flag_gen = 1;
    else if(strcmp(type,"bool")==0)
        type_flag_gen = 2;
    else if(strcmp(type,"string")==0)
        type_flag_gen = 3;
}

void find_index_and_scope_andtype(){
    // Find_scope , Find_index, Find_type
}

void store_code_gen(){
    find_index_and_scope_andtype();
    get_return_type(Find_type);

    if(Find_scope>0){
        if(type_flag_gen==0){
            // f2i
            fprintf(file,"istore %d\n",Find_index);
        }
        else if(type_flag_gen==1){
            // i2f
            fprintf(file,"fstore %d\n",Find_index);
        }
        else if(type_flag_gen==2){
            fprintf(file,"istore %d\n",Find_index);
        }
        else if(type_flag_gen==3){
            fprintf(file,"astore %d\n",Find_index);
        }
    }

}

void load_code_gen(){
    find_index_and_scope_andtype();
    get_return_type(Find_type);

    if(Find_scope>0){
        if(type_flag_gen==0)
            fprintf(file,"iload %d\n",Find_index);
        else if(type_flag_gen==1){
            fprintf(file,"fload %d\n",Find_index);
        }
        else if(type_flag_gen==2){
            fprintf(file,"iload %d\n",Find_index);
        }
        else if(type_flag_gen==3){
            fprintf(file,"aload %d\n",Find_index);
        }
    }
    // else if (find_scope==0)
    /*
    if(type_flag_gen==0)

    else if(type_flag_gen==1)

    else if(type_flag_gen==2)

    else if(type_flag_gen==3)
    */

}

void arith_code_gen(char operator[10]){


    type_casting();
    if(strcmp(operator,"add")==0){
        if(type_flag==0)
            fprintf(file,"iadd\n");
        else if(type_flag==1)
            fprintf(file,"fadd\n");
    }
    else if(strcmp(operator,"sub")==0){
        if(type_flag==0)
            fprintf(file,"isub\n");
        else if(type_flag==1)
            fprintf(file,"fsub\n");
    }
    else if(strcmp(operator,"mul")==0){
        if(type_flag==0)
            fprintf(file,"imul\n");
        else if(type_flag==1)
            fprintf(file,"fmul\n");
    }
    else if(strcmp(operator,"div")==0){
        if(type_flag==0)
            fprintf(file,"idiv\n");
        else if(type_flag)
            fprintf(file,"fdiv\n");
    }
    else if(strcmp(operator,"mod")==0){
        if(type_flag==0)
            fprintf(file,"irem\n");
    }
    /*
    if(type_flag==0)

    else if(type_flag==1)
    */
}

void type_casting(){

}