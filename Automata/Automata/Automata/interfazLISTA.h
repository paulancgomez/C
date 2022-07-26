#ifndef INTERFAZLISTA_H
#define INTERFAZLISTA_H

#include "interfazBASE.h"
#include "interfazPAR.h"

struct tipo_char{
	int nodo;
	struct tipo_char *dato;
	struct tipo_char *sig;
}


T_conjunto crea_nodo(T_ele);


T_conjunto unionn (T_conjunto, T_conjunto); 
T_conjunto interseccion(T_conjunto, T_conjunto);
T_conjunto diferencia(T_conjunto, T_conjunto);
T_conjunto vacio(); /*retorna null si el conjunto esta vacio*/
T_conjunto copiar(T_conjunto);
void mostrar_conjunto(T_conjunto);
void agrega_repetidos(T_conjunto*, T_conjunto);


int pertenece(T_conjunto, T_ele);  /*si una cadena pertenece a conjunto*/
T_ele retorna_elemento(T_conjunto);  /*retorna una cadena del conjunto*/
void agregar_elemento(T_conjunto*, T_ele); /*agrega una cadena en el conjunto*/
int contiene(T_conjunto, T_conjunto);

#endif
