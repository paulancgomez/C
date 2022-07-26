#include "interfazARBOL.h"
#include <stdlib.h>


void muestra_arbol_rec(Tarbol raiz, int e);
void carga_conjunto_trans(Tarbol raiz, int t, Conjunto T);
void carga_N(Conjunto*, Conjunto);
int pertenece_arbol(Tarbol a, T_ele e);

int repe_transiciones(Conjunto,T_ele);
Tstring crea_nodo_string(){
	Tstring nodo;
	nodo=(Tstring)malloc(sizeof(Tnodo_cadena));
	nodo->tipo=STRING;
	nodo->dato_cadena=carga_ele();
	return nodo;
}

Tstring crea_nodo_string_parametro(T_ele cadena){
	Tstring nodo;
	nodo=(Tstring)malloc(sizeof(Tnodo_cadena));
	nodo->tipo=STRING;
	nodo->dato_cadena=cadena;
	return nodo;
}

Tarbol crea_nodo_arbol(){  /*estoy creando un nodo, no una raiz. Es una raiz cuando el puntero derecho e izquierdo es distinto de vacio*/
	Tarbol nodo;
	nodo=(Tarbol)malloc(sizeof(Tnodo_arbol));
	nodo->tipo=SET;
	nodo->dato_arbol=NULL;
	nodo->sig=NULL;
	return nodo;
}

void inicia_arbol(Tarbol *raiz){
	(*raiz)->dato_arbol=NULL;
	(*raiz)->sig=NULL;
}

void agrega_der(Tarbol *raiz, Tarbol nuevo){
	(*raiz)->dato_arbol=nuevo;
}

void agrega_izq(Tarbol *raiz, Tarbol nuevo){
	(*raiz)->sig=nuevo;
}


/*void muestra_nodo_arbol(Tarbol uno){
	if(uno!=NULL){
		muestra_nodo_char(uno->dato_arbol);
	}
}
*/


/*
void recorre_arbol_REC(Tarbol raiz){  recorre siempre por la izquierda del arbol
	if(raiz!=NULL){
		recorre_arbol(raiz->dato);
		hago alguna cosa
		recorre_arbol(raiz->sig);
	}
}

void carga_arbol(Tarbol *raiz, Tarbol nodo){
	Tarbol aux;
	if(*raiz==NULL){
		nodo=crea_nodo_arbol();
		*raiz=nodo;
	}
	else{
		aux=*raiz;
		carga_arbol(aux->dato, nodo);
	}
}
*/


/*
Tarbol carga(){
	Tarbol raiz;
	Conjunto Q, E, q0, F, T;
	raiz=crea_nodo_arbol();
	inicializa(&Q, &E, &q0, &F, &T);
	carga_alfabeto(&E);
	Crea_estados(&Q,&q0);
	carga_EstAceptacion(&F,Q);
	trancisionesAFND(&T);
	carga_arbol(&raiz, &Q);
	return raiz;
}

void carga_arbol(Tarbol *raiz, Conjunto *Q){
	Tarbol nuevo, nuevo2;
	T_ele cadena;
	inicia_arbol(&nuevo);
	inicia_arbol(&nuevo2);
	if(*raiz==NULL){
		agrega_der(raiz, nuevo);
		agrega_izq(raiz, nuevo2);
		carga_arbol(*raiz->dato_arbol, *Q);
	}
	else{
		if((*Q)->sig!=NULL){ 
			cadena=retornaElemento(*Q);
			nuevo->dato_arbol = (Tarbol) crea_nodo_string_parametro(cadena);
			agrega_der(raiz, nuevo);
			carga_arbol(raiz, &Q->sig);
		}
		else{
			cadena=retornaElemento(*Q);
			nuevo->dato_arbol = (Tarbol) crea_nodo_string_parametro(cadena);
		}
	}
	
}


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
*/

