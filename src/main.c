#include "main.h"


int main(int argc,char* argv[]){
    Pprocessus lab = creerProcessus();//création du premier Processus
    lab->temps = 3;
    lab->priorite=5;

    Pprocessus truc = creerProcessus();//création du deuxième Processus
    truc->temps = 5;
    truc->priorite=3;

    Pordonanceur ordo = creerOrdonanceur();//création de l'ordonnanceur

    ajout_activite(ordo,lab);
    ajout_activite(ordo,truc);

    run(ordo);
    
    suppOrdonanceur(&ordo);
    return(0);
}