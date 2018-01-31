#pragma once
#include "Noeud.h"
#include "sstream" 
#include "string" 
#include "European_Option.h"
#include "American_Option.h"
#include "Option.h"


#include <cmath>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <math.h>
#include <algorithm> 
using namespace std;
class Arbre_Bin_Ptr 
{
public:

	int hauteur_arbre;
	Option * Opt;
	double up;
	double down;
	Noeud * racine;

	void Creation_arbre(Noeud * r);

	void afficher_offset(int offset);
	bool est_feuille(Noeud * element);
	void affichage_arborescence(Noeud * r, int offset);

	void Calcul_Price(Noeud * r);
	static void Afficher_price(Arbre_Bin_Ptr A, Arbre_Bin_Ptr B);
	void Afficher_price();

	Arbre_Bin_Ptr(int hauteur_arbre, Option * Opt);
	~Arbre_Bin_Ptr();
};

