#include "interfazlista.h"
//FUNCIONES AUXILIARES
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
		if(compara_ele(aux->dato,e)!=0)
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
		return 1;
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
};
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




//
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
Conj_PC crea_nodoPC(Tpar p){
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
		   *p=crea_nodoPC(crearUnPar(a->dato,b->dato));
		else{
			   
			   auxp=*p;
			   encUltimoPC(&auxp);
			   
			   auxp->sig=crea_nodoPC(crearUnPar(a->dato,b->dato));
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

int buscaPC(Conj_PC a, Tpar e){//BUSCA UN Tpar EN UN CONJUNTO 1 LO ENCONTRO 0 NO
	if(a!=NULL){
		if(a!=NULL && parIguales(a->dato,e)!=0){
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
			mostrarPar(a->dato);printf(" , ");
			a=a->sig;
			mostrarPCRec(a);
		}
		else{
		mostrarPar(a->dato);
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

