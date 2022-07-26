#ifndef INTERFAZARBOL_H
#define INTERFAZARBOL_H

#include <stdlib.h>
#include "interfazELEMENTO.h"

#define STRING 1032
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
Tarbol convertir(Tarbol);
void acepta_cadena(Tarbol);
void muestra_arbol(Tarbol);
void muestra_arbol_especial(Tarbol);


#endif
