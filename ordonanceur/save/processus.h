#ifndef PROCESSUS
#define PROCESSUS
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