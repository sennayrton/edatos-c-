/*
 * Alumno.cpp
 *
 *  Created on: 23/1/2015
 *      Author: carolinagallardo
 */

#include "Alumno.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Alumno::Alumno() {
	nombre = "";
	apellidos = "";
	matricula = "aa0000";
	calificacion = 0;
	numAsigs = 0;
}

Alumno::Alumno(string nom, string ape, string mat, float cal) {
	nombre = nom;
	apellidos = ape;
	matricula = mat;
	calificacion = cal;
	numAsigs = 0;
}

Alumno::~Alumno() {
}

string Alumno::getApellidos() {
	return apellidos;
}
void Alumno::setApellidos(string apel) {
	apellidos = apel;
}

string Alumno::getMatricula() {
	return matricula;
}
void Alumno::setMatricula(string mat) {
	matricula = mat;
}

string Alumno::getNombre() {
	return nombre;
}
void Alumno::setNombre(string nom) {
	nombre = nom;
}

float Alumno::getCalificacion() {
	return calificacion;
}
void Alumno::setCalificacion(float cal) {
	calificacion = cal;
}

int Alumno::getNumAsignaturas() {
	return numAsigs;
}

void Alumno::anadirAsignatura(string asig) {
	if (numAsigs < MAX) {
		asignaturas[numAsigs] = asig;
		numAsigs++;
	} else {
		cout << "Se ha rebasado el maximo de asignaturas " << endl;
	}
}

void Alumno::mostrarAsignaturas() {
	cout << nombre << " " << apellidos << " esta matriculado en: \n";
	for (int i = 0; i < numAsigs; i++)
		cout << " -" << asignaturas[i] << endl;
}

string Alumno::alumnoACadena() {
	stringstream convertir;
	string cali;
	convertir << calificacion;
	cali = convertir.str();
	return apellidos + ", " + nombre + ". Matr: " + matricula + " (" + cali
			+ ").";
}
