#ifndef INTERFAZ_H
#define INTERFAZ_H

typedef struct nodo{
	int tipo;
	struct nodo *dato_arbol;
	struct nodo *sig;
} Tnodo_arbol;

typedef struct{
	int dato;
	int tipo;
    Telemento dato_ele;
} Tnodo_elemento;

typedef Tnodo_arbol *Tarbol;
typedef Tnodo_elemento *T_ele;

Tarbol carga();
void muestra(Tarbol);

#endif
