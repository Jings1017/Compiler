/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw3.y" /* yacc.c:339  */

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

#line 145 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    INT = 259,
    FLOAT = 260,
    BOOL = 261,
    STRING = 262,
    INC = 263,
    DEC = 264,
    GEQ = 265,
    LEQ = 266,
    EQL = 267,
    NEQ = 268,
    ADD_ASSIGN = 269,
    SUB_ASSIGN = 270,
    MUL_ASSIGN = 271,
    QUO_ASSIGN = 272,
    REM_ASSIGN = 273,
    LAND = 274,
    LOR = 275,
    NEWLINE = 276,
    PRINT = 277,
    PRINTLN = 278,
    IF = 279,
    ELSE = 280,
    FOR = 281,
    TRUE = 282,
    FALSE = 283,
    INT_LIT = 284,
    SIGN_INT_LIT = 285,
    FLOAT_LIT = 286,
    SIGN_FLOAT_LIT = 287,
    STRING_LIT = 288,
    ID = 289
  };
#endif
/* Tokens.  */
#define VAR 258
#define INT 259
#define FLOAT 260
#define BOOL 261
#define STRING 262
#define INC 263
#define DEC 264
#define GEQ 265
#define LEQ 266
#define EQL 267
#define NEQ 268
#define ADD_ASSIGN 269
#define SUB_ASSIGN 270
#define MUL_ASSIGN 271
#define QUO_ASSIGN 272
#define REM_ASSIGN 273
#define LAND 274
#define LOR 275
#define NEWLINE 276
#define PRINT 277
#define PRINTLN 278
#define IF 279
#define ELSE 280
#define FOR 281
#define TRUE 282
#define FALSE 283
#define INT_LIT 284
#define SIGN_INT_LIT 285
#define FLOAT_LIT 286
#define SIGN_FLOAT_LIT 287
#define STRING_LIT 288
#define ID 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 86 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    int si_val;
    float f_val;
    float sf_val;
    char *s_val;
    char *id_val;
    /* ... */

#line 263 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 280 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  96
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   801

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  150
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  273

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    38,     2,     2,    44,     2,     2,
      39,    40,    43,    41,     2,    42,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
      50,    37,    49,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   121,   121,   122,   126,   127,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   145,   148,   151,
     154,   155,   158,   161,   161,   166,   170,   171,   175,   176,
     180,   181,   186,   187,   191,   207,   225,   225,   239,   239,
     255,   256,   257,   262,   267,   272,   276,   282,   288,   294,
     300,   306,   312,   318,   322,   326,   333,   333,   334,   334,
     335,   335,   336,   336,   337,   341,   342,   343,   347,   347,
     352,   352,   357,   357,   362,   367,   368,   369,   373,   374,
     375,   376,   377,   378,   382,   388,   403,   407,   408,   409,
     410,   411,   412,   417,   421,   453,   453,   457,   469,   481,
     485,   497,   509,   524,   528,   529,   530,   531,   535,   536,
     540,   544,   545,   546,   547,   548,   549,   550,   554,   564,
     573,   577,   586,   595,   604,   608,   609,   613,   614,   615,
     616,   617,   618,   622,   622,   623,   624,   629,   630,   634,
     640,   646,   653,   663,   670,   671,   672,   673,   677,   677,
     684
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "INT", "FLOAT", "BOOL", "STRING",
  "INC", "DEC", "GEQ", "LEQ", "EQL", "NEQ", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN", "LAND", "LOR", "NEWLINE",
  "PRINT", "PRINTLN", "IF", "ELSE", "FOR", "TRUE", "FALSE", "INT_LIT",
  "SIGN_INT_LIT", "FLOAT_LIT", "SIGN_FLOAT_LIT", "STRING_LIT", "ID", "'['",
  "']'", "'='", "'\"'", "'('", "')'", "'+'", "'-'", "'*'", "'%'", "'{'",
  "'}'", "';'", "'/'", "'>'", "'<'", "'!'", "$accept", "Program", "stmts",
  "stmt", "declaration", "$@1", "array_initial", "bool_initial",
  "literal_initial", "string_initial", "incdec_stmt", "print_stmt", "$@2",
  "$@3", "pure_arithmetic", "invalid_arithmetic", "if_stmt", "$@4", "$@5",
  "$@6", "$@7", "else_stmt", "for_stmt", "$@8", "$@9", "$@10", "for_expr",
  "assign", "error_assign", "error_stmt", "var", "ident", "block", "$@11",
  "arithmetic_add_stmt", "arithmetic_mul_stmt", "expression_stmt",
  "expression", "lor_expression", "land_expression",
  "comparsion_expression", "add_expression", "mul_expression", "operand",
  "term", "bool", "$@12", "literal", "int_literal", "float_literal",
  "sign_literal", "string_literal", "literal_convert", "id_term", "$@13", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    91,    93,    61,    34,    40,
      41,    43,    45,    42,    37,   123,   125,    59,    47,    62,
      60,    33
};
# endif

