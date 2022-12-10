#include "main.h"

int main(void){
    Pprocessus lab = creerProcessus();
    lab->temps = 3;
    lab->priorite=5;

    Pprocessus truc = creerProcessus();
    truc->temps = 5;
    truc->priorite=3;

    Pordonanceur ordo = creerOrdonanceur();

    ajout_activite(ordo,lab);
    ajout_activite(ordo,truc);

    run(ordo);
    
    suppOrdonanceur(&ordo);
    return(0);
}