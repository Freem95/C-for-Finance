#pragma once
#include "Option.h"
#include "European_Option.h"
#include "American_Option.h"
#include "Noeud.h"
#include "sstream" 
#include "string"


#include <cmath>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <math.h>
#include <algorithm> 
class Arbre_BinLattice
{
public:

	int hauteur_arbre;

	double up;
	double down;

	Noeud ** Mat_A;

	void Affect_Bin(Option * Opt);
	void Affect_Bin_C_P_Euro(European_Option * Opt);
	void Affect_Bin_C_P_Amer(American_Option * Opt);
	void Mat_Verif_Allocation();
	void Mat_Verif_Allocation_V_C_P();

	void Display_Price_A(Option * Opt);
	void Display_Price_E(Option * Opt);

	Arbre_BinLattice(int hauteur_arbre);
	~Arbre_BinLattice();
};

