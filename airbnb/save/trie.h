#ifndef TRIE
#define TRIE

#include "main.h"
#include "logement.h"

void echangerLogement(int x,int y,Plogement tableau[TAB_SIZE]);
void randomiserTableau(Plogement tableau[TAB_SIZE],int n);
float moyenneDistance(Plogement log);
void trieRapideTableau(Plogement tab[TAB_SIZE],int first, int last);
float moyennePrixLogement(Plogement tableau[TAB_SIZE], int k);

#endif