#include "Noeud.h"

Noeud::Noeud()
{
	p_up = nullptr;
	p_down = nullptr;
	p_parent = nullptr;
	exercice_call = 0;
	value = 0;
	val_call = 0;
	val_put = 0;
}

Noeud::~Noeud()
{
}

void Noeud::Assigner_pointeur_Noeud(Noeud* p_up, Noeud* p_down) {
	this->p_up = p_up;
	this->p_down = p_down;
}
