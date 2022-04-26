/*
 * Informes.c
 *
 *  Created on: May 5, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantalla.h"
#include "Contratacion.h"
#include "utn.h"
#include "Informes.h"
static const char TXT_TIPOS[2][4]={"LCD","LED"};

int info_imprimirPantallasContratadasByCuit(Contratacion* arrayContrataciones,int limiteContrataciones,Pantalla* arrayPantallas,int limitePantallas,char* auxiliarCuit)
{
	int retorno = -1;
	int i;
	int indiceArrayPantalla;
	int idPantalla;
	if(arrayContrataciones != NULL && limiteContrataciones > 0 && arrayPantallas != NULL && limitePantallas > 0 && auxiliarCuit != NULL)
	{
		for(i=0;i<limiteContrataciones;i++)
		{
			if(arrayContrataciones[i].isEmpty == 0 && strncmp(arrayContrataciones[i].cuit,auxiliarCuit,CUIT_LEN) == 0)
			{
				retorno = 0;
				idPantalla = arrayContrataciones[i].idPantalla;
				indiceArrayPantalla = pan_buscarId(arrayPantallas,limitePantallas,idPantalla);

				printf("\nID: %d - Archivo: %s - Cuit: %s - Dias: %d - IdPantalla: %d",arrayContrataciones[i].id,arrayContrataciones[i].archivo,arrayContrataciones[i].cuit,arrayContrataciones[i].dias,arrayContrataciones[i].idPantalla);
				printf(" - %s - %s - %.2f - %s",arrayPantallas[indiceArrayPantalla].nombre,arrayPantallas[indiceArrayPantalla].direccion,arrayPantallas[indiceArrayPantalla].precio,TXT_TIPOS[arrayPantallas[indiceArrayPantalla].tipo]);
			}
		}
	}
	return retorno;
}


int info_imprimirContratacionesConImporte(Contratacion* arrayContrataciones,int limiteContrataciones,Pantalla* arrayPantallas,int limitePantallas,char* auxiliarCuit)
{
	int retorno = -1;
	int i;
	int indiceArrayPantalla;
	int idPantalla;
	float auxiliarImporte;
	if(arrayContrataciones != NULL && limiteContrataciones > 0 && arrayPantallas != NULL && limitePantallas > 0 && auxiliarCuit != NULL)
	{
		for(i=0;i<limiteContrataciones;i++)
		{
			if(arrayContrataciones[i].isEmpty)
			{
				continue;
			}
			if(strncmp(arrayContrataciones[i].cuit,auxiliarCuit,CUIT_LEN) == 0)
			{
				retorno = 0;
				idPantalla = arrayContrataciones[i].idPantalla;
				indiceArrayPantalla = pan_buscarId(arrayPantallas,limitePantallas,idPantalla);
				auxiliarImporte = arrayContrataciones[i].dias * arrayPantallas[indiceArrayPantalla].precio;
				printf("\nID: %d - Archivo: %s - Cuit: %s - Dias: %d - IdPantalla: %d - Importe %.2f"
															,arrayContrataciones[i].id
															,arrayContrataciones[i].archivo
															,arrayContrataciones[i].cuit
															,arrayContrataciones[i].dias
															,arrayContrataciones[i].idPantalla
															,auxiliarImporte);
			}
		}
	}
	return retorno;
}

#define CANTIDAD_CLIENTES 1000

int info_imprimirContratacionesConImportePorCliente(Contratacion* arrayContrataciones,int limiteContrataciones,Pantalla* arrayPantallas,int limitePantallas)
{

	int retorno = -1;
	char listaCuit[CANTIDAD_CLIENTES][CUIT_LEN];
	int i;
	int j;
	int flagExisteCuit;
	int indiceCuitLibre = 0;
	float auxiliarDeuda;
	float deudaMaxima;
	int indiceClienteDeudaMaxima;

	for(i=0;i<limiteContrataciones;i++)
	{
		flagExisteCuit = 0;
		if(arrayContrataciones[i].isEmpty == 0)
		{
			for(j=0;j<indiceCuitLibre;j++)
			{
				if(strncmp(arrayContrataciones[i].cuit,listaCuit[j],CUIT_LEN ) == 0)
				{
					flagExisteCuit = 1;
					break;
				}
			}
			if(flagExisteCuit == 0)
			{
				strncpy(listaCuit[indiceCuitLibre],arrayContrataciones[i].cuit,CUIT_LEN);
				indiceCuitLibre++;
			}
		}
	}

	for(j=0;j<indiceCuitLibre;j++)
	{
		printf("\n\n El cliente con cuit %s\n",listaCuit[j]);
		info_imprimirContratacionesConImporte(arrayContrataciones,limiteContrataciones,arrayPantallas,limitePantallas,listaCuit[j]);
	}



	for(j=0;j<indiceCuitLibre;j++)
	{

		info_calcularDeudaCliente(arrayContrataciones,limiteContrataciones,arrayPantallas,limitePantallas,listaCuit[j], &auxiliarDeuda);
		if(j == 0|| (auxiliarDeuda > deudaMaxima))
		{
			deudaMaxima = auxiliarDeuda;
			indiceClienteDeudaMaxima = 	j;
		}

	}
	printf("\n\n El cliente con mas deuda es cuit %s - debe %.2f\n",listaCuit[indiceClienteDeudaMaxima],deudaMaxima);

	return retorno;



}


int info_calcularDeudaCliente(Contratacion* arrayContrataciones,int limiteContrataciones,Pantalla* arrayPantallas,int limitePantallas,char* auxiliarCuit, float* deuda)
{
	int retorno = -1;
	int i;
	int indiceArrayPantalla;
	int idPantalla;
	float auxiliarDeuda=0;
	if(arrayContrataciones != NULL && limiteContrataciones > 0 && arrayPantallas != NULL && limitePantallas > 0 && auxiliarCuit != NULL)
	{
		for(i=0;i<limiteContrataciones;i++)
		{
			if(arrayContrataciones[i].isEmpty)
			{
				continue;
			}
			if(strncmp(arrayContrataciones[i].cuit,auxiliarCuit,CUIT_LEN) == 0)
			{
				idPantalla = arrayContrataciones[i].idPantalla;
				indiceArrayPantalla = pan_buscarId(arrayPantallas,limitePantallas,idPantalla);
				auxiliarDeuda = auxiliarDeuda + (arrayContrataciones[i].dias * arrayPantallas[indiceArrayPantalla].precio);
			}
		}
		retorno = 0;
		*deuda=auxiliarDeuda;
	}
	return retorno;
}




