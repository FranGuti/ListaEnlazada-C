#include "lista.h"
#include <stdlib.h>
#include <stdbool.h>

/* ******************************************************************
 * Alumno: Francisco Gutierrez                                      *
 * Padrón: 103543                                                   *
 * Corrector: Rodrigo Souto                                         *
 * *****************************************************************/

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS                  *
 * *****************************************************************/

typedef struct nodo{
	struct nodo* prox;
	void* dato;
}nodo_t;


struct lista{
	nodo_t* prim;
	nodo_t* ult;
	size_t cant;
};

/* ******************************************************************
 *                      PRIMITIVAS DEL NODO                         *
 * *****************************************************************/

nodo_t* nodo_crear(void* dato, nodo_t* prox){
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if (!nodo){
		return NULL;
	}
	nodo->dato = dato;
	nodo->prox = prox;
	return nodo;
}

void nodo_destruir(nodo_t* nodo, void (destruir_dato) (void*)){
	if(destruir_dato){
		destruir_dato(nodo->dato);
	}
	free(nodo);
}

/* ******************************************************************
 *                    PRIMITIVAS DE LA LISTA                        *
 * *****************************************************************/

// Crea una lista vacia
// Post: devuelve una lista vacia. 
lista_t *lista_crear(void){
	lista_t* lista = malloc(sizeof(lista_t));
	if(!lista){
		return NULL;
	}
	lista->prim = NULL;
	lista->ult = NULL;
	lista->cant = 0;
	return lista;
}

// Devuelve verdadero en caso de que la lista esté vacía
// y falso en caso contrario
// Pre: la lista fue creada 
bool lista_esta_vacia(const lista_t *lista){
	return lista->cant == 0;
}

// Inserta un elemento en la primera posición de la lista. Devuelve false en caso de error
// Pre: La lista fue creada
// Post: dato se encuentra en la primera posición de la lista.
bool lista_insertar_primero(lista_t *lista, void *dato){
	nodo_t* nodo = nodo_crear(dato, lista->prim);
	if(!nodo){
		return false;
	}
	if(lista_esta_vacia(lista)){
		lista->ult = nodo;
	}
	lista->prim = nodo;
	lista->cant++;
	return true;
}

// Inserta dato en la ultima posición de la lista. Devuelve false en caso de error
// Pre: La lista fue creada
// Post: dato se encuentra en la última posición de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato){
	nodo_t* nodo = nodo_crear(dato, NULL);
	if(!nodo){
		return false;
	}
	if(lista_esta_vacia(lista)){
		lista->prim = nodo;
	}
	else{
		lista->ult->prox = nodo;
	}
	lista->ult = nodo;
	lista->cant++;
	return true;
}

// Borra el primer elemento de la lista y lo devuelve. En caso de estar vacía devuelve NULL
// Pre: La lista fue creada
// Post: El primer elemento se eliminó de la lista.
void *lista_borrar_primero(lista_t *lista){
	if(lista_esta_vacia(lista)){
		return NULL;
	}
	if(lista->cant == 1){
		lista->ult = NULL;
	}
	nodo_t* nodo = lista->prim;
	void* dato = nodo->dato;
	lista->prim = nodo->prox;
	nodo_destruir(nodo, NULL);
	lista->cant--;
	return dato;
}

// Devuelve el primer elemento de la lista. En caso de estar vacía devuelve NULL
// Pre: La lista fue creada
void *lista_ver_primero(const lista_t *lista){
	if(lista_esta_vacia(lista)){
		return NULL;
	}
	return lista->prim->dato;
}

// Devuelve el último elemento de la lista. En caso de estar vacía devuelve NULL
// Pre: La lista fue creada
void *lista_ver_ultimo(const lista_t* lista){
	if(lista_esta_vacia(lista)){
		return NULL;
	}
	return lista->ult->dato;
}

// Devuelve el largo de la lista
// Pre: La lista fue creada
size_t lista_largo(const lista_t *lista){
	return lista->cant;
}