#define YYPACT_NINF -74

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define YYTABLE_NINF -151

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     335,   -29,   -30,    39,   642,   642,   -74,   -74,   -74,   642,
     678,   -74,   -74,    23,   -74,    64,   -74,    33,    51,   642,
     -74,    11,    91,   372,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   233,   -74,   -74,   -74,   -74,   606,   642,   -74,
     642,    12,   -20,   -74,   -74,    77,    43,    52,    99,   -74,
     -74,   -74,   -74,     8,    61,   -12,   -74,   -74,   107,   606,
     -74,   -74,   -74,   -74,   606,    95,   115,   440,   101,   120,
     141,   143,   650,   145,   148,    43,   606,   -15,   -11,   164,
     165,   168,    88,   110,   176,   179,    38,   175,   180,    56,
     181,   191,   172,   471,   409,   -74,   -74,   -74,   285,   -74,
     -74,   714,   750,   750,   750,   750,   750,   208,   -74,   153,
     153,   153,   153,   153,   153,    12,   606,   606,   153,   153,
     153,   153,   153,   642,   -74,    11,   201,   201,    11,   196,
     196,   198,    42,   217,   197,   -74,   212,   216,   219,   642,
     642,   242,   148,   148,   148,   148,   231,   244,   -74,   -74,
     224,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   642,
     -74,   -74,   234,   642,   -74,   159,   -74,   606,   235,   250,
     284,   300,   159,   -74,   -74,   -74,   -74,   -74,   -74,    12,
      12,    12,    12,    12,    12,   -20,   -20,   -74,   -74,   -74,
     606,   -74,   -74,   -74,   -74,   114,   260,   261,    11,   263,
     -74,   248,   -74,   251,   -74,   -74,   -74,   -74,   502,   533,
      -5,   -74,   -74,   -74,   -74,   -74,   409,   262,   409,   409,
     259,   564,   -74,   606,   -74,   -74,   -74,   -74,   -74,   264,
     105,   -74,   -74,   -74,   -74,   254,   642,   257,   272,    43,
     -74,   282,   289,   301,   -74,   606,   193,   -74,   -74,   312,
     -74,   313,   -74,   -74,   287,   -74,   -74,   377,   -74,   113,
     -74,   303,   311
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     107,     0,     0,     0,   107,   107,    16,    38,    36,   107,
     107,   135,   136,   139,   141,   140,   142,   150,     0,   107,
      95,     0,     0,   107,     6,    12,     7,    11,    45,     9,
      10,     8,     0,    15,    13,    99,    14,   103,   107,   108,
     107,   106,   120,   124,   126,   131,   127,   137,   138,   128,
     130,   129,   132,     0,     0,     0,   139,   140,   150,   110,
     131,   127,   137,   138,   109,     0,     0,     0,   137,   138,
     130,   132,   150,     0,     0,     0,    77,   137,   138,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,   133,     1,     2,   107,    34,
      35,    93,    93,    93,    93,    93,    93,     0,    83,     0,
       0,     0,     0,     0,     0,   117,   105,   104,     0,     0,
       0,     0,     0,   107,    86,     0,     0,     0,     0,    31,
      31,    29,     0,     0,     0,    94,     0,     0,     0,   107,
     107,    67,     0,     0,     0,     0,     0,     0,    72,    74,
       0,    70,    68,    46,    48,    50,    47,    42,    49,    43,
      51,    23,    44,    97,    98,   100,    52,   102,   101,   107,
     143,   125,     0,   107,     4,    85,    78,    91,    90,    87,
      88,    89,    92,    79,    80,    81,    82,    84,    25,   113,
     114,   115,   116,   111,   112,   118,   119,   121,   123,   122,
      55,    53,    40,    41,    54,     0,     0,     0,     0,     0,
      33,     0,    18,     0,   145,   144,   147,   146,     0,     0,
       0,    64,    57,    59,    61,    63,   107,     0,   107,   107,
       0,     0,    96,   134,    30,    17,    19,    28,    20,     0,
       0,    39,    37,    65,    66,     0,   107,     0,     0,    27,
     149,     0,     0,     0,    73,     0,   107,    71,    69,     0,
      26,     0,    21,    22,     0,    24,    32,    94,    76,     0,
      75,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -73,   346,   -74,   -74,   -74,   -74,   220,   -74,
      83,   -74,   -74,   -74,   339,   -74,   131,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -43,   -74,   -74,
      57,   -10,   -56,   -74,    89,   -74,   -74,    -3,   -74,   -74,
     122,   152,    50,     4,   -74,    10,   -74,    29,    46,    73,
     -74,    27,   -74,   351,   -74
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    97,    98,    24,   230,   259,   209,   206,   212,
      25,    26,    66,    65,    27,    28,    29,   142,   143,   144,
     145,   221,    30,   229,   228,   226,    74,   107,   108,    31,
     176,    32,    33,    94,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    60,   173,    61,    62,    63,
      49,    50,    51,    52,    91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      75,    59,    64,   124,   125,    53,    67,    76,   128,    54,
      45,   141,   129,   130,   131,   132,    93,   137,   149,     9,
      45,   172,   135,   120,   121,   174,   126,   127,   122,    46,
     151,    95,   150,    45,   152,   116,    70,   117,    11,    12,
      20,   -94,   -94,   133,   136,   138,    47,   -94,   -94,   -94,
     -94,   -94,    46,   118,   119,    68,    77,   101,   102,   103,
     104,   105,    21,   210,    79,    80,    81,   162,    85,    47,
     -94,   125,   163,    48,    86,    87,    88,    89,    55,   211,
     106,    90,    69,    78,    92,   166,   222,   223,   224,   225,
     167,    96,   134,   126,   127,   135,    48,   123,   177,   177,
     177,   177,   177,   177,    45,    82,    83,    84,    45,   252,
     253,   178,   178,   178,   178,   178,   178,   156,   128,   157,
     200,    99,   100,    46,   197,   198,   199,    46,   181,   181,
     181,   181,   181,   181,   139,   201,   218,   219,   204,   158,
      47,   159,  -148,    56,    47,    57,   -56,   179,   179,   179,
     179,   179,   179,   245,   140,   247,   248,     2,     3,   183,
     184,   185,   186,   187,   244,   -58,   231,    48,   195,   196,
     233,    48,   202,   203,   180,   180,   180,   180,   180,   180,
      11,    12,    56,    14,    57,    16,   -60,    58,   -62,   115,
     148,    18,    19,    20,  -148,   153,   154,     2,     3,   155,
    -150,  -150,  -150,  -150,    21,   160,   260,  -150,   161,   164,
     170,   115,     4,     5,   165,   168,   115,   246,   237,   115,
      11,    12,    56,    14,    57,    16,   169,    58,   115,   188,
      56,    18,    19,   205,   234,   208,    45,   214,    45,    45,
     264,    99,   100,   255,    21,   115,   213,   101,   102,   103,
     104,   105,   215,   117,   269,    46,   216,    46,    46,   217,
     162,   189,   190,   191,   192,   193,   194,   220,   115,   115,
     106,   227,    47,   166,    47,    47,  -131,  -131,  -131,  -131,
     232,   235,   236,  -131,   238,    -5,   239,   240,     1,     2,
       3,  -137,  -137,  -137,  -137,   249,   135,   251,  -137,    48,
     254,    48,    48,   257,     4,     5,     6,     7,     8,     9,
     262,    10,    11,    12,    13,    14,    15,    16,   258,    17,
     261,   267,   263,    18,    19,  -138,  -138,  -138,  -138,   115,
      20,    -5,  -138,   265,   266,    -3,    21,   163,     1,     2,
       3,  -130,  -130,  -130,  -130,   167,    23,   268,  -130,    73,
     207,   243,   115,   270,     4,     5,     6,     7,     8,     9,
      71,    10,    11,    12,    13,    14,    15,    16,   256,    17,
     115,   115,    -5,    18,    19,     1,     2,     3,     0,     0,
      20,     0,     0,   115,     0,   115,    21,     0,     0,     0,
       0,     4,     5,     6,     7,     8,     9,     0,    10,    11,
      12,    13,    14,    15,    16,     0,    17,   115,     0,     0,
      18,    19,     1,     2,     3,     0,     0,    20,   271,    87,
      88,   272,     0,    21,     0,    90,     0,     0,     4,     5,
       6,     7,     8,     9,     0,    10,    11,    12,    13,    14,
      15,    16,     0,    17,     2,     3,     0,    18,    19,     0,
     109,   110,   111,   112,    20,    -5,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,    11,    12,    56,
      14,    57,    16,     0,    58,     2,     3,     0,    18,    19,
       0,   109,   110,   111,   112,    20,     0,     0,     0,   113,
     114,    21,     0,     0,     0,     0,     0,     0,    11,    12,
      56,    14,    57,    16,     0,    58,     2,     3,     0,    18,
      19,   171,   109,   110,   111,   112,     0,     0,     0,     0,
     113,   114,    21,     0,     0,     0,     0,     0,     0,    11,
      12,    56,    14,    57,    16,     0,    58,     2,     3,     0,
      18,    19,   241,   109,   110,   111,   112,     0,     0,     0,
       0,   113,   114,    21,     0,     0,     0,     0,     0,     0,
      11,    12,    56,    14,    57,    16,     0,    58,     2,     3,
       0,    18,    19,   242,   109,   110,   111,   112,     0,     0,
       0,     0,   113,   114,    21,     0,     0,     0,     0,     0,
       0,    11,    12,    56,    14,    57,    16,     0,    58,     0,
     250,     0,    18,    19,     0,     0,     0,     0,     0,     0,
       2,     3,     0,   113,   114,    21,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,    56,    14,    57,    16,     0,
      58,     0,     0,     0,    18,    19,     2,     3,     0,     0,
       0,     0,     0,     0,     0,   113,   114,    21,     0,     0,
       0,     4,     5,     0,   -94,   -94,   -94,   -94,   -94,    11,
      12,    56,    14,    57,    16,     0,    58,     0,     0,     0,
      18,    19,     2,     3,     0,  -148,     0,   -94,     0,     0,
       0,   146,     0,    21,   147,     0,     0,     4,     5,     0,
       0,     0,     0,     0,     0,    11,    12,    13,    14,    15,
      16,     0,    72,     0,     0,     0,    18,    19,     2,     3,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     4,     5,     0,     0,     0,     0,     0,
       0,    11,    12,    56,    14,    57,    16,     0,   175,     0,
       0,     0,    18,    19,     2,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     4,
       5,     0,     0,     0,     0,     0,     0,    11,    12,    56,
      14,    57,    16,     0,   182,     0,     0,     0,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21
};

