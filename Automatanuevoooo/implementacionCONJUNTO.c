#include "interfazCONJUNTO.h"
//FUNCIONES AUXILIARES

Conjunto crea_nodo(T_ele);
Conj_PC crea_nodoPC(T_par );
void union_conjuntoRec(Conjunto, Conjunto*);
void copiarRec(Conjunto, Conjunto*);
void mostrar_conjuntoRec(Conjunto);
void interseccionRec(Conjunto,Conjunto, Conjunto*);
void encuentraUltimo(Conjunto*,T_ele);
void mostrarPCRec(Conj_PC);
void encUltimoPC(Conj_PC *);
void recorrerBPC(Conjunto,Conjunto,Conj_PC *);
void recorrerAPC(Conjunto,Conjunto,Conj_PC *);
void diferenciaRec(Conjunto ,Conjunto ,Conjunto *);
//ULTIMO DE LA LISTA SIN TENER EN CUENTA LA COMPARACION PARA SABER SI ESTA REPETIDO
void ultimoElementoSinComparacion(Conjunto * );
/*void cargar_lista(){//CONSULTAR SI ESTA BIEN HACER ESTA FUNCION

}*/
Conjunto crea_nodo(T_ele e){
	Conjunto nuevo;
	nuevo=(Conjunto)malloc(sizeof(Tnodo));
	nuevo->dato=e;
	nuevo->sig=NULL;
	return nuevo;
}
T_ele retornaElemento(Conjunto l){
	return l->dato;
}
Conjunto conjuntovacio(){//RETORNA NULL
	return NULL;
}

void agregar_elemento(Conjunto* a, T_ele e){
	Conjunto aux=conjuntovacio();
	Conjunto nodo=crea_nodo(e);
	if(*a==NULL){
		*a=nodo;
	}
	else{
		aux=*a;
		encuentraUltimo(&aux,e);
		if(compara_ele(aux->dato,e)!=0)  /*no salio por esta condicion asi que la lista llego a sy fin*/
			aux->sig=nodo;
	}
}
void encuentraUltimo(Conjunto* aux, T_ele e){
	if((*aux)->sig!=NULL && compara_ele((*aux)->dato,e)!=0){
		*aux=(*aux)->sig;
		encuentraUltimo(aux,e);
	}
}

int pertenece(Conjunto a, T_ele e){//BUSCA UN T_ele EN UN CONJUNTO 1 LO ENCONTRO 0 NO
	if(a!=NULL){
		if(a!=NULL && compara_ele(a->dato,e)!=0){
			a=a->sig;
			return pertenece(a,e);
		}
		if(a==NULL)
		   return 0;
		else 
			return 1;  /*lo encontro*/
	}
	else 
	   return 0;
}

void diferenciaRec(Conjunto a,Conjunto b,Conjunto *nuevo){
	if(a!=NULL){
		if(pertenece(b,a->dato)==0)
			agregar_elemento(nuevo,a->dato);
		diferenciaRec(a->sig,b,nuevo);
	}
}
Conjunto diferencia(Conjunto a,Conjunto b){
	Conjunto nuevo=conjuntovacio();
	diferenciaRec(a,b,&nuevo);
	return nuevo;
}
void mostrar_conjunto(Conjunto a){
	printf("\n{");
	mostrar_conjuntoRec(a);
	printf("}\n");
}

void mostrar_conjuntoRec(Conjunto a){
	if(a!=NULL){
		if(a->sig!=NULL){
			mostrar_uno(a->dato);printf(" , ");
			a=a->sig;
			mostrar_conjuntoRec(a);
		}else{
			mostrar_uno(a->dato);}
	}
}

Conjunto union_conjunto(Conjunto a,Conjunto b){
	Conjunto nuevo=copiar(a);
	union_conjuntoRec(b,&nuevo);
	return nuevo;
}
void union_conjuntoRec(Conjunto b, Conjunto* nuevo){
	if(b!=NULL){
		if(pertenece(*nuevo,b->dato)==0)
			agregar_elemento(nuevo,b->dato);
		b=b->sig;
		union_conjuntoRec(b,nuevo);
	}
}
Conjunto copiar(Conjunto a){
	Conjunto nuevo=conjuntovacio();
	copiarRec(a,&nuevo);
	return nuevo;
}
void copiarRec(Conjunto a, Conjunto* nuevo){
	
	if(a!=NULL){
		agregar_elemento(nuevo,a->dato);
		a=a->sig;
		copiarRec(a,nuevo);
	}	
}

