/*
 * ListaNoOrdenada.cpp
 *
 *  Created on: 10/07/2014
 *      Author: pmartin
 */

#include "Lista.h"

//constructor

Lista::Lista() {
	inicio = NULL;
}
//destructor

Lista::~Lista() {
	pNodo aux;
	while (inicio != NULL) {
		aux = inicio;
		inicio = inicio->sig;
		delete aux;
	}
}

bool Lista::estaVacia() {
	return (inicio == NULL);
}

void Lista::insertarAlPrincipio(int x) {
	inicio = new NodoLista(x, inicio);
}

void Lista::escribirLista() {
	NodoLista *aux;
	cout << "Estado de la lista: " << endl;
	aux = inicio;
	while (aux != NULL) {
		cout << aux->clave << " ";
		aux = aux->sig;
	}
	cout << "\n" << endl;
}

void insercion(pNodo &nodo, int x) {
	if (nodo != NULL) {
		if (nodo->clave == x)
			cout << "Error la clave ya existe" << endl;
		else if (nodo->clave < x)
			insercion(nodo->sig, x);
		else
			nodo = new NodoLista(x, nodo);
	} else
		nodo = new NodoLista(x, NULL);
}
void Lista::insertar(int x) {
	insercion(inicio, x);
}
bool Lista::ejercicioConsulta() {
	bool resul = false;
	int pares = 0;
	int impares = 0;
	pNodo aux = inicio;

	while (aux != NULL) {
		if (aux->clave % 2 == 0) {
			pares++;
		} else {
			impares++;
		}
		aux = aux->sig;
	}
	if (pares == impares && pares != 0 && impares != 0) {
		resul = true;
	} else if (inicio != NULL)
		return false;
	else
		resul = false;
	return resul;
}

void Lista::ejercicioInsercion() {
	int suma = 0;
	pNodo aux = inicio;
	pNodo ultimo = inicio;

	while (aux != NULL) {
		if (aux->clave % 2 == 0) {
			suma = suma + aux->clave;
		} else {
			suma = suma - aux->clave;
		}
		if (aux->sig == NULL) {
			ultimo = aux;
		}
		aux = aux->sig;
	}
	if (ultimo != NULL) {
		ultimo->sig = new NodoLista(suma, NULL);
	} else {
		inicio = new NodoLista(0, NULL);
	}
}

int Lista::ejercicioEliminacion(int dato) {
	int a;
	bool primer = false;
	int res = -999;
	NodoLista *aux;
	if (!primer)
	{
		a = dato+aux->clave;
		primer = true;
	}

	if (aux != NULL) {
		if (aux->clave == a) {
			res = a;
			NodoLista *b = aux;
			aux = aux->sig;
			delete b;
		} else if (aux->clave < a)
			res = ejercicioEliminacion(a);
	}
	return res;
}

