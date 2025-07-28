#ifndef TS_H
#define TS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SCOPE_DEPTH 100

// Structure for identifier and constant symbols (Chained List)
typedef struct Symbol {
    char name[20];
    char code[20];
    char type[20];
    char value[50];
    char scope[20];   // la porte courant
    int rep;   // le nombre de déclarations/références (nrmlmn repetition de l'entité)
    struct Symbol* next;  // Pointer to handle collisions (Chaining)
} Symbol;

// Structure for Separators and Keywords (Chained List)
typedef struct SepKw {
    char name[20];
    char code[20];
    struct SepKw* next;
} SepKw;

// Structure for symbol table entries used in assembly generation
typedef struct listElts {
    char nomEntite[32];
    char typeEntite[16];
    struct listElts *suivant;
} *listElts;

// Hash tables for identifiers/constants, separators, and keywords
extern Symbol* ts_idf_cst[1000];
extern SepKw* ts_sep[40];
extern SepKw* ts_kw[40];

extern int count_idf_cst, count_kw, count_sep;

extern char scope_stack[MAX_SCOPE_DEPTH][50];
extern int scope_top;

// Hash function: h(k) = k % N
int hashFunction(char* key, int N);
// Search for an entity in the hash table
Symbol* search_idf_cst(char* entity);

// Insert a new identifier or constant
void insert_idf_cst(char* entity, char* code, char* type, char* value, char* scope, int rep);
// Search for separator or keyword based on code
SepKw* search_sep_kw(char* entity, char* code);
void insert_sep_kw(char* entity, char* code);

// Print Symbol Tables
void print();
// search elem and return its type
bool verifClasseType(char* entity);
bool check_type(char* entity1, char* entity2);

bool cmp_type(char* entity1, char* entity2);

// Insert Type into IDF Table
void insert_type(char* entity, char* type);

void insert_code(char* entity, char* code);
void insert_value(char* entity, char* val);
void cpy_type(char* entity, char* out);
void infer_type(char* value, char* typeaff);

void insert_scope(char* entity, char* scope);

// Push a new scope (when entering a class)
void push_scope(char *scope);
// Pop the current scope (when leaving a class)
void pop_scope();

// Get the current scope
char* current_scope();

int current_rep(char* entity);
// Check if an entity has been declared
int check_declaration(char* entity);

bool check_cons(char* entity);

listElts* create_symbol_table();

#endif