static const yytype_int16 yycheck[] =
{
      10,     4,     5,    46,    19,    34,     9,    10,    19,    39,
       0,    67,     4,     5,     6,     7,    19,    29,    74,    24,
      10,    94,    34,    43,    44,    98,    41,    42,    48,     0,
      45,    21,    75,    23,    45,    38,     9,    40,    27,    28,
      45,     8,     9,    35,    54,    55,     0,    14,    15,    16,
      17,    18,    23,    41,    42,     9,    10,    14,    15,    16,
      17,    18,    51,    21,    41,    42,    43,    29,    35,    23,
      37,    19,    34,     0,    41,    42,    43,    44,    39,    37,
      37,    48,     9,    10,    33,    29,   142,   143,   144,   145,
      34,     0,    31,    41,    42,    34,    23,    20,   101,   102,
     103,   104,   105,   106,    94,    41,    42,    43,    98,     4,
       5,   101,   102,   103,   104,   105,   106,    29,    19,    31,
     123,     8,     9,    94,   120,   121,   122,    98,   101,   102,
     103,   104,   105,   106,    39,   125,   139,   140,   128,    29,
      94,    31,    35,    29,    98,    31,    45,   101,   102,   103,
     104,   105,   106,   226,    39,   228,   229,     4,     5,   102,
     103,   104,   105,   106,   220,    45,   169,    94,   118,   119,
     173,    98,   126,   127,   101,   102,   103,   104,   105,   106,
      27,    28,    29,    30,    31,    32,    45,    34,    45,    37,
      45,    38,    39,    45,    35,    31,    31,     4,     5,    31,
      41,    42,    43,    44,    51,    29,   249,    48,    29,    34,
      38,    59,    19,    20,    34,    34,    64,   227,   208,    67,
      27,    28,    29,    30,    31,    32,    35,    34,    76,    21,
      29,    38,    39,    37,   205,    37,   226,    40,   228,   229,
      47,     8,     9,   246,    51,    93,    29,    14,    15,    16,
      17,    18,    40,   256,   264,   226,    40,   228,   229,    40,
      29,   109,   110,   111,   112,   113,   114,    25,   116,   117,
      37,    47,   226,    29,   228,   229,    41,    42,    43,    44,
      46,    21,    21,    48,    21,     0,    38,    36,     3,     4,
       5,    41,    42,    43,    44,    36,    34,    33,    48,   226,
      46,   228,   229,    46,    19,    20,    21,    22,    23,    24,
      21,    26,    27,    28,    29,    30,    31,    32,    46,    34,
      38,    34,    21,    38,    39,    41,    42,    43,    44,   177,
      45,    46,    48,    21,    21,     0,    51,    34,     3,     4,
       5,    41,    42,    43,    44,    34,     0,   264,    48,    10,
     130,   220,   200,   264,    19,    20,    21,    22,    23,    24,
       9,    26,    27,    28,    29,    30,    31,    32,   246,    34,
     218,   219,     0,    38,    39,     3,     4,     5,    -1,    -1,
      45,    -1,    -1,   231,    -1,   233,    51,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    -1,    34,   255,    -1,    -1,
      38,    39,     3,     4,     5,    -1,    -1,    45,    41,    42,
      43,    44,    -1,    51,    -1,    48,    -1,    -1,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,     4,     5,    -1,    38,    39,    -1,
      10,    11,    12,    13,    45,    46,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    34,     4,     5,    -1,    38,    39,
      -1,    10,    11,    12,    13,    45,    -1,    -1,    -1,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    34,     4,     5,    -1,    38,
      39,    40,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    34,     4,     5,    -1,
      38,    39,    40,    10,    11,    12,    13,    -1,    -1,    -1,
      -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    34,     4,     5,
      -1,    38,    39,    40,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    49,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    34,    -1,
      36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,    -1,    49,    50,    51,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    -1,
      34,    -1,    -1,    -1,    38,    39,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    -1,    -1,
      -1,    19,    20,    -1,    14,    15,    16,    17,    18,    27,
      28,    29,    30,    31,    32,    -1,    34,    -1,    -1,    -1,
      38,    39,     4,     5,    -1,    35,    -1,    37,    -1,    -1,
      -1,    41,    -1,    51,    44,    -1,    -1,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    34,    -1,    -1,    -1,    38,    39,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    34,    -1,
      -1,    -1,    38,    39,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    34,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    19,    20,    21,    22,    23,    24,
      26,    27,    28,    29,    30,    31,    32,    34,    38,    39,
      45,    51,    53,    55,    56,    62,    63,    66,    67,    68,
      74,    81,    83,    84,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    99,   100,   101,   102,
     103,   104,   105,    34,    39,    39,    29,    31,    34,    89,
      97,    99,   100,   101,    89,    65,    64,    89,   100,   101,
     103,   105,    34,    66,    78,    83,    89,   100,   101,    41,
      42,    43,    41,    42,    43,    35,    41,    42,    43,    44,
      48,   106,    33,    89,    85,    97,     0,    54,    55,     8,
       9,    14,    15,    16,    17,    18,    37,    79,    80,    10,
      11,    12,    13,    49,    50,    93,    89,    89,    41,    42,
      43,    44,    48,    20,    79,    19,    41,    42,    19,     4,
       5,     6,     7,    35,    31,    34,    83,    29,    83,    39,
      39,    84,    69,    70,    71,    72,    41,    44,    45,    84,
      79,    45,    45,    31,    31,    31,    29,    31,    29,    31,
      29,    29,    29,    34,    34,    34,    29,    34,    34,    35,
      38,    40,    54,    98,    54,    34,    82,    89,    97,   100,
     101,   103,    34,    82,    82,    82,    82,    82,    21,    93,
      93,    93,    93,    93,    93,    94,    94,    95,    95,    95,
      89,    97,   100,   100,    97,    37,    60,    60,    37,    59,
      21,    37,    61,    29,    40,    40,    40,    40,    89,    89,
      25,    73,    84,    84,    84,    84,    77,    47,    76,    75,
      57,    89,    46,    89,    99,    21,    21,    97,    21,    38,
      36,    40,    40,    68,    84,    54,    83,    54,    54,    36,
      36,    33,     4,     5,    46,    89,    92,    46,    46,    58,
      79,    38,    21,    21,    47,    21,    21,    34,    62,    83,
      86,    41,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    53,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    56,    57,    56,    56,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    62,    64,    63,    65,    63,
      66,    66,    66,    66,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    69,    68,    70,    68,
      71,    68,    72,    68,    68,    73,    73,    73,    75,    74,
      76,    74,    77,    74,    74,    78,    78,    78,    79,    79,
      79,    79,    79,    79,    80,    80,    81,    82,    82,    82,
      82,    82,    82,    82,    83,    85,    84,    86,    86,    86,
      87,    87,    87,    88,    89,    89,    89,    89,    90,    90,
      91,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      93,    94,    94,    94,    94,    95,    95,    96,    96,    96,
      96,    96,    96,    98,    97,    97,    97,    99,    99,   100,
     101,   102,   102,   103,   104,   104,   104,   104,   106,   105,
     105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     4,     5,
       5,     7,     7,     0,     7,     3,     1,     0,     2,     0,
       2,     0,     5,     1,     2,     2,     0,     5,     0,     5,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     0,     4,     0,     4,
       0,     4,     0,     4,     4,     2,     2,     0,     0,     6,
       0,     6,     0,     6,     3,     7,     7,     1,     2,     2,
       2,     2,     2,     1,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     0,     1,     0,     4,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     1,     0,     1,     2,
       2,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       1,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     4,     4,     0,     5,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 127 "compiler_hw3.y" /* yacc.c:1646  */
    { dump_symbol(scope); }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 145 "compiler_hw3.y" /* yacc.c:1646  */
    { insert_symbol( scope, (yyvsp[-3].id_val), "int32", yylineno, "-"); 
                                                fprintf(file,"istore %d\n",lookup_symbol((yyvsp[-3].id_val), scope));
                                            }
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 148 "compiler_hw3.y" /* yacc.c:1646  */
    { insert_symbol( scope, (yyvsp[-2].id_val), "string", yylineno, "-"); 
                                                fprintf(file,"astore %d\n",lookup_symbol((yyvsp[-2].id_val), scope));
                                            }
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 151 "compiler_hw3.y" /* yacc.c:1646  */
    { insert_symbol( scope, (yyvsp[-3].id_val), "float32", yylineno, "-"); 
                                                fprintf(file,"fstore %d\n",lookup_symbol((yyvsp[-3].id_val), scope));
                                            }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 154 "compiler_hw3.y" /* yacc.c:1646  */
    { insert_symbol( scope, (yyvsp[-3].id_val), "bool", yylineno, "-"); }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 155 "compiler_hw3.y" /* yacc.c:1646  */
    {   printf("INT_LIT %d\n", (yyvsp[-3].i_val));
                                                insert_symbol( scope, (yyvsp[-5].id_val), "array", yylineno, "int32"); 
                                            }
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 158 "compiler_hw3.y" /* yacc.c:1646  */
    {   printf("INT_LIT %d\n", (yyvsp[-3].i_val));
                                                insert_symbol( scope, (yyvsp[-5].id_val), "array", yylineno, "float32"); 
                                            }
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 161 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                            printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val),lookup_symbol((yyvsp[-2].id_val), scope));
                            printf("INT_LIT %d\n",(yyvsp[0].i_val));
                        }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 186 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("STRING_LIT %s\n", (yyvsp[-2].s_val));}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 191 "compiler_hw3.y" /* yacc.c:1646  */
    {   printf("INC\n");

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
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 207 "compiler_hw3.y" /* yacc.c:1646  */
    {   printf("DEC\n");

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
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 225 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(type_flag,"int32"); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 226 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 239 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(type_flag,"int32"); }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 240 "compiler_hw3.y" /* yacc.c:1646  */
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
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 255 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("ADD\n");}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 256 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("SUB\n");}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 257 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("FLOAT_LIT %f\n",(yyvsp[-2].f_val));
                                    printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));
                                    printf("ADD\n");
                                }
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 262 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("FLOAT_LIT %f\n",(yyvsp[-2].f_val));
                                    printf("FLOAT_LIT %f\n",(yyvsp[0].f_val));
                                    printf("SUB\n");
                                }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 267 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
                                    printf("INT_LIT %d\n", (yyvsp[0].i_val));
                                    printf("ADD\n");
                                }
