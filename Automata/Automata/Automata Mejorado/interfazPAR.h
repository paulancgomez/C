#ifndef INTERFAZPAR_H
#define INTERFAZPAR_H

#include "interfazELEMENTO.h"

typedef struct {
	T_ele a;     /*T_ele es una cadena*/
	T_ele b;
}Tpar;           /*Tpar es una par ordenado de dos cadenas (cadena1, cadena2)*/



Tpar carga_par(T_ele, T_ele);
void muestra_par(Tpar);  
int par_iguales(Tpar, Tpar);   /*MODIFICAR EN CASO DE SER NECESARIO PARA ORDENAR*/ /*1 si son iguales ambos pares y 0 si son distintos*/


#endif
