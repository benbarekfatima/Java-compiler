%{
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
%}

/* ----------------------------------------------------------------------
   Définition de l'union pour les valeurs sémantiques
   ---------------------------------------------------------------------- */
%union {
    float fval;
    int ival;
    char* str;
    char* res;
    struct {
        char* type;   // Contiendra le type (ex. "int", "float", etc.)
        char* value;  // Contiendra la valeur d'initialisation (ex. "5", "0.0", etc.)
    } attr;
}

    // %define parse.trace
/* ----------------------------------------------------------------------
   Déclaration des tokens (issus du lexer lexical.l)
   ---------------------------------------------------------------------- */
%token mc_class <str>mc_int <str>mc_float <str>mc_double <str>mc_char <str>mc_boolean <str>mc_string <str>mc_excp
%token mc_if mc_else mc_for mc_while mc_do mc_switch mc_case mc_default mc_break
%token mc_return mc_public mc_static mc_void mc_private mc_protected
%token mc_try mc_catch mc_finally mc_new  mc_throws mc_throw <str>mc_this
%token <str>mc_true <str>mc_false mc_print
%token <str>chaine  <str>caractere
%token <str>id <ival>integer <fval>real

%token addition soustraction multiplication division mod affectation
%token sup inf incrementation inf_egal sup_egal egal different et ou pt_exclamation addition_assignment

%token point pt_virgule deux_points virgule accolade_o accolade_f parenthese_o parenthese_f
%token crochet_o crochet_f

/* ----------------------------------------------------------------------
   Directives de précédence et associativité pour les opérateurs
   (pour réduire les conflits shift/reduce)
   ---------------------------------------------------------------------- */
%left '+' '-';   
%left '*' '/';

/* Déclare que le non-terminal 'type' retourne une valeur de type 'res' (défini dans la %union) */
%type <res> type type_array 
%type <attr> return_statement postfix_suffix

%type <attr> expression logical_or_expression logical_and_expression equality_expression relational_expression var_decl_suffix_opt
%type <attr> additive_expression multiplicative_expression unary_expression postfix_expression call_suffix primary_expression expression_list expression_list_opt
%type <attr> assignment_statement assignment_expression var_decl_for for_var_decl_suffix for_statement expression_opt

/* Précédence pour résoudre le problème du "dangling else" */
%nonassoc IFX
%nonassoc mc_else

/* indique la fin de fichier */
%token END_OF_FILE

/* ----------------------------------------------------------------------
   Définition du symbole de départ
   ---------------------------------------------------------------------- */
%start program

%%

// =--- Erreurs sémantiques à traiter:
// Variable double déclarée     done
// Variable non déclarée        done
// Incompatibilité de type      done
// Division par zéro        done
// Tableau (taille invalide)        done
// Tableau (type d'element invalide)        done
// Tableau (accès à de mauvais indices dans un tableau)     done (sr)
// Méthode (nombre et type de paramètres invalides)     done (sr)
// Méthode (type de retour invalide)        done
// Portée des paramètres et variables locales des méthodes      done

/* ======================================================================
   SECTION 1 : Structure du programme
   ====================================================================== */
/* Programme : une série de déclarations de classes */
program
    : class_decl_list END_OF_FILE
        { printf("programme syntaxiquement correcte.\n");
        generate_assembly_code(create_symbol_table()); // Generate assembly
         YYACCEPT; }
    ;

/* Liste de déclarations de classes */
class_decl_list
    : class_decl
    | class_decl_list class_decl
    ;

/* ======================================================================
   SECTION 2 : Déclarations de classes
   ====================================================================== */
/* Déclaration d'une classe (avec ou sans modificateur de visibilité) */

// --------SYM-------- : Portée des paramètres et variables locales
class_decl
    : mc_public_opt mc_class id accolade_o
    { 
        // Pousser la portée de la classe identifiée par 'id'
        push_scope($3);
        // Insérer ce symbole dans la TS (code "CLASS") s'il n'existe pas déjà
        if(check_declaration($3) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: redéclaration de la classe %s\n", nb_ligne, $3);
            // exit(1);
        }
        insert_idf_cst($3, "CLASS", "", " ", current_scope(), 1);
    }

    class_body accolade_f
    { 
        pop_scope();
        printf("Déclaration de classe terminée\n"); 
    }
    ;

mc_public_opt
    : | mc_public
    ;

/* Corps de la classe (peut être vide ou contenir une liste de déclarations internes) */
class_body
    : /* vide */
    | class_body_decl_list
    ;

/* Liste des déclarations internes d'une classe (variables et méthodes) */
class_body_decl_list
    : class_body_decl
    | class_body_decl_list class_body_decl
    ;