#line 1854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 276 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("INT_LIT %d\n",(yyvsp[-2].i_val));
                                    printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
                                    printf("error:%d: invalid operation: ADD (mismatched types int32 and float32)\n", yylineno+1);
                                    printf("ADD\n");
                                }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 282 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("FLOAT_LIT %f\n",(yyvsp[-2].f_val));
                                    printf("INT_LIT %d\n", (yyvsp[0].i_val));
                                    printf("error:%d: invalid operation: ADD (mismatched types float32 and int32)\n", yylineno+1);
                                    printf("ADD\n");
                                }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 288 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("INT_LIT %d\n",(yyvsp[-2].i_val));
                                    printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
                                    printf("error:%d: invalid operation: SUB (mismatched types int32 and float32)\n", yylineno+1);
                                    printf("SUB\n");
                                }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 294 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("FLOAT_LIT %f\n",(yyvsp[-2].f_val));
                                    printf("INT_LIT %d\n", (yyvsp[0].i_val));
                                    printf("error:%d: invalid operation: SUB (mismatched types float32 and int32)\n", yylineno+1);
                                    printf("SUB\n");
                                }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 300 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("INT_LIT %d\n",(yyvsp[-2].i_val));
                                    printf("FLOAT_LIT %f\n", (yyvsp[0].f_val));
                                    printf("error:%d: invalid operation: MUL (mismatched types int32 and float32)\n", yylineno+1);
                                    printf("MUL\n");
                                }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 306 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("FLOAT_LIT %f\n",(yyvsp[-2].f_val));
                                    printf("INT_LIT %d\n", (yyvsp[0].i_val));
                                    printf("error:%d: invalid operation: MUL (mismatched types float32 and int32)\n", yylineno+1);
                                    printf("MUL\n");
                                }
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 312 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
                                    printf("INT_LIT %d\n", (yyvsp[0].i_val));
                                    printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno+1);
                                    printf("REM\n");
                                }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 318 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("error:%d: invalid operation: (operator LAND not defined on int32)\n", yylineno+1);
                                    printf("LAND\n");
                                }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 322 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("error:%d: invalid operation: (operator LAND not defined on float32)\n", yylineno+1);
                                    printf("LAND\n");
                                }
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 326 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    yyerror("invalid operation: (operator LOR not defined on int32)");
                                    printf("LOR\n");
                                }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 333 "compiler_hw3.y" /* yacc.c:1646  */
    {yyerror("int32");}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 334 "compiler_hw3.y" /* yacc.c:1646  */
    {yyerror("float32");}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 335 "compiler_hw3.y" /* yacc.c:1646  */
    {yyerror("string");}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 336 "compiler_hw3.y" /* yacc.c:1646  */
    {yyerror("int32");}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 347 "compiler_hw3.y" /* yacc.c:1646  */
    {
                            printf("error:%d: non-bool (type float32) used as for condition\n", yylineno+1);
                            scope++;
                        }
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 351 "compiler_hw3.y" /* yacc.c:1646  */
    {scope--;}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 352 "compiler_hw3.y" /* yacc.c:1646  */
    {
                        printf("error:%d: non-bool (type int32) used as for condition\n", yylineno+1);
                        scope++;
                    }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 356 "compiler_hw3.y" /* yacc.c:1646  */
    {scope--;}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 357 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                    printf("error:%d: non-bool (type int32) used as for condition\n", yylineno+1);
                                    scope++;
                                }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 361 "compiler_hw3.y" /* yacc.c:1646  */
    {scope--;}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 373 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("ADD_ASSIGN\n"); }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 374 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("SUB_ASSIGN\n"); }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 375 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("MUL_ASSIGN\n"); }
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 376 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("QUO_ASSIGN\n"); }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 377 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("REM_ASSIGN\n"); }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 382 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                    if(id_type != var_type) {
                        printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, table[id_type].type, table[var_type].type);
                    }
                    printf("ASSIGN\n"); 
                }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 388 "compiler_hw3.y" /* yacc.c:1646  */
    {   
                            int tmp = -1;
                            for(int i=0; i<=scope; i++) {
                                if(lookup_symbol((yyvsp[0].id_val), i) != -1) 
                                    tmp = lookup_symbol((yyvsp[0].id_val), i);
                            }
                            if(tmp == -1)
                                printf("error:%d: undefined: %s\n", yylineno+1, (yyvsp[0].id_val));
                            printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), tmp);
                            yyerror("cannot assign to int32");
                            printf("ADD_ASSIGN\n");
                        }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 407 "compiler_hw3.y" /* yacc.c:1646  */
    {var_type = typeI; }
