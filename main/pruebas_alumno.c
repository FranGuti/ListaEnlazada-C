#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void prueba_lista_vacia(){
    printf("--------------PRUEBAS LISTA VACIA-------------\n");
    lista_t* lista = lista_crear();
    print_test("La lista se creó correctamente", lista!= NULL);

    print_test("La lista esta vacía", lista_esta_vacia(lista));
    print_test("El largo de la lista es 0", lista_largo(lista) == 0);
    print_test("Ver el primero de una lista vacía devuelve NULL", lista_ver_primero(lista) == NULL);
    print_test("Ver el ultimo de una lsita vacía devuelve NULL", lista_ver_ultimo(lista) == NULL);
    print_test("Eliminar el primer elemento de una lista vacia devuelve NULL", lista_borrar_primero(lista) == NULL);
    
    lista_destruir(lista, NULL);
    print_test("La lista se destruyó correctamente", true);
}

void pruebas_unitarias(){
    int uno = 1;
    printf("\n---------------PRUEBAS UNITARIAS--------------\n");
    lista_t* lista = lista_crear();
    print_test("La lista se creó correctamente", lista != NULL);
    
    print_test("Inserto uno al principio",lista_insertar_primero(lista, &uno));
    print_test("La lista no esta vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 1", lista_largo(lista) == 1);
    print_test("Ver primero es igual a uno", lista_ver_primero(lista) == &uno);
    print_test("Ver el último es igual a uno", lista_ver_ultimo(lista) == &uno);
    print_test("Eliminar primero es igual a uno", lista_borrar_primero(lista) == &uno);

    print_test("Inserto uno al final",lista_insertar_ultimo(lista, &uno));
    print_test("La lista no esta vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 1", lista_largo(lista) == 1);
    print_test("Ver primero es igual a uno", lista_ver_primero(lista) == &uno);
    print_test("Ver el último es igual a uno", lista_ver_ultimo(lista) == &uno);
    print_test("Eliminar primero es igual a uno", lista_borrar_primero(lista) == &uno);

    lista_destruir(lista, NULL);
    print_test("La lista de destruyó correctamente", true);
}

