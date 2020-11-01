/* A Bison parser, made by GNU Bison 3.7.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_P_TAB_H_INCLUDED
# define YY_YY_P_TAB_H_INCLUDED
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
    PROGRAM = 258,                 /* PROGRAM  */
    PROCEDURE = 259,               /* PROCEDURE  */
    IS = 260,                      /* IS  */
    OF = 261,                      /* OF  */
    BEGIN = 262,                   /* BEGIN  */
    END = 263,                     /* END  */
    EXIT = 264,                    /* EXIT  */
    IF = 265,                      /* IF  */
    THEN = 266,                    /* THEN  */
    ELSIF = 267,                   /* ELSIF  */
    ELSE = 268,                    /* ELSE  */
    WHILE = 269,                   /* WHILE  */
    DO = 270,                      /* DO  */
    LOOP = 271,                    /* LOOP  */
    FOR = 272,                     /* FOR  */
    TO = 273,                      /* TO  */
    BY = 274,                      /* BY  */
    RETURN = 275,                  /* RETURN  */
    RECORD = 276,                  /* RECORD  */
    TYPE = 277,                    /* TYPE  */
    ID = 278,                      /* ID  */
    READ = 279,                    /* READ  */
    WRITE = 280,                   /* WRITE  */
    STRING = 281,                  /* STRING  */
    INTEGER = 282,                 /* INTEGER  */
    REAL = 283,                    /* REAL  */
    NOT = 284,                     /* NOT  */
    VAR = 285,                     /* VAR  */
    ARRAY = 286,                   /* ARRAY  */
    DIV = 287,                     /* DIV  */
    MOD = 288,                     /* MOD  */
    OR = 289,                      /* OR  */
    AND = 290,                     /* AND  */
    ASSIGN = 291,                  /* ASSIGN  */
    OPEN_SQ_ANGL = 292,            /* OPEN_SQ_ANGL  */
    CLOSE_SQ_ANGL = 293,           /* CLOSE_SQ_ANGL  */
    NE_OP = 294,                   /* NE_OP  */
    GE_OP = 295,                   /* GE_OP  */
    LE_OP = 296                    /* LE_OP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_P_TAB_H_INCLUDED  */
