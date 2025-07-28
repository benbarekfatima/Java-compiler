// expr arith done
// expr arith complexe done 
// expr cond done done
// objets done 
// methods done
// str de controle ( if, for, while ) done 
// arrays

// fonction d'optimisation :
// 1. Propagation de copie      done
// 2. Propagation d'expressions     done
// 3. Elimination d'expressions redondantes (ou communes)       done
// 4. Simplification algébrique (Optimisation des multiplications et Élimination des calculs inutiles)      done 
// 5. Elimination de code inutile       done

#include "quad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Quad quads[MAX_QUADS];
int quad_index = 0;
int temp_index = 0;
static FILE *Assembly;

//supprimer quadruplet
void suppQuad(int i){
          strcpy(quads[i].op,"");
          strcpy(quads[i].arg2,"");
          strcpy(quads[i].arg1,"");
          strcpy(quads[i].result,"");
}
// Maintient la validité des sauts si on supprime un quad.
void verifierJmp(int indice){
	for (int i=0;i<quad_index;i++){
		int k=atoi(quads[i].arg1);
		if(quads[i].op[0]=='B' && k>=indice){
			k--;
			char c[20];
			sprintf(c,"%d",k);
			strcpy(quads[i].arg1,c);
		}
	}
}

//  Utilisé après une suppression pour combler le "trou"
void permutationQuad(int indice){
	for (int i =indice;i<quad_index;i++){
		quads[i]=quads[i+1];
	}
}

// recommencer la génération des quads
void init_quads() {
    quad_index = 0;
    temp_index = 0;
}

// Crée un nouvel temporaire (T0, T1, …) pour stocker les résultats intermédiaires des expressions
int new_temp() {
    return temp_index++;
}

// retourne le nom du temporaire correspondant à un numéro donné
const char* get_temp_name(int num) {
    static char temp[MAX_TEMP][10];
    snprintf(temp[num], sizeof(temp[num]), "T%d", num);
    return temp[num];
}

int add_quad(const char* op, const char* arg1, const char* arg2, const char* result) {
    if (quad_index >= MAX_QUADS) return -1;
    strncpy(quads[quad_index].op, op, sizeof(quads[quad_index].op)-1);
    strncpy(quads[quad_index].arg1, arg1, sizeof(quads[quad_index].arg1)-1);
    strncpy(quads[quad_index].arg2, arg2, sizeof(quads[quad_index].arg2)-1);
    strncpy(quads[quad_index].result, result, sizeof(quads[quad_index].result)-1);
    quad_index++;
    return quad_index-1;
}

void print_quads() {
    printf("\n===== QUADRUPLETS =====\n");
    for (int i = 0; i < quad_index; i++) {
        printf("%d : ( %s , %s , %s , %s )\n", i, quads[i].op, quads[i].arg1, quads[i].arg2, quads[i].result);
    }
     printf("\n**** le nombre des quadruplets avant l'optimisation est : %d \n",quad_index);
} 

// Propagation de copie
int chekPropCopie()
{
    int i=0;
    int change=0;
    for (i=0;i<quad_index;i++) // il verifie les quad un par un
    {
         if(quads[i].op[0]=='=')
        {
            // printf(" = ");
            int k=0;
            for(k=i+1;k<quad_index;k++) // il prend un quad et le compare avec les autres 
            {   // cas propagation impossible 
                if(strcmp(quads[i].result,quads[k].result)==0 || strcmp(quads[i].arg1,quads[k].result)==0) 
                    break;
                //(=,,d,t2)
                // printf("==================  \n");
                if(quads[k].op[0]=='+' || quads[k].op[0]=='*' || quads[k].op[0]=='-' || quads[k].op[0]=='/')
                {
                    //cmp t1 avec d
                    // printf("================== l9ina un quad avec oper \n");
                    if(strcmp(quads[i].arg1,quads[k].arg1)==0 )
                    {
                        // printf("================== switch entre op11 et op21 \n");
                        //t1=t2 puis enlever le quad[k] 
                        strcpy(quads[k].arg1,quads[i].result);
                        suppQuad(i);
						verifierJmp(i);
						permutationQuad(i);
                        quad_index--; i--;
                        change=1;
                    }else{
                      // printf("================== switch entre op11 et op22 \n");
                      if( strcmp(quads[i].arg1,quads[k].arg2)==0){
                        strcpy(quads[k].arg2,quads[i].result);
                        suppQuad(i);
						verifierJmp(i);
						permutationQuad(i);
                        quad_index--; i--;
                        change=1;
                        } 
                    }
                }
            }
        }
    }
    return change;
}

