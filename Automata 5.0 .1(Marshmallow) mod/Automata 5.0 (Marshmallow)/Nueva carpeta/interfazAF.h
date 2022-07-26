#ifndef INTERFAZAF_H
#define INTERFAZ_H
#include "interfazlista.h"

typedef struct{
	Conjunto Q;
	Conjunto E;
	Conjunto d;
	Conjunto q_0;
	Conjunto F;
}T_AF;

T_AF crea_AFD();
T_AF crea_AFND();
void AceptaCadena(T_AF);
void muestra_AF(T_AF);

#endif
