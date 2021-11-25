#include "Libro.h"

//constructores:
eLibro* eLibro_new() {
	eLibro* nuevoLibro;
	nuevoLibro = (eLibro*) malloc(sizeof(eLibro));
	return nuevoLibro;
}

eLibro* eLibro_newParametros(char* idStr, char* titulo, char* autor, char* precioStr, char* idEditorialStr) {
	eLibro* nuevoLibro;
	int retorno;
	int id;
	int idEditorial;
	float precio;
	nuevoLibro = NULL;

	if (idStr != NULL && idEditorialStr != NULL && titulo != NULL && autor != NULL && precioStr != NULL) {
		nuevoLibro = eLibro_new();
		if (nuevoLibro != NULL) {
			id = atoi(idStr);
			idEditorial = atoi(idEditorialStr);
			precio = atof(precioStr);

			retorno = eLibro_setLibro(nuevoLibro, id, titulo, autor, precio, idEditorial);
			if (retorno == -1){
				eLibro_deleteLibro(nuevoLibro);
				nuevoLibro = NULL;
			}
		}
	}

	return nuevoLibro;
}

//setters:
int eLibro_setLibro(eLibro* libro, int id, char* titulo, char* autor, float precio,  int idEditorial) {
	int retorno;
	retorno = -1;

	if (libro != NULL && titulo != NULL && autor != NULL) {
		retorno = eLibro_setId(libro, id);
		if (retorno == 0) {
			retorno = eLibro_setIdEditorial(libro, idEditorial);
			if (retorno == 0) {
				retorno = eLibro_setAutor(libro, autor);
				if (retorno == 0) {
					retorno = eLibro_setTitulo(libro, titulo);
					if (retorno == 0) {
						retorno = eLibro_setPrecio(libro, precio);
					}
				}
			}
		}
	}

	return retorno;
}

int eLibro_setId(eLibro* libro, int id) {
	int retorno;
	retorno = -1;

	if (libro != NULL && id > 0) {
		libro->id = id;
		retorno = 0;
	}

	return retorno;
}

int eLibro_setIdEditorial(eLibro* libro, int idEditorial) {
	int retorno;
	retorno = -1;

	if (libro != NULL && idEditorial > 0) {
		libro->idEditorial = idEditorial;
		retorno = 0;
	}

	return retorno;
}

int eLibro_setTitulo(eLibro* libro, char* titulo) {
	int retorno;
	retorno = -1;

	if (libro != NULL && titulo != NULL) {
		strcpy(libro->titulo, titulo);
		retorno = 0;
	}

	return retorno;
}

int eLibro_setAutor(eLibro* libro, char* autor) {
	int retorno;
	retorno = -1;

	if (libro != NULL && autor != NULL) {
		strcpy(libro->autor, autor);
		retorno = 0;
	}

	return retorno;
}

int eLibro_setPrecio(eLibro* libro, float precio) {
	int retorno;
	retorno = -1;

	if (libro != NULL && precio > 0) {
		libro->precio = precio;
		retorno = 0;
	}

	return retorno;
}

//getters:
int eLibro_getId(eLibro* libro, int* id) {
	int retorno;
	retorno = -1;

	if (libro != NULL && id != NULL) {
		*id = libro->id;
		retorno = 0;
	}

	return retorno;
}

int eLibro_getIdEditorial(eLibro* libro, int* idEditorial) {
	int retorno;
	retorno = -1;

	if (libro != NULL && idEditorial != NULL) {
		*idEditorial = libro->idEditorial;
		retorno = 0;
	}

	return retorno;
}

int eLibro_getTitulo(eLibro* libro, char* titulo) {
	int retorno;
	retorno = -1;

	if (libro != NULL && titulo != NULL) {
		strcpy(titulo, libro->titulo);
		retorno = 0;
	}

	return retorno;
}

int eLibro_getAutor(eLibro* libro, char* autor) {
	int retorno;
	retorno = -1;

	if (libro != NULL && autor != NULL) {
		strcpy(autor, libro->autor);
		retorno = 0;
	}

	return retorno;
}

int eLibro_getPrecio(eLibro* libro, float* precio) {
	int retorno;
	retorno = -1;

	if (libro != NULL && precio != NULL) {
		*precio = libro->precio;
		retorno = 0;
	}

	return retorno;
}

//otras:
void eLibro_deleteLibro(eLibro* libro) {
	if (libro != NULL) {
		free(libro);
	}
}

int eLibro_imprimirLibros(LinkedList* listaLibros, LinkedList* listaEditoriales) {
	int retorno;
	int listSize;
	int i;
	eLibro* libroAux;
	retorno = -1;

	if (listaLibros != NULL && listaEditoriales != NULL) {
		listSize = ll_len(listaLibros);
		printf("ID    Editorial\t\t   Nombre\t\t\t\t  Autor\t\t\t\t  Precio\n");
		for (i = 0; i < listSize; i++) {
			libroAux = ll_get(listaLibros, i);
			if (libroAux == NULL || eLibro_mostrarLibro(libroAux, listaEditoriales) != 0) {
				break;
			}
		}
		if (i == listSize) {
			retorno = 0;
		}
	}

	return retorno;
}

