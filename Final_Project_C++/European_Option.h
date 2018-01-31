#pragma once
#include "Option.h"
#include "Noeud.h"

#include <math.h>

class European_Option : public Option
{
public:

	European_Option(double r, double sigma, double K, double T, double S, double b, type_option t_option) : Option(r, sigma, K, T, S, b, t_option) {};
	~European_Option();
};