#line 2091 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 408 "compiler_hw3.y" /* yacc.c:1646  */
    {var_type = typeF; }
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 409 "compiler_hw3.y" /* yacc.c:1646  */
    {var_type = typeS; }
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 410 "compiler_hw3.y" /* yacc.c:1646  */
    {var_type = typeB; }
#line 2109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 412 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
                                strcpy(type_flag,table[lookup_symbol((yyvsp[0].id_val),scope)].type);
                                var_type = lookup_symbol((yyvsp[0].id_val), scope);
                            }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 421 "compiler_hw3.y" /* yacc.c:1646  */
    {   
                int tmp = -1;
                for(int i=0; i<=scope; i++) {
                    if(lookup_symbol((yyvsp[0].id_val), i) != -1) 
                        tmp = lookup_symbol((yyvsp[0].id_val), i);
                }
            
                if( tmp == -1 ){
                    printf("error:%d: undefined: %s\n", yylineno+1, (yyvsp[0].id_val));
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
                    printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), tmp);    
                    strcpy(type_flag,table[tmp].type);                    
                }

                Find_index = tmp;
            }
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 453 "compiler_hw3.y" /* yacc.c:1646  */
    {scope++;}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 453 "compiler_hw3.y" /* yacc.c:1646  */
    { scope--; }
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 457 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
                        if( strcmp(table[lookup_symbol((yyvsp[-2].id_val), scope)].type,table[lookup_symbol((yyvsp[0].id_val), scope)].type) != 0 ) {
                            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno+1, table[lookup_symbol((yyvsp[-2].id_val), scope)].type,table[lookup_symbol((yyvsp[0].id_val), scope)].type);
                        }
                        printf("ADD\n");

                        fprintf(file,"iload %d\n",lookup_symbol((yyvsp[-2].id_val),scope));
                        fprintf(file,"iload %d\n",lookup_symbol((yyvsp[0].id_val),scope));
                        fprintf(file,"iadd\n");
                      }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 469 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
                        if( strcmp(table[lookup_symbol((yyvsp[-2].id_val), scope)].type,table[lookup_symbol((yyvsp[0].id_val), scope)].type) != 0 ) {
                            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno+1, table[lookup_symbol((yyvsp[-2].id_val), scope)].type,table[lookup_symbol((yyvsp[0].id_val), scope)].type);
                        }
                        printf("SUB\n"); 

                        fprintf(file,"iload %d\n",lookup_symbol((yyvsp[-2].id_val),scope));
                        fprintf(file,"iload %d\n",lookup_symbol((yyvsp[0].id_val),scope));
                        fprintf(file,"isub\n");
                      }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 485 "compiler_hw3.y" /* yacc.c:1646  */
    {
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
                        if( strcmp(table[lookup_symbol((yyvsp[-2].id_val), scope)].type,table[lookup_symbol((yyvsp[0].id_val), scope)].type) != 0 ) {
                            printf("error:%d: invalid operation: MUL (mismatched types %s and %s)\n", yylineno+1, table[lookup_symbol((yyvsp[-2].id_val), scope)].type,table[lookup_symbol((yyvsp[0].id_val), scope)].type);
                        }
                        printf("MUL\n"); 

                        fprintf(file,"iload %d\n",lookup_symbol((yyvsp[-2].id_val),scope));
                        fprintf(file,"iload %d\n",lookup_symbol((yyvsp[0].id_val),scope));
                        fprintf(file,"imul\n");
                      }
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 497 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
                        if( strcmp(table[lookup_symbol((yyvsp[-2].id_val), scope)].type,table[lookup_symbol((yyvsp[0].id_val), scope)].type) != 0 ) {
                            printf("error:%d: invalid operation: QUO (mismatched types %s and %s)\n", yylineno+1, table[lookup_symbol((yyvsp[-2].id_val), scope)].type,table[lookup_symbol((yyvsp[0].id_val), scope)].type);
                        }
                        printf("QUO\n"); 

                        fprintf(file,"iload %d\n",lookup_symbol((yyvsp[-2].id_val),scope));
                        fprintf(file,"iload %d\n",lookup_symbol((yyvsp[0].id_val),scope));
                        fprintf(file,"idiv\n");
                      }
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 509 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-2].id_val), lookup_symbol((yyvsp[-2].id_val), scope));
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope));
                        if( strcmp(table[lookup_symbol((yyvsp[0].id_val), scope)].type,"float32") == 0 ) {
                            printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno+1);
                        }
                        printf("REM\n"); 

                        fprintf(file,"iload %d\n",lookup_symbol((yyvsp[-2].id_val),scope));
                        fprintf(file,"iload %d\n",lookup_symbol((yyvsp[0].id_val),scope));
                        fprintf(file,"irem\n");
                      }
