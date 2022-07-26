#ifndef INTERFAZELEMENTO_H
#define INTERFAZELEMENTO_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char ele;
}Telem;

typedef Telem *Telemento;

Telemento carga_ele();
Telemento carga_ele_parametro(char);
void muestra_ele(Telemento);
Telemento convertir_entero(Telemento);
Telemento convertir_cadena(Telemento);
int compara_ele(Telemento, Telemento);

#endif
