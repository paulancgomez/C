#include "interfazARBOL.h"

Tstring crea_nodo_string(){  /*crea nodo cadena*/
	Tstring nodo;
	nodo=(Tstring)malloc(sizeof(Tnodo_cadena));
	nodo->tipo=STRING;
	nodo->dato_cadena=carga_uno();
	return nodo;
}

Tstring crea_nodo_string_parametro(T_ele cadena){  /*crea nodo cadena mandando como parametro*/
	Tstring nodo;
	nodo=(Tstring)malloc(sizeof(Tnodo_cadena));
	nodo->tipo=STRING;
	nodo->dato_cadena=cadena;
	return nodo;
}

Tarbol crea_nodo_arbol(){  /*creo nodo arbol*/
	Tarbol nodo;
	nodo=(Tarbol)malloc(sizeof(Tnodo_arbol));
	nodo->tipo=SET;
	nodo->dato_arbol=NULL;
	nodo->sig=NULL;
	return nodo;
}

Tarbol carga_arbol_completo(){
	Tarbol raiz, aux;
	Conjunto Q, E, q0, F, T;
	raiz=crea_nodo_arbol();
	aux=raiz;
	inicializa(&Q, &E, &q0, &F, &T);
	carga_alfabeto(&E);
	Crea_estados(&Q,&q0);
	carga_EstAceptacion(&F,Q);
	/*trancisionesAFND(&T);*/
	raiz=carga_arbol_estado(raiz, aux, Q);
	aux=raiz->sig;
	aux=carga_arbol_alfabeto(aux, E);
	aux=aux->sig;
	aux=carga_arbol_estado_inicial(aux, q0);
	aux=aux->sig;
	aux=carga_arbol_estado_final(aux, q0);
	/*aux=aux->sig;
	raiz=carga_arbol_transicion(aux, T); */
	return raiz;
}

/*
Tarbol carga_arbol_estado(Tarbol raiz, Tarbol aux, Conjunto Q){
	Tarbol nuevo, nuevo2;
	T_ele cadena;
	nuevo=crea_nodo_arbol();
	nuevo2=crea_nodo_arbol();
	if(raiz->sig==NULL){
		int i;
		i=1;
		raiz->dato_arbol=nuevo;
		raiz->sig=nuevo2;
		return carga_arbol_estado(raiz, aux->dato_arbol, Q);
	}
	else{
		if(Q->sig!=NULL){ 
			cadena=retornaElemento(Q);
			nuevo->dato_arbol = (Tarbol) crea_nodo_string_parametro(cadena);
			nuevo->sig=nuevo;
			return carga_arbol_estado(raiz, aux->dato_arbol, Q->sig);
		}
		else{
			cadena=retornaElemento(Q); 
			nuevo->dato_arbol = (Tarbol) crea_nodo_string_parametro(cadena);
		}
	}
	return raiz;
}
*/

Tarbol carga(Tarbol raiz, int cant, Conjunto Q){
	Tarbol nuevo;
	T_ele cadena;
	nuevo=raiz->dato_arbol;
	cadena=retornaElemento(Q);
	carga_estado(&nuevo, cadena);
	if(cant-1!=0){
		cadena=retornaElemento(Q->sig);
		carga_estado(&nuevo, cadena);
		cant--;
	}
}

void carga_estado(Tarbol *nuevo, T_ele cadena){
	*nuevo->dato_arbol=(Tarbol)cadena;
	*nuevo->sig=crea_nodo_arbol();
	*nuevo=nuevo->sig;
}

Tarbol carga_arbol_alfabeto(Tarbol raiz, Conjunto Q){
	Tarbol nuevo, nuevo2;
	T_ele cadena;
	nuevo=crea_nodo_arbol();
	nuevo2=crea_nodo_arbol();
	if(raiz==NULL){
		raiz->dato_arbol=nuevo;
		raiz->sig=nuevo2;
		carga_arbol_alfabeto(raiz, Q);
	}
	else{
		if(Q->sig!=NULL){  /*si no llegue todavia al ultimo nodo*/
			cadena=retornaElemento(Q);
			nuevo->dato_arbol = (Tarbol) crea_nodo_string_parametro(cadena);
			raiz->dato_arbol=nuevo;
			carga_arbol_alfabeto(raiz, Q->sig);
		}
		else{
			cadena=retornaElemento(Q);
			nuevo->dato_arbol = (Tarbol) crea_nodo_string_parametro(cadena);
		}
	}
	return raiz;
}

