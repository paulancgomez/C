#ifndef INTERFAZCONJUNTO_H
#define INTERFAZCONJUNTO_H

#include "interfazPAR.h"
#inclide <stdlib.h>

#define INT 1024
#define CHAR 1025
#define STRING 1032
#define LIST 1033
#define SET 1034
typedef struct nodo{
	int SET;
	struct nodo *dato;
	struct nodo *sig;
} Tnodo;

typedef Tnodo *Tarbol;

typedef struct {
	int CHAR;
	char valor;
}Tchar;

Tconjunto crea_nodo();

T_conjunto unionn (T_conjunto, T_conjunto); 
T_conjunto interseccion(T_conjunto, T_conjunto);
T_conjunto diferencia(T_conjunto, T_conjunto);
T_conjunto vacio();   /*retorna null si el conjunto esta vacio*/
T_conjunto copiar(T_conjunto);
void mostrar_conjunto(T_conjunto);
void agrega_repetidos(T_conjunto*, T_conjunto);


int pertenece(T_conjunto, T_ele);  /*si una cadena pertenece a conjunto*/
T_ele retorna_elemento(T_conjunto);  /*retorna una cadena del conjunto*/
void agregar_elemento(T_conjunto*, T_ele); /*agrega una cadena en el conjunto*/
int contiene(T_conjunto, T_conjunto);

#endif
