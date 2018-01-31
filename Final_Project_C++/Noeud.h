#pragma once
#include <memory>


using namespace std;

class Noeud
{
private:
	

public:

	Noeud * p_parent;
	Noeud * p_up;
	Noeud * p_down;
	double value;
	int hauteur;
	double val_call;
	double val_put;
	bool exercice_call;
	bool exercice_put;

	void Assigner_pointeur_Noeud(Noeud*p_up, Noeud *p_down);
	Noeud();
	~Noeud();
};

