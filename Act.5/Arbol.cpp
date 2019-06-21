/*
 * Arbol.cpp
 *
 *  Created on: 21/12/2014
 *      Author: pmartin
 */

#include "Arbol.h"
#include <fstream>
#include <queue>
#include <stdlib.h>

Arbol::Arbol () {
	raiz = NULL;
}
Arbol::Arbol (int dato) {
	raiz = new NodoArbol (dato);
}
void destruir (pNodoArbol &nodo) {
	if (nodo != NULL) {
		destruir (nodo->iz);
		destruir (nodo->de);
		delete nodo;
		nodo = NULL;
	}
}
Arbol::~Arbol () {
	pNodoArbol nodo = raiz;
	destruir (nodo);
	raiz = NULL;
}

void auxPreOrden (pNodoArbol nodo) {
	if (nodo != NULL) {
		cout << nodo->clave << " "; 	// Nodo
		auxPreOrden (nodo->iz);	 		// Izquierda
		auxPreOrden (nodo->de);			// Derecha
	}
}

void Arbol::preOrden () {
	auxPreOrden (raiz);
	cout << "FIN" << endl;
}

void auxOrdenCentral (pNodoArbol nodo) {
	if (nodo != NULL) {
		auxOrdenCentral (nodo->iz);	 	// Izquierda
		cout << nodo->clave << " "; 	// Nodo
		auxOrdenCentral (nodo->de);		// Derecha
	}
}

void Arbol::ordenCentral () {
	auxOrdenCentral (raiz);
	cout << "FIN" << endl;
}

void auxPostOrden (pNodoArbol nodo) {
	if (nodo != NULL) {
		auxPostOrden (nodo->iz);	 	// Izquierda
		auxPostOrden (nodo->de);		// Derecha
		cout << nodo->clave << " "; 	// Nodo
	}
}

void Arbol::postOrden () {
	auxPostOrden (raiz);
	cout << "FIN" << endl;
}

void Arbol::amplitud () {
	pNodoArbol p;
	queue <pNodoArbol> c;

	p = raiz;
	if (p != NULL)
		c.push (p);
	while (!c.empty ()) {
		p = c.front ();
		c.pop ();
		cout << p->clave << " ";
		if (p->iz != NULL)
			c.push (p->iz);
		if (p->de != NULL)
			c.push (p->de);
	}
	cout << "FIN" << endl;
}

void inserta (pNodoArbol &nodo, int valor) {

	if (nodo == NULL)
		nodo = new NodoArbol (valor);
	else if (valor != nodo->clave) {
		if (valor < nodo->clave)
			inserta (nodo->iz, valor);
		else inserta (nodo->de, valor);
	}
	else cout << "Error, la clave ya existe" << endl;
}

void Arbol::insertar (int x) {
	inserta (raiz, x);
}
void quitarSucesor (pNodoArbol nodoQuitar, pNodoArbol &sucesor) {
	pNodoArbol hijo;

	if (sucesor->de == NULL) {
		hijo = sucesor->iz;
		nodoQuitar->clave = sucesor->clave;
		delete sucesor;
		sucesor = hijo;
	}
	else quitarSucesor (nodoQuitar, sucesor->de);
}

void elimina (pNodoArbol &nodo, int valor) {
	pNodoArbol hijo;

	if (nodo != NULL) {
		if (valor == nodo->clave)
			if ((nodo->iz == NULL) || (nodo->de == NULL)) {
				if (nodo->iz == NULL)
					hijo = nodo->de;
				else hijo = nodo->iz;
				delete nodo;
				nodo = hijo;
			}
			else quitarSucesor (nodo, nodo->iz);
		else if (valor < nodo->clave)
			elimina (nodo->iz, valor);
		else elimina (nodo->de, valor);
	}
	else cout << "la clave buscada no existe" << endl;
}

void Arbol::eliminar (int x) {
	elimina (raiz, x);
}

void Arbol::rellenarArbol (string f) {
	// COMPLETAR
	ifstream lectura(f);
	string linea;
	int clave;
	if (!lectura) {
		cout << "El fichero no ha sido encontrado" << endl;
	}
	while (!lectura.eof()) {
		lectura>>clave;
		insertar(clave);
	}
}


int sumarClavesImpares(pNodoArbol nodo) {
	int resul;
	if (nodo != NULL)
	{
		resul=sumarClavesImpares(nodo->iz)+sumarClavesImpares(nodo->de);
		if(nodo->de!=NULL && nodo->iz!=NULL)
		{
			if(nodo->clave %2!=0)
				resul+=nodo->clave;
		}
	}
	else resul=0;
	return resul;   //resultado 128
}
int Arbol::sumaClavesImparesDosHijos () {
	int resul = 0;
	resul=sumarClavesImpares(raiz);
	}


void mostrarClaves (pNodoArbol actual) {
	if (actual != NULL) {
		mostrarClaves(actual->de);
	if((actual->iz == NULL || actual->de == NULL)&&(actual->iz!=NULL || actual->de!=NULL))
		cout << actual->clave << " " << endl;
			mostrarClaves(actual->iz);
		}
	}

void Arbol::mostrarClavesUnHijo () {
		mostrarClaves (raiz);
	}