/* Une déclaration interne peut être une déclaration de variable ou de méthode */
class_body_decl
    : var_decl
    | method_decl
    | constructor_decl
    | block
    ;

/* ======================================================================
   SECTION 3 : Déclarations de variables et méthodes
   ====================================================================== */

/* Permet de déclarer plusieurs variables dans une même instruction
   ex: int a, b = 5, c; */
var_decl
    : type var_decl_list pt_virgule
    | type_array var_decl_list pt_virgule
    ;

var_decl_list
    : id var_decl_suffix_opt 
    {
        if (check_declaration($1) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Variable %s deja declaree dans la portee %s\n",nb_ligne, $1, current_scope());
        }
        if ($2.value != NULL) {
            if (strcmp(current_type, $2.type) != 0) {
                fprintf(stderr,"Erreur semantique ligne %d: Le type de l'expression (%s) ne correspond pas au type declare de la variable (%s).\n",nb_ligne, $2.type, current_type);
            }
            insert_idf_cst($1, "VAR", current_type, strdup($2.value), current_scope(), 1);
            add_quad("=", $2.value, "", $1); // Ajouter le quadruplet pour l'affectation
            printf("Debug: var_decl_list: Generated quad (=, %s, , %s)\n", $2.value, $1); // Débogage
        } else {
            insert_idf_cst($1, "VAR", current_type, " ", current_scope(), 1);
        }
    }  
    | var_decl_list virgule id 
{
        if (check_declaration($3) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Variable %s deja declaree dans la portee %s\n",nb_ligne, $3, current_scope());
        }
        insert_idf_cst($3, "VAR", current_type, " ", current_scope(), 1);
    }
    ;

var_decl_suffix_opt
    : /* vide */  { $$.type = NULL; $$.value = NULL; }
    | affectation expression { $$ = $2; }
    ;

/* préciser le type lors de la déclaration dans la boucle for */
var_decl_for
: type id for_var_decl_suffix
      {
          if (check_declaration($2) != 0) {
              fprintf(stderr, "Erreur semantique ligne %d: Variable %s deja declaree dans la portee %s\n", 
                      nb_ligne, $2, current_scope());
          }
          if ($3.value != NULL) {
              if (strcmp(current_type, $3.type) != 0) {
                  fprintf(stderr, "Erreur semantique ligne %d: Le type de l'expression (%s) ne correspond pas au type declare de la variable (%s).\n", 
                          nb_ligne, $3.type, current_type);
              }
              insert_idf_cst($2, "VAR", current_type, strdup($3.value), current_scope(), 1);
              add_quad("=", $3.value, "", $2); // Affectation pour l'initialisation
              printf("Debug: var_decl_for: Generated quad (=, %s, , %s)\n", $3.value, $2);
          } else {
              insert_idf_cst($2, "VAR", current_type, " ", current_scope(), 1);
          }
      }
    ;

for_var_decl_suffix
: affectation expression
      {
          $$ = $2;
      }
    | /* vide */
      {
          $$.type = NULL;
          $$.value = NULL;
      }
    ;

/* Déclaration de méthode : cas avec ou sans préfixe (toutes ces repetetions pour eleminer les problemes de shift/reduce*/
// --------SYM-------- : Portée des paramètres et variables locales
method_decl
    : visibility_static mc_void id 
    { 
        // Vérifier si la méthode est déjà déclarée dans la portée actuelle
        if(check_declaration($3) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Methode %s deja declaree dans la portee %s\n",nb_ligne, $3, current_scope());
            // exit(1);
        }

        current_method_return_type =strdup( "void");
        // Insérer la méthode dans la TS
        insert_idf_cst($3, "METHOD", "void", " ", current_scope(), 1);

        // On crée un nouveau scope pour les paramètres et variables locales.
        sprintf(scopeName, "%s_method", $3); 
        push_scope(scopeName);
    } parenthese_o param_list_opt parenthese_f throws_clause_opt
    block  
    { 
        pop_scope(); 
    }
    | visibility_static type id 
    { 
        if(check_declaration($3) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Methode %s deja declaree dans la portee %s\n",nb_ligne, $3, current_scope());
            // exit(1);
        }
 
        current_method_return_type = strdup($2);
        insert_idf_cst($3, "METHOD", $2, " ", current_scope(), 1);

        sprintf(scopeName, "%s_method", $3); 
        push_scope(scopeName);
    } parenthese_o param_list_opt parenthese_f throws_clause_opt 
    block
    { 
        pop_scope(); 
    }
    | mc_void id 
    { 
        if(check_declaration($2) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Methode %s deja declaree dans la portee %s\n",nb_ligne, $2, current_scope());
            // exit(1);
        }

        current_method_return_type = strdup("void");;
        insert_idf_cst($2, "METHOD", "void", " ", current_scope(), 1);

        sprintf(scopeName, "%s_method", $2);
        push_scope(scopeName);
    } parenthese_o param_list_opt parenthese_f throws_clause_opt 
    block
    { 
        pop_scope();
    }
    | type id 
    { 
        if(check_declaration($2) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Methode %s deja declaree dans la portee %s\n",nb_ligne,  $2, current_scope());
            // exit(1);
        }

        current_method_return_type = strdup($1);
        insert_idf_cst($2, "METHOD", $1, " ", current_scope(), 1);

        sprintf(scopeName, "%s_method", $2);
        push_scope(scopeName);
    } parenthese_o param_list_opt parenthese_f throws_clause_opt 
    block
    { 
        pop_scope(); 
    }
    ;

