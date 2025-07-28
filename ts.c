#include "TS.h"
#include "quad.h"

Symbol* ts_idf_cst[1000];
SepKw* ts_sep[40];
SepKw* ts_kw[40];
int count_idf_cst = 0, count_kw = 0, count_sep = 0;


// calcule une valeur (index) à partir du nom d’une entité pour la placer dans la table
int hashFunction(char* key, int N) {
    int sum = 0;
    int i = 0;
    while (key[i] != '\0') {
        sum += key[i];  // Sum of ASCII values of characters
        i++;
    }
    return sum % N;
}

// cherche un identificateur ou une constante dans la table
Symbol* search_idf_cst(char* entity) {
    int index = hashFunction(entity,1000);
    Symbol* current = ts_idf_cst[index];

    while (current) {
        if (strcmp(current->name, entity) == 0) {
            return current;  // Found
        }
        current = current->next;
    }
    return NULL;  // Not found
}

// insere un nouvel identificateur ou constante dans la table si elle n’existe pas déjà
void insert_idf_cst(char* entity, char* code, char* type, char* value, char* scope, int rep) {
    if (search_idf_cst(entity) != NULL) {
        return;  // Avoid duplicates
    }

    int index = hashFunction(entity,1000);
    Symbol* newSymbol = (Symbol*)malloc(sizeof(Symbol));
    strcpy(newSymbol->name, entity);
    strcpy(newSymbol->code, code);
    strcpy(newSymbol->type, type);
    strcpy(newSymbol->scope, scope);
    strcpy(newSymbol->value, value);
    newSymbol->rep = rep;
    newSymbol->next = ts_idf_cst[index];  // Insert at head (chaining)
    ts_idf_cst[index] = newSymbol;
}

// cherche un séparateur ou un mot-clé dans sa table
SepKw* search_sep_kw(char* entity, char* code) {
    SepKw** table = (strcmp(code, "sp") == 0) ? ts_sep : ts_kw;
    int index = hashFunction(entity, 40);
    SepKw* current = table[index];

    while (current) {
        if (strcmp(current->name, entity) == 0) {
            return current;  // Found
        }
        current = current->next;
    }
    return NULL;  // Not found
}

// insère un séparateur ou mot-clé s’il n’existe pas déjà
void insert_sep_kw(char* entity, char* code) {
    SepKw** table = (strcmp(code, "sp") == 0) ? ts_sep : ts_kw;
    
    if (search_sep_kw(entity, code) != NULL) {
        return;  // Avoid duplicates
    }

    int index = hashFunction(entity, 40);
    SepKw* newEntry = (SepKw*)malloc(sizeof(SepKw));
    strcpy(newEntry->name, entity);
    strcpy(newEntry->code, code);
    newEntry->next = table[index];  // Insert at head (chaining)
    table[index] = newEntry;
}

// affiche toutes les tables (identificateurs, séparateurs, mots-clés)
void print() {
    printf("\n ***************************** Table des symboles IDF ***************************************\n");
    printf("----------------------------------------------------------------------------------------------\n");
    // printf("|       Name       |       Code       |       Type       |       Value      |\n");
    printf("|       Name       |       Code       |       Type       |       Value      |      Scope     |\n");
    printf("----------------------------------------------------------------------------------------------\n");

    int i = 0;
    while (i < 1000) {
        Symbol* current = ts_idf_cst[i];
        while (current) {
            // printf("| %16s | %16s | %16s | %16s |\n", current->name, current->code, current->type, current->value);
            printf("| %16s | %16s | %16s | %16s | %14s |\n",
                current->name,
                current->code,
                current->type,
                current->value,
                current->scope);
            current = current->next;
        }
        i++;
    }
    printf("----------------------------------------------------------------------------------------------\n\n");


    printf("\n ** Table des symboles 'separateurs' **\n");
    printf("----------------------------------------\n");
    printf("|       Name       |        Code       |\n");
    printf("----------------------------------------\n");

    i = 0;
    while (i < 40) {
        SepKw* current = ts_sep[i];
        while (current) {
            printf("| %16s |  %16s |\n", current->name, current->code);
            current = current->next;
        }
        i++;
    }
    printf("----------------------------------------\n\n");


    printf("\n *** Table des symboles 'mots cles' ***\n");
    printf("-----------------------------------------\n");
    printf("|        Name        |       Code       |\n");
    printf("-----------------------------------------\n");

    i = 0;
    while (i < 40) {
        SepKw* current = ts_kw[i];
        while (current) {
            printf("| %18s | %16s |\n", current->name, current->code);
            current = current->next;
        }
        i++;
    }
    printf("-----------------------------------------\n\n");

}