// Propagation d'expressions
int chekPropExpression()
{
    int i=0;
    int change=0;
    for (i=0;i<quad_index;i++)
    {
         if(quads[i].op[0]=='+' || quads[i].op[0]=='*' || quads[i].op[0]=='-' || quads[i].op[0]=='/'  )
        {
            int k=0;
            for(k=i+1;k<quad_index;k++)
            {   //(+,a,b,t1) 
                //(?,?,?,b) || (?,?,?,t1)
                //sortir si le resultat ou la deuxieme operande subit un changement 
                if(strcmp(quads[i].arg2,quads[k].result)==0 || strcmp(quads[i].result,quads[k].result)==0)
                    break;
                //(=,,d,t2)
                if(quads[k].op[0]=='=')
                {
                    //cmp t1 avec d
                    if(strcmp(quads[i].result,quads[k].arg1)==0)
                    {
                        //t1=t2 puis enlever le quad[k] 
                        strcpy(quads[i].result,quads[k].result);
                        suppQuad(k);
						verifierJmp(k);
						permutationQuad(k);
                        quad_index--; k--;
                        change=1;
                    }
                    else {
                    if(strcmp(quads[i].result,quads[k].arg2)==0)
                    {
                        //t1=t2 puis enlever le quad[k] 
                        strcpy(quads[i].result,quads[k].result);
                        suppQuad(k);
						verifierJmp(k);
						permutationQuad(k);
                        quad_index--; k--;
                        change=1;
                    }
                }
                }
            }
        }
    }
    return change;
}

// Elimination d'expressions redondantes (ou communes)
int chekPropExpComun()
{
    int change = 0;
    for (int i = 0; i < quad_index; i++)
    {
        // On cherche des expressions arithmétiques
        if (quads[i].op[0] == '+' || quads[i].op[0] == '*' ||
            quads[i].op[0] == '-' || quads[i].op[0] == '/')
        {
            for (int k = i + 1; k < quad_index; k++)
            {
                // Si une des variables est redéfinie, on ne peut pas propager
                if (strcmp(quads[i].result, quads[k].result) == 0 ||
                    strcmp(quads[i].arg1, quads[k].result) == 0 ||
                    strcmp(quads[i].arg2, quads[k].result) == 0)
                    break;

                // Vérifie si même opération et mêmes arguments
                if (strcmp(quads[i].op, quads[k].op) == 0 &&
                    strcmp(quads[i].arg1, quads[k].arg1) == 0 &&
                    strcmp(quads[i].arg2, quads[k].arg2) == 0)
                {
                    // On cherche à remplacer le résultat du quad redondant (k)
                    // par le résultat du quad original (i)
                    char replaced[20];
                    strcpy(replaced, quads[k].result);

                    // Supprimer le quadruplet redondant
                    suppQuad(k);
                    verifierJmp(k);
                    permutationQuad(k);
                    quad_index--; // car on a supprimé un quad
                    change = 1;

                    // Mettre à jour tous les quads suivants qui utilisent le résultat remplacé
                    for (int j = k; j < quad_index; j++)
                    {
                        if (strcmp(quads[j].arg1, replaced) == 0)
                            strcpy(quads[j].arg1, quads[i].result);
                        if (strcmp(quads[j].arg2, replaced) == 0)
                            strcpy(quads[j].arg2, quads[i].result);
                    }

                    // comme on a supprimé un quad, k est décrémenté automatiquement
                    k--;
                }
            }
        }
    }
    return change;
}

// Simplification algébrique (Optimisation des multiplications)
// x * 2 = x + x,
int checkSimplification()
{
  int i=0;
    int change = 0;
    for (i=0;i<quad_index;i++)
    {
      if(quads[i].op[0]=='*' ){
        if(strcmp(quads[i].arg1,"2")==0){
          strcpy(quads[i].op,"+");
          strcpy(quads[i].arg1,quads[i].arg2);
          change=1;
        }else{
          if(strcmp(quads[i].arg2,"2")==0){
            strcpy(quads[i].op,"+");
          strcpy(quads[i].arg2,quads[i].arg1);
          change=1;
          }
        }
        
      }
    }
    return change;
}

