#include "pch.h"
#include "Nodo.h"


Nodo::Nodo(int m, bool esHijo)
{
	this->esHijo = esHijo;
	this->tienehijos = false;
	for (int i = 0; i < m - 1; i++) {
		this->hijos.push_back(nullptr);
	}
}

void Nodo::limpiarHijos()
{
	this->hijos.clear;
	for (int i = 0; i < this->hijos.size() - 1; i++) {
		this->hijos.push_back(nullptr);
	}
}




Nodo::~Nodo()
{
}
