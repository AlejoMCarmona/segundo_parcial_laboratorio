#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/// \fn LinkedList ll_newLinkedList*(void)
/// \brief Crea un nuevo LinkedList en memoria de manera dinamica
/// \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria o el puntero al espacio reservado
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if (this != NULL) {
        this->pFirstNode = NULL;
        this->size = 0;
    }

    return this;
}

/// \fn int ll_len(LinkedList*)
/// \brief Retorna la cantidad de elementos de la lista
/// \param this LinkedList* Puntero a la lista
/// \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
int ll_len(LinkedList* this)
{
    int returnAux;
    returnAux = -1;

    if (this != NULL) {
    	returnAux = this->size;
    }

    return returnAux;
}

/// \fn Node getNode*(LinkedList*, int)
/// \brief Obtiene un nodo de la lista
/// \param this LinkedList* Puntero a la lista
/// \param nodeIndex Indice del nodo a obtener
/// \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
/// 						(pNode) Si funciono correctamente
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode;
	pNode = NULL;

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) {
		pNode = this->pFirstNode;
		for (int i = 0; i < nodeIndex; i++) {
			pNode = pNode->pNextNode;
		}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/// \fn int addNode(LinkedList*, int, void*)
/// \brief Agrega y enlaza un nuevo nodo a la lista
/// \param this LinkedList* Puntero a la lista
/// \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
/// \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
/// \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
/// 					( 0) Si funciono correctamente
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux;
    Node* newNode;
    Node* nodeAux;
    returnAux = -1;

    if (this != NULL  && nodeIndex >= 0 && nodeIndex <= ll_len(this)) {
    	newNode = (Node*) malloc(sizeof(Node));
    	if (newNode != NULL) {
    		newNode->pElement = pElement;
        	if (nodeIndex == 0) {
        		newNode->pNextNode = this->pFirstNode;
        		this->pFirstNode = newNode;
        		returnAux = 0;
        	} else {
        		nodeAux = getNode(this, nodeIndex-1);
        		if (nodeAux != NULL) {
        			newNode->pNextNode = nodeAux->pNextNode;
            		nodeAux->pNextNode = newNode;
            		returnAux = 0;
        		} else {
        			free(newNode);
        		}
        	}
    	}

		if (returnAux == 0) {
			this->size = (this->size) + 1;
		}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/// \fn int ll_add(LinkedList*, void*)
/// \brief Agrega un elemento a la lista
/// \param this LinkedList* Puntero a la lista
/// \param pElement void* Puntero al elemento a ser agregado
/// \return int Retorna  (-1) Error: si el puntero a la lista es NULL
/// 					( 0) Si funciono correctamente
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux;
    int listSize;
    returnAux = -1;

    if (this != NULL) {
    	listSize = ll_len(this);
    	if (listSize != -1) {
    		returnAux = addNode(this, listSize, pElement);
    	}

    }

    return returnAux;
}

/// \fn void ll_get*(LinkedList*, int)
/// \brief Obtiene un elemento de la lista
/// \param this LinkedList* Puntero a la lista
/// \param index int Ubicacion del elemento a obtener
/// \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o si el indice es menor a 0 o mayor o igual al len de la lista
///                          (pElement) Si funciono correctamente
void* ll_get(LinkedList* this, int index)
{
    void* returnAux;
    Node* pNode;
    returnAux = NULL;

    if (this != NULL && index >= 0 && index < ll_len(this)) {
        pNode = getNode(this, index);
        if (pNode != NULL) {
        	returnAux = pNode->pElement;
        }
    }

    return returnAux;
}

/// \fn int ll_set(LinkedList*, int, void*)
/// \brief Modifica un elemento de la lista
/// \param this LinkedList* Puntero a la lista
/// \param index int Ubicacion del elemento a modificar
/// \param pElement void* Puntero al nuevo elemento
/// \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
/// 					( 0) Si funciono correctamente
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux;
    Node* pNode;
    returnAux = -1;

    if (this != NULL  && index >= 0 && index < ll_len(this)) {
        pNode = getNode(this, index);
        if (pNode != NULL) {
        	pNode->pElement = pElement;
        	returnAux = 0;
        }
    }

    return returnAux;
}

