//Actividad2.cpp
//Revisado 29/01/2018

#include <iostream>
#include <stack>
#include "Pila.h"
#include "Cola.h"
using namespace std;

// Funciones con Pila
void juegoEnsayoP(Pila &p) {
	p.apilar(13);
	p.apilar(10);
	p.apilar(7);
	p.apilar(5);
	p.apilar(3);
	p.apilar(-2);
}
int sumaPila(Pila &p) {
	int resul = 0;
	if (!p.pilaVacia()) {
		int elem = p.desapilar();
		resul = elem + sumaPila(p);
		p.apilar(elem);
	}
	return resul;
}
int elementosPares(Pila &p) {
	int resul = 0;
	if (!p.pilaVacia()) {
		int elem = p.desapilar();

		if (elem % 2 == 0)
			resul = elem + elementosPares(p);
		else
			resul = elementosPares(p);
		p.apilar(elem);
	}
	return resul;
}
int sumaParesPosicionImpar(Pila &p, int pos) {
	int resul = 0;
	pos++;
	if (!p.pilaVacia()) {
		int elem = p.desapilar();
		if (pos % 2 != 0 && elem % 2 == 0)
			resul = elem + sumaParesPosicionImpar(p, pos);
		//sumar mi elem
		else
			resul = sumaParesPosicionImpar(p, pos);

		p.apilar(elem);
	}
	return resul;
}
bool eliminarDatoMasUltimo(Pila &p, int &x) {
	bool resul = false;
	//IDA
	if (!p.pilaVacia()) {
		int elem = p.desapilar();
		if (p.pilaVacia()) {
			x = x + elem;
		} else
			resul = eliminarDatoMasUltimo(p, x);
		//VUELTA
		if (elem == x)
			return resul = true;
		else
			p.apilar(elem);
	}
	return resul;
}

// Funciones con Cola
void juegoEnsayoC(Cola &c) {
	c.encolar(-2);
	c.encolar(3);
	c.encolar(5);
	c.encolar(7);
	c.encolar(10);
	c.encolar(13);
}
int sumaCola(Cola &c) {
	int resul = 0;
	int elem, n;
	n = c.numElemCola();
	for (int i = 0; i < n; i++) {
		elem = c.desencolar();
		resul = resul + elem;
		c.encolar(elem);
	}
	return resul;
}
int sumarHastaX(Cola &c, int x) {
	int resul = 0;
	if (!c.colaVacia()) {
		int elem, n = c.numElemCola(), encon = 0, i = 0;
		while (i < n) {
			elem = c.desencolar();
			if (x == elem)
				encon = 1;
			if (!encon)
				resul += elem;
			c.encolar(elem);
			i++;
		}
	}
	return resul;
}
bool eliminarDatoMasPrimero(Cola &c, int x) {
	bool resul = false;
	int suma = x + c.primero();
	int elem;
	int n = c.numElemCola();
	for (int i = 0; i < n; i++) {
		elem = c.desencolar();
		if (elem == suma) {
			resul = true;
		} else
			c.encolar(elem);
	}
	return resul;
}

//Funciones con Stack
void juegoEnsayoS(stack<int> &p) {
	p.push(13);
	p.push(10);
	p.push(7);
	p.push(5);
	p.push(3);
	p.push(-2);
}
void escribirStack(stack<int> &p) {
	int elem;
	if (!p.empty()) {
		elem = p.top();
		p.pop();
		cout << elem << endl;
		escribirStack(p);
		p.push(elem);
	}
}
bool eliminarDatoMasUltimoB(stack<int> &p, int &x) {
	bool resul = false;
	//IDA
	if (!p.empty()) {
		int elem = p.top();
		p.pop();
		if (p.empty()) {
			x = x + elem;
		} else
			resul = eliminarDatoMasUltimoB(p, x);
		//VUELTA
		if (elem == x)
			return resul = true;
		else
			p.push(elem);
	}
	return resul;
}

