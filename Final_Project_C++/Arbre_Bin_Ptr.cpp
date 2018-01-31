#include "Arbre_Bin_Ptr.h"




Arbre_Bin_Ptr::Arbre_Bin_Ptr(int hauteur_arbre, Option	 * Opt)
{

	this->Opt = Opt;
	this->hauteur_arbre = hauteur_arbre;
	up = exp(Opt->sigma*sqrt(Opt->T / hauteur_arbre));
	down = 1 / up;

	racine = new Noeud();

	racine->value = Opt->S;

	racine->hauteur = 0;
}

Arbre_Bin_Ptr::~Arbre_Bin_Ptr()
{
}

void Arbre_Bin_Ptr::Creation_arbre(Noeud * r) {
	if (r->hauteur < hauteur_arbre - 1) {

		Noeud * noeud_fils_up = new Noeud();
		r->p_up = noeud_fils_up;
		r->p_up->value = r->value * up;
		r->p_up->hauteur = r->hauteur + 1;
		Creation_arbre(r->p_up);

		Noeud * noeud_fils_down = new Noeud();
		r->p_down = noeud_fils_down;
		r->p_down->value = r->value * down;
		r->p_down->hauteur = r->hauteur + 1;
		Creation_arbre(r->p_down);
	}
}

void Arbre_Bin_Ptr::Calcul_Price(Noeud * crt) {

	if (est_feuille(crt)) {
		crt->val_call = crt->value - Opt->K > 0 ? crt->value - Opt->K : 0;
		crt->val_put = Opt->K - crt->value > 0 ? Opt->K - crt->value : 0;
	}
	else {

		Calcul_Price(crt->p_up);
		Calcul_Price(crt->p_down);

		double R = exp(Opt->r / hauteur_arbre);
		double q = (R - down) / (up - down);

		crt->val_call = (q*(crt->p_up->val_call) + (1 - q)*(crt->p_down->val_call)) / R;
		crt->val_put = (q*(crt->p_up->val_put) + (1 - q)*(crt->p_down->val_put)) / R;
	}

}

void Arbre_Bin_Ptr::Afficher_price(Arbre_Bin_Ptr A, Arbre_Bin_Ptr C) {

	A.Creation_arbre(A.racine);
	A.Calcul_Price(A.racine);
	C.Creation_arbre(C.racine);
	C.Calcul_Price(C.racine);



	cout << ((A.racine->val_call + C.racine->val_call) / 2) << endl;
	cout << ((A.racine->val_put + C.racine->val_put) / 2) << endl;
}

void Arbre_Bin_Ptr::Afficher_price() {

	cout << "--------------    Arbre_Bin_Ptr    --------------" << endl;
	printf("\n");
	cout << "Matrice de hauteur : " << hauteur_arbre << endl;
	printf("\n");
	cout << "Le premium du call est de " << racine->val_call << endl;
	printf("\n");
	cout << "Le premium du put est de " << racine->val_put << endl;
	printf("\n");
}

void Arbre_Bin_Ptr::afficher_offset(int offset) {
	for (int i = 0; i < offset; i++) {
		printf(" ");
	}
}
bool Arbre_Bin_Ptr::est_feuille(Noeud * element) {
	return ((element->p_up) == NULL && (element->p_down) == NULL);
}
void Arbre_Bin_Ptr::affichage_arborescence(Noeud * r, int offset) {
	if (r != NULL) {
		printf("\n");
		afficher_offset(offset);
		if (offset != 0) {
			printf("|");
		}

		cout << r->value << endl;

		if (est_feuille(r) != NULL && (r->p_up == NULL)) {
			printf("\n");
			afficher_offset(offset + 1);
			printf("|/");
		}
		affichage_arborescence(r->p_up, offset + 1);

		if (!est_feuille(r) && r->p_up == NULL) {
			printf("\n");
			afficher_offset(offset + 1);
			printf("|/");
		}
		affichage_arborescence(r->p_down, offset + 1);
	}
}

