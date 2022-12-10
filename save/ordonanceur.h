#ifndef ORDONANCEUR
#define ORDONANCEUR
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