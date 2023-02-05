/*
 * Exercice 2 (Gestion de date)
Une date peut être écrite sous forme jour/mois/année.
Pour simplifier cet exercice on pourra considérer que tous les mois ont 30 jours.
1. Déclarer et définir une structure Date composée de trois entiers représentant respectivement le jour le mois et l’année.
2. Écrire une fonction constructeur constructeur_Date() qui retourne une variable de type Date dont les attributs
auront été saisis par l’utilisateur. Si les valeurs saisies sont incorrectes, on redemandera la saisie.
3. Écrire une procédure affiche_Date(Date d) qui affiche les attributs de la Date passée en paramètre sous forme
jour/mois/année.
4. Tester les deux fonctions précédentes en déclarant une variable de type Date dans le programme principal et en
l’affichant.
5. Écrire une fonction ajoute_jour(Date a, int jour) qui ajoute un nombre de jours à la date passée en paramètre et
retourne la nouvelle date obtenue.
6. Écrire une fonction enlever_jour(Date a, int jour) qui retire un nombre de jours à la date passée en paramètre
et retourne la nouvelle date obtenue.
 * 
 * 
 */


#include <stdio.h>

typedef struct
{
	int jour;
	int mois;
	int annee;
}Date;

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
void affiche_Date(Date d)
{
	printf("%d/%d/%d", d.jour, d.mois, d.annee);
}
int ajoute_jour(Date a, int jour)
{
	a.jour+=jour;
	return a.jour;
}
int enlever_jour(Date a, int jour)
{
	a.jour-=jour;
	return a.jour;
}
int main(int argc, char **argv)
{
	Date date;
	int jour;
	date=constructeur_Date();
	affiche_Date(date);

	while(1)
	{
		printf("\n saisir une quantité de jours à ajouter");
		scanf("%d", &jour);
		if(jour>0 && (date.jour+jour<32))
		{
			break;
		}
	}
	date.jour=ajoute_jour(date,jour);
	printf("%d",date.jour);
	while(1)
	{
		printf("\n saisir une quantité de jours à enlever");
		scanf("%d", &jour);
		if(jour>0 && (date.jour-jour>0))
		{
			break;
		}
		
	}
	enlever_jour(date, jour);
	return 0;
}

