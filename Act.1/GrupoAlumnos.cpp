/*
 * GrupoAlumnos.cpp
 *
 *  Created on: 23/1/2015
 *      Author: carolinagallardo
 */

#include "GrupoAlumnos.h"
#include <fstream>
#include <iomanip>

using namespace std;

GrupoAlumnos::GrupoAlumnos() {
	nombre = "GrupoDesconocido";
	listaAlumnos = new Alumno[10];
	numAlums = 0;
	maximo = 10;
}

GrupoAlumnos::GrupoAlumnos(int max, string nom) {
	nombre = nom;
	listaAlumnos = new Alumno[max];
	numAlums = 0;
	maximo = MAX;

}

GrupoAlumnos::~GrupoAlumnos() {
}

string GrupoAlumnos::getNombre() {
	return nombre;
}

void GrupoAlumnos::setNombre(string nom) {
	nombre = nom;
}

int GrupoAlumnos::getNumAlums() {
	return numAlums;
}

int GrupoAlumnos::getMaximo() {
	return numAlums;
}

Alumno GrupoAlumnos::getAlumno(int i) {
	Alumno a;
	if (i < numAlums)
		a = listaAlumnos[i];
	return a;
}

bool GrupoAlumnos::insertarAlumno(Alumno a) {
	if (numAlums < maximo) {
		listaAlumnos[numAlums] = a;
		numAlums++;
		return true;
	} else {
		return false;
	}
}

void GrupoAlumnos::mostrarGrupo() {
	cout << "Grupo " + nombre + ": " << endl;
	for (int i = 0; i < numAlums; i++)
		cout << i + 1 << ": " + listaAlumnos[i].alumnoACadena() << endl;
}

void GrupoAlumnos::guardarEnFichero() {
	ofstream salida("migrupo.txt");
	for (int i = 0; i < numAlums; i++) {
		salida << i + 1 << "." << listaAlumnos[i].alumnoACadena() << endl;
	}
	salida.close();

}