// vérifie si une entité est de type CLASS
bool verifClasseType(char* entity){
    Symbol* found = search_idf_cst(entity);
    if (!found){return false;}
    else{
        if(strcmp(found->code,"CLASS")==0){return true;}
        else{return false;}
    }

}

// vérifie si les deux entités ont des types compatibles
bool check_type(char* entity1, char* entity2) {
    Symbol* found1 = search_idf_cst(entity1);
    Symbol* found2 = search_idf_cst(entity2);


    if (!found1 || !found2) {
        return false;
    }

    if (!found1->type || !found2->type) {
        return false;
    }

    // Règle 1: Si l'un est "string", l'autre doit être "string"
    if (strcmp(found1->type, "string") == 0 || strcmp(found2->type, "string") == 0) {
        if (strcmp(found1->type, found2->type) == 0) {
            return true;
        } else {
            return false;
        }
    }else{

    // Règle 2: Si l'un est "int" ou "float", l'autre doit être "int" ou "float"
    if ((strcmp(found1->type, "int") == 0 || strcmp(found1->type, "float") == 0) &&
        (strcmp(found2->type, "int") == 0 || strcmp(found2->type, "float") == 0)) {
        return true;
    }

     return false;}
}

// vérifie si l'entité1 a exactement le type indiqué par entity2
bool cmp_type(char* entity1, char* entity2) {
    Symbol* found1 = search_idf_cst(entity1);

   
    // Règle 1: Si l'un est "string", l'autre doit être "string"
    if (strcmp(found1->type, entity2) == 0 ) {
        
            return true;
        } else {
            return false;
        }
    
}


//  insère ou met à jour le type d’un identificateur.
void insert_type(char* entity, char* type) {
    Symbol* found = search_idf_cst(entity);
    if (found) {
        strcpy(found->type, type);
    }
    found->rep=found->rep+1;
}

// insère ou met à jour le code d’un identificateur
void insert_code(char* entity, char* code) {
    Symbol* found = search_idf_cst(entity);
    if (found) {
        strcpy(found->code, code);
    }
    
}

// insère une valeur numérique à un identificateur
void insert_value(char* entity, char* val) {
    Symbol* found = search_idf_cst(entity);
    if (found) {
        strcpy(found->value, val); // Convertit val en float et l'affecte à found->value
    }
}

// copie le type de l’entité dans une autre variable
void cpy_type(char* entity, char* out) {
    Symbol* found = search_idf_cst(entity);
   
        strcpy(out, found->type);
            
}

// devine automatiquement le type (INT, FLOAT, STRING, BOOLEAN) d’une valeur
void infer_type(char* value, char* typeaff) {
    char* endptr;

    // Vérification d'un flottant (doit contenir un point)
    if (strchr(value, '.') != NULL) {  
        strtod(value, &endptr);
        if (*endptr == '\0') {  
            strcpy(typeaff, "float");
            return;
        }
    }

    // Vérification d'un entier
    strtol(value, &endptr, 10);
    if (*endptr == '\0') {  
        strcpy(typeaff, "int");
        return;
    }

    // Vérification d'une chaîne de caractères (entre guillemets)
    size_t len = strlen(value);
    if (len >= 2 && value[0] == '"' && value[len - 1] == '"') {
        strcpy(typeaff, "string");
        return;
    }

    // Vérification d'un booléen
    if (strcmp(value, "true") == 0 || strcmp(value, "false") == 0) {
        strcpy(typeaff, "boolean");
        return;
    }
  
}



