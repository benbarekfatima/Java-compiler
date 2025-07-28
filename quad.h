#ifndef QUAD_H
#define QUAD_H

#include "TS.h"

#define MAX_QUADS 1000
#define MAX_TEMP 100

// Structure d'un quadruplet
typedef struct {
    char op[10];
    char arg1[50];
    char arg2[50];
    char result[50];
} Quad;

// Fonctions pour la gestion des quadruplets
void init_quads();
int new_temp();
int add_quad(const char* op, const char* arg1, const char* arg2, const char* result);
void print_quads();

void optiQuad();

int chekPropCopie();
int chekPropExpression();
int chekPropExpComun();
int enleveZ();
int chekCalculeInutileMoins();
int chekCalculeInutilePlus();
int checkSimplification();
int optimiserOperationsInutiles();
int eliminerCodeInutile();

void afficherQuadAfterOpt();

const char* get_temp_name(int num);

// Assembly generation function
void generate_assembly_code(listElts tableS[]);


extern Quad quads[MAX_QUADS];
extern int quad_index;

#endif // QUAD_H 
