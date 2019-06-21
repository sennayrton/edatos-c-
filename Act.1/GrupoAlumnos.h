/*
 * GrupoAlumnos.h
 *
 *  Created on: 23/1/2015
 *      Author: carolinagallardo
 */

#include "Alumno.h"

#ifndef GRUPOALUMNOS_H_
#define GRUPOALUMNOS_H_

using namespace std;

class GrupoAlumnos {

public:

	GrupoAlumnos ();
	GrupoAlumnos (int maximo, string nombre);
	virtual ~GrupoAlumnos ();

	string getNombre ();
	void setNombre (string nom);
	int getNumAlums ();
	int getMaximo ();
	Alumno getAlumno (int i);
	bool insertarAlumno (Alumno a);
	void guardarEnFichero ();
	void mostrarGrupo ();

private:
	int numAlums;
	int maximo;
	string nombre;
	Alumno *listaAlumnos;
};

#endif /* GRUPOALUMNOS_H_ */
