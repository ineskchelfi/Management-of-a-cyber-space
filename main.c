#include <stdio.h>
#include <stdlib.h>
#include "cyber.h"
#include<string.h>
#include <time.h>

int main()
{
    internaute tab_inter[100];
    int taille_tab=0;
    char idt[10];
    int rech=-1;
    int choix;
    char rep[3];
    int j,m,a;
    int recherche=-1;

    FILE *FICHIER;



     FILE* fichier=fopen("cyberespace_data.txt","rt");
    if(fichier==NULL)
    {
        printf("\n L'espace internaute est vide ! \n ************* \n ");
        printf("Tapez [entrer] pour continuer... ");
        getch();
        system("cls");
    }
    else
    {
        int i=0;
        while(!feof(fichier))
        {
            fscanf(fichier,"%d %d %d %d %d %d %d %d %d %d %d\n",&tab_inter[i].cinn,&tab_inter[i].numPC,&tab_inter[i].annee,&tab_inter[i].moise,&tab_inter[i].jour,&tab_inter[i].he,&tab_inter[i].mine,&tab_inter[i].se,&tab_inter[i].hs,&tab_inter[i].mins);
            i++;
        }
        fclose(fichier);
        taille_tab=i;
    }


while(1)
{

    printf("\n****************************\n");
    printf("\n 1. Saisir un tableau d'internautes");
    printf("\n 2. Ajouter un internaute");
    printf("\n 3. Rechercher un internaute");
    printf("\n 4. Modifier un internaute");
    printf("\n 5. Supprimet un internaute");
    printf("\n 6. Afficher la liste des internaute");
    printf("\n 7. Afficher la liste des internautes pour une date donnee");
    printf("\n 8. Afficher le taux d'occupation de la journee");
    printf("\n 0. Quitter\n");

    printf("\n Introduire votre choix");
    printf("\n****************************\n");

    scanf("%d",&choix);
    switch(choix)
    {

    case 1:
        {
            taille_tab=Saisir_Tab_inter(tab_inter,taille_tab);
            break;

        }
    case 2:
        {
           taille_tab=Ajouter_Tab_inter(tab_inter,taille_tab);
           break;
        }
    case 3:
        {
          printf("Introduire l'internaute a chercher : ");
          scanf("%s", &idt);
          rech=rechercher_inter(tab_inter,taille_tab,idt);
          if(rech!=-1)
           {
             afficher_inter(tab_inter[rech]);
           }
           else printf("internaute inexistant\n");
           break;
         }
    case 4:
        {
          printf("Introduire la cin de l'internaute a modifier : ");
          scanf("%s", &idt);
          rech=rechercher_inter(tab_inter,taille_tab,idt);
          if(rech!=-1)
           {
             afficher_inter(tab_inter[rech]);
             printf("\n Vous etes sure de vouloir modifier cet internaute ? (oui/non)  ");
             scanf("%s",&rep);
             if(strcmp(rep,"oui")==0)
             {
                Modifier_inter(tab_inter, taille_tab, rech);
             }
             else break;
           }
           else printf("internaute inexistant\n");
           break;
        }
    case 5:
        {
          printf("Introduire la cin de l'internaute a supprimer : ");
          scanf("%s", &idt);
          rech=rechercher_inter(tab_inter,taille_tab,idt);
          if(rech!=-1)
           {
             afficher_inter(tab_inter[rech]);
             printf("\n Vous etes sure de vouloir supprimer cet internaute ?  ");
             scanf("%s", &rep);
             if(strcmp(rep,"oui")==0)
             {
                Supprimer_inter(tab_inter,taille_tab,rech);
                break;
             }
           }
           else printf("internaute inexistant\n");
           break;
        }
    case 6:
        {
            afficher_Tab_inter(tab_inter,taille_tab);
            break;
        }

    case 7 :
        {

            printf("saisir le jour\n");
            scanf("%d",&j);
            printf("saisir le mois\n");
            scanf("%d",&m);
            printf("saisir l'annee\n");
            scanf("%d",&a);
            recherche=rechercher_par_date(tab_inter,taille_tab,j,m,a);
          if(recherche!=-1)
            afficher_Tab_inter(tab_inter,taille_tab);
        else printf("Aucun internaute \n");
            break;

        }

    case 8 :
        {
            taux_occupation(tab_inter,taille_tab);
        }


    case 0:
        {
            FILE *fichier=fopen("cyberespace_data.txt","wt");
    if(fichier==NULL)
        {
            printf("\n Erreur d'ouverture de data base ! \n ***************\n Taper [entrer] pour continuer... ");
            getch();
        }
    else
        {
            for(int i=0; i<taille_tab ;i++)
            {
            fprintf(fichier,"%d %d %d %d %d %d %d %d %d %d %d\n",&tab_inter[i].cinn,&tab_inter[i].numPC,&tab_inter[i].annee,&tab_inter[i].moise,&tab_inter[i].jour,&tab_inter[i].he,&tab_inter[i].mine,&tab_inter[i].se,&tab_inter[i].hs,&tab_inter[i].mins);
            }
        fclose(fichier);
        }

              exit(0);

          }

    default:
        {
           printf("\n choix erronee");
        }
    }// swich

}//while

    return 0;
}

