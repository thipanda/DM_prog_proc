#include <stdlib.h>
#include <stdio.h>

#include "main.h"
#include "processus.h"
#include "ordonanceur.h"

Pordonanceur creerOrdonanceur(){
    Pordonanceur ptr;
    if((ptr = MALLOC(ordonanceur)) == NULL){
		fprintf(stderr, "ERREUR ALLOCATION MEMOIRE");
		exit(1);
	}
	ptr->premier = NULL;
	return(ptr);
}



void suppOrdonanceur(Pordonanceur* ptr){
    free(*ptr);
    *ptr = NULL;
}



void ajout_activite(Pordonanceur ordo, Pprocessus proc){
    if(ordo->premier == NULL){
        ordo->premier = proc;
    }else{
        Pprocessus element = ordo->premier;
        while(element->apres != NULL){
            element = element->apres;
        }
        element-> apres = proc;
    }
}

void step(Pordonanceur ordo){
    Pprocessus temp = ordo->premier;
    executerProcessus(ordo->premier);
    ordo->premier = ordo->premier->apres;
    suppProcessus(&temp);
}

void run(Pordonanceur ordo){
    while(ordo->premier != NULL){
        step(ordo);
    }
    printf("Fin de run\n");
}