/*Exercice 3 (combat !)
Dans cet exercice, nous allons simuler un combat épique de ninjas.
1. Voici les caractéristiques d’un Ninja :
— son attaque
— sa défense
— son esquive
— ses points de vie
— son nom, que l’on définira comme un tableau de caractères.
Toutes les caractéristiques autres que le nom peuvent être représentées par des réels. Définir la structure Ninja.
2. Dans le programme principal, déclarer deux variables Ninjas. Les valeurs de leurs champs seront initialisées avec des
valeurs aléatoires telles que :
— 5.0 <= attaque <= 10.0
— 2.0 <= défense <= 4.0
— 0.1 <= esquive <= 0.2
— 80.0 <= vie <= 100.0
* 3. Créer une procédure combat(Ninja a, Ninja b) qui prend en paramètres deux variables de type Ninja. Un combat
se déroule de la manière suivante : le Ninja a attaque, puis le Ninja b. Le combat se déroule jusqu’à ce qu’un des
combattants s’écroule (ses points de vie tombent à 0). Un round se passe comme suit :
— le programme effectue un jet de valeur aléatoire entre 0.0 et 1.0
— si cette valeur est plus petite ou égale à la valeur d’esquive du ninja défenseur, alors il ne se passe rien
— sinon le programme récupère la valeur d’attaque de l’attaquant, il lui soustrait la valeur de défense du défenseur
(en faisant attention à limiter la valeur à 0 : il ne faut pas descendre en-dessous.) : c’est la valeur des dégâts.
— le programme réduit les points de vie du défenseur du montant des dégâts calculés précédemment.
Ajouter des affichages dans cette fonction pour que l’on puisse suivre la manière dont se déroule le combat. Afficher le
gagnant du combat à la fin de la procédure.
4. Lancer le combat entre vos deux Ninjas déclarés dans le programme principal.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//~ #ifdef _unix_
	//~ void wait(void)
	//~ {
		//~ sleep(1);
	//~ }
//~ #elseif defined(_WIN32) || defined(WIN32)
	//~ void wait(void)
	//~ {
		//~ sleep(1000);
	//~ }
//~ #endif

typedef struct
{
	float attaque;
	float defense;
	float esquive;
	float pv;
	char nom[50];
	
}Ninjago;
Ninjago buildNinja(Ninjago Ninja)
{
	Ninja.attaque= rand()%6+5;
	Ninja.defense= rand()%3+2;
	Ninja.esquive= ((float)rand()/(float)(RAND_MAX)) * 0.2;
	if(Ninja.esquive==0)
		Ninja.esquive=0.1;
	Ninja.pv= rand()%21+80;
	printf("Saisir nom du ninja:");
	scanf("%s", Ninja.nom);
	return Ninja;
}
void combat(Ninjago a, Ninjago b)
{
	float degat=0;
	while(a.pv>0 &&b.pv>0)
	{
		printf("\nNinja %s-kun pv: %f et Ninja %s-kun pv: %f ",a.nom, a.pv,b.nom, b.pv);
		printf("\n %s-kun attaque",a.nom);
		if((float)rand()/(float)RAND_MAX*0.2> b.esquive)
		{
			if(a.attaque<b.defense)
				degat=0;
			else	
				degat=a.attaque-b.defense;
			b.pv-=degat;
			if(b.pv<=0)
				b.pv=0;
		}
		else
			printf("\n %s-kun a raté l'attaque",a.nom);
		sleep(2);
		printf("\n %s-kun attaque maintenant",b.nom);
		if((float)rand()/(float)RAND_MAX*0.2> a.esquive)
		{
			if(b.attaque<a.defense)
				degat=0;
			else	
				degat=b.attaque-a.defense;
			a.pv-=degat;
			if(a.pv<=0)
				a.pv=0;
		}
		else
			printf("\n %s-kun a raté l'attaque",b.nom);
	
		sleep(2);
	}
}
int main(int argc, char **argv)
{
	srand(time(NULL));
	Ninjago Ninja1, Ninja2;
	Ninja1=buildNinja(Ninja1);
	Ninja2=buildNinja(Ninja2);
	//~ combat(Ninja1,Ninja2);
	printf("%f, %f",Ninja1.esquive,Ninja2.esquive);
	if(Ninja1.esquive>Ninja2.esquive)
		combat(Ninja1,Ninja2);
	else
		combat(Ninja2,Ninja1);
	
	return 0;
}
//float x = ((float)rand()/(float)(RAND_MAX)) * a; generate a random float number from 1 to a
 


