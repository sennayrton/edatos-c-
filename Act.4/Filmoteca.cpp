/*
 * Filmoteca.cpp
 *
 */

#include "Filmoteca.h"
#include <fstream>
#include <string>

Filmoteca::Filmoteca (string prop) {
	Pelicula p;
	propietario = prop;
	cent = new NodoF(p);
	cab = new NodoF(p, cent);
}

Filmoteca::~Filmoteca () {
	pNodo aux;
		while (cab != cent) {
			aux = cab;
			cab = cab->sig;
			delete aux;
		}
}

bool Filmoteca::estaVacia () {
	if (cab->sig == cent) return true;
	else return false;
}

string Filmoteca::getPropietario () {
	return propietario;
}

void Filmoteca::setPropietario (string p) {
	propietario = p;
}

bool Filmoteca::insertarPelicula (Pelicula peli) {
	bool resul = false;
	pNodo actual = cab->sig, anterior = cab;
	string aux = peli.getTitulo();
	if (peli.tieneDatos()){
		while(actual != cent && actual->info.getTitulo().compare(aux) < 0){
			anterior = actual;
			actual = actual -> sig;
		}
		if (actual->info.getTitulo() != aux){
			anterior->sig = new NodoF(peli, actual);
			resul = true;
		}
	}
	return resul;
}

bool Filmoteca::eliminarPelicula (string titulo) {
	pNodo actual = cab->sig, anterior = cab;
	bool resul = false;
	cent->info.setTitulo(titulo);
	while(actual->info.getTitulo() != titulo){
		anterior = actual;
		actual = actual -> sig;
	}
	if (actual != cent){
		anterior->sig = actual->sig;
		delete actual;
		resul = true;
	}
	return resul;
}

Pelicula Filmoteca::buscarPelicula (string t) {
	Pelicula p;
	pNodo actual = cab->sig;
	cent->info.setTitulo(t);
	while (actual->info.getTitulo() != t)
		actual = actual -> sig;
	if(actual != cent) p = actual->info;
	return p;
}

void Filmoteca::mostrarFilmoteca() {
	Pelicula p;
	pNodo actual = cab->sig;
	pNodo anterior = cab;
	while (actual!=cent) {

		actual->info.aCadena();
		anterior = actual;
		actual = actual->sig;

	}
}

bool Filmoteca::guardarEnFichero (string f) {
	bool resul = false;
	ofstream fc((propietario + f + ".txt").c_str());
	NodoF *aux = cab->sig;
	Pelicula p;
	string taux;
	while (aux != cent){
		p = aux->info;
		taux = p.formatoFichero();
		aux = aux->sig;
		fc << taux << endl;
	}
	fc.close();
	resul = true;
	return resul;
}

void Filmoteca::recuperarDeFichero(string f) {
	ifstream fichero;
	fichero.open(f.c_str());
	Pelicula p;
	string aux;
	while (getline (fichero, aux)) {

		cout << aux << endl;
		p = Pelicula(aux);
		insertarPelicula(p);
		cout << p.aCadena() << endl;

	}
	fichero.close();
}

