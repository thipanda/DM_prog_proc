/*ordonnanceur contient toute les fonction permettant de gérer les ordonnanceurs*/


#ifndef ORDONANCEUR
#define ORDONANCEUR
/*
Structure définissant l'ordonnanceur
premier : pointe vers le premier processus de la file
*/
typedef struct ordonanceur {
    processus* premier;
}ordonanceur;
typedef ordonanceur* Pordonanceur;


Pordonanceur creerOrdonanceur();
void suppOrdonanceur(Pordonanceur* ptr);
void ajout_activite(Pordonanceur ordo, Pprocessus proc);
void step(Pordonanceur ordo);
void run(Pordonanceur ordo);
#endif