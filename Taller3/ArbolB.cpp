#include "pch.h"
#include "ArbolB.h"


ArbolB::ArbolB()
{
}

Nodo * ArbolB::buscarNodoAgregacion(Nodo* nodo, int id) //busca el nodo al que hay que agregar
{
	if (!nodo->tienehijos) {
		return nodo;
	}
	if (id > nodo->idclaves[nodo->idclaves.size() - 1]) {
		return buscarNodoAgregacion(nodo->hijos[nodo->idclaves.size()], id);
	}
	for (int i = 0; i < this->m - 1; i++)
	{
		if (id < nodo->idclaves[i]) {
			return buscarNodoAgregacion(nodo->hijos[i], id);
		}
	}
}

Nodo * ArbolB::buscarNodoAnterior(Nodo * nodo, Nodo* nodo_original, int id) // retorna el nodo anterior al nodo de agregacion
{
	if (id > nodo->idclaves[nodo->idclaves.size() - 1]) {
		if (nodo->hijos[nodo->idclaves.size()] == nodo_original) {
			return nodo;
		}
		return buscarNodoAnterior(nodo->hijos[nodo->idclaves.size()], nodo_original, id);
	}
	for (int i = 0; i < this->m - 1; i++) {
		if (id < nodo->idclaves[i]) {
			if (nodo->hijos[i] == nodo_original) {
				return nodo;
			}
			return buscarNodoAnterior(nodo->hijos[i], nodo_original, id);
		}
	}
}

void ArbolB::agregarDato(Nodo* nodo, int id)
{
	if (isOverflow(nodo)) { // pregunta si esta lleno
		Nodo * nodoaux = nullptr;
		Nodo * nodoaux2 = nullptr;
		vector<int> aux = nodo->idclaves;
		aux.push_back(id);
		sort(aux.begin(), aux.end());
		int n = ceil((double)m / 2) - 1;
		if (nodo == this->raiz) {
			nodoaux = new Nodo(m, false);
			nodoaux2 = new Nodo(m, false);
			for (int i = 0; i < n; i++) // se copian los datos izquierdos al nodo izquierdo
			{
				nodoaux->idclaves.push_back(aux[i]);
				nodoaux->hijos[i] = nodo->hijos[i];
			}
			nodoaux->hijos[n] = nodo->hijos[n]; // residuo de referencia
			for (int i = n + 1; i < m; i++) { // se copian los datos derechos al nodo derecho
				nodoaux2->idclaves.push_back(aux[i]);
				nodoaux2->hijos[i - n + 1] = nodo->hijos[i];
			}
			nodoaux2->hijos[nodoaux->idclaves.size()] = nodo->hijos[m]; // residuo
			nodo->idclaves.clear();
			nodo->limpiarHijos();
			nodo->idclaves.push_back(aux[n]);
			nodo->hijos[0] = nodoaux;
			nodo->hijos[1] = nodoaux2;
		}
		else {
			nodoaux = buscarNodoAnterior(this->raiz, nodo, id);
			agregarDato(nodoaux, aux[n]);
			nodoaux2 = buscarNodoAnterior(this->raiz, nodo, id);
			Nodo *nodoaux3 = new Nodo(this->m, false);
			for (int i = n + 1; i < m; i++) // se copian los datos del lado derecho al nuevo nodo
			{
				nodo->idclaves.erase(nodo->idclaves.begin() + i - 1); // se eliminan los datos repetidos del nodo problema
				nodoaux3->idclaves.push_back(aux[i]);
				nodoaux3->hijos[i - n + 1] = nodo->hijos[i];
			}
			nodoaux3->hijos[nodoaux->idclaves.size()] = nodo->hijos[m]; // residuo de referencia de hijo
			nodoaux2->hijos[nodoaux2->idclaves.size()] = nodoaux3;
			nodoaux3 = NULL;
			delete nodoaux3;
		}
		nodoaux = nodoaux2 = NULL;
		delete nodoaux, nodoaux2;

	}
	nodo->idclaves.push_back(id); // si no esta lleno se agrega
	sort(nodo->idclaves.begin(), nodo->idclaves.end());
	return;

	//if (id > nodo->idclaves[nodo->idclaves.size() - 1]) {
	//	agregarDato(nodo->hijos[nodo->idclaves.size()], id);
	//	return;
	//}
	//for (int i = 0; i < this->m - 1; i++)
	//{
	//	if (id < nodo->idclaves[i]) {
	//		agregarDato(nodo->hijos[i], id);
	//		return;
	//	}
	//}







	/*if (nodo->idclaves.size() == (this->m - 1)) {
		vector<int> aux = nodo->idclaves;
		if (!nodo->tienehijos) {



		}
		else if (nodo->tienehijos) {


		}

	}
	else if (nodo->tienehijos) {
		if (id > nodo->idclaves[nodo->idclaves.size() - 1]) {
			agregarDato(nodo->hijos[nodo->idclaves.size()], id);
		}
		for (int i = 0; i < this->m - 1; i++)
		{
			if (id < nodo->idclaves[i]) {
				agregarDato(nodo->hijos[i], id);
			}
		}
	}
	else {
		nodo->idclaves.push_back(id);
		sort(nodo->idclaves.begin(), nodo->idclaves.end());
	}*/






	//vector <int> aux = nodo->idclaves;
	//if (id > aux[aux.size() - 1]) {
	//	aux.push_back(id);
	//}
	//else {
	//	for (int i = 0; i < this->m - 1; i++)
	//	{
	//		if (id < aux[i]) {
	//			aux.insert(aux.begin() + i, id);
	//		}
	//	}
	//}
	//Nodo *nodoaux;
	//Nodo *hijo1 = new Nodo(this->m, true);
	//Nodo *hijo2 = new Nodo(this->m, true);
	//int n = ceil((double)m / 2);
	//if (nodo == this->raiz && !nodo->tienehijos) {
	//	hijo1->idclaves.push_back(aux[n]);
	//	aux.erase(aux.begin() + n);
	//	for (int i = n; i < aux.size(); i++) {
	//		hijo2->idclaves.push_back(aux[i]);
	//		this->raiz->idclaves.erase(this->raiz->idclaves.begin() + i);
	//	}
	//	hijo1->hijos[0] = this->raiz;
	//	hijo1->hijos[1] = hijo2;
	//	nodoaux = hijo1;
	//	this->raiz = hijo1;
	//	hijo1 = nodoaux;
	//	this->raiz->tienehijos = true;
	//}

}

bool ArbolB::isOverflow(Nodo * nodo)
{
	return (nodo->idclaves.size() < (m - 1)) ? true : false;
}


ArbolB::~ArbolB()
{
}
