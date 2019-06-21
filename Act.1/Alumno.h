/*
 * Alumno.h
 *
 *  Created on: 23/1/2015
 *      Author: carolinagallardo
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_

#include <iostream>
using namespace std;

#define MAX 5

class Alumno {

public:
	Alumno ();
	Alumno (string nom, string ape, string mat, float cal);
	virtual ~Alumno ();

	string getApellidos ();
	void setApellidos (string apel);

	string getNombre ();
	void setNombre (string nom);

	string getMatricula ();
	void setMatricula (string mat);

	float getCalificacion ();
	void setCalificacion (float cal);

	int getNumAsignaturas ();

	void anadirAsignatura (string asig);
	string alumnoACadena ();
	void mostrarAsignaturas ();


private:
	string nombre;
	string apellidos;
	string matricula;
	float calificacion;
	string  asignaturas[MAX];
	int numAsigs;
};

#endif /* ALUMNO_H_ */