/// \fn int ll_remove(LinkedList*, int)
/// \brief Elimina un elemento de la lista
/// \param this LinkedList* Puntero a la lista
/// \param index int Ubicacion del elemento a eliminar
/// \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
///						( 0) Si funciono correctamente
int ll_remove(LinkedList* this,int index)
{
    int returnAux;
    Node* pNodeRemove;
    Node* pNodeAux;
    returnAux = -1;

    if (this != NULL && index >= 0 && index < ll_len(this)) {
        pNodeRemove = getNode(this, index);
        if (pNodeRemove != NULL) {
        	if (index == 0) {
         		this->pFirstNode = pNodeRemove->pNextNode;
        		returnAux = 0;
        	} else {
        		pNodeAux = getNode(this, index-1);
        		if (pNodeAux != NULL) {
            		pNodeAux->pNextNode = pNodeRemove->pNextNode;
            		returnAux = 0;
        		}
        	}

        	if (returnAux == 0) {
        		this->size = (this->size) - 1;
        		free(pNodeRemove);
        	}
        }
    }

    return returnAux;
}

/// \fn int ll_clear(LinkedList*)
/// \brief Elimina todos los elementos de la lista
/// \param this LinkedList* Puntero a la lista
/// \return int Retorna  (-1) Error: si el puntero a la lista es NULL
/// 					( 0) Si funciono correctamente
int ll_clear(LinkedList* this)
{
    int returnAux;
    int listSize;
    returnAux = -1;

    if (this != NULL) {
    	listSize = ll_len(this);

    	for (int i = 0; i < listSize; i++) {
        	if (ll_remove(this, 0) == -1) {
    			break;
    		}
    	}

    	if (ll_len(this) == 0) {
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/// \fn int ll_deleteLinkedList(LinkedList*)
/// \brief Elimina todos los elementos de la lista y la lista
/// \param this LinkedList* Puntero a la lista
/// \return int Retorna  (-1) Error: si el puntero a la lista es NULL
/// 					( 0) Si funciono correctamente
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux;
    returnAux = -1;

    if (this != NULL) {
    	if (ll_clear(this) == 0) {
    		free(this);
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/// \fn int ll_indexOf(LinkedList*, void*)
/// \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
/// \param this LinkedList* Puntero a la lista
/// \param pElement void* Puntero al elemento
/// \return int Retorna  (-1) Error: si el puntero a la lista es NULL
/// 					(indice del elemento) Si funciono correctamente
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux;
    int listSize;
    returnAux = -1;

    if (this != NULL ) {
    	listSize = ll_len(this);
    	if (listSize != -1) {
    		for (int i = 0; i < listSize; i++) {
    			if (pElement == ll_get(this, i)) {
    				returnAux = i;
    				break;
    			}
    		}
    	}
    }

    return returnAux;
}

/// \fn int ll_isEmpty(LinkedList*)
/// \brief Indica si la lista esta o no vacia
/// \param this LinkedList* Puntero a la lista
/// \return int Retorna  (-1) Error: si el puntero a la lista es NULL
///						 ( 0) Si la lista NO esta vacia
///                      ( 1) Si la lista esta vacia
int ll_isEmpty(LinkedList* this)
{
    int returnAux;
    int listSize;
    returnAux = -1;

    if (this != NULL) {
    	listSize = ll_len(this);
    	if (listSize != -1) {
        	returnAux = 0;
    		if (listSize == 0) {
    			returnAux = 1;
    		}
    	}
    }

    return returnAux;
}

/// \fn int ll_push(LinkedList*, int, void*)
/// \brief Inserta un nuevo elemento en la lista en la posicion indicada
/// \param this LinkedList* Puntero a la lista
/// \param index int Ubicacion donde se agregara el nuevo elemento
/// \param pElement void* Puntero al nuevo elemento
/// \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
/// 					( 0) Si funciono correctamente
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux;
    returnAux = -1;

    if (this != NULL && index >= 0 && index <= ll_len(this)) {
    	returnAux = addNode(this, index, pElement);
    }

    return returnAux;
}

/// \fn void ll_pop*(LinkedList*, int)
/// \brief Elimina el elemento de la posicion indicada y retorna su puntero
/// \param this LinkedList* Puntero a la lista
/// \param index int Ubicacion del elemento eliminar
/// \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
/// 						(pElement) Si funciono correctamente
void* ll_pop(LinkedList* this,int index)
{
    void* nodeAux;
    nodeAux = NULL;

    if (this != NULL && index >= 0 && index < ll_len(this)) {
    	nodeAux = ll_get(this, index);
    	if (nodeAux != NULL) {
    		if (ll_remove(this, index) == -1) {
    			nodeAux = NULL;
    		}
    	}
    }

    return nodeAux;
}

/// \fn int ll_contains(LinkedList*, void*)
/// \brief Determina si la lista contiene o no el elemento pasado como parametro
/// \param this LinkedList* Puntero a la lista
/// \param pElement void* Puntero del elemento a verificar
/// \return int Retorna  (-1) Error: si el puntero a la lista es NULL
///						 ( 1) Si contiene el elemento
///						 ( 0) si No contiene el elemento
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux;
    returnAux = -1;

    if (this != NULL) {
    	returnAux = 1;
    	if (ll_indexOf(this, pElement) == -1) {
        	returnAux = 0;
    	}
    }

    return returnAux;
}

/// \fn int ll_containsAll(LinkedList*, LinkedList*)
/// \brief Determina si todos los elementos de la lista (this2) estan contenidos en la lista (this)
/// \param this LinkedList* Puntero a la lista
/// \param this2 LinkedList* Puntero a la lista
/// \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
/// 					 ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
/// 					 ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux;
    int listSize2;
    int r;
    void* pElementAux;
    returnAux = -1;

    if (this != NULL && this2 != NULL) {
       	listSize2 = ll_len(this2);
       	if (listSize2 != -1) {
   			returnAux = 1;
       		for (int i = 0; i < listSize2; i++) {
               	pElementAux = ll_get(this2, i);
               	r = ll_contains(this, pElementAux);
               	if (r == -1 || r == 0) {
                 	returnAux = 0;
                  	break;
               	}
            }
       	}
    }

    return returnAux;
}

/// \fn LinkedList ll_subList*(LinkedList*, int, int)
/// \brief Crea y retorna una nueva lista con los elementos indicados
/// \param this LinkedList* Puntero a la lista
/// \param from int Indice desde el cual se copian los elementos en la nueva lista
/// \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
/// \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
///			o (si el indice from es menor a 0 o mayor al len de la lista)
///			o (si el indice to es menor o igual a from o mayor al len de la lista)
///			(puntero a la nueva lista) Si ok
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray;
    void* pElementAux;
    int listSize;
    cloneArray = NULL;

    if (this != NULL) {
    	listSize = ll_len(this);
    	if (listSize != -1 && from >= 0 && from < listSize && to > from && to <= listSize) {
    		cloneArray = ll_newLinkedList();
    		if (cloneArray != NULL) {
        		for (int i = from; i < to; i++) {
        			pElementAux = ll_get(this, i);
        			if (ll_add(cloneArray, pElementAux) == -1) {
        				ll_deleteLinkedList(cloneArray);
        				cloneArray = NULL;
        				break;
        			}
        		}
    		}

    	}
    }

    return cloneArray;
}

