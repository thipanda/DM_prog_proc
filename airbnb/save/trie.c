#include "trie.h"

/*
Permet d'échanger la position de deux logement dans le tableau
Prend en entré deux pointeurs vers de logements
N'a pas de sortie
*/
void echangerLogement(int x,int y,Plogement tableau[TAB_SIZE]){
    Plogement temp;//créer une variable temporaire pour échanger les logements
    temp = tableau[x];
    tableau[x] = tableau[y];
    tableau[y] = temp;
}

/*
Permet de mélanger de manière aléatoire le tableau de logement en échangeant deux logements aléatoires n fois
Prend en entrée le tableau de logement et le nombre de fois que l'on souhaite échanger des logements
N'a pas de sortie
*/
void randomiserTableau(Plogement tableau[TAB_SIZE],int n){
    int x = 0;//variable x et y utilisé pour stocké les variables aléatoires
    int y = 0;
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        x = (rand()) % TAB_SIZE;
        y = (rand()) % TAB_SIZE;
        if(x!=y){
            echangerLogement(x,y,tableau);
        }
    }

}


/*
Permet de faire la moyenne des distances d'un logement
Prend en entrée un pointeur sur logement
Sort la moyenne des distances de ce logement
*/
float moyenneDistance(Plogement log){
    float avg = 0;//permet de stocker la moyenne des distances
    for(int i = 0;i<3;i++){
        avg = avg + (float)(log->distance[i]);
    }
    return(avg);
}

/*
Permet de trier le tableau de logement selon la moyenne des distances de chaque logement
Prend en entré le tableau de logement et le début et la fin de la partie à trié
N'a pas de sortie
*/
void trieRapideTableau(Plogement tab[TAB_SIZE],int first, int last){
    int pivot;//variable nécessaire pour l'algorithme de trie rapide
    int i;
    int j;
    if(first < last){
        pivot = first;
        i = first;
        j = last;
        while(i < j){
            while((moyenneDistance(tab[i])<= moyenneDistance(tab[pivot]))&&(i < last)){
            i++;
            }
            while(moyenneDistance(tab[j]) > moyenneDistance(tab[pivot]))
            j--;
            if(i < j){
                echangerLogement(i,j,tab);
            }
        }
        echangerLogement(pivot,j,tab);
        trieRapideTableau(tab, first, j-1);
        trieRapideTableau(tab, j + 1,last);
    }
}

/*
Permet de calculer la moyenne des k logements ressemblant le plus au logements x
Prend en entrées le tableau de logement(triée sinon la moyenne n'aura aucune valeur) et le nombre k de logement qui influe sur l'estimation de prix
Sort l'estimation du prix
*/
float moyennePrixLogement(Plogement tableau[TAB_SIZE], int k){
    float temp = 0;//valeur temporaire contenat le prix moyen
    for(int i = 0;i < k;i++){
        temp = temp + tableau[i]->price;
    }
    printf("Le prix moyen des %d premier logement est : %f\n",k,temp/k);
    return(temp/k);
}