#line 2250 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 528 "compiler_hw3.y" /* yacc.c:1646  */
    { strcpy(type_flag,"bool");}
#line 2256 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 536 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("LOR\n"); }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 540 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("LAND\n"); }
#line 2268 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 544 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("GTR\n"); }
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 545 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("LSS\n"); }
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 546 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("GEQ\n"); }
#line 2286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 547 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("LEQ\n"); }
#line 2292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 548 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("EQL\n"); }
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 549 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("NEQ\n"); }
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 554 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                            printf("ADD\n"); 
                                            if(strcmp(type_flag,"int32")==0){
                                                fprintf(file,"iadd\n");
                                            }
                                            else if(strcmp(type_flag,"float32")==0){
                                                fprintf(file,"fadd\n");
                                            }
                                            
                                        }
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 564 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                            printf("SUB\n"); 
                                            if(strcmp(type_flag,"int32")==0){
                                                fprintf(file,"isub\n");
                                            }
                                            else if(strcmp(type_flag,"float32")==0){
                                                fprintf(file,"fsub\n");
                                            }
                                        }
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 577 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                        printf("MUL\n");
                                        if(strcmp(type_flag,"int32")==0){
                                                fprintf(file,"imul\n");
                                        }
                                        else if(strcmp(type_flag,"float32")==0){
                                            fprintf(file,"fmul\n");
                                        } 
                                    }