/*
Tarbol carga_arbol(int *e){
	Tarbol raiz;
	Conjunto E, Q, q_0, F, T;
	
	inicializa(&Q, &E, &q_0, &F, &T);
	raiz=crea_nodo_arbol();
	
	*e=Crea_estados(&Q,&q_0); 
    printf("estado");
	
	carga_estado(&raiz, Q, *e);
	printf("cargo estados");
	
	carga_alfabeto(&E);
	carga_EstAceptacion(&F,Q);
	printf("aceptacion");
	
	return raiz;
}

void carga_estado(Tarbol *raiz, Conjunto Q, int tam){
	Tarbol aux;
	T_ele cadena;
	aux=*raiz;
	carga(aux->dato_arbol, tam, cadena, Q);
}

void carga(Tarbol raiz, int tam, T_ele cadena, Conjunto Q){
	if(tam>1){
		printf("esta cargando ");
		cadena=retornaElemento(Q);
		raiz->dato_arbol=(Tarbol)crea_nodo_string_parametro(cadena);
		raiz->sig=crea_nodo_arbol();
		carga(raiz->sig, tam-1, cadena, Q->sig);
	}
	else{
		printf("cargo el ultimo");
		raiz->dato_arbol=(Tarbol)crea_nodo_string_parametro(cadena);
		raiz->sig=NULL;
	}
}

void muestra_arbol(Tarbol raiz, int e){
	if(raiz!=NULL)
		muestra_arbol_rec(raiz->dato_arbol, e);
}
*/

/*
void muestra_arbol_rec(Tarbol raiz, int e){
	if(e>0){
		muestra_nodo_string(raiz->dato_arbol);
		muestra_arbol_rec(raiz->sig, e-1);	
	}
}

*/
/*
Tarbol carga_arbol(int *n){
	Tarbol arbol, aux;
	T_ele cadena;
	int i;
	arbol=crea_nodo_arbol();
	arbol->dato_arbol=crea_nodo_arbol();
	arbol->sig=crea_nodo_arbol();
	aux=arbol->dato_arbol;
	for(i=1;i<3;i++){
		cadena=carga_ele();
	    aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(cadena);
	    aux->sig=crea_nodo_arbol();
		aux=aux->sig;
		printf("cargo %d", i);
	}
	cadena=carga_ele();
	aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(cadena);
	aux->sig=NULL;
	printf("cargo 3");
	return arbol;
}
*/

void muestra_arbol(Tarbol raiz){ 
	
	printf("\n\nMUESTRA ESTADOS");
	muestra_conjunto(raiz->dato_arbol);
	printf("\n\nMUESTRA ALFABETO");
	raiz=raiz->sig;
	muestra_conjunto(raiz->dato_arbol);
	printf("\n\nMUESTRA ESTADO INICIAL");	
	raiz=raiz->sig;
	muestra_conjunto(raiz->dato_arbol);
	printf("\n\nMUESTRA ESTADOS DE ACEPTACION");
	raiz=raiz->sig;
	muestra_conjunto(raiz->dato_arbol);
	printf("\n\nMUESTRA TRANSICIONES");
    raiz=raiz->sig;
	muestra_trans(raiz);
}

void muestra_trans(Tarbol raiz){  //muestra el conjunto de transiciones
	printf("\n{");
	while(raiz!=NULL){
		muestra_conjunto_trans(raiz->dato_arbol);
		raiz=raiz->sig;
		if(raiz!=NULL)
			printf(", ");
	}
	printf("}");
}

void muestra_conjunto_trans(Tarbol raiz){  //muestra una transicion
	int i=1, b=0, s=0;
	printf("(");
	while(raiz->sig!=NULL){
		if(i<=2 || b==0){
			i++;
		}
		else{
			b=1;
		}
		muestra_nodo_string(raiz->dato_arbol);
		printf(", ");
		raiz=raiz->sig;
		if(i>2 && raiz->sig!=NULL && s==0){
			s=1;
			printf("{");
		}
	}
	muestra_nodo_string(raiz->dato_arbol);
	if(s==1){
		printf("}");
	}
	printf(")");
}
void muestra_conjunto(Tarbol raiz){
	if(raiz!=NULL){
	printf("\n{");
	while(raiz->sig!=NULL){
		muestra_nodo_string(raiz->dato_arbol);
		printf(", ");
	    raiz=raiz->sig;
	}
	muestra_nodo_string(raiz->dato_arbol);
	printf("}");
	}
	else
	   printf("\nCONJUNTO VACIO");
}

