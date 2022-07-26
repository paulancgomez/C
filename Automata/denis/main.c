#include <stdio.h>
#include "AUTOMATA.h"
#include <string.h>
#include <stdlib.h>

const int TAM=80;

int main() {
	printf("EN ESTE PROGRAMA LAS PARTES DEL AUTOMATA SON UNICAMENTE DEL TIPO CHAR \n");
	printf("ADEMAS EL PRIMER ESTADO INGRESADO ES EL ESTADO INICIAL \n");
	printf("Y LA LETRA 'V' ES EL ESTADO VACIO \n\n");
	tcadena cadena;
	tcadena estados;
	int tam;
	char s='S';	
	t_ptr lista=NULL;
	tcadena est_aux;
	t_ptr lista_trans;
	t_ptr aceptacion;
	t_ptr sigma;
	int ce=0;
	int cs=0;
	
	lista=crearAF(&ce,&cs,estados);
	printf("%c",estados[0]);
	lista_trans=lista;
	mostrar(lista);
	printf("\n\n");
	
	while(lista_trans->der!=NULL)
		lista_trans=lista_trans->der;
	lista_trans=lista_trans->izq;
	while(s=='S'){
		aceptacion=lista;
		sigma=lista->izq;
		printf("ingrese cadena: ");
		leecad(cadena,80);
		fflush(stdin);
		if(cadena_pertenece(cadena,sigma)){
			est_aux[0]=estados[0];
			tam=0;
			verificacion_de_cadenas(cadena,est_aux,lista_trans,&tam);
			aceptacion=aceptacion->der;
			aceptacion=aceptacion->der;
			aceptacion=aceptacion->der;
			aceptacion=aceptacion->izq;
			aceptacion_de_cadenas_1(est_aux,aceptacion,tam);
		}
		else{
			printf("La cadena no pertenece al alfabeto.\n");
		}
		fflush(stdin);
		printf("quiere seguir ingresando otro estado?? S/N: ");
		fflush(stdin);
		scanf("%c",&s);
		fflush(stdin);
		while(s!='S' && s!='N'){
			printf("quiere seguir ingresando otro estado?? S/N: ");
			fflush(stdin);
			scanf("%c",&s);
			fflush(stdin);
		}
	}
	
	return 0;
}
