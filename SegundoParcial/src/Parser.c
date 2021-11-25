#include "Parser.h"
#include "Editorial.h"
#include <stdio.h>
#include "Libro.h"

int parser_LibrosDesdeTexto(FILE* pArch , LinkedList* listaLibros)
{
	int retorno;
	char idStr[20];
	char titulo[80];
	char autor[50];
	char precioStr[20];
	char idEditorialStr[20];
	int r;
	eLibro* nuevoLibro;
	retorno = -1;

	if (pArch != NULL && listaLibros != NULL) {
		fscanf(pArch, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, titulo, autor, precioStr, idEditorialStr); //para la cabecera
	    while(!feof(pArch)) {
	    	r = fscanf(pArch, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, titulo, autor, precioStr, idEditorialStr);
	    	if (r != 5) {
	    		retorno = -1;
	    		break;
	    	}
	    	nuevoLibro = eLibro_newParametros(idStr, titulo, autor, precioStr, idEditorialStr);
			if (nuevoLibro == NULL) {
				retorno = -1;
				break;
			}
			retorno = ll_add(listaLibros, nuevoLibro);
			if (retorno == -1) {
				eLibro_deleteLibro(nuevoLibro);
				break;
			}
	    }
	}

    return retorno;
}

int parser_EditorialesDesdeTexto (FILE* pArch, LinkedList* listaEditoriales) {
	int retorno;
	int r;
	char idStr[20];
	char nombre[50];
	eEditorial* nuevaEditorial;
	retorno = -1;

	if (pArch != NULL && listaEditoriales != NULL) {
		fscanf(pArch, "%[^,],%[^\n]\n", idStr, nombre);
	    while(!feof(pArch)) {
	    	r = fscanf(pArch, "%[^,],%[^\n]\n", idStr, nombre);
	    	if (r != 2) {
	    		retorno = -1;
	    		break;
	    	}
	    	nuevaEditorial = eEditorial_newParametros(idStr, nombre);
			if (nuevaEditorial == NULL) {
				retorno = -1;
				break;
			}
			retorno = ll_add(listaEditoriales, nuevaEditorial);
			if (retorno != 0) {
				eEditorial_deleteEditorial(nuevaEditorial);
				retorno = -1;
				break;
			}
	    }
	}

	return retorno;
}



