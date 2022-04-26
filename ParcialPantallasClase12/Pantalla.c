#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pantalla.h"
#include "utn.h"

static const char TXT_TIPOS[2][4]={"LCD","LED"};

/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_imprimir(Pantalla* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - %.2f - %s",pElemento->id,pElemento->nombre,pElemento->direccion,pElemento->precio,TXT_TIPOS[pElemento->tipo]);
	}
	return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_imprimirArray(Pantalla* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			pan_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_inicializarArray(Pantalla* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_altaArray(Pantalla* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Pantalla bufferPantalla;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferPantalla.nombre,NOMBRE_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getDescripcion(bufferPantalla.direccion,DIRECCION_LEN,"\nDireccion?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferPantalla.precio,"\nPrecio?\n","\nERROR\n",0,10000,2) == 0 &&
			utn_getNumero(&bufferPantalla.tipo,"Ingrese tipo [0:LCD 1:LED]:","No!",0,1,2)==0)
		{
			respuesta = 0;
			bufferPantalla.id = *id;
			bufferPantalla.isEmpty = 0;
			array[indice] = bufferPantalla;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_modificarArray(Pantalla* array,int limite, int indice)
{
	int respuesta = -1;
	Pantalla bufferPantalla;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferPantalla.nombre,NOMBRE_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getDescripcion(bufferPantalla.direccion,DIRECCION_LEN,"\nDireccion?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferPantalla.precio,"\nPrecio?\n","\nERROR\n",0,10000,2) == 0 &&
			utn_getNumero(&bufferPantalla.tipo,"Ingrese tipo [0:LCD 1:LED]:","No!",0,1,2)==0)
		{
			respuesta = 0;
			bufferPantalla.id = array[indice].id;
			bufferPantalla.isEmpty = 0;
			array[indice] = bufferPantalla;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_bajaArray(Pantalla* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pan_buscarId(Pantalla array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int pan_getEmptyIndex(Pantalla* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de clientes por nombre
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int pan_ordenarPorNombre(Pantalla* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Pantalla buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}


/**
 * \brief Ordenar el array de clientes por nombre y altura
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int pan_ordenarPorNombrePrecio(Pantalla* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Pantalla buffer;
	int auxiliarCmp;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
/*
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
				else if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) == 0)
				{
					if(array[i].altura < array[i+1].altura)
					{
						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i+1];
						array[i+1]=buffer;
					}
				}
*/
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN);
				if(	 auxiliarCmp > 0 ||
					(auxiliarCmp == 0 && array[i].precio < array[i+1].precio) )
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}



/**
 * \brief Da de alta una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array de pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pan_altaForzadaArray(Pantalla* array,int limite, int indice, int* id,char* nombre,char* direccion, float precio ,int tipo)

{
	int respuesta = -1;
	Pantalla bufferPantalla;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
			strncpy(bufferPantalla.nombre,nombre,NOMBRE_LEN);
			strncpy(bufferPantalla.direccion,direccion,DIRECCION_LEN);
			bufferPantalla.precio = precio;
			bufferPantalla.tipo = tipo;
			respuesta = 0;
			bufferPantalla.id = *id;
			bufferPantalla.isEmpty = 0;
			array[indice] = bufferPantalla;
			(*id)++;
	}
	return respuesta;
}
