Conjunto interseccion(Conjunto a, Conjunto b){
	Conjunto nuevo=conjuntovacio();
	interseccionRec(a,b,&nuevo);
	return nuevo;
}
void interseccionRec(Conjunto a,Conjunto b, Conjunto* nuevo){
	
	if(a!=NULL){
		if(pertenece(b,a->dato)==1)
			agregar_elemento(nuevo,a->dato);
		a=a->sig;
		interseccionRec(a,b,nuevo);
	}
}
int contiene(Conjunto a,Conjunto b){
	if(a!=NULL){
		if(b!=NULL){
			int ban=0;
			while(a!=NULL && ban==0){
				if(pertenece(b,a->dato)==0)
					ban=1;
				a=a->sig;
			}
			if(ban==1)
				  return 0;
			else
				return 1;
		}
		else
		   return 0;
	}
	else
	   return 1;
	
}

//PAR ORDENADO
Conj_PC crea_nodoPC(T_par p){
	Conj_PC nuevo;
	nuevo=(Conj_PC)malloc(sizeof(Tnodo2));
	nuevo->dato=p;
	nuevo->sig=NULL;
	
	return nuevo;
}

Conj_PC productoCartesiano(Conjunto a,Conjunto b){
	
	Conj_PC p=NULL;
	
	recorrerAPC(a,b,&p);
	return p;
}

//AÑADIDO
void recorrerAPC(Conjunto a,Conjunto b,Conj_PC *p){
	if(a!=NULL){
		recorrerBPC(a,b,p);
		recorrerAPC(a->sig,b,p);
	}
}
//AÑADIDO
void recorrerBPC(Conjunto a,Conjunto b,Conj_PC *p){
	if(b!=NULL){
		Conj_PC auxp=NULL;
		if(*p==NULL)
			*p=crea_nodoPC(carga_par(a->dato,b->dato));
		else{
			
			auxp=*p;
			encUltimoPC(&auxp);
			
			auxp->sig=crea_nodoPC(carga_par(a->dato,b->dato));
		}
		recorrerBPC(a,b->sig,p);
	}
}
//AÑADIDO
void encUltimoPC(Conj_PC *a){
	if((*a)->sig!=NULL)
	{
		*a=(*a)->sig;
		encUltimoPC(a);
	}
}

int buscaPC(Conj_PC a, T_par e){//BUSCA UN Tpar EN UN CONJUNTO 1 LO ENCONTRO 0 NO
	if(a!=NULL){
		if(a!=NULL && par_iguales(a->dato,e)!=0){
			return buscaPC(a->sig,e);
		}
		if(a==NULL)
		   return 0;
		else 
			return 1;
	}
	else 
	   return 0;
}
void mostrarPC(Conj_PC a){
	printf("\n{");
	mostrarPCRec(a);
	printf("}\n");
};
void mostrarPCRec(Conj_PC a){
	if(a!=NULL){
		if(a->sig!=NULL){
			muestra_par(a->dato);printf(" , ");
			a=a->sig;
			mostrarPCRec(a);
		}
		else{
			muestra_par(a->dato);
		}
	}
}


//NUEVO
void agrega_repetidos(Conjunto *a,Conjunto b){
	Conjunto aux=conjuntovacio();
	while(b!=NULL){
		if(*a==NULL){
			*a=crea_nodo(retornaElemento(b));
		}
		else{
			aux=*a;
			ultimoElementoSinComparacion(&aux);
			aux->sig=crea_nodo(retornaElemento(b));
		}
		b=b->sig;
	}
}

//NUEVO
//ULTIMO DE LA LISTA SIN TENER EN CUENTA LA COMPARACION PARA SABER SI ESTA REPETIDO
void ultimoElementoSinComparacion(Conjunto *aux){
	if((*aux)->sig!=NULL ){
		*aux=(*aux)->sig;
		ultimoElementoSinComparacion(aux);
	}
}

/*void inicializa_AF(T_AF*); */
void carga_alfabeto(Conjunto*);
int Cant_estados(Conjunto);
void Crea_estados(Conjunto *, Conjunto*);
void carga_EstAceptacion(Conjunto*, Conjunto);
Conjunto despuesComa(Tcadena);
T_ele antesComa(Tcadena);
T_ele entreComa(Tcadena);
/*void trancisionesAFND(T_AF *);*/
void muestra_d(Conjunto);

int repe_transiciones(Conjunto,T_ele);

void inicializa(Conjunto *Q, Conjunto *E, Conjunto *d, Conjunto *q_0, Conjunto *F){
	*Q=conjuntovacio();
	*E=conjuntovacio();
	*d=conjuntovacio();
	*q_0=conjuntovacio();
	*F=conjuntovacio();
}
/*
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
*/
void carga_alfabeto(Conjunto* E){
	int tam,i,B;
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
/*
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
*/


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
/*
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
			if(auxc[0]!='\0')*/
		/*		{*/
		/*			aux=carga_ele(auxc);*/
		/*			agregar_elemento(&nuevo,aux);*/
		/*		}*/
	/*	auxc=strtok(NULL,",{}");
	}
	return nuevo;
}

*/
//NUEVOS
/*
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
