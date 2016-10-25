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
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "parser.h"

#define YYDEBUG 1

int cont_while = 0;
int cont_for = 0;
int cont_if = 0;

extern FILE *yyin;
extern FILE *yyout;

int yylex(void);
tipoTree * cria_node(char nonT[20], int n_filhos, ...);
tipoTree * terminalNumber(int token_n);
tipoTree * terminalToken(char id[20], int token_n);
char * consultaToken(int token_n);
void yyerror(char *string);

int insereVar(listaVar **p, char *id, int value);
listaVar * consultaVar(listaVar *p, char *id);
int consultaFuncs(listaFuncs *p, char *id);
int insereFunc(listaFuncs **p, char *id);
int assignValues(tipoTree *p);

tipoTree *treeRoot = NULL;
listaVar *vars = NULL;
listaFuncs *funcs = NULL;
int G_NUM = 1;
int G_ACC = 0;


#line 103 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
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
    SEMICOL = 258,
    ASSIGN = 259,
    DO = 260,
    END = 261,
    WHILE = 262,
    FOR = 263,
    COMMA = 264,
    IF = 265,
    THEN = 266,
    FUNCTION = 267,
    ELSEIF = 268,
    ELSE = 269,
    OPENPAR = 270,
    CLOSEPAR = 271,
    LOCAL = 272,
    RETURN = 273,
    NIL = 274,
    TIMES = 275,
    MINUS = 276,
    PLUS = 277,
    DIV = 278,
    LT = 279,
    LTEQ = 280,
    GT = 281,
    GTEQ = 282,
    EQ = 283,
    NEQ = 284,
    AND = 285,
    OR = 286,
    BLOCO = 287,
    FUNCALL = 288,
    COMANDO_N = 289,
    RETURN_N = 290,
    EXP_N = 291,
    LIST_N = 292,
    LISTEXP_N = 293,
    NOT = 294,
    COMMENT = 295,
    C_COMMENT = 296,
    NAME = 297,
    NUMBER = 298
  };
#endif
/* Tokens.  */
#define SEMICOL 258
#define ASSIGN 259
#define DO 260
#define END 261
#define WHILE 262
#define FOR 263
#define COMMA 264
#define IF 265
#define THEN 266
#define FUNCTION 267
#define ELSEIF 268
#define ELSE 269
#define OPENPAR 270
#define CLOSEPAR 271
#define LOCAL 272
#define RETURN 273
#define NIL 274
#define TIMES 275
#define MINUS 276
#define PLUS 277
#define DIV 278
#define LT 279
#define LTEQ 280
#define GT 281
#define GTEQ 282
#define EQ 283
#define NEQ 284
#define AND 285
#define OR 286
#define BLOCO 287
#define FUNCALL 288
#define COMANDO_N 289
#define RETURN_N 290
#define EXP_N 291
#define LIST_N 292
#define LISTEXP_N 293
#define NOT 294
#define COMMENT 295
#define C_COMMENT 296
#define NAME 297
#define NUMBER 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "parser.y" /* yacc.c:355  */

	tipoTree *treePointer;
	int integer;
	char id[20];

