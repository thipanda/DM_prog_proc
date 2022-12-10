#ifndef LIRE
#define LIRE

#include "main.h"
#include "logement.h"

void skipFirstLine(char* c,FILE* fichier);
void remplir(int temp,Plogement logement,int colonne);
void readCell(char* c,int cell_nb,FILE* fichier,Plogement tableau[TAB_SIZE],Plogement x,int line);
void readLine(char* c,FILE* fichier,Plogement x,Plogement tableau[TAB_SIZE],int line);
void tableauDistance( Plogement x,Plogement tableau[TAB_SIZE]);

#endif