/// \fn LinkedList ll_clone*(LinkedList*)
/// \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
/// \param this LinkedList* Puntero a la lista
/// \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
///			(puntero a la nueva lista) Si ok
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray;
    int listSize;
    cloneArray = NULL;

    if (this != NULL) {
    	listSize = ll_len(this);
    	if (listSize != -1) {
        	cloneArray = ll_subList(this, 0, listSize);
    	}
    }

    return cloneArray;
}

/// \fn int ll_sort(LinkedList*, int(*)(void*, void*), int)
/// \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
/// \param this LinkedList* Puntero a la lista
/// \param pFunc (*pFunc) Puntero a la funcion criterio
/// \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
/// \return int Retorna  (-1) Error: si el puntero a la listas es NULL
///                      ( 0) Si ok
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux;
    int listSize;
    int r;
    void* pElement1;
    void* pElement2;
    void* pElementAux;
    returnAux = -1;

    if (this != NULL && pFunc != NULL && (order == 0 || order == 1)) {
    	listSize = ll_len(this);
    	for (int i = 0; i < listSize-1; i++) {
    		for (int j = i+1; j < listSize; j++) {
    			pElement1 = ll_get(this, i);
    			pElement2 = ll_get(this, j);
    			if (pElement1 != NULL && pElement2 != NULL) {
        			r = pFunc(pElement1, pElement2);
        			if ((order == 1 && r == 1) || (order == 0 && r == -1)) {
        				pElementAux = pElement1;
        				ll_set(this, i, pElement2);
        				ll_set(this, j, pElementAux);
        			}
    			}
    		}
    	}
    	returnAux = 0;
    }

    return returnAux;

}