#line 235 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    90,    91,    94,    95,    97,    98,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   112,   113,
     116,   117,   120,   121,   124,   125,   128,   129,   132,   135,
     136,   139,   140,   143,   146,   149,   150,   153,   156,   157,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOL", "ASSIGN", "DO", "END",
  "WHILE", "FOR", "COMMA", "IF", "THEN", "FUNCTION", "ELSEIF", "ELSE",
  "OPENPAR", "CLOSEPAR", "LOCAL", "RETURN", "NIL", "TIMES", "MINUS",
  "PLUS", "DIV", "LT", "LTEQ", "GT", "GTEQ", "EQ", "NEQ", "AND", "OR",
  "BLOCO", "FUNCALL", "COMANDO_N", "RETURN_N", "EXP_N", "LIST_N",
  "LISTEXP_N", "NOT", "COMMENT", "C_COMMENT", "NAME", "NUMBER", "$accept",
  "programa", "bloco", "bloco2", "bloco3", "comando", "otherexp", "elseif",
  "else", "optionListanome", "assignlistaexp", "comandoret",
  "optionListaexp", "optionSemicol", "chamadadefuncao", "listadenomes",
  "commaNome", "listaexp", "commaExp", "exp", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -26

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-26)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,   -26,     9,    13,   -24,    13,   -22,   -20,    13,     8,
      24,   -26,   -26,     9,   -26,   -26,    21,    32,    13,   -26,
      13,    13,     8,   -26,   -26,   111,    26,    42,    27,   -26,
      37,    40,   -26,   206,    13,    35,   -26,   -26,   -26,     9,
      13,   -26,   194,    17,   -26,     9,    13,    13,    13,    13,
      13,    13,    13,    13,    13,    13,    13,    13,    13,     9,
     -20,    13,   -26,   -26,   -26,    41,    44,    15,   -26,   -26,
     -26,    52,   -26,    17,    17,   -26,   -15,   -15,   -15,   -15,
     -15,   -15,   218,   124,   134,   -26,    71,   -26,   -26,    13,
     -26,   -26,   -26,    13,    -3,     9,   206,   157,    13,     9,
      82,    83,    13,    85,   178,   -26,   -26,   -26,   206,     9,
       9,    86,   -26,   -26
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     9,     7,     0,     0,     0,     0,     0,    29,    35,
       0,     2,     4,     7,     8,    11,     0,     0,     0,    42,
       0,     0,    41,    40,    43,     0,     0,     0,     0,    35,
      26,    31,    30,    38,    29,    34,     1,     3,     6,     7,
       0,    12,     0,    57,    56,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
      24,     0,    17,    32,    28,    37,     0,     0,     5,    10,
      58,     0,    46,    45,    44,    47,    50,    51,    52,    53,
      54,    55,    49,    48,     0,    20,     0,    25,    27,     0,
      33,    36,    13,     0,    22,     7,    39,    18,     0,     7,
       0,     0,     0,     0,     0,    23,    15,    16,    19,     7,
       7,     0,    21,    14
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,     2,    54,   -10,    -4,   -26,   -26,   -26,   -26,
     -26,   -26,    57,   -26,     0,    -6,   -26,   -25,   -26,    28
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    10,    11,    37,    12,    13,   103,    94,   100,    86,
      62,    14,    31,    64,    24,    16,    35,    32,    65,    33
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,    30,    15,    38,    17,    46,    47,    48,    49,    39,
      98,    99,     1,    15,     2,    69,     3,     4,    26,     5,
      28,     6,    29,    34,    36,    40,     7,     8,    18,    38,
      58,    25,    19,    27,    20,    39,    88,    46,    41,    15,
      49,    61,    60,    63,    67,    15,    42,    71,    43,    44,
      89,     9,    21,    59,    87,    22,    23,    91,    92,    15,
      90,    85,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    95,   106,   107,
     109,    66,   113,    68,     0,    15,     0,   101,     0,    15,
       0,   105,     0,     0,     0,     0,     0,     0,     0,    15,
      15,   111,   112,     0,     0,     0,    45,    96,     0,     0,
       0,    97,     0,     0,     0,     0,   104,     0,     0,     0,
     108,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    93,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,   110,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      70,     0,     0,     0,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     0,    57
};

