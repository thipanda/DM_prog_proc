#include "main.h"
#include "trie.h"
#include "lire.h"
#include "logement.h"



int main(int argc,char* argv[]){
    Plogement x = creer_x();//création du logement x
    Plogement tableau[TAB_SIZE];//création du tableau de logement;

    tableauDistance(x,tableau);

    randomiserTableau(tableau,10000);

    trieRapideTableau(tableau,0,TAB_SIZE-1);

    moyennePrixLogement(tableau,100);
    moyennePrixLogement(tableau,1000);
    moyennePrixLogement(tableau,3000);
    moyennePrixLogement(tableau,6000);

    suppLogement(&x);
    viderTableauLogement(tableau);
    return(0);
}