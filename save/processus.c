#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "main.h"
#include "processus.h"



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

void suppProcessus(Pprocessus* ptr){
    free(*ptr);
    *ptr = NULL;
}

void executerProcessus(Pprocessus ptr){
    printf("Priorite : %d\nTemps : %d\n",ptr->priorite,ptr->temps);
    sleep(ptr->temps);
}