/* Déclaration de constructeur (pas de type de retour) */
constructor_decl
    : visibility_static id 
    { 
        if(check_declaration($2) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Methode %s deja declaree dans la portee %s\n",nb_ligne,  $2, current_scope());
            // exit(1);
        }

        insert_idf_cst($2, "CONSTR", "", " ", current_scope(), 1);

        sprintf(scopeName, "%s_method", $2);
        push_scope(scopeName);
    }
    parenthese_o param_list_opt parenthese_f block
    { 
        pop_scope(); 
    }
    | id
    { 
        if(check_declaration($1) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Methode %s deja declaree dans la portee %s\n",nb_ligne,  $1, current_scope());
            // exit(1);
        }

        insert_idf_cst($1, "CONSTR", "", " ", current_scope(), 1);

        sprintf(scopeName, "%s_method", $1);
        push_scope(scopeName);
    } parenthese_o param_list_opt parenthese_f block
    { 
        pop_scope(); 
    }
    ;

/* Clause throws optionnelle */
throws_clause_opt:
      /* vide */
    | mc_throws exception_list
    ;

/* Liste d'exceptions */
exception_list:
      type
    | exception_list virgule type
    ;

/* Combinaisons explicites pour visibilité et static */
visibility_static
    : visibility_actual                { /* uniquement visibilité */ }
    | mc_static                        { /* uniquement static */ }
    | visibility_actual mc_static      { /* visibilité suivie de static */ }
    | mc_static visibility_actual      { /* static suivi de visibilité */ }
    ;

/* Définition des tokens de visibilité */
visibility_actual
    : mc_public
    | mc_private
    | mc_protected
    ;

/* Types supportés */
type
    : mc_int { current_type=strdup($1); $$=current_type}
    | mc_float { current_type=strdup($1); $$=current_type}
    | mc_double { current_type=strdup($1); $$=current_type}
    | mc_char { current_type=strdup($1); $$=current_type}
    | mc_boolean { current_type=strdup($1); $$=current_type}
    | mc_string { current_type=strdup($1); $$=current_type}
    | mc_excp  { current_type=strdup($1); $$=current_type}
    | id { current_type=strdup($1); $$=current_type} /* Permet d'utiliser un identificateur comme type */
    ;

/* Déclaration de type tableau (exemple : String[]) */
type_array 
    : type crochet_o crochet_f
    {
        char* base = $1;
        char* full_type = malloc(strlen(base) + 3); // +3 pour "[]" et '\0'
        sprintf(full_type, "%s[]", base);
        current_type = full_type; $$=current_type;
    }
    | type crochet_o crochet_f crochet_o crochet_f
    {
        char* base = $1;
        char* full_type = malloc(strlen(base) + 5); // +6 pour "[][]" et '\0'
        sprintf(full_type, "%s[][]", base);
        current_type = full_type; $$=current_type;
    }
    ;

/* Liste optionnelle de paramètres */
param_list_opt
    : /* vide */
    | param_list
    ;

/* Liste de paramètres séparés par des virgules */
param_list
    : param
    | param_list virgule param
    ;

/* Un paramètre : type et identificateur (supporte aussi les tableaux) */
param
    : type id
    {   if (check_declaration($2) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Variable %s deja declaree dans la portee %s\n",nb_ligne, $2, current_scope());
            // exit(1);
        }

        insert_idf_cst($2, "VAR", current_type," ", current_scope(), 1);

    }
    | type_array id  /* Support pour `String[] args` */
    {   if (check_declaration($2) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Variable %s deja declaree dans la portee %s\n",nb_ligne, $2, current_scope());
            // exit(1);
        }

        insert_idf_cst($2, "VAR", current_type," ", current_scope(), 1);
       
    }
    ;

