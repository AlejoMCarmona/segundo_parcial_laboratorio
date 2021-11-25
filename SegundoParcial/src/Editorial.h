#ifndef EDITORIAL_H_
#define EDITORIAL_H_
#include "LinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int id;
	char nombre[30];
} eEditorial;

/// \fn eEditorial eEditorial_new*()
/// \brief Crea espacio en memoria dinámica para almacenar una editorial
/// \return Retorna un puntero a eEditorial - NULL si no encontró espacio en memoria
eEditorial* eEditorial_new();

/// \fn eEditorial eEditorial_newParametros*(char*, char*)
/// \brief Crea espacio en memoria dinamica para almacenar una nueva editorial y asigna valores a los campos del mismo, pasados
/// como cadena de caracteres, que luego son parseados. Muy util para utilizar a la hora de traer desde el archivo de texto.
/// \param idStr ID de la editorial, como cadena de caracteres
/// \param nombre Nombre de la editorial
/// \return Retorna el puntero a la editorial creada - NULL si no encontró espacio en memoria o si hubo otro error (no poder cargar
/// los datos correctamente a la nueva editorial)
eEditorial* eEditorial_newParametros(char* idStr, char* nombre);

/// \fn int eEditorial_setEditorial(eEditorial*, int, char*)
/// \brief Setea los valores pasados por parámetro a la nueva editorial
/// \param editorial Puntero a eEditorial donde se van a almacenar los valores
/// \param id ID de la nueva editorial
/// \param nombre Nombre de la editorial
/// \return Retorna 0 si pudo setear el libro correctamente - (-1) si no pudo
int eEditorial_setEditorial(eEditorial* editorial, int id, char* nombre);

/// \fn int eEditorial_setId(eEditorial*, int)
/// \brief Setea el ID de la editorial
/// \param editorial Puntero a eEditorial
/// \param id ID de la editorial
/// \return Retorna 0 si pudo setearlo correctamente - (-1) si hubo un error (puntero nulo)
int eEditorial_setId(eEditorial* editorial, int id);

/// \fn int eEditorial_setNombre(eEditorial*, char*)
/// \brief Setea el nombre de la editorial
/// \param editorial Puntero a eEditorial
/// \param nombre Nombre de la editorial
/// \return Retorna 0 si pudo setearlo correctamente - (-1) si hubo un error (puntero nulo)
int eEditorial_setNombre(eEditorial* editorial, char* nombre);

/// \fn int eEditorial_getId(eEditorial*, int*)
/// \brief Obtiene el id de la editorial
/// \param editorial Puntero a eEditorial
/// \param id Puntero a entero donde se almacenará el ID de la editorial
/// \return Retorna 0 si pudo obtenerlo correctamente - (-1) si hubo un error (puntero nulo)
int eEditorial_getId(eEditorial* editorial, int *id);

/// \fn int eEditorial_getNombre(eEditorial*, char*)
/// \brief Obtiene el nombre de la editorial
/// \param editorial Puntero a eEditorial
/// \param nombre Puntero a cadena de caracteres donde se almacenará el nombre de la editorial
/// \return Retorna 0 si pudo obtenerlo correctamente - (-1) si hubo un error (puntero nulo)
int eEditorial_getNombre(eEditorial* editorial, char* nombre);

/// \fn eEditorial eEditorial_BuscarPorId*(LinkedList*, int)
/// \brief Busca una editorial a través de su ID
/// \param listEditoriales Puntero a LinkedList de editoriales
/// \param id ID a buscar en la lista enlazada
/// \return Retorna un puntero a la editorial con ese ID - NULL si hubo un error, como ID no
/// encontrado o puntero hacia la lista nulo
eEditorial* eEditorial_BuscarPorId(LinkedList* listEditoriales, int id);

/// \fn void eEditorial_deleteEditorial(eEditorial*)
/// \brief Elimina una editorial de la lista, liberando espacio en memoria dinámcia
/// \param editorial Puntero a eEditorial a eliminar
void eEditorial_deleteEditorial(eEditorial* editorial);

/// \fn int eEditorial_mostrarEditorial(eEditorial*)
/// \brief Muestra los datos de una editorial
/// \param editorial Puntero a eEditorial cuyos datos se quieren mostrar
/// \return Retorna 0 si pudo mostrarse la editorial correctamente - (-1) si hubo un error
int eEditorial_mostrarEditorial(eEditorial* editorial);

#endif /* EDITORIAL_H_ */