// Simplification algébrique (Élimination des calculs inutiles)
// x = a - a => supprimer le quad et remplacer x par 0 dans les prochaines quads
int  chekCalculeInutileMoins()
{
    int i=0;
    int change = 0; 
    for (i=0;i<quad_index;i++)
    {
      if(quads[i].op[0]=='-' ){
        if(strcmp(quads[i].arg1,quads[i].arg2)==0){
          int k=0;
            for(k=i+1;k<quad_index;k++)
            {  
              if(strcmp(quads[i].result,quads[k].result)==0)
                    break;
              if(strcmp(quads[i].result,quads[k].arg1)==0 )
              {
                strcpy(quads[k].arg1,"0");
              }else{
                if( strcmp(quads[i].result,quads[k].arg2)==0) {strcpy(quads[k].arg2,"0");}
                
              }
            }
          
          suppQuad(i);
		  verifierJmp(i);
		  permutationQuad(i);
          quad_index--; i--;
          change=1;
        }
      }
    }
    return change;
}

// Simplification algébrique (Élimination des calculs inutiles)
// x = 0 + a => x = a   et   x = a + 0 => x = a: supprimer le quad et remplacer x par a dans les prochaines quads
int chekCalculeInutilePlus()
{
    int i=0;
    int change = 0;
    for (i=0;i<quad_index;i++)
    {
      if(quads[i].op[0]=='+' ){
        if(strcmp(quads[i].arg1,"0")==0){
          int k=0;
          for(k=i+1;k<quad_index;k++)
            { 
               if(strcmp(quads[i].result,quads[k].arg1)==0 ){
                strcpy(quads[k].arg1,quads[i].arg2);
                suppQuad(i);  
				verifierJmp(i);  
				permutationQuad(i);
                quad_index--; i--;
                change=1;
                break;
               }else{
                if(strcmp(quads[i].result,quads[k].arg2)==0 ){
                  strcpy(quads[k].arg2,quads[i].arg2);
                  suppQuad(i);
				  verifierJmp(i);
				  permutationQuad(i);
                  quad_index--; i--;
                  change=1;
                  break;
                }

               }
            }
        }else{
          if(strcmp(quads[i].arg2,"0")==0){
                      int k=0;
          for(k=i+1;k<quad_index;k++)
            { 
              if(strcmp(quads[i].result,quads[k].arg1)==0 ){
                strcpy(quads[k].arg1,quads[i].arg1);
                suppQuad(i);
				verifierJmp(i);
				permutationQuad(i);
                quad_index--; i--;
                change=1;
                break;
               }else{
                if(strcmp(quads[i].result,quads[k].arg2)==0 ){
                  strcpy(quads[k].arg2,quads[i].arg1);
                suppQuad(i);
				verifierJmp(i);
				permutationQuad(i);
                quad_index--; i--;
                change=1;
                break;
                }

               }
            }

          }
        }
      }
    }
    return change;
}

// Simplification algébrique (Élimination des calculs inutiles)
// a = y + 1 ; b = a - 1 => b = y    et    x = y * 1 => x = y
int optimiserOperationsInutiles() {
    int i;
    int change = 0;
    for (i = 0; i < quad_index - 1; i++) {
        // ----------------------------
        // Cas : a = y + 1 ; b = a - 1 => b = y
        // ----------------------------
        if (strcmp(quads[i].op, "+") == 0 && strcmp(quads[i+1].op, "-") == 0) {
            if (strcmp(quads[i+1].arg1, quads[i].result) == 0 &&
                strcmp(quads[i].arg2, quads[i+1].arg2) == 0) {
                // On remplace l'opération par une affectation directe
                strcpy(quads[i+1].op, "=");
                strcpy(quads[i+1].arg1, quads[i].arg1);
                strcpy(quads[i+1].arg2, "");
                // Supprimer le quad précédent
                suppQuad(i);
                verifierJmp(i);
                permutationQuad(i);
                change =  1;
                quad_index--; i--; // Revenir pour traiter l'élément déplacé
            }
        }

        // ----------------------------
        // Cas : a = y * 1 => a = y
        // ----------------------------
        if (strcmp(quads[i].op, "*") == 0) {
            if (strcmp(quads[i].arg1, "1") == 0) {
                strcpy(quads[i].op, "=");
                strcpy(quads[i].arg1, quads[i].arg2);
                strcpy(quads[i].arg2, "");
                change = 1;
            } else if (strcmp(quads[i].arg2, "1") == 0) {
                strcpy(quads[i].op, "=");
                // arg1 reste, on supprime arg2
                strcpy(quads[i].arg2, "");
                change = 1;
            }
        }

        // ----------------------------
        // Cas : a = y / 1 => a = y
        // ----------------------------
        if (strcmp(quads[i].op, "/") == 0 && strcmp(quads[i].arg2, "1") == 0) {
            strcpy(quads[i].op, "=");
            strcpy(quads[i].arg2, "");
            change = 1;
        }
    }

    return change;
}