void muestra_nodo_string(Tstring nodo){
	if(nodo!=NULL){
		muestra_ele(nodo->dato_cadena);
	}
}

void carga_N(Conjunto *N, Conjunto T){
	Tcadena cadena, aux_cadena;
	T_ele antes, entre;
	Conjunto acep;
	
	retorna_ele(T->dato, cadena);
	
	strcpy(aux_cadena, cadena);
	antes=antesComa(aux_cadena);
	agregar_elemento(N, antes);
	
	strcpy(aux_cadena, cadena);
	entre=entreComa(aux_cadena);
	agregar_elemento(N, entre);
	
	strcpy(aux_cadena, cadena);
	acep=despuesComa(aux_cadena);
	
	while(acep!=NULL){
		agregar_elemento(N, acep->dato);
		acep=acep->sig;
	}
}

Tarbol carga_arbol(){
	Tarbol arbol, aux;
	Conjunto Q, E, q_0, F, T, T_aux, N;
	int e, a, ea, t, i, n;
	inicializa(&Q, &E, &q_0, &F, &T);
	printf("\nINGRESO DE ALFABETO");
	carga_alfabeto(&E);
	printf("\nINGRESO DE ESTADOS");
	Crea_estados(&Q,&q_0);
	printf("\nINGRESO DE ESTADOS DE ACEPTACION");
	carga_EstAceptacion(&F, Q);
	printf("\nINGRESO DE TRANSICIONES");
	printf("\nPARA AFD: LA CARGA DE TRANSICION ES DEL FORMATO: \nEstadoPartida,ElementoDelAlfabeto,EstadoLlegada");
	printf("\nPARA AFND: LA CARGA DE TRANSICION ES DEL FORMATO: \nEstadoPartida,ElementoDelAlfabeto,{EstadoLlegada1,EstadoLlegada2,...}");
	transicionesAFND(Q, E, &T);
	
	e=Cant_estados(Q);
	a=Cant_estados(E);
	ea=Cant_estados(F);
    t=Cant_estados(T); //total de transiciones
	
	arbol=crea_nodo_arbol();
	crea_hijos(&arbol);
	carga_conjunto(arbol->dato_arbol, e, Q);
	
    aux=arbol->sig;
	crea_hijos(&aux);
	carga_conjunto(aux->dato_arbol, a, E);
	
	aux=aux->sig;
	crea_hijos(&aux);
	carga_conjunto(aux->dato_arbol, 1, q_0);
	
	aux=aux->sig;
	crea_hijos(&aux);
	carga_conjunto(aux->dato_arbol, ea, F);
	
	T_aux=T;
	
	aux=aux->sig;
	
	if(T_aux->sig==NULL)  //si hay un solo nodo en las transiciones
		crea_hijos_ultimo(&aux);
	else
		crea_hijos(&aux);
	
	for(i=1;i<t;i++){
		N=conjuntovacio();
		carga_N(&N, T_aux);
		n=Cant_estados(N);
		carga_conjunto(aux->dato_arbol, n, N);
		aux=aux->sig;
		T_aux=T_aux->sig;
		if(T_aux->sig==NULL)
			crea_hijos_ultimo(&aux);
		else
			crea_hijos(&aux);
	}
	
	N=conjuntovacio();
	carga_N(&N, T_aux);
	n=Cant_estados(N);
	carga_conjunto(aux->dato_arbol, n, N);
	
	/*carga_conjunto(aux->dato_arbol, t, T);*/
	/*carga_conjunto_trans(aux, t, T);*/
	
	/*Conjunto N, acep;
	Tcadena cadena, aux_cadena;
	T_ele antes, entre;
	int n;
	
	acep=conjuntovacio();
	N=conjuntovacio();
	
	while(T!=NULL){
		retorna_ele(T->dato, cadena);
		
		strcpy(aux_cadena, cadena);
		antes=antesComa(aux_cadena);
		agregar_elemento(&N, antes);
		
		strcpy(aux_cadena, cadena);
		entre=entreComa(aux_cadena);
		agregar_elemento(&N, entre);
		
		strcpy(aux_cadena, cadena);
		acep=despuesComa(aux_cadena);
		
		while(acep!=NULL){
			agregar_elemento(&N, acep->dato);
			acep=acep->sig;
		}
		
		n=Cant_estados(N);
		
		carga_conjunto(aux->dato_arbol, n, N);
		
		N=conjuntovacio();
		T=T->sig;
		
		aux=aux->sig;
		
		if(T->sig==NULL){
			crea_hijos_ultimo(&aux);
		}
		else{
			crea_hijos(&aux);
		}
	}
	
	*/
	printf("\n");
	system("PAUSE");
	system("cls");

	return arbol;
}
/*	
void carga_conjunto_trans(Tarbol raiz, int t, Conjunto T){
	Conjunto N, acep;
	Tcadena cadena, aux_cadena;
	T_ele antes, entre;
	int n;
	acep=conjuntovacio();
	N=conjuntovacio();
	
	while(T!=NULL){
		retorna_ele(T->dato, cadena);
		printf("cadenaaaaaaaa: %s", cadena);
		strcpy(aux_cadena, cadena);
		
		antes=antesComa(aux_cadena);
		agregar_elemento(&N, antes);
		
		strcpy(aux_cadena, cadena);
		entre=entreComa(aux_cadena);
	    agregar_elemento(&N, entre);
		
		strcpy(aux_cadena, cadena);
	    acep=despuesComa(aux_cadena);
		
	    while(acep!=NULL){
		    agregar_elemento(&N, acep->dato);
		    acep=acep->sig;
	    }
		
	    n=Cant_estados(N);
		
	    carga_conjunto(raiz->dato_arbol, n, N);
		muestra_conjunto(raiz->dato_arbol);
		
		N=conjuntovacio();
		T=T->sig;
		
		raiz=raiz->sig;
		
		if(T->sig==NULL){
			crea_hijos_ultimo(&raiz);
		}
		else{
			crea_hijos(&raiz);
		}
	}
	
}
*/
void crea_hijos(Tarbol *arbol){
	(*arbol)->dato_arbol=crea_nodo_arbol();
	(*arbol)->sig=crea_nodo_arbol();
}