static const yytype_int8 yycheck[] =
{
       0,     7,     2,    13,     2,    20,    21,    22,    23,    13,
      13,    14,     3,    13,     5,    40,     7,     8,    42,    10,
      42,    12,    42,    15,     0,     4,    17,    18,    15,    39,
       4,     3,    19,     5,    21,    39,    61,    20,     6,    39,
      23,     4,    15,     3,     9,    45,    18,    45,    20,    21,
       9,    42,    39,    11,    60,    42,    43,    42,     6,    59,
      16,    59,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    16,     6,     6,
       5,    34,     6,    39,    -1,    95,    -1,    95,    -1,    99,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
     110,   109,   110,    -1,    -1,    -1,     5,    89,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
     102,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,     9,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     7,     8,    10,    12,    17,    18,    42,
      45,    46,    48,    49,    55,    58,    59,    46,    15,    19,
      21,    39,    42,    43,    58,    63,    42,    63,    42,    42,
      59,    56,    61,    63,    15,    60,     0,    47,    48,    49,
       4,     6,    63,    63,    63,     5,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     4,    11,
      15,     4,    54,     3,    57,    62,    56,     9,    47,    61,
      16,    46,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    46,    53,    59,    61,     9,
      16,    42,     6,     9,    51,    16,    63,    63,    13,    14,
      52,    46,     9,    50,    63,    46,     6,     6,    63,     5,
      11,    46,    46,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    50,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    55,    56,
      56,    57,    57,    58,    59,    60,    60,    61,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     0,     1,     1,
       3,     1,     3,     5,    10,     7,     7,     3,     0,     2,
       0,     5,     0,     2,     0,     1,     0,     2,     3,     0,
       1,     0,     1,     4,     2,     0,     3,     2,     0,     3,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     3
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
        case 2:
#line 79 "parser.y" /* yacc.c:1646  */
    {
				if((yyvsp[0].treePointer) != NULL){
					(yyval.treePointer) = cria_node("programa", 1, (yyvsp[0].treePointer));
					treeRoot = (yyval.treePointer);
				}
		}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 90 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = cria_node("bloco", 2, (yyvsp[-1].treePointer), (yyvsp[0].treePointer)); }
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = cria_node("bloco", 1, (yyvsp[0].treePointer));}
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 94 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("comando", 2, (yyvsp[-1].treePointer), (yyvsp[0].treePointer));}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 95 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL;}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 97 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL; }
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 98 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("bloco", 1, (yyvsp[0].treePointer)); }
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 101 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = terminalToken(";", SEMICOL); }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 102 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = cria_node("comando", 3, (yyvsp[-2].treePointer), terminalToken("=", ASSIGN), (yyvsp[0].treePointer)); }
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 103 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = cria_node("comando", 1, (yyvsp[0].treePointer)); }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 104 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = cria_node("comando", 3, terminalToken("do", DO), terminalToken("end", END)); }
#line 1496 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = cria_node("comando", 5, terminalToken("while", WHILE), (yyvsp[-3].treePointer), terminalToken("do", DO), (yyvsp[-1].treePointer), terminalToken("end", END)); }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = cria_node("comando", 10, terminalToken("for", FOR), terminalToken((yyvsp[-8].id), NAME), terminalToken("=", ASSIGN), (yyvsp[-6].treePointer), terminalToken(",", COMMA), (yyvsp[-4].treePointer), (yyvsp[-3].treePointer), terminalToken("do", DO), (yyvsp[-1].treePointer), terminalToken("end", END) ); }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 107 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("comando", 7, terminalToken("if", IF), (yyvsp[-5].treePointer), terminalToken("then", THEN), (yyvsp[-3].treePointer), (yyvsp[-2].treePointer), (yyvsp[-1].treePointer), terminalToken("end", END)); }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 108 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = cria_node("comando", 7, terminalToken("function", FUNCTION), terminalToken((yyvsp[-5].id), NAME), terminalToken("(", OPENPAR), (yyvsp[-3].treePointer), terminalToken(")", CLOSEPAR), (yyvsp[-1].treePointer), terminalToken("end", END)); }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 109 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("comando", 3, terminalToken("local", LOCAL), (yyvsp[-1].treePointer), (yyvsp[0].treePointer)); }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 112 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL; }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 113 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = cria_node("listaexp", 2, terminalToken(",", COMMA), (yyvsp[0].treePointer)); }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 116 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL; }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 117 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("elseif", 5, (yyvsp[-4].treePointer), terminalToken("elseif", ELSEIF), (yyvsp[-2].treePointer), terminalToken("then", THEN), (yyvsp[0].treePointer)); }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 120 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = NULL; }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 121 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("comando", 2, terminalToken("else", ELSE), (yyvsp[0].treePointer)); }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 124 "parser.y" /* yacc.c:1646  */
    {(yyval.treePointer) = NULL;}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 125 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("listadenomes", 1, (yyvsp[0].treePointer)); }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 128 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL;}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 129 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("listaexp", 2, terminalToken("=", ASSIGN), (yyvsp[0].treePointer)); }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 132 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("comandoret", 3, terminalToken("return", RETURN), (yyvsp[-1].treePointer), (yyvsp[0].treePointer)); }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL; }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("listaexp", 1, (yyvsp[0].treePointer)); }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 139 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL; }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 140 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = terminalToken(";", SEMICOL); }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 143 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("chamadadefuncao", 4,terminalToken((yyvsp[-3].id), NAME), terminalToken("(", OPENPAR), (yyvsp[-1].treePointer), terminalToken(")", CLOSEPAR)); }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 146 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("listadenomes", 2, terminalToken((yyvsp[-1].id), NAME), (yyvsp[0].treePointer)); }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 149 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL;}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 150 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("listadenomes", 3, (yyvsp[-2].treePointer), terminalToken(",", COMMA), terminalToken((yyvsp[0].id), NAME)); }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 153 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("listaexp", 2,(yyvsp[-1].treePointer), (yyvsp[0].treePointer)); }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 156 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = NULL; }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("listaexp", 3, (yyvsp[-2].treePointer), terminalToken(",", COMMA), (yyvsp[0].treePointer)); }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 160 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = terminalNumber((yyvsp[0].integer)); }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 161 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = terminalToken((yyvsp[0].id), NAME); }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 162 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = terminalToken("nil", NIL); }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 163 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("chamadadefuncao", 1, (yyvsp[0].treePointer)); }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 164 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opbin", 3, (yyvsp[-2].treePointer), terminalToken("+", PLUS), (yyvsp[0].treePointer)); }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 165 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opbin", 3, (yyvsp[-2].treePointer), terminalToken("-", MINUS), (yyvsp[0].treePointer)); }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 166 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opbin", 3, (yyvsp[-2].treePointer), terminalToken("*", TIMES), (yyvsp[0].treePointer)); }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 167 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opbin", 3, (yyvsp[-2].treePointer), terminalToken("/", DIV), (yyvsp[0].treePointer)); }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 168 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opbin", 3, (yyvsp[-2].treePointer), terminalToken("or", OR), (yyvsp[0].treePointer)); }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 169 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opbin", 3, (yyvsp[-2].treePointer), terminalToken("and", AND), (yyvsp[0].treePointer)); }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 170 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opbin", 3, (yyvsp[-2].treePointer), terminalToken("<", LT), (yyvsp[0].treePointer)); }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 171 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opbin", 3, (yyvsp[-2].treePointer), terminalToken("<=", LTEQ), (yyvsp[0].treePointer)); }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 172 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opbin", 3, (yyvsp[-2].treePointer), terminalToken(">", GT), (yyvsp[0].treePointer)); }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 173 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opbin", 3, (yyvsp[-2].treePointer), terminalToken(">=", GTEQ), (yyvsp[0].treePointer)); }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 174 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opbin", 3, (yyvsp[-2].treePointer), terminalToken("==", EQ), (yyvsp[0].treePointer)); }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 175 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opbin", 3, (yyvsp[-2].treePointer), terminalToken("~=", NEQ), (yyvsp[0].treePointer)); }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 176 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opunaria", 2, terminalToken("not", NOT), (yyvsp[0].treePointer)); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 177 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("opunaria", 2, terminalToken("-", MINUS), (yyvsp[0].treePointer)); }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 178 "parser.y" /* yacc.c:1646  */
    { (yyval.treePointer) = cria_node("exp", 3,terminalToken("(", OPENPAR), (yyvsp[-1].treePointer), terminalToken(")", CLOSEPAR)); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1776 "y.tab.c" /* yacc.c:1646  */
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
#line 180 "parser.y" /* yacc.c:1906  */


tipoTree * cria_node(char nonT[20], int n_filhos, ...){

	va_list params;
	int i = 0;
	tipoTree *aux = malloc(sizeof(struct treeNode));
	aux->nonTerminal = malloc(sizeof(char)*strlen(nonT));
	strcpy(aux->nonTerminal, nonT);
	aux->num_filhos = n_filhos;
	aux->filhos = malloc(n_filhos * sizeof(struct treeNode));

	va_start(params, n_filhos);
	while(i < n_filhos)
	{
		aux->filhos[i] = va_arg(params, tipoTree*);
		i++;
	}

	va_end(params);
	return aux;
}

tipoTree * terminalNumber(int token_n){

	tipoTree *aux = malloc(sizeof(struct treeNode));
	aux->num_filhos = 0;
	aux->tokenNumber = NUMBER;
	aux->number = token_n;
	aux->id = NULL;
	return aux;
}

tipoTree * terminalToken(char id[20], int token_n){

	tipoTree *aux = malloc(sizeof(struct treeNode));
	aux->num_filhos = 0;
	aux->tokenNumber = token_n;
	aux->id = malloc(sizeof(char)*strlen(id));
	strcpy(aux->id, id);
	return aux;
}

char * consultaToken(int token_n){

	switch( token_n ){
		case AND :
			return "T_AND";
			break;
		case  NOT:
			return "T_NOT";
			break;
		case OR:
			return "T_OR";
			break;
		case ELSEIF:
			return "T_ELSEIF";
			break;
		case WHILE:
			return "T_WHILE";
			break;
		case DO:
			return "T_DO";
			break;
		case FUNCTION:
			return "T_FUNCTION";
			break;
		case END:
			return "T_END";
			break;
		case FOR:
			return "T_FOR";
			break;
		case ELSE:
			return "T_ELSE";
			break;
		case IF:
			return "T_IF";
			break;
		case THEN:
			return "T_THEN";
			break;
		case RETURN:
			return "T_RETURN";
			break;
		case LOCAL:
			return "T_LOCAL";
			break;
		case NIL:
			return "T_NIL";
			break;
		case NAME:
			return "T_NAME";
			break;
		case NUMBER:
			return "T_NUMBER";
			break;
		case PLUS:
			return "T_PLUS";
			break;
		case MINUS:
			return "T_MINUS";
			break;
		case TIMES:
			return "T_TIMES";
			break;
		case DIV:
			return "T_DIV";
			break;
		case COMMA:
			return "T_COMMA";
			break;
		case SEMICOL:
			return "T_SEMICOL";
			break;
		case ASSIGN:
			return "T_ASSIGN";
			break;
		case EQ:
			return "T_EQ";
			break;
		case NEQ:
			return "T_NEQ";
			break;
		case LTEQ:
			return "T_LTEQ";
			break;
		case GTEQ:
			return "T_GTEQ";
			break;
		case LT:
			return "T_LT";
			break;
		case GT:
			return "T_GT";
			break;
		case CLOSEPAR:
			return "T_CLOSEPAR";
			break;
		case OPENPAR:
			return "T_OPENPAR";
			break;
		default :
			return "NONE";
	}
};

int insereVar(listaVar **p, char *id, int value){

	listaVar *aux = malloc(sizeof(struct listaV));
	strcpy(aux->varName, id);
	aux->varValue = value;
	aux->prox = *p;
	*p = aux;
}

listaVar * consultaVar(listaVar *p, char *id){

	listaVar *aux;
	for(aux = p; aux != NULL; aux = aux->prox){
		if( strcmp(aux->varName,id) == 0){
			return aux;
		}
	}
	return NULL;
}

int consultaFuncs(listaFuncs *p, char *id){

	listaFuncs *aux;
	for(aux = p; aux != NULL; aux = aux->prox){
		if( strcmp(aux->fname,id) == 0 ){
			return 1;
		}
	}
	return 0;
}

int insereFunc(listaFuncs **p, char *id){

	listaFuncs *aux = malloc(sizeof(struct listaF));
	strcpy(aux->fname, id);
	aux->prox = *p;
	*p = aux;
}

int updateVar(listaVar *p, char *id, int newValue){

	listaVar *aux = consultaVar(p, id);
	// printf("foi?\n");
	if (aux != NULL)
		aux->varValue = newValue;
	else
		return -1;
	return 1;
}

void yyerror(char *string){  fprintf(stderr, "%s\n", string); }

int printTree(tipoTree *p){

	if(p == NULL)
		return 0;
	if(p->nonTerminal != NULL)
		fprintf(yyout,"[%s ", p->nonTerminal);
	else
		fprintf(yyout, "[");
	if(p->num_filhos == 0)
	{
		if (p->tokenNumber == NUMBER)
			fprintf(yyout, "%s %d", consultaToken(p->tokenNumber), p->number);
		else
			fprintf(yyout, "%s %s", consultaToken(p->tokenNumber), p->id);
	}
	else
	{
		int i;
		for(i = 0; i < p->num_filhos; i++)
			printTree(p->filhos[i]);
	}
	fprintf(yyout,"]");
}


int geraCodeOpBin(tipoTree *p){

	int i,x,y;
	if (p == NULL)
		return 0;

	if (p->nonTerminal == NULL)
		return 0;

	printf("cheguei em %s\n", p->nonTerminal);
	if( strcmp(p->nonTerminal,"opbin") == 0 ){

		//resolve primeiro filho
		if (p->filhos[0]->tokenNumber == NUMBER){

			//Primeiro fator eh um numero
			fprintf(yyout,"li $a0, %d\n", p->filhos[0]->number);
			fprintf(yyout,"sw $a0, 0($sp)\n");
			fprintf(yyout,"addiu $sp, $sp, -4\n");
			x = p->filhos[0]->number;
		}
		else
		{
			//Primeiro fator espera um resultado
			if( p->filhos[0]->nonTerminal != NULL){
				if (strcmp(p->filhos[0]->nonTerminal, "exp") == 0 ){
					geraCodeOpBin(p->filhos[0]->filhos[1]);
				}
				else{
					geraCodeOpBin(p->filhos[0]);
				}
				fprintf(yyout,"sw $a0, 0($sp)\n");
				fprintf(yyout,"addiu $sp, $sp, -4\n");
				x = G_ACC;
			}
			else
			{
				if(p->filhos[0]->tokenNumber == NAME){
					printf("achei a var %s\n", p->filhos[0]->id);
					listaVar *aux = consultaVar(vars, p->filhos[0]->id);
					if (aux == NULL)
						printf("Erro : var nao encontrada!!!!\n");
					else{
						fprintf(yyout, "lw $a0, %s\n", p->filhos[0]->id);
						fprintf(yyout, "sw $a0, 0($sp)\n");
						fprintf(yyout,"addiu $sp, $sp, -4\n");
					}
					x = aux->varValue;
				}
				else{
					printf("entrei aqui dentro do %s\n", p->nonTerminal);
					geraCodeOpBin(p->filhos[2]);
					fprintf(yyout,"sw $a0, 0($sp)\n");
					fprintf(yyout,"addiu $sp, $sp, -4\n");
					x = G_ACC;
				}
			}
		}
		if (p->filhos[2]->tokenNumber == NUMBER) {
			printf("cheguei aqui tbm hein\n");
			//Segundo fator eh um numero
			fprintf(yyout,"li $a0, %d\n", p->filhos[2]->number);
			fprintf(yyout,"sw $a0, 0($sp)\n");
			fprintf(yyout,"addiu $sp, $sp, -4\n");
			y = p->filhos[2]->number;
		}
		else
		{
			if( p->filhos[2]->nonTerminal != NULL){
				if ( strcmp(p->filhos[2]->nonTerminal, "exp") == 0 ){
					printf("entrou em exp\n");
					geraCodeOpBin(p->filhos[2]->filhos[1]);
				}
				else{
					printf("gerei aqui\n");
					geraCodeOpBin(p->filhos[2]);
				}
				fprintf(yyout,"sw $a0, 0($sp)\n");
				fprintf(yyout,"addiu $sp, $sp, -4\n");
				y = G_ACC;
			}
			else
			{
				if(p->filhos[2]->tokenNumber == NAME){
					printf("achei a var %s\n", p->filhos[2]->id);
					listaVar *aux = consultaVar(vars, p->filhos[2]->id);
					if (aux == NULL)
						printf("Erro : var nao encontrada!!!!\n");
					else
					{
						fprintf(yyout, "lw $a0, %s\n", p->filhos[2]->id);
						fprintf(yyout, "sw $a0, 0($sp)\n");
						fprintf(yyout,"addiu $sp, $sp, -4\n");
					}
					y = aux->varValue;
				}
				else{
					printf("entrei aqui dentro do %s\n", p->nonTerminal);
					geraCodeOpBin(p->filhos[2]);
					fprintf(yyout,"sw $a0, 0($sp)\n");
					fprintf(yyout,"addiu $sp, $sp, -4\n");
					y = G_ACC;
				}
			}
		}
		//Opera fatores
		fprintf(yyout,"lw $t1, 4($sp)\n");
		fprintf(yyout,"addiu $sp, $sp, 4\n");
		fprintf(yyout,"lw $a0, 4($sp)\n");
		fprintf(yyout,"addiu $sp, $sp, 4\n");

		if(p->filhos[1]->tokenNumber == PLUS){
			fprintf(yyout,"add $a0, $a0, $t1\n");
			G_ACC = x + y;
		}
		else if(p->filhos[1]->tokenNumber == MINUS)
		{
			fprintf(yyout,"sub $a0, $a0, $t1\n");
			G_ACC = x - y;
		}
		else if(p->filhos[1]->tokenNumber == TIMES)
		{
			fprintf(yyout,"mult $a0, $t1\n");
			fprintf(yyout,"mflo $a0\n");
			G_ACC = x * y;
		}
		else if(p->filhos[1]->tokenNumber == DIV){
			fprintf(yyout,"div $a0, $t1\n");
			fprintf(yyout,"mflo $a0\n");
			G_ACC = x/y;
		}
		else if(p->filhos[1]->tokenNumber == EQ)
		{
			fprintf(yyout, "seq $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == NEQ)
		{
			fprintf(yyout, "sne $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == GTEQ)
		{
			fprintf(yyout, "sge $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == GT)
		{
			fprintf(yyout, "sgt $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == LTEQ)
		{
			fprintf(yyout, "sle $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == LT)
		{
			printf("ta saindo da jaula\n");
			fprintf(yyout, "slt $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == AND)
		{
			fprintf(yyout, "and $a0, $a0, $t1\n");
		}
		else if(p->filhos[1]->tokenNumber == OR)
		{
			fprintf(yyout, "or $a0, $a0, $t1\n");
		}
	}
	else if(p->filhos[0]->tokenNumber == NUMBER)
	{
		printf("achei o numero %d\n", p->filhos[0]->number);
		fprintf(yyout, "li $a0, %d\n",p->filhos[0]->number);
		G_ACC = p->filhos[0]->number;
		return 0;
	}
	else if(p->filhos[0]->tokenNumber == NAME){

		printf("achei a var %s\n", p->filhos[0]->id);
		listaVar *aux = consultaVar(vars, p->filhos[0]->id);
		if (aux == NULL)
			printf("Erro : var nao encontrada!!!!\n");
		else
		fprintf(yyout, "lw $a0, %s\n", p->filhos[0]->id);

		G_ACC = aux->varValue;
		return 0;
	}
	else if( strcmp(p->nonTerminal,"opunaria") == 0 ){

		if(p->filhos[0]->tokenNumber == MINUS){
			geraCodeOpBin(p->filhos[1]);
			fprintf(yyout, "li $t1 -1\n");
			fprintf(yyout,"mult $a0, $t1\n");
			fprintf(yyout,"mflo $a0\n");
		}
		else
		{
			geraCodeOpBin(p->filhos[1]);
			if(G_ACC == 1)
				fprintf(yyout, "li $a0, 0\n");
			else //if (G_ACC == 0)
				fprintf(yyout, "li $a0, 1\n");
		}
		return 0;
	}
	else
	{

		for(i = 0; i < p->num_filhos; i++){
			if (p->filhos[i] != NULL) {
				geraCodeOpBin(p->filhos[i]);
			}
		}
	}
	return 0;
}

int nameOrNumber (tipoTree *p){
	printf("foi aqui\n");
	if(p->tokenNumber == NUMBER)
	{
		printf("achei o numero %d\n", p->number);
		fprintf(yyout, "li $a0, %d\n",p->number);
		G_ACC = p->number;
	}
	if(p->tokenNumber == NAME)
	{
		printf("achei a var %s\n", p->id);
		listaVar *aux = consultaVar(vars, p->id);
		if (aux == NULL)
			printf("Erro : var nao encontrada!!!!\n");
		else
		fprintf(yyout, "lw $a0, %s\n", p->id);
		G_ACC = aux->varValue;
	}
	printf("saiu nameOrNumber\n");
}

int trataVars(tipoTree *p){

	if(p == NULL)
		return 0;
	if(p->num_filhos == 0)
	{
		if ((p->tokenNumber == NAME) && (consultaVar(vars, p->id) == NULL) && !(consultaFuncs(funcs,p->id))){
			insereVar(&vars, p->id, 0);
			fprintf(yyout, "%s: .word 0\n", p->id);
		}
	}
	else
	{
		int i;
		for(i = 0; i < p->num_filhos; i++)
			trataVars(p->filhos[i]);
	}
}

int trataFuncs(tipoTree *p){

	if(p == NULL)
		return 0;

	if( strcmp(p->nonTerminal,"comando") == 0){
		if(p->filhos[0]->id != NULL)
		{
			if( strcmp(p->filhos[0]->id, "function")){
				if(!consultaFuncs(funcs, p->filhos[1]->id))
					insereFunc(&funcs, p->filhos[1]->id);
			}
		}
	}
	else
	{
		int i;
		for(i = 0; i < p->num_filhos; i++)
			trataFuncs(p->filhos[i]);
	}
}

// int buscaValor(tipoTree *p){
//
// }

// int buscaVar(tipoTree *p, tipoTree *q){
//
// 	int new_value, i;
// 	if(p == NULL)
// 		return 0;
// 	else if(p->nonTerminal == NULL){
// 		if (p->tokenNumber == NAME){
// 			new_value = buscaValor(q);
// 			updateVar(vars, p->id, new_value);
// 			G_NUM++;
// 		}
// 	}
// 	else
// 		for(i = 0; i < p->num_filhos; i++)
// 			buscaVar(p->filhos[i], q);
// }

int geraCode(tipoTree *p){

	int i;
	if(p == NULL)
		return 0;
	if(p->nonTerminal == NULL)
		return 0;

	printf("entrei em %s\n", p->nonTerminal);

	if( strcmp(p->nonTerminal, "chamadadefuncao") == 0 )
	{
		if( strcmp(p->filhos[0]->id, "print") == 0){
			printf("entrei no print\n");
			geraCode(p->filhos[2]);
			printf("saiu print\n");
			fprintf(yyout, "li $v0, 1\n");
			fprintf(yyout, "syscall\n");
			fprintf(yyout, "li $v0, 4\n");
			fprintf(yyout, "la $a0, _newline\n");
			fprintf(yyout, "syscall\n");
		}
		// gerando codigo para chamada de funcao
		else {
			char nome[30];
			strcpy(nome, p->filhos[0]->id);
			strcat(nome, "_entry");

			fprintf(yyout, "sw $fp, 0($sp)\n");
			fprintf(yyout, "addiu $sp, $sp, -4\n");

			// a funcao possui parametros
			if (p->filhos[2] != NULL) {
				/* code */
			}
			else {

				fprintf(yyout, "jal %s\n", nome);
			}
		}
		return 0;
	}

	if( strcmp(p->nonTerminal, "listaexp") == 0 ){

		// printf("entrei na listaexp\n");
		geraCodeOpBin(p);
		// printf("sai de listaexp\n");
		return 0;
	}
	if( strcmp(p->nonTerminal, "comando") == 0){

		if (p->filhos[0]->id != NULL) {

			// gerando codigo para instrucao while
			if (strcmp(p->filhos[0]->id, "while") == 0) {
				cont_while++;
				fprintf(yyout, "true_bw%d:\n", cont_while);
				geraCodeOpBin(p->filhos[1]);
				fprintf(yyout, "li $t1, 0\n");
				fprintf(yyout, "beq $a0, $t1, false_bw%d\n", cont_while);
				geraCode(p->filhos[3]);
				fprintf(yyout, "j true_bw%d\n", cont_while);
				fprintf(yyout, "false_bw%d:\n", cont_while);
			}

			// gerando codigo para instrucao if [else]
			if (strcmp(p->filhos[0]->id, "if") == 0) {
				cont_if++;
				geraCodeOpBin(p->filhos[1]);
				fprintf(yyout, "li $t1, 0\n");
				fprintf(yyout, "beq $a0, $t1, false_bi%d\n", cont_if);
				geraCode(p->filhos[3]);
				fprintf(yyout, "j exit_if%d\n", cont_if);

				fprintf(yyout, "false_bi%d:\n", cont_if);
				if (p->filhos[5] != NULL) {
					// possui comando else no codigo
					geraCode(p->filhos[5]->filhos[1]);
				}
				fprintf(yyout, "exit_if%d:\n", cont_if);
			}

			// gerando codigo para instrucao for
			// t0 armazena ate onde o for deve ir
			if (strcmp(p->filhos[0]->id, "for") == 0) {
				
				cont_for++;
				if(p->filhos[5]->nonTerminal != NULL)
					geraCodeOpBin(p->filhos[3]);
				else
					nameOrNumber(p->filhos[3]);
				printf("%d\n", G_ACC);
				fprintf(yyout, "sw $a0, %s\n", p->filhos[1]->id);
				if(p->filhos[5]->nonTerminal != NULL)
					geraCodeOpBin(p->filhos[5]);
				else
					nameOrNumber(p->filhos[5]);
				printf("%d\n", G_ACC);
				fprintf(yyout, "move $a0, $t0\n");
				// pegar terceiro parametro, se tiver

				fprintf(yyout, "true_bf%d:\n", cont_for);
				fprintf(yyout, "lw $a0, %s\n", p->filhos[1]->id);
				fprintf(yyout, "ble $a0, $t0, false_bf%d\n", cont_for);
				geraCode(p->filhos[8]);
				fprintf(yyout, "lw $a0, %s\n", p->filhos[1]->id);
				fprintf(yyout, "li $t1, 1\n");
				fprintf(yyout, "add $a0, $a0, $t1\n");
				fprintf(yyout, "sw $a0, %s\n", p->filhos[1]->id);
				fprintf(yyout, "j true_bf%d\n", cont_for);

				fprintf(yyout, "false_bf%d:\n", cont_for);

			}

			// gerando codigo para definicao de funcao
			if (strcmp(p->filhos[0]->id, "function") == 0) {
				char nome2[30];
				strcpy(nome2, p->filhos[1]->id);
				strcat(nome2, "_entry");
				fprintf(yyout, "%s:\n", nome2);
				fprintf(yyout, "move $fp, $sp\n");
				fprintf(yyout, "sw $ra, 0($sp)\n");
				fprintf(yyout, "addiu $sp, $sp, -4\n");
				geraCode(p->filhos[5]);
				fprintf(yyout, "lw $ra, 4($sp)\n");
				// tem que fazer uma busca pelo nome da funcao para saber a quantidade de parametros
				// z = quantidade de parametros da funcao
				// fprintf(yyout, "addiu $sp, $sp, %d\n", z);
				fprintf(yyout, "lw $fp, 0($sp)\n");
				fprintf(yyout, "jr $ra\n");
			}

			return 0;
		}

		if(p->num_filhos == 3)
		{
			if(p->filhos[1]->tokenNumber == ASSIGN)
			{
				printf("entrei no assign\n");
				geraCodeOpBin(p->filhos[2]);
				listaVar *aux;
				int new_value = G_ACC;
				printf("saiu com valor: %d\n", new_value);
				printf("%s\n", p->filhos[0]->filhos[0]->id);
				aux = consultaVar(vars, p->filhos[0]->filhos[0]->id);
				aux->varValue = new_value;
				// fprintf(yyout, "li $a0, %d\n", new_value);
				fprintf(yyout, "sw $a0, %s\n", p->filhos[0]->filhos[0]->id);
				printf("sai do assign\n");
			}
			return 0;
		}
	}
	if(p->filhos[0]->nonTerminal != NULL)
	{
		for(i = 0; i < p->num_filhos; i++){
			if(p->filhos[i] != NULL){
				// printf("%d %s\n", i, p->nonTerminal);
				geraCode(p->filhos[i]);
			}
		}
	}
	printf("terminei os filhos de %s\n", p->nonTerminal);
}

int main(int argc, char** argv){

	yyin = fopen(argv[1], "r");
	yyout = fopen(argv[2], "w");

	if(!yyin) printf("Arquivo nao pode ser aberto!\n");
	else{
		yyparse();
	}

	//Inicialiazao de ambiente
	// printTree(treeRoot);
	insereFunc(&funcs, "print");
	trataFuncs(treeRoot);

	//Inicializacao MIPS
	fprintf(yyout, "\n.data\n");
	trataVars(treeRoot);
	fprintf(yyout, "\n");
	fprintf(yyout, "_newline: .asciiz \"\\n\"\n");
	fprintf(yyout,".text\n");
	fprintf(yyout,".globl main\n\n");
	fprintf(yyout,"main:\n");

	geraCode(treeRoot);

	fprintf(yyout, "li $v0, 4\n");
	fprintf(yyout, "la $a0, _newline\n");
	fprintf(yyout, "syscall\n");

	fprintf(yyout, "\nli $v0, 10\n");
	fprintf(yyout, "syscall");
	fprintf(yyout,"\n");

	fclose(yyin);
	fclose(yyout);

	return 0;
}