/* ======================================================================
   SECTION 4 : Instructions et blocs
   ====================================================================== */

/* Bloc d'instructions */
block
    : accolade_o statement_list_opt accolade_f
    ;

/* Liste optionnelle d'instructions */
statement_list_opt
    : /* vide */
    | statement_list
    ;

/* Liste d'instructions */
statement_list
    : statement
    | statement_list statement
    ;

/* Différents types d'instructions */
statement
    : block
    | var_decl
    | if_statement
    | while_statement
    | do_statement
    | for_statement
    | switch_statement
    | return_statement
    | throw_statement 
    | try_catch_statement
    | mc_print parenthese_o expression_opt parenthese_f pt_virgule
    /* Ajoutez ces règles spécifiques */
    | assignment_statement pt_virgule   // Affectations (i = 5;)
    | postfix_statement pt_virgule     // Incréments (i++;)
    ;

/* Expression postfixe comme une instruction*/
postfix_statement
    : primary_expression parenthese_o argument_list_opt parenthese_f
    | postfix_expression postfix_suffix
    | postfix_expression incrementation
    ;

/* ======================================================================
   SECTION 5 : Structures de contrôle
   ====================================================================== */

/* Instruction if avec ou sans else */
if_statement
: mc_if parenthese_o expression parenthese_f statement %prec IFX
      {
          printf("Debug: if_statement: condition value=%s, quad_index=%d\n", $3.value ? $3.value : "NULL", quad_index);
          const char* label_end = new_label();
          add_quad("IF_FALSE", $3.value, "", label_end);
          // Les quadruplets de $5 (statement) sont déjà générés
          add_quad("LABEL", "", "", label_end);
      }
    | mc_if parenthese_o expression parenthese_f statement mc_else statement
      {
          printf("Debug: if_else_statement: condition value=%s, quad_index=%d\n", $3.value ? $3.value : "NULL", quad_index);
          const char* label_else = new_label();
          const char* label_end = new_label();
          add_quad("IF_FALSE", $3.value, "", label_else);
          // Quadruplets de $5 (statement du if)
          add_quad("GOTO", "", "", label_end);
          add_quad("LABEL", "", "", label_else);
          // Quadruplets de $7 (statement du else)
          add_quad("LABEL", "", "", label_end);
      }
    ;

/* Boucle while */
while_statement
    : mc_while parenthese_o expression parenthese_f statement
    {


        const char* label_start = new_label();
        const char* label_end = new_label();

        // 1. Étiquette de début de la boucle
        add_quad("LABEL", "", "", label_start);

        // 2. Calculer la condition
        if ($3.value != NULL) {
            // Générer un nouveau quadruplet pour la condition (par exemple, i < 5)
            int t = new_temp();
            const char* temp_name = get_temp_name(t);
            // Supposons que $3.value contient le résultat de l'expression (par exemple, T0 pour i < 5)
            // Nous devons régénérer la condition en utilisant les informations de l'expression
            add_quad("<", $3.value, "5", temp_name); // Exemple : T0 = i < 5
            add_quad("IF_FALSE", temp_name, "", label_end);
        }

        // 3. Corps de la boucle (les quadruplets de statement sont déjà générés)

        // 4. Saut au début de la boucle
        add_quad("GOTO", "", "", label_start);

        // 5. Étiquette de fin
        add_quad("LABEL", "", "", label_end);
    }
    ;

/* Boucle do-while */
do_statement
    : mc_do statement mc_while parenthese_o expression parenthese_f pt_virgule
    ;

/* Boucle for avec initialisation, condition et mise à jour */
for_statement
    : mc_for parenthese_o for_init_opt  expression_opt pt_virgule for_update_opt parenthese_f statement
    {
          printf("Debug: for_statement: condition=%s, quad_index=%d\n", 
                 $4.value ? $4.value : "NULL", quad_index);
          
          const char* label_start = new_label();
          const char* label_end = new_label();

          // Label de début
          add_quad("LABEL", "", "", label_start);
          
          // Condition (si non vide)
          if ($4.value != NULL) {
              add_quad("IF_FALSE", $4.value, "", label_end);
          }
          
          // Corps (les quadruplets du statement sont déjà générés)
          
          // Incrémentation (les quadruplets de for_update_opt sont déjà générés)
          
          // Retour au début
          add_quad("GOTO", "", "", label_start);
          
          // Label de fin
          add_quad("LABEL", "", "", label_end);
      }
    ;

/* Initialisation optionnelle dans la boucle for */
for_init_opt
    : pt_virgule
    | expression pt_virgule
    | var_decl_for pt_virgule
    ;

