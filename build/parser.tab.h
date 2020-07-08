/* A Bison parser, made by GNU Bison 3.6.2.  */

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

#line 145 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