#line 2347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 586 "compiler_hw3.y" /* yacc.c:1646  */
    {
                                        printf("QUO\n"); 
                                        if(strcmp(type_flag,"int32")==0){
                                            fprintf(file,"idiv\n");
                                        }
                                        else if(strcmp(type_flag,"float32")==0){
                                            fprintf(file,"fdiv\n");
                                        }
                                    }
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 595 "compiler_hw3.y" /* yacc.c:1646  */
    {   
                                        printf("REM\n"); 
                                        if(strcmp(type_flag,"int32")==0){
                                            fprintf(file,"irem\n");
                                        }
                                        else if(strcmp(type_flag,"float32")==0){
                                            fprintf(file,"frem\n");
                                        }
                                    }
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 622 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("NOT\n"); strcpy(type_flag,"bool"); }
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 623 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("TRUE\n"); strcpy(type_flag,"bool"); }
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 624 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("FALSE\n"); strcpy(type_flag,"bool");}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 629 "compiler_hw3.y" /* yacc.c:1646  */
    {strcpy(type_flag,"int32");}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 630 "compiler_hw3.y" /* yacc.c:1646  */
    {strcpy(type_flag,"float32");}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 634 "compiler_hw3.y" /* yacc.c:1646  */
    {   printf("INT_LIT %d\n", (yyvsp[0].i_val)); 
                    fprintf(file,"ldc %d\n",(yyvsp[0].i_val));
                }
