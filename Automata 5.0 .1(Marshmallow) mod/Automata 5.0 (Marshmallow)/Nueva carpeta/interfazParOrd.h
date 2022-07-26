#ifndef INTERFAZPARORD_H
#define INTERFAZPARORD_H

#include "interfazbase.h"

typedef struct {
	T_ele a;     /*T_ele es una estrucutra con un solo campo y ese campo es una cadena*/
	T_ele b;
}Tpar;           /*Tpar es una par ordenado de dos cadenas (cadena1, cadena2)*/

Tpar crearUnPar(T_ele, T_ele);
int parIguales(Tpar, Tpar);   /*MODIFICAR EN CASO DE SER NECESARIO PARA ORDENAR*/
void mostrarPar(Tpar);         /*1 si son iguales ambos pares y 0 si son distintos*/

#endif
