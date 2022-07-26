#include "interfazCONJUNTO.h"

Conjunto crea_nodo(T_ele);
Conj_PC crea_nodoPC(Tpar );
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
void ultimoElementoSinComparacion(Conjunto * );
Conjunto despuesComa(Tcadena n);
T_ele antesComa(Tcadena);
T_ele entreComa(Tcadena);
void muestra_d(Conjunto);
int repe_transiciones(Conjunto d,T_ele elem);

Conjunto crea_nodo(T_ele e){
	Conjunto nuevo;
	nuevo=(Conjunto)malloc(sizeof(Tnodo1));
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

void muestra_lista(Conjunto lis){
	if(lis!=NULL){
		while(lis!=NULL){
			printf("\n");
			muestra_ele(lis->dato);
			lis=lis->sig;
		}
	}
	else
	   printf("\nLISTA VACIA");
}

/*
void agregar_elemento(Conjunto* a, T_ele e){  //esta mal, no agrega el ultimo elemento
	Conjunto aux=conjuntovacio();
	Conjunto nodo=crea_nodo(e);
	if(*a==NULL){
		*a=nodo;
	}
	else{
		aux=*a;
		encuentraUltimo(&aux,e);
		if(compara_ele(aux->dato,e)!=0) 
			aux->sig=nodo;
	}
}
*/
void agregar_elemento(Conjunto *lis, T_ele e){  //este sirveee
	Conjunto aux;
	Conjunto nodo;
	aux=conjuntovacio();
	nodo=crea_nodo(e);
	if(*lis==NULL){
		*lis=nodo;
	}
	else{
		aux=*lis;
		while(aux->sig!=NULL)
			aux=aux->sig;
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




//
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

void carga_alfabeto(Conjunto* E){
	int tam,i,TC,B;
	T_ele sim;
	printf("\nIngrese cantidad de simbolos del alfabeto: ");
	scanf("%i",&tam);
	for(i=1; i<=tam; i++){
		printf("\nIngrese simbolo: ");
		sim=carga_ele();
		B=pertenece(*E,sim);
		while(B==1){
			printf("Simbolo No Valido...\nIngrese otro simbolo: ");
			sim=carga_ele();
			B=pertenece(*E,sim);
		}
		agregar_elemento(E,sim);
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

void Crea_estados(Conjunto *nuevo, Conjunto *EstIni){
	T_ele x,vacio;
	int i,b,c,z;
	printf("\n");
	do{
		printf("Ingrese la cantidad de estados: ");
	    scanf("%d",&c);
	}while(c<=0);
	printf("**El primer estado que ingrese se le asignara como ESTADO INICIAL**\n");
	for(i=1;i<=c;i++){
		vacio=carga_ele_parametro(" ");
		printf("Ingrese el nombre del estado: ");
		x=carga_ele();
		b=pertenece(*nuevo, x);
		z=compara_ele(x,vacio);
		while(b==1 || z==0){
			printf("ESTADO NO VALIDO. Vuelva a ingresar: ");
			x=carga_ele();
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
	printf("\n");
	do{
		printf("Ingrese estado de aceptacion: ");
		etiqueta=carga_ele();
		B1=pertenece(Est,etiqueta);
		B2=pertenece(*Acep,etiqueta);
		while(B1!=1 || B2==1){
			printf("ESTADO NO VALIDO. Ingrese otro: ");
			etiqueta=carga_ele();
			B1=pertenece(Est,etiqueta);
			B2=pertenece(*Acep,etiqueta);
		}
		agregar_elemento(Acep,etiqueta);
		printf("Desea ingresar otro estado? SI (1) - NO (0): ");
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

void transicionesAFND(Conjunto Q, Conjunto E, Conjunto *T){
	Conjunto acep=conjuntovacio();
	char res;
	T_ele elemTran;
	Tcadena tranLeida,auxTranLeida;
	printf("\nmuestra estados.");
	muestra_lista(Q);
	printf("\nmuestra alfabeto.");
	muestra_lista(E);
	printf("\n\n");
	do{
		printf("Ingrese transicion: ");	
		leeCad(tranLeida,100);
		strcpy(auxTranLeida,tranLeida);
		elemTran=antesComa(auxTranLeida);
		if(pertenece(Q,elemTran)==1 && repe_transiciones(*T,elemTran)<=Cant_estados(E))//EN ESTE CASO USO Cant_estados PARA SABER LA CANTIDAD DE ELEMENTOS DE E
		{
			strcpy(auxTranLeida,tranLeida);
			elemTran=entreComa(auxTranLeida);
			if(pertenece(E,elemTran)==1){
				strcpy(auxTranLeida,tranLeida);
				acep=despuesComa(auxTranLeida);
				elemTran=carga_ele_parametro(tranLeida);
				printf("\nmuestra acep");
				muestra_lista(acep);
				if(contiene(acep,Q) && pertenece(*T,elemTran)==0){
					agregar_elemento(T,elemTran);
					printf("Desea ingresar otra trancion? SI(1) - NO(0): ");
					scanf("%c",&res);
					fflush(stdin);
				}
				else{
					printf("ESTADOS DE LLEGADA NO VALIDOS.");
					res='1';
				}
				
			}
			else{
				printf("ELEMENTO DE ALFABETO NO VALIDO.");
				res='1';
			}
		}
		else{
			printf("\nESTADO DE PARTIDA NO VALIDO.");
			res='1';}
	} while(res!='0');
}

T_ele  antesComa(Tcadena n){
	//Tcadena n;
	//strcpy(n,a);
	char * auxc="";
	auxc=strtok(n,",");
	return carga_ele_parametro(auxc);
}
T_ele entreComa(Tcadena n){
	//Tcadena n;
	//strcpy(n,a);
	char * auxc="";
	auxc=strtok(n,",");
	auxc=strtok(NULL,",");
	return carga_ele_parametro(auxc);
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
		aux=carga_ele_parametro(auxc);
		agregar_elemento(&nuevo,aux);
		/*		if(auxc[0]!='\0')*/
		/*		{*/
		/*			aux=carga_ele(auxc);*/
		/*			agregar_elemento(&nuevo,aux);*/
		/*		}*/
		auxc=strtok(NULL,",{}");
	}
	return nuevo;
}



int repe_transiciones(Conjunto d,T_ele elem){//PARA CONTROLAR QUE LAS CANTIDADES DE TRANSICIONES DESDE UN ESTADO NO SEAN MAYOR QUE LAS DEL ALFABETO
	int c=0;//CONTADOR
	T_ele aux;
	Tcadena auxCad;
	while(d!=NULL){
		aux=retornaElemento(d);
		retorna_ele(aux,auxCad);
		if(compara_ele(antesComa(auxCad),elem)==0)//VER SI SE BURLA EL ENCAPSULAMIENTO
			c++;
		d=d->sig;
	}
	return c;
}
void inicializa(Conjunto *Q, Conjunto *E , Conjunto *q0, Conjunto *F, Conjunto *T){
	*Q=conjuntovacio();
	*E=conjuntovacio();
	*q0=conjuntovacio();
	*F=conjuntovacio();
	*T=conjuntovacio();
}

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

void ultimoElementoSinComparacion(Conjunto *aux){
	if((*aux)->sig!=NULL ){
		*aux=(*aux)->sig;
		ultimoElementoSinComparacion(aux);
	}
}
