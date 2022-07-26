#ifndef INTERFAZLISTA_H
#define INTERFAZLISTA_H
#include "interfazbase.h"
#include "interfazParOrd.h"

typedef struct Nodo{
	T_ele dato;
	struct Nodo * sig;
}Tnodo;
typedef Tnodo* Conjunto;

typedef struct Nodo2{
	Tpar dato;
	struct Nodo2* sig;
}Tnodo2;
typedef Tnodo2* Conj_PC;
/*void cargar_lista();//CONSULTAR SI ESTA BIEN HACER ESTA FUNCION*/


void agrega_repetidos(Conjunto *,Conjunto);
T_ele retornaElemento(Conjunto);
Conjunto conjuntovacio();//RETORNA NULL
void agregar_elemento(Conjunto*, T_ele);
int pertenece(Conjunto, T_ele);//UN UN T_ele EN UN CONJUNTO 1 LOENCONTRO 0 NO
Conjunto diferencia(Conjunto ,Conjunto);
void mostrar_conjunto(Conjunto);
int contiene(Conjunto,Conjunto);

Conjunto union_conjunto(Conjunto,Conjunto);
Conjunto copiar(Conjunto);

Conjunto interseccion(Conjunto,Conjunto);


//PAR ORDENADO
Conj_PC productoCartesiano(Conjunto,Conjunto);//SIN PARES REPETIDOS
int buscaPC(Conj_PC,Tpar);//NO USADO
void mostrarPC(Conj_PC);
#endif
