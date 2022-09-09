#ifndef CYBER_H_INCLUDED
#define CYBER_H_INCLUDED


typedef struct internaute
{
    char cinn [10];
    int jour[20];
    int mois[20];
    int annee;
    int he, mine, se,daye, moise, ane;
    int hs,mins;
    int numPC;
    int duree;
}internaute;


internaute Saisir_inter();
int Saisir_Tab_inter(internaute Tab[], int N);
void afficher_inter(internaute E);
void afficher_Tab_inter(internaute Tab[], int N);
int rechercher_inter(internaute Tab[],int N, char ident[10]);
int rechercher_par_date(internaute Tab[],int N, int a,int b,int c);
int Ajouter_Tab_inter(internaute Tab[], int N);

void Modifier_inter(internaute Tab[], int taille, int indice);

void Supprimer_inter(internaute Tab[], int N,int indice);

void taux_occupation (internaute Tab[],int N);


#endif // INTERNAUTE_H_INCLUDED