void pruebas_varios_elementos(){
    int uno = 1;
    int dos = 2;
    int tres = 3;
    int cuatro = 4;
    printf("\n----------PRUEBAS VARIOS ELEMENTOS----------\n");

    lista_t* lista = lista_crear();
    print_test("La lista se creo", lista != NULL);

    printf("\nINSERTANDO EN ORDEN DECRECIENTE\n\n");
    print_test("Inserto uno al principio", lista_insertar_primero(lista, &uno));

    print_test("Inserto dos al principio", lista_insertar_primero(lista, &dos));
    print_test("La lista no está vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 2", lista_largo(lista) == 2);
    print_test("El primer elemento es igual a dos", lista_ver_primero(lista) == &dos);
    print_test("El ultimo elemento es igual a uno", lista_ver_ultimo(lista) == &uno);

    print_test("Inserto tres al principio", lista_insertar_primero(lista, &tres));
    print_test("La lista no esta vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 3", lista_largo(lista) == 3);
    print_test("El primer elemento es igual a tres", lista_ver_primero(lista) == &tres);
    print_test("El ultimo elemento es igual a uno", lista_ver_ultimo(lista) == &uno);

    print_test("Inserto cuatro al principio", lista_insertar_primero(lista, &cuatro));
    print_test("La lista no está vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 4", lista_largo(lista) == 4);
    print_test("El primer elemento es igual a cuatro", lista_ver_primero(lista) == &cuatro);
    print_test("El ultimo elemento es igual a uno", lista_ver_ultimo(lista) == &uno);

    print_test("Borrar primero es cuatro", lista_borrar_primero(lista) == &cuatro);
    print_test("Borrar primero es tres", lista_borrar_primero(lista) == &tres);
    print_test("Borrar primero es dos", lista_borrar_primero(lista) == &dos);
    print_test("Borrar primero es uno", lista_borrar_primero(lista) == &uno);
    print_test("La lista está vacía", lista_esta_vacia(lista));

    
    
    printf("\nINSERTANDO EN ORDEN CRECIENTE\n\n");
    print_test("Inserto uno al final", lista_insertar_ultimo(lista, &uno));

    print_test("Inserto dos al final", lista_insertar_ultimo(lista, &dos));
    print_test("La lista no está vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 2", lista_largo(lista) == 2);
    print_test("El primer elemento es igual a uno", lista_ver_primero(lista) == &uno);
    print_test("El ultimo elemento es igual a dos", lista_ver_ultimo(lista) == &dos);

    print_test("Inserto tres al final", lista_insertar_ultimo(lista, &tres));
    print_test("La lista no esta vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 3", lista_largo(lista) == 3);
    print_test("El primer elemento es igual a uno", lista_ver_primero(lista) == &uno);
    print_test("El ultimo elemento es igual a tres", lista_ver_ultimo(lista) == &tres);

    print_test("Inserto cuatro al final", lista_insertar_ultimo(lista, &cuatro));
    print_test("La lista no está vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 4", lista_largo(lista) == 4);
    print_test("El primer elemento es igual a uno", lista_ver_primero(lista) == &uno);
    print_test("El ultimo elemento es igual a cuatro", lista_ver_ultimo(lista) == &cuatro);

    print_test("Borrar primero es uno", lista_borrar_primero(lista) == &uno);
    print_test("Borrar primero es dos", lista_borrar_primero(lista) == &dos);
    print_test("Borrar primero es tres", lista_borrar_primero(lista) == &tres);
    print_test("Borrar primero es cuatro", lista_borrar_primero(lista) == &cuatro);
    print_test("La lista está vacía", lista_esta_vacia(lista));

    
    printf("\nINSERTANDO DESORDENADAMENTE\n\n");
    print_test("Inserto uno al principio", lista_insertar_primero(lista, &uno));

    print_test("Inserto dos al principio", lista_insertar_primero(lista, &dos));
    print_test("La lista no está vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 2", lista_largo(lista) == 2);
    print_test("El primer elemento es igual a dos", lista_ver_primero(lista) == &dos);
    print_test("El ultimo elemento es igual a uno", lista_ver_ultimo(lista) == &uno);

    print_test("Inserto tres al final", lista_insertar_ultimo(lista, &tres));
    print_test("La lista no esta vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 3", lista_largo(lista) == 3);
    print_test("El primer elemento es igual a dos", lista_ver_primero(lista) == &dos);
    print_test("El ultimo elemento es igual a tres", lista_ver_ultimo(lista) == &tres);

    print_test("Inserto cuatro al final", lista_insertar_ultimo(lista, &cuatro));
    print_test("La lista no está vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 4", lista_largo(lista) == 4);
    print_test("El primer elemento es igual a dos", lista_ver_primero(lista) == &dos);
    print_test("El ultimo elemento es igual a cuatro", lista_ver_ultimo(lista) == &cuatro);

    print_test("Borrar primero es dos", lista_borrar_primero(lista) == &dos);
    print_test("Borrar primero es uno", lista_borrar_primero(lista) == &uno);
    print_test("Borrar primero es tres", lista_borrar_primero(lista) == &tres);
    print_test("Borrar primero es cuatro", lista_borrar_primero(lista) == &cuatro);
    print_test("La lista está vacía", lista_esta_vacia(lista));

    lista_destruir(lista, NULL);
    print_test("La lista se destruyó correctamente", true);
}

