#ifndef INTERFAZAF_H
#define INTERFAZAF_H

#include "interfazCONJUNTO.h"

typedef struct{
	T_conjunto Q;
	T_conjunto E;
	T_conjunto d;
	T_conjunto q_0;
	T_conjunto F;
}T_AF;

T_AF carga_AFD();
T_AF carga_AFND();
void acepta_cadena(T_AF); 
void inicializa_AF(T_AF *);
void muestra_AF(T_AF);

#endif
