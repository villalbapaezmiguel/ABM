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
#include "Pantalla.h"

static int nuevoId(void);

int inicializar(Pantalla* pantalla , int len)
{
	int retorno = -1;

	if(pantalla != NULL && len >0)
	{
		for (int i = 0; i < len; ++i) {

			pantalla[i].isEmpty = VACIO ;
			retorno = 1;
		}
	}

	return retorno;
}

int buscarLugarLIbre(Pantalla* pantalla , int len , int* lugarLibre)
{
	int retorno = -1;

	if(pantalla != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(pantalla[i].isEmpty == VACIO )
			{
				*lugarLibre = i;
				retorno = 1;
				break;
			}
		}
	}

	return retorno ;
}

/*\brief Da de alta una pantalla en una posicion del array
 *\param pantalla es el array de pantallas a ser actualizado
 *\param len limite del array pantalla
 *\param lugarLibre es el lugar donde va a estar libre y podamos cargar los datos al usuario
 *\return retorna 1 si todo salio bien y -1 si hay un error*/
int pedirDatos(Pantalla* pantalla , int len , int lugarLibre)
{
	int retorno =-1;
	char auxNombre [NOMBRE_LEN];
	char auxDireccion [DIRECCION_LEN];
	int auxPrecio ;
	int auxTipo ;

	int controlador ;

	if(pantalla != NULL && len > 0)
	{
		if(pantalla[lugarLibre].isEmpty == VACIO)
		{
			controlador = utn_getNombre(auxNombre, NOMBRE_LEN, "\nIngrese el nombre :","\nERROR", 2);
			while(controlador != 0)
			{
				controlador = utn_getNombre(auxNombre, NOMBRE_LEN, "\nIngrese el nombre :","\nERROR", 2);
			}
			controlador = utn_getDescripcion(auxDireccion, DIRECCION_LEN, "\nIngrese direccion :", "\nEEROR", 2);
			while(controlador != 0)
			{
				controlador = utn_getDescripcion(auxDireccion, DIRECCION_LEN, "\nIngrese direccion :", "\nEEROR", 2);
			}
//			controlador = utn_getNumero(auxDni, "\nIngrese DNI :", "\nEEROR", 0, 100000, 2);
//			while(controlador != 0)
//			{
//				controlador = utn_getNumero(auxDni, "\nIngrese DNI :", "\nEEROR", 0, 100000, 2);
//			}
			controlador = utn_getNumero(&auxPrecio, "\nIngrese precio (entre 1 y 1000):", "\nERROR ", 1, 1000, 2);
			while(controlador != 0)
			{
				controlador = utn_getNumero(&auxPrecio, "\nIngrese precio (entre 1 y 1000):", "\nERROR ", 1, 1000, 2);
			}

			controlador = utn_getNumero(&auxTipo, "\nIngrese tipo (1- LCD || 2- LED) :", "\nerror", 1, 2, 2);
			while(controlador != 0)
			{
				controlador = utn_getNumero(&auxTipo, "\nIngrese tipo (1- LCD || 2- LED) :", "\nerror", 1, 2, 2);
			}

			switch(auxTipo)
			{
			case 1 :
				strncpy(pantalla[lugarLibre].nombre, auxNombre , sizeof(pantalla[lugarLibre].nombre));
				strncpy(pantalla[lugarLibre].direccion, auxDireccion , sizeof(pantalla[lugarLibre].direccion));
				pantalla[lugarLibre].precio = auxPrecio ;
				pantalla[lugarLibre].isEmpty = OCUPADO ;
				pantalla[lugarLibre].id = nuevoId() ;
				pantalla[lugarLibre].tipo = TIPO_LCD;
				retorno = 1;
				break;
			case 2:
				strncpy(pantalla[lugarLibre].nombre, auxNombre , sizeof(pantalla[lugarLibre].nombre));
				strncpy(pantalla[lugarLibre].direccion, auxDireccion , sizeof(pantalla[lugarLibre].direccion));
				pantalla[lugarLibre].precio = auxPrecio ;
				pantalla[lugarLibre].isEmpty = OCUPADO ;
				pantalla[lugarLibre].id = nuevoId() ;
				pantalla[lugarLibre].tipo = TIPO_LED;
				retorno = 1;
				break;
			}



		}else{
			printf("\nEste luegar ya esta ocupado");
		}

	}

	return retorno;
}