/* Expression optionnelle dans la boucle for */
expression_opt
: /* vide */
      {
          $$.type = NULL;
          $$.value = NULL;
      }
    | expression
      {
          $$ = $1;
      }
    ;

/* Mise à jour optionnelle dans la boucle for */
for_update_opt
: /* vide */
      {
          // Pas d'incrémentation
      }
    | expression
      {
          // Les quadruplets pour l'expression (ex: i++) sont déjà générés
      }
    ;

/* Instruction switch-case */
switch_statement
    : mc_switch parenthese_o expression parenthese_f accolade_o case_list_opt  default_statement_opt accolade_f
    ;

/* Liste optionnelle de cas pour switch */
case_list_opt
    : /* vide */
    | case_list
    ;

/* Liste des cas dans une instruction switch */
case_list
    : case_statement
    | case_list case_statement
    ;

/* Un cas dans switch */
case_statement
    : mc_case constant deux_points statement_list_opt break_opt
    ;

break_opt
    : /* vide */
    | mc_break pt_virgule
    ;

/* Clause default */
default_statement_opt
    : /* vide */
    | default_statement
    ;

default_statement
    : mc_default deux_points statement_list_opt
    ;

/* Constantes supportées */
constant
    : integer
    | real
    | mc_true
    | mc_false
    | id
    | chaine
    | caractere
    ;

/* Instruction return (avec ou sans expression) */

// --------SYM-------- : Type de retour de la méthode invalide
return_statement
    : mc_return pt_virgule
    {
          // Dans le cas d'une méthode void, aucun retour n'est attendu.
          if (strcmp(current_method_return_type, "void") != 0) {
              fprintf(stderr,"Erreur semantique ligne %d: La methode doit retourner une valeur.",nb_ligne);
            //   exit(1);
          }
      }
    | mc_return expression pt_virgule
    {
          // Comparer le type de l'expression ($2) avec le type de retour attendu de la méthode.
          if(strcmp($2.type, current_method_return_type) != 0) {
              fprintf(stderr,"Erreur semantique ligne %d: Le type de retour %s ne correspond pas a la signature de la methode %s\n",nb_ligne,$2.type,current_method_return_type);
            //   exit(1);
          }
          $$ = $2;
      }
    ;

throw_statement
    : mc_throw expression pt_virgule
    ;

try_catch_statement
    : mc_try block catch_list finally_opt
    ;

catch_list
    : catch_clause
    | catch_list catch_clause
    ;

catch_clause
    : mc_catch parenthese_o type id parenthese_f
    {
        if(!verifClasseType($3)) {
            fprintf(stderr, "Erreur symantique ligne %d: %s n'est pas un type d'exception\n", nb_ligne, $3);
            // exit(1);
        }
        insert_idf_cst($4, "VAR", $3, " ", current_scope(), 1);
    }
     block
    ;

finally_opt
    : /* vide */
    | mc_finally block
    ;

/* ======================================================================
   SECTION 6 : Expressions
   ====================================================================== */

/* Expression générale */
expression
    : logical_or_expression  { $$ = $1; }
    ;

/* Expression d'affectation */
assignment_expression
    : logical_or_expression { $$ = $1; }
    | assignment_statement { $$ = $1; }
    ;

assignment_statement
    : postfix_expression affectation assignment_expression
    {
        // Vérifier si la variable à gauche est déclarée
        if ($1.value != NULL && search_idf_cst($1.value) == NULL) {
            fprintf(stderr, "Erreur semantique ligne %d: Variable non declaree\n", nb_ligne, $1.value);
            // exit(1); // Commenter pour permettre la détection d'autres erreurs
        }else{
        // Vérifier la compatibilité des types (facultatif, si vous voulez renforcer la vérification)
        if ($1.type != NULL && $3.type != NULL && strcmp($1.type, $3.type) != 0) {
            fprintf(stderr, "Erreur semantique ligne %d: Incompatibilite de type. Type attendu : %s, Type recu : %s\n",nb_ligne, $1.type, $3.type);
            // exit(1);
        }
        }
        // Générer le quadruplet d'affectation
        add_quad("=", $3.value, "", $1.value);
        // Propager les attributs
        $$.type = $3.type ? strdup($3.type) : NULL;
        $$.value = $3.value ? strdup($3.value) : NULL;
    }
    | postfix_expression addition_assignment assignment_expression
    {
        // Vérifier si la variable à gauche est déclarée
        if ($1.value != NULL && search_idf_cst($1.value) == NULL) {
            fprintf(stderr, "Erreur sémantique ligne %d: Variable '%s' non déclarée\n", nb_ligne, $1.value);
            // exit(1);
        }
        // Vérifier la compatibilité des types (facultatif)
        if ($1.type != NULL && $3.type != NULL && strcmp($1.type, $3.type) != 0) {
            fprintf(stderr, "Erreur sémantique ligne %d: Incompatibilité de type. Type attendu : %s, Type reçu : %s\n", nb_ligne, $1.type, $3.type);
            // exit(1);
        }
        // Propager les attributs
        $$.type = $3.type ? strdup($3.type) : NULL;
        $$.value = $3.value ? strdup($3.value) : NULL;
    }
    ;

