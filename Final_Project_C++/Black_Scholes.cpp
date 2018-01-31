#include "Black_Scholes.h"



Black_Scholes::Black_Scholes()
{

}

Black_Scholes::~Black_Scholes()
{
}


double Black_Scholes::Calcul_Option(European_Option o	, double t)
{
	double premium;
	if (o.t_option == call) {
		premium = o.S*normalDistribution(Calcul_D1(o, t)) - o.K* exp(-(o.r)*(o.T - t))*normalDistribution(Calcul_D2(o, t));
}
	else
	{
		premium = o.K * exp(-o.r*(o.T - t)) * normalDistribution(-Calcul_D2(o, t)) - o.S*normalDistribution(-Calcul_D1(o, t));
	}
	return  premium;
}

double Black_Scholes::Calcul_D1(European_Option o, double t) {
	double D1;
	D1 = (log(o.S / o.K) + (o.r + 0.5*pow(o.sigma, 2))*(o.T - t)) / (o.sigma * sqrt(o.T - t));
	return D1;
};
double Black_Scholes::Calcul_D2(European_Option o, double t) {
	double D2;
	D2 = Calcul_D1(o, t) - o.sigma * sqrt(o.T - t);
	return D2;
};
double Black_Scholes::normalDistribution(double x)
{
	static const double RT2PI = sqrt(4.0*acos(0.0));
	static const double SPLIT = 10. / sqrt(2);
	static const double a[] = { 220.206867912376,221.213596169931,112.079291497871,33.912866078383,6.37396220353165,0.700383064443688,3.52624965998911e-02 };
	static const double b[] = { 440.413735824752,793.826512519948,637.333633378831,296.564248779674,86.7807322029461,16.064177579207,1.75566716318264,8.83883476483184e-02 };

	const double z = fabs(x);
	double Nz = 0.0;

	// if z outside these limits then value effectively 0 or 1 for machine precision
	if (z <= 37.0)
	{
		// NDash = N'(z) * sqrt{2\pi}
		const double NDash = exp(-z*z / 2.0) / RT2PI;
		if (z<SPLIT)
		{
			const double Pz = (((((a[6] * z + a[5])*z + a[4])*z + a[3])*z + a[2])*z + a[1])*z + a[0];
			const double Qz = ((((((b[7] * z + b[6])*z + b[5])*z + b[4])*z + b[3])*z + b[2])*z + b[1])*z + b[0];
			Nz = RT2PI*NDash*Pz / Qz;
		}
		else
		{
			const double F4z = z + 1.0 / (z + 2.0 / (z + 3.0 / (z + 4.0 / (z + 13.0 / 20.0))));
			Nz = NDash / F4z;
		}
	}
	return x >= 0.0 ? 1 - Nz : Nz;
}