static int nuevoId(void)
{
	static int contador =0;

	return (contador++);
}

int buscarPorId(Pantalla* pantalla , int len , int id , int* idPosicion)
{
	int retorno = -1;

	if(pantalla != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(pantalla[i].id == id)
			{
				*idPosicion = i;
				retorno = 1;
				break ;
			}
		}
	}

	return retorno;
}

int baja(Pantalla* pantalla , int len , int* idBaja)
{
	int retorno = -1;

	if(pantalla != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(pantalla[i].id == *idBaja)
			{
				pantalla[i].isEmpty = VACIO ;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int modificar(Pantalla* pantalla , int len , int idModificar , int posicionModificar)
{
	int retorno = -1;
	int controlador ;
//	Cliente auxiliarCliente ;
	char auxNombre [NOMBRE_LEN];
	char auxDireccion [DIRECCION_LEN];
	int auxPrecio ;
	int auxTipo;

	if(pantalla != NULL && len > 0)
	{
		if(pantalla[posicionModificar].isEmpty == OCUPADO)
		{
			controlador = utn_getNombre(auxNombre, NOMBRE_LEN, "\nIngrese su nuevo nombre :","\nERROR", 2);
			while(controlador != 0)
			{
				controlador = utn_getNombre(auxNombre, NOMBRE_LEN, "\nIngrese su nuevo nombre :","\nERROR", 2);
			}
			controlador = utn_getDescripcion(auxDireccion, DIRECCION_LEN, "\nIngrese nueva Direccion :", "\nEEROR", 2);
			while(controlador != 0)
			{
				controlador = utn_getDescripcion(auxDireccion, DIRECCION_LEN, "\nIngrese nueva Direccion :", "\nEEROR", 2);
			}
			controlador = utn_getNumero(&auxPrecio, "\nIngrese nuevo precio (entre 1 y 1000):", "\nERROR ", 1, 10000, 2);
			while(controlador != 0)
			{
				controlador = utn_getNumero(&auxPrecio, "\nIngrese nuevo precio (entre 1 y 1000):", "\nERROR ", 1, 1000, 2);
			}

			controlador = utn_getNumero(&auxTipo, "\nIngrese nuevo tipo (1- LCD || 2- LED) :", "\nerror", 1, 2, 2);
			while(controlador != 0)
			{
				controlador = utn_getNumero(&auxTipo, "\nIngrese nuevo tipo (1- LCD || 2- LED) :", "\nerror", 1, 2, 2);
			}

			switch(auxTipo)
			{
			case 1 :
				strncpy(pantalla[posicionModificar].nombre, auxNombre , sizeof(pantalla[posicionModificar].nombre));
				strncpy(pantalla[posicionModificar].direccion, auxDireccion , sizeof(pantalla[posicionModificar].direccion));
				pantalla[posicionModificar].precio = auxPrecio ;
				pantalla[posicionModificar].isEmpty = OCUPADO ;
				pantalla[posicionModificar].id = nuevoId() ;
				pantalla[posicionModificar].tipo = TIPO_LCD;
				retorno = 1;
				break;
			case 2:
				strncpy(pantalla[posicionModificar].nombre, auxNombre , sizeof(pantalla[posicionModificar].nombre));
				strncpy(pantalla[posicionModificar].direccion, auxDireccion , sizeof(pantalla[posicionModificar].direccion));
				pantalla[posicionModificar].precio = auxPrecio ;
				pantalla[posicionModificar].isEmpty = OCUPADO ;
				pantalla[posicionModificar].id = nuevoId() ;
				pantalla[posicionModificar].tipo = TIPO_LED;
				retorno = 1;
				break;
			}

//		//	clientes[posicionModificar] = auxiliarCliente ;//creo que modificar tiene un problema
//			strncpy(pantalla[posicionModificar].nombre, auxNombre , sizeof(pantalla[posicionModificar].nombre));
//			strncpy(pantalla[posicionModificar].direccion, auxDireccion , sizeof(pantalla[posicionModificar].direccion));
//			pantalla[posicionModificar].precio = auxPrecio ;
//			retorno = 1;



		}else{
			printf("\nNO EXISTE !!");
		}
	}

	return retorno;
}

int imprimir(Pantalla* pantalla , int len )
{
	int retorno = -1;
	char auxTipo [30];
	if(pantalla != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(pantalla[i].isEmpty == OCUPADO)
			{
				//opcion uno :
//				switch(pantalla[i].tipo)
//				{
//				case 1:
//
//					printf("\nNombre : %s || Direccion : %s || Precio : %f || ID : %d || Tipo : LCD ",pantalla[i].nombre , pantalla[i].direccion, pantalla[i].precio , pantalla[i].id);
//					retorno = 1;
//
//					break;
//				case 2:
//					printf("\nNombre : %s || Direccion : %s || Precio : %f || ID : %d || Tipo : LED ",pantalla[i].nombre , pantalla[i].direccion, pantalla[i].precio , pantalla[i].id);
//					retorno = 1;
//
//					break;
//				}
				//opcion dos :
				switch(pantalla[i].tipo)
				{
				case TIPO_LCD:
					strncpy(auxTipo , "LCD", sizeof(auxTipo));

					break;
				case TIPO_LED:
					strncpy(auxTipo , "LED", sizeof(auxTipo));

					break;
				}
				printf("\nNombre : %s || Direccion : %s || Precio : %f || ID : %d || Tipo : %s ",pantalla[i].nombre , pantalla[i].direccion, pantalla[i].precio , pantalla[i].id , auxTipo );
				retorno =1;
			}
		}
	}
	return retorno;
}

int ordenarPorNombre(Pantalla* pantalla , int len)
{
	int retorno = -1;
	int flagSwap;
	Pantalla buffer ;

	if(pantalla != NULL && len > 0)
	{
		retorno= 1;
		do
		{
			flagSwap = 0;
			for (int i = 0; i < len; ++i) {

				if(pantalla[i].isEmpty || pantalla[i+1].isEmpty)
				{
					continue ;
				}
				if(strncmp(pantalla[i].nombre ,pantalla[i+1].nombre , NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = pantalla[i];
					pantalla[i] = pantalla[i+1];
					pantalla[i+1] = buffer ;
				}
			}
			len--;
		}while(flagSwap);
	}

	return retorno;
}

int ordenarPorNombre_o_Precio(Pantalla* pantalla , int len)
{
	int retorno = -1;
	int flagSwap;
	Pantalla buffer ;

	if(pantalla != NULL && len > 0)
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
				if(pantalla[i].isEmpty || pantalla[i+1].isEmpty)
				{
					continue ;
				}
				int auxiliarCoparacion = strncmp(pantalla[i].nombre ,pantalla[i+1].nombre , NOMBRE_LEN);
				if( auxiliarCoparacion > 0 ||
				(auxiliarCoparacion == 0 && pantalla[i].precio < pantalla[i+1].precio))
				{
					flagSwap = 1;
					buffer = pantalla[i];
					pantalla[i] = pantalla[i+1];
					pantalla[i+1] = buffer ;
				}
			}
			len--;
		}while(flagSwap);
	}

	return retorno;
}


