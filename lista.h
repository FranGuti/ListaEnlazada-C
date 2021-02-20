#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdbool.h>

/* ******************************************************************
 *                DEFINICION DE LOS TIPOS DE DATOS                  *
 * *****************************************************************/

typedef struct lista lista_t;


/* ******************************************************************
 *                    PRIMITIVAS DE LA LISTA                        *
 * *****************************************************************/

// Crea una lista vacia
// Post: devuelve una lista vacia. 
lista_t *lista_crear(void);

// Devuelve verdadero en caso de que la lista esté vacía
// y falso en caso contrario
// Pre: la lista fue creada 
bool lista_esta_vacia(const lista_t *lista);

// Inserta un elemento en la primera posición de la lista. Devuelve false en caso de error
// Pre: La lista fue creada
// Post: dato se encuentra en la primera posición de la lista.
bool lista_insertar_primero(lista_t *lista, void *dato);

// Inserta dato en la ultima posición de la lista. Devuelve false en caso de error
// Pre: La lista fue creada
// Post: dato se encuentra en la última posición de la lista.
bool lista_insertar_ultimo(lista_t *lista, void *dato);

// Borra el primer elemento de la lista y lo devuelve. En caso de estar vacía devuelve NULL
// Pre: La lista fue creada
// Post: El primer elemento se eliminó de la lista.
void *lista_borrar_primero(lista_t *lista);

// Devuelve el primer elemento de la lista. En caso de estar vacía devuelve NULL
// Pre: La lista fue creada
void *lista_ver_primero(const lista_t *lista);

// Devuelve el último elemento de la lista. En caso de estar vacía devuelve NULL
// Pre: La lista fue creada
void *lista_ver_ultimo(const lista_t* lista);

// Devuelve el largo de la lista
// Pre: La lista fue creada
size_t lista_largo(const lista_t *lista);

// Destruye la lista aplicando la función destruir_dato a los elementos de la misma.
// En caso de recibir NULL, no se aplica.
// Pre: La lista fue creada
// Post: Se liberó la lista
void lista_destruir(lista_t *lista, void destruir_dato(void *));

/* ******************************************************************
 *                    PRIMITIVA DEL ITERADOR INTERNO                *
 * *****************************************************************/

// 
void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);

/* ******************************************************************
 *                DEFINICION DEL TIPO DE DATO ITER                  *
 * *****************************************************************/

typedef struct lista_iter lista_iter_t;

/* ******************************************************************
 *                 PRIMITIVAS DEL ITERADOR EXTERNO                  *
 * *****************************************************************/

// Crea el iterador externo
// Pre: La lista fue creada
lista_iter_t *lista_iter_crear(lista_t *lista);

// En caso de que el iterador pueda avanzar sobre la lista devuelve true
// False en caso contrario
// Pre: El iterador fue creado
// Post: Avanza a la siguiente posición el iterador
bool lista_iter_avanzar(lista_iter_t *iter);

// Devuelve el elemento sobre el cual está "parado" el iterador
// Pre: El iterador fue creado
void *lista_iter_ver_actual(const lista_iter_t *iter);

// Devuelve true si el iterador está en la última posición de la lista
// False en caso contrario
// Pre: El iterador fue creado 
bool lista_iter_al_final(const lista_iter_t *iter);

// Destruye el iterador
// Pre: El iter fue creado
// Post: Se liberó iter
void lista_iter_destruir(lista_iter_t *iter);

// Inserta dato en la posición de la lista sobre la cual se encuentra iter
// Pre: El iterador fue creado
// Post: dato se agregó a la lista
bool lista_iter_insertar(lista_iter_t *iter, void *dato);

// Borra el elemento de la lista sobre el cual está "parado" iter
// Pre: El iterador fue creado
// Post: se borró el elemento de la lista
void *lista_iter_borrar(lista_iter_t *iter);


// FUNCIÓN DE PRUEBAS
void pruebas_lista_alumno(void);

#endif // LISTA_H