void crea_hijos_ultimo(Tarbol *arbol){
	(*arbol)->dato_arbol=crea_nodo_arbol();
	(*arbol)->sig=NULL;
}

void carga_conjunto(Tarbol aux, int e, Conjunto Q){
	int i;
	T_ele cadena;
	for(i=1;i<e;i++){
		cadena=retornaElemento(Q);
		Q=Q->sig;
		aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(cadena);
		aux->sig=crea_nodo_arbol();
		aux=aux->sig;
	}
	cadena=retornaElemento(Q);
	aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(cadena);
	aux->sig=NULL;
}
/*
Tarbol carga_arbol(){
	Tarbol arbol, aux;
	T_ele cadena;
	cadena=carga_ele();
	arbol=crea_nodo_arbol();
	crea_hijos(&arbol);
	aux=arbol->dato_arbol;
	aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(cadena);
	aux->sig=NULL;
	
	aux=arbol->sig;
	crea_hijos(&aux);
	aux=aux->dato_arbol;
	cadena=carga_ele();
	aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(cadena);
	aux->sig=NULL;
	
	return arbol;
}
*/
/*
void muestra_arbol(Tarbol raiz){
	Tarbol aux;
	aux=raiz->sig;
	raiz=raiz->dato_arbol;
	muestra_nodo_string(raiz->dato_arbol);
	aux=aux->dato_arbol;
	muestra_nodo_string(aux->dato_arbol);

}

*/

Tarbol retorna_estado_inicial(Tarbol raiz){
	int i;
	for(i=1; i<=2; i++){
		raiz=raiz->sig;
	}
	return raiz->dato_arbol;
}

Tarbol retorna_estado_acep(Tarbol raiz){
	int i;
	for(i=1; i<=3; i++){
		raiz=raiz->sig;
	}
	return raiz->dato_arbol;
}

