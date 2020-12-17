/* A Bison parser, made by GNU Bison 3.7.1.  */

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
#define YYBISON_VERSION "3.7.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "p.y"

    #include <stdio.h>
	#include "ast.h"

Node* astRoot = NULL;
int yyerror(char * s);
extern int yylex(void);


#line 81 "p.tab.c"

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

#include "p.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_PROCEDURE = 4,                  /* PROCEDURE  */
  YYSYMBOL_IS = 5,                         /* IS  */
  YYSYMBOL_OF = 6,                         /* OF  */
  YYSYMBOL_BEGINTEST = 7,                  /* BEGINTEST  */
  YYSYMBOL_END = 8,                        /* END  */
  YYSYMBOL_EXIT = 9,                       /* EXIT  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_THEN = 11,                      /* THEN  */
  YYSYMBOL_ELSIF = 12,                     /* ELSIF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_LOOP = 16,                      /* LOOP  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_TO = 18,                        /* TO  */
  YYSYMBOL_BY = 19,                        /* BY  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_RECORD = 21,                    /* RECORD  */
  YYSYMBOL_TYPE = 22,                      /* TYPE  */
  YYSYMBOL_ID = 23,                        /* ID  */
  YYSYMBOL_READ = 24,                      /* READ  */
  YYSYMBOL_WRITE = 25,                     /* WRITE  */
  YYSYMBOL_STRING = 26,                    /* STRING  */
  YYSYMBOL_INTEGER = 27,                   /* INTEGER  */
  YYSYMBOL_REAL = 28,                      /* REAL  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_VAR = 30,                       /* VAR  */
  YYSYMBOL_ARRAY = 31,                     /* ARRAY  */
  YYSYMBOL_MOD = 32,                       /* MOD  */
  YYSYMBOL_OR_OP = 33,                     /* OR_OP  */
  YYSYMBOL_ASSIGN = 34,                    /* ASSIGN  */
  YYSYMBOL_OPEN_SQ_ANGL = 35,              /* OPEN_SQ_ANGL  */
  YYSYMBOL_CLOSE_SQ_ANGL = 36,             /* CLOSE_SQ_ANGL  */
  YYSYMBOL_OPEN_BR = 37,                   /* OPEN_BR  */
  YYSYMBOL_CLOSE_BR = 38,                  /* CLOSE_BR  */
  YYSYMBOL_OPEN_SQUARE = 39,               /* OPEN_SQUARE  */
  YYSYMBOL_CLOSE_SQUARE = 40,              /* CLOSE_SQUARE  */
  YYSYMBOL_OPEN_CURLY = 41,                /* OPEN_CURLY  */
  YYSYMBOL_CLOSE_CURLY = 42,               /* CLOSE_CURLY  */
  YYSYMBOL_NE_OP = 43,                     /* NE_OP  */
  YYSYMBOL_GE_OP = 44,                     /* GE_OP  */
  YYSYMBOL_LE_OP = 45,                     /* LE_OP  */
  YYSYMBOL_GT_OP = 46,                     /* GT_OP  */
  YYSYMBOL_LT_OP = 47,                     /* LT_OP  */
  YYSYMBOL_EQ_OP = 48,                     /* EQ_OP  */
  YYSYMBOL_ADD = 49,                       /* ADD  */
  YYSYMBOL_SUB = 50,                       /* SUB  */
  YYSYMBOL_MUL = 51,                       /* MUL  */
  YYSYMBOL_DIV = 52,                       /* DIV  */
  YYSYMBOL_END_OF_INSTRUCTION = 53,        /* END_OF_INSTRUCTION  */
  YYSYMBOL_COLON = 54,                     /* COLON  */
  YYSYMBOL_COMMA = 55,                     /* COMMA  */
  YYSYMBOL_DOT = 56,                       /* DOT  */
  YYSYMBOL_AND_OP = 57,                    /* AND_OP  */
  YYSYMBOL_CONSTANT = 58,                  /* CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 59,            /* STRING_LITERAL  */
  YYSYMBOL_60_ = 60,                       /* '+'  */
  YYSYMBOL_61_ = 61,                       /* '-'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_body = 64,                      /* body  */
  YYSYMBOL_declaration_list = 65,          /* declaration_list  */
  YYSYMBOL_declaration = 66,               /* declaration  */
  YYSYMBOL_ID_list = 67,                   /* ID_list  */
  YYSYMBOL_68_var_decl = 68,               /* var-decl  */
  YYSYMBOL_simple_assign = 69,             /* simple_assign  */
  YYSYMBOL_70_type_decl = 70,              /* type-decl  */
  YYSYMBOL_71_procedure_decl = 71,         /* procedure-decl  */
  YYSYMBOL_type = 72,                      /* type  */
  YYSYMBOL_typename = 73,                  /* typename  */
  YYSYMBOL_component = 74,                 /* component  */
  YYSYMBOL_75_fp_section_list = 75,        /* fp-section_list  */
  YYSYMBOL_76_formal_params = 76,          /* formal-params  */
  YYSYMBOL_77_fp_section = 77,             /* fp-section  */
  YYSYMBOL_statement_list = 78,            /* statement_list  */
  YYSYMBOL_statement = 79,                 /* statement  */
  YYSYMBOL_80_write_expr_list = 80,        /* write-expr_list  */
  YYSYMBOL_81_write_params = 81,           /* write-params  */
  YYSYMBOL_82_write_expr = 82,             /* write-expr  */
  YYSYMBOL_expression = 83,                /* expression  */
  YYSYMBOL_lvalue_list = 84,               /* lvalue_list  */
  YYSYMBOL_lvalue = 85,                    /* lvalue  */
  YYSYMBOL_expression_list = 86,           /* expression_list  */
  YYSYMBOL_87_actual_params = 87,          /* actual-params  */
  YYSYMBOL_88_ID_expression_list = 88,     /* ID-expression_list  */
  YYSYMBOL_89_record_inits = 89,           /* record-inits  */
  YYSYMBOL_90_array_init_list = 90,        /* array-init_list  */
  YYSYMBOL_91_array_inits = 91,            /* array-inits  */
  YYSYMBOL_92_array_init = 92,             /* array-init  */
  YYSYMBOL_number = 93,                    /* number  */
  YYSYMBOL_94_unary_op = 94,               /* unary-op  */
  YYSYMBOL_95_binary_op = 95               /* binary-op  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   558

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  195

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   314


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
       2,     2,     2,    60,     2,    61,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   117,   117,   120,   123,   124,   125,   128,   129,   130,
     131,   134,   135,   138,   139,   142,   145,   148,   151,   152,
     155,   158,   161,   162,   165,   166,   169,   172,   173,   174,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   191,   192,   195,   196,   197,   200,   201,   204,
     205,   206,   207,   208,   209,   210,   211,   214,   215,   218,
     219,   220,   223,   224,   227,   228,   231,   232,   235,   238,
     239,   242,   245,   246,   249,   253,   254,   255,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "PROCEDURE",
  "IS", "OF", "BEGINTEST", "END", "EXIT", "IF", "THEN", "ELSIF", "ELSE",
  "WHILE", "DO", "LOOP", "FOR", "TO", "BY", "RETURN", "RECORD", "TYPE",
  "ID", "READ", "WRITE", "STRING", "INTEGER", "REAL", "NOT", "VAR",
  "ARRAY", "MOD", "OR_OP", "ASSIGN", "OPEN_SQ_ANGL", "CLOSE_SQ_ANGL",
  "OPEN_BR", "CLOSE_BR", "OPEN_SQUARE", "CLOSE_SQUARE", "OPEN_CURLY",
  "CLOSE_CURLY", "NE_OP", "GE_OP", "LE_OP", "GT_OP", "LT_OP", "EQ_OP",
  "ADD", "SUB", "MUL", "DIV", "END_OF_INSTRUCTION", "COLON", "COMMA",
  "DOT", "AND_OP", "CONSTANT", "STRING_LITERAL", "'+'", "'-'", "$accept",
  "program", "body", "declaration_list", "declaration", "ID_list",
  "var-decl", "simple_assign", "type-decl", "procedure-decl", "type",
  "typename", "component", "fp-section_list", "formal-params",
  "fp-section", "statement_list", "statement", "write-expr_list",
  "write-params", "write-expr", "expression", "lvalue_list", "lvalue",
  "expression_list", "actual-params", "ID-expression_list", "record-inits",
  "array-init_list", "array-inits", "array-init", "number", "unary-op",
  "binary-op", YY_NULLPTR
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
      43,    45
};
#endif

#define YYPACT_NINF (-79)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,     8,    17,   109,   -79,    26,    28,    40,    44,    24,
     -79,    56,   -79,   -79,   -79,    93,   -79,   -31,    40,   -79,
     -79,   533,   -79,    67,    21,   238,    83,   -79,    64,   238,
     238,   533,   238,   533,    95,   238,    84,    86,    91,   444,
     -79,     6,   -17,    94,   110,   128,    82,    53,   -79,   238,
     -79,   -79,   -79,    66,   290,   -30,   -79,   238,   -79,   -79,
      23,   139,   462,   160,   480,   102,   312,    54,   -79,   115,
       0,    88,   -79,   -79,   238,   238,   117,    89,   -79,   119,
      90,    92,   110,    28,   -79,   334,   238,   126,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   238,   398,   533,   533,    98,
     533,   105,   238,   -79,   -79,   233,   -79,   -12,   -79,   121,
      -2,   -79,   398,   -79,   355,   377,   -79,    28,    61,   -79,
      28,    28,   152,   -79,   -79,   398,   -22,   155,   131,   398,
     533,   533,   -79,   498,   -79,   203,   398,    87,    62,   -30,
     -79,   -79,   141,   -79,   -79,   -79,   -79,   -79,   157,   113,
     -79,   -79,   238,   238,   238,   114,   238,   -79,   398,   116,
     -30,   -79,   -79,   109,   -79,   155,   398,   269,   -79,   182,
     -79,   120,   140,    -7,   533,   -79,   238,   143,   -79,   516,
     398,   238,   127,   398,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     6,     1,     0,     0,     0,     0,     0,
       4,     0,    10,    20,     9,     0,    11,     0,     8,    13,
       2,    29,     5,     0,     0,     0,     0,    14,     0,     0,
       0,    29,     0,    29,     0,     0,    59,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,    59,    77,     0,
      74,    75,    76,     0,     0,    50,    49,     0,    12,    40,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     3,    28,     0,     0,     0,     0,    25,     0,
       0,     0,     0,     0,    16,     0,     0,     0,    54,    55,
      56,    82,    83,    90,    88,    89,    85,    86,    87,    78,
      79,    80,    81,    15,    84,     0,    52,    29,    29,     0,
      29,     0,     0,    41,    65,     0,    59,     0,    45,    47,
       0,    42,    48,    33,     0,     0,    61,     0,     0,    22,
       0,     0,     0,    18,    51,    72,     0,    69,     0,    53,
      34,    35,    36,     0,    38,     0,    62,     0,     0,    57,
      46,    44,     0,    30,    60,    26,    24,    23,     0,     0,
      19,    71,     0,     0,     0,     0,     0,    64,    63,     0,
      58,    47,    43,     6,    21,    70,    73,     0,    37,     0,
      32,     0,     0,     0,    29,    17,     0,     0,    68,     0,
      66,     0,     0,    67,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,    22,   -79,   170,   -79,   -79,   176,   -79,   -79,
     -79,    -1,   134,   -79,   -79,   -78,   -29,   -32,   -79,   -79,
      46,   -10,   -79,   -21,   -79,   165,   -79,   -79,   -79,   -79,
      51,   -79,   -79,   -79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,     9,    10,    17,    18,    19,    14,    12,
      46,    53,    82,   128,    43,    79,    39,    40,   120,    71,
     121,   122,   148,    55,   147,    68,   183,    89,   136,    90,
     137,    56,    57,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,   129,    62,    25,    64,    15,    77,    73,     1,    75,
      41,   116,    41,     3,   161,    54,   187,     4,    41,    60,
      61,    78,    63,    47,    26,    66,    76,    75,     5,    48,
      73,    21,    73,   162,   107,   188,   151,    49,   118,    85,
      74,    41,    44,    41,    76,    75,     6,   106,   117,    11,
     157,    13,    45,   152,     7,    91,    92,   115,    50,   119,
      51,    52,    76,    16,   124,   125,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   135,    47,   140,   141,
     104,   143,   133,    48,    77,   116,    41,    41,   -20,    41,
     -20,    49,   114,    23,   -20,   139,   149,    20,    24,   156,
     169,    86,   145,    67,    42,   146,    58,    87,    73,    73,
      47,    73,    50,     5,    51,    52,    48,    59,    65,    41,
      41,    67,    41,    69,    49,   167,   155,   170,    70,   158,
     159,     6,    80,    81,    83,    84,   112,   168,   116,     7,
     126,   123,    77,   127,   130,    50,   131,    51,    52,   138,
     108,   142,   135,   176,   177,   189,   179,    73,   144,   150,
     160,   163,   173,    41,    47,   164,   174,   178,    41,   180,
      48,    91,    92,   185,   186,   110,   190,   191,    49,    22,
     194,   193,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    91,    92,    27,   181,   104,   184,   172,    50,
     171,    51,    52,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   175,    91,    92,   132,   104,    88,     0,
       0,   166,     0,     0,     0,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    91,    92,     0,     0,   104,
       0,     0,     0,     0,     0,     0,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    47,     0,     0,     0,
     104,    47,    48,     0,     0,    91,    92,    48,     0,     0,
      49,     0,     0,     0,     0,    49,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,     0,     0,     0,     0,
     104,    50,   182,    51,    52,     0,    50,     0,    51,    52,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    91,    92,     0,     0,   104,     0,     0,     0,
       0,     0,     0,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    91,    92,     0,   104,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   113,    91,    92,     0,   104,
       0,     0,   134,     0,     0,     0,     0,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    91,    92,     0,
       0,   104,     0,     0,     0,     0,     0,     0,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   153,    91,
      92,     0,   104,     0,     0,     0,     0,   154,     0,     0,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      91,    92,     0,     0,   104,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,     0,    72,    28,    29,   104,    30,    31,    32,     0,
      33,    34,     0,     0,    35,     0,     0,    36,    37,    38,
     109,    28,    29,     0,    30,    31,    32,     0,    33,    34,
       0,     0,    35,     0,     0,    36,    37,    38,   111,    28,
      29,     0,    30,    31,    32,     0,    33,    34,     0,     0,
      35,     0,     0,    36,    37,    38,   165,    28,    29,     0,
      30,    31,    32,     0,    33,    34,     0,     0,    35,     0,
       0,    36,    37,    38,   192,    28,    29,     0,    30,    31,
      32,     0,    33,    34,     0,     0,    35,     0,     0,    36,
      37,    38,    28,    29,     0,    30,    31,    32,     0,    33,
      34,     0,     0,    35,     0,     0,    36,    37,    38
};

static const yytype_int16 yycheck[] =
{
      21,    79,    31,    34,    33,     6,    23,    39,     3,    39,
      31,    23,    33,     5,    36,    25,    23,     0,    39,    29,
      30,    38,    32,    23,    55,    35,    56,    39,     4,    29,
      62,     7,    64,    55,    11,    42,    38,    37,    38,    49,
      34,    62,    21,    64,    56,    39,    22,    57,    69,    23,
     128,    23,    31,    55,    30,    32,    33,    67,    58,    59,
      60,    61,    56,    23,    74,    75,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    86,    23,   107,   108,
      57,   110,    83,    29,    23,    23,   107,   108,    35,   110,
      37,    37,    38,    37,    41,   105,   117,    53,     5,    38,
      38,    35,   112,    37,    37,   115,    23,    41,   140,   141,
      23,   143,    58,     4,    60,    61,    29,    53,    23,   140,
     141,    37,   143,    37,    37,    38,   127,   148,    37,   130,
     131,    22,    38,    23,     6,    53,    34,   147,    23,    30,
      23,    53,    23,    54,    54,    58,    54,    60,    61,    23,
      11,    53,   162,   163,   164,   184,   166,   189,    53,    38,
       8,     6,     5,   184,    23,    34,    53,    53,   189,    53,
      29,    32,    33,    53,    34,    15,   186,    34,    37,     9,
      53,   191,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    32,    33,    18,   173,    57,    15,   152,    58,
      59,    60,    61,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,   162,    32,    33,    82,    57,    53,    -1,
      -1,    18,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    32,    33,    -1,    -1,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    23,    -1,    -1,    -1,
      57,    23,    29,    -1,    -1,    32,    33,    29,    -1,    -1,
      37,    -1,    -1,    -1,    -1,    37,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      57,    58,    23,    60,    61,    -1,    58,    -1,    60,    61,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    32,    33,    -1,    -1,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    32,    33,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    32,    33,    -1,    57,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    32,    33,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    32,
      33,    -1,    57,    -1,    -1,    -1,    -1,    40,    -1,    -1,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      32,    33,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    -1,     8,     9,    10,    57,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    20,    -1,    -1,    23,    24,    25,
       8,     9,    10,    -1,    12,    13,    14,    -1,    16,    17,
      -1,    -1,    20,    -1,    -1,    23,    24,    25,     8,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    -1,    -1,
      20,    -1,    -1,    23,    24,    25,     8,     9,    10,    -1,
      12,    13,    14,    -1,    16,    17,    -1,    -1,    20,    -1,
      -1,    23,    24,    25,     8,     9,    10,    -1,    12,    13,
      14,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,    23,
      24,    25,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    -1,    -1,    20,    -1,    -1,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    63,     5,     0,     4,    22,    30,    64,    65,
      66,    23,    71,    23,    70,    73,    23,    67,    68,    69,
      53,     7,    66,    37,     5,    34,    55,    69,     9,    10,
      12,    13,    14,    16,    17,    20,    23,    24,    25,    78,
      79,    85,    37,    76,    21,    31,    72,    23,    29,    37,
      58,    60,    61,    73,    83,    85,    93,    94,    23,    53,
      83,    83,    78,    83,    78,    23,    83,    37,    87,    37,
      37,    81,     8,    79,    34,    39,    56,    23,    38,    77,
      38,    23,    74,     6,    53,    83,    35,    41,    87,    89,
      91,    32,    33,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    57,    95,    83,    11,    11,     8,
      15,     8,    34,    53,    38,    83,    23,    85,    38,    59,
      80,    82,    83,    53,    83,    83,    23,    54,    75,    77,
      54,    54,    74,    73,    38,    83,    90,    92,    23,    83,
      78,    78,    53,    78,    53,    83,    83,    86,    84,    85,
      38,    38,    55,    53,    40,    73,    38,    77,    73,    73,
       8,    36,    55,     6,    34,     8,    18,    38,    83,    38,
      85,    59,    82,     5,    53,    92,    83,    83,    53,    83,
      53,    64,    23,    88,    15,    53,    34,    23,    42,    78,
      83,    34,     8,    83,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    65,    65,    65,    66,    66,    66,
      66,    67,    67,    68,    68,    69,    70,    71,    72,    72,
      73,    74,    75,    75,    76,    76,    77,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    80,    80,    81,    81,    81,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    84,    84,    85,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    90,
      90,    91,    92,    92,    93,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     4,     1,     2,     0,     0,     2,     2,
       2,     1,     3,     1,     2,     4,     4,     9,     3,     4,
       1,     4,     1,     2,     4,     2,     3,     1,     2,     0,
       4,     2,     6,     3,     4,     4,     4,     6,     4,    10,
       2,     3,     1,     3,     3,     2,     3,     1,     1,     1,
       1,     3,     2,     3,     2,     2,     2,     1,     2,     1,
       4,     3,     1,     2,     4,     2,     3,     4,     6,     1,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

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
  case 2: /* program: PROGRAM IS body END_OF_INSTRUCTION  */