int eLibro_mostrarLibro(eLibro* libro, LinkedList* listaEditoriales) {
	int retorno;
	int id;
	int idEditorial;
	char nombreEditorial[50];
	char titulo[80];
	char autor[50];
	float precio;
	eEditorial* editorialAux;
	retorno = -1;

	if (libro != NULL && listaEditoriales != NULL) {
		eLibro_getId(libro, &id);
		eLibro_getIdEditorial(libro, &idEditorial);
		eLibro_getAutor(libro, autor);
		eLibro_getTitulo(libro, titulo);
		eLibro_getPrecio(libro, &precio);

		editorialAux = eEditorial_BuscarPorId(listaEditoriales, idEditorial);
		if (editorialAux != NULL) { //TODO: editorial desconocida?
			eEditorial_getNombre(editorialAux, nombreEditorial);
			printf("%-4d  %-20s %-20s %30s %30f\n", id, nombreEditorial, titulo, autor, precio);
			retorno = 0;
		}
	}

	return retorno;
}

int eLibro_CompararNombres(void* l1, void* l2) {
	int retorno;
	eLibro* libro1;
	eLibro* libro2;
	char autorl1[50];
	char autorl2[50];
	retorno = -1;
	libro1 = (eLibro*) l1;
	libro2 = (eLibro*) l2;

	if (libro1 != NULL && libro2 != NULL) {
		if (eLibro_getAutor(libro1, autorl1) == 0 && eLibro_getAutor(libro2, autorl2) == 0) {
			retorno = strcmp(autorl1,autorl2);
		}
	}

	return retorno;
}

int eLibro_CompararEditorial(void* pElement) {
	int retorno;
	int idEditorial;
	eLibro* libro = (eLibro*) pElement;
	retorno = -1;

	if (libro != NULL) {
		retorno = eLibro_getIdEditorial(libro, &idEditorial);
		if (retorno != -1) {
			if (idEditorial == 4) {
				retorno = 1;
			} else {
				retorno = 0;
			}
		}
	}

	return retorno;
}

int eLibro_guardarLibrosFiltradosEnArchivoTexto(FILE* pFile, LinkedList* listaLibros, int (*pFunc)(void*)) {
	int retorno;
	int r;
	int i;
	LinkedList* listaFiltrada;
	eLibro* libroAux;
	int tamLista;
	int id;
	int idEditorial;
	char titulo[80];
	char autor[50];
	float precio;
	retorno = -1;

	if (pFile != NULL && pFunc != NULL){
		listaFiltrada = ll_filter(listaLibros, pFunc);
		if (listaFiltrada != NULL) {
			tamLista = ll_len(listaFiltrada);
			if (tamLista != -1) {
				fprintf(pFile, "id,titulo,autor,precio,idEditorial (Minotauro)\n");
				for (i = 0; i < tamLista; i++) {
					libroAux = ll_get(listaFiltrada, i);
					if (libroAux != NULL) {
						eLibro_getId(libroAux, &id);
						eLibro_getIdEditorial(libroAux, &idEditorial);
						eLibro_getTitulo(libroAux, titulo);
						eLibro_getAutor(libroAux, autor);
						eLibro_getPrecio(libroAux, &precio);
						r = fprintf(pFile, "%d,%s,%s,%f,%d\n", id, titulo, autor, precio, idEditorial);
						if (r < 0) {
							break;
						}
					}
				}
				if (i == tamLista) {
					retorno = 0;
				}
			}
		}
	}

	return retorno;
}

int eLibro_descontarPrecio(void* l1) {
	int retorno;
	int idEditorial;
	float precio;
	float porcDescuento;
	float descuento;
	eLibro* libro;
	porcDescuento = 0;
	retorno = -1;
	libro = (eLibro*) l1;

	if (libro != NULL) {
		eLibro_getIdEditorial(libro, &idEditorial);
		eLibro_getPrecio(libro, &precio);
		if (precio >= 300 && idEditorial == 1) {
			porcDescuento = 20;
		} else {
			if (precio <= 200 && idEditorial == 2) {
				porcDescuento = 10;
			}
		}
		descuento = (precio * porcDescuento) / 100;
		precio -= descuento;
		eLibro_setPrecio(libro, precio);
		retorno = 0;
	}

	return retorno;
}

int eLibro_guardarListaMapeadaArchivoTexto(FILE* pArch, LinkedList* listaLibros) {
	int retorno;
	int i;
	int id;
	int idEditorial;
	char titulo[80];
	char autor[50];
	float precio;
	int r;
	int tamLista;
	eLibro* libroAux;
	retorno = -1;

	if (listaLibros != NULL && pArch != NULL) {
		tamLista = ll_len(listaLibros);
		if (tamLista != -1) {
			fprintf(pArch, "id,titulo,autor,precio,idEditorial\n");
			for (i = 0; i < tamLista; i++) {
				libroAux = ll_get(listaLibros, i);
				if (libroAux != NULL) {
					eLibro_getId(libroAux, &id);
					eLibro_getIdEditorial(libroAux, &idEditorial);
					eLibro_getTitulo(libroAux, titulo);
					eLibro_getAutor(libroAux, autor);
					eLibro_getPrecio(libroAux, &precio);
					r = fprintf(pArch, "%d,%s,%s,%f,%d\n", id, titulo, autor, precio, idEditorial);
					if (r < 0) {
						break;
					}
				}
			}
			if (i == tamLista) {
				retorno = 0;
			}
		}
	}

	return retorno;
}
