

#ifndef NODOLISTA_H_
#define NODOLISTA_H_

#include <iostream>
using namespace std;

class NodoLista {
public:
	int clave;
	NodoLista *sig;

	NodoLista () {
		clave = 0;
		sig = NULL;
	}
	NodoLista (int elemento, NodoLista *n) {
		clave = elemento;
		sig = n;
	}
};

#endif /* NODOLISTA_H_ */

#ifndef LISTA_H_
#define LISTA_H_



typedef NodoLista *pNodo;
class Lista {
	//Variables miembro
private:
	pNodo inicio;
public:
	// Interfaz/Prototipo
	Lista ();
	~Lista ();

	bool estaVacia ();
	void insertarAlPrincipio (int x);
	void escribirLista ();
	void insertar (int x);
	bool ejercicioConsulta ();
	void ejercicioInsercion ();
	int ejercicioEliminacion (int dato);
};

#endif /* LISTA_H_ */