// élimination de code inutiles: simplification de valeur constante, (x = 0)
int enleveZ()
{
    int i=0;
    int change = 0;
    for (i=0;i<quad_index;i++)
    {
         if(quads[i].op[0]=='=' && strcmp(quads[i].arg1,"0")==0)
        {
            int k=0;
            for(k=i+1;k<quad_index;k++)
            {   
                if(strcmp(quads[i].result,quads[k].result)==0 )
                    break;
                if(strcmp(quads[k].arg1,quads[i].result)==0)
                {
                  strcpy(quads[k].arg1,"0");
				  suppQuad(i);
				  verifierJmp(i);
				  permutationQuad(i);
                  quad_index--; i--;
                  change=1;
                }else{
					if (strcmp(quads[k].arg2,quads[i].result)==0 ){
						 strcpy(quads[k].arg2,"0");
						suppQuad(i);
						verifierJmp(i);
						permutationQuad(i);
                        quad_index--; i--;
                        change=1;
					}
				}
            }
        }
    }
    return change;
}

// élimination de code inutiles: supprimer les instructions qui affectent des variables jamais utilisées par la suite
int eliminerCodeInutile() {
    int i, j;
    int used;
    int change= 0;
    for (i = 0; i < quad_index; i++) {
        // On cible uniquement les opérations qui produisent un résultat
        // et qui ne sont pas des sauts ni des appels
        if (quads[i].result[0] != '\0' &&
            strcmp(quads[i].op, "if") != 0 &&
            strcmp(quads[i].op, "goto") != 0 &&
            strcmp(quads[i].op, "call") != 0 &&
            strcmp(quads[i].op, "return") != 0) {

            used = 0;

            // Chercher si quads[i].result est utilisé plus tard
            for (j = i + 1; j < quad_index; j++) {
                if ((strcmp(quads[i].result, quads[j].arg1) == 0) ||
                    (strcmp(quads[i].result, quads[j].arg2) == 0)) {
                    used = 1;
                    break;
                }
            }

            // Si jamais utilisé, on le supprime
            if (!used) {
                suppQuad(i);
                verifierJmp(i);
                permutationQuad(i);
                change=1;
                quad_index--; i--; // Revenir sur l'instruction déplacée
            }
        }
    }
    return change;
}


void optiQuad(){
    int changed;

    do {
        changed = 0;

        if (chekPropCopie())               changed = 1;
        if (chekPropExpression())          changed = 1;
        if (chekPropExpComun())            changed = 1;
        if (chekCalculeInutileMoins())     changed = 1;
        if (chekCalculeInutilePlus())      changed = 1;
        if (checkSimplification())         changed = 1;
        if (optimiserOperationsInutiles()) changed = 1;
        if (enleveZ())                     changed = 1;

    } while (changed);
    // eliminerCodeInutile(); // je lai eliminté car mon exemple ne traite pas bcp de reutilisation
}


void afficherQuadAfterOpt()
{ 
    int i, nbQuad=0;
    printf("\n::::::::::::::::::::::: Quadruplets apres optimisation :::::::::::::::::::::::::::::::::::\n");
    for (i=0;i<quad_index;i++)
    {  if((strcmp(quads[i].op,"" ) !=0) ){  //Ne pas afficher les quad vide (produits apres le processus d'optimisation)
        printf("\n %d - ( %s  ,  %s  ,  %s  ,  %s )",i,quads[i].op,quads[i].arg1,quads[i].arg2,quads[i].result); 
        nbQuad++;
        }
    }
    printf("\n\n**** le nombre des quadruplets apres l'optimisation est : %d \n",nbQuad);
}






// -----------------------------------------------------------------
// --------------------- assembleur ---------------------------------
// ------------------------------------------------------------------

// Assembly generation functions
static void init_assembly_file() {
    Assembly = fopen("CodeObjet.asm", "w+");
    if (!Assembly) {
        printf("Error opening CodeObjet.asm\n");
        return;
    }
}

static void close_assembly_file() {
    if (Assembly) {
        fclose(Assembly);
        printf("Assembly code generated in CodeObjet.asm\n");
    }
}

