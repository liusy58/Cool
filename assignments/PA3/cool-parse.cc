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


/* Substitute the variable and function names.  */
#define yyparse         cool_yyparse
#define yylex           cool_yylex
#define yyerror         cool_yyerror
#define yydebug         cool_yydebug
#define yynerrs         cool_yynerrs

#define yylval          cool_yylval
#define yychar          cool_yychar
#define yylloc          cool_yylloc

/* Copy the first part of user declarations.  */
#line 6 "cool.y" /* yacc.c:339  */

    #include <iostream>
    #include "cool-tree.h"
    #include "stringtab.h"
    #include "utilities.h"

    extern char *curr_filename;


    /* Locations */
    #define YYLTYPE int              /* the type of locations */
    #define cool_yylloc curr_lineno  /* use the curr_lineno from the lexer
                                        for the location of tokens */

    extern int node_lineno;          /* set before constructing a tree node
                                        to whatever you want the line number
                                        for the tree node to be */


    #define YYLLOC_DEFAULT(Current, Rhs, N)         \
    Current = Rhs[1];                             \
    node_lineno = Current;


    #define SET_NODELOC(Current)  \
    node_lineno = Current;

    /* IMPORTANT NOTE ON LINE NUMBERS
    *********************************
    * The above definitions and macros cause every terminal in your grammar to
    * have the line number supplied by the lexer. The only task you have to
    * implement for line numbers to work correctly, is to use SET_NODELOC()
    * before constructing any constructs from non-terminals in your grammar.
    * Example: Consider you are matching on the following very restrictive
    * (fictional) construct that matches a plus between two integer constants.
    * (SUCH A RULE SHOULD NOT BE  PART OF YOUR PARSER):

    plus_consts : INT_CONST '+' INT_CONST

    * where INT_CONST is a terminal for an integer constant. Now, a correct
    * action for this rule that attaches the correct line number to plus_const
    * would look like the following:

    plus_consts : INT_CONST '+' INT_CONST
    {
        // Set the line number of the current non-terminal:
        // ***********************************************
        // You can access the line numbers of the i'th item with @i, just
        // like you acess the value of the i'th exporession with $i.
        //
        // Here, we choose the line number of the last INT_CONST (@3) as the
        // line number of the resulting expression (@$). You are free to pick
        // any reasonable line as the line number of non-terminals. If you
        // omit the statement @$=..., bison has default rules for deciding which
        // line number to use. Check the manual for details if you are interested.
        @$ = @3;


        // Observe that we call SET_NODELOC(@3); this will set the global variable
        // node_lineno to @3. Since the constructor call "plus" uses the value of
        // this global, the plus node will now have the correct line number.
        SET_NODELOC(@3);

        // construct the result node:
        $$ = plus(int_const($1), int_const($3));
    }

    */



    void yyerror(char *s);        /*  defined below; called for each parse error */
    extern int yylex();           /*  the entry point to the lexer  */

    /************************************************************************/
    /*                DONT CHANGE ANYTHING IN THIS SECTION                  */

    Program ast_root;         /* the result of the parse  */
    Classes parse_results;        /* for use in semantic analysis */
    int omerrs = 0;               /* number of errors in lexing and parsing */

#line 157 "cool.tab.c" /* yacc.c:339  */

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
   by #include "cool.tab.h".  */
#ifndef YY_COOL_YY_COOL_TAB_H_INCLUDED
# define YY_COOL_YY_COOL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int cool_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    ELSE = 259,
    FI = 260,
    IF = 261,
    IN = 262,
    INHERITS = 263,
    LET = 264,
    LOOP = 265,
    POOL = 266,
    THEN = 267,
    WHILE = 268,
    CASE = 269,
    ESAC = 270,
    OF = 271,
    DARROW = 272,
    NEW = 273,
    ISVOID = 274,
    STR_CONST = 275,
    INT_CONST = 276,
    BOOL_CONST = 277,
    TYPEID = 278,
    OBJECTID = 279,
    ASSIGN = 280,
    NOT = 281,
    LE = 282,
    ERROR = 283
  };
