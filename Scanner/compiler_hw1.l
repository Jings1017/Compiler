/* Definition section */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define YY_NO_UNPUT
    #define YY_NO_INPUT

    int line_num = 0;
    int comment_num = 0;
    int line_index = -1;

%}

/* Define regular expression label */
letter          [a-zA-Z_]
digit           [0-9]
id              {letter}+({letter}|{digit})*
inumber         {digit}+
fnumber         ({digit}*\.{digit}+)
cppcomment      ("//")(.)*
commentln    ("/*")[^("*/")^(\n)]*(\n)
ccomment         ("/*")[^("*/")^(\n)]*("*/")
whitespace      [ \t]+

/* Rules section */
%START  str end comment
%%

<str>\"/{id}      { printf("%-8s \t %s\n", yytext, "QUOTA"); BEGIN end; }
<end>{id}/\"      { printf("%-8s \t %s\n", yytext, "STRING"); }

<comment>([^("*/")^("\n")]|[+=-~!@#$%^&*()<>]*)*("*/")  { 
                                        for(int i=0;i<strlen(yytext);i++)
                                            printf("%c",yytext[i]);
                                        printf("%-6s \t %s\n", yytext+yyleng, "C Comment"); 
                                        comment_num++;
                                        BEGIN 0;
                                    }
<comment>([^("*/")^("\n")]|[+=-~!@#$%^&*()<>]*)*("\n") { 
                                                printf("%s%-8s\t %s\n", yytext, "", "C Comment");
                                                comment_num++;
                                                line_num++; 
                                                BEGIN comment;
                                            }

"+"          { printf("%-8s \t %s\n", yytext, "ADD"); }
"-"          { printf("%-8s \t %s\n", yytext, "SUB"); }
"*"          { printf("%-8s \t %s\n", yytext, "MUL"); }
"/"          { printf("%-8s \t %s\n", yytext, "QUO"); }
"%"          { printf("%-8s \t %s\n", yytext, "REM"); }

"++"         { printf("%-8s \t %s\n", yytext, "INC"); }
"--"         { printf("%-8s \t %s\n", yytext, "DEC"); }

">"          { printf("%-8s \t %s\n", yytext, "GTR"); }
"<"          { printf("%-8s \t %s\n", yytext, "LSS"); }
">="         { printf("%-8s \t %s\n", yytext, "GEQ"); }
"<="         { printf("%-8s \t %s\n", yytext, "LEQ"); }
"=="         { printf("%-8s \t %s\n", yytext, "EQL"); }
"!="         { printf("%-8s \t %s\n", yytext, "NEQ"); }
"="          { printf("%-8s \t %s\n", yytext, "ASSIGN"); }
"+="         { printf("%-8s \t %s\n", yytext, "ADD_ASSIGN"); }
"-="         { printf("%-8s \t %s\n", yytext, "SUB_ASSIGN"); }
"*="         { printf("%-8s \t %s\n", yytext, "MUL_ASSIGN"); }
"/="         { printf("%-8s \t %s\n", yytext, "QUO_ASSIGN"); }
"%="         { printf("%-8s \t %s\n", yytext, "REM_ASSIGN"); }

"&&"         { printf("%-8s \t %s\n", yytext, "LAND"); }
"||"         { printf("%-8s \t %s\n", yytext, "LOR"); }
"!"          { printf("%-8s \t %s\n", yytext, "NOT"); }

"("         { printf("%-8s \t %s\n", yytext, "LPAREN"); }
")"         { printf("%-8s \t %s\n", yytext, "RPAREN"); }
"["         { printf("%-8s \t %s\n", yytext, "LBRACK"); }
"]"         { printf("%-8s \t %s\n", yytext, "RBRACK"); }
"{"         { printf("%-8s \t %s\n", yytext, "LBRACE"); }
"}"         { printf("%-8s \t %s\n", yytext, "RBRACE"); }
";"         { printf("%-8s \t %s\n", yytext, "SEMICOLON"); }
","         { printf("%-8s \t %s\n", yytext, "COMMA"); }

"\""        { printf("%-8s \t %s\n", yytext, "QUOTA"); }
"\n"         { printf("%-8s \t %s\n", "", "NEWLINE"); line_num++; }

"print"           { printf("%-8s \t %s\n", yytext, "PRINT");   BEGIN str; }
"println"         { printf("%-8s \t %s\n", yytext, "PRINTLN"); BEGIN str; }
"string"          { printf("%-8s \t %s\n", yytext, "STRING");  BEGIN str; }

"if"              { printf("%-8s \t %s\n", yytext, "IF"); }
"else"            { printf("%-8s \t %s\n", yytext, "ELSE"); }
"for"             { printf("%-8s \t %s\n", yytext, "FOR"); }
"int32"           { printf("%-8s \t %s\n", yytext, "INT"); }
"float32"         { printf("%-8s \t %s\n", yytext, "FLOAT"); }
"bool"            { printf("%-8s \t %s\n", yytext, "BOOL"); }
"true"            { printf("%-8s \t %s\n", yytext, "TRUE"); }
"false"           { printf("%-8s \t %s\n", yytext, "FALSE"); }
"var"             { printf("%-8s \t %s\n", yytext, "VAR"); }

{id}             { printf("%-8s \t %s\n", yytext, "IDENT"); }
{inumber}        { printf("%-8s \t %s\n", yytext, "INT_LIT"); }
{fnumber}        { printf("%-8s \t %s\n", yytext, "FLOAT_LIT"); }

{cppcomment}    {   printf("%-8s \t %s\n", yytext, "C++ Comment"); comment_num++;
                    int m=0,n=0;
                    for(int i=0;i<yyleng-1;i++)
                    {
                        if(yytext[i]=='/'&&yytext[i+1]=='*') m++;
                        else if (yytext[i]=='*'&&yytext[i+1]=='/') n++;
                    }
                    if(m==n) comment_num-=m;
                }
{ccomment}      {   printf("%-11s \t %s\n", yytext, "C Comment") ; }
{commentln}     {   printf("%s%-8s\t %s\n", yytext,"", "C Comment"); 
                    line_num++;
                    comment_num++;
                    BEGIN comment; 
                }

{whitespace}      {;}

<<EOF>>     { line_num++; yyterminate(); }

%%

/*  C Code section */
int yywrap(void)
{
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    yylex();
    printf("\nFinish scanning,\n");
    printf("total line: %d\n", line_num);
    printf("comment line: %d\n", comment_num);
    fclose(yyin);
    return 0;
}
