#ifndef INTERFAZCONJUNTO_H
#define INTERFAZCONJUNTO_H

#include "interfazELEMENTO.h"
#include "interfazPAR.h"

typedef struct Nodo{
	T_ele dato;
	struct Nodo * sig;
}Tnodo;

typedef Tnodo* Conjunto; 

typedef struct Nodo2{
	T_par dato;
	struct Nodo2* sig;
}Tnodo2;

typedef Tnodo2* Conj_PC;

/*void cargar_lista();  CONSULTAR SI ESTA BIEN HACER ESTA FUNCION*/
void carga_alfabeto(Conjunto *);
void Crea_estados(Conjunto *, Conjunto *);
void carga_EstAceptacion(Conjunto *, Conjunto);
void inicializa(Conjunto *, Conjunto *, Conjunto *, Conjunto *, Conjunto *);
void agrega_repetidos(Conjunto *,Conjunto);
T_ele retornaElemento(Conjunto);
Conjunto conjuntovacio();//RETORNA NULL
void agregar_elemento(Conjunto*, T_ele);
int pertenece(Conjunto, T_ele);//UN UN T_ele EN UN CONJUNTO 1 LOENCONTRO 0 NO
Conjunto diferencia(Conjunto ,Conjunto);
void mostrar_conjunto(Conjunto);
int contiene(Conjunto,Conjunto);
Conjunto conjuntovacio();
Conjunto union_conjunto(Conjunto,Conjunto);
Conjunto copiar(Conjunto);

Conjunto interseccion(Conjunto,Conjunto);


//PAR ORDENADO
Conj_PC productoCartesiano(Conjunto,Conjunto);//SIN PARES REPETIDOS
int buscaPC(Conj_PC,T_par);//NO USADO
void mostrarPC(Conj_PC);

#endif