#endif
/* Tokens.  */
#define CLASS 258
#define ELSE 259
#define FI 260
#define IF 261
#define IN 262
#define INHERITS 263
#define LET 264
#define LOOP 265
#define POOL 266
#define THEN 267
#define WHILE 268
#define CASE 269
#define ESAC 270
#define OF 271
#define DARROW 272
#define NEW 273
#define ISVOID 274
#define STR_CONST 275
#define INT_CONST 276
#define BOOL_CONST 277
#define TYPEID 278
#define OBJECTID 279
#define ASSIGN 280
#define NOT 281
#define LE 282
#define ERROR 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 89 "cool.y" /* yacc.c:355  */

    Boolean boolean;
    Symbol symbol;
    Program program;
    Class_ class_;
    Classes classes;
    Feature feature;
    Features features;
    Formal formal;
    Formals formals;
    Case case_;
    Cases cases;
    Expression expression;
    Expressions expressions;
    char *error_msg;

#line 270 "cool.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE cool_yylval;
extern YYLTYPE cool_yylloc;
int cool_yyparse (void);

#endif /* !YY_COOL_YY_COOL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 301 "cool.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   461

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

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
      41,    42,    33,    31,    44,    32,    37,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    43,    40,
      29,    30,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,    35,     2,     2,     2,
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
      25,    26,    27,    28,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   173,   173,   182,   188,   198,   203,   206,   214,   218,
     223,   226,   233,   236,   239,   242,   246,   250,   255,   258,
     264,   270,   273,   277,   281,   284,   287,   291,   294,   299,
     304,   307,   310,   313,   319,   323,   328,   331,   334,   337,
     340,   343,   346,   349,   352,   355,   358,   361,   364,   367,
     370,   373,   376,   379,   382,   385,   388,   391,   394,   397,
     400,   403,   409,   412
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ELSE", "FI", "IF", "IN",
  "INHERITS", "LET", "LOOP", "POOL", "THEN", "WHILE", "CASE", "ESAC", "OF",
  "DARROW", "NEW", "ISVOID", "STR_CONST", "INT_CONST", "BOOL_CONST",
  "TYPEID", "OBJECTID", "ASSIGN", "NOT", "LE", "ERROR", "'<'", "'='",
  "'+'", "'-'", "'*'", "'/'", "'~'", "'@'", "'.'", "'{'", "'}'", "';'",
  "'('", "')'", "':'", "','", "$accept", "program", "class_list", "class",
  "feature_list", "nonempty_feature_list", "feature", "formal_list",
  "nonempty_formal_list", "formal", "expression_list", "nonempty_block",
  "case_list", "branch", "inner_let", "expression", "nonempty_expr",
  "while_exp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   284,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    60,
      61,    43,    45,    42,    47,   126,    64,    46,   123,   125,
      59,    40,    41,    58,    44
};
# endif

