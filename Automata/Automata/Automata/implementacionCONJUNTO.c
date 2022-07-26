#include "interfazCONJUNTO.h"

/*FUNCIONES RECURSIVAS*/
void union_REC(T_conjunto, T_conjunto *);
void copiar_REC(T_conjunto, T_conjunto *);
void muestra_REC(T_conjunto);
void interseccion_REC(T_conjunto, T_conjunto, T_conjunto *);
void diferencia_REC(T_conjunto ,T_conjunto ,T_conjunto *);


Tarbol crea_arbol(){  /*estoy creando un nodo, no una raiz. Es una raiz cuando el puntero derecho e izquierdo es distinto de vacio*/
	Tarbol nodo;
	nodo=(Tarbol)malloc(sizeof(Tnodo));
	nodo->dato=NULL;
	nodo->sig=NULL;
	return nodo;
}

void inicia_arbol(Tarbol *raiz){
	*raiz->dato=NUL;
	*raiz->sig=NULL;
}

void agrega_der(Tarbol *raiz, Tarbol nuevo){
	*raiz->dato=nuevo;
}

void agrega_izq(Tarbol *raiz, Tarbol nuevo){
	*raiz->sig=nuevo;
}

void muestra_nodo(Tarbol nodo){  /*CORREGIRRRRRRRR*/
	if(nodo!=NULL){
		muestra_ele(nodo->dato);
	}
}
