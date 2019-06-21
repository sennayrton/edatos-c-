#include <iostream>
#include "GrafoMA.h"
#include "GrafoLA.h"

using namespace std;

GrafoMA juegoEnsayo1 () {
	GrafoMA grafo (5, true);
	grafo.insertaVertices (5);

	grafo.insertaArista (0, 1);
	grafo.insertaArista (1, 2);
	grafo.insertaArista (2, 3);
	grafo.insertaArista (3, 4);
	grafo.insertaArista (4, 0);
	return grafo;
}

GrafoMA juegoEnsayo2 () {
	GrafoMA grafo (14, true);
	grafo.insertaVertices (12);

	grafo.insertaArista (0, 1);
	grafo.insertaArista (0, 2);
	grafo.insertaArista (4, 7);
	grafo.insertaArista (0, 3);
	grafo.insertaArista (1, 3);
	grafo.insertaArista (3, 6);
	grafo.insertaArista (9, 1);
	grafo.insertaArista (9, 10);
	grafo.insertaArista (5, 10);
	grafo.insertaArista (8, 9);
	grafo.insertaArista (8, 12);
	return grafo;
}
GrafoLA juegoEnsayo3 () {
	GrafoLA grafo (5, false);
	grafo.insertaVertices (5);

	grafo.insertaArista (0, 1);
	grafo.insertaArista (0, 4);
	grafo.insertaArista (1, 2);
	grafo.insertaArista (1, 3);
	grafo.insertaArista (3, 4);
	return grafo;
}

int main () {
	cout << "//////////////////////////////////////" << endl;
	cout << "PRUEBAS CON MATRIZ DE ADYACENCIAS" << endl;
	cout << "//////////////////////////////////////" << endl;
	GrafoMA grafo = juegoEnsayo2 ();

	grafo.imprimirTabla ();
	cout << "----------------------- " << endl;
	cout << "Tamaño de grafo: " << grafo.tamano () << endl;
	cout << "Grado de entrada de 1: " << grafo.gradoIn (1) << endl;
	cout << "Grado de salida de 1: " << grafo.gradoOut (1) << endl;
	cout << "----------------------- " << endl;
	cout << "Recorrido en amplitud: " << endl;
	grafo.recorrerAmplitud ();
	cout << "----------------------- " << endl;
	cout << "Recorrido en profundidad: " << endl;
	grafo.recorrerProfundidad ();
	cout << "----------------------- " << endl;

	cout << "//////////////////////////////////////" << endl;
	cout << "PRUEBAS CON LISTAS DE ADYACENCIAS" << endl;
	cout << "//////////////////////////////////////" << endl;
	GrafoLA grafol (14, false);
	grafol.insertaVertices (12);

	grafol.insertaArista (0, 1);
	grafol.insertaArista (0, 2);
	grafol.insertaArista (4, 7);
	grafol.insertaArista (0, 3);
	grafol.insertaArista (1, 3);
	grafol.insertaArista (3, 6);
	grafol.insertaArista (9, 1);
	grafol.insertaArista (9, 10);
	grafol.insertaArista (5, 10);
	grafol.insertaArista (8, 9);
	grafol.insertaArista (18, 9);

	grafol.imprimirListas ();
	cout << "----------------------- " << endl;
	cout << "Tamaño de grafo: " << grafol.tamano () << endl;
	cout << "----------------------- " << endl;
	grafol.recorrerAmplitud ();
	grafol.recorrerProfundidad ();

	cout << endl;

return 0;
}

