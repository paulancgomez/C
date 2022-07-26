#ifndef INTERFAZPAR_H
#define INTERFAZPAR_H

#include "interfazELEMENTO.h"

typedef struct {
	T_ele a;   
	T_ele b;
}T_par;



T_par carga_par(T_ele, T_ele);
void muestra_par(T_par);  
int par_iguales(T_par, T_par);

#endif