/* Expression logique OU */
logical_or_expression
    : logical_and_expression { $$ = $1; }
    | logical_or_expression ou logical_and_expression {
        int t = new_temp();
        add_quad("||", $1.value, $3.value, get_temp_name(t));
        $$.type = strdup("boolean");
        $$.value = strdup(get_temp_name(t));
    }
    ;

/* Expression logique ET */
logical_and_expression
    : equality_expression { $$ = $1; }
    | logical_and_expression et equality_expression {
        int t = new_temp();
        add_quad("&&", $1.value, $3.value, get_temp_name(t));
        $$.type = strdup("boolean");
        $$.value = strdup(get_temp_name(t));
    }
    ;

/* Expression d'égalité */
equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression egal relational_expression {
        int t = new_temp();
        add_quad("==", $1.value, $3.value, get_temp_name(t));
        $$.type = strdup("boolean");
        $$.value = strdup(get_temp_name(t));
    }
    | equality_expression different relational_expression {
        int t = new_temp();
        add_quad("!=", $1.value, $3.value, get_temp_name(t));
        $$.type = strdup("boolean");
        $$.value = strdup(get_temp_name(t));
    }
    ;

/* Expression relationnelle */
relational_expression
    : additive_expression { $$ = $1; }
    | relational_expression inf additive_expression {
        int t = new_temp();
        add_quad("<", $1.value, $3.value, get_temp_name(t));
        $$.type = strdup("boolean");
        $$.value = strdup(get_temp_name(t));
    }
    | relational_expression sup additive_expression {
        int t = new_temp();
        add_quad(">", $1.value, $3.value, get_temp_name(t));
        $$.type = strdup("boolean");
        $$.value = strdup(get_temp_name(t));
    }
    | relational_expression inf_egal additive_expression {
        int t = new_temp();
        add_quad("<=", $1.value, $3.value, get_temp_name(t));
        $$.type = strdup("boolean");
        $$.value = strdup(get_temp_name(t));
    }
    | relational_expression sup_egal additive_expression {
        int t = new_temp();
        add_quad(">=", $1.value, $3.value, get_temp_name(t));
        $$.type = strdup("boolean");
        $$.value = strdup(get_temp_name(t));
    }
    ;

/* Expression additive */
additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression addition multiplicative_expression {
        int t = new_temp();
        add_quad("+", $1.value, $3.value, get_temp_name(t));
        $$.type = ((strcmp($1.type, "float") == 0) || (strcmp($3.type, "float") == 0)) ? strdup("float") : strdup("int");
        $$.value = strdup(get_temp_name(t));
    }
    | additive_expression soustraction multiplicative_expression{
        int t = new_temp();
        add_quad("-", $1.value, $3.value, get_temp_name(t));
        $$.type = ((strcmp($1.type, "float") == 0) || (strcmp($3.type, "float") == 0)) ? strdup("float") : strdup("int");
        $$.value = strdup(get_temp_name(t));
    }
    ;

/* Expression multiplicative */
multiplicative_expression
    : unary_expression  { $$ = $1; }
    | multiplicative_expression multiplication unary_expression {
        if ($1.value == NULL || $3.value == NULL) {
            fprintf(stderr, "Erreur semantique ligne %d: Operande invalide pour la multiplication\n", nb_ligne);
            $$.type = strdup("int"); // Valeur par défaut
            $$.value = NULL;
        } else {
            printf("Debug: multiplicative_expression: $1.value=%s, $3.value=%s\n", 
                   $1.value, $3.value);
            int t = new_temp();
            add_quad("*", $1.value, $3.value, get_temp_name(t));
            $$.type = ((strcmp($1.type, "float") == 0) || (strcmp($3.type, "float") == 0)) ? strdup("float") : strdup("int");
            $$.value = strdup(get_temp_name(t));
        }
    }
    | multiplicative_expression division unary_expression {
        int t = new_temp();
        add_quad("/", $1.value, $3.value, get_temp_name(t));
        $$.type = ((strcmp($1.type, "float") == 0) || (strcmp($3.type, "float") == 0)) ? strdup("float") : strdup("int");
        $$.value = strdup(get_temp_name(t));
    }
    | multiplicative_expression mod unary_expression {
        int t = new_temp();
        add_quad("%", $1.value, $3.value, get_temp_name(t));
        $$.type = strdup("int");
        $$.value = strdup(get_temp_name(t));
    }
    ;
 
