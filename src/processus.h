/*processus contient toute les fonction permettant de gérer les processus*/

#ifndef PROCESSUS
#define PROCESSUS
/*
Structure définissant le processus
priorite : le niveau de priorité du processus
temps : le temps que met le processus à s'exécuter
*/
typedef struct processus {
    int priorite;
    int temps;
    struct processus* apres;
} processus;
typedef processus * Pprocessus;

Pprocessus creerProcessus();
void suppProcessus(Pprocessus* ptr);
void executerProcessus(Pprocessus ptr);
#endif