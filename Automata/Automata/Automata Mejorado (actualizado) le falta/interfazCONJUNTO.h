#ifndef INTERFAZCONJUNTO_H
#define INTERFAZCONJUNTO_H
#include <stdlib.h>
#include "interfazPAR.h"

typedef struct nodoo{
	T_ele dato;
	struct nodoo * sig;
}Tnodo1;

typedef Tnodo1* Conjunto; 

typedef struct Nodo2{
	Tpar dato;
	struct Nodo2* sig;
}Tnodo2;

typedef Tnodo2* Conj_PC;

/*void cargar_lista();  CONSULTAR SI ESTA BIEN HACER ESTA FUNCION*/


void agrega_repetidos(Conjunto *,Conjunto);
T_ele retornaElemento(Conjunto);
void muestra_lista(Conjunto);
Conjunto conjuntovacio();//RETORNA NULL
void agregar_elemento(Conjunto*, T_ele);
int pertenece(Conjunto, T_ele);//UN UN T_ele EN UN CONJUNTO 1 LOENCONTRO 0 NO
Conjunto diferencia(Conjunto ,Conjunto);
void mostrar_conjunto(Conjunto);
int contiene(Conjunto,Conjunto);
void inicializa(Conjunto *, Conjunto * , Conjunto *, Conjunto *, Conjunto *);
Conjunto union_conjunto(Conjunto,Conjunto);
Conjunto copiar(Conjunto);
Conjunto interseccion(Conjunto,Conjunto);
void carga_alfabeto(Conjunto*);
int Cant_estados(Conjunto);
void Crea_estados(Conjunto *, Conjunto*);
void carga_EstAceptacion(Conjunto*, Conjunto);
void transicionesAFND(Conjunto, Conjunto, Conjunto*);
T_ele  antesComa(Tcadena n);
T_ele entreComa(Tcadena n);

//PAR ORDENADO
Conj_PC productoCartesiano(Conjunto,Conjunto);//SIN PARES REPETIDOS
int buscaPC(Conj_PC,Tpar);//NO USADO
void mostrarPC(Conj_PC);

#endif
