/*
 * Filmoteca.h
 *
 * Created by Carolina Gallardo.
 * Copyright (c) 2016. All rights reserved.
 */

#include <string>
#include <iostream>
#include "Pelicula.h"
#include <map>

#ifndef FILMOTECA_H_
#define FILMOTECA_H_

class Filmoteca {

private:
	string propietario;
	map<string, Pelicula> peliculas;

public:
	Filmoteca (string prop);

	string getPropietario ();
	void setPropietario (string prop);

	bool estaVacia ();
	bool insertarPelicula (Pelicula l);
	bool eliminarPelicula (string titulo);
	Pelicula buscarPelicula (string titulo);
	void mostrarFilmoteca ();
};

#endif /* FILMOTECA_H_ */

