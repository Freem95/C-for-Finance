#pragma once
#include "European_Option.h"
#include <math.h>       /* log */

class Black_Scholes
{
public:

	double Calcul_Option(European_Option o, double t);
	double Calcul_D1(European_Option o, double t);
	double Calcul_D2(European_Option o, double t);
	double normalDistribution(double x);
	Black_Scholes();
	~Black_Scholes();
};

