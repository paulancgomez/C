#include<stdio.h>
#include<stdlib.h>

struct marca
{
	char nombre[60];
	struct marca *sig,*sig2;
};
typedef struct marca nodo;
nodo *pt;


int main()
{
	printf("\n\t\tESTO ES UNA PRUEBA\n\n\n");
	pt=(nodo*)malloc(sizeof(nodo)); // nodo raiz (arbol binario)
	printf("Nombre: ");
	scanf(" %[^\n]", pt->nombre);
	pt->sig=(nodo*)malloc(sizeof(nodo)); //nodo hijo izquierdo
	pt->sig2=(nodo*)malloc(sizeof(nodo));// nodo hijo derecho
	
	printf("\n\tSEGUNDO NIVEL\n\n");
	printf("Nombre(hijo izquierdo): ");
	scanf(" %[^\n]", pt->sig->nombre);
	printf("Nombre(hijo derecho): ");
	scanf(" %[^\n]", pt->sig2->nombre);
	printf("\n\n");
	system("pause");
	system("cls");
	
	//Impresion de datos
	printf("\n\n\t\t\tARBOL BINARIO\n\n\n");
	printf("\t\t\t%s\n\n\t%s\t\t\t\t%s\n\n\n",pt->nombre,pt->sig->nombre,pt->sig2->nombre);
	system("pause");
	
	return 0;
}
