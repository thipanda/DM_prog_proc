#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "main.h"
#include "processus.h"


/*
Permet de créer un Processus
Ne prend pas d'entrée et sort un pointeur vers le Processus
*/
Pprocessus creerProcessus(){
	Pprocessus ptr;
	if((ptr = MALLOC(processus)) == NULL){
		fprintf(stderr, "ERREUR ALLOCATION MEMOIRE");
		exit(1);
	}
	ptr->temps = 0;
	ptr->priorite = 0;
    processus* apres = NULL;
	return(ptr);
}

/*Permet de libérer l'espace mémoire prit par le processus
Prend en entré le processus et n'a pas de sortie
*/
void suppProcessus(Pprocessus* ptr){
    free(*ptr);
    *ptr = NULL;
}

/*Permet d'exécuter un processus :
affiche sa priorité, son temps d'exécution
Prend en entré le pointeur vers le Processus
N'a pas de sortit
*/
void executerProcessus(Pprocessus ptr){
    printf("Priorite : %d\nTemps : %d\n",ptr->priorite,ptr->temps);
    sleep(ptr->temps);
}