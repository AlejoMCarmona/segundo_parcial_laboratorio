#ifndef PARSER_H_
#define PARSER_H_
#include "Libro.h"

/// \fn int parser_LibrosDesdeTexto(FILE*, LinkedList*)
/// \brief Convierte los datos de los libros almacenados como texto en el archivo a los tipos de datos
/// correspondientes, para luego ser almacenados en una lista dinámica
/// \param pArch Puntero a FILE que representa el archivo a abrir
/// \param listaLibros LinkedList de libros
/// \return Retorna 0 si pudo parsear los datos correctamente a una LinkedList - (-1) si hubo un error
int parser_LibrosDesdeTexto(FILE* pArch , LinkedList* listaLibros);

/// \fn int parser_EditorialesDesdeTexto(FILE*, LinkedList*)
/// \brief Convierte los datos de las editoriales almacenados como texto en el archivo a los tipos de datos
/// correspondientes, para luego ser almacenados en una lista dinámica
/// \param pArch Puntero a FILE que representa el archivo a abrir
/// \param listaLibros LinkedList de libros
/// \return Retorna 0 si pudo parsear los datos correctamente a una LinkedList - (-1) si hubo un error
int parser_EditorialesDesdeTexto (FILE* pArch , LinkedList* listaEditoriales);

#endif /* PARSER_H_ */
