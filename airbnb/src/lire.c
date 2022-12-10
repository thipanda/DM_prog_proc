#include "lire.h"

/*
Permet de mettre le pointeur dans le fichier à la deuxième ligne car il n'y a pas de variable sur la première ligne
Prend en entrée un pointeur sur le dernier caractère lu du fichier et le pointeur vers le fichier
N'a pas de sortie
*/
void skipFirstLine(char* c,FILE* fichier){
    while((*c != '\n')&&(*c != EOF)){
        *c = fgetc(fichier);
    }
}

/*
Permet d'affecter dans la structure logement les variables lues depuis le fichier
Prend en entrée le pointeur vers le logement, la variable à mettre ainsi que l'endroit ou mettre la variable
N'a pas de sortie
*/
void remplir(int temp,Plogement logement,int colonne){
    switch (colonne){
    case 0:
        logement->numero = temp;
    case 1:
        logement->accommodates = temp;
        break;
    case 2:
        logement->bedrooms = temp;
        break;
    case 3:
        logement->bathrooms = temp;
        break;
    case 4:
        logement->beds = temp;
        break;
    case 5:
        logement->price = temp;
        break;
    case 6:
        logement->minimum_nights = temp;
        break;
    case 7:
        logement->maximum_nights = temp;
        break;
    case 8:
        logement->number_of_reviews = temp;
        break;
    
    default:
        printf("Erreur dans la fonction remplir\n");
        break;
    }
}

/*
Permet de lire une cellule du fichier csv puis d'envoyer la valeurs collecter à la fonction remplir
Prend en entrée le pointeur vers le dernier caractère lu du fichier, le numéro de la cellule dans lequel on se trouve,le pointeur vers le fichier,le pointeur vers le tableau,le pointeur vers le logement x et le numéro de ligne ou l'on se trouve
N'a pas de sortie
*/
void readCell(char* c,int cell_nb,FILE* fichier,Plogement tableau[TAB_SIZE],Plogement x,int line){
    int temp = 0;//valeur temporaire qui permet de calculer la valeur à l'interieur de la cellule
    int f = -1;//permet de gérer le problème du point
    if(*c != EOF){
        do{
            *c = fgetc(fichier);
            if(*c == '.'){
                f = temp;
            }
            if((*c != EOF)&&(*c != ',')&&(*c != '\n')&&(*c != '\r')){
                temp = temp*10 + (int)(*c)-48;
            }
        }while((*c != EOF)&&(*c != ',')&&(*c != '\n'));
    }

    if(f == -1){
        f = temp;
    }
    //printf("temp : %d ",f);
    remplir(f,tableau[line],cell_nb);

    if(cell_nb == 1){
        tableau[line]->distance[0] = distance(x,tableau[line],cell_nb);
    }
    if(cell_nb == 2){
        tableau[line]->distance[1] = distance(x,tableau[line],cell_nb);
    }
    if(cell_nb == 4){
        tableau[line]->distance[2] = distance(x,tableau[line],cell_nb);
    }
}


/*
Permet de lire une ligne en appelant plusieurs fois la fonction readCell
Prend en entrée le pointeur vers le dernier caractère lu du fichier, le pointeur vers le fichier,le pointeur vers le tableau,le pointeur vers le logement x et le numéro de ligne ou l'on se trouve
N'a pas de sortie
*/
void readLine(char* c,FILE* fichier,Plogement x,Plogement tableau[TAB_SIZE],int line){
    int cell_nb = 0;//permet de savoir dans qu'elle cellule on se situe
    tableau[line] = creerLogement();
    if(*c != EOF){
        do{
            readCell(c,cell_nb,fichier,tableau,x,line);
            cell_nb = cell_nb + 1;
        }while((*c != '\n')&&(*c != EOF));
    }
}
/*
Permet de lire le fichier airbnb_donnees_propres.csv puis de les stocker dans un tableau de logement
Prend en entrée le pointeur vers le logement x et le pointeur vers le tableau de logement
N'a pas de sortie
*/
void tableauDistance( Plogement x,Plogement tableau[TAB_SIZE]){
    FILE* fichier = NULL;//création du pointeur vers le fichier que l'on va lire
    char c = 0;//dernier caractère lu
    int line = 0;//numéro de la ligne ou l'on se trouve


    fichier = fopen("airbnb_donnees_propres.csv","r");
    if(fichier == NULL){
        exit(1);
    }

    skipFirstLine(&c,fichier);

    while ((c != EOF)&&(line < TAB_SIZE)){
        readLine(&c,fichier,x,tableau,line);
        line++;
    }

    fclose(fichier);
}