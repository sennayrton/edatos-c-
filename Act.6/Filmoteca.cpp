/*
 * Filmoteca.cpp
 *
 */

#include "Filmoteca.h"

Filmoteca::Filmoteca (string prop) {
	propietario = prop;
	raiz = NULL;
}
void Filmoteca::destruir (pNodo &nodo) {
	if (nodo != NULL) {
		destruir (nodo->iz);
		destruir (nodo->de);
		delete nodo;
		nodo = NULL;
	}
}
Filmoteca::~Filmoteca () {
	destruir (raiz);
}

bool Filmoteca::estaVacia () {
	return raiz == NULL;
}

string Filmoteca::getPropietario () {
	return propietario;
}

void Filmoteca::setPropietario (string p) {
	propietario = p;
}

bool insertar (pNodo &nodo, Pelicula peli) {
	bool resul = false;
	if (nodo == NULL)
	{
		if(peli.tieneDatos())
		{
			nodo=new NodoF(peli);
			resul=true;
		}
	}
	else if (peli.getTitulo() != nodo->info.getTitulo())
	{
		if(peli.getTitulo() < nodo->info.getTitulo())
			resul=insertar(nodo->iz, peli);
		else
			resul=insertar(nodo->de, peli);
	}
	return resul;
}
bool Filmoteca::insertarPelicula (Pelicula peli) {
	bool resul = false;
	resul=insertar(raiz, peli);
	return resul;
}

void Filmoteca::quitarSucesor (pNodo nodoQuitar, pNodo &sucesor) {
	pNodo hijo;

	if (sucesor->de == NULL) {
		hijo = sucesor->iz;
		nodoQuitar->info = sucesor->info;
		delete sucesor;
		sucesor = hijo;
	}
	else quitarSucesor (nodoQuitar, sucesor->de);
}

bool Filmoteca::elimina (pNodo &nodo, string t) {
	pNodo hijo;
	bool resul = false;

	if (nodo != NULL) {
		if (t == nodo->info.getTitulo()) {
			if ((nodo->iz == NULL) || (nodo->de == NULL)) {
				if (nodo->iz == NULL)
					hijo = nodo->de;
				else hijo = nodo->iz;
				delete nodo;
				nodo = hijo;
			}
			else quitarSucesor (nodo, nodo->iz);
			resul = true;
		}
		else if (t < nodo->info.getTitulo())
			resul = elimina (nodo->iz, t);
		else resul = elimina (nodo->de, t);
	}
	return resul;
}

bool Filmoteca::eliminarPelicula (string titulo) {
	return elimina (raiz, titulo);
}

Pelicula buscar(pNodo nodo, string t) {
	Pelicula resul;
	if (nodo != NULL)
	{
		if(nodo->info.getTitulo()== t)
			resul=nodo->info;
		else
		{
			if(nodo->info.getTitulo()> t)
				resul=buscar(nodo->iz, t);
			else
				resul=buscar(nodo->de, t);
		}
	}
	return resul;
}

Pelicula Filmoteca::buscarPelicula (string t) {
   Pelicula p;
   p=buscar(raiz, t);
   return p;
}

void muestraenorden(pNodo nodo, int &pos)
{
	if(nodo != NULL)
	{
		muestraenorden(nodo->iz, pos);
		cout<< pos << "."<< nodo->info.aCadena()<<endl;
		pos++;
		muestraenorden(nodo->de, pos);
	}
}
void Filmoteca::mostrarFilmoteca () {
	int pos = 1;
	muestraenorden(raiz,pos);
}


