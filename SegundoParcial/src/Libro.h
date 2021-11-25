#ifndef LIBRO_H_
#define LIBRO_H_
#include "Editorial.h"

typedef struct {
	int id;
	int idEditorial;
	char titulo[80];
	char autor[50];
	float precio;
} eLibro;

/// \fn eLibro eLibro_new*()
/// \brief Crea espacio en memoria dinamica para almacenar un nuevo libro
/// \return Retorna el puntero al libro creado - NULL si no encontró espacio en memoria
eLibro* eLibro_new();

/// \fn eLibro eLibro_newParametros*(char*, char*, char*, char*, char*)
/// \brief Crea espacio en memoria dinamica para almacenar un nuevo libro y asigna valores a los campos del mismo, pasados
/// como cadena de caracteres, que luego son parseados. Muy util para utilizar a la hora de traer desde el archivo de texto.
/// \param idStr ID del libro, como cadena de caracteres
/// \param titulo Titulo del libro
/// \param autor Autor del libro
/// \param precioStr Precio del libro, como cadena de caracteres
/// \param idEditorialStr ID de la editorial, como cadena de caracteres
/// \return Retorna el puntero al libro creado - NULL si no encontró espacio en memoria o si hubo otro error (no poder cargar
/// los datos correctamente al nuevo libro)
eLibro* eLibro_newParametros(char* idStr, char* titulo, char* autor, char* precioStr, char* idEditorialStr);

/// \fn int eLibro_setLibro(eLibro*, int, char*, char*, float, int)
/// \brief Setea los valores pasados por parámetro al nuevo libro
/// \param libro Puntero a eLibro donde van a ser almacenados los datos
/// \param id ID del libro a ser seteado
/// \param titulo Titulo del libro a ser seteado
/// \param autor Autor del libro a ser seteado
/// \param precio Precio del libro a ser seteado
/// \param idEditorial ID del libro a ser seteado
/// \return Retorna  0 si pudo setear el libro correctamente - (-1) si no pudo
int eLibro_setLibro(eLibro* libro, int id, char* titulo, char* autor, float precio,  int idEditorial);

/// \fn int eLibro_setId(eLibro*, int)
/// \brief Setea el ID del libro
/// \param libro Puntero a eLibro
/// \param id ID del libro
/// \return Retorna 0 si pudo setearlo correctamente - (-1) si hubo un error (puntero nulo)
int eLibro_setId(eLibro* libro, int id);

/// \fn int eLibro_setIdEditorial(eLibro*, int)
/// \brief Setea el ID de la editorial del libro
/// \param libro Puntero a eLibro
/// \param idEditorial ID de la editorial del libro
/// \return Retorna 0 si pudo setearlo correctamente - (-1) si hubo un error (puntero nulo)
int eLibro_setIdEditorial(eLibro* libro, int idEditorial);

/// \fn int eLibro_setTitulo(eLibro*, char*)
/// \brief Setea el titulo a eLibro
/// \param libro Puntero a eLibro
/// \param titulo Titulo del libro
/// \return Retorna 0 si pudo setearlo correctamente - (-1) si hubo un error (puntero nulo)
int eLibro_setTitulo(eLibro* libro, char* titulo);

/// \fn int eLibro_setAutor(eLibro*, char*)
/// \brief Setea el autor del eLibro
/// \param libro Puntero a eLibro
/// \param autor Autor del libro
/// \return Retorna 0 si pudo setearlo correctamente - (-1) si hubo un error (puntero nulo)n
int eLibro_setAutor(eLibro* libro, char* autor);

/// \fn int eLibro_setPrecio(eLibro*, float)
/// \brief Setea el precio del eLibro
/// \param libro Puntero a eLibro
/// \param precio Precio del libro
/// \return Retorna 0 si pudo setearlo correctamente - (-1) si hubo un error (puntero nulo)
int eLibro_setPrecio(eLibro* libro, float precio);

/// \fn int eLibro_getId(eLibro*, int*)
/// \brief Obtiene el id del eLibro
/// \param libro Puntero a eLibro
/// \param id Puntero a entero donde se almacenará el ID del libro
/// \return Retorna 0 si pudo obtenerlo correctamente - (-1) si hubo un error (puntero nulo)
int eLibro_getId(eLibro* libro, int* id);

