# TDA Lista Simplemente Enlazada
Es un trabajo realizado durante la cursada de Algoritmos y Programación II.
El mismo consta de la implementación y desarrollo del Tipo de Dato Abstracto Lista Simplemente Enlazada en el lenguaje de programación C. 
Tiene como objetivo la creación del mismo para posterior uso como librería con un correcto manejo de memoria, la implementación de un iterador propio que sea capaz de recorrer la lista, y sus métodos :

 - Lista Crear
     > Crea y devuelve una Lista vacía

 - Lista Esta Vacia
    >Devuelve un booleano el cual es True si la Lista está vacía, False en caso contrario
    
 - Lista Insertar Primero
    >Inserta el elemento recibido por parámetro en el primer lugar de la Lista
    
 - Lista Insertar Ultimo
   > Inserta el elemento recibido por parámetro en el primer lugar de la Lista
 
 - Lista Borrar Primero
   > Elimina el elemento en la primer posición de la Lista y lo devuelve

 - Lista Ver Primero
   > Devuelve el elemento que se encuentra en la primer posición de la Lista

- Lista Ver Ultimo
  >Devuelve el elemento en la última posición de la Lista
  
- Lista Largo
   >Devuelve la cantidad de elementos en la Lista
   
- Lista Destruir
  > Elimina los elementos de la Lista y destruye la misma

Una Lista Simplemente Enlazada es aquella que, bajo un sistema de Nodos simplemente enlazados (valga la redundancia), logra implementar la funcionalidad de una lista.

El Nodo es un "contenedor" que no solo conoce al elemento que porta sino que también cuenta con la capacidad de enlazarse junto con otros, de esta forma podemos crear cadenas de información de forma fácil. Este enlace puede ser simple, es decir cada nodo conoce un solo nodo diferente o puede ser doble, triple, etc. En este caso utilizamos el nodo de enlace simple.

La funcionalidad es sencilla, la Lista conoce en sus atributos al primer y último nodo. El primer nodo conoce al segundo, el segundo al tercero y así sucesivamente hasta llegar al último que tiene una referencia a NULL para marcar el fin de la lista

También se implementa un Iterador Externo que implementa los métodos:

 - Iter Crear
    >Crea el iterador externo
 - Iter Avanzar
    >Si el iterador puede avanzar devuelve True, en caso contrario devuelve False
 - Iter Ver Actual
    >Devuelve el elemento sobre el cual está "parado" el iterador
 - Iter Al Final 
    >Devuelve True si el iterador esta en la última posición de la lista, False en caso contrario
 - Iter Destruir
   >Destruye el iterador
 - Iter Insertar
    >Inserta el dato recibido por parámetro en la posición de la lista sobre la cual está "parado" el iterador
 - Iter Borrar
    >Borra el elemento de la lista sobre el cual el iterador está "parado"

Además se crea el iterador interno que recibe una función de visita con la firma:
 >void lista_iterar(lista_t *lista, bool visitar(void *dato, void *extra), void *extra);
 
 El mismo, recorre la lista aplicándole la función a cada dato hasta que la función de visita devuelva False o la lista termine una iteración completa
