#ifndef INTERFAZPAR_H
#define INTERFAZPAR_H

#include "interfazBASE.h"

typedef struct {
	T_ele a;     /*T_ele es una cadena*/
	T_ele b;
}T_par;           /*Tpar es una par ordenado de dos cadenas (cadena1, cadena2)*/



T_par carga_par(T_ele, T_ele);
void muestra_par(T_par);  
int par_iguales(T_par, T_par);   /*MODIFICAR EN CASO DE SER NECESARIO PARA ORDENAR*/ /*1 si son iguales ambos pares y 0 si son distintos*/



#endif