void pruebas_null(){
    printf("\n\n----------------PRUEBAS CON NULL--------------\n");

    lista_t* lista = lista_crear();
    print_test("La lista se creó correctamente", lista != NULL);

    print_test("Inserto NULL al principio de la lista", lista_insertar_primero(lista, NULL));
    print_test("La lista no está vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 1", lista_largo(lista) == 1);
    print_test("Ver primero es NULL", lista_ver_primero(lista) == NULL);
    print_test("Ver último es NULL", lista_ver_ultimo(lista) == NULL);

    print_test("Se puede insertar NULL al final", lista_insertar_ultimo(lista, NULL));
    print_test("La lista no está vacía", !lista_esta_vacia(lista));
    print_test("El largo de la lista es 2", lista_largo(lista) == 2);
    print_test("Ver primero es NULL", lista_ver_primero(lista) == NULL);
    print_test("Ver último es NULL", lista_ver_ultimo(lista) == NULL);

    print_test("Borrar el primer elemento es NULL", lista_borrar_primero(lista) == NULL);
    print_test("Borrar el primer elemento es NULL", lista_borrar_primero(lista) == NULL);
    print_test("La lista está vacía", lista_esta_vacia(lista));

    lista_destruir(lista, NULL);
    print_test("La lista se destruyó correctamente", true);
}

bool pruebas_de_volumen_insertando_al_inicio(size_t tam){

    lista_t* lista = lista_crear();
    if (!lista){
        return false;
    }

    size_t* vector = malloc(sizeof(void*) * tam);

    if (vector == NULL){
        lista_destruir(lista, NULL);
        return false;
    }

    bool estado = true;

    for (size_t i = 0; i < tam; i++){
        vector[i] = i;
        if(!lista_insertar_primero(lista, &vector[i])){
            estado = false;
        }
    }

    for(size_t i = 0; i < tam; i++){
        if(lista_ver_primero(lista) != &vector[tam - i - 1] || lista_borrar_primero(lista) != &vector[tam - i - 1]){
            estado = false;
        }
    }

    if(lista_ver_primero(lista) != NULL || lista_borrar_primero(lista) != NULL){
        estado = false;
    }

    lista_destruir(lista, (*free));
    free(vector);
    return estado;
}

bool pruebas_de_volumen_insertando_al_final(size_t tam){

    lista_t* lista = lista_crear();
    if (!lista){
        return false;
    }

    size_t* vector = malloc(sizeof(void*) * tam);

    if (vector == NULL){
        lista_destruir(lista, NULL);
        return false;
    }

    bool estado = true;

    for (size_t i = 0; i < tam; i++){
        vector[i] = i;
        if(!lista_insertar_ultimo(lista, &vector[i])){
            estado = false;
        }
    }

    for(size_t i = 0; i < tam; i++){
        if(lista_borrar_primero(lista) != &vector[i]){
            estado = false;
        }
    }

    if (lista_ver_primero(lista) != NULL || lista_borrar_primero(lista) != NULL){
        estado = false;
    }

    lista_destruir(lista, (*free));
    free(vector);
    return estado;
}

 /* ****************************** PRUEBAS ITERADORES *********************** */
 /* ************************************ EXTERNO **************************** */

 void pruebas_iterador_externo_lista_vacia(){
    printf("-----------------PRUEBAS ITER LISTA VACÍA---------------\n");

    lista_t* lista = lista_crear();
    print_test("La lista se creó correctamente", lista != NULL);

    lista_iter_t* iter = lista_iter_crear(lista);
    print_test("El iterador de la lista se creó correctamente", iter != NULL);
    print_test("No se puede avanzar el iterador", !lista_iter_avanzar(iter));
    print_test("El iterador no está 'parado' sobre ningun elemento", lista_iter_ver_actual(iter) == NULL);
    print_test("El iterador está al final de la lista", lista_iter_al_final(iter));
    print_test("No se puede borrar el elemento actual del iterador sobre una lista vacía", lista_iter_borrar(iter) == false);
    
    lista_iter_destruir(iter);
    print_test("El iter se destruyó correctamente", true);

    lista_destruir(lista, NULL);
    print_test("La lista se destruyo correctamente", true);
}

