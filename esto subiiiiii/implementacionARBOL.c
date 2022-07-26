#include "interfazARBOL.h"

//CREA NODOS
Tarbol crea_nodo_arbol();
Tstring crea_nodo_string();
Tstring crea_nodo_string_parametro(T_ele);

//INICIALIZA
void crea_hijos(Tarbol*);
void crea_hijos_parametro(Tarbol*, T_ele);

//CARGA ARBOL
void carga_alfabeto_arbol(Tarbol);
void carga_conjunto_arbol(Tarbol, int, int, T_ele);
void carga_estado_ini(Tarbol, Tarbol);
void carga_estados_arbol(Tarbol);
void carga_estado_acep(Tarbol, Tarbol);
void carga_transi_arbol(Tarbol, Tarbol);

//MUESTRA ARBOL
void muestra_conjunto(Tarbol);
void muestra_nodo_string(Tstring);
void muestra_trans(Tarbol);
void muestra_conjunto_trans(Tarbol);

//RETORNA
T_ele retorna_dato_cadena(Tstring);
Tarbol retorna_Q(Tarbol raiz);
Tarbol retorna_alfabeto(Tarbol raiz);


//OTROS
Tarbol despuesComa_arbol(Tcadena);
int repe_transiciones_arbol(Tarbol, T_ele);
int contiene_arbol(Tarbol,Tarbol );
int pertenece_arboles(Tarbol, Tarbol);
int cant_estados_arbol(Tarbol);
int pertenece_arbol(Tarbol a, T_ele e);
void agrega_elemento_arbol(Tarbol *, T_ele);
void agrega_repetidos_arbol(Tarbol *a, Tarbol b);

//MODULOS PUBLICOS

Tarbol arbol_vacio(){
	return NULL;
}

Tarbol carga_arbol(){
	Tarbol arbol, aux, Q;
	
	printf("\n\nCARGANDO AUTOMATA..");
	
	arbol=aux=arbol_vacio();
	
	printf("\n\nINGRESO DE ESTADOS");
	arbol=crea_nodo_arbol();
	crea_hijos(&arbol);
	carga_estados_arbol(arbol->dato_arbol);
	Q=arbol->dato_arbol;
	
	printf("\nINGRESO DE ALFABETO");
	aux=arbol->sig;
	crea_hijos(&aux);
	carga_alfabeto_arbol(aux->dato_arbol);
	
	printf("\nINGRESO DE ESTADO INICIAL");
	aux=aux->sig;
	crea_hijos(&aux);
	carga_estado_ini(aux->dato_arbol, Q);
	
	printf("\nINGRESO DE ESTADOS DE ACEPTACION");
	aux=aux->sig;
	crea_hijos(&aux);
	carga_estado_acep(aux->dato_arbol, arbol);
	
	printf("\nINGRESO DE TRANSICIONES");
	printf("\nNOTA: LA CARGA DE TRANSICION CUANDO TIENE UN SOLO ESTADO DE LLEGADA ES DEL FORMATO: \nEstadoPartida,ElementoDelAlfabeto,EstadoLlegada");
	printf("\nNOTA: LA CARGA DE TRANSICION CUANDO TIENE MAS DE UN ESTADO DE LLEGADA ES DEL FORMATO: \nEstadoPartida,ElementoDelAlfabeto,{EstadoLlegada1,EstadoLlegada2,...}");
	printf("\nNOTA: LA CARGA DE TRANSICION DE UN ESTADO QUE LLEGA AL VACIO ES DEL FORMATO: \nEstadoPartida,ElementoDelAlfabeto,");
	
	aux=aux->sig;
	crea_nodo_arbol(&aux);
	carga_transi_arbol(aux, arbol);
	
	printf("\nAUTOMATA CARGADO.");
	
	printf("\n\n");
	system("PAUSE");
	system("cls");
	
	return arbol;
}

void muestra_arbol(Tarbol raiz){ 
	printf("\nMOSTRANDO DATOS DEL AUTOMATA..");
	printf("\n\n*******************************");
	printf("\nMUESTRA ESTADOS");
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
	printf("\n\n*******************************");
}

//CREA NODOS

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

