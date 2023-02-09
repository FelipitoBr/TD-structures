/*
Exercice 4 (Anniversaire Automatique)
1. Définir une structure Personne qui va contenir :
— Une chaîne de caractères prenom
— Une Date date_naissance (vous pouvez récuperer la structure Date définie à l’exercice 2).
2. Ecrire la fonction constructeur de Personne qui va récupérer les valeurs saisies par l’utilisateur. On pourra utiliser la
fonction constructeur_Date() définie à l’exercice 2.
3. Déclarer un tableau de 10 Personne dont les valeurs seront saisies grâce à la fonction de la question précédente.
4. Ecrire une fonction/procédure bonAnniversaire qui prend en paramètre un tableau de 10 Personnes et une Date. Cet
algorithme doit afficher "Bon anniversaire à " suivi du prénom des Personne dont l’anniversaire est à la Date passée
en paramètre.&zé&
 * 
 */


#include <stdio.h>
#define NPERSSONS 10
typedef struct
{
		int jour;
		int mois;
		int annee;
}Date;
typedef struct
{
	char prenom[50];
	Date bday;
}Personne;

Date constructeur_Date ()
{
	Date date;
	while(1)
	{
		printf("Saisir jour: ");
		scanf(" %d", &date.jour);
		if(date.jour>0 && date.jour<32)
		{
			break;
		}
	}
	while(1)
	{
		printf("Saisir mois: ");
		scanf(" %d", &date.mois);
		if(date.mois>0 && date.mois<13)
		{
			break;
		}
	}
	printf("Saisir anee: ");
	scanf(" %d", &date.annee);
	return date;
}


void build(Personne quelqun[])
{
	for(int i= 0; i <NPERSSONS; i++)
	{
		printf("Saisir un prénom:");
		scanf("%s", quelqun[i].prenom);
		quelqun[i].bday=constructeur_Date();
	}
	
}

void bonAnniversaire(Personne personne[], Date date)
{
	for(int i = 0; i<NPERSSONS; i++)
	{
		if(personne[i].bday.jour==date.jour)
		{
			if(personne[i].bday.mois==date.mois)
			{
				if(personne[i].bday.mois==date.mois)
				{
					printf("Bon anniversaire à %s\n",personne[i].prenom);
				}
			}	
		}
			
	}
	
}
int main(int argc, char **argv)
{	
	Personne personnes[10];
	Date trydate;	
	build(personnes);
	trydate.jour=1;
	trydate.mois=2;
	trydate.annee=3;
	
	bonAnniversaire(personnes, trydate);
	
	return 0;
}

