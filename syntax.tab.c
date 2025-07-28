
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntax.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include "TS.h"
    #include "quad.h"
    extern int nb_ligne;
    extern int col;
    extern FILE *yyin;
    void yyerror(const char *s);
    #define YYDEBUG 1
    int yylex(void);
    char scopeName[50];
    char* current_type;
    char* current_method_return_type;
    int label_index = 0;
    const char* new_label() {
        static char label[100][10];
        snprintf(label[label_index], sizeof(label[label_index]), "L%d", label_index);
        return label[label_index++];
    }


/* Line 189 of yacc.c  */
#line 96 "syntax.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     mc_class = 258,
     mc_int = 259,
     mc_float = 260,
     mc_double = 261,
     mc_char = 262,
     mc_boolean = 263,
     mc_string = 264,
     mc_excp = 265,
     mc_if = 266,
     mc_else = 267,
     mc_for = 268,
     mc_while = 269,
     mc_do = 270,
     mc_switch = 271,
     mc_case = 272,
     mc_default = 273,
     mc_break = 274,
     mc_return = 275,
     mc_public = 276,
     mc_static = 277,
     mc_void = 278,
     mc_private = 279,
     mc_protected = 280,
     mc_try = 281,
     mc_catch = 282,
     mc_finally = 283,
     mc_new = 284,
     mc_throws = 285,
     mc_throw = 286,
     mc_this = 287,
     mc_true = 288,
     mc_false = 289,
     mc_print = 290,
     chaine = 291,
     caractere = 292,
     id = 293,
     integer = 294,
     real = 295,
     addition = 296,
     soustraction = 297,
     multiplication = 298,
     division = 299,
     mod = 300,
     affectation = 301,
     sup = 302,
     inf = 303,
     incrementation = 304,
     inf_egal = 305,
     sup_egal = 306,
     egal = 307,
     different = 308,
     et = 309,
     ou = 310,
     pt_exclamation = 311,
     addition_assignment = 312,
     point = 313,
     pt_virgule = 314,
     deux_points = 315,
     virgule = 316,
     accolade_o = 317,
     accolade_f = 318,
     parenthese_o = 319,
     parenthese_f = 320,
     crochet_o = 321,
     crochet_f = 322,
     IFX = 323,
     END_OF_FILE = 324
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 26 "syntax.y"

    float fval;
    int ival;
    char* str;
    char* res;
    struct {
        char* type;   // Contiendra le type (ex. "int", "float", etc.)
        char* value;  // Contiendra la valeur d'initialisation (ex. "5", "0.0", etc.)
    } attr;