Tarbol carga_arbol_estado_inicial(Tarbol raiz, Conjunto Q){
	Tarbol nuevo, nuevo2;
	T_ele cadena;
	nuevo=crea_nodo_arbol();
	nuevo2=crea_nodo_arbol();
	if(raiz->sig==NULL){
		raiz->dato_arbol=nuevo;
		raiz->sig=nuevo2;
		carga_arbol_alfabeto(raiz, Q);
	}
	else{
		if(Q->sig!=NULL){  /*si no llegue todavia al ultimo nodo*/
			cadena=retornaElemento(Q);
			nuevo->dato_arbol = (Tarbol) crea_nodo_string_parametro(cadena);
			raiz->dato_arbol=nuevo;
			carga_arbol_alfabeto(raiz, Q->sig);
		}
		else{
			cadena=retornaElemento(Q);
			nuevo->dato_arbol = (Tarbol) crea_nodo_string_parametro(cadena);
		}
	}
	return raiz;
}

Tarbol carga_arbol_estado_final(Tarbol raiz, Conjunto Q){
	Tarbol nuevo, nuevo2;
	T_ele cadena;
	nuevo=crea_nodo_arbol();
	nuevo2=crea_nodo_arbol();
	if(raiz->sig==NULL){
		raiz->dato_arbol=nuevo;
		raiz->sig=nuevo2;
		carga_arbol_alfabeto(raiz, Q);
	}
	else{
		if(Q->sig!=NULL){  /*si no llegue todavia al ultimo nodo*/
			cadena=retornaElemento(Q);
			nuevo->dato_arbol = (Tarbol) crea_nodo_string_parametro(cadena);
			raiz->dato_arbol=nuevo;
			carga_arbol_alfabeto(raiz, Q->sig);
		}
		else{
			cadena=retornaElemento(Q);
			nuevo->dato_arbol = (Tarbol) crea_nodo_string_parametro(cadena);
		}
	}
	return raiz;
}

Tarbol carga_arbol_transicion(Tarbol raiz, Conjunto Q){
	Tarbol nuevo, nuevo2;
	T_ele cadena;
	nuevo=crea_nodo_arbol();
	nuevo2=crea_nodo_arbol();
	if(raiz->sig==NULL){
		raiz->dato_arbol=nuevo;
		raiz->sig=nuevo2;
		carga_arbol_alfabeto(raiz, Q);
	}
	else{
		if(Q->sig!=NULL){  /*si no llegue todavia al ultimo nodo*/
			cadena=retornaElemento(Q);
			nuevo->dato_arbol = (Tarbol) crea_nodo_string_parametro(cadena);
			raiz->dato_arbol=nuevo;
			carga_arbol_alfabeto(raiz, Q->sig);
		}
		else{
			cadena=retornaElemento(Q);
			nuevo->dato_arbol = (Tarbol) crea_nodo_string_parametro(cadena);
		}
	}
	return raiz;
}

void muestra_arbol(Tarbol raiz){
	if(raiz==NULL){
		muestra_nodo_arbol(raiz);
		muestra_arbol(raiz->dato_arbol);
		muestra_arbol(raiz->sig);
		
	}
}

void muestra_nodo_arbol(Tarbol uno){
	if(uno!=NULL){
		mostrar_conjunto(uno->dato_arbol);
	}
}
/*
void inicia_arbol(Tarbol *raiz){
	*raiz->dato_arbol=NULL;
	*raiz->sig=NULL;
}

void agrega_der(Tarbol *raiz, Tarbol nuevo){
	*raiz->dato_arbol=nuevo;
}

void agrega_izq(Tarbol *raiz, Tarbol nuevo){
	*raiz->sig=nuevo;
}


void muestra_nodo_string(Tstring nodo){
	
	if(nodo!=NULL){
		mostrar_uno(nodo->dato_cadena);
	}
}
*/
