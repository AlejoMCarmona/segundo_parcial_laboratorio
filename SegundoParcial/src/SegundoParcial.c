/*
 ============================================================================
 Name        : SegundoParcial.c
 Author      : Alejo Martin Carmona
 Version     : V1.0
 Copyright   : Your copyright notice
 Description : Segundo parcial de Laboratorio I
 Date		 : 25/11/2021
 ============================================================================
 */

#include "Controller.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int retorno;
	LinkedList* listaLibros;
	LinkedList* listaEditoriales;
	listaLibros = ll_newLinkedList();
	listaEditoriales = ll_newLinkedList();

	if (listaLibros != NULL && listaLibros != NULL) {
		do{
			retorno = controller_mostrarMenu(&opcion);
			printf("--------------------------------------------------\n");

			if (retorno == 0) {
			            switch(opcion) {
			                case 1:
			                	retorno = controller_cargarLibrosDesdeArchivoTexto(listaLibros);
			                	if (retorno == 0) {
			                		printf("Archivo de texto cargado con éxito.\n");
			                	} else {
			                		if (retorno == -2) {
			                			printf("ERROR. Ya hay una lista de libros cargada.\n");
			                		} else {
				                		printf("¡ERROR al intentar cargar el archivo de libros a la lista!\n");
			                		}
			                	}
			                    break;
			                case 2:
			                	retorno = controller_cargarEditorialesDesdeArchivoTexto(listaEditoriales);
			                	 if (retorno == 0) {
			                		 printf("Archivo de texto cargado con éxito.\n");
			                	 } else {
				                	if (retorno == -2) {
				                		printf("ERROR. Ya hay una lista de editoriales cargada.\n");
				                	} else {
					                	printf("¡ERROR al intentar cargar el archivo de editoriales a la lista!\n");
				                	}
			                	 }
			                	break;
			                case 3:
			                	retorno = controller_ordenarLibros(listaLibros, eLibro_CompararNombres);
			                	if (retorno == 0) {
			                		printf("Ordenamiento realizado con éxito.\n");
			                	} else {
			                		if (retorno == -2) {
			                			printf("¡ERROR! Debe cargar primero la lista de libros.\n");
			                		} else {
			                			printf("¡ERROR! No se pudo realizar el ordenamiento con éxito\n");
			                		}

			                	}
			                	break;
			                case 4:
			                	retorno = controller_imprimirLibros(listaLibros, listaEditoriales);
			                	if (retorno == -1) {
			                		printf("¡ERROR al intentar imprimir los libros!\n");
			                	} else {
			                		if (retorno == -2) {
			                			printf("¡ERROR! Debe cargar primero la lista de libros y la de editoriales.\n");
			                		}
			                	}
			                	break;
			                case 5:
			                	retorno = controller_guardarLibrosFiltradosEnArchivoTexto(listaLibros, eLibro_CompararEditorial);
			                	if (retorno == 0) {
			                		printf("Lista guardada con exito en el archivo de texto.\n");
			                	} else {
			                		if (retorno == -2) {
			                			printf("¡ERROR! Debe cargar primero la lista de libros.\n");
			                		} else {
			                			printf("¡ERROR al querer guardar la lista!\n");
			                		}
			                	}
			                	break;
			                case 6:
			                	retorno = controller_guardarListaMapeadaArchivoTexto(listaLibros, eLibro_descontarPrecio);
			                	if (retorno == 0) {
			                		printf("Descuentos realizados con exito y archivo creado.\n");
			                	} else {
			                		if (retorno == -1) {
			                			printf("ERROR\n");
			                		} else {
			                			if (retorno == -2) {
			                				printf("ERROR. Debe cargar la lista de libros primero.\n");
			                			}
			                		}
			                	}
			                	break;
			                case 7:
			                	printf("¡Gracias por utilizar el programa!\n");
			                	ll_deleteLinkedList(listaLibros);
			                	ll_deleteLinkedList(listaEditoriales);
			                	break;
			                default:
			                	printf("Elija una opcion válida.\n");
			                	break;
			            }
			        } else {
			        	printf("ERROR. Solo ingrese números enteros.\n");
			        }

			        printf("--------------------------------------------------\n");
			    }while(opcion != 7);
	} else {
		printf("ERROR AL INTENTAR CREAR LAS LISTAS ENLAZADAS. Programa finalizado.\n");
	}

	return EXIT_SUCCESS;
}
