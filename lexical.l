%{
    #include "syntax.tab.h"
    #include"TS.h"
    extern YYSTYPE yylval;
    #include <stdio.h>
    #include <stdlib.h>
    int nb_ligne = 1, col=1;
%}

alpha               [a-zA-Z]
numeric             [0-9]
alpha_num           {alpha}|{numeric}
decimal             [1-9][0-9]*[lL]?|0[lL]?
binary              0[bB][0-1]+[lL]?
octal               0[0-7]*[lL]?
hexadecimal         0[xX][0-9a-fA-F]+[lL]?

real                [0-9]+(\.[0-9]*)?([eE][+-]?[0-9]+)?[fF]?
integer             {decimal}|{binary}|{octal}|{hexadecimal}
caractere           \'(\\.|[^'])\'
chaine              \"(\\.|[^"])*\"
id                  ({alpha}|_|$)({alpha_num}|_|$)*

line_comment        \/\/.*
multi_line_comment  \/\*([^*]*|\*[^/]+)*\*\/


%%

                            /* ====== Mots-clés ======    "on envoit les valeurs par yylval ici pour les mc de type"    */
"class"          { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext);  
                    // printf("Mot-clé: class \n");  
                    return mc_class; }
"int"            { insert_sep_kw(yytext, "kw"); yylval.str=strdup(yytext); col = col + strlen(yytext); 
                 //printf("Mot-clé: int \n");  
                 return mc_int; }
"float"          { insert_sep_kw(yytext, "kw"); yylval.str=strdup(yytext); col = col + strlen(yytext);  
                    // printf("Mot-clé: float \n");  
                    return mc_float; }
"double"         { insert_sep_kw(yytext, "kw"); yylval.str=strdup(yytext); col = col + strlen(yytext);  
                    // printf("Mot-clé: double \n");  
                    return mc_double; }
"char"           { insert_sep_kw(yytext, "kw"); yylval.str=strdup(yytext); col = col + strlen(yytext); 
                    // printf("Mot-clé: char \n");  
                    return mc_char; }
"boolean"        { insert_sep_kw(yytext, "kw"); yylval.str=strdup(yytext); col = col + strlen(yytext); 
                    // printf("Mot-clé: boolean \n"); 
                     return mc_boolean; }
"String"         { insert_sep_kw(yytext, "kw"); yylval.str=strdup(yytext); col = col + strlen(yytext);  
                    // printf("Mot-clé: String \n");  
                    return mc_string; }
"Exception"      { insert_idf_cst(yytext, "CLASS", "", "0", current_scope(), 1); yylval.str=strdup(yytext); col = col + strlen(yytext); 
                // printf("Mot-clé 'Exception'\n");  
                return mc_excp; }

"if"             { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé: if \n");  
                    return mc_if; }
"else"           { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext);  
                    // printf("Mot-clé: else \n"); 
                     return mc_else; }
"for"            { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext);
                    //  printf("Mot-clé: for \n"); 
                     return mc_for; }
"while"          { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext);
                    //  printf("Mot-clé: while \n"); 
                     return mc_while; }
"do"             { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé: do \n"); 
                     return mc_do; }
"switch"         { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé: switch \n"); 
                     return mc_switch; }
"case"           { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext);
                    //  printf("Mot-clé: case \n"); 
                     return mc_case; }
"default"        { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé: default\n"); 
                    return mc_default; }
"break"          { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext);
                    //  printf("Mot-clé: break\n");
                     return mc_break; }

"return"         { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé: return \n");  
                    return mc_return; }
"public"         { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext);  
                    //printf("Mot-clé: public \n"); 
                     return mc_public; }
"static"         { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé: static \n"); 
                     return mc_static; }
"void"           { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé: void \n"); 
                     return mc_void; }
"private"        { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé: private \n"); 
                     return mc_private; }
"protected"      { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé: protected \n"); 
                     return mc_protected; }

"try"            { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé 'try'\n"); 
                     return mc_try; }
"catch"          { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé 'catch'\n");  
                    return mc_catch; }
"finally"        { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé 'finally'\n"); 
                     return mc_finally; }
"new"            { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé 'new'\n"); 
                     return mc_new; }
"throws"         { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé: throws\n");
                     return mc_throws; }
"throw"          { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé: throw\n"); 
                    return mc_throw; }
"this"           { insert_sep_kw(yytext, "kw"); yylval.str=strdup(yytext); col = col + strlen(yytext);
                    // printf("Mot-clé: this\n");
                     return mc_this; }