#line 2413 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 640 "compiler_hw3.y" /* yacc.c:1646  */
    {   printf("FLOAT_LIT %f\n", (yyvsp[0].f_val)); 
                        fprintf(file,"ldc %f\n",(yyvsp[0].f_val)); 
                    }
#line 2421 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 646 "compiler_hw3.y" /* yacc.c:1646  */
    {   
                                printf("INT_LIT %d\n", abs((yyvsp[0].si_val))); 
                                if( (yyvsp[0].si_val) >=0 )
                                    printf("POS\n");
                                else
                                    printf("NEG\n");
                            }
#line 2433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 653 "compiler_hw3.y" /* yacc.c:1646  */
    {   
                                printf("FLOAT_LIT %f\n", fabs((yyvsp[0].sf_val))); 
                                if( (yyvsp[0].sf_val) >=0 )
                                    printf("POS\n");
                                else
                                    printf("NEG\n");
                            }
#line 2445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 663 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("STRING_LIT %s\n", (yyvsp[-1].s_val)); 
                                strcpy(type_flag,"string"); 
                                fprintf(file,"ldc %s\n",(yyvsp[-1].s_val));
                            }
#line 2454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 670 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("F to I\n"); id_type = typeI; }
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 671 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("FLOAT_LIT %f\nF to I\n",(yyvsp[-1].f_val));  }
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 672 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("I to F\n"); }
#line 2472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 673 "compiler_hw3.y" /* yacc.c:1646  */
    { printf("INT_LIT %d\nI to F\n",(yyvsp[-1].i_val)); id_type = typeI; }
#line 2478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 677 "compiler_hw3.y" /* yacc.c:1646  */
    { 
                if(strcmp(table[lookup_symbol((yyvsp[0].id_val), scope)].type,"array")==0){
                    printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), lookup_symbol((yyvsp[0].id_val), scope)); 
                }
            }
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 682 "compiler_hw3.y" /* yacc.c:1646  */
    {strcpy(type_flag,table[lookup_symbol((yyvsp[-4].id_val), scope)].element);}
#line 2494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 684 "compiler_hw3.y" /* yacc.c:1646  */
    {   int tmp = -1;
                for(int i=0; i<=scope; i++) {
                    if( lookup_symbol((yyvsp[0].id_val), i) != -1) 
                        tmp = lookup_symbol((yyvsp[0].id_val), i);
                }
                if( tmp == -1 ) {
                    printf("error:%d: undefined: %s\n", yylineno+1, (yyvsp[0].id_val));
                }
                else {
                    printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].id_val), tmp); 
                    strcpy(type_flag,table[tmp].type);
                }
                
                if(strcmp(type_flag,"int32")==0)
                    fprintf(file,"iload %d\n",lookup_symbol((yyvsp[0].id_val),scope));
                else if(strcmp(type_flag,"float32")==0)
                    fprintf(file,"fload %d\n",lookup_symbol((yyvsp[0].id_val),scope));
            }
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2521 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 704 "compiler_hw3.y" /* yacc.c:1906  */


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