#define YYPACT_NINF -111

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define YYTABLE_NINF -64

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-64)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      54,  -111,    -4,    22,    53,  -111,    -7,  -111,  -111,    35,
       5,    26,  -111,    18,    40,  -111,    45,     5,    56,    69,
      65,     6,    84,    83,    85,  -111,    86,   104,  -111,  -111,
      91,   111,    92,    56,   191,  -111,  -111,   113,  -111,  -111,
     285,   118,   285,   285,   121,   285,  -111,  -111,  -111,    -9,
     285,   285,   315,   285,  -111,   413,  -111,   108,    36,   105,
    -111,   353,   365,  -111,    13,   285,   119,   413,    13,   110,
     116,   390,   376,   285,   285,   285,   285,   285,   285,   285,
     124,   128,   285,   285,   143,   224,   144,   413,    33,   413,
    -111,   254,  -111,   424,   424,   424,   -16,   -16,    13,    13,
     132,   129,   402,   328,     2,   146,   162,   131,    -1,   135,
    -111,   285,  -111,   157,   119,  -111,   285,    77,   158,   118,
    -111,   160,  -111,   147,  -111,   413,   148,    58,   339,  -111,
       8,  -111,   174,  -111,   119,  -111,  -111,    77,   118,   191,
      80,  -111,  -111,  -111,  -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,     0,     0,     0,     3,     0,     1,     4,     0,
       0,     0,    15,     0,     0,     8,     0,     0,    17,     0,
       0,     0,     0,     0,     0,    16,    19,    13,     5,    10,
       0,     0,     0,     0,     0,     6,    20,     0,    18,    61,
       0,     0,     0,     0,     0,     0,    59,    58,    60,    57,
       0,     0,     0,     0,    14,    34,    41,     0,     0,     0,
      43,     0,     0,    45,    46,     0,     0,    55,    51,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    22,
      42,     0,    56,    53,    52,    54,    47,    48,    49,    50,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
      39,     0,    25,     0,     0,    12,     0,     0,     0,     0,
      62,     0,    44,     0,    28,    21,     0,     0,     0,    31,
       0,    33,     0,    27,     0,    38,    40,     0,     0,     0,
       0,    30,    32,    29,    37
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,   190,   178,   177,  -111,  -111,   168,  -111,
    -110,   112,  -111,    98,   -91,   -77,   -40,  -111
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    14,    15,    16,    24,    25,    26,
      88,    70,   108,   109,    60,    54,    55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,     9,    61,    62,   127,    64,    12,    12,   106,   117,
      67,    68,    71,    72,   122,   137,    65,    78,    79,     6,
      80,    81,     7,   107,   140,    87,    89,   118,   131,    13,
      13,    10,    66,    93,    94,    95,    96,    97,    98,    99,
     129,   130,   102,   103,    -9,   -11,   119,   142,    83,    80,
      81,    71,   138,    -2,     1,     1,     2,     2,    11,    18,
     141,    19,   143,    73,    17,    74,    75,    76,    77,    78,
      79,   125,    80,    81,    89,   110,   128,   111,    39,    20,
      23,   -35,   -35,    40,   -35,    21,    41,   -35,   -35,   -35,
      42,    43,    27,   -35,    89,    44,    45,    46,    47,    48,
     135,    49,   111,    50,   -35,    28,   -35,   -35,   -35,   -35,
     -35,   -35,    51,   -35,   -35,    52,   -35,   -35,    53,   -35,
      39,   -35,   144,    30,   111,    40,    31,    32,    41,    34,
      33,    35,    42,    43,    36,    37,    57,    44,    45,    46,
      47,    48,    59,    49,    63,    50,    82,   100,    84,   -26,
     -63,   -63,   101,   -63,    51,    90,   -63,    52,   -63,    39,
      53,   -23,   -63,   -23,    40,   -35,   104,    41,   107,   113,
     114,    42,    43,   120,   121,   124,    44,    45,    46,    47,
      48,   126,    49,   132,    50,   -63,   -63,   133,   -63,   134,
     -63,   139,    39,    51,     8,    22,    52,    40,    29,    53,
      41,    38,   -35,   112,    42,    43,   123,     0,     0,    44,
      45,    46,    47,    48,     0,    49,     0,    50,     0,     0,
       0,     0,     0,     0,     0,   105,    51,     0,     0,    52,
      40,   -35,    53,    41,     0,   -35,     0,    42,    43,     0,
       0,     0,    44,    45,    46,    47,    48,     0,    49,     0,
      50,     0,     0,     0,     0,    69,     0,     0,     0,    51,
      40,     0,    52,    41,     0,    53,     0,    42,    43,     0,
       0,     0,    44,    45,    46,    47,    48,     0,    49,     0,
      50,     0,     0,     0,     0,     0,    39,     0,     0,    51,
       0,    40,    52,   -24,    41,    53,     0,     0,    42,    43,
       0,     0,     0,    44,    45,    46,    47,    48,     0,    49,
       0,    50,     0,     0,     0,     0,    69,     0,     0,     0,
      51,    40,     0,    52,    41,     0,    53,     0,    42,    43,
       0,     0,   116,    44,    45,    46,    47,    48,     0,    49,
       0,    50,     0,     0,   136,     0,     0,     0,     0,     0,
      51,     0,     0,    52,     0,    73,    53,    74,    75,    76,
      77,    78,    79,    85,    80,    81,    73,     0,    74,    75,
      76,    77,    78,    79,     0,    80,    81,     0,     0,     0,
      73,    86,    74,    75,    76,    77,    78,    79,     0,    80,
      81,     0,    73,     0,    74,    75,    76,    77,    78,    79,
       0,    80,    81,    73,     0,    74,    75,    76,    77,    78,
      79,     0,    80,    81,     0,     0,     0,    73,    92,    74,
      75,    76,    77,    78,    79,     0,    80,    81,     0,    73,
      91,    74,    75,    76,    77,    78,    79,     0,    80,    81,
      73,   115,    74,    75,    76,    77,    78,    79,     0,    80,
      81,   -64,     0,   -64,   -64,    76,    77,    78,    79,     0,
      80,    81
};

