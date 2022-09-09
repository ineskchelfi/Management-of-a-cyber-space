#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <time.h>
#include "cyber.h"

internaute Saisir_inter()
{
   int he, mine, se, daye, moise, ane,hs,mins,h,m,s,ans;

   time_t now;
   internaute inter;

while ((strlen(inter.cinn))!=8){
    printf("\n Introduire numero CIN : ");
    scanf("%s", &inter.cinn);
}


   printf("\n Introduire numero du PC : ");
   scanf("%d", &inter.numPC);
    // Renvoie l'heure actuelle
  time(&now);
  // Convertir au format heure locale
   struct tm *local = localtime(&now);
  inter.he = local->tm_hour;
  inter.mine = local->tm_min;
  inter.se = local->tm_sec;
  inter.daye = local->tm_mday;
  inter.moise = local->tm_mon + 1;
  inter.ane = local->tm_year + 1900;
  printf("L'heure d'entrée : %02d:%02d:%02d\n", inter.he, inter.mine, inter.se);
  // Afficher la date courante
  printf("La date d'entrée : %02d/%02d/%d\n", inter.daye, inter.moise, inter.ane);
  printf("\n Introduire l'heure de sortie : ");
  printf("L'heure :");scanf("%d",&inter.hs);
  printf("La minute :");scanf("%d",&inter.mins);
//  scanf("%d %d %d (..h ..min ..sec) ",hs,mins,ss);
if (inter.hs<inter.he) {
    printf("\n Heure incorrecte , Introduire l'heure de sortie : ");
  printf("L'heure :");scanf("%d",&inter.hs);
  printf("La minute :");scanf("%d",&inter.mins);
}
else if ((inter.hs==inter.he)&&(inter.mine>inter.mins))
    {

     printf("\n Minute incorrecte ,Introduire l'heure de sortie : ");
     printf("L'heure :");scanf("%d",&inter.hs);
    printf("La minute :");scanf("%d",&inter.mins);
}
inter.duree=((inter.hs*3600)+(inter.mins*60))-((inter.he*3600)+(inter.mine*60)+(inter.se));
h = inter.duree / 3600; //1 heure = 3600 secondes
	inter.duree = inter.duree % 3600; //% : Le reste de division entiere
	m = inter.duree / 60;   //1 minute = 60 secondes
	inter.duree = inter.duree % 60;
printf("la durée passé est : %dh %dmin  ",h,m);
    return inter;


}
int Saisir_Tab_inter(internaute Tab[], int N)
{
    internaute inter;
    int i=N;
    char rep[3];

   do
   {
     inter=Saisir_inter();
     Tab[i]=inter;
     i++;
     printf("\n Voulez vous saisir un autre internaute : oui/non  ");
     scanf("%s",rep);
   }while(strcmp(rep,"oui")==0);
   N=i;
   return N;

}


void afficher_inter(internaute I)
{
    printf("\n****\n Le numero CIN : %s", I.cinn);
    printf("\n Heure d'entree : %d:%d:%d\n", I.he, I.mine, I.se);
    printf("\n Heure de sortie : %d h %d \n",I.hs,I.mins );
    printf("\n La date : %d / %d / %d \n", I.daye,I.moise,I.ane);
    printf("\n Numero PC : %d \n", I.numPC);


}


void afficher_Tab_inter(internaute Tab[], int N)
{
    for(int i=0; i<N; i++)
    {
        afficher_inter(Tab[i]);
    }

}
int rechercher_inter(internaute Tab[],int N, char ident[10])
{
    int i=0;
    int existe=-1;
    while(i<N && existe==-1)
    {
        if(strcmp(Tab[i].cinn,ident) == 0)
        {
           existe = i;
        }
       i++;
    }
    return existe;
}

int Ajouter_Tab_inter(internaute Tab[], int N)
{
    internaute inter;
    int i=N;

     inter=Saisir_inter();
     Tab[i]=inter;
     i++;
   N=i;
   return N;

}

void Modifier_inter(internaute Tab[], int N, int indice)
{
    int choix;

    printf("\n Que voulez vous modifier ? \n\n");
    printf("\n 1. Modifier le numero CIN ");
    printf("\n 2. Modifier le numero du PC");
    printf("\n Donner votre choix:  ");
    scanf("%d", &choix);

    switch(choix)
    {
    case 1:
        {
            printf("\n Introduire le numero CIN :  ");
            scanf("%s",Tab[indice].cinn);
            break;
        }

    case 2:
        {
            printf("\n Introduire numero PC  ");
            scanf("%d",&Tab[indice].numPC);
            break;
        }


    default:
        printf("\n Choix erronee");
    }
    return 0;
}

void Supprimer_inter(internaute Tab[], int N, int indice)
{
    int i;
    int taille=N;

    for(i=indice-1;i<taille-1;i++)
    {
        Tab[i]=Tab[i+1];
    }
    N--;
}


int rechercher_par_date(internaute Tab[],int N, int a,int b,int c)
{
    int i=0;
    int existe=-1;
    while(i<N && existe==-1)
    {
        if ((Tab[i].daye==a) &&(Tab[i].moise==b)&&(Tab[i].ane==c))
        {
           existe = i;
        }
       i++;
    }
    return existe;}

void taux_occupation (internaute Tab[],int N)
{
    int somme=0;
    int nbr=0;
    int d=0; int occupation ,h,m,i;
    for (i=0;i<N;i++)
    {
        d=((Tab[i].hs*3600)+(Tab[i].mins*60))-((Tab[i].he*3600)+(Tab[i].mine*60)+(Tab[i].se));
        somme=somme +d;
        nbr=nbr+1;
    }
    occupation = somme/nbr;
    h=occupation/3600;
    occupation = occupation % 3600;
    m=occupation/60;
    occupation= occupation % 60;
    printf("le taux d'occupation de la journee est : %dh %dmin  ",h,m);}