// assigne un scope (contexte) à une entité
void insert_scope(char* entity, char* scope) {
    Symbol* found = search_idf_cst(entity);
    if (found) {
        strcpy(found->scope, scope);
    }
    Symbol* current= search_idf_cst(entity);
    
    if(current->rep<=1){
    strcpy(found->type, "");}
    current->rep=current->rep+1;
}


char scope_stack[MAX_SCOPE_DEPTH][50];
int scope_top = -1;

// entre dans un nouveau scope (ex: entrer dans une classe)
void push_scope(char *scope) {
    if (scope_top < MAX_SCOPE_DEPTH - 1) {
        scope_top++;
        strcpy(scope_stack[scope_top], scope);
    }
}

// Psort du scope actuel et désactive les symboles qui y étaient définis
void pop_scope() {
    if (scope_top >= 0) {
        char* current_scope = scope_stack[scope_top]; // Get the current scope

        int i = 0; // Initialize index for the hash table
        while (i < 1000) { // Iterate over all hash table entries
            Symbol* current = ts_idf_cst[i];

            while (current) { // Traverse the linked list in each bucket
                if (strcmp(current->scope, current_scope) == 0) {
                    current->rep = 0; // Set rep to 0 for symbols in the current scope
                }
                current = current->next;
            }

            i++; // Move to the next index
        }

        // Move to the previous scope
        scope_top--;
    }
}


// retourne le nom du scope actuel
char* current_scope() {
    
    if (scope_top >= 0) {
        return scope_stack[scope_top];
    }

    return "";
}

// retourne le nombre de fois qu’un symbole a été redéfini
int current_rep(char* entity) {
    Symbol* current= search_idf_cst(entity);
           return  current->rep;
   
}

// vérifie si une variable a été déclarée dans le scope courant ou un scope parent
int check_declaration(char* entity) {
    int i = scope_top;  // Start from the current scope
    bool vide=true;
    while (i >= 0) {  // Check all scopes from current to global
        int index = hashFunction(entity, 1000);
        Symbol* current = ts_idf_cst[index];

        while (current && vide ) {
            if (strcmp(current->name, entity) == 0 && strcmp(current->scope, scope_stack[i]) == 0) {
              //  printf("Variable %s found in scope %s\n", entity, scope_stack[i]);
                if (strcmp(current->type, "") ==0){
                return 0;  // Variable non declared in this or parent scope
            }else{ return -1;}
                
        }
            current = current->next;
        }

        i--;  // Move to the parent scope
    }return 0;
    // Not found in any accessible scope
}

// vérifie si le nom de la variable est identique à son scope (peut servir à vérifier les constantes ?)
bool check_cons(char* entity) {
    Symbol* current = search_idf_cst(entity);
    if (current == NULL) {
        return false; // Évite l'accès à un pointeur NULL
    }
    return strcmp(current->scope, entity) == 0;
}



listElts* create_symbol_table() {
    listElts* tableS = (listElts*)calloc(100, sizeof(listElts));
    int var_count = 0;

    for (int i = 0; i < 1000; i++) {
        Symbol* current = ts_idf_cst[i];
        while (current) {
            if (strcmp(current->code, "VAR") == 0 && current->rep > 0) {
                listElts elt = (listElts)malloc(sizeof(struct listElts));
                strcpy(elt->nomEntite, current->name);
                if (strcmp(current->type, "int") == 0) {
                    strcpy(elt->typeEntite, "INTEGER");
                } else if (strcmp(current->type, "float") == 0) {
                    strcpy(elt->typeEntite, "FLOAT");
                } else {
                    strcpy(elt->typeEntite, current->type);
                }
                elt->suivant = NULL;

                if (tableS[var_count / 10] == NULL) {
                    tableS[var_count / 10] = elt;
                } else {
                    listElts last = tableS[var_count / 10];
                    while (last->suivant) last = last->suivant;
                    last->suivant = elt;
                }
                var_count++;
            }
            current = current->next;
        }
    }
    return tableS;
}

