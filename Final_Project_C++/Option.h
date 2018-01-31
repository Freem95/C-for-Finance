#pragma once
enum type_option { call, put };

class Option
{
public:
	double r; //Interest rate
	double sigma; //Volatility
	double K;//Strike price
	double T;//Expiry date (or maturity)
	double S;//Underlying price
	double b;//Cost of carry
	type_option t_option;

	Option(double r, double sigma, double K, double T, double S, double b, type_option t_option);
	~Option();

};

