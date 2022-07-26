#include "interfazARBOL.h"

//TRABAJO PRACTICO TRANSVERSAL

//Integrantes:
//           CARDOZO GOMEZ PAULA NICOLE
//           CHIRI JAIRO MAURICIO

//FUNCION: Carga AF
//		   Muestra AF.

int menu();

int main(){
	Tarbol arbol, arbol_conv;
	int opc, b, opc2;
	
	b=0;
	arbol=arbol_conv=arbol_vacio();
	
	do{
		opc=menu();
		
		printf("\n");
		system("pause");
		system("cls");
		
		switch(opc){
		case 1:
			arbol=carga_arbol();
			muestra_arbol(arbol);
			b=1;
			
			printf("\n\n");
			system("pause");
			system("cls");
			break;
		case 2:
			printf("\n                       USTED ELIGIO OPCION 2: CONVERTIR AFND EN AFD. MOSTRAR AMBOS AF.");
			if(!b)
				arbol=carga_arbol();	
			printf("\n**SE MOSTRARA AMBOS AF**\n");
			printf("\n          AFND INGRESADO\n");
			muestra_arbol(arbol);
			arbol_conv=convertir(arbol);
			printf("\n          AFND INGRESADO CONVERTIDO EN AFD");
			muestra_arbol_especial(arbol_conv);
			printf("\n\n");
			system("pause");
			system("cls");
			break;
		case 3:
			if(!b){
				printf("\n                      USTED ELIGIO OPCION 3: INGRESO Y VERIFICACION DE CADENAS EN AF INGRESADO");
				arbol=carga_arbol();
			}
			do{
				printf("\n                     USTED ELIGIO OPCION 3: INGRESO Y VERIFICACION DE CADENAS EN AF INGRESADO\n");
				muestra_arbol(arbol);
				acepta_cadena(arbol);
				printf("\n\nIngresar otra cadena? (0)NO - (1)SI:  ");
				scanf("%d",&opc2);
				if(opc2!=0){
					printf("\n");
					system("pause");
					system("cls");
				}
			}while(opc2!=0);
			
			printf("\n\n");
			system("pause");
			system("cls");
			break;
		case 0:
			printf("\nFIN DEL PROGRAMA!");
			break;
		}
	}while(opc);
	
	return 0;
}

int menu(){
	int b;
	printf("\n          MENU");
	printf("\n\n(1) CARGAR UN AF INGRESANDO UNA UNICA CADENA DE CARACTERES CON LA FORMA:\n    ({q0,q1,..,qn},{a1,a2,..,am},{(qi,ak,qj),...},q0,{qf,...}) ");
	printf("\n\n(2) CONVERTIR AFND EN AFD. MOSTRAR AMBOS AF");
	printf("\n\n(3) INGRESAR Y VERIFICAR CADENAS EN AF INGRESADO.");
	printf("\n\n(0) SALIR.\n");
	do{
		printf("\nElija una opcion: ");
		scanf("%d", &b);
	}while(b!=0 && b!=1 && b!=2 && b!=3);
	return b;
}
