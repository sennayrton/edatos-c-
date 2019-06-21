
#include "Lista.h"

void juegoEnsayo1(Lista &lista) {
	//lista.insertarAlPrincipio(3);
	lista.insertarAlPrincipio(8);
	lista.insertarAlPrincipio(4);
	lista.insertarAlPrincipio(2);
	lista.insertarAlPrincipio(1);
}

void juegoEnsayo2(Lista &lista) {
	lista.insertarAlPrincipio(6);
	lista.insertarAlPrincipio(4);
	lista.insertarAlPrincipio(15);
	lista.insertarAlPrincipio(8);
	lista.insertarAlPrincipio(3);
}

void juegoEnsayo3(Lista &lista) {
	lista.insertarAlPrincipio(10);
	lista.insertarAlPrincipio(9);
	lista.insertarAlPrincipio(6);
	lista.insertarAlPrincipio(5);
	lista.insertarAlPrincipio(4);
	lista.insertarAlPrincipio(3);
}

int main() {
	Lista l1, l2, l3;
	juegoEnsayo1(l1);
	l1.escribirLista();
	bool resul = l1.ejercicioConsulta();
	if (resul)
		cout << "Resultado ejercicio 1: true" << endl;
	else
		cout << "Resultado ejercicio 1: false" << endl;
	l1.escribirLista();
	juegoEnsayo2(l2);
	l2.escribirLista();
	cout << "Resultado ejercicio 2: " << endl;
	l2.ejercicioInsercion();
	l2.escribirLista();
	juegoEnsayo3(l3);
	l3.escribirLista();
	int dato = -3;
	cout << "Resultado ejercicio 3 con dato=" << dato << ": "
			<< l3.ejercicioEliminacion(dato) << endl;
	l3.escribirLista();
	return 0;
}