// Destruye la lista aplicando la función destruir_dato a los elementos de la misma.
// En caso de recibir NULL, no se aplica.
// Pre: La lista fue creada
// Post: Se liberó la lista
void lista_destruir(lista_t *lista, void destruir_dato(void *)){
	nodo_t* act = lista->prim;
	while(act){
		nodo_t* sig = act->prox;
		nodo_destruir(act, *(destruir_dato));
		act = sig;
	}
	free(lista);
}

/* ******************************************************************
 *                    PRIMITIVA DEL ITERADOR INTERNO                *
 * *****************************************************************/

void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra){
    nodo_t* act = lista->prim;
    while(act){
    	void* dato = act->dato;
        if (!visitar(dato, extra)){
            return;
        }
        act = act->prox;
    }
}

/* ******************************************************************
 *                DEFINICION DEL TIPO DE DATO ITER                  *
 * *****************************************************************/

struct lista_iter{
	lista_t* lista;
	nodo_t* act;
	nodo_t* ant;
};

/* ******************************************************************
 *                 PRIMITIVAS DEL ITERADOR EXTERNO                  *
 * *****************************************************************/

// Crea el iterador externo, en caso de error devuelve NULL
// Pre: La lista fue creada
lista_iter_t *lista_iter_crear(lista_t *lista){
	lista_iter_t* iter = malloc(sizeof(lista_iter_t));
	if(!iter){
		return NULL;
	}
	iter->lista = lista;
	iter->act = lista->prim;
	iter->ant = NULL;
	return iter;
}

// En caso de que el iterador pueda avanzar sobre la lista devuelve true
// False en caso contrario
// Pre: El iterador fue creado
// Post: Avanza a la siguiente posición el iterador
bool lista_iter_avanzar(lista_iter_t *iter){
	if(iter->act == NULL){
		return false;
	}
	iter->ant = iter->act;
	iter->act = iter->act->prox;
	return true;
}

// Devuelve el elemento sobre el cual está "parado" el iterador
// Pre: El iterador fue creado
void *lista_iter_ver_actual(const lista_iter_t *iter){
	if(iter->act == NULL){
		return NULL;
	}
	return iter->act->dato;
}

// Devuelve true si el iterador está en la última posición de la lista
// False en caso contrario
// Pre: El iterador fue creado 
bool lista_iter_al_final(const lista_iter_t *iter){
	return iter->act == NULL;
}

// Destruye el iterador
// Pre: El iter fue creado
// Post: Se liberó iter
void lista_iter_destruir(lista_iter_t *iter){
	free(iter);
}

// Inserta dato en la posición de la lista sobre la cual se encuentra iter
// Pre: El iterador fue creado
// Post: dato se agregó a la lista
bool lista_iter_insertar(lista_iter_t *iter, void *dato){
	nodo_t* nodo = nodo_crear(dato, iter->act);
	if(!nodo){
		return false;
	}
	if(iter->ant == NULL){
		iter->lista->prim = nodo; 
	}
	else{
		iter->ant->prox = nodo;
	}
	if(iter->ant == iter->lista->ult){
		iter->lista->ult = nodo;
	}
	iter->act = nodo;
	iter->lista->cant++;
	return true;
}

// Borra el elemento de la lista sobre el cual está "parado" iter
// Pre: El iterador fue creado
// Post: se borró el elemento de la lista
void *lista_iter_borrar(lista_iter_t *iter){
	if(iter->act == NULL){
		return NULL;
	}
	nodo_t* nodo = iter->act;
	void* dato = nodo->dato;
	if(iter->lista->prim == nodo){
		iter->lista->prim = nodo->prox;
	}
	else{
		iter->ant->prox = nodo->prox;
	}
	if(iter->lista->ult == nodo){
		iter->lista->ult = iter->ant;
	}
	iter->act = nodo->prox;
	iter->lista->cant--;
	nodo_destruir(nodo, NULL);
	return dato;
}

