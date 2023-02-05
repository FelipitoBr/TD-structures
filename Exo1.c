/*
 Exercice 1 (Un peu de géomètrie)
Un point dans un espace 2D est caractérisé par son abscisse et son ordonnée.
1. Déclarer et définir une structure Point. x
2. Ecrire une fonction constructeur_Point() qui retourne un Point dont les attributs ont été saisis par l’utilisateur.
3. Ecrire une procédure affiche_Point( Point x) qui affiche les attributs du Point passés en paramètres sous forme
(abscisse, ordonnée).
4. Dans le programme principal, définir deux variables de type Point. Les définir et les afficher en utilisant les deux
fonctions précédentes.x
5. Ecrire une fonction ajouter_Point(Point a, Point b) qui retourne un Point dont les coordonnées sont la somme
des coordonnées des points a et b.x
6. Écrire une fonction longueur( Point a, Point b) qui retourne la longueur du segment ab.
Indication : On pourra utiliser sqrt() qui calcule la racine carrée. Cette fonction est dans la bibliothèque math.h. Si
cette bibliothèque est incluse dans le code il faut rajouter -lm à la suite de la ligne de commande de compilation. X
7. Écrire une fonction estCarre( Point a, Point b, Point c, Point d) qui retourne 1 si les 4 points passés en paramètre forment un carré.
8. Écrire une fonction sontAlignes( Point a, Point b, Point c) qui retourne 1 si les trois Points passés en paramètres sont alignés (appartiennent à la même droite). X
 * 
 */


#include <stdio.h>
#include <math.h>
typedef struct 
{
	float abscisses;
	float ordonees;
} Point;

Point constructeur_Point(Point x)
{
	printf(" Saisir un l'abscisse: ");
	scanf("%f", &x.abscisses);
	printf(" Saisir un l'ordonees: ");
	scanf("%f", &x.ordonees);
	return x;
}
void affiche_Point(float x, float y)
{
	printf("x: %.2f\n", x );
	printf("y: %.2f", y );
	
}
Point ajouter_Point(Point a, Point b, Point somme)
{
	somme.abscisses=a.abscisses+b.abscisses;
	somme.ordonees=a.ordonees+b.ordonees;
	return somme;
}
double longueur( Point a, Point b)
{
	double l=0;
	l= sqrt(pow(b.abscisses-a.abscisses,2)+pow(b.ordonees-a.ordonees,2));
	return l;

}
int estCarre(Point a, Point b,Point c, Point d )
{
	double ab=longueur(a,b);
	double dc=longueur(d,c);
	double ac=longueur(a,c);
	double bd=longueur(b,d);
	if ((ab==dc)&&(ac==bd))
	{
		if(ab==bd)
			return 1;
	}
		return 0;
}
int sontAlignes( Point a, Point b, Point c)
{
	if((b.abscisses-a.abscisses)*(c.ordonees-a.ordonees)==(b.ordonees-a.ordonees)*(c.abscisses-a.abscisses))
		return 1;
	return 0;

}
int main(int argc, char **argv)
{
	Point a, b,c,d, somme;
	double l=0;
	
	a=constructeur_Point(a);
	b=constructeur_Point(b);
	c=constructeur_Point(c);
	d=constructeur_Point(d);
	
	affiche_Point(a.abscisses,b.ordonees);
	somme=ajouter_Point(a,b,somme);
	l=longueur(a,b);
	printf("\nDistance : %lf", l);
	printf(" here :%d",estCarre(a,b,c,d));
	
	return 0;
}

