#pragma once
#include "European_Option.h"
#include "Option.h"

#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <stdlib.h>     /* srand, rand */
#include <time.h>		/* time */

using namespace std;

class Monte_Carlo
{
public:

	Option * Opt;
	double t;
	int Nbr_Simu; 
	int inter;

	double* Calcul_Option();



	void afficher_Price();
	Monte_Carlo(Option * Opt, int Nbr_Simu, int inter);
	double randn(double mu, double sigma);

	~Monte_Carlo();
};