Tarbol crea_nodo_arbol(){
	Tarbol nodo;
	nodo=(Tarbol)malloc(sizeof(Tnodo_arbol));
	nodo->tipo=SET;
	nodo->dato_arbol=NULL;
	nodo->sig=NULL;
	return nodo;
}

//MUESTRA

void muestra_trans(Tarbol raiz){  //muestra el conjunto de transiciones
	if(raiz!=NULL){
		printf("\n{");
		while(raiz!=NULL){
			muestra_conjunto_trans(raiz->dato_arbol);
			raiz=raiz->sig;
			if(raiz!=NULL)
				printf(", ");
		}
		printf("}");
	}
	else
	   printf("\nCONJUNTO VACIO.");
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
		muestra_nodo_string((Tstring)raiz->dato_arbol);
		printf(", ");
		raiz=raiz->sig;
		if(i>2 && raiz->sig!=NULL && s==0){
			s=1;
			printf("{");
		}
	}
	if(i==2){
		muestra_nodo_string((Tstring)raiz->dato_arbol);
		printf(", EstadoVacio");
	}
	else
	   muestra_nodo_string((Tstring)raiz->dato_arbol);
	if(s==1){
		printf("}");
	}
	printf(")");
}

void muestra_conjunto(Tarbol raiz){
	if(raiz!=NULL){
		printf("\n{");
		while(raiz->sig!=NULL){
			muestra_nodo_string((Tstring)raiz->dato_arbol);
			printf(", ");
			raiz=raiz->sig;
		}
		muestra_nodo_string((Tstring)raiz->dato_arbol);
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

//CARGA ARBOL

void carga_alfabeto_arbol(Tarbol E){
	Tarbol aux;
	int tam,i,B; 
	T_ele sim; 
	B=0;
	aux=E;
	printf("\n");
	do{
		printf("Ingrese cantidad de simbolos del alfabeto: ");
		scanf("%i",&tam);
		if(tam<=0)
			printf("Por favor ingrese una cantidad positiva.\n");
	}while(tam<=0);
	for(i=1; i<tam; i++){
		printf("Ingrese simbolo: ");
		sim=carga_ele();
		B=pertenece_arbol(E,sim);
		while(B==1){
			printf("SIMBOLO NO VALIDO. Ingrese otro simbolo: ");
			sim=carga_ele();
			B=pertenece_arbol(E, sim);
		}
		aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(sim);
		aux->sig=crea_nodo_arbol();
		aux=aux->sig;
	}
	printf("Ingrese simbolo: ");
	sim=carga_ele();
	B=pertenece_arbol(E,sim);
	while(B==1){
		printf("SIMBOLO NO VALIDO. Ingrese otro simbolo: ");
		sim=carga_ele();
		B=pertenece_arbol(E, sim);
	}
	aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(sim);
	aux->sig=NULL;
}

void carga_estados_arbol(Tarbol Q){
	Tarbol aux;
	T_ele x, vacio;
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
		vacio=carga_ele_parametro(" ");
		printf("Ingrese el nombre del estado: ");
		x=carga_ele();
		b=pertenece_arbol(Q, x);
		z=compara_ele(x,vacio);
		while(b==1 || z==0){
			printf("ESTADO NO VALIDO. Vuelva a ingresar: ");
			x=carga_ele();
			b=pertenece_arbol(Q, x);
			z=compara_ele(x,vacio);
		}
		aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(x);
		aux->sig=crea_nodo_arbol();
		aux=aux->sig;
	}
	vacio=carga_ele_parametro(" ");
	printf("Ingrese el nombre del estado: ");
	x=carga_ele();
	b=pertenece_arbol(Q, x);
	z=compara_ele(x,vacio);
	while(b==1 || z==0){
		printf("ESTADO NO VALIDO. Vuelva a ingresar: ");
		x=carga_ele();
		b=pertenece_arbol(Q, x);
		z=compara_ele(x,vacio);
	}
	aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(x);
	aux->sig=NULL;
}

void carga_estado_ini(Tarbol q_0, Tarbol Q){
	T_ele x;
	int b;
	printf("\nIngrese el nombre del estado: ");
	x=carga_ele();
	b=pertenece_arbol(Q, x);
	while(b==0){
		printf("ESTADO NO VALIDO. Vuelva a ingresar: ");
		x=carga_ele();
		b=pertenece_arbol(Q, x);
	}
	q_0->dato_arbol=(Tarbol)crea_nodo_string_parametro(x);
	q_0->sig=arbol_vacio();
}

void carga_estado_acep(Tarbol F, Tarbol Q){
	int opc,B1,B2; // CA, CEst;
	T_ele etiqueta;
	Tarbol aux;
	Q=retorna_Q(Q);
	opc=0;  //CA=0;
	//CEst=Cant_estados(Est);
	aux=F;
	printf("\n");
	do{
		printf("Ingrese estado de aceptacion: ");
		etiqueta=carga_ele();
		B1=pertenece_arbol(Q, etiqueta);
		B2=pertenece_arbol(F,etiqueta);
		while(B1!=1 || B2==1){
			printf("ESTADO NO VALIDO. Ingrese otro: ");
			etiqueta=carga_ele();
			B1=pertenece_arbol(Q, etiqueta);
			B2=pertenece_arbol(F, etiqueta);
		}
		printf("Desea ingresar otro estado de aceptacion? SI (1) - NO (0): ");
		scanf("%i",&opc);
		//	CA++;
		if(opc){
			aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(etiqueta);
			aux->sig=crea_nodo_arbol();
			aux=aux->sig;
		}
		else{
			aux->dato_arbol=(Tarbol)crea_nodo_string_parametro(etiqueta);
			aux->sig=NULL;
		}
	} while(opc!=0); //&& CA<=CEst
}

void carga_transi_arbol(Tarbol T, Tarbol arbol){
	Tarbol Q, E, aux, T_recorre, acep, nuevo; 
	int res;
	T_ele elemTran1, elemTran2;
	Tcadena tranLeida,auxTranLeida;
	res=1;
	aux=acep=nuevo=arbol_vacio();
	Q=retorna_Q(arbol);
	E=retorna_alfabeto(arbol);
	T_recorre=T;
	printf("\n\n");
	aux=T_recorre;
	do{
		printf("Ingrese transicion: ");	
		leeCad(tranLeida,100);
		strcpy(auxTranLeida,tranLeida);
		elemTran1=antesComa(auxTranLeida);  
		if(pertenece_arbol(Q,elemTran1)==1 && repe_transiciones_arbol(T, elemTran1)<=cant_estados_arbol(E)){
			strcpy(auxTranLeida,tranLeida);
			elemTran2=entreComa(auxTranLeida); 
			if(pertenece_arbol(E,elemTran2)==1){
				strcpy(auxTranLeida,tranLeida);
				acep=despuesComa_arbol(auxTranLeida);
				agrega_elemento_arbol(&nuevo, elemTran1);
				agrega_elemento_arbol(&nuevo, elemTran2);
				agrega_repetidos_arbol(&nuevo, acep);
				if(contiene_arbol(acep, Q) && pertenece_arboles(T,nuevo)==0){
					printf("Desea ingresar otra transicion? SI(1) - NO(0): ");
					scanf("%d",&res);
					fflush(stdin);
					if(res==1){
						agrega_repetidos_arbol(&aux->dato_arbol, nuevo);
						aux->sig=crea_nodo_arbol();
						T_recorre=T_recorre->sig;
						nuevo=arbol_vacio();
						aux=aux->sig;
					}
					else{
						agrega_repetidos_arbol(&aux->dato_arbol, nuevo);
						aux->sig=arbol_vacio();
					}
				}
				else
				   printf("ESTADO DE LLEGADA NO VALIDO.");
				
			}
			else
			   printf("ELEMENTO DE ALFABETO NO VALIDO.");
		}
		else
																										printf("\nESTADO DE PARTIDA NO VALIDO.");
	} while(res!=0);
}

//INCIALIZA

void crea_hijos(Tarbol *arbol){
	(*arbol)->dato_arbol=crea_nodo_arbol();
	(*arbol)->sig=crea_nodo_arbol();
}

void crea_hijos_parametro(Tarbol *raiz, T_ele dato){
	(*raiz)->dato_arbol=(Tarbol)crea_nodo_string_parametro(dato);
	(*raiz)->sig=NULL;
}

//RETORNA

Tarbol retorna_Q(Tarbol raiz){
	raiz=raiz->dato_arbol;
	return raiz;
}

Tarbol retorna_alfabeto(Tarbol raiz){
	raiz=raiz->sig;
	return raiz->dato_arbol;
}

T_ele retorna_dato_cadena(Tstring nodo){ 
	return nodo->dato_cadena;
}

//OTROS

int pertenece_arbol(Tarbol a, T_ele e){ //si lo encontro retorna 1
	if(a!=NULL){
		if(a->dato_arbol!=NULL){
			if(a!=NULL && compara_ele(retorna_dato_cadena((Tstring)a->dato_arbol), e)!=0){
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

void agrega_repetidos_arbol(Tarbol *a, Tarbol b){
	Tarbol aux;
	aux=arbol_vacio();
	while(b!=NULL){
		if(*a==NULL){
			*a=crea_nodo_arbol();
			crea_hijos_parametro(a, retorna_dato_cadena((Tstring)b->dato_arbol));
		}
		else{
			aux=*a;
			while(aux->sig!=NULL){
				aux=aux->sig;
			}
			aux->sig=crea_nodo_arbol();
			crea_hijos_parametro(&aux->sig, retorna_dato_cadena((Tstring)b->dato_arbol));
		}
		b=b->sig;
	}
}

Tarbol despuesComa_arbol(Tcadena n){
	Tarbol nuevo=arbol_vacio();
	T_ele aux;
	char * auxc="";
	auxc=strtok(n,",");
	auxc=strtok(NULL,",");
	auxc=strtok(NULL,",{}");
	while(auxc!=NULL){
		aux=carga_ele_parametro(auxc);
		agrega_elemento_arbol(&nuevo,aux);
		auxc=strtok(NULL,",{}");
	}
	return nuevo;
}

int repe_transiciones_arbol(Tarbol T, T_ele elem){//calcula que la cantidad de transiciones desde un mismo estado de partida no sea mayor a la del alfabeto
	int c=0;
	T_ele aux_elem;
	Tarbol aux_T;
	aux_T=T;
	if(aux_T->dato_arbol!=NULL){
		while(aux_T->dato_arbol!=NULL){
			aux_T=aux_T->dato_arbol;
			aux_elem=retorna_dato_cadena((Tstring)aux_T->dato_arbol);
			if(compara_ele(aux_elem,elem)==0)//VER SI SE BURLA EL ENCAPSULAMIENTO
				c++;
			aux_T=T->sig;
			T=T->sig;
		}
	}
	return c;
}

int contiene_arbol(Tarbol a, Tarbol b){
	if(a!=NULL){
		if(b!=NULL){
			int ban=0;
			while(a!=NULL && ban==0){
				if(pertenece_arbol(b, retorna_dato_cadena((Tstring)a->dato_arbol))==0)
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

int pertenece_arboles(Tarbol T, Tarbol bus){
	Tarbol aux_T, aux_bus;
	aux_T=T;
	int b=0;
	aux_bus=bus;
	if(aux_T!=NULL){
		while(aux_T!=NULL && aux_bus!=NULL){
			aux_T=aux_T->dato_arbol;
			while(aux_T!=NULL && aux_bus!=NULL && b==0){
				if(compara_ele(retorna_dato_cadena((Tstring)aux_T->dato_arbol), retorna_dato_cadena((Tstring)aux_bus->dato_arbol))==0){
					aux_T=aux_T->sig;
					aux_bus=aux_bus->sig;
				}
				else
				   b=1;
			}
			if(aux_T!=NULL || aux_bus!=NULL){
				return pertenece_arboles(T->sig, bus);
			}
			else
			   return 1;
		}
		if(aux_T==NULL && aux_bus==NULL)
			  return 1;
		else
			return 0;
	}
	else
	   return 0;
}

int cant_estados_arbol(Tarbol raiz){  //retorna la cantidad de nodos del arbol
	int c=0;
	while(raiz!=NULL){
		c++;
		raiz=raiz->sig;
	}
	return c;
}
