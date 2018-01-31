#include "Arbre_BinLattice.h"



Arbre_BinLattice::Arbre_BinLattice(int hauteur_arbre)
{
	this->hauteur_arbre = hauteur_arbre;
	Mat_A = new Noeud*[hauteur_arbre];

	for (int a = 0; a <hauteur_arbre; a++) {
		Mat_A[a] = new Noeud[hauteur_arbre];// -a - 1];
	}
}


void Arbre_BinLattice::Affect_Bin(Option * Opt) {

	up = exp(Opt->sigma*sqrt(Opt->T / hauteur_arbre));
	down = 1 / up;

	Mat_A[0][0].value = Opt->S;
	for (int col = 1; col < hauteur_arbre; col++) {

		for (int lig = 0; lig < col + 1; lig++) {
			if (lig != col) {
				Mat_A[lig][col].value = Mat_A[lig][col - 1].value * up;

			}
			else {
				Mat_A[lig][col].value = Mat_A[lig - 1][col - 1].value * down;
			}
		}
	}
}
void Arbre_BinLattice::Affect_Bin_C_P_Euro(European_Option * Opt) {

	up = exp(Opt->sigma*sqrt(Opt->T / hauteur_arbre));
	down = 1 / up;

	double R = exp(Opt->r / hauteur_arbre);
	double q = (R - down) / (up - down);

	for (int col = hauteur_arbre - 1; col >= 0; col--) {
		for (int lig = col; lig >= 0; lig--) {
			if (col == hauteur_arbre - 1) {
				Mat_A[lig][col].val_call = max(Mat_A[lig][col].value - Opt->K, 0.00000);
				Mat_A[lig][col].val_put = max(Opt->K - Mat_A[lig][col].value, 0.00000);
			}
			else {
				Mat_A[lig][col].val_call = ((q * Mat_A[lig][col + 1].val_call + (1 - q) * Mat_A[lig + 1][col + 1].val_call)) / R;
				Mat_A[lig][col].val_put = ((q * Mat_A[lig][col + 1].val_put + (1 - q) * Mat_A[lig + 1][col + 1].val_put)) / R;
			}
		}
	}
}

void Arbre_BinLattice::Affect_Bin_C_P_Amer(American_Option * Opt) {

	up = exp(Opt->sigma*sqrt(Opt->T / hauteur_arbre));
	down = 1 / up;

	double R = exp(Opt->r / hauteur_arbre);
	double q = (R - down) / (up - down);

	for (int col = hauteur_arbre - 1; col >= 0; col--) {
		for (int lig = col; lig >= 0; lig--) {
			if (col == hauteur_arbre - 1) {
				Mat_A[lig][col].val_call = max(Mat_A[lig][col].value - Opt->K, 0.00000);
				Mat_A[lig][col].val_put = max(Opt->K - Mat_A[lig][col].value, 0.00000);
			}
			else {
				Mat_A[lig][col].val_call = max(Mat_A[lig][col].value - Opt->K, ((q * Mat_A[lig][col + 1].val_call + (1 - q) * Mat_A[lig + 1][col + 1].val_call)) / R);
				if (Mat_A[lig][col].value - Opt->K > ((q * Mat_A[lig][col + 1].val_call + (1 - q) * Mat_A[lig + 1][col + 1].val_call)) / R) {
					Mat_A[lig][col].exercice_call = true;
				}
				Mat_A[lig][col].val_put = max(Opt->K - Mat_A[lig][col].value, ((q * Mat_A[lig][col + 1].val_put + (1 - q) * Mat_A[lig + 1][col + 1].val_put)) / R);
				if (Opt->K - Mat_A[lig][col].value > ((q * Mat_A[lig][col + 1].val_put + (1 - q) * Mat_A[lig + 1][col + 1].val_put)) / R) {
					Mat_A[lig][col].exercice_put = false;
				}
			}
		}
	}
}
void Arbre_BinLattice::Display_Price_A(Option * Opt) {

	cout << "--------------    Arbre_BinLattice    --------------" << endl;
	printf("\n");
	cout << "Option de type American" << endl;
	printf("\n");
	cout << "Matrice de hauteur : " << hauteur_arbre << endl;
	printf("\n");
	cout << "Le premium du call est de " << Mat_A[0][0].val_call << endl;
	printf("\n");
	cout << "Le premium du put est de " << Mat_A[0][0].val_put << endl;
	printf("\n");
}
void Arbre_BinLattice::Display_Price_E(Option * Opt) {

	cout << "--------------    Arbre_BinLattice    --------------" << endl;
	printf("\n");
	cout << "Option de type Europeen" << endl;
	printf("\n");
	cout << "Matrice de hauteur : " << hauteur_arbre << endl;
	printf("\n");
	cout << "Le premium du call est de " << Mat_A[0][0].val_call << endl;
	printf("\n");
	cout << "Le premium du put est de " << Mat_A[0][0].val_put << endl;
	printf("\n");
}
void Arbre_BinLattice::Mat_Verif_Allocation() {

	for (int i = 0; i < hauteur_arbre; i++) {
		printf("\n");
		for (int j = 0; j < hauteur_arbre; j++) {
			cout << Mat_A[i][j].value << " ";
		}
	}
}
void Arbre_BinLattice::Mat_Verif_Allocation_V_C_P() {

	for (int i = 0; i < hauteur_arbre; i++) {
		printf("\n");
		for (int j = 0; j < hauteur_arbre; j++) {
			cout << Mat_A[i][j].val_put << " ";
		}
	}
}


Arbre_BinLattice::~Arbre_BinLattice()
{
}
