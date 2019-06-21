/*
 * Filmoteca.cpp
 *
 */

#include "Filmoteca.h"

Filmoteca::Filmoteca (string prop) {
	propietario = prop;
}


string Filmoteca::getPropietario () {
	return propietario;
}

void Filmoteca::setPropietario (string p) {
	propietario = p;
}

bool Filmoteca::estaVacia () {
	return peliculas.empty();
}

bool Filmoteca::insertarPelicula(Pelicula peli) {
	bool tobe = false, insertada = false;
	map < string, Pelicula>::iterator it;
	it = peliculas.begin();
	while(it!= peliculas.end() && !tobe)
	{
	if(it->first == peli.getTitulo())
		tobe=true;
	it++;
	}
	if(!tobe && peli.tieneDatos())
	{
		peliculas[peli.getTitulo()] = peli;
		insertada=true;
		map<string, Pelicula>::iterator it;
		it = peliculas.begin();
		while(it!= peliculas.end()&&!tobe)
		{
			if(it->first == peli.getTitulo())
				tobe=true;
			else
				it++;
		}
	}
	return insertada;
}


bool Filmoteca::eliminarPelicula (string titulo) {
	bool tobe=false, eliminada=false;
	map<string, Pelicula>::iterator it;
	it= peliculas.begin();
	while(it!= peliculas.end() && !tobe)
	{
		if(it->first == titulo)
			tobe=true;
		else
			it++;
	}
	if(tobe)
	{
		peliculas.erase(titulo);
		eliminada=true;
	}
    return eliminada;
}


Pelicula Filmoteca::buscarPelicula (string t) {
	Pelicula resul;
	bool tobe=false;
	map<string, Pelicula>::iterator it;
	it = peliculas.begin();
	while(it!= peliculas.end() && !tobe)
	{
		if(it->first == t)
			tobe=true;
		else
			it++;
	}
	if(tobe)
		resul= it->second;
	return resul;
}


void Filmoteca::mostrarFilmoteca () {
	int cont=1;
	map<string, Pelicula>::iterator it;
	it = peliculas.begin();
	while(it != peliculas.end())
	{
		cout<<cont << ". "<<it->second.aCadena()<< endl;
		it++;
		cont++;
	}
}


