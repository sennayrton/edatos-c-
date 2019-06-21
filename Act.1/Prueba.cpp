
#include "Alumno.h"
#include <iostream>
#include <string>
#include <sstream>
#include "GrupoAlumnos.h"
#include <fstream>
#include <iomanip>
using namespace std;

float mediaGrupo(GrupoAlumnos grupo) {
	Alumno a;
	float media = 0, cal, suma = 0;
	int total = grupo.getNumAlums();
	for (int i = 0; i < total; i++) {
		cal = grupo.getAlumno(i).getCalificacion();
		suma = suma + cal;
		media = suma / total;
	}
	return media;

}

int main() {

	GrupoAlumnos g1(4, "GX102");

	Alumno a1("Arias Gonzalez", "Felipe", "aa1253", 3.50);

	Alumno a2("Garcia Sacedón", "Manuel", "ax0074", 8.35);

	Alumno a3("Lopez Medina", "Margarita", "mj7726", 7.70);

	Alumno a4("Ramirez Heredia", "Jorge", "lp1523", 4.50);

	Alumno a5("Yuste Pelaez", "Jorge", "lp1523", 4.50);

	a1.anadirAsignatura("EEDD");

	a1.anadirAsignatura("MD");

	cout << a1.alumnoACadena() << endl;

	a1.mostrarAsignaturas();

	g1.insertarAlumno(a1);

	g1.insertarAlumno(a2);

	g1.insertarAlumno(a3);

	g1.insertarAlumno(a4);

	g1.insertarAlumno(a5);

	g1.mostrarGrupo();

	cout << "Nota media: " << mediaGrupo(g1) << endl;

	g1.guardarEnFichero();

}