Tarbol retorna_transi(Tarbol raiz, int n){
	int i;
	for(i=1; i<=n; i++){
		raiz=raiz->sig;
	}
	return raiz;
}

T_ele retorna_dato_cadena(Tstring nodo){
	return nodo->dato_cadena;
}

void acepta_cadena(Tarbol arbol){
	Tarbol q_0, F, T, T_recorre, aux_T, nuevo, acep, ant, auxAnt;
	Tcadena leido,cadCom,auxcadCom;  //leido es la cadena ingresada
	T_ele elem,elemAnt, ele; 
	int i=0,b1,b2, n=4;
	char cara;  //contiene un caracter de la cadena
	
	q_0=retorna_estado_inicial(arbol);
	
	//muestra_conjunto(q_0);
	
	F=retorna_estado_acep(arbol);
	
	//muestra_conjunto(F);
	
	T=retorna_transi(arbol, n);
	
	//muestra_conjunto(T);
	
	ant=auxAnt=nuevo=acep=T_recorre=arbol_vacio();
	
	agrega_elemento_arbol(&ant,retorna_dato_cadena(q_0->dato_arbol));
	auxAnt=ant;
	T_recorre=T;
	//muestra_conjunto(ant);
	
	printf("\n\nSe respondera si una cadena es aceptada o no. ");
	printf("\nIngrese cadena: ");
	leeCad(leido,tam_max);
	
	cara=leido[i];

	//printf("cara: %c", cara);
	
	while(cara!='\0'){
		//printf("\nentro primer while");
		//printf("\ncara: %c", cara);
		//system("pause");
		while(auxAnt!=NULL){ //auxAnt CONJUNTO DE ESTADOS
			//printf("\nentro segundo while");
			//if(aux_T!=NULL)
				aux_T=T->dato_arbol;
				T_recorre=T;
			//	printf("\nmuestra aux_t");
			//	muestra_conjunto(aux_T);
			//	system("pause");
			//	printf("\nmuestra t_recorre");
			//	muestra_conjunto(T_recorre);
			//	system("pause");
			while(aux_T!=NULL){ //hasta que la lista de transiciones se termine
			//    printf("\nentro tercer while");
				//	printf("MUESTRA AUX_T iteracion");
			//	muestra_conjunto(aux_T);
			//	system("pause");
				//elem=retornaElemento(auxTransiciones);
				//elemAnt=retornaElemento(auxAnt);
				elemAnt=retorna_dato_cadena(auxAnt->dato_arbol);  //contiene estado inicial T_ele
				//retorna_ele(elem,auxcadCom);
				//strcpy(cadCom,auxcadCom);
				
				b1=strcmp(retorna_dato_cadena(aux_T->dato_arbol).cadena, elemAnt.cadena);
				//printf("elemento 1: %s, elemento 2: %s", retorna_dato_cadena(aux_T->dato_arbol).cadena, elemAnt.cadena);
				//retorna_ele(elem,auxcadCom);
				//strcpy(cadCom,auxcadCom);
				aux_T=aux_T->sig;
				
				b2=strcmp(retorna_dato_cadena(aux_T->dato_arbol).cadena, carga_caracter_ele(cara).cadena);
				//printf("elemento 1: %s, elemento 2: %s", retorna_dato_cadena(aux_T->dato_arbol).cadena, carga_caracter_ele(cara).cadena);
				//printf("mustra b1: %d, muestra b2: %d", b1, b2);
				//system("pause");
				//retorna_ele(elem,auxcadCom);
				//strcpy(cadCom,auxcadCom);
				
				if(b1==0 && b2==0){
					//printf("\nentro primer if");
					//if(compara_ele(antesComa(cadCom),elemAnt)==0 && compara_ele(entreComa(cadCom),carga_caracter(cara))==0){
				//	strcpy(auxcadCom, elem.cadena);  //copia elem.cadena en auxcadCom
				//	acep=despuesComa(auxcadCom);
					aux_T=aux_T->sig;
				//	printf("\nmuestra acep");
				//	muestra_conjunto(aux_T);
				//	system("pause");
					agrega_repetidos_arbol(&nuevo,aux_T);  //agrega los nodos de acep a nuevo sin importar si hay repetidos
				//	printf("\nmuestra nuevo");
				//	muestra_conjunto(nuevo);
				//	system("pause");
					//	printf("entra en el ciclo");
				//	printf("muestra nuevo");
				//	muestra_conjunto(nuevo);
				//	system("pause");
				 //   printf("\nsalio del primer if");
				}
				
				aux_T=T_recorre->sig;
				T_recorre=T_recorre->sig;
				if(aux_T!=NULL){
				//	printf("\nentro segundo if");
					aux_T=aux_T->dato_arbol;
				//	printf("\nsalio segundo if");
				}
			}
			//printf("\nsalio tercer while");
			//system("pause");
			auxAnt=auxAnt->sig;
			//printf("\nmuestra aux_ant");
			//muestra_conjunto(auxAnt);
			//system("pause");
		}
		//printf("\nsalio segundo while");
		ant=nuevo;
		auxAnt=ant;
		nuevo=arbol_vacio();
		i++;
		cara=leido[i];
		//printf("\nmuestra ant");
		//muestra_conjunto(ant);
		//system("pause");
		//printf("\nmuestra aux_ant");
		//muestra_conjunto(auxAnt);
		//system("pause");
	}
	//printf("salio primer while");
	//system("pause");
	
	//printf("muestra ant");
	//muestra_conjunto(ant);
	//system("pause");
	
	//printf("muestra F");
	//muestra_conjunto(F);
	//system("pause");
	
	//printf("\nmuestra interseccion");
	//muestra_conjunto(interseccion_arbol(ant, F));
	//system("pause");
	
	if(interseccion_arbol(ant, F)!=NULL)
		  printf("\nLA CADENA ES ACEPTADA!");
	else
		printf("\nLA CADENA NO ES ACEPTADA!");

}

