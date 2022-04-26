#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Contratacion.h"
#include "utn.h"

/**
 * \brief Imprime los datos de un contratacion
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cont_imprimir(Contratacion* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - Archivo: %s - Cuit: %s - Dias: %d - IdPantalla: %d",pElemento->id,pElemento->archivo,pElemento->cuit,pElemento->dias,pElemento->idPantalla);
	}
	return retorno;
}

/**
 * \brief Imprime el array de contrataciones
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cont_imprimirArray(Contratacion* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			cont_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cont_inicializarArray(Contratacion* array,int limite)
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
 * \brief Da de alta un contratacion en una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al contratacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cont_altaArray(Contratacion* array,int limite, int indice, int* idContratacion, int idPantalla)
{
	int respuesta = -1;
	Contratacion bufferContratacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idContratacion != NULL)
	{
		if(	!utn_getDni(bufferContratacion.cuit,CUIT_LEN,"\n CUIT? ", "\nError", 2) &&
			!utn_getNumero(&bufferContratacion.dias,"\n DIAS? ", "\nError",1,365,2) &&
			!utn_getDescripcion(bufferContratacion.archivo,ARCHIVO_LEN,"\nArchivo? ", "\nError",2))
		{
			respuesta = 0;
			bufferContratacion.idPantalla = idPantalla;
			bufferContratacion.id = *idContratacion;
			bufferContratacion.isEmpty = 0;
			array[indice] = bufferContratacion;
			(*idContratacion)++;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un contratacion en una posicion del array de manera forzada
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al contratacion
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cont_altaForzadaArray(Contratacion* array,int limite, int indice, int* idContratacion, int idPantalla,char* archivo,char* cuit,int dias)
{
	int respuesta = -1;
	Contratacion bufferContratacion;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && idContratacion != NULL)
	{
		strncpy(bufferContratacion.archivo,archivo,ARCHIVO_LEN);
		strncpy(bufferContratacion.cuit,cuit,CUIT_LEN);
		bufferContratacion.dias = dias;
		bufferContratacion.idPantalla = idPantalla;
		respuesta = 0;
		bufferContratacion.id = *idContratacion;
		bufferContratacion.isEmpty = 0;
		array[indice] = bufferContratacion;
		(*idContratacion)++;

	}
	return respuesta;
}


/**
 * \brief Actualiza los datos de un contratacion en una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cont_modificarArray(Contratacion* array,int limite, int indice)
{
	int respuesta = -1;
	int  dias;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		if(	!utn_getNumero(&dias,"\n DIAS? ", "\nError",1,365,2))
		{
			respuesta = 0;
			array[indice].dias = dias;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de contrataciones a ser actualizado
 * \param limite Limite del array de contrataciones
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cont_bajaArray(Contratacion* array,int limite, int indice)
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
* \param array contratacion Array de contratacion
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cont_buscarId(Contratacion array[], int limite, int valorBuscado)
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
 * \param array Array de contrataciones
 * \param limite Limite del array de contrataciones
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int cont_getEmptyIndex(Contratacion* array,int limite)
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