static void generate_from_quad() {
    char Operation[10]; // Buffer for assembly operation

    for (int i = 0; i < quad_index; i++) {
        // Handle arithmetic operations
        if (strcmp(quads[i].op, "+") == 0 || strcmp(quads[i].op, "-") == 0 ||
            strcmp(quads[i].op, "*") == 0 || strcmp(quads[i].op, "/") == 0) {
            switch (quads[i].op[0]) {
                case '+': strcpy(Operation, "ADD"); break;
                case '-': strcpy(Operation, "SUB"); break;
                case '*': strcpy(Operation, "MUL"); break;
                case '/': strcpy(Operation, "DIV"); break;
            }

            if (quads[i].arg1[0] == 'T' && quads[i].arg2[0] == 'T') {
                fprintf(Assembly, "\t\tPOP AX\n"); // Pop first temporary
                fprintf(Assembly, "\t\tPOP BX\n"); // Pop second temporary
                if (quads[i].op[0] == '/') {
                    fprintf(Assembly, "\t\tCWD\n"); // Sign-extend AX to DX:AX for division
                    fprintf(Assembly, "\t\t%s BX\n", Operation);
                } else {
                    fprintf(Assembly, "\t\t%s AX, BX\n", Operation);
                }
                fprintf(Assembly, "\t\tPUSH AX\n"); // Push result
            } else if (quads[i].arg1[0] == 'T') {
                fprintf(Assembly, "\t\tPOP AX\n"); // Pop first temporary
                if (quads[i].op[0] == '/') {
                    fprintf(Assembly, "\t\tCWD\n");
                    fprintf(Assembly, "\t\t%s %s\n", Operation, quads[i].arg2);
                } else {
                    fprintf(Assembly, "\t\t%s AX, %s\n", Operation, quads[i].arg2);
                }
                fprintf(Assembly, "\t\tPUSH AX\n");
            } else if (quads[i].arg2[0] == 'T') {
                fprintf(Assembly, "\t\tPOP AX\n"); // Pop second temporary
                if (quads[i].op[0] == '/') {
                    fprintf(Assembly, "\t\tCWD\n");
                    fprintf(Assembly, "\t\t%s %s\n", Operation, quads[i].arg1);
                } else {
                    fprintf(Assembly, "\t\t%s AX, %s\n", Operation, quads[i].arg1);
                }
                fprintf(Assembly, "\t\tPUSH AX\n");
            } else {
                fprintf(Assembly, "\t\tMOV AX, %s\n", quads[i].arg1); // Load first operand
                if (quads[i].op[0] == '/') {
                    fprintf(Assembly, "\t\tCWD\n");
                    fprintf(Assembly, "\t\t%s %s\n", Operation, quads[i].arg2);
                } else {
                    fprintf(Assembly, "\t\t%s AX, %s\n", Operation, quads[i].arg2);
                }
                fprintf(Assembly, "\t\tPUSH AX\n"); // Push result
            }
        }
        // Handle assignment
        else if (strcmp(quads[i].op, "=") == 0) {
            if (quads[i].arg1[0] == 'T') {
                fprintf(Assembly, "\t\tPOP AX\n");
                fprintf(Assembly, "\t\tMOV %s, AX\n", quads[i].result);
            } else if (quads[i].result[0] == 'T') {
                fprintf(Assembly, "\t\tMOV AX, %s\n", quads[i].arg1);
                fprintf(Assembly, "\t\tPUSH AX\n");
            } else {
                fprintf(Assembly, "\t\tMOV AX, %s\n", quads[i].arg1);
                fprintf(Assembly, "\t\tMOV %s, AX\n", quads[i].result);
            }
        }
        // Pour les comparaisons
        else if (strcmp(quads[i].op, "<") == 0 || strcmp(quads[i].op, ">") == 0 ||
                 strcmp(quads[i].op, "==") == 0 || strcmp(quads[i].op, "!=") == 0 ||
                 strcmp(quads[i].op, "<=") == 0 || strcmp(quads[i].op, ">=") == 0) {
            
            // Charger les opérandes
            fprintf(Assembly, "\t\tMOV AX, %s\n", quads[i].arg1);
            fprintf(Assembly, "\t\tMOV BX, %s\n", quads[i].arg2);
            
            // Comparer
            fprintf(Assembly, "\t\tCMP AX, BX\n");
            
            // Générer le saut conditionnel approprié
            const char* jump_instruction;
            switch(quads[i].op[0]) {
                case '<': 
                    if (quads[i].op[1] == '=') jump_instruction = "JLE";
                    else jump_instruction = "JL";
                    break;
                case '>': 
                    if (quads[i].op[1] == '=') jump_instruction = "JGE";
                    else jump_instruction = "JG";
                    break;
                case '=': jump_instruction = "JE"; break;
                case '!': jump_instruction = "JNE"; break;
                default: jump_instruction = "JMP";
            }
            
            // Stocker le résultat
            fprintf(Assembly, "\t\t%s set_true_%d\n", jump_instruction, i);
            fprintf(Assembly, "\t\tMOV %s, 0\n", quads[i].result);
            fprintf(Assembly, "\t\tJMP end_%d\n", i);
            fprintf(Assembly, "set_true_%d:\n", i);
            fprintf(Assembly, "\t\tMOV %s, 1\n", quads[i].result);
            fprintf(Assembly, "end_%d:\n", i);
        }
        // Pour les opérateurs logiques
        else if (strcmp(quads[i].op, "&&") == 0) {
            fprintf(Assembly, "\t\tMOV AX, %s\n", quads[i].arg1);
            fprintf(Assembly, "\t\tMOV BX, %s\n", quads[i].arg2);
            fprintf(Assembly, "\t\tAND AX, BX\n");
            fprintf(Assembly, "\t\tMOV %s, AX\n", quads[i].result);
        }
        else if (strcmp(quads[i].op, "||") == 0) {
            fprintf(Assembly, "\t\tMOV AX, %s\n", quads[i].arg1);
            fprintf(Assembly, "\t\tMOV BX, %s\n", quads[i].arg2);
            fprintf(Assembly, "\t\tOR AX, BX\n");
            fprintf(Assembly, "\t\tMOV %s, AX\n", quads[i].result);
        }
        // Pour les structures de contrôle
        else if (strcmp(quads[i].op, "IF_FALSE") == 0) {
            fprintf(Assembly, "\t\tMOV AX, %s\n", quads[i].arg1);
            fprintf(Assembly, "\t\tCMP AX, 0\n");
            fprintf(Assembly, "\t\tJE %s\n", quads[i].result);
        }
        else if (strcmp(quads[i].op, "GOTO") == 0) {
            fprintf(Assembly, "\t\tJMP %s\n", quads[i].result);
        }
        else if (strcmp(quads[i].op, "LABEL") == 0) {
            fprintf(Assembly, "%s:\n", quads[i].result);
        }
    }
}