/// \fn int ll_count(LinkedList*, int(*)(void*))
/// \brief Realiza un conteo sobre la LinkedList basandose en un criterio establecido por la función
/// puntero
/// \param this LinkedList* Puntero a la lista
/// \param pFunc (*pFunc) Puntero a la funcion criterio
/// \return Retorna el resultado del conteo
int ll_count(LinkedList* this, int (*pFunc)(void* element)) {
	int contador;
	int listSize;
	void* pElement;
	contador = 0;

	if (this != NULL && pFunc != NULL) {
		listSize = ll_len(this);
		if (listSize != -1 && listSize > 0) {
			for (int i = 0; i < listSize; i++) {
				pElement = ll_get(this, i);
				if (pElement != NULL) {
					contador += pFunc(pElement);
				}
			}
		}
	}

	return contador;
}

/// \fn LinkedList ll_filter*(LinkedList*, int(*)(void*))
/// \brief Crea una lista nueva basándose en un filtro establecido por la función puntero
/// \param this LinkedList* Puntero a la lista
/// \param pFunc (*pFunc) Puntero a la funcion criterio
/// \return Retorna la LinkedList creada a partir del filtro establecido previamente - NULL
/// si hubo un error por puntero nulo o si no se encontró espacio en memoria para crear la
/// lista
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* element)) {
	int listSize;
	int r;
	void* pElement;
	LinkedList* filterLinkedList;
	filterLinkedList = NULL;
	r = -1;

	if (this != NULL && pFunc != NULL) {
		listSize = ll_len(this);
		if (listSize > 0) {
			filterLinkedList = ll_newLinkedList();
			if (filterLinkedList != NULL) {
				for (int i = 0; i < listSize; i++) {
					pElement = ll_get(this, i);
					if (pElement != NULL && pFunc(pElement) == 1) {
						r = ll_add(filterLinkedList, pElement);
						if (r == -1) {
							ll_deleteLinkedList(filterLinkedList);
							filterLinkedList = NULL;
							break;
						}
					}

				}
			}

		}
	}

	return filterLinkedList;
}

int ll_map(LinkedList* this, int (*pFunc)(void*)) {
	int returnAux;
	void* pElement;
	int listSize;
	returnAux = -1;

	if (pFunc != NULL && this != NULL) {
		listSize = ll_len(this);
		for (int i = 0; i < listSize; i++) {
			pElement = ll_get(this, i);
			if (pElement != NULL) {
				returnAux = pFunc(pElement);
				if (returnAux == -1) {
					break;
				}
			}
		}
	}

	return returnAux;
}
