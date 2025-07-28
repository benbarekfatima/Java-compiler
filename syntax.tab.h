
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
#line 26 "syntax.y"

    float fval;
    int ival;
    char* str;
    char* res;
    struct {
        char* type;   // Contiendra le type (ex. "int", "float", etc.)
        char* value;  // Contiendra la valeur d'initialisation (ex. "5", "0.0", etc.)
    } attr;



/* Line 1676 of yacc.c  */
#line 134 "syntax.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


