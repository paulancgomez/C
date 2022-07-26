#ifndef AUTOMATA_H
#define AUTOMATA_H

#define INT 1024
#define CHAR 2015
#define STRING 1032
#define LIST 1033
#define SET 1034

typedef char tcadena[112];

typedef struct nodo{
	int nodetype;
	struct nodo* izq;
	struct nodo* der;
}tnodo;

typedef struct tipochar{
	int nodetype;
	char valor;
}Ttipochar;

typedef Ttipochar* t_ptr_char;
typedef tnodo* t_ptr;
typedef char testados[80];
typedef char testados_trans[80];


void mostrar(t_ptr);
t_ptr crearAF(int*,int*, tcadena);
int leecad(tcadena, int);
t_ptr crear_e_f_t(t_ptr);
void verificacion_de_cadenas(tcadena, tcadena, t_ptr,int*);
void aceptacion_de_cadenas_1(tcadena,t_ptr,int);
int cadena_pertenece(tcadena,t_ptr);
t_ptr crear_e_d_aceptacion(t_ptr);

#endif
