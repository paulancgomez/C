#include "interfazELEMENTO.h"

Telemento convertir_entero(Telemento);
Telemento convertir_cadena(Telemento);

Telemento carga_ele(){
	Telemento uno;
	char x;
	fflush(stdin);
	scanf("%c", &x);
	uno=(Telemento)malloc(sizeof(Telem));
	uno->ele=x;
	fflush(stdin);
	return uno;
}

Telemento carga_ele_parametro(char dos){
	Telemento uno;
	uno=(Telemento)malloc(sizeof(Telem));
	uno->ele=dos;
	return uno;
}

void muestra_ele(Telemento uno){
	fflush(stdin);
	printf("%c", uno->ele);
	fflush(stdin);
}

int compara_ele(Telemento a, Telemento b){
	int r;
	if('a'=='b')
		r=0;
	else
		r=1;
	return r;
}