void pruebasPila() {
	Pila pila;
	juegoEnsayoP(pila);
	cout << "Contenido de la pila antes de la funcion:" << endl;
	pila.imprimirPila();
	cout << "Apartado 2.1. La suma de los elementos es: " << sumaPila(pila)
			<< " \n";
	cout << "Contenido de la pila despues del apartado 2.1.:" << endl;
	pila.imprimirPila();
	cout << "Apartado 2.2. El numero de elementos pares es: "
			<< elementosPares(pila) << " \n";
	cout << "Contenido de la pila despues del apartado 2.2.:" << endl;
	pila.imprimirPila();
	int pos = 0;
	cout
			<< "Apartado 2.3 La suma de los elementos pares en posiciones impares desde la cima es: "
			<< sumaParesPosicionImpar(pila, pos) << " \n";
	cout << "Contenido de la pila despues del apartado 2.3.:" << endl;
	pila.imprimirPila();
	int x = 5;
	cout << "Apartado 2.4. Eliminar el dato " << x << " mas el ultimo es: ";
	cout << eliminarDatoMasUltimo(pila, x) << " \n";
	cout << "Contenido de la pila despues del apartado 2.4:" << endl;
	pila.imprimirPila();
}
void pruebasCola() {
	Cola cola;
	juegoEnsayoC(cola);
	cout << "Contenido de la cola antes de la funcion:" << endl;
	cola.imprimirCola();
	cout << "Apartado 3.1. La suma de los elementos de la cola es: "
			<< sumaCola(cola) << "\n";
	cout << "Contenido de la cola:" << endl;
	cola.imprimirCola();
	int x = 5;
	cout << "Apartado 3.2 La suma de los elementos de la cola hasta " << x
			<< " es: " << sumarHastaX(cola, x) << "\n";
	cout << "Contenido de la cola:" << endl;
	cola.imprimirCola();
	cout << "Apartado 3.3. Eliminar el dato " << x << " mas el primero es: ";
	cout << eliminarDatoMasPrimero(cola, x) << "\n";
	cout << "Contenido de la cola:" << endl;
	cola.imprimirCola();
}

void pruebaStack() {
	stack<int> p;
	juegoEnsayoS(p);
	cout << "Contenido del stack antes de la funcion:" << endl;
	escribirStack(p);
	int x = 5;
	cout << "Apartado 5.1. Eliminar el dato " << x << " mas el ultimo es: ";
	cout << eliminarDatoMasUltimoB(p, x) << " \n";
	cout << "Contenido del stack despues de la ejecucion de la funcion:"
			<< endl;
	escribirStack(p);
}

int menu() {
	int resul = 0;
	cout << "Ejercicios de la actividad 2" << endl;
	cout << "\t 1. Apartado 2 (pilas)" << endl;
	cout << "\t 2. Apartado 3 (colas)" << endl;
	cout << "\t 3. Apartado 5 (utilizacion de la clase stack)" << endl;
	cout << "\t 0. Salir" << endl;
	cout << endl << "Introduzca el ejercicio que desee ejecutar: " << endl;
	cin >> resul;
	return resul;
}

void ejecutarOpcion(int opcion) {
	switch (opcion) {
	case 1:
		pruebasPila();
		break;
	case 2:
		pruebasCola();
		break;
	case 3:
		pruebaStack();
		break;
	}
	return;
}

int main() {

	bool salir = false;
	int opcion;
	do {
		opcion = menu();
		if (opcion == 0) {
			cout << "Adios" << endl;
			salir = true;
		} else if (opcion <= 4) {
			ejecutarOpcion(opcion);
			cout << "Pulse una tecla para continuar" << endl;
			cin.ignore(10, '\n');
			cin.get();
		} else
			cout << "Opcion no valida, vuelva a intentarlo" << endl;
	} while (!salir);
	return 0;
}