void pruebas_unitarias_lista_iterador_externo(){
    printf("\n\n----------PRUEBAS UNITARIAS DEL ITERADOR EXTERNO-----------\n");
    char choco[] = {'C', 'H', 'O', 'C', 'O', 'L', 'A', 'T', 'E'};
    char choclo[] = {'C', 'H', 'O', 'C', 'L', 'O'};

    lista_t* lista = lista_crear();
    print_test("La lista se creó correctamente", lista != NULL);
    print_test("Se inserta 'CHOCOLATE' en la lista", lista_insertar_primero(lista, choco));

    lista_iter_t* iter = lista_iter_crear(lista);
    print_test("El iterador está sobre 'CHOCOLATE", lista_iter_ver_actual(iter) == choco);
    print_test("El iterador no está al final de la lista", !lista_iter_al_final(iter));
    print_test("El largo de la lista es 1", lista_largo(lista) == 1);
    print_test("Se inserta 'CHOCLO' con el iterador", lista_iter_insertar(iter, choclo));
    print_test("Ahora el primer elemento es 'CHOCLO'", lista_ver_primero(lista) == choclo);
    print_test("Ahora el ultimo elemento es 'CHOCOLATE'", lista_ver_ultimo(lista) == choco);
    print_test("El largo de la lista es dos", lista_largo(lista) == 2);
    print_test("El iterador está sobre 'CHOCLO'", lista_iter_ver_actual(iter) == choclo);
    print_test("Borro el elemento actual del iterador", lista_iter_borrar(iter) == choclo);
    print_test("El largo de la lista es uno", lista_largo(lista) == 1);
    print_test("El primer elemento de la lista es 'CHOCOLATE'", lista_ver_primero(lista) == choco);
    print_test("El último elemento también es 'CHOCOLATE'", lista_ver_ultimo(lista) == choco);
    print_test("El iter está sobre 'CHOCOLATE'", lista_iter_ver_actual(iter) == choco);
    print_test("Borro el elemento actual de iterador", lista_iter_borrar(iter) == choco);
    print_test("La lista está vacía", lista_esta_vacia(lista));
    print_test("El iterador está fuera de la lista", lista_iter_ver_actual(iter) == NULL);
    print_test("No se puede ver el actual", lista_iter_ver_actual(iter) == NULL);
    print_test("Borrar el actual es NULL", lista_iter_borrar(iter) == NULL);
    lista_iter_destruir(iter);
    print_test("El iter se destruyo correctamente", true);

    lista_destruir(lista, NULL);
    print_test("La lista se destruyó correctamente", true);
}

void pruebas_iterador_externo_lista_varios(){
    printf("\n\n-----------------PRUEBAS VARIOS ELEMENTOS--------------------\n");
    
    char papa[] = {'P', 'A', 'P', 'A'};
    char pan[] = {'P', 'A', 'N'};
    char agua[] = {'A', 'G', 'U', 'A'};
    char leche[] = {'L', 'E', 'C', 'H', 'E'};

    lista_t* lista = lista_crear();
    print_test("La lista se creó correctamente", lista != NULL);

    lista_iter_t* iter = lista_iter_crear(lista);
    print_test("El iterador se creo correctamente", iter != NULL);

    print_test("Agrego leche a la lista", lista_iter_insertar(iter, leche));
    print_test("Avanzo el iterador", lista_iter_avanzar(iter));
    print_test("El iterador esta al final de la lista", lista_iter_al_final(iter));
    print_test("El primer elemento es leche", lista_ver_primero(lista) == leche);
    print_test("El último elemento es leche", lista_ver_ultimo(lista) == leche);
    print_test("El largo de la lista es 1", lista_largo(lista) == 1);
    print_test("Agrego pan a la lista", lista_iter_insertar(iter, pan));
    print_test("Avanzo el iterador", lista_iter_avanzar(iter));
    print_test("El primer elemento es leche", lista_ver_primero(lista) == leche);
    print_test("El último elemento es pan", lista_ver_ultimo(lista) == pan);
    print_test("El largo de la lista es 2", lista_largo(lista) == 2);
    print_test("Agrego agua", lista_iter_insertar(iter, agua));
    print_test("Avanzo el iterador", lista_iter_avanzar(iter));
    print_test("El primer elemento es leche", lista_ver_primero(lista) == leche);
    print_test("El último elemento es agua", lista_ver_ultimo(lista) == agua);
    print_test("El largo de la lista es 3", lista_largo(lista) == 3);
    print_test("Agrego papa a lista", lista_iter_insertar(iter, papa));
    print_test("El primer elemento es leche", lista_ver_primero(lista) == leche);
    print_test("El último elemento es papa", lista_ver_ultimo(lista) == papa);
    print_test("El largo de la lista es 4", lista_largo(lista) == 4);
    print_test("Avanzo el iterador", lista_iter_avanzar(iter));
    print_test("El iterador está al final", lista_iter_al_final(iter));
    print_test("El iterador no se puede avanzar mas", !lista_iter_avanzar(iter));

    lista_iter_destruir(iter);
    print_test("El iterador se destruyo correctamente", true);
    lista_destruir(lista, NULL);
    print_test("La lista se destruyo correctamente", true);

}


