#include "logement.h"


/*
Permet de créer un logement
Ne prend pas d'entrée
Sort un pointeur vers le logement
*/
Plogement creerLogement(){
	Plogement ptr;//création du pointeur vers le logement qui va accueillir la structure
	if((ptr = MALLOC(logement)) == NULL){
		fprintf(stderr, "ERREUR ALLOCATION MEMOIRE");
		exit(1);
	}
	ptr->accommodates = 0;
	ptr->bedrooms = 0;
	ptr->bathrooms = 0;
	ptr->beds = 0;
	ptr->price = 0;
	ptr->minimum_nights = 0;
	ptr->maximum_nights = 0;
	ptr->number_of_reviews = 0;
    ptr->numero = 0;
	return(ptr);
}

/*
Permet de supprimer l'espace mémoire prise par la structure logement
Prend en entrée le pointeur vers le logement
N'a pas de sortie
*/
void suppLogement(Plogement* ptr){
    free(*ptr);
    *ptr = NULL;
}

/*
Permet de supprimer tout les logement du tableau de logement
Prend en entré le tableau de logement
N'a pas de sortie
*/
void viderTableauLogement(Plogement tableau[TAB_SIZE]){
    for(int i = 0;i < TAB_SIZE;i++){
        suppLogement(&tableau[i]);
    }
}

/*
Permet d'afficher les caractéristique d'un logement
Prend en entré un pointeur vers un logement
N'a pas de sortie
*/
void afficherLogement(Plogement ptr){
    if(ptr != NULL){
        printf("numero logement : %d\naccomodates : %d\nbedrooms : %d\nbathrooms : %d\nbeds : %d\nprice : %d\nminimum_nights : %d\nmaximum_nights : %d\nnumber_of_reviews : %d\ndistance accomodate : %d\ndistance bedrooms : %d\ndistance beds : %d\n\n",ptr->numero,ptr->accommodates,ptr->bedrooms,ptr->bathrooms,ptr->beds,ptr->price,ptr->minimum_nights,ptr->maximum_nights,ptr->number_of_reviews,ptr->distance[0],ptr->distance[1],ptr->distance[2]);
    }else{
        printf("Le logement existe pas\n");
    }
}

/*
Permet d'écrire dans un fichier déjà ouvert les caractéristique d'un logement
Prend en entré le pointeur vers un fichier et le pointeur vers un logement
N'a pas de sortie
*/
void ecrireLogement(Plogement ptr,FILE* file){
    if(ptr != NULL){
        fprintf(file,"numero logement : %d\naccomodates : %d\nbedrooms : %d\nbathrooms : %d\nbeds : %d\nprice : %d\nminimum_nights : %d\nmaximum_nights : %d\nnumber_of_reviews : %d\ndistance accomodate : %d\ndistance bedrooms : %d\ndistance beds : %d\n\n",ptr->numero,ptr->accommodates,ptr->bedrooms,ptr->bathrooms,ptr->beds,ptr->price,ptr->minimum_nights,ptr->maximum_nights,ptr->number_of_reviews,ptr->distance[0],ptr->distance[1],ptr->distance[2]);
    }else{
        fprintf(file,"Le logement existe pas\n");
    }
}

/*
Permet de créer le logement x
N'a pas d'entré
Sort le pointeur vers le logement x
*/
Plogement creer_x(){
    Plogement ptr = creerLogement();
    ptr->accommodates = 2;
    ptr->bedrooms = 1;
    ptr->bathrooms = 1;
    ptr->beds = 1;
    ptr->price = 100;
    ptr->minimum_nights = 2;
    ptr->maximum_nights = 420;
    ptr->number_of_reviews = 10;
    ptr->numero = -1;
    return(ptr);
}

/*
Permet de calculer la distance de la variable voulue entre deux logement
Prend en entré deux pointeurs vers logements
Sort la distance
*/
int distance(Plogement log_1,Plogement log_2,int col){
    int x,y =0;
    switch (col){
    case 1:
        x = log_1->accommodates;
        y = log_2->accommodates;
        break;
    case 2:
        x = log_1->bedrooms;
        y = log_2->bedrooms;
        break;
    case 3:
        x = log_1->bathrooms;
        y = log_2->bathrooms;
        break;
    case 4:
        x = log_1->beds;
        y = log_2->beds;
        break;
    case 5:
        x = log_1->price;
        y = log_2->price;
        break;
    case 6:
        x = log_1->minimum_nights;
        y = log_2->minimum_nights;
        break;
    case 7:
        x = log_1->maximum_nights;
        y = log_2->maximum_nights;
        break;
    case 8:
        x = log_1->number_of_reviews;
        y = log_2->number_of_reviews;
        break;
    
    default:
        break;
    }
    return(abs(x - y));
}


/*
Permet d'afficher toute les distances d'un tableau de logement
Prend en entré un tableau de logement
N'a pas de sortie
*/
void afficherDistance(Plogement tableau[TAB_SIZE]){
    for(int i = 0; i < TAB_SIZE;i++){
        printf("Distance logement %d :\nacommodate : %d\nbedrooms : %d\nbeds : %d\n",i,tableau[i]->distance[0],tableau[i]->distance[1],tableau[i]->distance[2]);
    }
}

/*
Permet d'afficher le tableau de Logement
Prend en entré le tableau de Logement
N'a pas de sortie
*/
void afficherTableau(Plogement tableau[TAB_SIZE]){
    FILE* file;

    file = fopen("Tableau_V2.txt","w");
    if(file == NULL){
        printf("Error\n");
        exit(1);
    }

    for(int i = 0; i< TAB_SIZE;i++){
        afficherLogement(tableau[i]);
        ecrireLogement(tableau[i], file);
    }

    fclose(file);
}