/*\brief Da de alta una pantalla en una posicion del array
 *\param pantalla es el array de pantallas a ser actualizado
 *\param len limite del array pantalla
 *\param lugarLibre es el lugar donde va a estar libre y podamos cargar los datos al usuario
 *\return retorna 1 si todo salio bien y -1 si hay un error*/
int pedirDatosForzada(Pantalla* pantalla , int len , int lugarLibre , char* nombre, char* direccion, float precio ,int tipo )
{
	int retorno =-1;

	Pantalla bufferPatalla;

	if(pantalla != NULL && len > 0)
	{

		strncpy(bufferPatalla.direccion , direccion ,DIRECCION_LEN);
		strncpy(bufferPatalla.nombre , nombre ,NOMBRE_LEN);
		bufferPatalla.precio = precio ;
		bufferPatalla.tipo = tipo ;
		bufferPatalla.id = nuevoId();
		pantalla[lugarLibre] = bufferPatalla;
		retorno = 1;



//		if(pantalla[lugarLibre].isEmpty == VACIO)
//		{
//			controlador = utn_getNombre(auxNombre, NOMBRE_LEN, "\nIngrese el nombre :","\nERROR", 2);
//			while(controlador != 0)
//			{
//				controlador = utn_getNombre(auxNombre, NOMBRE_LEN, "\nIngrese el nombre :","\nERROR", 2);
//			}
//			controlador = utn_getDescripcion(auxDireccion, DIRECCION_LEN, "\nIngrese direccion :", "\nEEROR", 2);
//			while(controlador != 0)
//			{
//				controlador = utn_getDescripcion(auxDireccion, DIRECCION_LEN, "\nIngrese direccion :", "\nEEROR", 2);
//			}
////			controlador = utn_getNumero(auxDni, "\nIngrese DNI :", "\nEEROR", 0, 100000, 2);
////			while(controlador != 0)
////			{
////				controlador = utn_getNumero(auxDni, "\nIngrese DNI :", "\nEEROR", 0, 100000, 2);
////			}
//			controlador = utn_getNumeroFlotante(&auxPrecio, "\nIngrese precio :", "\nERROR ", 0.0, 100.00, 2);
//			while(controlador != 0)
//			{
//				controlador = utn_getNumeroFlotante(&auxPrecio, "\nIngrese precio :", "\nERROR ", 0.0, 100.00, 2);
//			}
//
//			controlador = utn_getNumero(&auxTipo, "\nIngrese tipo (1- LCD || 2- LED) :", "\nerror", 1, 2, 2);
//			while(controlador != 0)
//			{
//				controlador = utn_getNumero(&auxTipo, "\nIngrese tipo (1- LCD || 2- LED) :", "\nerror", 1, 2, 2);
//			}
//
//			switch(auxTipo)
//			{
//			case 1 :
//				strncpy(pantalla[lugarLibre].nombre, auxNombre , sizeof(pantalla[lugarLibre].nombre));
//				strncpy(pantalla[lugarLibre].direccion, auxDireccion , sizeof(pantalla[lugarLibre].direccion));
//				pantalla[lugarLibre].precio = auxPrecio ;
//				pantalla[lugarLibre].isEmpty = OCUPADO ;
//				pantalla[lugarLibre].id = nuevoId() ;
//				pantalla[lugarLibre].tipo = TIPO_LCD;
//				retorno = 1;
//				break;
//			case 2:
//				strncpy(pantalla[lugarLibre].nombre, auxNombre , sizeof(pantalla[lugarLibre].nombre));
//				strncpy(pantalla[lugarLibre].direccion, auxDireccion , sizeof(pantalla[lugarLibre].direccion));
//				pantalla[lugarLibre].precio = auxPrecio ;
//				pantalla[lugarLibre].isEmpty = OCUPADO ;
//				pantalla[lugarLibre].id = nuevoId() ;
//				pantalla[lugarLibre].tipo = TIPO_LED;
//				retorno = 1;
//				break;
//			}
//
//
//
//		}else{
//			printf("\nEste luegar ya esta ocupado");
//		}

	}

	return retorno;
}




