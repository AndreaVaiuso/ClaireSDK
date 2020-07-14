/* A Bison parser, made by GNU Bison 3.6.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.6.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "headers/claire.h"
    #include "headers/printree.h"
    FILE *out;

#line 80 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MIN = 258,                     /* MIN  */
    PRINT = 259,                   /* PRINT  */
    BULTIN = 260,                  /* BULTIN  */
    CMDLIST = 261,                 /* CMDLIST  */
    IFLIST = 262,                  /* IFLIST  */
    ENDIF = 263,                   /* ENDIF  */
    LIST = 264,                    /* LIST  */
    COLON = 265,                   /* COLON  */
    LOOP = 266,                    /* LOOP  */
    PROCEDURE = 267,               /* PROCEDURE  */
    UPDATEDEF = 268,               /* UPDATEDEF  */
    ENDDIR = 269,                  /* ENDDIR  */
    SCHEDULE = 270,                /* SCHEDULE  */
    OUTERIF = 271,                 /* OUTERIF  */
    OP = 272,                      /* OP  */
    CP = 273,                      /* CP  */
    END = 274,                     /* END  */
    BREAK = 275,                   /* BREAK  */
    INCREASE = 276,                /* INCREASE  */
    DECREASE = 277,                /* DECREASE  */
    BY = 278,                      /* BY  */
    REPEAT = 279,                  /* REPEAT  */
    RETURN = 280,                  /* RETURN  */
    INPUT = 281,                   /* INPUT  */
    OUTPUT = 282,                  /* OUTPUT  */
    FUNC = 283,                    /* FUNC  */
    FCALL = 284,                   /* FCALL  */
    DOT = 285,                     /* DOT  */
    COMMA = 286,                   /* COMMA  */
    SEMICOLON = 287,               /* SEMICOLON  */
    QM = 288,                      /* QM  */
    ASSIGN = 289,                  /* ASSIGN  */
    CONNECT = 290,                 /* CONNECT  */
    COLLECTION = 291,              /* COLLECTION  */
    DISPLAY = 292,                 /* DISPLAY  */
    SIZE = 293,                    /* SIZE  */
    SLEEP = 294,                   /* SLEEP  */
    SYML = 295,                    /* SYML  */
    UNDEF = 296,                   /* UNDEF  */
    EQUALS = 297,                  /* EQUALS  */
    ADD = 298,                     /* ADD  */
    SUB = 299,                     /* SUB  */
    DIV = 300,                     /* DIV  */
    MUL = 301,                     /* MUL  */
    ABS = 302,                     /* ABS  */
    LT = 303,                      /* LT  */
    GT = 304,                      /* GT  */
    GE = 305,                      /* GE  */
    LE = 306,                      /* LE  */
    NE = 307,                      /* NE  */
    OQ = 308,                      /* OQ  */
    CQ = 309,                      /* CQ  */
    OG = 310,                      /* OG  */
    CG = 311,                      /* CG  */
    AND = 312,                     /* AND  */
    OR = 313,                      /* OR  */
    CONCAT = 314,                  /* CONCAT  */
    IDENTIFIER = 315,              /* IDENTIFIER  */
    FIDENTIFIER = 316,             /* FIDENTIFIER  */
    DO = 317,                      /* DO  */
    IF = 318,                      /* IF  */
    ELSE = 319,                    /* ELSE  */
    UPDATE = 320,                  /* UPDATE  */
    WHILE = 321,                   /* WHILE  */
    DEVICEID = 322,                /* DEVICEID  */
    BOOLEAN = 323,                 /* BOOLEAN  */
    NUMBER = 324,                  /* NUMBER  */
    STRING = 325,                  /* STRING  */
    CMP = 326,                     /* CMP  */
    MINUS = 327                    /* MINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "parser.y"

    char* symbolname;
    SYMBOL* symbol;
    SYMLIST* symlist;
    SYMREF* symref;
    VARLIST* varlist;
    AST* ast;

#line 211 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MIN = 3,                        /* MIN  */
  YYSYMBOL_PRINT = 4,                      /* PRINT  */
  YYSYMBOL_BULTIN = 5,                     /* BULTIN  */
  YYSYMBOL_CMDLIST = 6,                    /* CMDLIST  */
  YYSYMBOL_IFLIST = 7,                     /* IFLIST  */
  YYSYMBOL_ENDIF = 8,                      /* ENDIF  */
  YYSYMBOL_LIST = 9,                       /* LIST  */
  YYSYMBOL_COLON = 10,                     /* COLON  */
  YYSYMBOL_LOOP = 11,                      /* LOOP  */
  YYSYMBOL_PROCEDURE = 12,                 /* PROCEDURE  */
  YYSYMBOL_UPDATEDEF = 13,                 /* UPDATEDEF  */
  YYSYMBOL_ENDDIR = 14,                    /* ENDDIR  */
  YYSYMBOL_SCHEDULE = 15,                  /* SCHEDULE  */
  YYSYMBOL_OUTERIF = 16,                   /* OUTERIF  */
  YYSYMBOL_OP = 17,                        /* OP  */
  YYSYMBOL_CP = 18,                        /* CP  */
  YYSYMBOL_END = 19,                       /* END  */
  YYSYMBOL_BREAK = 20,                     /* BREAK  */
  YYSYMBOL_INCREASE = 21,                  /* INCREASE  */
  YYSYMBOL_DECREASE = 22,                  /* DECREASE  */
  YYSYMBOL_BY = 23,                        /* BY  */
  YYSYMBOL_REPEAT = 24,                    /* REPEAT  */
  YYSYMBOL_RETURN = 25,                    /* RETURN  */
  YYSYMBOL_INPUT = 26,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 27,                    /* OUTPUT  */
  YYSYMBOL_FUNC = 28,                      /* FUNC  */
  YYSYMBOL_FCALL = 29,                     /* FCALL  */
  YYSYMBOL_DOT = 30,                       /* DOT  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 32,                 /* SEMICOLON  */
  YYSYMBOL_QM = 33,                        /* QM  */
  YYSYMBOL_ASSIGN = 34,                    /* ASSIGN  */
  YYSYMBOL_CONNECT = 35,                   /* CONNECT  */
  YYSYMBOL_COLLECTION = 36,                /* COLLECTION  */
  YYSYMBOL_DISPLAY = 37,                   /* DISPLAY  */
  YYSYMBOL_SIZE = 38,                      /* SIZE  */
  YYSYMBOL_SLEEP = 39,                     /* SLEEP  */
  YYSYMBOL_SYML = 40,                      /* SYML  */
  YYSYMBOL_UNDEF = 41,                     /* UNDEF  */
  YYSYMBOL_EQUALS = 42,                    /* EQUALS  */
  YYSYMBOL_ADD = 43,                       /* ADD  */
  YYSYMBOL_SUB = 44,                       /* SUB  */
  YYSYMBOL_DIV = 45,                       /* DIV  */
  YYSYMBOL_MUL = 46,                       /* MUL  */
  YYSYMBOL_ABS = 47,                       /* ABS  */
  YYSYMBOL_LT = 48,                        /* LT  */
  YYSYMBOL_GT = 49,                        /* GT  */
  YYSYMBOL_GE = 50,                        /* GE  */
  YYSYMBOL_LE = 51,                        /* LE  */
  YYSYMBOL_NE = 52,                        /* NE  */
  YYSYMBOL_OQ = 53,                        /* OQ  */
  YYSYMBOL_CQ = 54,                        /* CQ  */
  YYSYMBOL_OG = 55,                        /* OG  */
  YYSYMBOL_CG = 56,                        /* CG  */
  YYSYMBOL_AND = 57,                       /* AND  */
  YYSYMBOL_OR = 58,                        /* OR  */
  YYSYMBOL_CONCAT = 59,                    /* CONCAT  */
  YYSYMBOL_IDENTIFIER = 60,                /* IDENTIFIER  */
  YYSYMBOL_FIDENTIFIER = 61,               /* FIDENTIFIER  */
  YYSYMBOL_DO = 62,                        /* DO  */
  YYSYMBOL_IF = 63,                        /* IF  */
  YYSYMBOL_ELSE = 64,                      /* ELSE  */
  YYSYMBOL_UPDATE = 65,                    /* UPDATE  */
  YYSYMBOL_WHILE = 66,                     /* WHILE  */
  YYSYMBOL_DEVICEID = 67,                  /* DEVICEID  */
  YYSYMBOL_BOOLEAN = 68,                   /* BOOLEAN  */
  YYSYMBOL_NUMBER = 69,                    /* NUMBER  */
  YYSYMBOL_STRING = 70,                    /* STRING  */
  YYSYMBOL_CMP = 71,                       /* CMP  */
  YYSYMBOL_MINUS = 72,                     /* MINUS  */
  YYSYMBOL_YYACCEPT = 73,                  /* $accept  */
  YYSYMBOL_root = 74,                      /* root  */
  YYSYMBOL_codeblock = 75,                 /* codeblock  */
  YYSYMBOL_functionconstruct = 76,         /* functionconstruct  */
  YYSYMBOL_statement = 77,                 /* statement  */
  YYSYMBOL_conditionalconstruct = 78,      /* conditionalconstruct  */
  YYSYMBOL_conditionallist = 79,           /* conditionallist  */
  YYSYMBOL_conditionalstat = 80,           /* conditionalstat  */
  YYSYMBOL_conditionalouterstat = 81,      /* conditionalouterstat  */
  YYSYMBOL_loopconstruct = 82,             /* loopconstruct  */
  YYSYMBOL_updatedef = 83,                 /* updatedef  */
  YYSYMBOL_enddef = 84,                    /* enddef  */
  YYSYMBOL_assign = 85,                    /* assign  */
  YYSYMBOL_expression = 86,                /* expression  */
  YYSYMBOL_booleanop = 87,                 /* booleanop  */
  YYSYMBOL_operation = 88,                 /* operation  */
  YYSYMBOL_functioncall = 89,              /* functioncall  */
  YYSYMBOL_varlist = 90,                   /* varlist  */
  YYSYMBOL_namelist = 91,                  /* namelist  */
  YYSYMBOL_term = 92,                      /* term  */
  YYSYMBOL_refvar = 93                     /* refvar  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   702

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  73
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

#define YYMAXUTOK   327


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
  /* YYRLINEYYN -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    51,    51,    59,    60,    67,    69,    72,    73,    74,
      75,    76,    77,    80,    81,    84,    85,    88,    94,   100,
     101,   104,   107,   108,   109,   110,   113,   114,   115,   118,
     119,   120,   121,   122,   123,   124,   125,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   157,   162,   169,   170,   173,   174,   177,   178,   179,
     182,   185
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MIN", "PRINT",
  "BULTIN", "CMDLIST", "IFLIST", "ENDIF", "LIST", "COLON", "LOOP",
  "PROCEDURE", "UPDATEDEF", "ENDDIR", "SCHEDULE", "OUTERIF", "OP", "CP",
  "END", "BREAK", "INCREASE", "DECREASE", "BY", "REPEAT", "RETURN",
  "INPUT", "OUTPUT", "FUNC", "FCALL", "DOT", "COMMA", "SEMICOLON", "QM",
  "ASSIGN", "CONNECT", "COLLECTION", "DISPLAY", "SIZE", "SLEEP", "SYML",
  "UNDEF", "EQUALS", "ADD", "SUB", "DIV", "MUL", "ABS", "LT", "GT", "GE",
  "LE", "NE", "OQ", "CQ", "OG", "CG", "AND", "OR", "CONCAT", "IDENTIFIER",
  "FIDENTIFIER", "DO", "IF", "ELSE", "UPDATE", "WHILE", "DEVICEID",
  "BOOLEAN", "NUMBER", "STRING", "CMP", "MINUS", "$accept", "root",
  "codeblock", "functionconstruct", "statement", "conditionalconstruct",
  "conditionallist", "conditionalstat", "conditionalouterstat",
  "loopconstruct", "updatedef", "enddef", "assign", "expression",
  "booleanop", "operation", "functioncall", "varlist", "namelist", "term",
  "refvar", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327
};
#endif

#define YYPACT_NINF (-101)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACTSTATE-NUM -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -101,     8,   196,  -101,    -7,   -10,  -101,   -38,   -38,   -10,
     -29,   -27,    18,    21,   154,   154,    12,    28,  -101,   -10,
      17,   621,  -101,  -101,  -101,  -101,    24,  -101,   -18,  -101,
    -101,  -101,    35,   -40,   650,  -101,    23,    39,   621,    -4,
     627,  -101,    20,    51,    52,   -40,   650,    32,    79,   -38,
     154,   154,  -101,    94,   614,   154,   -16,   540,    33,   650,
    -101,    57,  -101,  -101,  -101,    60,   -10,   -10,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   621,    13,
     106,  -101,  -101,   154,   154,  -101,    72,   108,    71,    85,
    -101,  -101,   103,   117,    66,   109,   111,   130,   621,  -101,
     142,  -101,   250,   621,   -15,    60,  -101,    92,   139,    -3,
      -3,  -101,  -101,   139,   139,   139,   139,   139,  -101,  -101,
    -101,  -101,  -101,  -101,   621,  -101,  -101,   621,  -101,  -101,
    -101,    90,   119,   -21,   560,  -101,   154,   122,   304,  -101,
     127,  -101,  -101,  -101,   104,  -101,   358,  -101,  -101,  -101,
      62,  -101,  -101,  -101,   412,  -101,  -101,   466,   154,   486,
    -101,  -101,   139,   133,  -101
};

  /* YYDEFACTSTATE-NUM -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,     3,     0,
       0,     0,    37,    49,    48,    12,     0,     7,     0,    10,
       2,    29,    11,    33,    32,    51,    47,    67,     0,     0,
       0,    47,    70,     0,     0,    36,    35,     0,     0,     0,
       0,     0,    58,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     4,     8,     3,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    60,     0,     0,    27,     0,     0,     0,     0,
      59,    62,    63,     0,     0,     0,    65,     0,     0,     3,
       0,     3,     0,     0,     0,    15,    39,    40,    41,    52,
      53,    54,    55,    43,    44,    45,    46,    42,    26,    68,
      69,    31,    56,    57,     0,    50,    30,     0,    61,    71,
       3,     0,     0,     0,    18,    25,    22,     0,     0,     9,
       0,    13,     3,    16,     0,    64,     0,    66,     3,    20,
      23,    21,    19,     3,     0,    28,     6,     0,     0,     0,
      14,     5,    24,     0,    17
};

  /* YYPGOTONTERM-NUM.  */
