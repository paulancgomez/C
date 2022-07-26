/*#include "interfazAF.h"

/*
int interseccion_conjuntos(Taf af, Tvec vec){
	return interseccion_conjuntos_privado(vec, af.F);
}

int interseccion_conjuntos_privado(Tvec vec, Tvec F){  
	int i, band;
	band=0;
	for(i=1; i<=tam1; i++){
	    for(j=1; j<=tam2 && band==0; j++){
			if(vec[i]==F[j]){
				band=1;
		    }
	    }
	}
	return band;
}*/
/*
#include <string.h>
void inicializa_AF(T_AF*);
void carga_alfabeto(Conjunto*);
int Cant_estados(Conjunto);
void Crea_estados(Conjunto *, Conjunto*);
void carga_EstAceptacion(Conjunto*, Conjunto);
Conjunto despuesComa(Tcadena);
T_ele antesComa(Tcadena);
T_ele entreComa(Tcadena);
void trancisionesAFND(T_AF *);
void muestra_d(Conjunto);

int repe_transiciones(Conjunto,T_ele);

void inicializa_AF(T_AF* nuevo){
	nuevo->Q=conjuntovacio();
	nuevo->E=conjuntovacio();
	nuevo->d=conjuntovacio();
	nuevo->q_0=conjuntovacio();
	nuevo->F=conjuntovacio();
}

T_AF crea_AFND(){
	T_AF nuevo;
	Conjunto d;
	inicializa_AF(&nuevo);
	carga_alfabeto(&nuevo.E);
	Crea_estados(&nuevo.Q,&nuevo.q_0);
	carga_EstAceptacion(&nuevo.F,nuevo.Q);
	trancisionesAFND(&nuevo);
	return nuevo;
}

void carga_alfabeto(Conjunto* E){
	int tam,i,TC,B;
	T_ele sim;
	printf("\nIngrese cantidad de simbolos del alfabeto: ");
	scanf("%i",&tam);
	for(i=1; i<=tam; i++){
		printf("\nIngrese simbolo: ");
		sim=carga_uno();
		B=pertenece(*E,sim);
		while(B==1){
			printf("Simbolo No Valido...\nIngrese otro simbolo: ");
			sim=carga_uno();
			B=pertenece(*E,sim);
		}
		agregar_elemento(E,sim);
	}
}

void Crea_estados(Conjunto *nuevo, Conjunto* EstIni){
	
	
	T_ele x,vacio;
	int i,b,c,z;
	
	printf("ingrese la cantidad de estados ");
	scanf("%d",&c);
	printf("\nEl primer estado que ingrese se le asignara como Estado Inicial...\n");
	system("pause");
	printf("\n");
	for(i=1;i<=c;i++){
		
		vacio=carga_ele(" ");
		printf("\ningrese el nombre del estado\n ");
		x=carga_uno();
		
		b=pertenece(*nuevo, x);
		z=compara_ele(x,vacio);
		while(b==1 || z==0){
			
			printf("\nel estado no es valido vuelva a agregar\n");
			
			x=carga_uno();
			
			b=pertenece(*nuevo, x);
			z=compara_ele(x,vacio);
			
		}
		
		agregar_elemento(nuevo,x);
		if(i==1){
			agregar_elemento(EstIni,x);
		}
	}
	
}

void carga_EstAceptacion(Conjunto* Acep, Conjunto Est){
	int CA, CEst,opc,B1,B2;
	T_ele etiqueta;
	opc=CA=0;
	CEst=Cant_estados(Est);
	do{
		printf("\nIngrese estado de Aceptacion:\t");
		etiqueta=carga_uno();
		B1=pertenece(Est,etiqueta);
		B2=pertenece(*Acep,etiqueta);
		while(B1!=1 || B2==1){
			printf("Estado No Valido...\nIngrese otro: ");
			etiqueta=carga_uno();
			B1=pertenece(Est,etiqueta);
			B2=pertenece(*Acep,etiqueta);
		}
		agregar_elemento(Acep,etiqueta);
		printf("\nDesea ingresar otro estado?\t*No(0)\n*Si(cualquier numero): ");
		scanf("%i",&opc);
		CA++;
	} while(opc!=0 && CA<=CEst);
}

int Cant_estados(Conjunto c){
	int t=0;
	while(c!=NULL){
		t=t+1;
		c=c->sig;
	}
	return t;
}
void muestra_AF(T_AF x){
	printf("\nAlfabeto: \n");
	mostrar_conjunto(x.E);
	printf("\nEstado Inicial: \n");
	mostrar_conjunto(x.q_0);
	printf("\nEstados: \n");
	mostrar_conjunto(x.Q);
	printf("\nEstados de Aceptacion: \n");
	mostrar_conjunto(x.F);
	printf("\nTransiciones: \n");
	muestra_d(x.d);
}
void muestra_d(Conjunto d){
	printf("{");
	while(d!=NULL){
		printf("(");
		mostrar_uno(retornaElemento(d));
		printf(")");
		printf(" , ");
		d=d->sig;
	}
	printf("}");
}
void AceptaCadena(T_AF A){
	//ANTERIOR,NUEVO CONJUNTO Y  AUXILIAR DE ANTERIOR PARA RECORRERLO SIN PERDER EL PRIMERO
	Conjunto ant=conjuntovacio(),auxAnt=conjuntovacio(),nuevo=conjuntovacio();
	//ESTADOS SIRVE PARA OBTENER EL CONJUNTO DE LOS ESTADOS DE LLEGADA Y AUXTRANSICIONES PARA RECORRER LAS TRANSICIONES
	Conjunto estados=conjuntovacio(),auxTransiciones=conjuntovacio(),acep=conjuntovacio();//para conjuntos de estados de llegada
	//PARA LEER CADENA INGRESADA POR USUARIO Y cadCom PARA FACILITAR COMPARAR CADENAS
	Tcadena leido,cadCom,auxcadCom;
	//PARA AYUDAR A OBTENER LAS CADENAS DE TRANSICIONES
	T_ele elem,elemAnt;
	int i=0,b1,b2;
	char cara;//PARA CARACTERES EXTRAIDOS DE LA CADENA
	agregar_elemento(&ant,retornaElemento(A.q_0));
	auxAnt=ant;
	printf("ingrese cadena a leer,se respondera si es aceptada o no\n");
	leecad(leido,100);
	cara=leido[i];
	while(cara!='\0'){
		while(auxAnt!=NULL){//auxAnt CONJUNTO DE ESTADOS
			auxTransiciones=A.d;
			while(auxTransiciones!=NULL ){//auxTransiciones CONJUNTO DE TERNAS
				elem=retornaElemento(auxTransiciones);
				elemAnt=retornaElemento(auxAnt);
				retornaValor(elem,auxcadCom);
				strcpy(cadCom,auxcadCom);
				b1=strcmp(antesComa(cadCom).valor,elemAnt.valor);
				retornaValor(elem,auxcadCom);
				strcpy(cadCom,auxcadCom);
				b2=strcmp(entreComa(cadCom).valor,carga_caracter(cara).valor);
				retornaValor(elem,auxcadCom);
				strcpy(cadCom,auxcadCom);
				if(b1==0 && b2==0){
					//if(compara_ele(antesComa(cadCom),elemAnt)==0 && compara_ele(entreComa(cadCom),carga_caracter(cara))==0){
					strcpy(auxcadCom,elem.valor);
					acep=despuesComa(auxcadCom);
					agrega_repetidos(&nuevo,acep);
				}
				auxTransiciones=auxTransiciones->sig;
			}
			
			auxAnt=auxAnt->sig;
		}
		ant=nuevo;
		auxAnt=ant;
		nuevo=conjuntovacio();
		i++;
		cara=leido[i];
	}
	if(interseccion(ant,A.F)!=NULL)
		  printf("la cadena es aceptada");
	else
		printf("la cadena NO es aceptada");
}
void trancisionesAFND(T_AF *A){
	Conjunto acep=conjuntovacio();
	char res;
	T_ele elemTran;
	Tcadena tranLeida,auxTranLeida;
	do{
		printf("ingrese trancision formato: estado,elementoDeAlfabeto,estado\n");	
		leecad(tranLeida,100);
		strcpy(auxTranLeida,tranLeida);
		elemTran=antesComa(auxTranLeida);
		if(pertenece(A->Q,elemTran)==1 && repe_transiciones(A->d,elemTran)<=Cant_estados(A->E))//EN ESTE CASO USO Cant_estados PARA SABER LA CANTIDAD DE ELEMENTOS DE E
		{
			strcpy(auxTranLeida,tranLeida);
			elemTran=entreComa(auxTranLeida);
			if(pertenece(A->E,elemTran)==1){
				strcpy(auxTranLeida,tranLeida);
				acep=despuesComa(auxTranLeida);
				elemTran=carga_ele(tranLeida);
				if(contiene(acep,A->Q) && pertenece(A->d,elemTran)==0){
					
					agregar_elemento(&(A->d),elemTran);
					printf("desea ingresar otra trancion?SI(cualquier caracter),NO(0)\n");
					scanf("%c",&res);
					fflush(stdin);
				}
				else{
					printf("estados de llegada no validos\n");
					res=='1';
				}
				
			}
			else{
				printf("elemento de alfabeto no valido\n");
				res=='1';
			}
		}
		else{
			printf("estado de partida no valido\n");
			res=='1';}
	} while(res!='0');
	printf("a finalizado la carga de trancisiones\n");
}

T_ele  antesComa(Tcadena n){
	//Tcadena n;
	//strcpy(n,a);
	char * auxc="";
	auxc=strtok(n,",");
	return carga_ele(auxc);
}
T_ele entreComa(Tcadena n){
	//Tcadena n;
	//strcpy(n,a);
	char * auxc="";
	auxc=strtok(n,",");
	auxc=strtok(NULL,",");
	return carga_ele(auxc);
}
Conjunto despuesComa(Tcadena n){
	//Tcadena n;
	Conjunto nuevo=conjuntovacio();
	T_ele aux;
	//strcpy(n,a);
	char * auxc="";
	auxc=strtok(n,",");
	auxc=strtok(NULL,",");
	auxc=strtok(NULL,",{}");
	while(auxc!=NULL){
		aux=carga_ele(auxc);
		agregar_elemento(&nuevo,aux);
		/*		if(auxc[0]!='\0')*/
		/*		{*/
		/*			aux=carga_ele(auxc);*/
		/*			agregar_elemento(&nuevo,aux);*/
		/*		}*/
	/*	auxc=strtok(NULL,",{}");
	}
	return nuevo;
}


//NUEVOS
int repe_transiciones(Conjunto d,T_ele elem){//PARA CONTROLAR QUE LAS CANTIDADES DE TRANSICIONES DESDE UN ESTADO NO SEAN MAYOR QUE LAS DEL ALFABETO
	int c=0;//CONTADOR
	T_ele aux;
	Tcadena auxCad;
	while(d!=NULL){
		aux=retornaElemento(d);
		retornaValor(aux,auxCad);
		if(compara_ele(antesComa(auxCad),elem)==0)//VER SI SE BURLA EL ENCAPSULAMIENTO
			c++;
		d=d->sig;
	}
	return c;
}

*/

