#pragma once
#include "Nodo.h"


class ArbolB
{
public:
	ArbolB();
	Nodo* buscarNodoAgregacion(Nodo* nodo, int id);
	Nodo * buscarNodoAnterior(Nodo * nodo, Nodo * nodo_original, int id);
	void agregarDato(Nodo* nodo, int id);
	bool isOverflow(Nodo* nodo);
	~ArbolB();

private:
	int m;
	Nodo* raiz;
};