/* Line 214 of yacc.c  */
#line 214 "syntax.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 226 "syntax.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   504

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNRULES -- Number of states.  */
#define YYNSTATES  333

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   324

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    70,    68,     2,    69,     2,    71,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    72,    73
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    11,    12,    20,    21,    23,
      24,    26,    28,    31,    33,    35,    37,    39,    43,    47,
      50,    54,    55,    58,    62,    65,    66,    67,    77,    78,
      88,    89,    98,    99,   108,   109,   117,   118,   125,   126,
     129,   131,   135,   137,   139,   142,   145,   147,   149,   151,
     153,   155,   157,   159,   161,   163,   165,   167,   171,   177,
     178,   180,   182,   186,   189,   192,   196,   197,   199,   201,
     204,   206,   208,   210,   212,   214,   216,   218,   220,   222,
     224,   230,   233,   236,   241,   244,   247,   253,   261,   267,
     275,   284,   286,   289,   292,   293,   295,   296,   298,   307,
     308,   310,   312,   315,   321,   322,   325,   326,   328,   332,
     334,   336,   338,   340,   342,   344,   346,   349,   353,   357,
     362,   364,   367,   368,   376,   377,   380,   382,   384,   386,
     390,   394,   396,   400,   402,   406,   408,   412,   416,   418,
     422,   426,   430,   434,   436,   440,   444,   446,   450,   454,
     458,   460,   463,   466,   469,   472,   475,   478,   481,   482,
     486,   490,   492,   494,   496,   498,   500,   502,   504,   506,
     512,   518,   522,   526,   532,   541,   542,   544,   546,   550,
     552,   556,   557
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      75,     0,    -1,    76,    73,    -1,    77,    -1,    76,    77,
      -1,    -1,    79,     3,    38,    62,    78,    80,    63,    -1,
      -1,    21,    -1,    -1,    81,    -1,    82,    -1,    81,    82,
      -1,    83,    -1,    88,    -1,    93,    -1,   105,    -1,   100,
      84,    59,    -1,   101,    84,    59,    -1,    38,    85,    -1,
      84,    61,    38,    -1,    -1,    46,   132,    -1,   100,    38,
      87,    -1,    46,   132,    -1,    -1,    -1,    98,    23,    38,
      89,    64,   102,    65,    96,   105,    -1,    -1,    98,   100,
      38,    90,    64,   102,    65,    96,   105,    -1,    -1,    23,
      38,    91,    64,   102,    65,    96,   105,    -1,    -1,   100,
      38,    92,    64,   102,    65,    96,   105,    -1,    -1,    98,
      38,    94,    64,   102,    65,   105,    -1,    -1,    38,    95,
      64,   102,    65,   105,    -1,    -1,    30,    97,    -1,   100,
      -1,    97,    61,   100,    -1,    99,    -1,    22,    -1,    99,
      22,    -1,    22,    99,    -1,    21,    -1,    24,    -1,    25,
      -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,     8,
      -1,     9,    -1,    10,    -1,    38,    -1,   100,    66,    67,
      -1,   100,    66,    67,    66,    67,    -1,    -1,   103,    -1,
     104,    -1,   103,    61,   104,    -1,   100,    38,    -1,   101,
      38,    -1,    62,   106,    63,    -1,    -1,   107,    -1,   108,
      -1,   107,   108,    -1,   105,    -1,    83,    -1,   110,    -1,
     111,    -1,   112,    -1,   113,    -1,   117,    -1,   125,    -1,
     126,    -1,   127,    -1,    35,    64,   115,    65,    59,    -1,
     134,    59,    -1,   109,    59,    -1,   145,    64,   146,    65,
      -1,   142,   144,    -1,   142,    49,    -1,    11,    64,   132,
      65,   108,    -1,    11,    64,   132,    65,   108,    12,   108,
      -1,    14,    64,   132,    65,   108,    -1,    15,   108,    14,
      64,   132,    65,    59,    -1,    13,    64,   114,   115,    59,
     116,    65,   108,    -1,    59,    -1,   132,    59,    -1,    86,
      59,    -1,    -1,   132,    -1,    -1,   132,    -1,    16,    64,
     132,    65,    62,   118,   122,    63,    -1,    -1,   119,    -1,
     120,    -1,   119,   120,    -1,    17,   124,    60,   106,   121,
      -1,    -1,    19,    59,    -1,    -1,   123,    -1,    18,    60,
     106,    -1,    39,    -1,    40,    -1,    33,    -1,    34,    -1,
      38,    -1,    36,    -1,    37,    -1,    20,    59,    -1,    20,
     132,    59,    -1,    31,   132,    59,    -1,    26,   105,   128,
     131,    -1,   129,    -1,   128,   129,    -1,    -1,    27,    64,
     100,    38,    65,   130,   105,    -1,    -1,    28,   105,    -1,
     135,    -1,   135,    -1,   134,    -1,   142,    46,   133,    -1,
     142,    57,   133,    -1,   136,    -1,   135,    55,   136,    -1,
     137,    -1,   136,    54,   137,    -1,   138,    -1,   137,    52,
     138,    -1,   137,    53,   138,    -1,   139,    -1,   138,    48,
     139,    -1,   138,    47,   139,    -1,   138,    50,   139,    -1,
     138,    51,   139,    -1,   140,    -1,   139,    41,   140,    -1,
     139,    42,   140,    -1,   141,    -1,   140,    43,   141,    -1,
     140,    44,   141,    -1,   140,    45,   141,    -1,   142,    -1,
      56,   141,    -1,    42,   141,    -1,    41,   141,    -1,    49,
     141,    -1,   145,   143,    -1,   142,   144,    -1,   142,    49,
      -1,    -1,    64,   146,    65,    -1,    58,    38,   143,    -1,
      38,    -1,    39,    -1,    40,    -1,    33,    -1,    34,    -1,
      37,    -1,    36,    -1,    32,    -1,    29,    38,    64,   146,
      65,    -1,    29,    10,    64,   146,    65,    -1,    64,   149,
      65,    -1,    62,   148,    63,    -1,    29,   100,    66,   132,
      67,    -1,    29,   100,    66,   132,    67,    66,   132,    67,
      -1,    -1,   147,    -1,   132,    -1,   147,    61,   132,    -1,
     132,    -1,   148,    61,   132,    -1,    -1,   148,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   109,   110,   121,   120,   139,   140,   144,
     146,   151,   152,   157,   158,   159,   160,   170,   171,   175,
     191,   201,   202,   207,   228,   233,   243,   242,   263,   262,
     280,   279,   297,   296,   318,   317,   334,   333,   351,   353,
     358,   359,   364,   365,   366,   367,   372,   373,   374,   379,
     380,   381,   382,   383,   384,   385,   386,   391,   398,   408,
     410,   415,   416,   421,   430,   447,   451,   453,   458,   459,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   476,   477,   482,   483,   484,   493,   501,   517,   550,
     555,   585,   586,   587,   593,   597,   606,   609,   617,   621,
     623,   628,   629,   634,   637,   639,   643,   645,   649,   654,
     655,   656,   657,   658,   659,   660,   667,   675,   687,   691,
     695,   696,   701,   700,   711,   713,   722,   727,   728,   732,
     751,   771,   772,   782,   783,   793,   794,   800,   810,   811,
     817,   823,   829,   839,   840,   846,   856,   857,   871,   877,
     887,   888,   901,   914,   917,   934,   941,   942,   959,   960,
     969,   979,   983,   991,   998,  1003,  1008,  1015,  1022,  1029,
    1035,  1042,  1048,  1058,  1069,  1099,  1101,  1106,  1107,  1112,
    1113,  1117,  1118
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_class", "mc_int", "mc_float",
  "mc_double", "mc_char", "mc_boolean", "mc_string", "mc_excp", "mc_if",
  "mc_else", "mc_for", "mc_while", "mc_do", "mc_switch", "mc_case",
  "mc_default", "mc_break", "mc_return", "mc_public", "mc_static",
  "mc_void", "mc_private", "mc_protected", "mc_try", "mc_catch",
  "mc_finally", "mc_new", "mc_throws", "mc_throw", "mc_this", "mc_true",
  "mc_false", "mc_print", "chaine", "caractere", "id", "integer", "real",
  "addition", "soustraction", "multiplication", "division", "mod",
  "affectation", "sup", "inf", "incrementation", "inf_egal", "sup_egal",
  "egal", "different", "et", "ou", "pt_exclamation", "addition_assignment",
  "point", "pt_virgule", "deux_points", "virgule", "accolade_o",
  "accolade_f", "parenthese_o", "parenthese_f", "crochet_o", "crochet_f",
  "'+'", "'-'", "'*'", "'/'", "IFX", "END_OF_FILE", "$accept", "program",
  "class_decl_list", "class_decl", "$@1", "mc_public_opt", "class_body",
  "class_body_decl_list", "class_body_decl", "var_decl", "var_decl_list",
  "var_decl_suffix_opt", "var_decl_for", "for_var_decl_suffix",
  "method_decl", "$@2", "$@3", "$@4", "$@5", "constructor_decl", "$@6",
  "$@7", "throws_clause_opt", "exception_list", "visibility_static",
  "visibility_actual", "type", "type_array", "param_list_opt",
  "param_list", "param", "block", "statement_list_opt", "statement_list",
  "statement", "postfix_statement", "if_statement", "while_statement",
  "do_statement", "for_statement", "for_init_opt", "expression_opt",
  "for_update_opt", "switch_statement", "case_list_opt", "case_list",
  "case_statement", "break_opt", "default_statement_opt",
  "default_statement", "constant", "return_statement", "throw_statement",
  "try_catch_statement", "catch_list", "catch_clause", "$@8",
  "finally_opt", "expression", "assignment_expression",
  "assignment_statement", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "call_suffix", "postfix_suffix",
  "primary_expression", "argument_list_opt", "argument_list",
  "expression_list", "expression_list_opt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,    43,    45,
      42,    47,   323,   324
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    78,    77,    79,    79,    80,
      80,    81,    81,    82,    82,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    87,    87,    89,    88,    90,    88,
      91,    88,    92,    88,    94,    93,    95,    93,    96,    96,
      97,    97,    98,    98,    98,    98,    99,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   106,   106,   107,   107,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   109,   109,   109,   110,   110,   111,   112,
     113,   114,   114,   114,   115,   115,   116,   116,   117,   118,
     118,   119,   119,   120,   121,   121,   122,   122,   123,   124,
     124,   124,   124,   124,   124,   124,   125,   125,   126,   127,
     128,   128,   130,   129,   131,   131,   132,   133,   133,   134,
     134,   135,   135,   136,   136,   137,   137,   137,   138,   138,
     138,   138,   138,   139,   139,   139,   140,   140,   140,   140,
     141,   141,   141,   141,   141,   142,   142,   142,   143,   143,
     144,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   146,   146,   147,   147,   148,
     148,   149,   149
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     0,     7,     0,     1,     0,
       1,     1,     2,     1,     1,     1,     1,     3,     3,     2,
       3,     0,     2,     3,     2,     0,     0,     9,     0,     9,
       0,     8,     0,     8,     0,     7,     0,     6,     0,     2,
       1,     3,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     5,     0,
       1,     1,     3,     2,     2,     3,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     2,     2,     4,     2,     2,     5,     7,     5,     7,
       8,     1,     2,     2,     0,     1,     0,     1,     8,     0,
       1,     1,     2,     5,     0,     2,     0,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     4,
       1,     2,     0,     7,     0,     2,     1,     1,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     2,     2,     2,     2,     2,     0,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       5,     3,     3,     5,     8,     0,     1,     1,     3,     1,
       3,     0,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     8,     0,     7,     3,     0,     1,     2,     4,     0,
       0,     5,     9,    49,    50,    51,    52,    53,    54,    55,
      46,    43,     0,    47,    48,    56,    66,     0,    10,    11,
      13,    14,    15,     0,    42,     0,     0,    16,    45,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,   164,   165,     0,   167,   166,   161,   162,   163,    66,
     181,    71,     0,    70,     0,    67,    68,     0,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,   158,     6,
      12,     0,    34,     0,    44,    21,     0,     0,    21,     0,
       0,    59,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,   116,     0,     0,   126,   131,   133,   135,   138,
     143,   146,   150,   158,     0,    55,    56,     0,     0,    94,
     179,   150,     0,   182,     0,    65,    69,    82,    81,     0,
     157,     0,     0,   156,   175,   155,    26,     0,    28,     0,
      19,     0,    57,    17,     0,    18,    59,    56,     0,     0,
       0,    60,    61,     0,    91,     0,     0,    94,     0,     0,
       0,     0,   153,   152,   154,   151,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   156,   175,     0,   124,   120,   175,   175,     0,   118,
       0,    95,     0,   172,   171,   129,   128,   127,   150,   130,
     158,   177,     0,   176,     0,    59,     0,    22,    59,     0,
      20,     0,    63,    64,     0,     0,     0,    93,    25,     0,
      92,     0,     0,     0,   132,   134,   136,   137,   140,   139,
     141,   142,   144,   145,   147,   148,   149,     0,     0,     0,
     121,   119,     0,     0,     0,     0,   180,   160,   159,     0,
      59,     0,    59,     0,    58,    38,    37,    62,    86,     0,
      23,    96,    88,     0,    99,   159,     0,   125,   170,   169,
     173,    80,   178,     0,     0,     0,    38,     0,     0,     0,
      24,     0,    97,     0,     0,   106,   100,   101,     0,     0,
      38,    35,    38,     0,    39,    40,    31,    87,     0,    89,
     111,   112,   114,   115,   113,   109,   110,     0,     0,     0,
     107,   102,   122,     0,     0,     0,    33,     0,    90,    66,
      66,    98,     0,   174,    27,    29,    41,   104,   108,   123,
       0,   103,   105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    12,     5,    27,    28,    29,    61,
      87,   140,   155,   260,    31,   204,   206,    90,   141,    32,
     137,    40,   278,   294,    33,    34,    62,    36,   150,   151,
     152,    63,    64,    65,    66,    67,    68,    69,    70,    71,
     157,   190,   281,    72,   285,   286,   287,   331,   309,   310,
     307,    73,    74,    75,   184,   185,   322,   241,   201,   195,
      76,   105,   106,   107,   108,   109,   110,   111,   112,   135,
     133,   113,   202,   203,   122,   124
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -265
static const yytype_int16 yypact[] =
{
      12,  -265,    41,   -11,  -265,    45,  -265,  -265,  -265,    39,
      37,  -265,    64,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,    89,    67,  -265,  -265,    48,   368,    55,    64,  -265,
    -265,  -265,  -265,   412,   103,   -30,    90,  -265,  -265,  -265,
      73,    76,    95,    96,   368,    97,   109,    82,   419,   174,
    -265,  -265,  -265,    99,  -265,  -265,   -27,  -265,  -265,   307,
     174,  -265,   -24,  -265,    91,   368,  -265,   107,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,   108,    -2,   105,  -265,
    -265,   132,   134,   136,  -265,   -39,   110,     2,   129,    17,
     112,   466,   174,   405,   174,   165,   174,  -265,   174,   174,
     174,   174,  -265,   174,   121,   126,   128,   -32,    50,    49,
     -13,  -265,   -34,   120,   158,   122,   123,   124,   130,   174,
    -265,    -2,    21,   139,   144,  -265,  -265,  -265,  -265,   174,
     138,   174,   155,   142,   174,  -265,  -265,   140,  -265,   174,
    -265,   153,   152,  -265,   181,  -265,   466,  -265,   -21,   182,
     156,   163,  -265,   160,  -265,   167,   191,   174,   172,   168,
     170,   178,  -265,  -265,  -265,  -265,  -265,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
    -265,  -265,   174,   171,    80,  -265,   174,   174,   174,  -265,
     179,  -265,   174,  -265,  -265,  -265,  -265,   126,     8,  -265,
     120,  -265,   180,   176,   175,   466,   183,  -265,   466,   184,
    -265,   185,  -265,  -265,    82,   466,   368,  -265,   186,   187,
    -265,   368,   174,   190,   128,   -32,    50,    50,    49,    49,
      49,    49,   -13,   -13,  -265,  -265,  -265,   188,   466,    82,
    -265,  -265,   193,   198,   189,   196,  -265,  -265,   205,   174,
     466,   200,   466,   203,  -265,   218,  -265,  -265,   257,   174,
    -265,   174,  -265,   206,   253,  -265,   234,  -265,  -265,  -265,
     208,  -265,  -265,   210,    82,   212,   218,   466,    82,   368,
    -265,   213,  -265,   228,   246,   270,   253,  -265,   225,   174,
     218,  -265,   218,    82,   230,  -265,  -265,  -265,   368,  -265,
    -265,  -265,  -265,  -265,  -265,  -265,  -265,   232,   233,   236,
    -265,  -265,  -265,   229,    82,    82,  -265,   466,  -265,   368,
     368,  -265,    82,  -265,  -265,  -265,  -265,   281,  -265,  -265,
     242,  -265,  -265
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -265,  -265,  -265,   301,  -265,  -265,  -265,  -265,   277,     1,
     272,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,  -265,
    -265,  -265,  -264,  -265,  -265,   285,   -10,   -88,  -141,  -265,
      94,   -12,  -204,  -265,   -38,  -265,  -265,  -265,  -265,  -265,
    -265,   162,  -265,  -265,  -265,  -265,    38,  -265,  -265,  -265,
    -265,  -265,  -265,  -265,  -265,   141,  -265,  -265,     0,   195,
       3,     4,   161,   164,   -17,   -50,   -20,   -48,   -25,   131,
    -103,   -22,  -107,  -265,   269,  -265
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -86
static const yytype_int16 yytable[] =
{
      37,    77,    35,   149,    78,   211,    95,   139,    85,   181,
       1,   -56,   293,    30,    88,   180,    37,   212,    35,    77,
     169,   170,    78,    83,   132,   -32,   314,   126,   315,    30,
     177,   178,   179,     1,   121,   114,    86,    78,   117,   -56,
      77,     6,    86,    78,   129,    86,   104,   130,     9,   118,
     162,   163,   164,   165,   129,   131,   132,   180,   149,   120,
     120,   143,     7,   144,   251,   131,   132,   253,    13,    14,
      15,    16,    17,    18,    19,   237,   145,    10,   144,   242,
     243,   148,   192,   156,   193,    20,    21,    22,    23,    24,
     175,   176,   153,   158,   159,   181,   161,   171,   172,    11,
     173,   174,    25,   120,   198,    39,   198,   183,   239,   273,
      20,   275,   -36,    23,    24,   327,   328,   149,    79,   191,
     149,   228,   229,   230,   231,    84,    26,   149,    88,   234,
     235,   236,   196,   197,   196,   197,   148,    91,    48,   207,
      92,    50,    51,    52,    26,    54,    55,    97,    57,    58,
      98,    99,   226,   227,   125,   232,   233,   191,   100,    93,
      94,    96,   149,   119,   149,   101,   127,   128,   102,   134,
     136,   103,   -56,    60,   138,   139,   146,   142,   258,   160,
     166,   167,   168,   262,   182,   183,   186,   187,   244,   189,
     188,    77,   246,   200,    78,   148,    77,   -85,   148,    78,
     192,   -84,   256,    48,   205,   148,    50,    51,    52,   194,
      54,    55,    97,    57,    58,    98,    99,   208,   209,   210,
     213,   214,   263,   100,   215,   216,   217,   267,   266,   218,
     101,   220,   259,   221,   222,   238,   103,   249,    60,   250,
     148,   297,   148,   223,   245,   248,   261,   252,   277,   272,
     255,   254,   264,   265,    77,   271,   270,    78,   268,   280,
     318,   282,   291,   269,   -83,   274,   296,   295,   276,   279,
     284,   283,   288,    77,   289,   290,    78,   292,   298,   300,
     301,   316,   302,   303,   304,   305,   306,   299,   308,   313,
     312,   317,   319,   320,    77,    77,   323,    78,    78,   321,
     330,   332,   324,   325,     8,    80,    38,   326,    89,   257,
     329,    13,    14,    15,    16,    17,    18,    19,    41,   219,
      42,    43,    44,    45,   311,   240,   199,    46,   224,   123,
       0,   247,   225,    47,     0,     0,    48,     0,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    98,    99,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,   101,     0,     0,     0,     0,     0,    59,
       0,    60,    13,    14,    15,    16,    17,    18,    19,    41,
       0,    42,    43,    44,    45,     0,     0,     0,    46,     0,
       0,     0,     0,     0,    47,     0,     0,    48,     0,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    13,
      14,    15,    16,    17,    18,    19,    13,    14,    15,    16,
      17,    18,    19,    13,    14,    15,    16,    17,    18,   115,
      59,     0,    60,     0,    48,    81,     0,    50,    51,    52,
       0,    54,    55,    56,    57,    58,    98,    99,     0,     0,
      82,     0,     0,     0,   100,     0,     0,   116,     0,     0,
       0,   101,     0,     0,   154,     0,     0,   103,     0,    60,
      13,    14,    15,    16,    17,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   147
};

static const yytype_int16 yycheck[] =
{
      12,    26,    12,    91,    26,   146,    44,    46,    38,   112,
      21,    38,   276,    12,    38,    49,    28,    38,    28,    44,
      52,    53,    44,    33,    58,    64,   290,    65,   292,    28,
      43,    44,    45,    21,    59,    47,    66,    59,    48,    66,
      65,     0,    66,    65,    46,    66,    46,    49,     3,    49,
      98,    99,   100,   101,    46,    57,    58,    49,   146,    59,
      60,    59,    73,    61,   205,    57,    58,   208,     4,     5,
       6,     7,     8,     9,    10,   182,    59,    38,    61,   186,
     187,    91,    61,    93,    63,    21,    22,    23,    24,    25,
      41,    42,    92,    93,    94,   198,    96,    47,    48,    62,
      50,    51,    38,   103,   129,    38,   131,    27,    28,   250,
      21,   252,    64,    24,    25,   319,   320,   205,    63,   119,
     208,   171,   172,   173,   174,    22,    62,   215,    38,   177,
     178,   179,   129,   129,   131,   131,   146,    64,    29,   139,
      64,    32,    33,    34,    62,    36,    37,    38,    39,    40,
      41,    42,   169,   170,    63,   175,   176,   157,    49,    64,
      64,    64,   250,    64,   252,    56,    59,    59,    59,    64,
      38,    62,    38,    64,    38,    46,    64,    67,   216,    14,
      59,    55,    54,   221,    64,    27,    64,    64,   188,    59,
      66,   216,   192,    38,   216,   205,   221,    59,   208,   221,
      61,    59,   214,    29,    64,   215,    32,    33,    34,    65,
      36,    37,    38,    39,    40,    41,    42,    64,    66,    38,
      38,    65,   222,    49,    61,    65,    59,   239,   238,    38,
      56,    59,    46,    65,    64,    64,    62,    61,    64,    64,
     250,   279,   252,    65,    65,    65,    59,    64,    30,   249,
      65,    67,    62,    65,   279,    59,    67,   279,    65,   259,
     298,   261,   274,    65,    59,    65,   278,   277,    65,    12,
      17,    65,    38,   298,    66,    65,   298,    65,    65,    33,
      34,   293,    36,    37,    38,    39,    40,    59,    18,   289,
      65,    61,    60,    60,   319,   320,    67,   319,   320,    63,
      19,    59,   314,   315,     3,    28,    21,   317,    36,   215,
     322,     4,     5,     6,     7,     8,     9,    10,    11,   157,
      13,    14,    15,    16,   286,   184,   131,    20,   167,    60,
      -1,   200,   168,    26,    -1,    -1,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    64,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    13,    14,    15,    16,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     4,
       5,     6,     7,     8,     9,    10,     4,     5,     6,     7,
       8,     9,    10,     4,     5,     6,     7,     8,     9,    10,
      62,    -1,    64,    -1,    29,    23,    -1,    32,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      38,    -1,    -1,    -1,    49,    -1,    -1,    38,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    62,    -1,    64,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    21,    75,    76,    77,    79,     0,    73,    77,     3,
      38,    62,    78,     4,     5,     6,     7,     8,     9,    10,
      21,    22,    23,    24,    25,    38,    62,    80,    81,    82,
      83,    88,    93,    98,    99,   100,   101,   105,    99,    38,
      95,    11,    13,    14,    15,    16,    20,    26,    29,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    62,
      64,    83,   100,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   117,   125,   126,   127,   134,   142,   145,    63,
      82,    23,    38,   100,    22,    38,    66,    84,    38,    84,
      91,    64,    64,    64,    64,   108,    64,    38,    41,    42,
      49,    56,    59,    62,   132,   135,   136,   137,   138,   139,
     140,   141,   142,   145,   105,    10,    38,   100,   132,    64,
     132,   142,   148,   148,   149,    63,   108,    59,    59,    46,
      49,    57,    58,   144,    64,   143,    38,    94,    38,    46,
      85,    92,    67,    59,    61,    59,    64,    38,   100,   101,
     102,   103,   104,   132,    59,    86,   100,   114,   132,   132,
      14,   132,   141,   141,   141,   141,    59,    55,    54,    52,
      53,    47,    48,    50,    51,    41,    42,    43,    44,    45,
      49,   144,    64,    27,   128,   129,    64,    64,    66,    59,
     115,   132,    61,    63,    65,   133,   134,   135,   142,   133,
      38,   132,   146,   147,    89,    64,    90,   132,    64,    66,
      38,   102,    38,    38,    65,    61,    65,    59,    38,   115,
      59,    65,    64,    65,   136,   137,   138,   138,   139,   139,
     139,   139,   140,   140,   141,   141,   141,   146,    64,    28,
     129,   131,   146,   146,   132,    65,   132,   143,    65,    61,
      64,   102,    64,   102,    67,    65,   105,   104,   108,    46,
      87,    59,   108,   132,    62,    65,   100,   105,    65,    65,
      67,    59,   132,   102,    65,   102,    65,    30,    96,    12,
     132,   116,   132,    65,    17,   118,   119,   120,    38,    66,
      65,   105,    65,    96,    97,   100,   105,   108,    65,    59,
      33,    34,    36,    37,    38,    39,    40,   124,    18,   122,
     123,   120,    65,   132,    96,    96,   105,    61,   108,    60,
      60,    63,   130,    67,   105,   105,   100,   106,   106,   105,
      19,   121,    59
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 102 "syntax.y"
    { printf("programme syntaxiquement correcte.\n");
        generate_assembly_code(create_symbol_table()); // Generate assembly
         YYACCEPT; ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 121 "syntax.y"
    { 
        // Pousser la portée de la classe identifiée par 'id'
        push_scope((yyvsp[(3) - (4)].str));
        // Insérer ce symbole dans la TS (code "CLASS") s'il n'existe pas déjà
        if(check_declaration((yyvsp[(3) - (4)].str)) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: redéclaration de la classe %s\n", nb_ligne, (yyvsp[(3) - (4)].str));
            // exit(1);
        }
        insert_idf_cst((yyvsp[(3) - (4)].str), "CLASS", "", " ", current_scope(), 1);
    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 133 "syntax.y"
    { 
        pop_scope();
        printf("Déclaration de classe terminée\n"); 
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 176 "syntax.y"
    {
        if (check_declaration((yyvsp[(1) - (2)].str)) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Variable %s deja declaree dans la portee %s\n",nb_ligne, (yyvsp[(1) - (2)].str), current_scope());
        }
        if ((yyvsp[(2) - (2)].attr).value != NULL) {
            if (strcmp(current_type, (yyvsp[(2) - (2)].attr).type) != 0) {
                fprintf(stderr,"Erreur semantique ligne %d: Le type de l'expression (%s) ne correspond pas au type declare de la variable (%s).\n",nb_ligne, (yyvsp[(2) - (2)].attr).type, current_type);
            }
            insert_idf_cst((yyvsp[(1) - (2)].str), "VAR", current_type, strdup((yyvsp[(2) - (2)].attr).value), current_scope(), 1);
            add_quad("=", (yyvsp[(2) - (2)].attr).value, "", (yyvsp[(1) - (2)].str)); // Ajouter le quadruplet pour l'affectation
            printf("Debug: var_decl_list: Generated quad (=, %s, , %s)\n", (yyvsp[(2) - (2)].attr).value, (yyvsp[(1) - (2)].str)); // Débogage
        } else {
            insert_idf_cst((yyvsp[(1) - (2)].str), "VAR", current_type, " ", current_scope(), 1);
        }
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 192 "syntax.y"
    {
        if (check_declaration((yyvsp[(3) - (3)].str)) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Variable %s deja declaree dans la portee %s\n",nb_ligne, (yyvsp[(3) - (3)].str), current_scope());
        }
        insert_idf_cst((yyvsp[(3) - (3)].str), "VAR", current_type, " ", current_scope(), 1);
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 201 "syntax.y"
    { (yyval.attr).type = NULL; (yyval.attr).value = NULL; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 202 "syntax.y"
    { (yyval.attr) = (yyvsp[(2) - (2)].attr); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 208 "syntax.y"
    {
          if (check_declaration((yyvsp[(2) - (3)].str)) != 0) {
              fprintf(stderr, "Erreur semantique ligne %d: Variable %s deja declaree dans la portee %s\n", 
                      nb_ligne, (yyvsp[(2) - (3)].str), current_scope());
          }
          if ((yyvsp[(3) - (3)].attr).value != NULL) {
              if (strcmp(current_type, (yyvsp[(3) - (3)].attr).type) != 0) {
                  fprintf(stderr, "Erreur semantique ligne %d: Le type de l'expression (%s) ne correspond pas au type declare de la variable (%s).\n", 
                          nb_ligne, (yyvsp[(3) - (3)].attr).type, current_type);
              }
              insert_idf_cst((yyvsp[(2) - (3)].str), "VAR", current_type, strdup((yyvsp[(3) - (3)].attr).value), current_scope(), 1);
              add_quad("=", (yyvsp[(3) - (3)].attr).value, "", (yyvsp[(2) - (3)].str)); // Affectation pour l'initialisation
              printf("Debug: var_decl_for: Generated quad (=, %s, , %s)\n", (yyvsp[(3) - (3)].attr).value, (yyvsp[(2) - (3)].str));
          } else {
              insert_idf_cst((yyvsp[(2) - (3)].str), "VAR", current_type, " ", current_scope(), 1);
          }
      ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 229 "syntax.y"
    {
          (yyval.attr) = (yyvsp[(2) - (2)].attr);
      ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 233 "syntax.y"
    {
          (yyval.attr).type = NULL;
          (yyval.attr).value = NULL;
      ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 243 "syntax.y"
    { 
        // Vérifier si la méthode est déjà déclarée dans la portée actuelle
        if(check_declaration((yyvsp[(3) - (3)].str)) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Methode %s deja declaree dans la portee %s\n",nb_ligne, (yyvsp[(3) - (3)].str), current_scope());
            // exit(1);
        }

        current_method_return_type =strdup( "void");
        // Insérer la méthode dans la TS
        insert_idf_cst((yyvsp[(3) - (3)].str), "METHOD", "void", " ", current_scope(), 1);

        // On crée un nouveau scope pour les paramètres et variables locales.
        sprintf(scopeName, "%s_method", (yyvsp[(3) - (3)].str)); 
        push_scope(scopeName);
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 259 "syntax.y"
    { 
        pop_scope(); 
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 263 "syntax.y"
    { 
        if(check_declaration((yyvsp[(3) - (3)].str)) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Methode %s deja declaree dans la portee %s\n",nb_ligne, (yyvsp[(3) - (3)].str), current_scope());
            // exit(1);
        }
 
        current_method_return_type = strdup((yyvsp[(2) - (3)].res));
        insert_idf_cst((yyvsp[(3) - (3)].str), "METHOD", (yyvsp[(2) - (3)].res), " ", current_scope(), 1);

        sprintf(scopeName, "%s_method", (yyvsp[(3) - (3)].str)); 
        push_scope(scopeName);
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 276 "syntax.y"
    { 
        pop_scope(); 
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 280 "syntax.y"
    { 
        if(check_declaration((yyvsp[(2) - (2)].str)) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Methode %s deja declaree dans la portee %s\n",nb_ligne, (yyvsp[(2) - (2)].str), current_scope());
            // exit(1);
        }

        current_method_return_type = strdup("void");;
        insert_idf_cst((yyvsp[(2) - (2)].str), "METHOD", "void", " ", current_scope(), 1);

        sprintf(scopeName, "%s_method", (yyvsp[(2) - (2)].str));
        push_scope(scopeName);
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 293 "syntax.y"
    { 
        pop_scope();
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 297 "syntax.y"
    { 
        if(check_declaration((yyvsp[(2) - (2)].str)) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Methode %s deja declaree dans la portee %s\n",nb_ligne,  (yyvsp[(2) - (2)].str), current_scope());
            // exit(1);
        }

        current_method_return_type = strdup((yyvsp[(1) - (2)].res));
        insert_idf_cst((yyvsp[(2) - (2)].str), "METHOD", (yyvsp[(1) - (2)].res), " ", current_scope(), 1);

        sprintf(scopeName, "%s_method", (yyvsp[(2) - (2)].str));
        push_scope(scopeName);
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 310 "syntax.y"
    { 
        pop_scope(); 
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 318 "syntax.y"
    { 
        if(check_declaration((yyvsp[(2) - (2)].str)) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Methode %s deja declaree dans la portee %s\n",nb_ligne,  (yyvsp[(2) - (2)].str), current_scope());
            // exit(1);
        }

        insert_idf_cst((yyvsp[(2) - (2)].str), "CONSTR", "", " ", current_scope(), 1);

        sprintf(scopeName, "%s_method", (yyvsp[(2) - (2)].str));
        push_scope(scopeName);
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 330 "syntax.y"
    { 
        pop_scope(); 
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 334 "syntax.y"
    { 
        if(check_declaration((yyvsp[(1) - (1)].str)) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Methode %s deja declaree dans la portee %s\n",nb_ligne,  (yyvsp[(1) - (1)].str), current_scope());
            // exit(1);
        }

        insert_idf_cst((yyvsp[(1) - (1)].str), "CONSTR", "", " ", current_scope(), 1);

        sprintf(scopeName, "%s_method", (yyvsp[(1) - (1)].str));
        push_scope(scopeName);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 345 "syntax.y"
    { 
        pop_scope(); 
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 364 "syntax.y"
    { /* uniquement visibilité */ ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 365 "syntax.y"
    { /* uniquement static */ ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 366 "syntax.y"
    { /* visibilité suivie de static */ ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 367 "syntax.y"
    { /* static suivi de visibilité */ ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 379 "syntax.y"
    { current_type=strdup((yyvsp[(1) - (1)].str)); (yyval.res)=current_type;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 380 "syntax.y"
    { current_type=strdup((yyvsp[(1) - (1)].str)); (yyval.res)=current_type;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 381 "syntax.y"
    { current_type=strdup((yyvsp[(1) - (1)].str)); (yyval.res)=current_type;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 382 "syntax.y"
    { current_type=strdup((yyvsp[(1) - (1)].str)); (yyval.res)=current_type;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 383 "syntax.y"
    { current_type=strdup((yyvsp[(1) - (1)].str)); (yyval.res)=current_type;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 384 "syntax.y"
    { current_type=strdup((yyvsp[(1) - (1)].str)); (yyval.res)=current_type;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 385 "syntax.y"
    { current_type=strdup((yyvsp[(1) - (1)].str)); (yyval.res)=current_type;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 386 "syntax.y"
    { current_type=strdup((yyvsp[(1) - (1)].str)); (yyval.res)=current_type;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 392 "syntax.y"
    {
        char* base = (yyvsp[(1) - (3)].res);
        char* full_type = malloc(strlen(base) + 3); // +3 pour "[]" et '\0'
        sprintf(full_type, "%s[]", base);
        current_type = full_type; (yyval.res)=current_type;
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 399 "syntax.y"
    {
        char* base = (yyvsp[(1) - (5)].res);
        char* full_type = malloc(strlen(base) + 5); // +6 pour "[][]" et '\0'
        sprintf(full_type, "%s[][]", base);
        current_type = full_type; (yyval.res)=current_type;
    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 422 "syntax.y"
    {   if (check_declaration((yyvsp[(2) - (2)].str)) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Variable %s deja declaree dans la portee %s\n",nb_ligne, (yyvsp[(2) - (2)].str), current_scope());
            // exit(1);
        }

        insert_idf_cst((yyvsp[(2) - (2)].str), "VAR", current_type," ", current_scope(), 1);

    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 431 "syntax.y"
    {   if (check_declaration((yyvsp[(2) - (2)].str)) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Variable %s deja declaree dans la portee %s\n",nb_ligne, (yyvsp[(2) - (2)].str), current_scope());
            // exit(1);
        }

        insert_idf_cst((yyvsp[(2) - (2)].str), "VAR", current_type," ", current_scope(), 1);
       
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 494 "syntax.y"
    {
          printf("Debug: if_statement: condition value=%s, quad_index=%d\n", (yyvsp[(3) - (5)].attr).value ? (yyvsp[(3) - (5)].attr).value : "NULL", quad_index);
          const char* label_end = new_label();
          add_quad("IF_FALSE", (yyvsp[(3) - (5)].attr).value, "", label_end);
          // Les quadruplets de $5 (statement) sont déjà générés
          add_quad("LABEL", "", "", label_end);
      ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 502 "syntax.y"
    {
          printf("Debug: if_else_statement: condition value=%s, quad_index=%d\n", (yyvsp[(3) - (7)].attr).value ? (yyvsp[(3) - (7)].attr).value : "NULL", quad_index);
          const char* label_else = new_label();
          const char* label_end = new_label();
          add_quad("IF_FALSE", (yyvsp[(3) - (7)].attr).value, "", label_else);
          // Quadruplets de $5 (statement du if)
          add_quad("GOTO", "", "", label_end);
          add_quad("LABEL", "", "", label_else);
          // Quadruplets de $7 (statement du else)
          add_quad("LABEL", "", "", label_end);
      ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 518 "syntax.y"
    {


        const char* label_start = new_label();
        const char* label_end = new_label();

        // 1. Étiquette de début de la boucle
        add_quad("LABEL", "", "", label_start);

        // 2. Calculer la condition
        if ((yyvsp[(3) - (5)].attr).value != NULL) {
            // Générer un nouveau quadruplet pour la condition (par exemple, i < 5)
            int t = new_temp();
            const char* temp_name = get_temp_name(t);
            // Supposons que $3.value contient le résultat de l'expression (par exemple, T0 pour i < 5)
            // Nous devons régénérer la condition en utilisant les informations de l'expression
            add_quad("<", (yyvsp[(3) - (5)].attr).value, "5", temp_name); // Exemple : T0 = i < 5
            add_quad("IF_FALSE", temp_name, "", label_end);
        }

        // 3. Corps de la boucle (les quadruplets de statement sont déjà générés)

        // 4. Saut au début de la boucle
        add_quad("GOTO", "", "", label_start);

        // 5. Étiquette de fin
        add_quad("LABEL", "", "", label_end);
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 556 "syntax.y"
    {
          printf("Debug: for_statement: condition=%s, quad_index=%d\n", 
                 (yyvsp[(4) - (8)].attr).value ? (yyvsp[(4) - (8)].attr).value : "NULL", quad_index);
          
          const char* label_start = new_label();
          const char* label_end = new_label();

          // Label de début
          add_quad("LABEL", "", "", label_start);
          
          // Condition (si non vide)
          if ((yyvsp[(4) - (8)].attr).value != NULL) {
              add_quad("IF_FALSE", (yyvsp[(4) - (8)].attr).value, "", label_end);
          }
          
          // Corps (les quadruplets du statement sont déjà générés)
          
          // Incrémentation (les quadruplets de for_update_opt sont déjà générés)
          
          // Retour au début
          add_quad("GOTO", "", "", label_start);
          
          // Label de fin
          add_quad("LABEL", "", "", label_end);
      ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 593 "syntax.y"
    {
          (yyval.attr).type = NULL;
          (yyval.attr).value = NULL;
      ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 598 "syntax.y"
    {
          (yyval.attr) = (yyvsp[(1) - (1)].attr);
      ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 606 "syntax.y"
    {
          // Pas d'incrémentation
      ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 610 "syntax.y"
    {
          // Les quadruplets pour l'expression (ex: i++) sont déjà générés
      ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 668 "syntax.y"
    {
          // Dans le cas d'une méthode void, aucun retour n'est attendu.
          if (strcmp(current_method_return_type, "void") != 0) {
              fprintf(stderr,"Erreur semantique ligne %d: La methode doit retourner une valeur.",nb_ligne);
            //   exit(1);
          }
      ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 676 "syntax.y"
    {
          // Comparer le type de l'expression ($2) avec le type de retour attendu de la méthode.
          if(strcmp((yyvsp[(2) - (3)].attr).type, current_method_return_type) != 0) {
              fprintf(stderr,"Erreur semantique ligne %d: Le type de retour %s ne correspond pas a la signature de la methode %s\n",nb_ligne,(yyvsp[(2) - (3)].attr).type,current_method_return_type);
            //   exit(1);
          }
          (yyval.attr) = (yyvsp[(2) - (3)].attr);
      ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 701 "syntax.y"
    {
        if(!verifClasseType((yyvsp[(3) - (5)].res))) {
            fprintf(stderr, "Erreur symantique ligne %d: %s n'est pas un type d'exception\n", nb_ligne, (yyvsp[(3) - (5)].res));
            // exit(1);
        }
        insert_idf_cst((yyvsp[(4) - (5)].str), "VAR", (yyvsp[(3) - (5)].res), " ", current_scope(), 1);
    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 722 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 727 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 728 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 733 "syntax.y"
    {
        // Vérifier si la variable à gauche est déclarée
        if ((yyvsp[(1) - (3)].attr).value != NULL && search_idf_cst((yyvsp[(1) - (3)].attr).value) == NULL) {
            fprintf(stderr, "Erreur semantique ligne %d: Variable non declaree\n", nb_ligne, (yyvsp[(1) - (3)].attr).value);
            // exit(1); // Commenter pour permettre la détection d'autres erreurs
        }else{
        // Vérifier la compatibilité des types (facultatif, si vous voulez renforcer la vérification)
        if ((yyvsp[(1) - (3)].attr).type != NULL && (yyvsp[(3) - (3)].attr).type != NULL && strcmp((yyvsp[(1) - (3)].attr).type, (yyvsp[(3) - (3)].attr).type) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Incompatibilite de type. Type attendu : %s, Type recu : %s\n",nb_ligne, (yyvsp[(1) - (3)].attr).type, (yyvsp[(3) - (3)].attr).type);
            // exit(1);
        }
        }
        // Générer le quadruplet d'affectation
        add_quad("=", (yyvsp[(3) - (3)].attr).value, "", (yyvsp[(1) - (3)].attr).value);
        // Propager les attributs
        (yyval.attr).type = (yyvsp[(3) - (3)].attr).type ? strdup((yyvsp[(3) - (3)].attr).type) : NULL;
        (yyval.attr).value = (yyvsp[(3) - (3)].attr).value ? strdup((yyvsp[(3) - (3)].attr).value) : NULL;
    ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 752 "syntax.y"
    {
        // Vérifier si la variable à gauche est déclarée
        if ((yyvsp[(1) - (3)].attr).value != NULL && search_idf_cst((yyvsp[(1) - (3)].attr).value) == NULL) {
            fprintf(stderr, "Erreur sémantique ligne %d: Variable '%s' non déclarée\n", nb_ligne, (yyvsp[(1) - (3)].attr).value);
            // exit(1);
        }
        // Vérifier la compatibilité des types (facultatif)
        if ((yyvsp[(1) - (3)].attr).type != NULL && (yyvsp[(3) - (3)].attr).type != NULL && strcmp((yyvsp[(1) - (3)].attr).type, (yyvsp[(3) - (3)].attr).type) != 0) {
            fprintf(stderr, "Erreur sémantique ligne %d: Incompatibilité de type. Type attendu : %s, Type reçu : %s\n", nb_ligne, (yyvsp[(1) - (3)].attr).type, (yyvsp[(3) - (3)].attr).type);
            // exit(1);
        }
        // Propager les attributs
        (yyval.attr).type = (yyvsp[(3) - (3)].attr).type ? strdup((yyvsp[(3) - (3)].attr).type) : NULL;
        (yyval.attr).value = (yyvsp[(3) - (3)].attr).value ? strdup((yyvsp[(3) - (3)].attr).value) : NULL;
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 771 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 772 "syntax.y"
    {
        int t = new_temp();
        add_quad("||", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
        (yyval.attr).type = strdup("boolean");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 782 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 783 "syntax.y"
    {
        int t = new_temp();
        add_quad("&&", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
        (yyval.attr).type = strdup("boolean");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 793 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 794 "syntax.y"
    {
        int t = new_temp();
        add_quad("==", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
        (yyval.attr).type = strdup("boolean");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 800 "syntax.y"
    {
        int t = new_temp();
        add_quad("!=", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
        (yyval.attr).type = strdup("boolean");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 810 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 811 "syntax.y"
    {
        int t = new_temp();
        add_quad("<", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
        (yyval.attr).type = strdup("boolean");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 817 "syntax.y"
    {
        int t = new_temp();
        add_quad(">", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
        (yyval.attr).type = strdup("boolean");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 823 "syntax.y"
    {
        int t = new_temp();
        add_quad("<=", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
        (yyval.attr).type = strdup("boolean");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 829 "syntax.y"
    {
        int t = new_temp();
        add_quad(">=", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
        (yyval.attr).type = strdup("boolean");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 839 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 840 "syntax.y"
    {
        int t = new_temp();
        add_quad("+", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
        (yyval.attr).type = ((strcmp((yyvsp[(1) - (3)].attr).type, "float") == 0) || (strcmp((yyvsp[(3) - (3)].attr).type, "float") == 0)) ? strdup("float") : strdup("int");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 846 "syntax.y"
    {
        int t = new_temp();
        add_quad("-", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
        (yyval.attr).type = ((strcmp((yyvsp[(1) - (3)].attr).type, "float") == 0) || (strcmp((yyvsp[(3) - (3)].attr).type, "float") == 0)) ? strdup("float") : strdup("int");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 856 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 857 "syntax.y"
    {
        if ((yyvsp[(1) - (3)].attr).value == NULL || (yyvsp[(3) - (3)].attr).value == NULL) {
            fprintf(stderr, "Erreur semantique ligne %d: Operande invalide pour la multiplication\n", nb_ligne);
            (yyval.attr).type = strdup("int"); // Valeur par défaut
            (yyval.attr).value = NULL;
        } else {
            printf("Debug: multiplicative_expression: $1.value=%s, $3.value=%s\n", 
                   (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value);
            int t = new_temp();
            add_quad("*", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
            (yyval.attr).type = ((strcmp((yyvsp[(1) - (3)].attr).type, "float") == 0) || (strcmp((yyvsp[(3) - (3)].attr).type, "float") == 0)) ? strdup("float") : strdup("int");
            (yyval.attr).value = strdup(get_temp_name(t));
        }
    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 871 "syntax.y"
    {
        int t = new_temp();
        add_quad("/", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
        (yyval.attr).type = ((strcmp((yyvsp[(1) - (3)].attr).type, "float") == 0) || (strcmp((yyvsp[(3) - (3)].attr).type, "float") == 0)) ? strdup("float") : strdup("int");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 877 "syntax.y"
    {
        int t = new_temp();
        add_quad("%", (yyvsp[(1) - (3)].attr).value, (yyvsp[(3) - (3)].attr).value, get_temp_name(t));
        (yyval.attr).type = strdup("int");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 887 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 888 "syntax.y"
    {
          if ((yyvsp[(2) - (2)].attr).value == NULL) {
              fprintf(stderr, "Erreur semantique ligne %d: Operande invalide pour !\n", nb_ligne);
              (yyval.attr).type = strdup("boolean");
              (yyval.attr).value = NULL;
          } else {
              int t = new_temp();
              add_quad("!", (yyvsp[(2) - (2)].attr).value, "", get_temp_name(t));
              (yyval.attr).type = strdup("boolean");
              (yyval.attr).value = strdup(get_temp_name(t));
              printf("Debug: unary_expression (!): input=%s, output=%s\n", (yyvsp[(2) - (2)].attr).value, (yyval.attr).value);
          }
      ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 902 "syntax.y"
    {
          (yyval.attr).type = strdup((yyvsp[(2) - (2)].attr).type);
          char buffer[32];
          if (strcmp((yyvsp[(2) - (2)].attr).type, "int") == 0) {
              sprintf(buffer, "%d", -atoi((yyvsp[(2) - (2)].attr).value));
          } else if (strcmp((yyvsp[(2) - (2)].attr).type, "float") == 0) {
              sprintf(buffer, "%f", -atof((yyvsp[(2) - (2)].attr).value));
          } else {
              fprintf(stderr, "Erreur semantique ligne %d: operateur unaire '-' sur type '%s'\n", nb_ligne, (yyvsp[(2) - (2)].attr).type);
          }
          (yyval.attr).value = strdup(buffer);
      ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 914 "syntax.y"
    {
          (yyval.attr) = (yyvsp[(2) - (2)].attr);
      ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 918 "syntax.y"
    {
          if ((yyvsp[(2) - (2)].attr).type != NULL && strcmp((yyvsp[(2) - (2)].attr).type, "int") != 0) {
              fprintf(stderr, "Erreur semantique ligne %d: Operande non entier pour ++\n", nb_ligne);
          }
          int t = new_temp();
          const char* temp_name = get_temp_name(t);
          add_quad("+", (yyvsp[(2) - (2)].attr).value, "1", temp_name);
          add_quad("=", temp_name, "", (yyvsp[(2) - (2)].attr).value);
          (yyval.attr).type = strdup("int");
          (yyval.attr).value = strdup((yyvsp[(2) - (2)].attr).value);
          printf("Debug: unary_expression (++): input=%s, output=%s\n", (yyvsp[(2) - (2)].attr).value, (yyval.attr).value);
      ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 934 "syntax.y"
    { 
        if ((yyvsp[(2) - (2)].attr).type == NULL) (yyval.attr) = (yyvsp[(1) - (2)].attr); 
        else {
            (yyval.attr).type = (yyvsp[(2) - (2)].attr).type;
            (yyval.attr).value = (yyvsp[(2) - (2)].attr).value;
        }
    ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 941 "syntax.y"
    { (yyval.attr) = (yyvsp[(2) - (2)].attr); ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 943 "syntax.y"
    {
          if ((yyvsp[(1) - (2)].attr).type != NULL && strcmp((yyvsp[(1) - (2)].attr).type, "int") != 0) {
              fprintf(stderr, "Erreur semantique ligne %d: Operande non entier pour ++\n", nb_ligne);
          }
          int t = new_temp();
          const char* temp_name = get_temp_name(t);
          add_quad("+", (yyvsp[(1) - (2)].attr).value, "1", temp_name);
          add_quad("=", temp_name, "", (yyvsp[(1) - (2)].attr).value);
          (yyval.attr).type = strdup("int");
          (yyval.attr).value = strdup((yyvsp[(1) - (2)].attr).value);
          printf("Debug: postfix_expression (++): input=%s, output=%s\n", (yyvsp[(1) - (2)].attr).value, (yyval.attr).value);
      ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 959 "syntax.y"
    { (yyval.attr).type = NULL; (yyval.attr).value = NULL; ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 960 "syntax.y"
    {
        int t = new_temp();
        add_quad("CALL", (yyvsp[(1) - (3)].str), "", get_temp_name(t));
        (yyval.attr).type = strdup("FUNC_RETURN");
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 969 "syntax.y"
    {
        char champ[100];
        sprintf(champ, "%s.%s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str)); // $<str>1 = nom de l'objet
        (yyval.attr).type = strdup("method");
        (yyval.attr).value = strdup(champ);
    ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 979 "syntax.y"
    {
        (yyval.attr).type = strdup("id");
        (yyval.attr).value = strdup((yyvsp[(1) - (1)].str));
    ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 983 "syntax.y"
    { 
        (yyval.attr).type = strdup("int");
        char buffer[32];
        sprintf(buffer, "%d", yylval.ival);
        (yyval.attr).value = strdup(buffer);
        // mettre a jour current_type
        // current_type = strdup("int");
    ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 991 "syntax.y"
    { 
        (yyval.attr).type = strdup("float");
        char buffer[32];
        sprintf(buffer, "%f", yylval.fval);
        (yyval.attr).value = strdup(buffer);
        // current_type = strdup("float");
    ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 998 "syntax.y"
    { 
        // current_type=strdup("boolean"); 
        (yyval.attr).type = strdup("boolean");
        (yyval.attr).value = strdup("true");
    ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1003 "syntax.y"
    { 
        // current_type=strdup("boolean"); 
        (yyval.attr).type = strdup("boolean");
        (yyval.attr).value = strdup("false");
    ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1008 "syntax.y"
    { 
        // current_type=strdup("char"); 
        (yyval.attr).type = strdup("char");
        // char buffer[32];
        // sprintf(buffer, "%d", yylval.str);
        (yyval.attr).value = strdup(yylval.str);
    ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1015 "syntax.y"
    { 
        // current_type=strdup("chaine"); 
        (yyval.attr).type = strdup("chaine");
        // char buffer[32];
        // sprintf(buffer, "%d", yylval.str);
        (yyval.attr).value = strdup(yylval.str);
    ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1022 "syntax.y"
    { 
        // current_type=strdup($1); 
        (yyval.attr).type = strdup((yyvsp[(1) - (1)].str));
        char buffer[32];
        sprintf(buffer, "%d", yylval.str);
        (yyval.attr).value = strdup(buffer);
    ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1029 "syntax.y"
    {
        int t = new_temp();
        add_quad("NEW", (yyvsp[(2) - (5)].str), "", get_temp_name(t));
        (yyval.attr).type = strdup((yyvsp[(2) - (5)].str));
        (yyval.attr).value = strdup(get_temp_name(t));
    ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1035 "syntax.y"
    { 
        // current_type=strdup($2); 
        (yyval.attr).type=strdup((yyvsp[(2) - (5)].str));
        char buffer[32];
        sprintf(buffer, "%d", yylval.str);
        (yyval.attr).value = strdup(buffer);
    ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1042 "syntax.y"
    { 
        (yyval.attr).type = (yyvsp[(2) - (3)].attr).type ? strdup((yyvsp[(2) - (3)].attr).type) : strdup("unknown");
        (yyval.attr).value = (yyvsp[(2) - (3)].attr).value ? strdup((yyvsp[(2) - (3)].attr).value) : NULL;
        printf("Debug: parenthese_o expression_list_opt parenthese_f: type=%s, value=%s\n", 
               (yyval.attr).type, (yyval.attr).value ? (yyval.attr).value : "NULL");
    ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1048 "syntax.y"
    { 
        // current_type=strdup("list"); 
        (yyval.attr).type=strdup("list");
        char buffer[32];
        sprintf(buffer, "%d", yylval.str);
        (yyval.attr).value = strdup(buffer);
    ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1058 "syntax.y"
    { 
        if (strcmp((yyvsp[(4) - (5)].attr).type, "int") != 0 || atoi((yyvsp[(4) - (5)].attr).value) <= 0) {
            fprintf(stderr, "Erreur semantique ligne %d: taille de tableau invalide '%s'\n", nb_ligne, (yyvsp[(4) - (5)].attr).value);
            // exit(1);
        }
        // current_type=strdup($2); 
        (yyval.attr).type=strdup((yyvsp[(2) - (5)].res));
        char buffer[32];
        sprintf(buffer, "%d", yylval.str);
        (yyval.attr).value = strdup(buffer);
     /* Instanciation d'un tableau, ex: new int[3] */ ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1069 "syntax.y"
    {
        if (strcmp((yyvsp[(4) - (8)].attr).type, "int") != 0 || atoi((yyvsp[(4) - (8)].attr).value) <= 0) {
            fprintf(stderr, "Erreur semantique ligne %d: taille de matrice (nbr de ligne) invalide '%s'\n", nb_ligne, (yyvsp[(4) - (8)].attr).value);
            // exit(1);
        } 
        if (strcmp((yyvsp[(7) - (8)].attr).type, "int") != 0 || atoi((yyvsp[(7) - (8)].attr).value) <= 0) {
            fprintf(stderr, "Erreur semantique ligne %d: taille de matrice (nbr de colonne) invalide '%s'\n", nb_ligne, (yyvsp[(7) - (8)].attr).value);
            // exit(1);
        } 
        // current_type=strdup($2); 
        (yyval.attr).type=strdup((yyvsp[(2) - (8)].res));
        char buffer[32];
        sprintf(buffer, "%d", yylval.str);
        (yyval.attr).value = strdup(buffer);
          /* Instanciation d'une matrice, ex: new int[2][1] */ ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1112 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1113 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (3)].attr); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1117 "syntax.y"
    { (yyval.attr).type = NULL; (yyval.attr).value = NULL; ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1118 "syntax.y"
    { (yyval.attr) = (yyvsp[(1) - (1)].attr); ;}
    break;



/* Line 1455 of yacc.c  */
#line 3009 "syntax.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1121 "syntax.y"


/* ======================================================================
   SECTION 7 : Code C d'accompagnement
   ====================================================================== */
/* Fonction de gestion des erreurs */
void yyerror(const char *s) {
    fprintf(stderr, "Erreur syntaxique/semantique (ligne %d, colonne %d): %s\n", nb_ligne, col, s);
}

/* Fonction principale */
int main(void) {
    //  yydebug = 1; 
    init_quads();
    yyparse();
    print();
    print_quads();
    optiQuad();
    afficherQuadAfterOpt();
    return 0;
}


