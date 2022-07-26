#ifndef INTERFAZARBOL_H
#define INTERFAZARBOL_H

#include <stdlib.h>
#include "interfazELEMENTO.h"
#include "interfazCONJUNTO.h"

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

typedef struct nodo2{
	int tipo;
	T_ele dato_cadena;
}Tnodo_cadena;

typedef Tnodo_cadena *Tstring;

Tarbol crea_nodo_arbol();
Tstring crea_nodo_string();
void muestra_nodo_string(Tstring);
void muestra_nodo_arbol(Tarbol);
Tstring crea_nodo_string_parametro(T_ele cadena);
Tarbol carga_arbol_estado(Tarbol, Tarbol, Conjunto);
Tarbol carga_arbol_alfabeto(Tarbol, Conjunto);
Tarbol carga_arbol_estado_inicial(Tarbol, Conjunto);
Tarbol carga_arbol_estado_final(Tarbol, Conjunto);
Tarbol carga_arbol_transicion(Tarbol, Conjunto);
Tarbol carga_arbol_completo();

#endif

