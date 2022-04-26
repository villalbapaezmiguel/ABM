/*
 * Cliente.c
 *
 *  Created on: 28 oct. 2021
 *      Author: miguel
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "string.h"
#include "Contratacion.h"
#include "Pantalla.h"

static int nuevoIdContratacion(void);

int inicializar_contratacion(Contratacion* contratacion , int len)
{
	int retorno = -1;

	if(contratacion != NULL && len >0)
	{
		for (int i = 0; i < len; ++i) {

			contratacion[i].isEmpty = VACIO ;
			retorno = 1;
		}
	}

	return retorno;
}

int buscarLugarLIbre_contratacion(Contratacion* clientes , int len , int* lugarLibre)
{
	int retorno = -1;

	if(clientes != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(clientes[i].isEmpty == VACIO )
			{
				*lugarLibre = i;
				retorno = 1;
				break;
			}
		}
	}

	return retorno ;
}

int pedirDatos_contratacion(Contratacion* contratacion , int len , int lugarLibre, int idPantalla )
{
	int retorno =-1;

	char auxNombreArchivo [NOMBRE_LEN];
//	char auxDni [CUIT_LEN];
//	float auxAltura ;
	char auxCuit[CUIT_LEN];
	int auxDias ;

	int controlador ;

	if(contratacion != NULL && len > 0)
	{
		if(contratacion[lugarLibre].isEmpty == VACIO)
		{
			controlador = utn_getDni(auxCuit, CUIT_LEN,"\nIngrese el cuit del cliente :", "\nERROR ", 2);
			while(controlador != 0)
			{
				controlador = utn_getDni(auxCuit, CUIT_LEN,"\nIngrese el cuit del cliente :", "\nERROR ", 2);
			}
			controlador = utn_getNumero(&auxDias, "\nIngrese la cantidad de dias que dura la publicacion (1 a 100):", "\nERROR ", 1, 100, 2);
			while(controlador != 0)
			{
				controlador = utn_getNumero(&auxDias, "\nIngrese la cantidad de dias que dura la publicacion :", "\nERROR ", 1, 100, 2);
			}
			controlador = utn_getDescripcion(auxNombreArchivo, CUIT_LEN, "\nIngrese nombre de archivo de video (ejem. Video 1.avi) :", "\nEEROR", 2);
			while(controlador != 0)
			{
				controlador = utn_getDescripcion(auxNombreArchivo, CUIT_LEN, "\nIngrese nombre de archivo de video (ejem. Video 1.avi) :", "\nEEROR", 2);
			}

			strncpy(contratacion[lugarLibre].cuit, auxCuit , sizeof(contratacion[lugarLibre].cuit));
			strncpy(contratacion[lugarLibre].archivo, auxNombreArchivo , sizeof(contratacion[lugarLibre].archivo));
			contratacion[lugarLibre].dias = auxDias;
			contratacion[lugarLibre].isEmpty = OCUPADO ;
			contratacion[lugarLibre].id = nuevoIdContratacion();
			contratacion[lugarLibre].idPantallas = idPantalla ;
			retorno = 1;



//			controlador = utn_getNombre(auxNombreArchivo, NOMBRE_LEN, "\nIngrese su nombre :","\nERROR", 2);
//			while(controlador != 0)
//			{
//				controlador = utn_getNombre(auxNombreArchivo, NOMBRE_LEN, "\nIngrese su nombre :","\nERROR", 2);
//			}
//			controlador = utn_getDescripcion(auxDni, CUIT_LEN, "\nIngrese DNI :", "\nEEROR", 2);
//			while(controlador != 0)
//			{
//				controlador = utn_getDescripcion(auxDni, CUIT_LEN, "\nIngrese DNI :", "\nEEROR", 2);
//			}
////			controlador = utn_getNumero(auxDni, "\nIngrese DNI :", "\nEEROR", 0, 100000, 2);
////			while(controlador != 0)
////			{
////				controlador = utn_getNumero(auxDni, "\nIngrese DNI :", "\nEEROR", 0, 100000, 2);
////			}
//			controlador = utn_getNumeroFlotante(&auxAltura, "\nIngrese altura :", "\nERROR ", 0.0, 3.14, 2);
//			while(controlador != 0)
//			{
//				controlador = utn_getNumeroFlotante(&auxAltura, "\nIngrese altura :", "\nERROR ", 0.0, 3.14, 2);
//			}
//
//			strncpy(contratacion[lugarLibre].archivo, auxNombreArchivo , sizeof(contratacion[lugarLibre].archivo));
//			strncpy(contratacion[lugarLibre].cuit, auxDni , sizeof(contratacion[lugarLibre].cuit));
//			//clientes[lugarLibre].altura = auxAltura ;


		}else{
			printf("\nEste luegar ya esta ocupado");
		}

	}

	return retorno;
}


static int nuevoIdContratacion(void)
{
	static int contador =0;

	return (contador++);
}

int buscarPorId_contratacion(Contratacion* contratacion , int len , int id , int* idPosicion )
{
	int retorno = -1;

	if(contratacion != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(contratacion[i].id == id )
			{
				*idPosicion = i;
				retorno = 1;
				break ;
			}
		}
	}

	return retorno;
}

int baja_contratacion(Contratacion* contratacion , int len , int* idBaja)
{
	int retorno = -1;

	if(contratacion != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(contratacion[i].id == *idBaja)
			{
				contratacion[i].isEmpty = VACIO ;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int modificar_contratacion(Contratacion* contratacion , int len , int idModificar , int posicionModificar , Pantalla* pantalla , int lenPantalla)
{
	int retorno = -1;
	int controlador ;
	int auxDias ;

	if((contratacion != NULL && len > 0) && (pantalla != NULL && lenPantalla > 0))
	{
		if(contratacion[posicionModificar].isEmpty == OCUPADO && pantalla[posicionModificar].id == idModificar)
		{

			controlador = utn_getNumero(&auxDias, "\nIngrese la cantidad de dias que dura la publicacion (1 a 100):", "\nERROR ", 1, 100, 2);
			while(controlador != 0)
			{
				controlador = utn_getNumero(&auxDias, "\nIngrese la cantidad de dias que dura la publicacion :", "\nERROR ", 1, 100, 2);
			}
			contratacion[posicionModificar].dias = auxDias;
			retorno = 1;

		}else{
			printf("\nNO EXISTE !!");
		}
	}

	return retorno;
}

int imprimir_contratacion(Contratacion* contratacion , int len )
{
	int retorno = -1;

	if(contratacion != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(contratacion[i].isEmpty == OCUPADO)
			{
				printf("\nID : %d || Archivo : %s || Cuit del cliente : %s ||  IdPantlla : %d || Dias : %d",contratacion[i].id , contratacion[i].archivo,contratacion[i].cuit , contratacion[i].idPantallas , contratacion[i].dias);

				retorno = 1;
			}
		}
	}

	return retorno;
}

int ordenarPorNombre_contratacion(Contratacion* clientes , int len)
{
	int retorno = -1;
	int flagSwap;
	Contratacion buffer ;

	if(clientes != NULL && len > 0)
	{
		retorno= 1;
		do
		{
			flagSwap = 0;
			for (int i = 0; i < len; ++i) {

				if(clientes[i].isEmpty || clientes[i+1].isEmpty)
				{
					continue ;
				}
				if(strncmp(clientes[i].archivo ,clientes[i+1].archivo , NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = clientes[i];
					clientes[i] = clientes[i+1];
					clientes[i+1] = buffer ;
				}
			}
			len--;
		}while(flagSwap);
	}

	return retorno;
}

int ordenarPorNombre_o_Dias_contratacion(Contratacion* clientes , int len)
{
	int retorno = -1;
	int flagSwap;
	Contratacion buffer ;

	if(clientes != NULL && len > 0)
	{
		retorno =1;
		do
		{
			flagSwap = 0;
			for (int i = 0; i < len; ++i) {

//				if(strncmp(clientes[i].nombrer ,clientes[i+1].nombrer , NOMBRE_LEN) > 0)//TAMBIEN FUNCIONA
//				{
//					flagSwap = 1;
//					buffer = clientes[i];
//					clientes[i] = clientes[i+1];
//					clientes[i+1] = buffer ;
//
//				}else if(strncmp(clientes[i].nombrer ,clientes[i+1].nombrer , NOMBRE_LEN) == 0)
//				{
//					if(clientes[i].altura < clientes[i+1])
//					{
//						flagSwap = 1;
//						buffer = clientes[i];
//						clientes[i] = clientes[i+1];
//						clientes[i+1] = buffer ;
//					}
//				}
				if(clientes[i].isEmpty || clientes[i+1].isEmpty)
				{
					continue ;
				}
				int auxiliarCoparacion = strncmp(clientes[i].archivo ,clientes[i+1].archivo , NOMBRE_LEN);
				if( auxiliarCoparacion > 0 ||
				(auxiliarCoparacion == 0 && clientes[i].dias < clientes[i+1].dias))
				{
					flagSwap = 1;
					buffer = clientes[i];
					clientes[i] = clientes[i+1];
					clientes[i+1] = buffer ;
				}
			}
			len--;
		}while(flagSwap);
	}

	return retorno;
}


int pedirDatos_contratacionForzada(Contratacion* contratacion , int len , int lugarLibre ,int* idPantallaContratacion ,int idPantalla,char* archivo,char* cuit, int dias)
{
	int retorno =-1;

	Contratacion bufferContratacion ;

	if(contratacion != NULL && len > 0)
	{
		strncpy(bufferContratacion.archivo , archivo , sizeof(bufferContratacion.archivo));
		strncpy(bufferContratacion.cuit , cuit , sizeof(bufferContratacion.cuit));
		bufferContratacion.dias = dias;
		bufferContratacion.idPantallas = idPantalla;
		bufferContratacion.id = nuevoIdContratacion();
		bufferContratacion.isEmpty = OCUPADO;
		contratacion[lugarLibre] = bufferContratacion ;
		retorno = 1;
		/*int* idPantallaContratacion : es inecesario porque notros ya tenemos una funcion que incremanta el Id de contratacion
		 * en el video lo ponia porque el todavia no habia creado una funcion para incrementar el ID .
		 * asi que si no entendes el porque lo hicimos es porque nosotros ya tenemos una funcion que genera un nuevo id  de contratacion,
		 * lo podriamos quitar como parametro y no pasaria nada */
	}

	return retorno;
}