static const yytype_int16 yycheck[] =
{
      40,     8,    42,    43,   114,    45,     1,     1,    85,     7,
      50,    51,    52,    53,    15,     7,    25,    33,    34,    23,
      36,    37,     0,    24,   134,    65,    66,    25,   119,    24,
      24,    38,    41,    73,    74,    75,    76,    77,    78,    79,
     117,   118,    82,    83,    39,    39,    44,   138,    12,    36,
      37,    91,    44,     0,     1,     1,     3,     3,    23,    41,
     137,    43,   139,    27,    38,    29,    30,    31,    32,    33,
      34,   111,    36,    37,   114,    42,   116,    44,     1,    39,
      24,     4,     5,     6,     7,    40,     9,    10,    11,    12,
      13,    14,    23,    16,   134,    18,    19,    20,    21,    22,
      42,    24,    44,    26,    27,    40,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       1,    44,    42,    39,    44,     6,    43,    42,     9,    25,
      44,    40,    13,    14,    23,    43,    23,    18,    19,    20,
      21,    22,    24,    24,    23,    26,    38,    23,    43,    39,
       4,     5,    24,     7,    35,    39,    10,    38,    12,     1,
      41,    42,    16,    44,     6,     7,    23,     9,    24,    37,
      41,    13,    14,    11,    43,    40,    18,    19,    20,    21,
      22,    24,    24,    23,    26,    39,    40,    40,    42,    41,
      44,    17,     1,    35,     4,    17,    38,     6,    21,    41,
       9,    33,    44,    91,    13,    14,   108,    -1,    -1,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    35,    -1,    -1,    38,
       6,    40,    41,     9,    -1,    11,    -1,    13,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    35,
       6,    -1,    38,     9,    -1,    41,    -1,    13,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    35,
      -1,     6,    38,    39,     9,    41,    -1,    -1,    13,    14,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,
      35,     6,    -1,    38,     9,    -1,    41,    -1,    13,    14,
      -1,    -1,     4,    18,    19,    20,    21,    22,    -1,    24,
      -1,    26,    -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    38,    -1,    27,    41,    29,    30,    31,
      32,    33,    34,    10,    36,    37,    27,    -1,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    -1,    -1,    -1,
      27,    16,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    -1,    27,    -1,    29,    30,    31,    32,    33,    34,
      -1,    36,    37,    27,    -1,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    -1,    -1,    -1,    27,    42,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    -1,    27,
      40,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      27,    39,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    27,    -1,    29,    30,    31,    32,    33,    34,    -1,
      36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    46,    47,    48,    23,     0,    48,     8,
      38,    23,     1,    24,    49,    50,    51,    38,    41,    43,
      39,    40,    49,    24,    52,    53,    54,    23,    40,    50,
      39,    43,    42,    44,    25,    40,    23,    43,    53,     1,
       6,     9,    13,    14,    18,    19,    20,    21,    22,    24,
      26,    35,    38,    41,    60,    61,    62,    23,    61,    24,
      59,    61,    61,    23,    61,    25,    41,    61,    61,     1,
      56,    61,    61,    27,    29,    30,    31,    32,    33,    34,
      36,    37,    38,    12,    43,    10,    16,    61,    55,    61,
      39,    40,    42,    61,    61,    61,    61,    61,    61,    61,
      23,    24,    61,    61,    23,     1,    60,    24,    57,    58,
      42,    44,    56,    37,    41,    39,     4,     7,    25,    44,
      11,    43,    15,    58,    40,    61,    24,    55,    61,    60,
      60,    59,    23,    40,    41,    42,     5,     7,    44,    17,
      55,    60,    59,    60,    42
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      50,    50,    51,    51,    51,    51,    52,    52,    53,    53,
      54,    55,    55,    55,    56,    56,    56,    57,    57,    58,
      59,    59,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     8,     1,     1,     0,
       3,     2,     9,     3,     5,     1,     1,     0,     3,     1,
       3,     3,     1,     0,     2,     3,     1,     3,     2,     5,
       7,     5,     7,     5,     1,     0,     3,     8,     6,     4,
       7,     1,     3,     2,     5,     2,     2,     3,     3,     3,
       3,     2,     3,     3,     3,     2,     3,     1,     1,     1,
       1,     1,     5,     4
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 174 "cool.y" /* yacc.c:1646  */
    {
            (yyloc) = (yylsp[0]);
            ast_root = program((yyvsp[0].classes));
        }
#line 1633 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 183 "cool.y" /* yacc.c:1646  */
    {
               (yyval.classes) = single_Classes((yyvsp[0].class_));
               parse_results = (yyval.classes);
           }
#line 1642 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 189 "cool.y" /* yacc.c:1646  */
    {
               (yyval.classes) = append_Classes((yyvsp[-1].classes), single_Classes((yyvsp[0].class_)));
               parse_results = (yyval.classes);
           }
#line 1651 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 199 "cool.y" /* yacc.c:1646  */
    {
          (yyval.class_) = class_((yyvsp[-4].symbol), idtable.add_string("Object"), (yyvsp[-2].features), stringtable.add_string(curr_filename));
      }
#line 1659 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 204 "cool.y" /* yacc.c:1646  */
    { (yyval.class_) = class_((yyvsp[-6].symbol), (yyvsp[-4].symbol), (yyvsp[-2].features), stringtable.add_string(curr_filename)); }
#line 1665 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 215 "cool.y" /* yacc.c:1646  */
    { (yyval.features) = (yyvsp[0].features); }
#line 1671 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 218 "cool.y" /* yacc.c:1646  */
    { (yyval.features) = nil_Features(); }
#line 1677 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 224 "cool.y" /* yacc.c:1646  */
    { (yyval.features) = append_Features(single_Features((yyvsp[-2].feature)), (yyvsp[0].features)); }
#line 1683 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 227 "cool.y" /* yacc.c:1646  */
    { (yyval.features) = single_Features((yyvsp[-1].feature)); }
#line 1689 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 234 "cool.y" /* yacc.c:1646  */
    { (yyval.feature) = method((yyvsp[-8].symbol), (yyvsp[-6].formals), (yyvsp[-3].symbol), (yyvsp[-1].expression)); }
#line 1695 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 237 "cool.y" /* yacc.c:1646  */
    { (yyval.feature) = attr((yyvsp[-2].symbol), (yyvsp[0].symbol), no_expr()); }
#line 1701 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 240 "cool.y" /* yacc.c:1646  */
    { (yyval.feature) = attr((yyvsp[-4].symbol), (yyvsp[-2].symbol), (yyvsp[0].expression)); }
#line 1707 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 247 "cool.y" /* yacc.c:1646  */
    { (yyval.formals) = (yyvsp[0].formals); }
#line 1713 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 250 "cool.y" /* yacc.c:1646  */
    { (yyval.formals) = nil_Formals(); }
#line 1719 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 256 "cool.y" /* yacc.c:1646  */
    { (yyval.formals) = append_Formals(single_Formals((yyvsp[-2].formal)), (yyvsp[0].formals)); }
#line 1725 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 259 "cool.y" /* yacc.c:1646  */
    { (yyval.formals) = single_Formals((yyvsp[0].formal)); }
#line 1731 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 265 "cool.y" /* yacc.c:1646  */
    { (yyval.formal) = formal((yyvsp[-2].symbol), (yyvsp[0].symbol)); }
#line 1737 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 271 "cool.y" /* yacc.c:1646  */
    { (yyval.expressions) = append_Expressions((yyvsp[-2].expressions), single_Expressions((yyvsp[0].expression))); }
#line 1743 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 274 "cool.y" /* yacc.c:1646  */
    { (yyval.expressions) = single_Expressions((yyvsp[0].expression)); }
#line 1749 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 277 "cool.y" /* yacc.c:1646  */
    { (yyval.expressions) = nil_Expressions(); }
#line 1755 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 282 "cool.y" /* yacc.c:1646  */
    { (yyval.expressions) = single_Expressions((yyvsp[-1].expression)); }
#line 1761 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 285 "cool.y" /* yacc.c:1646  */
    { (yyval.expressions) = append_Expressions(single_Expressions((yyvsp[-2].expression)), (yyvsp[0].expressions)); }
#line 1767 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 292 "cool.y" /* yacc.c:1646  */
    { (yyval.cases) = append_Cases((yyvsp[-2].cases), single_Cases((yyvsp[-1].case_))); }
#line 1773 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 295 "cool.y" /* yacc.c:1646  */
    { (yyval.cases) = single_Cases((yyvsp[-1].case_)); }
#line 1779 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 300 "cool.y" /* yacc.c:1646  */
    { (yyval.case_) = branch((yyvsp[-4].symbol), (yyvsp[-2].symbol), (yyvsp[0].expression)); }
#line 1785 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 305 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = let((yyvsp[-6].symbol), (yyvsp[-4].symbol), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1791 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 308 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = let((yyvsp[-4].symbol), (yyvsp[-2].symbol), no_expr(), (yyvsp[0].expression)); }
#line 1797 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 311 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = let((yyvsp[-6].symbol), (yyvsp[-4].symbol), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1803 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 314 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = let((yyvsp[-4].symbol), (yyvsp[-2].symbol), no_expr(), (yyvsp[0].expression)); }
#line 1809 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 320 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1815 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 323 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = no_expr(); }
#line 1821 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 329 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = assign((yyvsp[-2].symbol), (yyvsp[0].expression)); }
#line 1827 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 332 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = static_dispatch((yyvsp[-7].expression), (yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expressions)); }
#line 1833 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 335 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = dispatch((yyvsp[-5].expression), (yyvsp[-3].symbol), (yyvsp[-1].expressions)); }
#line 1839 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 338 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = dispatch(object(idtable.add_string("self")), (yyvsp[-3].symbol), (yyvsp[-1].expressions)); }
#line 1845 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 341 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = cond((yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1851 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 344 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1857 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 347 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = block((yyvsp[-1].expressions)); }
#line 1863 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 350 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1869 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 353 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = typcase((yyvsp[-3].expression), (yyvsp[-1].cases)); }
#line 1875 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 356 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = new_((yyvsp[0].symbol)); }
#line 1881 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 359 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = isvoid((yyvsp[0].expression)); }
#line 1887 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 362 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = plus((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1893 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 365 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = sub((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1899 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 368 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = mul((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1905 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 371 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = divide((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1911 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 374 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = neg((yyvsp[0].expression)); }
#line 1917 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 377 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = lt((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1923 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 380 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = leq((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1929 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 383 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = eq((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1935 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 386 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = comp((yyvsp[0].expression)); }
#line 1941 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 389 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[-1].expression); }
#line 1947 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 392 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = object((yyvsp[0].symbol)); }
#line 1953 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 395 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = int_const((yyvsp[0].symbol)); }
#line 1959 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 398 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = string_const((yyvsp[0].symbol)); }
#line 1965 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 401 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = bool_const((yyvsp[0].boolean)); }
#line 1971 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 404 "cool.y" /* yacc.c:1646  */
    { }
#line 1977 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 410 "cool.y" /* yacc.c:1646  */
    { (yyval.expression) = loop((yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1983 "cool.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 413 "cool.y" /* yacc.c:1646  */
    { }
#line 1989 "cool.tab.c" /* yacc.c:1646  */
    break;


#line 1993 "cool.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 418 "cool.y" /* yacc.c:1906  */


/* This function is called automatically when Bison detects a parse error. */
void yyerror(char *s) {
    extern int curr_lineno;

    cerr << "\"" << curr_filename << "\", line " << curr_lineno << ": "
         << s << " at or near ";

    print_cool_token(yychar);

    cerr << endl;

    omerrs++;

    if (omerrs > 50) {
        fprintf(stdout, "More than 50 errors\n");
        exit(1);
    }

}
