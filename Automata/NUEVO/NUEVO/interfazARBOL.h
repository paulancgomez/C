#ifndef INTERFAZARBOL_H
#define INTERFAZARBOL_H

#include <stdlib.h>
#include "interfazELEMENTO.h"

#define INI 0
#define ELE 1
#define ENTERO 2
#define STRING 3


typedef struct nodo{
	int tipo;
	struct nodo *dato_arbol;
	struct nodo *sig;
} Tnodo_arbol;

typedef struct{
	int dato;
	int tipo;
	Telemento dato_ele;
} Tnodo_elemento;

typedef Tnodo_arbol *Tarbol;
typedef Tnodo_elemento *T_ele;

Tarbol arbol_vacio();
Tarbol carga_arbol();
void muestra_arbol(Tarbol);


#endif
