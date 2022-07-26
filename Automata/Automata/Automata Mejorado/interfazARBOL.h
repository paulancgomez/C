#ifndef INTERFAZARBOL_H
#define INTERFAZARBOL_H

#include <stdlib.h>
#include "interfazELEMENTO.h"
#include "interfazCONJUNTO.h"
#include "interfazAFND.h"

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

Tarbol crea_nodo_arbol();
Tstring crea_nodo_string();
Tstring crea_nodo_string_parametro(T_ele cadena);
Tarbol carga_arbol();
void muestra_arbol(Tarbol);
void muestra_conjunto(Tarbol);
void muestra_nodo_string(Tstring);
void crea_hijos(Tarbol*);
void crea_hijos_ultimo(Tarbol*);
void carga_conjunto(Tarbol, int, Conjunto);
void carga_conjunto_trans(Tarbol, int, Conjunto);
void muestra_trans(Tarbol);
void muestra_conjunto_trans(Tarbol);
Tarbol retorna_estado_acep(Tarbol);
Tarbol retorna_estado_inicial(Tarbol);
Tarbol retorna_transi(Tarbol, int);
void acepta_cadena(Tarbol);
void crea_hijos_parametro(Tarbol*, T_ele);
void agrega_elemento_arbol(Tarbol *, T_ele);
Tarbol interseccion_arbol(Tarbol a, Tarbol b);
void agrega_repetidos_arbol(Tarbol *, Tarbol);
Tarbol arbol_vacio();
#endif
