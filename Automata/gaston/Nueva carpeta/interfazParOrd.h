#ifndef INTERFAZPARORD_H
#define INTERFAZPARORD_H

#include "interfazbase.h"
typedef struct {
	T_ele a;
	T_ele b;
}Tpar;

Tpar crearUnPar(T_ele,T_ele);
int parIguales(Tpar,Tpar);//MODIFICAR EN CASO DE SER NECESARIO PARA ORDENAR(SOLO DEVUELVE 0 o 1)
void mostrarPar(Tpar);
#endif
