#include "Option.h"



Option::Option(double r, double sigma, double K, double T, double S, double b, type_option t_option)
{
	this->r = r;
	this->sigma = sigma;
	this->K = K;
	this->T = T;
	this->S = S;
	this->b = b;
	this->t_option = t_option;
}


Option::~Option()
{
}
