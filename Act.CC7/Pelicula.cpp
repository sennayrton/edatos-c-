/*
 * Pelicula.cpp
 */

#include "Pelicula.h"
#include <string>
#include <stdlib.h>

Pelicula::~Pelicula() {
	// TODO Auto-generated destructor stub
}

Pelicula::Pelicula() {
	// Completar
	titulo = "";
	genero = "";
	director = "";
	fecha = 1900;
	interpretes = NULL;
	numInters = 0;
}

Pelicula::Pelicula(string t, string d, string gen, int f) {
	// Completar
	titulo = t;
	genero = gen;
	director = d;
	fecha = f;
	interpretes = NULL;
	numInters = 0;
}

Pelicula::Pelicula(string linea) {
	numInters = 0;
	interpretes = NULL;
	string delimiter = ";";
	size_t pos = 0;
	string token;
	string datos[4];
	int i = 0;
	while ((pos = linea.find(delimiter)) != string::npos && i < 4) {
		token = linea.substr(0, pos);
		datos[i] = token;
		i++;
		linea.erase(0, pos + delimiter.length());
	}
	int n = atoi(datos[3].c_str());
	titulo = datos[0];
	director = datos[1];
	genero = datos[2];
	fecha = n;
	// y ahora los interpretes
	if (linea != "")
		while ((pos = linea.find(delimiter)) != string::npos) {
			token = linea.substr(0, pos);
			insertarInterprete(token);
			linea.erase(0, pos + delimiter.length());
		}
}

string Pelicula::getDirector() {
	return this->director;
}

void Pelicula::setDirector(string d) {
	this->director = d;
}

string Pelicula::getGenero() {
	return genero;
}

void Pelicula::setGenero(string genero) {
	this->genero = genero;
}

string Pelicula::getTitulo() {
	return titulo;
}

void Pelicula::setTitulo(string titulo) {
	this->titulo = titulo;
}

void Pelicula::setFecha(int aaaa) {
	this->fecha = aaaa;
}

string Pelicula::aCadena() {
	stringstream convertirFecha, convertirInters;
	convertirFecha << fecha;
	string f = convertirFecha.str();
	convertirInters << numInters;
	string i = convertirInters.str();

	string aux = titulo + ". " + director + ". (" + genero + "). " + f
			+ ". \n \t" + " Interpretes (" + i + "): "
			+ this->getListaInterpretes();
	return aux;
}

string Pelicula::formatoFichero() {
	stringstream convertir;
	string fec;
	convertir << this->fecha;
	fec = convertir.str();
	string aux;
	aux = this->getTitulo() + ";" + this->getDirector() + ";"
			+ this->getGenero() + ";" + fec + ";";
	aux += getListaInterpretes();
	return aux;
}

bool Pelicula::tieneDatos() {
	bool resul = false;
	if (titulo != "" && director != "")
		resul = true;
	return resul;
}

string Pelicula::getListaInterpretes() {
	//completar
	string aux = "";
	pInter actual = interpretes;
	while (actual != NULL) {
		aux += actual->interprete + ";";
		actual = actual->sig;
	}
	return aux;
}

bool Pelicula::insertarInterprete(string actor) {
	//completar
	pInter actual = interpretes;
	pInter anterior = NULL;
	while (actual != NULL && actual->interprete != actor) {
		anterior = actual;
		actual = actual->sig;
	}
	if (actual == NULL) {
		pInter nuevo = new NodoInterprete(actor);
		if (interpretes == NULL) {
			interpretes = nuevo;
		} else {
			anterior->sig = nuevo;
		}
		numInters++;
		return true;
	} else {
		return false;
	}
}

bool Pelicula::eliminarInterprete(string actor) {
	//completar
	pInter actual = interpretes;
	pInter anterior = NULL;
	while (actual != NULL && actual->interprete != actor) {
		anterior = actual;
		actual = actual->sig;
	}
	if (actual != NULL) {
		if (interpretes != actual) {
			anterior->sig = actual->sig;
		} else {
			interpretes = actual->sig;
		}
		numInters--;
		delete actual;
		return true;
	} else {
		return false;
	}
}

