#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Input.h"
#include "Parser.h"
#include <stdio.h>

/// \fn int controller_mostrarMenu(int*)
/// \brief Muestra un menú de opciones y le permite al usuario elegir una de ellas
/// \param opcion Puntero a entero donde se almacena la opción elegida por el usuario
/// \return Retorna 0 si pudo ingresarse un entero correctamente - (-1) si hubo un error
int controller_mostrarMenu(int* opcion);

/// \fn int controller_cargarLibrosDesdeArchivoTexto(LinkedList*)
/// \brief Carga todos los libros desde un archivo de texto a una LinkedList
/// \param listaLibros Puntero a LinkedList donde se almacenan los libros
/// \return Retorna 0 si pudo cargarse correctamente - (-1) si hubo un error.
int controller_cargarLibrosDesdeArchivoTexto(LinkedList* listaLibros);

/// \fn int controller_cargarEditorialesDesdeArchivoTexto(LinkedList*)
/// \brief Carga todos los editoriales desde un archivo de texto a una LinkedList
/// \param listaEditoriales Puntero a LinkedList donde se almacenan las editoriales
/// \return Retorna 0 si pudo cargarse correctamente - (-1) si hubo un error.
int controller_cargarEditorialesDesdeArchivoTexto(LinkedList* listaEditoriales);

/// \fn int controller_imprimirLibros(LinkedList*, LinkedList*)
/// \brief Imprime todos los datos de los libros
/// \param listaLibros Puntero a LinkedList donde se almacenan los libros
/// \param listaEditoriales Puntero a LinkedList donde se almacenan las editoriales
/// \return Retorna 0 si pudieron imprimirse los libros correctamente - (-1) si hubo un error - (-2) si aún no
/// se cargaron las listas
int controller_imprimirLibros(LinkedList* listaLibros, LinkedList* listaEditoriales);

/// \fn int controller_ordenarLibros(LinkedList*, int(*)(void*, void*))
/// \brief Ordena los libros de manera ascendente, según un criterio establecido por la función puntero
/// \param listaLibros Puntero a LinkedList donde se almacenan los libros
/// \param pFunc Puntero a funcion que se encarga de establecer el criterio de ordenamiento
/// \return Retorna 0 si se pudo realizar el ordenamiento de manera correcta - (-1) si hubo un error - (-2) si aún
/// no se cargó la lista de los libros
int controller_ordenarLibros(LinkedList* listaLibros, int (*pFunc)(void*, void*));

/// \fn int controller_guardarLibrosFiltradosEnArchivoTexto(LinkedList*, int(*)(void*))
/// \brief Guarda los libros filtrados según el criterio establecido por la función puntero en un archivo de texto
/// \param listaLibros Puntero a LinkedList donde se almacenan los libros
/// \param pFunc Puntero a funcion que se encarga de establecer el criterio de filtrado
/// \return Retorna 0 si se pudo guardar la lista filtrada según el criterio - (-1) si hubo un error - (-2) si aún
/// no se cargó la lista de los libros
int controller_guardarLibrosFiltradosEnArchivoTexto(LinkedList* listaLibros, int (*pFunc)(void*));

int controller_guardarListaMapeadaArchivoTexto(LinkedList* listaLibros, int (*pFunc)(void*));

#endif /* CONTROLLER_H_ */
