#include "Editorial.h"
#include "LinkedList.h"

//constructores:
eEditorial* eEditorial_new() {
	eEditorial* nuevoEditorial;
	nuevoEditorial = (eEditorial*) malloc(sizeof(eEditorial));
	return nuevoEditorial;
}

eEditorial* eEditorial_newParametros(char* idStr, char* nombre) {
	eEditorial* nuevaEditorial;
	int retorno;
	int id;
	nuevaEditorial = NULL;

	if (idStr != NULL && nombre != NULL) {
		nuevaEditorial = eEditorial_new();
		if (nuevaEditorial != NULL) {
			id = atoi(idStr);

			retorno = eEditorial_setEditorial(nuevaEditorial, id, nombre);
			if (retorno == -1){
				eEditorial_deleteEditorial(nuevaEditorial);
				nuevaEditorial = NULL;
			}
		}
	}

	return nuevaEditorial;
}

//setters:
int eEditorial_setEditorial(eEditorial* editorial, int id, char* nombre) {
	int retorno;
	retorno = -1;

	if (editorial != NULL && nombre != NULL) {
		retorno = eEditorial_setId(editorial, id);
		if (retorno == 0) {
			retorno = eEditorial_setNombre(editorial, nombre);
		}
	}

	return retorno;
}

int eEditorial_setId(eEditorial* editorial, int id) {
	int retorno;
	retorno = -1;

	if (editorial != NULL && id > 0) {
		editorial->id = id;
		retorno = 0;
	}

	return retorno;
}

int eEditorial_setNombre(eEditorial* editorial, char* nombre) {
	int retorno;
	retorno = -1;

	if (editorial != NULL && nombre > 0) {
		strcpy(editorial->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

//getters:
int eEditorial_getId(eEditorial* editorial, int *id) {
	int retorno;
	retorno = -1;

	if (editorial != NULL && id != NULL) {
		*id = editorial->id;
		retorno = 0;
	}

	return retorno;
}

int eEditorial_getNombre(eEditorial* editorial, char* nombre) {
	int retorno;
	retorno = -1;

	if (editorial != NULL && nombre != NULL) {
		strcpy(nombre, editorial->nombre);
		retorno = 0;
	}

	return retorno;
}

//extras:
eEditorial* eEditorial_BuscarPorId(LinkedList* listEditoriales, int id) {
	int idAux;
	int listSize;
	int i;
	eEditorial* editorial;

	if (listEditoriales != NULL) {
		listSize = ll_len(listEditoriales);
		for (i = 0; i < listSize; i++) {
			editorial = (eEditorial*) ll_get(listEditoriales, i);
			if (eEditorial_getId(editorial, &idAux) == 0 && idAux == id) {
				break;
			}
		}
		if (listSize == i) {
			editorial = NULL;
		}
	}

	return editorial;
}

int eEditorial_mostrarEditorial(eEditorial* editorial) {
	int retorno;
	int id;
	char nombre[50];
	retorno = -1;

	if (editorial != NULL) {
		eEditorial_getId(editorial, &id);
		eEditorial_getNombre(editorial, nombre);
		printf("%d\t%s\n", id, nombre);
		retorno = 0;
	}

	return retorno;
}

void eEditorial_deleteEditorial(eEditorial* editorial) {
	if (editorial != NULL) {
		free(editorial);
	}
}

