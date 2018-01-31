

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <memory>
#include <cmath>

#include "Black_Scholes.h"
#include "European_Option.h"
#include "Monte_Carlo.h"
#include "Arbre_BinLattice.h"
#include "Arbre_Bin_Ptr.h"

#include "Noeud.h"
#include "sstream" 
#include "string" 

using namespace std;


int main() {


	srand((unsigned)time(NULL));

	European_Option * Ptr_E = new European_Option(0.01, 0.2, 40, 1, 40, 0, put);
	American_Option * Ptr_A = new American_Option(0.01, 0.2, 40, 1, 40, 0, put);

	Arbre_Bin_Ptr A = Arbre_Bin_Ptr(20, Ptr_E);
	A.Creation_arbre(A.racine);
	A.Calcul_Price(A.racine);
	A.Afficher_price();

	printf("\n");
	
	Arbre_BinLattice t_E(200);
	t_E.Affect_Bin(Ptr_E);
	t_E.Affect_Bin_C_P_Euro(Ptr_E);
	t_E.Display_Price_E(Ptr_E);

	printf("\n");
	Arbre_BinLattice t_A(200);
	t_A.Affect_Bin(Ptr_A);
	t_A.Affect_Bin_C_P_Amer(Ptr_A);
	t_A.Display_Price_A(Ptr_A);
	
	printf("\n");
	Monte_Carlo M = Monte_Carlo(Ptr_E, 10000, 30);
	M.afficher_Price();

	

	system("pause");
}

