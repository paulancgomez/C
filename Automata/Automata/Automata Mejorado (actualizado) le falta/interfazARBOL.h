#ifndef INTERFAZARBOL_H
#define INTERFAZARBOL_H

#include <stdlib.h>
#include "interfazELEMENTO.h"

#define INT 1024
#define CHAR 1025
#define STRING 1032
#define LIST 1033
#define SET 1034

typedef struct nodo{
	int tipo ; 
	struct nodo *dato_arbol;
	struct nodo *sig;
} Tnodo_arbol;

typedef Tnodo_arbol *Tarbol;

typedef struct {
    int tipo;
	T_ele dato_cadena;
}Tnodo_cadena;

typedef Tnodo_cadena *Tstring;

Tarbol arbol_vacio();
Tarbol carga_arbol();
void acepta_cadena(Tarbol);
void muestra_arbol(Tarbol);

#endif
