#include "Controller.h"

int controller_mostrarMenu(int* opcion) {
	int retorno;

	if (opcion != NULL) {
		printf("--------PROGRAMA DE LIBROS Y EDITORIALES--------\n\n");
		printf("1. Cargar los datos de los libros de un archivo (texto)\n"
		       "2. Cargar los datos de las editoriales de un archivo (texto)\n"
		       "3. Ordenar la lista de libros según autores.\n"
		   	   "4. Imprimir todos los datos de los libros.\n"
		  	   "5. Guardar listado de los libros de la editorial Minotauro en un archivo.\n"
		  	   "6. Generar el archivo de salida mapeado.csv luego de aplicar la funcion map\n"
		   	   "7. Salir\n\n");

		retorno = IngresarEntero(opcion, "Ingrese una opción: ");
	}

	return retorno;
}

int controller_cargarLibrosDesdeArchivoTexto(LinkedList* listaLibros) {
	int retorno;
	char confirmacion;
	char nombreArchivo[30];
	FILE* pArch;
	confirmacion = ' ';
	retorno = -1;

	if (listaLibros != NULL) {
		if (ll_len(listaLibros) > 0) {
			retorno = PedirConfirmacionConIntentos(&confirmacion, "ALERTA: Ya hay una lista cargada. ¿Desea cargarla nuevamente? Se sobreescribirá", "¡ERROR! ALERTA: Ya hay una lista cargada. ¿Desea cargarla nuevamente? Se sobreescribirá", 5);
			if (retorno == -1 || confirmacion == 'n') {
				retorno = -2;
			}
		}
		if (retorno != -2) {
			retorno = IngresarCadenaConIntentos(nombreArchivo, sizeof(nombreArchivo), "Ingrese el nombre del archivo, con su extension: ", "ERROR. Ingrese el nombre del archivo, con su extension: ", 5);
			if (retorno == 0) {
				pArch = fopen(nombreArchivo, "r");
				if (pArch != NULL) {
					if (confirmacion == 's') {
						ll_clear(listaLibros);
					}
					retorno = parser_LibrosDesdeTexto(pArch, listaLibros);
					fclose(pArch);
				} else {
					retorno = -1;
				}
			}
		}
	}

	return retorno;
}

int controller_cargarEditorialesDesdeArchivoTexto(LinkedList* listaEditoriales) {
	int retorno;
	char confirmacion;
	char nombreArchivo[30];
	FILE* pArch;
	retorno = -1;
	confirmacion = ' ';

	if (listaEditoriales != NULL) {
		if (ll_len(listaEditoriales) > 0){
			retorno = PedirConfirmacionConIntentos(&confirmacion, "ALERTA: Ya hay una lista cargada. ¿Desea cargarla nuevamente? Se sobreescribirá", "¡ERROR! ALERTA: Ya hay una lista cargada. ¿Desea cargarla nuevamente? Se sobreescribirá", 5);
			if (retorno == -1 || confirmacion == 'n') {
				retorno = -2;
			}
		}
		if (retorno != -2) {
			retorno = IngresarCadenaConIntentos(nombreArchivo, sizeof(nombreArchivo), "Ingrese el nombre del archivo, con su extension: ", "ERROR. Ingrese el nombre del archivo, con su extension: ", 5);
			if (retorno == 0) {
				pArch = fopen(nombreArchivo, "r");
				if (pArch != NULL) {
					if (confirmacion == 's') {
						ll_clear(listaEditoriales);
					}
					retorno = parser_EditorialesDesdeTexto(pArch, listaEditoriales);
					fclose(pArch);
				} else {
					retorno = -1;
				}
			}
		}
	}

	return retorno;
}

int controller_ordenarLibros(LinkedList* listaLibros, int (*pFunc)(void*, void*)) {
	int retorno;
	retorno = -1;

	if (listaLibros != NULL && pFunc != NULL) {
		if (ll_len(listaLibros)) {
			retorno = ll_sort(listaLibros, pFunc, 1);
		} else {
			retorno = -2;
		}
	}

	return retorno;
}

int controller_imprimirLibros(LinkedList* listaLibros, LinkedList* listaEditoriales) {
	int retorno;
	int listSize;
	retorno = -1;

	if (listaLibros != NULL && listaEditoriales != NULL) {
		listSize = ll_len(listaLibros);
		if (listSize > 0 && ll_len(listaEditoriales) > 0) {
			retorno = eLibro_imprimirLibros(listaLibros, listaEditoriales);
		} else {
			retorno = -2;
		}
	}

	return retorno;
}

int controller_guardarLibrosFiltradosEnArchivoTexto(LinkedList* listaLibros, int (*pFunc)(void*)) {
	int retorno;
	FILE *pArch;
	retorno = -1;

	if (listaLibros != NULL && pFunc != NULL) {
		if (ll_len(listaLibros) > 0) {
			pArch = fopen("LibrosMinotauro.csv", "w");
			if (pArch != NULL) {
				retorno = eLibro_guardarLibrosFiltradosEnArchivoTexto(pArch, listaLibros, pFunc);
				fclose(pArch);
			}
		} else {
			retorno = -2;
		}
	}

	return retorno;
}

int controller_guardarListaMapeadaArchivoTexto(LinkedList* listaLibros, int (*pFunc)(void*)) {
	int retorno;
	FILE* pArch;
	retorno = -1;

	if (listaLibros != NULL) {
		if (ll_len(listaLibros) > 0) {
			retorno = ll_map(listaLibros, pFunc);
			if (retorno == 0) {
				pArch = fopen("mapeado.csv", "w");
				if (pArch != NULL) {
					retorno = eLibro_guardarListaMapeadaArchivoTexto(pArch, listaLibros);
					fclose(pArch);
				} else {
					retorno = -1;
				}
			}
		} else {
			retorno = -2;
		}
	}

	return retorno;
}