/// \fn int eLibro_getIdEditorial(eLibro*, int*)
/// \brief Obtiene el ID de la editorial del eLibro
/// \param libro Puntero a eLibro
/// \param idEditorial Puntero a entero donde se almacenará el ID de la editorial del libro
/// \return Retorna 0 si pudo obtenerlo correctamente - (-1) si hubo un error (puntero nulo)
int eLibro_getIdEditorial(eLibro* libro, int* idEditorial);

/// \fn int eLibro_getTitulo(eLibro*, char*)
/// \brief Obtiene el titulo de la editorial del eLibro
/// \param libro Puntero a eLibro
/// \param titulo Cadena de caracteres donde se almacenará el titulo del libro
/// \return Retorna 0 si pudo obtenerlo correctamente - (-1) si hubo un error (puntero nulo)
int eLibro_getTitulo(eLibro* libro, char* titulo);

/// \fn int eLibro_getAutor(eLibro*, char*)
/// \brief Obtiene el autor del eLibro
/// \param libro Puntero a eLibro
/// \param idEditorial Cadena de caracteres donde se almacenará el autor del libro
/// \return Retorna 0 si pudo obtenerlo correctamente - (-1) si hubo un error (puntero nulo)
int eLibro_getAutor(eLibro* libro, char* autor);

/// \fn int eLibro_getPrecio(eLibro*, float*)
/// \brief Obtiene el precio del eLibro
/// \param libro Puntero a eLibro
/// \param idEditorial Puntero a flotante donde se almacenará el precio del libro
/// \return Retorna 0 si pudo obtenerlo correctamente - (-1) si hubo un error (puntero nulo)
int eLibro_getPrecio(eLibro* libro, float* precio);

/// \fn void eLibro_deleteLibro(eLibro*)
/// \brief Elimina un libro, liberando espacio en memoria
/// \param libro Puntero a eLibro a ser liberado
void eLibro_deleteLibro(eLibro* libro);

/// \fn int eLibro_imprimirLibros(LinkedList*, LinkedList*)
/// \brief Imprime toda la lista de libros
/// \param listaLibros Puntero a LinkedList donde se almacenan los libros
/// \param listaEditoriales Puntero a LinkedList donde se almacenan las editoriales
/// \return Retorna 0 si se pudieron imprimir los libros - (-1) si hubo un error
int eLibro_imprimirLibros(LinkedList* listaLibros, LinkedList* listaEditoriales);

/// \fn int eLibro_mostrarLibro(eLibro*, LinkedList*)
/// \brief Muestra todos los datos de un libro
/// \param libro Puntero a eLibro
/// \param listaEditoriales Puntero a LinkedList de editoriales
/// \return Retorna 0 si pudo mostrar los datos del libro correctamente - (-1) si hubo un error
int eLibro_mostrarLibro(eLibro* libro, LinkedList* listaEditoriales);

/// \fn int eLibro_CompararNombres(void*, void*)
/// \brief Compara dos nombres de autores de distintos libros
/// \param l1 Puntero a void que apunta a un libro
/// \param l2 Puntero a void que apunta a un libro
/// \return Retorna 1 si l1 es mayor que l2 - (-1) si l1 es menor que l2 - 0 si son iguales
int eLibro_CompararNombres(void* l1, void* l2);

/// \fn int eLibro_CompararEditorial(void*)
/// \brief Compara la editorial del libro para comprobar si pertenece a la editorial Minotauro
/// \param pElement Puntero a void que apunta a un libro
/// \return Retorna (-1) si hubo un error al obtener el ID del libro a comparar - 0 si no pertenece
/// a la editorial Minotauro - 1 si pertenece
int eLibro_CompararEditorial(void* pElement);

/// \fn int eLibro_guardarLibrosFiltradosEnArchivoTexto(FILE*, LinkedList*, int(*)(void*))
/// \brief Guarda la lista de libros filtrada según un criterio establecido por la función puntero
/// \param pFile Archivo en el que se va a guardar la lista
/// \param listaLibros Puntero a LinkedList de libros
/// \param pFunc Función puntero que establece el criterio de filtrado
/// \return Retorna 0 si pudo guardar la lista correctamente - (-1) si no pudo
int eLibro_guardarLibrosFiltradosEnArchivoTexto(FILE* pFile, LinkedList* listaLibros, int (*pFunc)(void*));

int eLibro_descontarPrecio(void* l1);

int eLibro_guardarListaMapeadaArchivoTexto(FILE* pArch, LinkedList* listaLibros);

#endif /* LIBRO_H_ */