#line 117 "p.y"
                                                                        { (yyval.node) = createProgramNode((yyvsp[-1].node)); astRoot = (yyval.node); }
#line 1371 "p.tab.c"
    break;

  case 3: /* body: declaration_list BEGINTEST statement_list END  */
#line 120 "p.y"
                                                          { (yyval.node) = createBodyNode((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1377 "p.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 123 "p.y"
                                                                                { (yyval.node) = createListNode("Declaration", (yyvsp[0].node)); }
#line 1383 "p.tab.c"
    break;

  case 5: /* declaration_list: declaration_list declaration  */
#line 124 "p.y"
                                                                        { (yyval.node) = (yyvsp[-1].node); addLinkToList((yyval.node), (yyvsp[0].node));}
#line 1389 "p.tab.c"
    break;

  case 6: /* declaration_list: %empty  */
#line 125 "p.y"
                                                                                                                { (yyval.node) = createDeclarationNode(NULL); }
#line 1395 "p.tab.c"
    break;

  case 8: /* declaration: VAR var-decl  */
#line 129 "p.y"
                                                                                                { (yyval.node) = createDeclarationNode((yyvsp[0].node));}
#line 1401 "p.tab.c"
    break;

  case 9: /* declaration: TYPE type-decl  */
#line 130 "p.y"
                                                                                                { (yyval.node) = createDeclarationNode((yyvsp[0].node));}
#line 1407 "p.tab.c"
    break;

  case 10: /* declaration: PROCEDURE procedure-decl  */
#line 131 "p.y"
                                                                                        { (yyval.node) = createDeclarationNode((yyvsp[0].node));}
#line 1413 "p.tab.c"
    break;

  case 11: /* ID_list: ID  */
#line 134 "p.y"
                                                        { (yyval.node) = createIdList((yyvsp[0].strings)); }
#line 1419 "p.tab.c"
    break;

  case 12: /* ID_list: ID_list COMMA ID  */
#line 135 "p.y"
                                                                                        { (yyval.node) = (yyvsp[-2].node); addIdToList((yyvsp[-2].node), (yyvsp[0].strings));}
#line 1425 "p.tab.c"
    break;

  case 13: /* var-decl: simple_assign  */
#line 138 "p.y"
                                                        { (yyval.node) = createVarDeclarationList((yyvsp[0].node)); }
#line 1431 "p.tab.c"
    break;

  case 14: /* var-decl: var-decl simple_assign  */
#line 139 "p.y"
                                                                { (yyval.node) = (yyvsp[-1].node); addLinkToList((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1437 "p.tab.c"
    break;

  case 15: /* simple_assign: ID_list ASSIGN expression END_OF_INSTRUCTION  */
#line 142 "p.y"
                                                                  { (yyval.node) = createSimpleAssign((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1443 "p.tab.c"
    break;

  case 16: /* type-decl: typename IS type END_OF_INSTRUCTION  */
#line 145 "p.y"
                                                                  { (yyval.node) = createTypeDeclaration((yyvsp[-3].node), (yyvsp[-1].node));}
#line 1449 "p.tab.c"
    break;

  case 17: /* procedure-decl: ID OPEN_BR formal-params CLOSE_BR COLON typename IS body END_OF_INSTRUCTION  */
#line 148 "p.y"
                                                                                                    { (yyval.node) = createProcedureDeclaration((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1455 "p.tab.c"
    break;

  case 18: /* type: ARRAY OF typename  */
#line 151 "p.y"
                                                        { (yyval.node) = createType(NULL, (yyvsp[0].node), "ARRAY OF");}
#line 1461 "p.tab.c"
    break;

  case 19: /* type: RECORD component component END  */
#line 152 "p.y"
                                                            { (yyval.node) = createType((yyvsp[-2].node), (yyvsp[-1].node), "RECORD");}
#line 1467 "p.tab.c"
    break;

  case 20: /* typename: ID  */
#line 155 "p.y"
                                                        { (yyval.node) = createTypename((yyvsp[0].strings));}
#line 1473 "p.tab.c"
    break;

  case 21: /* component: ID COLON typename END_OF_INSTRUCTION  */
#line 158 "p.y"
                                                       { (yyval.node) = createComponent((yyvsp[-1].node)); }
#line 1479 "p.tab.c"
    break;

  case 22: /* fp-section_list: fp-section  */
#line 161 "p.y"
                                                                   { (yyval.node) = createListNode("FormalParameter", (yyvsp[0].node)); }
#line 1485 "p.tab.c"
    break;

  case 23: /* fp-section_list: fp-section_list fp-section  */
#line 162 "p.y"
                                                                                                   { (yyval.node) = (yyvsp[-1].node); addLinkToList((yyval.node), (yyvsp[0].node)); }
#line 1491 "p.tab.c"
    break;

  case 24: /* formal-params: OPEN_BR fp-section fp-section_list CLOSE_BR  */
#line 165 "p.y"
                                                                    { (yyval.node) = createFormalParameters((yyvsp[-2].node), (yyvsp[-1].node)); }
#line 1497 "p.tab.c"
    break;

  case 25: /* formal-params: OPEN_BR CLOSE_BR  */
#line 166 "p.y"
                                                                        { (yyval.node) = createFormalParameters(NULL, NULL); }
#line 1503 "p.tab.c"
    break;

  case 26: /* fp-section: ID COLON typename  */
#line 169 "p.y"
                                                                    { (yyval.node) = createFpSection((yyvsp[0].node));}
#line 1509 "p.tab.c"
    break;

  case 27: /* statement_list: statement  */
#line 172 "p.y"
                                                                   { (yyval.node) = createListNode("Statement", (yyvsp[0].node)); }
#line 1515 "p.tab.c"
    break;

  case 28: /* statement_list: statement_list statement  */
#line 173 "p.y"
                                                                                                           { (yyval.node) = (yyvsp[-1].node); addLinkToList((yyval.node), (yyvsp[0].node));}
#line 1521 "p.tab.c"
    break;

  case 29: /* statement_list: %empty  */
#line 174 "p.y"
                                                                                   { (yyval.node) = NULL;}
#line 1527 "p.tab.c"
    break;

  case 30: /* statement: lvalue ASSIGN expression END_OF_INSTRUCTION  */
#line 177 "p.y"
                                                                                                                        { (yyval.node) = createLvalueStatement((yyvsp[-3].node), (yyvsp[-1].node));}
#line 1533 "p.tab.c"
    break;

  case 31: /* statement: ID actual-params  */
#line 178 "p.y"
                                                                                            { (yyval.node) = createIDStatement((yyvsp[-1].strings), (yyvsp[0].node));}
#line 1539 "p.tab.c"
    break;

  case 32: /* statement: READ OPEN_BR lvalue lvalue_list CLOSE_BR END_OF_INSTRUCTION  */
#line 179 "p.y"
                                                                                                { (yyval.node) = createReadStatement((yyvsp[-3].node), (yyvsp[-2].node));}
#line 1545 "p.tab.c"
    break;

  case 33: /* statement: WRITE write-params END_OF_INSTRUCTION  */
#line 180 "p.y"
                                                                                                                                        { (yyval.node) = createWriteStatement((yyvsp[-1].node));}
#line 1551 "p.tab.c"
    break;

  case 34: /* statement: IF expression THEN statement_list  */
#line 181 "p.y"
                                                                                                                                        { (yyval.node) = createIfStatement((yyvsp[-2].node), (yyvsp[0].node));}
#line 1557 "p.tab.c"
    break;

  case 35: /* statement: ELSIF expression THEN statement_list  */
#line 182 "p.y"
                                                                                                                                        { (yyval.node) = createElsIfStatement((yyvsp[-2].node), (yyvsp[0].node));}
#line 1563 "p.tab.c"
    break;

  case 36: /* statement: ELSE statement_list END END_OF_INSTRUCTION  */
#line 183 "p.y"
                                                                                            { (yyval.node) = createElseStatement((yyvsp[-2].node));}
#line 1569 "p.tab.c"
    break;

  case 37: /* statement: WHILE expression DO statement_list END END_OF_INSTRUCTION  */
#line 184 "p.y"
                                                                                            { (yyval.node) = createWhileStatement((yyvsp[-4].node), (yyvsp[-2].node));}
#line 1575 "p.tab.c"
    break;

  case 38: /* statement: LOOP statement_list END END_OF_INSTRUCTION  */
#line 185 "p.y"
                                                                                            { (yyval.node) = createLoopStatement((yyvsp[-2].node));}
#line 1581 "p.tab.c"
    break;

  case 39: /* statement: FOR ID ASSIGN expression TO expression DO statement_list END END_OF_INSTRUCTION  */
#line 186 "p.y"
                                                                                                    { (yyval.node) = createForStatement((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node));}
#line 1587 "p.tab.c"
    break;

  case 40: /* statement: EXIT END_OF_INSTRUCTION  */
#line 187 "p.y"
                                                                                            { (yyval.node) = NULL;}
#line 1593 "p.tab.c"
    break;

  case 41: /* statement: RETURN expression END_OF_INSTRUCTION  */
#line 188 "p.y"
                                                                                                                                        { (yyval.node) = createReturnStatement((yyvsp[-1].node));}
#line 1599 "p.tab.c"
    break;

  case 42: /* write-expr_list: write-expr  */
#line 191 "p.y"
                                                                  { (yyval.node) = createListNode("WriteExpressions", (yyvsp[0].node)); }
#line 1605 "p.tab.c"
    break;

  case 43: /* write-expr_list: write-expr_list COMMA write-expr  */
#line 192 "p.y"
                                                                                  { (yyval.node) = (yyvsp[-2].node); addLinkToList((yyval.node), (yyvsp[0].node));}
#line 1611 "p.tab.c"
    break;

  case 44: /* write-params: OPEN_BR write-expr_list CLOSE_BR  */
#line 195 "p.y"
                                                                  { (yyval.node) = createWriteParameters((yyvsp[-1].node));}
#line 1617 "p.tab.c"
    break;

  case 45: /* write-params: OPEN_BR CLOSE_BR  */
#line 196 "p.y"
                                                                                                                  { (yyval.node) =  NULL;}
#line 1623 "p.tab.c"
    break;

  case 46: /* write-params: OPEN_BR STRING_LITERAL CLOSE_BR  */
#line 197 "p.y"
                                                                      { (yyval.node) = createStringLiteral((yyvsp[-1].strings));}
#line 1629 "p.tab.c"
    break;

  case 47: /* write-expr: STRING_LITERAL  */
#line 200 "p.y"
                                                                  { (yyval.node) = NULL;}
#line 1635 "p.tab.c"
    break;

  case 48: /* write-expr: expression  */
#line 201 "p.y"
                                                                                                                  { (yyval.node) = createWriteExpressions((yyvsp[0].node));}
#line 1641 "p.tab.c"
    break;

  case 49: /* expression: number  */
#line 204 "p.y"
                                                                  { (yyval.node) = createNumberExpression((yyvsp[0].node));}
#line 1647 "p.tab.c"
    break;

  case 50: /* expression: lvalue  */
#line 205 "p.y"
                                                                                                                          { (yyval.node) = createLvalueExpression((yyvsp[0].node));}
#line 1653 "p.tab.c"
    break;

  case 51: /* expression: OPEN_BR expression CLOSE_BR  */
#line 206 "p.y"
                                                                      { (yyval.node) = createExpression((yyvsp[-1].node));}
#line 1659 "p.tab.c"
    break;

  case 52: /* expression: unary-op expression  */
#line 207 "p.y"
                                                                                                          { (yyval.node) = createUnaryExpression((yyvsp[-1].node), (yyvsp[0].node));}
#line 1665 "p.tab.c"
    break;

  case 53: /* expression: expression binary-op expression  */
#line 208 "p.y"
                                                                                                  { (yyval.node) = createBinaryExpression((yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1671 "p.tab.c"
    break;

  case 54: /* expression: typename actual-params  */
#line 209 "p.y"
                                                                                                          { (yyval.node) = createActualParametersExpression((yyvsp[-1].node), (yyvsp[0].node));}
#line 1677 "p.tab.c"
    break;

  case 55: /* expression: typename record-inits  */
#line 210 "p.y"
                                                                      { (yyval.node) = createRecordInitsExpression((yyvsp[-1].node), (yyvsp[0].node));}
#line 1683 "p.tab.c"
    break;

  case 56: /* expression: typename array-inits  */
#line 211 "p.y"
                                                                      { (yyval.node) = createArrayInitsExpression((yyvsp[-1].node), (yyvsp[0].node));}
#line 1689 "p.tab.c"
    break;

  case 57: /* lvalue_list: lvalue  */
#line 214 "p.y"
                                                                  { (yyval.node) = createListNode("Lvalues", (yyvsp[0].node)); }
#line 1695 "p.tab.c"
    break;

  case 58: /* lvalue_list: lvalue_list lvalue  */
#line 215 "p.y"
                                                                              { (yyval.node) = (yyvsp[-1].node); addLinkToList((yyval.node), (yyvsp[0].node));}
#line 1701 "p.tab.c"
    break;

  case 59: /* lvalue: ID  */
#line 218 "p.y"
                                                                  { (yyval.node) = createLvalue((yyvsp[0].strings), NULL, NULL);}
#line 1707 "p.tab.c"
    break;

  case 60: /* lvalue: lvalue OPEN_SQUARE expression CLOSE_SQUARE  */
#line 219 "p.y"
                                                                                  { (yyval.node) = createLvalue(NULL, (yyvsp[-3].node), (yyvsp[-1].node));}
#line 1713 "p.tab.c"
    break;

  case 61: /* lvalue: lvalue DOT ID  */
#line 220 "p.y"
                                                                                                                  { (yyval.node) = createLvalue((yyvsp[0].strings), (yyvsp[-2].node), NULL);}
#line 1719 "p.tab.c"
    break;

  case 62: /* expression_list: expression  */
#line 223 "p.y"
                                                                                                          { (yyval.node) = createListNode("Expressions", (yyvsp[0].node)); }
#line 1725 "p.tab.c"
    break;

  case 63: /* expression_list: expression_list expression  */
#line 224 "p.y"
                                                                                      { (yyval.node) = (yyvsp[-1].node); addLinkToList((yyval.node), (yyvsp[0].node));}
#line 1731 "p.tab.c"
    break;

  case 64: /* actual-params: OPEN_BR expression expression_list CLOSE_BR  */
#line 227 "p.y"
                                                                  { (yyval.node) = createActualParameters((yyvsp[-2].node), (yyvsp[-1].node));}
#line 1737 "p.tab.c"
    break;

  case 65: /* actual-params: OPEN_BR CLOSE_BR  */
#line 228 "p.y"
                                                                                                          { (yyval.node) = NULL;}
#line 1743 "p.tab.c"
    break;

  case 66: /* ID-expression_list: ID ASSIGN expression  */
#line 231 "p.y"
                                                                  { (yyval.node) = createListNode("IdentifierExpressions", (yyvsp[0].node)); }
#line 1749 "p.tab.c"
    break;

  case 67: /* ID-expression_list: ID-expression_list ID ASSIGN expression  */
#line 232 "p.y"
                                                                                      { (yyval.node) = (yyvsp[-3].node); addLinkToList((yyval.node), (yyvsp[0].node));}
#line 1755 "p.tab.c"
    break;

  case 68: /* record-inits: OPEN_CURLY ID ASSIGN expression ID-expression_list CLOSE_CURLY  */
#line 235 "p.y"
                                                                                     { (yyval.node) = createRecordInits((yyvsp[-4].strings), (yyvsp[-2].node), (yyvsp[-1].node));}
#line 1761 "p.tab.c"
    break;

  case 69: /* array-init_list: array-init  */
#line 238 "p.y"
                                                                  { (yyval.node) = createListNode("ArrayInit", (yyvsp[0].node)); }
#line 1767 "p.tab.c"
    break;

  case 70: /* array-init_list: array-init_list COMMA array-init  */
#line 239 "p.y"
                                                                                  { (yyval.node) = (yyvsp[-2].node); addLinkToList((yyval.node), (yyvsp[0].node));}
#line 1773 "p.tab.c"
    break;

  case 71: /* array-inits: OPEN_SQ_ANGL array-init_list CLOSE_SQ_ANGL  */
#line 242 "p.y"
                                                                  { (yyval.node) = createArrayInits((yyvsp[-1].node));}
#line 1779 "p.tab.c"
    break;

  case 72: /* array-init: expression  */
#line 245 "p.y"
                                                                  { (yyval.node) = createArrayInit((yyvsp[0].node), NULL);}
#line 1785 "p.tab.c"
    break;

  case 73: /* array-init: array-init OF expression  */
#line 246 "p.y"
                                                                                                          { (yyval.node) = createArrayInit((yyvsp[-2].node), (yyvsp[0].node));}
#line 1791 "p.tab.c"
    break;

  case 74: /* number: CONSTANT  */
#line 249 "p.y"
                                                                  { (yyval.node) = createNumber((yyvsp[0].intVal));}
#line 1797 "p.tab.c"
    break;

  case 75: /* unary-op: '+'  */
#line 253 "p.y"
                                                                  {(yyval.node) = createUnaryOp("+");}
#line 1803 "p.tab.c"
    break;

  case 76: /* unary-op: '-'  */
#line 254 "p.y"
                                                                          {(yyval.node) = createUnaryOp("-");}
#line 1809 "p.tab.c"
    break;

  case 77: /* unary-op: NOT  */
#line 255 "p.y"
                                                                          {(yyval.node) = createUnaryOp("NOT");}
#line 1815 "p.tab.c"
    break;

  case 78: /* binary-op: ADD  */
#line 258 "p.y"
                                                                  {(yyval.node) = createBinaryOp("ADD");}
#line 1821 "p.tab.c"
    break;

  case 79: /* binary-op: SUB  */
#line 259 "p.y"
                                                                                                                          {(yyval.node) = createBinaryOp("SUB");}
#line 1827 "p.tab.c"
    break;

  case 80: /* binary-op: MUL  */
#line 260 "p.y"
                                                                      {(yyval.node) = createBinaryOp("MUL");}
#line 1833 "p.tab.c"
    break;

  case 81: /* binary-op: DIV  */
#line 261 "p.y"
                                                                      {(yyval.node) = createBinaryOp("DIV");}
#line 1839 "p.tab.c"
    break;

  case 82: /* binary-op: MOD  */
#line 262 "p.y"
                                                                      {(yyval.node) = createBinaryOp("MOD");}
#line 1845 "p.tab.c"
    break;

  case 83: /* binary-op: OR_OP  */
#line 263 "p.y"
                                                                      {(yyval.node) = createBinaryOp("OR_OP");}
#line 1851 "p.tab.c"
    break;

  case 84: /* binary-op: AND_OP  */
#line 264 "p.y"
                                                                      {(yyval.node) = createBinaryOp("AND_OP");}
#line 1857 "p.tab.c"
    break;

  case 85: /* binary-op: GT_OP  */
#line 265 "p.y"
                                                                      {(yyval.node) = createBinaryOp("GT_OP");}
#line 1863 "p.tab.c"
    break;

  case 86: /* binary-op: LT_OP  */
#line 266 "p.y"
                                                                      {(yyval.node) = createBinaryOp("LT_OP");}
#line 1869 "p.tab.c"
    break;

  case 87: /* binary-op: EQ_OP  */
#line 267 "p.y"
                                                                      {(yyval.node) = createBinaryOp("EQ_OP");}
#line 1875 "p.tab.c"
    break;

  case 88: /* binary-op: GE_OP  */
#line 268 "p.y"
                                                                      {(yyval.node) = createBinaryOp("GE_OP");}
#line 1881 "p.tab.c"
    break;

  case 89: /* binary-op: LE_OP  */
#line 269 "p.y"
                                                                      {(yyval.node) = createBinaryOp("LE_OP");}
#line 1887 "p.tab.c"
    break;

  case 90: /* binary-op: NE_OP  */
#line 270 "p.y"
                                                                      {(yyval.node) = createBinaryOp("NE_OP");}
#line 1893 "p.tab.c"
    break;


#line 1897 "p.tab.c"

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
      yyerror (YY_("syntax error"));
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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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

  return yyresult;
}

#line 272 "p.y"


int yyerror(char * s) 
/* yacc error handler */
{    
	printf ( "%s\n", s); 
	return 0;
}  