Tarbol arbol_vacio(){
	return NULL;
}
void interseccion_arbol_rec(Tarbol a,Tarbol b, Tarbol *nuevo){
	if(a!=NULL){
		if(pertenece_arbol(b, retorna_dato_cadena(a->dato_arbol))==1)  //si es igual a 1 pertenece
			agrega_elemento_arbol(nuevo, retorna_dato_cadena(a->dato_arbol));
		a=a->sig;
		interseccion_arbol_rec(a, b, nuevo);
	}
}

Tarbol interseccion_arbol(Tarbol a, Tarbol b){
	Tarbol nuevo=arbol_vacio();
	interseccion_arbol_rec(a, b, &nuevo);
	//printf("muestra nuevo de interseccion");
	//muestra_conjunto(nuevo);
	return nuevo;
}

int pertenece_arbol(Tarbol a, T_ele e){ //si lo encontro retorna 1
	if(a!=NULL){
		if(a!=NULL && compara_ele(retorna_dato_cadena(a->dato_arbol), e)!=0){
			a=a->sig;
			return pertenece(a, e);
		}
		if(a==NULL)
		   return 0;
		else 
			return 1; 
	}
	else 
	   return 0;
}

void agrega_repetidos_arbol(Tarbol *a, Tarbol b){
	Tarbol aux;
	aux=arbol_vacio();
	while(b!=NULL){
		if(*a==NULL){
			*a=crea_nodo_arbol();
			crea_hijos_parametro(a, retorna_dato_cadena(b->dato_arbol));
		}
		else{
			aux=*a;
			while(aux->sig!=NULL){
				aux=aux->sig;
			}
			aux->sig=crea_nodo_arbol();
			crea_hijos_parametro(&aux->sig, retorna_dato_cadena(b->dato_arbol));
		}
     	b=b->sig;
	}
}

void crea_hijos_parametro(Tarbol *raiz, T_ele dato){
	(*raiz)->dato_arbol=(Tarbol)crea_nodo_string_parametro(dato);
	(*raiz)->sig=NULL;
}

void agrega_elemento_arbol(Tarbol *lis, T_ele dato){
	Tarbol aux;
	Tarbol nodo;
	nodo=crea_nodo_arbol();
	crea_hijos_parametro(&nodo, dato);
	
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
