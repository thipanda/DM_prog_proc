#include <stdlib.h>
#include <stdio.h>

#include "main.h"
#include "processus.h"
#include "ordonanceur.h"

/*
Fonction qui permet de créer un ordonanceur
Elle ne prend aucune entré et donne en sortie le pointeur vers l'ordonanceur
*/
Pordonanceur creerOrdonanceur(){
    Pordonanceur ptr;//creation d'un pointeur vers un ordonnanceur
    if((ptr = MALLOC(ordonanceur)) == NULL){
		fprintf(stderr, "ERREUR ALLOCATION MEMOIRE");
		exit(1);
	}
	ptr->premier = NULL;//La file est vide donc on fait pointer premier vers NULL
	return(ptr);
}


/*
Fonction qui permet de retirer de la mémoire l'ordanceur
Elle ne prend aucune entré ni sortie
*/
void suppOrdonanceur(Pordonanceur* ptr){
    free(*ptr);
    *ptr = NULL;
}


/*
Fonction qui permet d'enfiler un Processus dans l'ordonanceur
Ell prend en entré le pointeur vers l'ordonanceur et le pointeur vers le Processus
Elle n'a pas de sortit
*/
void ajout_activite(Pordonanceur ordo, Pprocessus proc){
    if(ordo->premier == NULL){
        ordo->premier = proc;
    }else{
        Pprocessus element = ordo->premier;//création d'un pointeur sur processus qui va nous permettre de naviguer dans la file pour checher le dernier element
        while(element->apres != NULL){
            element = element->apres;
        }
        element-> apres = proc;
    }
}

/*
Fonction qui permet d'exécuter puis de faire sortir le Processus en haut de la pile
Elle prend en entrée le pointeur vers l'ordonnanceur
Elle n'a pas de sortie
*/
void step(Pordonanceur ordo){
    Pprocessus temp = ordo->premier;//permet de garder en mémoire puis de supprimer le premier processus de la file
    executerProcessus(ordo->premier);
    ordo->premier = ordo->premier->apres;
    suppProcessus(&temp);
}
/*
Fonction qui permet d'exécuter tout les processus d'une file dans le bon ordre
Elle prend en entré le pointeur vers l'ordonnanceur
*/
void run(Pordonanceur ordo){
    while(ordo->premier != NULL){
        step(ordo);
    }
    printf("Fin de run\n");
}