
#include "Filmoteca.h"
#include "Pelicula.h"
#include <iostream>

using namespace std;

void rellenarFilmoteca(Filmoteca &f);
void probarInsertar(Filmoteca &fi, Pelicula &p);
void probarBuscarPelicula(Filmoteca &f);
void probarEliminar(Filmoteca &f);
void _probarEliminar(Filmoteca &fi, string t);

int main() {

	string separador = "----------------------\n";
	Filmoteca film("MiFilmoteca");

	cout << "***********************************************" << endl;
	cout << "    PRUEBAS DE FILMOTECA" << endl;
	cout << "***********************************************" << endl;

	cout << "Prueba F1. MOSTRAR una filmoteca VACÍA" << endl;
	film.mostrarFilmoteca();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get();

	cout << "Prueba F2. INSERTAR películas y mostrar filmoteca: " << endl;
	rellenarFilmoteca(film);
	film.mostrarFilmoteca();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get();

	cout << "Prueba F3. ELIMINAR peliculas y mostrar filmoteca: " << endl;
	probarEliminar(film);
	film.mostrarFilmoteca();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get();
	cout << "------ FIN --------" << endl;

	cout << "Prueba F4. BUSCAR película y mostrar filmoteca: " << endl;
	probarBuscarPelicula(film);
	cout << separador << endl;
	film.mostrarFilmoteca();
	cout << separador << endl;
	cout << "Pulse una tecla para continuar" << endl;
	cin.get();
	cout << "------ FIN --------" << endl;

	return 0;
}

////////////////////////////////////////////////////

void rellenarFilmoteca(Filmoteca &f) {
	string ani = "animacion";
	string drama = "drama";
	string comedia = "comedia";
	string amor = "com. romantica";
	string docu = "documentales";
	Pelicula p1("Kunfu", "Bruce Lee", comedia, 1989);
	Pelicula p2("Cenicienta", "Almodovar", ani, 2015);
	Pelicula p3("Pinocho", "Buñuel", drama, 1980);
	Pelicula p4("Yoga", "Emir", drama, 2010);
	Pelicula p5("Rambo", "Schwazzenegger", amor, 2001);
	Pelicula p6("Dormir es un deporte", "Indurain", docu, 1999);
	Pelicula p7("Azarosos", "Crowfunding", drama, 2006);
	Pelicula p8("Zoiberg el Robot", "C3PO", "sci fi", 2010);
	probarInsertar(f, p1);
	probarInsertar(f, p2);
	probarInsertar(f, p3);
	probarInsertar(f, p7);
	probarInsertar(f, p6);
	probarInsertar(f, p4);
	probarInsertar(f, p5);
	probarInsertar(f, p8);
	Pelicula fantasma("", "Almodovar", "drama", 1980);
	cout << "Pelicula vacia: ";
	probarInsertar(f, fantasma);
	cout << "Pelicula repetida: ";
	probarInsertar(f, p5);
}

void probarInsertar(Filmoteca &fi, Pelicula &p) {
	bool resul = fi.insertarPelicula(p);
	if (resul)
		cout << " - " + p.getTitulo() + " (" + p.getDirector() + "): INSERTADO"
				<< endl;
	else
		cout
				<< " - " + p.getTitulo() + " (" + p.getDirector()
						+ "): NO INSERTADO" << endl;
}


void probarEliminar(Filmoteca &f) {
	_probarEliminar(f, "Zoiberg el Robot");
	_probarEliminar(f, "Kunfu");
	_probarEliminar(f, "Pelicula que no está");
}

void _probarEliminar(Filmoteca &fi, string t) {
	if (fi.eliminarPelicula(t))
		cout << " - " + t + ": ELIMINADA" << endl;
	else
		cout << " - " + t + ": NO ELIMINADA" << endl;
}

void probarBuscarPelicula(Filmoteca &f) {
	Pelicula p2 = f.buscarPelicula("Yoga");
	cout << p2.aCadena() << endl;
	p2 = f.buscarPelicula("No existe");
	cout << "Película que no existe: " << p2.aCadena() << endl;
}