void generate_assembly_code(listElts tableS[]) {

    init_assembly_file();
    if (!Assembly) return;

    // Program title
    fprintf(Assembly, "TITLE ProgName\n");

    // Stack segment
    fprintf(Assembly, "\nPILE SEGMENT STACK\n");
    fprintf(Assembly, "\tDB 100 DUP (?)\n");
    fprintf(Assembly, "PILE ENDS\n");

    // Data segment
    fprintf(Assembly, "\nDATA SEGMENT\n");
    for (int i = 0; i < 100; i++) {
        listElts parcourt = tableS[i];
        while (parcourt != NULL) {
            if (parcourt->typeEntite[0] != '\0') { // Non-empty type
                fprintf(Assembly, "\t%s ", parcourt->nomEntite);
                if (strcmp(parcourt->typeEntite, "INTEGER") == 0) {
                    fprintf(Assembly, "DW 0\n"); // Scalar integer
                } else if (strcmp(parcourt->typeEntite, "FLOAT") == 0) {
                    fprintf(Assembly, "DD 0.0\n"); // Scalar float
                }
            }
            parcourt = parcourt->suivant;
        }
    }
    // Declare temporaries
    for (int i = 0; i < temp_index; i++) {
        fprintf(Assembly, "\t%s DW 0\n", get_temp_name(i));
    }
    fprintf(Assembly, "DATA ENDS\n");

    // Code segment
    fprintf(Assembly, "\nCODE SEGMENT\n");
    fprintf(Assembly, "MAIN:\n");
    fprintf(Assembly, "\tASSUME CS:CODE, DS:DATA, SS:PILE\n");
    fprintf(Assembly, "\tMOV AX, DATA\n");
    fprintf(Assembly, "\tMOV DS, AX\n");
    generate_from_quad();
    fprintf(Assembly, "\tMOV AX, 4C00h\n"); // Exit program (DOS)
    fprintf(Assembly, "\tINT 21h\n");
    fprintf(Assembly, "CODE ENDS\n");
    fprintf(Assembly, "END MAIN\n");

    close_assembly_file();
}
