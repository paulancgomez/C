#include "interfazARBOL.h"

//CREA NODOS
Tarbol crea_nodo_arbol();
T_ele crea_nodo_elemento();
T_ele crea_nodo_elemento_parametro(Telemento);
void muestra_nodo_elemento(T_ele);
void crea_hijos_ultimo(Tarbol *arbol);

//RETORNA
Telemento retorna_dato_cadena(T_ele nodo);

//CARGA
void carga_estados_arbol(Tarbol);

//MUESTRA
void muestra_conjunto(Tarbol);
void muestra_lista(Tarbol);
void muestra_nodo(Tarbol);

//INICIALIZA
void crea_hijos(Tarbol *);

//PERTENECE
int pertenece_arbol(Tarbol, Telemento);

//DESARROLLO

//MODULOS PUBLICOS

Tarbol carga_arbol(){
	Tarbol arbol, aux, Q;
	
	printf("\n\nCARGANDO AUTOMATA..");
	
	arbol=aux=arbol_vacio();
	
	printf("\n\nINGRESO DE ESTADOS");
	arbol=crea_nodo_arbol();
	crea_hijos_ultimo(&arbol);  //corregir luego a crea hijos (solamente)
	//printf("antes del carga");
	carga_estados_arbol(arbol->dato_arbol);
	//printf("despues del carga");
	Q=arbol->dato_arbol;
	//if(arbol->sig==NULL)
	//	printf("solo cargo estadossssssssss");
	//printf("\nAUTOMATA CARGADO.");
	
	printf("\nmostrando lista");
	muestra_conjunto(Q);
	
	printf("\n\n");
	system("PAUSE");
	system("cls");
	
	return arbol;
}


void muestra_arbol(Tarbol raiz){
	printf("MUESTRA ESTADOS: ");
	muestra_conjunto(raiz->dato_arbol);
}

//CREA NODOS

Tarbol crea_nodo_arbol(){
	Tarbol nodo;
	nodo=(Tarbol)malloc(sizeof(Tnodo_arbol));
	nodo->tipo=INI;
	nodo->dato_arbol=NULL;
	nodo->sig=NULL;
	return nodo;
}

T_ele crea_nodo_elemento(){
	T_ele nodo;
	nodo=(T_ele)malloc(sizeof(Tnodo_elemento));
	nodo->dato=0;
	nodo->tipo=1;
	return nodo;
}

T_ele crea_nodo_elemento_parametro(Telemento ele){
	T_ele nodo;
	nodo=(T_ele)malloc(sizeof(Tnodo_elemento));
	nodo->dato=0;
	nodo->tipo=1;
	nodo->dato_ele=ele;
	//printf("despues del asterisco");
	return nodo;
}

//CARGA

void carga_estados_arbol(Tarbol Q){
	Tarbol aux;
	Telemento x, vacio;
	int i,b,c,z;
	aux=Q;
	printf("\n");
	do{
		printf("Ingrese la cantidad de estados: ");
		scanf("%d",&c);
		if(c<=0)
			printf("Por favor ingrese una cantidad positiva.\n");
	}while(c<=0);
	for(i=1;i<c;i++){
		vacio=carga_ele_parametro(' ');
		printf("Ingrese el nombre del estado: ");
		x=carga_ele();
		b=pertenece_arbol(Q, x);
		z=compara_ele(x,vacio);
		//printf("b vale %d y z vale%d", b, z);
		while(b==1 || z==0){
			printf("ESTADO NO VALIDO. Vuelva a ingresar: ");
			x=carga_ele();
			b=pertenece_arbol(Q, x);
			z=compara_ele(x,vacio);
		}
		//printf("salio while");
		aux->dato_arbol=(Tarbol)crea_nodo_elemento_parametro(x);
		printf("\nmuestro en el nodo: ");
		muestra_nodo(aux->dato_arbol); //despues sacar
		aux->sig=crea_nodo_arbol();
		aux=aux->sig;
	}
	//printf("\nsalio for");
	vacio=carga_ele_parametro(' ');
	printf("\nIngrese el nombre del estado: ");
	x=carga_ele();
	b=pertenece_arbol(Q, x);
	z=compara_ele(x,vacio);
	while(b==1 || z==0){
		printf("ESTADO NO VALIDO. Vuelva a ingresar: ");
		x=carga_ele();
		b=pertenece_arbol(Q, x);
		z=compara_ele(x,vacio);
	}
	aux->dato_arbol=(Tarbol)crea_nodo_elemento_parametro(x);
	aux->sig=NULL;
	printf("\nmuestro en el nodo: ");
	muestra_nodo(aux->dato_arbol); //despues sacar
}

//MUESTRA

void muestra_nodo(Tarbol nodo){
	T_ele x;
	if(nodo!=NULL){
		x=(T_ele)nodo;
		muestra_ele(x->dato_ele);
	}
	else
	   printf("VACIO");
}

void muestra_conjunto(Tarbol raiz){
	if(raiz!=NULL){
		printf("\n{");
		while(raiz->sig!=NULL){
			muestra_nodo_elemento((T_ele)raiz->dato_arbol);
			printf(", ");
			raiz=raiz->sig;
		}
		muestra_nodo_elemento((T_ele)raiz->dato_arbol);
		printf("}");
	}
	else
	   printf("\nCONJUNTO VACIO");
}

void muestra_nodo_elemento(T_ele nodo){
	if(nodo!=NULL){
		//printf("elemento distinto de null");
		muestra_ele(nodo->dato_ele);
	}
}

void muestra_lista(Tarbol raiz){
	//printf("entro a muestra");
	if(raiz!=NULL){
		//printf("distinto de null");
		while(raiz!=NULL){
			//printf("entro while");
			muestra_nodo_elemento((T_ele)raiz->dato_arbol);
			//printf("mostro uno");
			raiz=raiz->sig;
		}
		//printf("salio while");
	}
	else
	   printf("lista vacia");
}

//PERTENECE

int pertenece_arbol(Tarbol a, Telemento e){ //(1)si lo encontro. (0) no lo encontro
	if(a!=NULL){
		if(a->dato_arbol!=NULL){
			if(a!=NULL && compara_ele(retorna_dato_cadena((T_ele)a->dato_arbol), e)!=0){
				a=a->sig;
				return pertenece_arbol(a, e);
			}
			if(a==NULL)
			   return 0;
			else 
				return 1; 
		}
		else
		   return 0;
	}
	else 
	   return 0;
}

//INICIALIZA

void crea_hijos(Tarbol *arbol){
	(*arbol)->dato_arbol=crea_nodo_arbol();
	(*arbol)->sig=crea_nodo_arbol();
}

void crea_hijos_ultimo(Tarbol *arbol){
	(*arbol)->dato_arbol=crea_nodo_arbol();
	(*arbol)->sig=NULL;
}

//RETORNA

Tarbol arbol_vacio(){
	return NULL;
}

Telemento retorna_dato_cadena(T_ele nodo){   //retorna el dato del puntero tipo String
	return nodo->dato_ele;
}
