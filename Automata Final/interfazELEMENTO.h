#ifndef INTERFAZELEMENTO_H
#define INTERFAZELEMENTO_H

#include "interfazCADENA.h"
#include <stdio.h>
#include <string.h>

typedef struct {
	Tcadena cadena;
}T_ele;

T_ele carga_ele();
T_ele carga_ele_parametro(Tcadena );
void muestra_ele(T_ele);
void retorna_ele(T_ele, Tcadena);  /*retorna cadena en una cadena auxiliar*/
int compara_ele(T_ele, T_ele);  /*devuelve -1, 0 o 1*/
T_ele carga_caracter_ele(char);
T_ele  antesComa(Tcadena n);
T_ele entreComa(Tcadena n);

#endif