static const yytype_int8 yypgoto[] =
{
    -101,  -101,     3,  -101,  -101,  -101,    63,  -101,  -101,  -101,
    -101,  -101,  -101,    -6,     4,    11,  -101,  -100,    41,    -2,
    -101
};

  /* YYDEFGOTONTERM-NUM.  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    25,    26,    27,   104,   105,    28,    29,
      30,   137,    31,    32,    33,    34,    35,    93,    97,    41,
      37
};

  /* YYTABLEYYPACT[STATE-NUM] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      36,    63,    95,   149,   141,    43,    44,     5,     3,    39,
      38,     7,     8,    45,    81,    61,    40,    66,    67,    36,
      46,    57,    42,    58,   144,    52,    53,   145,    12,    54,
      59,    47,    80,    48,    14,    49,    36,    15,    50,   119,
     120,   101,    71,    72,    96,    56,    64,    87,    92,   142,
      16,    60,    36,    66,    67,    36,    62,    78,    22,    23,
      24,    88,    89,   100,    99,    55,    94,   102,    65,    79,
     106,   107,   118,    55,    83,    84,    36,    59,    59,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   126,
      66,    67,   133,   158,   122,   123,    36,   140,    36,    85,
      36,    36,   134,    82,   138,    69,    70,    71,    72,    69,
      70,    71,    72,    86,    69,    70,    71,    72,    92,   101,
     129,    92,    36,   103,   121,    36,   125,   124,    69,    70,
      71,    72,    36,   146,   127,   128,    36,    69,    70,    71,
      72,    90,   131,   130,    36,   154,     4,   150,   132,    66,
      96,   157,    36,   148,   151,    36,   159,    36,   153,     5,
     155,   135,     6,     7,     8,   164,   136,     9,   143,   162,
       0,    51,   147,     0,     0,     7,     8,    10,    11,     0,
      12,    13,    69,    70,    71,    72,    14,     0,     0,    15,
       0,     0,    12,     0,     0,     0,     0,     0,    14,     0,
       4,    15,    16,    17,    18,    19,     0,     0,    21,     0,
      22,    23,    24,     5,    16,     0,     6,     7,     8,     0,
       0,     9,     0,    23,    24,     0,     0,     0,     0,     0,
       0,    10,    11,     0,    12,    13,     0,     0,     0,     0,
      14,     0,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     0,    16,    17,    18,    19,
       0,    20,    21,     0,    22,    23,    24,     5,     0,   139,
       6,     7,     8,     0,     0,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,    12,    13,
       0,     0,     0,     0,    14,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     0,
      16,    17,    18,    19,     0,     0,    21,     0,    22,    23,
      24,     5,     0,     0,     6,     7,     8,     0,   152,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,     0,    12,    13,     0,     0,     0,     0,    14,     0,
       0,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     0,    16,    17,    18,    19,     0,     0,
      21,     0,    22,    23,    24,     5,     0,   156,     6,     7,
       8,     0,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,     0,    12,    13,     0,     0,
       0,     0,    14,     0,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,    16,    17,
      18,    19,     0,     0,    21,     0,    22,    23,    24,     5,
       0,   160,     6,     7,     8,     0,     0,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,     0,
      12,    13,     0,     0,     0,     0,    14,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,    16,    17,    18,    19,     0,     0,    21,     0,
      22,    23,    24,     5,     0,   161,     6,     7,     8,     0,
       4,     9,     0,     0,   163,     0,     0,     0,     0,     0,
       0,    10,    11,     5,    12,    13,     6,     7,     8,     0,
      14,     9,     0,    15,     0,     0,     0,     0,     0,     0,
       0,    10,    11,     0,    12,    13,    16,    17,    18,    19,
      14,     0,    21,    15,    22,    23,    24,     0,     0,     0,
       0,     0,     0,     0,     4,     0,    16,    17,    18,    19,
       0,     0,    21,     0,    22,    23,    24,     5,     0,     0,
       6,     7,     8,     0,     4,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     5,    12,    13,
       6,     7,     8,     0,    14,     9,     0,    15,     0,     0,
       0,     0,     0,     0,     0,    10,    11,     0,    12,    13,
      16,    17,    18,    19,    14,     0,    98,    15,    22,    23,
      24,     0,     0,     0,     0,     0,     0,     0,     4,     0,
      16,    17,    18,    19,     0,     4,    21,     0,    22,    23,
      24,     5,    91,     0,     6,     7,     8,     0,     5,     9,
       0,     6,     7,     8,     0,    82,     9,     0,     0,    10,
      11,     0,    12,    13,     0,     0,    10,    11,    14,    12,
      13,    15,     0,     0,     0,    14,     0,     0,    15,    68,
      69,    70,    71,    72,    16,    73,    74,    75,    76,    77,
       0,    16,    22,    23,    24,     0,     0,     0,     0,    22,
      23,    24,    68,    69,    70,    71,    72,     0,    73,    74,
      75,    76,    77
};

static const yytype_int16 yycheck[] =
{
       2,    19,    18,    24,    19,     7,     8,    17,     0,     5,
      17,    21,    22,     9,    18,    21,     5,    57,    58,    21,
       9,    18,    60,    19,   124,    14,    15,   127,    38,    17,
      19,    60,    38,    60,    44,    17,    38,    47,    17,    26,
      27,    62,    45,    46,    60,    17,    64,    49,    54,    64,
      60,    34,    54,    57,    58,    57,    32,    34,    68,    69,
      70,    50,    51,    60,    31,    53,    55,    64,    33,    30,
      66,    67,    78,    53,    23,    23,    78,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    18,
      57,    58,    98,    31,    83,    84,    98,   103,   100,    67,
     102,   103,    99,    18,   101,    43,    44,    45,    46,    43,
      44,    45,    46,    34,    43,    44,    45,    46,   124,    62,
      54,   127,   124,    63,    18,   127,    18,    55,    43,    44,
      45,    46,   134,   130,    31,    18,   138,    43,    44,    45,
      46,    47,    31,    34,   146,   142,     4,   136,    18,    57,
      60,   148,   154,    34,    32,   157,   153,   159,    31,    17,
      56,    19,    20,    21,    22,    32,    24,    25,   105,   158,
      -1,    17,   131,    -1,    -1,    21,    22,    35,    36,    -1,
      38,    39,    43,    44,    45,    46,    44,    -1,    -1,    47,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,
       4,    47,    60,    61,    62,    63,    -1,    -1,    66,    -1,
      68,    69,    70,    17,    60,    -1,    20,    21,    22,    -1,
      -1,    25,    -1,    69,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,    -1,    60,    61,    62,    63,
      -1,    65,    66,    -1,    68,    69,    70,    17,    -1,    19,
      20,    21,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    38,    39,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      60,    61,    62,    63,    -1,    -1,    66,    -1,    68,    69,
      70,    17,    -1,    -1,    20,    21,    22,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    -1,    38,    39,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,    -1,    60,    61,    62,    63,    -1,    -1,
      66,    -1,    68,    69,    70,    17,    -1,    19,    20,    21,
      22,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,    60,    61,
      62,    63,    -1,    -1,    66,    -1,    68,    69,    70,    17,
      -1,    19,    20,    21,    22,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,
      38,    39,    -1,    -1,    -1,    -1,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,    -1,    60,    61,    62,    63,    -1,    -1,    66,    -1,
      68,    69,    70,    17,    -1,    19,    20,    21,    22,    -1,
       4,    25,    -1,    -1,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    17,    38,    39,    20,    21,    22,    -1,
      44,    25,    -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    -1,    38,    39,    60,    61,    62,    63,
      44,    -1,    66,    47,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,    -1,    60,    61,    62,    63,
      -1,    -1,    66,    -1,    68,    69,    70,    17,    -1,    -1,
      20,    21,    22,    -1,     4,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    17,    38,    39,
      20,    21,    22,    -1,    44,    25,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    38,    39,
      60,    61,    62,    63,    44,    -1,    66,    47,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      60,    61,    62,    63,    -1,     4,    66,    -1,    68,    69,
      70,    17,    18,    -1,    20,    21,    22,    -1,    17,    25,
      -1,    20,    21,    22,    -1,    18,    25,    -1,    -1,    35,
      36,    -1,    38,    39,    -1,    -1,    35,    36,    44,    38,
      39,    47,    -1,    -1,    -1,    44,    -1,    -1,    47,    42,
      43,    44,    45,    46,    60,    48,    49,    50,    51,    52,
      -1,    60,    68,    69,    70,    -1,    -1,    -1,    -1,    68,
      69,    70,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    52
};

  /* YYSTOSSTATE-NUM -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    74,    75,     0,     4,    17,    20,    21,    22,    25,
      35,    36,    38,    39,    44,    47,    60,    61,    62,    63,
      65,    66,    68,    69,    70,    76,    77,    78,    81,    82,
      83,    85,    86,    87,    88,    89,    92,    93,    17,    87,
      88,    92,    60,    92,    92,    87,    88,    60,    60,    17,
      17,    17,    88,    88,    17,    53,    17,    75,    87,    88,
      34,    86,    32,    19,    64,    33,    57,    58,    42,    43,
      44,    45,    46,    48,    49,    50,    51,    52,    34,    30,
      86,    18,    18,    23,    23,    67,    34,    92,    88,    88,
      47,    18,    86,    90,    88,    18,    60,    91,    66,    31,
      75,    62,    75,    63,    79,    80,    87,    87,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    86,    26,
      27,    18,    88,    88,    55,    18,    18,    31,    18,    54,
      34,    31,    18,    86,    75,    19,    24,    84,    75,    19,
      86,    19,    64,    79,    90,    90,    75,    91,    34,    24,
      88,    32,    24,    31,    75,    56,    19,    75,    31,    75,
      19,    19,    88,     8,    32
};

  /* YYR1YYN -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    73,    74,    75,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    78,    78,    79,    79,    80,    81,    82,
      82,    83,    84,    84,    84,    84,    85,    85,    85,    86,
      86,    86,    86,    86,    86,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    92,    92,
      93,    93
};

  /* YYR2YYN -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     3,     7,     6,     1,     2,     4,
       1,     1,     1,     4,     6,     1,     2,     6,     4,     5,
       5,     5,     1,     2,     4,     1,     3,     3,     6,     1,
       4,     4,     1,     1,     1,     2,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       4,     1,     3,     3,     3,     3,     4,     4,     2,     3,
       3,     4,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yystacksize = YYINITDEPTH;
  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;


  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 51 "parser.y"
                          {
    if((yyvsp[-1].ast) != NULL){
        eval((yyvsp[-1].ast));
    }
    eval((yyvsp[0].ast));
    }
#line 1789 "parser.tab.c"
    break;

  case 3:
#line 59 "parser.y"
           { (yyval.ast) = NULL; }
#line 1795 "parser.tab.c"
    break;

  case 4:
#line 60 "parser.y"
                                { 
    if((yyvsp[-2].ast) == NULL){
        (yyval.ast) = (yyvsp[-1].ast);
    } else (yyval.ast) = newast(CMDLIST,(yyvsp[-2].ast),(yyvsp[-1].ast));
    }
#line 1805 "parser.tab.c"
    break;

  case 5:
#line 67 "parser.y"
                                                                   { 
    (yyval.ast) = newfunc((yyvsp[-6].symbol),(AST*)(yyvsp[-4].symlist),(yyvsp[-1].ast),NULL); prevscope(); }
#line 1812 "parser.tab.c"
    break;

  case 6:
#line 69 "parser.y"
                                         { (yyval.ast) = newfunc((yyvsp[-5].symbol),NULL,(yyvsp[-1].ast),NULL); prevscope(); }
#line 1818 "parser.tab.c"
    break;

  case 7:
#line 72 "parser.y"
                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1824 "parser.tab.c"
    break;

  case 8:
#line 73 "parser.y"
                           { (yyval.ast) = newflow(NULL,(yyvsp[-1].ast),NULL,NULL); }
#line 1830 "parser.tab.c"
    break;

  case 9:
#line 74 "parser.y"
                                          { (yyval.ast) = newflow(NULL,(yyvsp[-3].ast),(yyvsp[-1].ast),(yyvsp[-2].symbol)); }
#line 1836 "parser.tab.c"
    break;

  case 10:
#line 75 "parser.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 1842 "parser.tab.c"
    break;

  case 11:
#line 76 "parser.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1848 "parser.tab.c"
    break;

  case 12:
#line 77 "parser.y"
                    { (yyval.ast) = (yyvsp[0].ast); }
#line 1854 "parser.tab.c"
    break;

  case 13:
#line 80 "parser.y"
                                                        { (yyval.ast) = newflow((yyvsp[-3].ast),(yyvsp[-1].ast),NULL,NULL); }
#line 1860 "parser.tab.c"
    break;

  case 14:
#line 81 "parser.y"
                                                   { (yyval.ast) = newflow((yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[-1].ast),(yyvsp[-2].symbol));   prevscope();  }
#line 1866 "parser.tab.c"
    break;

  case 15:
#line 84 "parser.y"
                                  { (yyval.ast) = newast(IFLIST,(yyvsp[0].ast),NULL); }
#line 1872 "parser.tab.c"
    break;

  case 16:
#line 85 "parser.y"
                                   { (yyval.ast) = newast(IFLIST,(yyvsp[-1].ast),(yyvsp[0].ast)); }
#line 1878 "parser.tab.c"
    break;

  case 17:
#line 88 "parser.y"
                                                               {
    (yyval.ast) = newastscope(IF,(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[-5].symbol)); 
    prevscope();
    }
#line 1887 "parser.tab.c"
    break;

  case 18:
#line 94 "parser.y"
                                                   {
    (yyval.ast) = newastscope(IF,(yyvsp[-2].ast),(yyvsp[0].ast),(yyvsp[-3].symbol)); 
    prevscope();
    }
#line 1896 "parser.tab.c"
    break;

  case 19:
#line 100 "parser.y"
                                                    { (yyval.ast) = newastscope(WHILE,(yyvsp[-3].ast),(yyvsp[-1].ast),(yyvsp[-2].symbol)); prevscope();}
#line 1902 "parser.tab.c"
    break;

  case 20:
#line 101 "parser.y"
                                       { (yyval.ast) = newastscope(DO,(yyvsp[-1].ast),(yyvsp[-3].ast),(yyvsp[-4].symbol));  prevscope(); }
#line 1908 "parser.tab.c"
    break;

  case 21:
#line 104 "parser.y"
                                                    {(yyval.ast) = newastscope(UPDATEDEF,(yyvsp[-2].ast),(yyvsp[-1].ast),(yyvsp[-4].symbol)); prevscope();}
#line 1914 "parser.tab.c"
    break;

  case 22:
#line 107 "parser.y"
               { (yyval.ast) = newast(REPEAT,NULL,NULL);}
#line 1920 "parser.tab.c"
    break;

  case 23:
#line 108 "parser.y"
                   { (yyval.ast) = newast(REPEAT,(yyvsp[0].ast),NULL); }
#line 1926 "parser.tab.c"
    break;

  case 24:
#line 109 "parser.y"
                                   { (yyval.ast) = newast(REPEAT,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 1932 "parser.tab.c"
    break;

  case 25:
#line 110 "parser.y"
      { (yyval.ast) = newast(END,NULL,NULL); }
#line 1938 "parser.tab.c"
    break;

  case 26:
#line 113 "parser.y"
                               { (yyval.ast) = newasgn((yyvsp[-2].symref),(yyvsp[0].ast)); }
#line 1944 "parser.tab.c"
    break;

  case 27:
#line 114 "parser.y"
                              { (yyval.ast) = newsymasgn(findsymbol((yyvsp[-1].symbolname)),(yyvsp[0].ast)); }
#line 1950 "parser.tab.c"
    break;

  case 28:
#line 115 "parser.y"
                                             { (yyval.ast) = newsymasgn(findsymbol((yyvsp[-4].symbolname)),(AST*)(yyvsp[-1].varlist)); }
#line 1956 "parser.tab.c"
    break;

  case 29:
#line 118 "parser.y"
                   {(yyval.ast) = (yyvsp[0].ast); }
#line 1962 "parser.tab.c"
    break;

  case 30:
#line 119 "parser.y"
                        { (yyval.ast) = newbinfunc((yyvsp[-1].ast),2); }
#line 1968 "parser.tab.c"
    break;

  case 31:
#line 120 "parser.y"
                         { (yyval.ast) = newbinfunc((yyvsp[-1].ast),0); }
#line 1974 "parser.tab.c"
    break;

  case 32:
#line 121 "parser.y"
            { (yyval.ast) = (yyvsp[0].ast); }
#line 1980 "parser.tab.c"
    break;

  case 33:
#line 122 "parser.y"
            { (yyval.ast) = (yyvsp[0].ast); }
#line 1986 "parser.tab.c"
    break;

  case 34:
#line 123 "parser.y"
        { (yyval.ast) = newast(BREAK,NULL,NULL); }
#line 1992 "parser.tab.c"
    break;

  case 35:
#line 124 "parser.y"
                   { (yyval.ast) = newast(RETURN,(yyvsp[0].ast),NULL); }
#line 1998 "parser.tab.c"
    break;

  case 36:
#line 125 "parser.y"
                   { (yyval.ast) = newast(RETURN,(yyvsp[0].ast),NULL); }
#line 2004 "parser.tab.c"
    break;

  case 37:
#line 128 "parser.y"
                   { (yyval.ast) = (yyvsp[0].ast); }
#line 2010 "parser.tab.c"
    break;

  case 38:
#line 129 "parser.y"
                  { (yyval.ast) = (yyvsp[-1].ast); }
#line 2016 "parser.tab.c"
    break;

  case 39:
#line 130 "parser.y"
                          { (yyval.ast) = newast(AND,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 2022 "parser.tab.c"
    break;

  case 40:
#line 131 "parser.y"
                         { (yyval.ast) = newast(OR,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 2028 "parser.tab.c"
    break;

  case 41:
#line 132 "parser.y"
                                       { (yyval.ast) = newast(EQUALS,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 2034 "parser.tab.c"
    break;

  case 42:
#line 133 "parser.y"
                                   { (yyval.ast) = newast(NE,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 2040 "parser.tab.c"
    break;

  case 43:
#line 134 "parser.y"
                                   { (yyval.ast) = newast(LT,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 2046 "parser.tab.c"
    break;

  case 44:
#line 135 "parser.y"
                                   { (yyval.ast) = newast(GT,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 2052 "parser.tab.c"
    break;

  case 45:
#line 136 "parser.y"
                                   { (yyval.ast) = newast(GE,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 2058 "parser.tab.c"
    break;

  case 46:
#line 137 "parser.y"
                                   { (yyval.ast) = newast(LE,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 2064 "parser.tab.c"
    break;

  case 47:
#line 141 "parser.y"
                { (yyval.ast) = (AST*) (yyvsp[0].symref); }
#line 2070 "parser.tab.c"
    break;

  case 48:
#line 142 "parser.y"
         { (yyval.ast) = (yyvsp[0].ast); }
#line 2076 "parser.tab.c"
    break;

  case 49:
#line 143 "parser.y"
         { (yyval.ast) = (yyvsp[0].ast); }
#line 2082 "parser.tab.c"
    break;

  case 50:
#line 144 "parser.y"
                  { (yyval.ast) = newbinfunc((AST*)(yyvsp[-1].symref),1); }
#line 2088 "parser.tab.c"
    break;

  case 51:
#line 145 "parser.y"
               { (yyval.ast) = (yyvsp[0].ast); }
#line 2094 "parser.tab.c"
    break;

  case 52:
#line 146 "parser.y"
                          { (yyval.ast) = newast(ADD,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 2100 "parser.tab.c"
    break;

  case 53:
#line 147 "parser.y"
                          { (yyval.ast) = newast(SUB,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 2106 "parser.tab.c"
    break;

  case 54:
#line 148 "parser.y"
                          { (yyval.ast) = newast(DIV,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 2112 "parser.tab.c"
    break;

  case 55:
#line 149 "parser.y"
                          { (yyval.ast) = newast(MUL,(yyvsp[-2].ast),(yyvsp[0].ast)); }
#line 2118 "parser.tab.c"
    break;

  case 56:
#line 150 "parser.y"
                             { (yyval.ast) = newast(INCREASE,(AST*)(yyvsp[-2].symref),(yyvsp[0].ast)); }
#line 2124 "parser.tab.c"
    break;

  case 57:
#line 151 "parser.y"
                             { (yyval.ast) = newast(DECREASE,(AST*)(yyvsp[-2].symref),(yyvsp[0].ast)); }
#line 2130 "parser.tab.c"
    break;

  case 58:
#line 152 "parser.y"
                            { (yyval.ast) = newast(MIN,(yyvsp[0].ast),NULL); }
#line 2136 "parser.tab.c"
    break;

  case 59:
#line 153 "parser.y"
                    { (yyval.ast) = newast(ABS,(yyvsp[-1].ast),NULL); }
#line 2142 "parser.tab.c"
    break;

  case 60:
#line 154 "parser.y"
                  { (yyval.ast) = (yyvsp[-1].ast); }
#line 2148 "parser.tab.c"
    break;

  case 61:
#line 157 "parser.y"
                                       {
    char* id = strdup((yyvsp[-3].symbolname));
    strcat(id,"()");
    (yyval.ast) = newast(FCALL,(AST*)findsymbol(id),(AST*)(yyvsp[-1].varlist)); 
    }
#line 2158 "parser.tab.c"
    break;

  case 62:
#line 162 "parser.y"
                   {
    char* id = strdup((yyvsp[-2].symbolname));
    strcat(id,"()");
    (yyval.ast) = newast(FCALL,(AST*)findsymbol(id),NULL); 
    }
#line 2168 "parser.tab.c"
    break;

  case 63:
#line 169 "parser.y"
                    { (yyval.varlist) = newvarlist((yyvsp[0].ast),NULL); }
#line 2174 "parser.tab.c"
    break;

  case 64:
#line 170 "parser.y"
                           { (yyval.varlist) = newvarlist((yyvsp[-2].ast),(yyvsp[0].varlist)); }
#line 2180 "parser.tab.c"
    break;

  case 65:
#line 173 "parser.y"
                     { (yyval.symlist) = newsymlist(lookup((yyvsp[0].symbolname)),NULL); }
#line 2186 "parser.tab.c"
    break;

  case 66:
#line 174 "parser.y"
                            { (yyval.symlist) = newsymlist(lookup((yyvsp[-2].symbolname)),(yyvsp[0].symlist)); }
#line 2192 "parser.tab.c"
    break;

  case 67:
#line 177 "parser.y"
             { (yyval.symref) = (yyvsp[0].symref); }
#line 2198 "parser.tab.c"
    break;

  case 68:
#line 178 "parser.y"
                   { (yyvsp[-2].symref)->readingtype = -1; (yyval.symref) = (yyvsp[-2].symref); }
#line 2204 "parser.tab.c"
    break;

  case 69:
#line 179 "parser.y"
                    { (yyvsp[-2].symref)->readingtype = 1; (yyval.symref) = (yyvsp[-2].symref); }
#line 2210 "parser.tab.c"
    break;

  case 70:
#line 182 "parser.y"
                   {
    (yyval.symref) = newref(findsymbol((yyvsp[0].symbolname)),NULL); 
    }
#line 2218 "parser.tab.c"
    break;

  case 71:
#line 185 "parser.y"
                             { 
    (yyval.symref) = newref(findsymbol((yyvsp[-3].symbolname)),(yyvsp[-1].ast)); 
    }
#line 2226 "parser.tab.c"
    break;


#line 2230 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 191 "parser.y"
