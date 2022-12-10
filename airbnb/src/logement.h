/*
Permet de gérer la structure logement(qui sert à l'enrengistrement des données en mémoire) ainsi que le tableau de logement
*/
#ifndef LOGEMENT
#define LOGEMENT

#include "main.h"
/*
Structure du logement
Prend toute les variables qui définissent un logement ainsi qy'un tableau contenant jusqu'à 3 distances
*/
typedef struct log {
	int accommodates;
    int bedrooms;
    int bathrooms;
    int beds;
    int price;
    int minimum_nights;
    int maximum_nights;
    int number_of_reviews;
    int distance[3];
    int numero;
} logement;
typedef logement * Plogement;

Plogement creerLogement();

void suppLogement(Plogement* ptr);

void viderTableauLogement(Plogement tableau[TAB_SIZE]);

void afficherLogement(Plogement ptr);

void ecrireLogement(Plogement ptr,FILE* file);

Plogement creer_x();

int distance(Plogement log_1,Plogement log_2,int col);

void afficherDistance(Plogement tableau[TAB_SIZE]);

void afficherTableau(Plogement tableau[TAB_SIZE]);

#endif