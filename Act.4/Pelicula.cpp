/*
 * Pelicula.cpp
 */

#include "Pelicula.h"
#include <string>
#include <stdlib.h>

Pelicula::~Pelicula () {
	// TODO Auto-generated destructor stub
}

Pelicula::Pelicula () {
		titulo = "";
		director = "";
		genero = "";
		fecha = 1900;
		numInters = 0;
		interpretes = 0;
}

Pelicula::Pelicula (string t, string d, string gen, int f) {

		titulo = t;
		director = d;
		genero = gen;
		fecha = f;
		numInters = 0;
		interpretes = 0;
}

Pelicula::Pelicula (string linea) {
		numInters = 0;
		interpretes = NULL;
		string delimiter = ";";
		size_t pos = 0;
		string token;
		string datos [4];
		int i = 0;
		while ((pos = linea.find (delimiter)) != string::npos && i < 4) {
			token = linea.substr (0, pos);
			datos [i] = token;
			i++;
			linea.erase (0, pos + delimiter.length ());
		}
		int n = atoi (datos [3].c_str ());
		titulo = datos [0];
		director = datos [1];
		genero = datos [2];
		fecha = n;
		// y ahora los interpretes
		if (linea != "")
		while ((pos = linea.find (delimiter)) != string::npos) {
			token = linea.substr (0, pos);
			insertarInterprete (token);
			linea.erase (0, pos + delimiter.length ());
		}
	}

string Pelicula::getDirector () {
		return this->director;
	}

void Pelicula::setDirector (string d) {
		this->director = d;
	}

string Pelicula::getGenero () {
		return genero;
	}

void Pelicula::setGenero (string genero) {
		this->genero = genero;
	}

string Pelicula::getTitulo () {
		return titulo;
	}

void Pelicula::setTitulo (string titulo) {
		this->titulo = titulo;
	}

void Pelicula::setFecha (int aaaa) {
		this->fecha = aaaa;
	}

string Pelicula::aCadena () {
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

string Pelicula::formatoFichero () {
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

bool Pelicula::tieneDatos () {
		bool resul = false;
		if (titulo != "" && director != "")
			resul = true;
		return resul;
	}

string Pelicula::getListaInterpretes () {
		string aux = "";
		pInter actual = interpretes;
		while(actual != NULL) {
			aux += actual->interprete + ";";
			actual = actual->sig;
		}
		return aux;
	}


bool Pelicula::insertarInterprete (string actor) {
	bool resul = false, existe = false;
	if (interpretes == NULL){
			interpretes = new NodoInterprete(actor);
			resul = true;
			numInters++;
		}
		else {
			pInter actual = interpretes->sig, anterior = interpretes;
			while (actual != NULL && existe == false){
				if (actual->interprete == actor) existe = true;
				anterior = actual;
				actual = actual->sig;
			}
			if (existe != true){
				anterior -> sig = new NodoInterprete(actor);
				resul = true;
				numInters++;
			}
		}
		return resul;
	}

bool Pelicula::eliminarInterprete (string actor) {
	bool resul = false, accion = false;
		pInter actual=interpretes->sig, anterior=interpretes;
		if (anterior -> interprete == actor){
			delete actual;
			accion = true;
		}
		while(actual != NULL && accion != true){
			if(actual->interprete == actor){
				anterior->sig = actual->sig;
				delete actual;
				accion = true;
			}
			else {
				anterior = actual;
				actual = actual->sig;
			}
		}
		if(accion == true){
			numInters--;
			resul = true;
		}
		return resul;
	}