bool prueba_volumen_iterador_externo(size_t tam){
    lista_t* lista = lista_crear();
    if(lista == NULL){
        return false;
    }

    size_t* vector = malloc(sizeof(size_t) * tam);
    if (vector == NULL){
        lista_destruir(lista, (*free));
        return false;
    }

    lista_iter_t* iter = lista_iter_crear(lista);
    if(iter == NULL){
        lista_destruir(lista, (*free));
        free(vector);
        return false;
    }

    bool estado = true;
    for(size_t i = 0; i < tam; i++){
        vector[i] = i;
        if((!lista_iter_insertar(iter, &vector[i])) || !lista_iter_avanzar(iter)){
            estado = false;
        }
    }

    lista_iter_destruir(iter);
    print_test("El iterador fue destruido correctamente", true);

    lista_iter_t* iterador = lista_iter_crear(lista);

    if(iterador == NULL){
        lista_destruir(lista, (*free));
        free(vector);
        return false;
    }

    for (size_t i = 0; i < tam; i++){
        if((lista_ver_primero(lista) != lista_iter_ver_actual(iterador)) || (lista_iter_borrar(iterador) != &vector[i])){
            estado = false;
        }
    }
    if((!lista_iter_al_final(iterador)) || (!lista_esta_vacia(lista))){
        estado = false;
    }
    lista_iter_destruir(iterador);
    lista_destruir(lista, (*free));
    free(vector);
    return estado;
}

/* **************************** ITERADOR INTERNO ************************************ */


bool elevar_cuadrado(void* dato, void* res){
    *(int*) res = *(int*) res + ((*(int*) dato) * (*(int*) dato));
    return true;
}

bool pruebas_interno_potencia(){
    lista_t* lista = lista_crear();
    if(lista == NULL){
        return false;
    }
    int uno = 1;
    int dos = 2;
    int tres = 3;

    lista_insertar_ultimo(lista, &uno);
    lista_insertar_ultimo(lista, &uno);
    lista_insertar_ultimo(lista, &tres);
    lista_insertar_ultimo(lista, &dos);
    lista_insertar_ultimo(lista, &dos);

    int res = 0;

    lista_iterar(lista, (*elevar_cuadrado), &res);
    lista_destruir(lista, NULL);
    return res == 19;
}

void pruebas_lista_alumno(void){
    printf("\n-------------------------------PRUEBAS LISTA-----------------------------\n");

    prueba_lista_vacia();
    pruebas_unitarias();
    pruebas_varios_elementos();
    pruebas_null();


    
    print_test("\n\nPRUEBAS DE VOLUMEN INSERTANDO AL INICIO", pruebas_de_volumen_insertando_al_inicio(100000));
    


    print_test("\nPRUEBAS DE VOLUMEN INSERTANDO AL FINAL", pruebas_de_volumen_insertando_al_final(100000));


    
    printf("\n\n---------------PRUEBAS ITERADORES-------------\n\n");
    
    printf("--------------------EXTERNO-------------------\n");
    pruebas_iterador_externo_lista_vacia();
    pruebas_unitarias_lista_iterador_externo();
    pruebas_iterador_externo_lista_varios();
    print_test("PRUEBAS DE VOLUMEN DEL ITERADOR EXTERNO", prueba_volumen_iterador_externo(100000));


    
    printf("\n\n--------------------------INTERNO---------------------\n");
    print_test("Crea una lista y eleva al cuadrado todos los elementos", pruebas_interno_potencia());
}