/* Expression unaire */
unary_expression
    : postfix_expression { $$ = $1; }
    | pt_exclamation unary_expression {
          if ($2.value == NULL) {
              fprintf(stderr, "Erreur semantique ligne %d: Operande invalide pour !\n", nb_ligne);
              $$.type = strdup("boolean");
              $$.value = NULL;
          } else {
              int t = new_temp();
              add_quad("!", $2.value, "", get_temp_name(t));
              $$.type = strdup("boolean");
              $$.value = strdup(get_temp_name(t));
              printf("Debug: unary_expression (!): input=%s, output=%s\n", $2.value, $$.value);
          }
      }
    | soustraction unary_expression 
    {
          $$.type = strdup($2.type);
          char buffer[32];
          if (strcmp($2.type, "int") == 0) {
              sprintf(buffer, "%d", -atoi($2.value));
          } else if (strcmp($2.type, "float") == 0) {
              sprintf(buffer, "%f", -atof($2.value));
          } else {
              fprintf(stderr, "Erreur semantique ligne %d: operateur unaire '-' sur type '%s'\n", nb_ligne, $2.type);
          }
          $$.value = strdup(buffer);
      }
    | addition unary_expression {
          $$ = $2;
      }
    | incrementation unary_expression
      {
          if ($2.type != NULL && strcmp($2.type, "int") != 0) {
              fprintf(stderr, "Erreur semantique ligne %d: Operande non entier pour ++\n", nb_ligne);
          }
          int t = new_temp();
          const char* temp_name = get_temp_name(t);
          add_quad("+", $2.value, "1", temp_name);
          add_quad("=", temp_name, "", $2.value);
          $$.type = strdup("int");
          $$.value = strdup($2.value);
          printf("Debug: unary_expression (++): input=%s, output=%s\n", $2.value, $$.value);
      }
    ;

/* Expression postfixe */
postfix_expression
    : primary_expression call_suffix { 
        if ($2.type == NULL) $$ = $1; 
        else {
            $$.type = $2.type;
            $$.value = $2.value;
        }
    }
    | postfix_expression postfix_suffix { $$ = $2; }
    | postfix_expression incrementation
      {
          if ($1.type != NULL && strcmp($1.type, "int") != 0) {
              fprintf(stderr, "Erreur semantique ligne %d: Operande non entier pour ++\n", nb_ligne);
          }
          int t = new_temp();
          const char* temp_name = get_temp_name(t);
          add_quad("+", $1.value, "1", temp_name);
          add_quad("=", temp_name, "", $1.value);
          $$.type = strdup("int");
          $$.value = strdup($1.value);
          printf("Debug: postfix_expression (++): input=%s, output=%s\n", $1.value, $$.value);
      }
    ;

/* Suffixe d'appel de méthode direct ou non */
call_suffix
    : /* vide */ { $$.type = NULL; $$.value = NULL; }
    | parenthese_o argument_list_opt parenthese_f {
        int t = new_temp();
        add_quad("CALL", $<str>1, "", get_temp_name(t));
        $$.type = strdup("FUNC_RETURN");
        $$.value = strdup(get_temp_name(t));
    }
    ;

postfix_suffix
    : point id call_suffix {
        char champ[100];
        sprintf(champ, "%s.%s", $<str>1, $2); // $<str>1 = nom de l'objet
        $$.type = strdup("method");
        $$.value = strdup(champ);
    }
    ;