"true"           { insert_sep_kw(yytext, "kw"); yylval.str=strdup(yytext); col = col + strlen(yytext);
                    //  printf("Valeur booléenne 'true'\n"); 
                     return mc_true; }
"false"          { insert_sep_kw(yytext, "kw"); yylval.str=strdup(yytext); col = col + strlen(yytext);
                    //  printf("Valeur booléenne 'false'\n"); 
                     return mc_false; }
"System.out.println" { insert_sep_kw(yytext, "kw"); col = col + strlen(yytext); 
                    // printf("Mot-clé 'System.out.println'\n");
                      return mc_print; }


                        /* ====== Opérateurs ====== */
"+"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur: + \n");  
                    return addition; }
"-"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur: - \n"); 
                     return soustraction; }
"*"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur: * \n");  
                    return multiplication; }
"/"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur: / \n"); 
                     return division; }
"%"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur: % \n"); 
                     return mod; }
"="              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur: = \n"); 
                     return affectation; }
">"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur: > \n"); 
                     return sup; }
"<"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur: < \n"); 
                     return inf; }
"++"             { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur: ++ \n"); 
                     return incrementation; }
"<="             { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur <= \n");
                      return inf_egal; }
">="             { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur >= \n"); 
                     return sup_egal; }
"=="             { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur == \n"); 
                     return egal; }
"!="             { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur != \n"); 
                     return different; }
"&&"             { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext);
                    //  printf("Opérateur && \n");
                      return et; }
"||"             { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur || \n"); 
                     return ou; }
"!"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Opérateur ! \n"); 
                     return pt_exclamation; }
"+="             { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext);
                    // printf("Opérateur: +=\n"); 
                    return addition_assignment; }


                        /* ====== Séparateurs ====== */
"."              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("point: . \n");
                     return point; }
";"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Délimiteur: ; \n");
                     return pt_virgule; }
":"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Délimiteur: : \n");
                     return deux_points; }
","              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Virgule ',' \n");
                     return virgule; }
"{"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext);
                    //  printf("Délimiteur: { \n");
                     return accolade_o; }
"}"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Délimiteur: } \n"); 
                    return accolade_f; }
"("              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Délimiteur: ( \n"); 
                    return parenthese_o; }
")"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext);  
                    //printf("Délimiteur: ) \n"); 
                    return parenthese_f; }
"["              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext); 
                    // printf("Délimiteur: [ \n"); 
                    return crochet_o; }
"]"              { insert_sep_kw(yytext, "sp"); col = col + strlen(yytext);  
                    //printf("Délimiteur: ] \n");
                     return crochet_f; }

<<EOF>>          { return END_OF_FILE; }


                        /* ====== Identificateurs ======   "on envoit les valeurs par yylval ici"   */
{id}             { yylval.str=strdup(yytext); col = col + strlen(yytext); 
                    // printf("Identificateur: %s \n", yytext);  
                    return id; }


                        /* ====== Constantes ======   "on envoit les valeurs par yylval ici"    */    
{integer}        { yylval.ival=atoi(yytext); col = col + strlen(yytext);  
                    //printf("Nombre entier: %s \n", yytext);
                      return integer; }
{real}           { yylval.fval=atof(yytext); col = col + strlen(yytext);  
                    //printf("Nombre reel: %s\n", yytext);
                     return real; }
{caractere}      { yylval.str=strdup(yytext); col = col + strlen(yytext); 
                    // printf("Caractère: %s \n", yytext); 
                    return  caractere; }
{chaine}         { yylval.str=strdup(yytext); col = col + strlen(yytext); 
                    // printf("Chaîne de caractères: %s \n", yytext);
                     return chaine; }


{line_comment}  {   col += strlen(yytext); }

{multi_line_comment}   {    int nb = 0;
                            while (yytext[nb] != '\0') {  
                                if (yytext[nb] == '\n') {  
                                    nb_ligne++;
                                    col = 1;
                                } else {
                                    col++;
                                }
                                nb++;
                            } 
                        }


[ \t]+                 { col = col + strlen(yytext);  /* Ignore les espaces et tabulations */ }
\n                     { col = 1;  nb_ligne++; }

.   { 
    printf("Erreur lexicale à la ligne %d, colonne %d: Caractère non valide '%s'\n", nb_ligne, col, yytext); 
    exit(1);  // Arrêt facultatif du compilateur
}

%%

int yywrap() {
    return 1;
}
