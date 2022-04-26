/*
 * >>>> CLASE 10 <<<<
 *
 * Desarrollar una aplicacion que permita gestionar una array de Clientes
 *
 * Se debera poder realizar
 * 	ALTAS
 * 	BAJAS
 * 	MODIFICACIONES
 *
 * La aplicacion debera permitir ordenar el array por Nombre del cliente
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "Contratacion.h"
#include "utn.h"
#include "Informes.h"
#define CANTIDAD_PANTALLAS 		100
#define CANTIDAD_CONTRATACIONES 1000

int main(void) {

	Contratacion arrayContrataciones[CANTIDAD_CONTRATACIONES];
	Pantalla arrayPantallas[CANTIDAD_PANTALLAS];
	int idPantallas=0;
	int idContrataciones=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;
	int auxiliarIdContratacion;
	int auxiliarIndiceContratacion;
	char auxiliarCuit[CUIT_LEN];


	if(pan_inicializarArray(arrayPantallas,CANTIDAD_PANTALLAS) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}

	if(cont_inicializarArray(arrayContrataciones,CANTIDAD_CONTRATACIONES) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}

	pan_altaForzadaArray(arrayPantallas,CANTIDAD_PANTALLAS,0,&idPantallas,"Pantalla 1","Zapiola 879", 12000.22,0);
	pan_altaForzadaArray(arrayPantallas,CANTIDAD_PANTALLAS,1,&idPantallas,"Pantalla 2","9 de julio 222", 22000.22,1);
	pan_altaForzadaArray(arrayPantallas,CANTIDAD_PANTALLAS,2,&idPantallas,"Pantalla 3","Mitre 750", 42000.22,0);

	cont_altaForzadaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,0,&idContrataciones,1,"Archivo1.mov","1234",2);
	cont_altaForzadaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,1,&idContrataciones,1,"Archivo2.mov","1234",10);
	cont_altaForzadaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,2,&idContrataciones,1,"Archivo3.mov","1234",20);
	cont_altaForzadaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,3,&idContrataciones,0,"Archivo4.mov","2222",2);
	cont_altaForzadaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,4,&idContrataciones,0,"Archivo5.mov","2222",10);
	cont_altaForzadaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,5,&idContrataciones,2,"Archivo6.mov","2222",20);
	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar una pantalla"
							"\n2.Modificar una pantalla"
							"\n3.Eliminar una pantalla"
							"\n4.Contratar una publicidad"
							"\n5.Modificar condiciones de publicacion"
							"\n6.Cancelar Contratacion"
							"\n7.Consulta facturación"
							"\n8.Imprimir contratacion"
							"\n9.Imprimir lista pantalla"
							"\n10.Informar"

							"\n11.Salir\n\n",

							"\nError opcion invalida",1,11,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = pan_getEmptyIndex(arrayPantallas,CANTIDAD_PANTALLAS);
				if(auxiliarIndice >= 0)
				{
					if(pan_altaArray(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarIndice,&idPantallas) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				pan_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del Panatalla a modificar","\nID invalido",0,idPantallas,0) == 0)
				{
					auxiliarIndice = pan_buscarId(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarId);
					if(	auxiliarIndice >= 0 &&
							pan_modificarArray(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				pan_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del Pantalla a eliminar","\nID invalido",0,idPantallas,0)==0)
				{
					auxiliarIndice = pan_buscarId(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarId);
					if(	auxiliarIndice >= 0 &&
							pan_bajaArray(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:

				auxiliarIndiceContratacion = cont_getEmptyIndex(arrayContrataciones,CANTIDAD_CONTRATACIONES);
				if(auxiliarIndiceContratacion >= 0)
				{
					pan_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);
					if(	utn_getNumero(&auxiliarId,"\nId Pantalla: ","\nError",0,10000,2) == 0 &&
						pan_buscarId(arrayPantallas,CANTIDAD_PANTALLAS,auxiliarId) != -1)
					{
						cont_altaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,auxiliarIndiceContratacion,&idContrataciones,auxiliarId);
					}
					else
					{
						printf("\nEL ID NO EXISTE");
					}
				}
				break;

				/*Se pedirá que se ingrese el cuit del cliente y se listaran todas las pantallas de
				video que el cliente tiene contratadas mostrando todos sus campos.
				Luego de ingresar el ID de la contratacion, se permitirá modificar la cantidad de días
				contratados para la misma.*/
			case 5:
				if(	!utn_getDni(auxiliarCuit,CUIT_LEN,"\n CUIT? ", "\nError", 2) &&
					!info_imprimirPantallasContratadasByCuit(arrayContrataciones,CANTIDAD_CONTRATACIONES,arrayPantallas,CANTIDAD_PANTALLAS,auxiliarCuit))
				{

					if(!utn_getNumero(&auxiliarIdContratacion,"\nID CONTRATACION A MODIFICAR? ","\nERROR",0,10000,2))
					{
						auxiliarIndiceContratacion = cont_buscarId(arrayContrataciones,CANTIDAD_CONTRATACIONES,auxiliarIdContratacion);
						if(auxiliarIndiceContratacion != -1)
						{
							cont_modificarArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,auxiliarIndiceContratacion);
						}
					}
				}
				else
				{
					printf("\nCUIT NO ENCONTRADO");
				}
				break;

			case 6:
				if(	!utn_getDni(auxiliarCuit,CUIT_LEN,"\n CUIT? ", "\nError", 2) &&
					!info_imprimirPantallasContratadasByCuit(arrayContrataciones,CANTIDAD_CONTRATACIONES,arrayPantallas,CANTIDAD_PANTALLAS,auxiliarCuit))
				{

					if(!utn_getNumero(&auxiliarIdContratacion,"\nID CONTRATACION A CANCELAR? ","\nERROR",0,10000,2))
					{
						auxiliarIndiceContratacion = cont_buscarId(arrayContrataciones,CANTIDAD_CONTRATACIONES,auxiliarIdContratacion);
						if(auxiliarIndiceContratacion != -1)
						{
							cont_bajaArray(arrayContrataciones,CANTIDAD_CONTRATACIONES,auxiliarIndiceContratacion);
						}
					}
				}
				else
				{
					printf("\nCUIT NO ENCONTRADO");
				}
				break;

			/*Consulta facturación: Se deberá ingresar el cuit del cliente y se deberá listar el importe
			a pagar por cada contratación.*/
			case 7:
				if(	!utn_getDni(auxiliarCuit,CUIT_LEN,"\n CUIT? ", "\nError", 2))
				{
					info_imprimirContratacionesConImporte(arrayContrataciones,CANTIDAD_CONTRATACIONES,arrayPantallas,CANTIDAD_PANTALLAS,auxiliarCuit);
				}
				break;

			case 10:
				info_imprimirContratacionesConImportePorCliente(arrayContrataciones,CANTIDAD_CONTRATACIONES,arrayPantallas,CANTIDAD_PANTALLAS);
				break;
			case 14:
				pan_ordenarPorNombre(arrayPantallas,CANTIDAD_PANTALLAS);
				break;

			case 8:
				cont_imprimirArray(arrayContrataciones,CANTIDAD_CONTRATACIONES);
				break;
			case 9:
				pan_imprimirArray(arrayPantallas,CANTIDAD_PANTALLAS);
				break;

			}
		}
	}while(opcion != 11);

	return EXIT_SUCCESS;
}