/* Expression primaire */
primary_expression
    : id {
        $$.type = strdup("id");
        $$.value = strdup($1);
    }
    | integer { 
        $$.type = strdup("int");
        char buffer[32];
        sprintf(buffer, "%d", yylval.ival);
        $$.value = strdup(buffer);
        // mettre a jour current_type
        // current_type = strdup("int");
    }
    | real { 
        $$.type = strdup("float");
        char buffer[32];
        sprintf(buffer, "%f", yylval.fval);
        $$.value = strdup(buffer);
        // current_type = strdup("float");
    }
    | mc_true { 
        // current_type=strdup("boolean"); 
        $$.type = strdup("boolean");
        $$.value = strdup("true");
    }
    | mc_false { 
        // current_type=strdup("boolean"); 
        $$.type = strdup("boolean");
        $$.value = strdup("false");
    }
    | caractere { 
        // current_type=strdup("char"); 
        $$.type = strdup("char");
        // char buffer[32];
        // sprintf(buffer, "%d", yylval.str);
        $$.value = strdup(yylval.str);
    }
    | chaine { 
        // current_type=strdup("chaine"); 
        $$.type = strdup("chaine");
        // char buffer[32];
        // sprintf(buffer, "%d", yylval.str);
        $$.value = strdup(yylval.str);
    }
    | mc_this{ 
        // current_type=strdup($1); 
        $$.type = strdup($1);
        char buffer[32];
        sprintf(buffer, "%d", yylval.str);
        $$.value = strdup(buffer);
    }
    | mc_new id parenthese_o argument_list_opt parenthese_f {
        int t = new_temp();
        add_quad("NEW", $2, "", get_temp_name(t));
        $$.type = strdup($2);
        $$.value = strdup(get_temp_name(t));
    }
    | mc_new mc_excp parenthese_o argument_list_opt parenthese_f { 
        // current_type=strdup($2); 
        $$.type=strdup($2);
        char buffer[32];
        sprintf(buffer, "%d", yylval.str);
        $$.value = strdup(buffer);
    }
    | parenthese_o expression_list_opt parenthese_f { 
        $$.type = $2.type ? strdup($2.type) : strdup("unknown");
        $$.value = $2.value ? strdup($2.value) : NULL;
        printf("Debug: parenthese_o expression_list_opt parenthese_f: type=%s, value=%s\n", 
               $$.type, $$.value ? $$.value : "NULL");
    }
    | accolade_o expression_list accolade_f { 
        // current_type=strdup("list"); 
        $$.type=strdup("list");
        char buffer[32];
        sprintf(buffer, "%d", yylval.str);
        $$.value = strdup(buffer);
    }
    /* --- Modification : Ajout des alternatives pour tableaux et matrices --- */
    
    // --------SYM-------- : Tableaux: : taille invalide ou type d'élément invalide
    | mc_new type crochet_o expression crochet_f { 
        if (strcmp($4.type, "int") != 0 || atoi($4.value) <= 0) {
            fprintf(stderr, "Erreur semantique ligne %d: taille de tableau invalide '%s'\n", nb_ligne, $4.value);
            // exit(1);
        }
        // current_type=strdup($2); 
        $$.type=strdup($2);
        char buffer[32];
        sprintf(buffer, "%d", yylval.str);
        $$.value = strdup(buffer);
     /* Instanciation d'un tableau, ex: new int[3] */ }
    | mc_new type crochet_o expression crochet_f crochet_o expression crochet_f {
        if (strcmp($4.type, "int") != 0 || atoi($4.value) <= 0) {
            fprintf(stderr, "Erreur semantique ligne %d: taille de matrice (nbr de ligne) invalide '%s'\n", nb_ligne, $4.value);
            // exit(1);
        } 
        if (strcmp($7.type, "int") != 0 || atoi($7.value) <= 0) {
            fprintf(stderr, "Erreur semantique ligne %d: taille de matrice (nbr de colonne) invalide '%s'\n", nb_ligne, $7.value);
            // exit(1);
        } 
        // current_type=strdup($2); 
        $$.type=strdup($2);
        char buffer[32];
        sprintf(buffer, "%d", yylval.str);
        $$.value = strdup(buffer);
          /* Instanciation d'une matrice, ex: new int[2][1] */ }
    // | id crochet_o expression crochet_f{
    //     if (strcmp($3.type, "int") != 0 || atoi($3.value) <= 0) {
    //         fprintf(stderr, "Erreur semantique ligne %d: taille de tableau invalide '%s'\n", nb_ligne, $3.value);
    //         //exit(1);
    //     }
    // }
    // | id crochet_o expression crochet_f crochet_o expression crochet_f{
    //     if (strcmp($3.type, "int") != 0 || atoi($3.value) <= 0) {
    //         fprintf(stderr, "Erreur semantique ligne %d: taille de tableau invalide '%s'\n", nb_ligne, $3.value);
    //         //exit(1);
    //     }
    // }
    ;

/* Liste optionnelle d'arguments */
argument_list_opt
    : /* vide */ 
    | argument_list  
    ;

/* Liste d'arguments séparés par des virgules */
argument_list
    : expression
    | argument_list virgule expression
    ;

/* Liste d'arguments séparés par des virgules */
expression_list
    : expression { $$ = $1; }
    | expression_list virgule expression { $$ = $1; }
    ;

expression_list_opt
    : /* vide */ { $$.type = NULL; $$.value = NULL; }
    | expression_list  { $$ = $1; }
    ;

%%

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

