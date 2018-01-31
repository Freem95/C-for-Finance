#include "Monte_Carlo.h"


Monte_Carlo::Monte_Carlo(Option * Opt, int Nbr_Simu, int inter)
{ 
	this->Opt = Opt;
	this->t = t;
	this->Nbr_Simu = Nbr_Simu;
	this->inter = inter;

}


Monte_Carlo::~Monte_Carlo()
{
}

double* Monte_Carlo::Calcul_Option() {
	double *  myArray = new double(2);

	double res = 0;
	double tmpc;
	double tmpp;
	double sommec;
	double sommep;
	double moyennec;
	double moyennep;

	double randomNumber = 0;
	double expo;

	sommec = 0;
	sommep = 0;
	moyennec = 0;
	moyennep = 0;

	for (int i = 0; i < Nbr_Simu; i++) {
		res = Opt->S;

		for (int j = 0; j < inter; j++) {
			randomNumber = randn(0, 1);
			double power = pow(Opt->sigma, 2);
			double racine = sqrt(Opt->T / inter);
			expo = exp((Opt->r - power / 2.0) * (Opt->T / inter) + Opt->sigma * racine * randomNumber);

			res = res * expo;
		}

		tmpc = max(res - Opt->K, 0.00);
		tmpp = max(Opt->K - res, 0.00);

		sommec = sommec + tmpc;
		sommep = sommep + tmpp;
	}


	moyennec = sommec / Nbr_Simu;
	moyennep = sommep / Nbr_Simu;

	myArray[0] = moyennec;
	myArray[1] = moyennep;
	return myArray;
}

void Monte_Carlo::afficher_Price() {

	cout << "--------------    Monte_Carlo    --------------" << endl;
	printf("\n");
	cout << "Nombre de simulation : " << Nbr_Simu << endl;
	printf("\n");
	cout << "Le premium du call est de " << Calcul_Option()[0] << endl;
	printf("\n");
	cout << "Le premium du put est de " << Calcul_Option()[1] << endl;
	printf("\n");
}

double Monte_Carlo::randn(double mu, double sigma)
{
	double U1, U2, W, mult;
	static double X1, X2;
	static int call = 0;

	if (call == 1)
	{
		call = !call;
		return (mu + sigma * (double)X2);
	}

	do
	{
		U1 = -1 + ((double)rand() / RAND_MAX) * 2;
		U2 = -1 + ((double)rand() / RAND_MAX) * 2;
		W = pow(U1, 2) + pow(U2, 2);
	} while (W >= 1 || W == 0);

	mult = sqrt((-2 * log(W)) / W);
	X1 = U1 * mult;
	X2 = U2 * mult;

	call = !call;

	return (mu + sigma * (double)X1);
}