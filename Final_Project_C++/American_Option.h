#pragma once
#include "Option.h"
#include "Noeud.h"

#include <math.h>
class American_Option : public Option
{
public:
	American_Option(double r, double sigma, double K, double T, double S, double b, type_option t_option) : Option(r, sigma, K, T, S, b, t_option) {};
	~American_Option();
};

