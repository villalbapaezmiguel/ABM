/*
 * Salon.c
 *
 *  Created on: 19 oct. 2021
 *      Author: miguel
 */

 #define NOMBRE_DIRECCION 51
#include "Salon.h"

static int nuevoIdSalon(void);

/*brief: Iinicializamos todos los salones en 1
 * brief: Salones* salon
 * brief: int len es el tamaño que tiene el array salon
 * brief: return  retorna 1 si salio todo bien , de lo contrario -1 */
int inicializarSalon(Salones* salon , int len)
{
	int retorno = -1;

	if(salon != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			salon[i].flagEmpty = 1;
			retorno = 1;
		}
	}

	return retorno ;
}
/*brief: vamos generando nuevos Id
 * brief: return  va a ir retornarndo el incremento del contador ,
 * de esta manera vamos haciendo un id de forma incremental y que no se puedan haber identificadores iguales*/
static int nuevoIdSalon(void)
{
	static int contador = 0;

	return (contador ++);
}

/*brief: tomamos los datos de usuario
 * brief: Salones* salon
 * param: int len
 * return : retorna 1 si salio todo bien , de lo contrario -1
 */
int cargaDeSalon(Salones* salon, int len)
{
	int retorno = -1;

	int tipo ;
	char nombre[NOMBRE_DIRECCION];
	char direccion[NOMBRE_DIRECCION];

	if(salon != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(utn_getNumero(&tipo, "Ingrese tipo\n :\n1 - shopping \n2 - local ", "\nERROR", 1, 2, 2)==0)
			{
				if(pedirTexto(nombre, NOMBRE_DIRECCION, "\nIngrese nombre :", "\nERROR", 2)==0)
				{
					if(pedirTexto(direccion,NOMBRE_DIRECCION, "\nIngrese direccion :","\nERROR" , 2)==0)
					{
						salon[i].tipo = tipo ;
						strncpy(salon[i].nombre,nombre,sizeof(salon[i].nombre));
						strncpy(salon[i].direccion,direccion,sizeof(salon[i].direccion));
						salon[i].flagEmpty = 0;
						retorno = 1;

						printf("---------------------aca comienza---------------------");
						switch(tipo)
						{
							case 1:
								printf("\nTipo de salon : shopping , nombre : %s , direccion : %s", salon[i].nombre , salon[i].direccion);
								break ;
							case 2:
								printf("\nTipo de salon : local , nombre : %s , direccion : %s", salon[i].nombre , salon[i].direccion);
								break ;
						}

						printf("---------------------aca termina----------------------");
					}
				}
			}

		}
	}

	return retorno;
}

/*brief: borramos por el Id
 * brief: Salones* salon
 * brief: int len Es el tamaño del array salon
 * brief: return retona 1 si todo salio bien , si hubo un error retorna -1
 * brief : int salonId nos pasa el id del salon
 * brief: buscarPorId()con esta funcion podemos sacar la posicion para luego dar de baja */
int borrarPorId(Salones* salon , int len , int salonId)
{
	int retorno = -1;

	int posicion ;
	if(salon != NULL && len > 0)
	{
		if(buscarPorId(salon, len, salonId, &posicion)== 1)
		{
			salon[posicion].flagEmpty = 1;
			retorno = 1;
		}

	}

	return retorno;
}
/*brief: bucamos por id , esta funcion nos va a servir para borrar por id
 * brief: Salones* salon
 * brief: int len Es el tamaño del array salon
 * brief: return retona 1 si todo salio bien , si hubo un error retorna -1
 * brief : int salonId nos pasa el id del salon
 * brief : int salonId Es el Id del salon
 * brief : int posicionId aca se va a guardar la posicion que salga
 */
int buscarPorId(Salones* salon , int len , int salonId , int* posicionId)
{
	int retornar = -1;

	if(salon != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i)
		{

			if(salon[i].flagEmpty != 1)
			{
				if(salon[i].id == salonId)
				{
					*posicionId = i;
					retornar = 1;
					break;
				}
			}
		}
	}
	return retornar ;
}

/*brief: imprimimos por pantalla los datos del usuario
 * brief: Salones* salon
 * brief: int len Es el tamaño del array salon
 * brief: return retona 1 si todo salio bien , si hubo un error retorna -1
 * brief: vamos imprimiendo todos los datos del usuario en pantalla*/
int imprimirSalon(Salones* salon , int len )
{
	int retorno = -1;
	int tipoSalon ;

	if(salon != NULL && len > 0)
	{
		printf("-------------------------------aca comienza----------------------");
		for (int i = 0; i < len; ++i)
		{

			if(salon[i].flagEmpty == 0)
			{
				retorno = 1;
				tipoSalon = salon[i].tipo;

				switch(tipoSalon)
				{
					case 1:
						printf("\ntipo : shopping , Id : %d , Nombre : %d , direccion : %d",
								salon[i].id , salon[i].nombre, salon[i].direccion);
						break ;
					case 2 :
						printf("\ntipo : Local , Id : %d , Nombre : %d , direccion : %d",
								salon[i].id , salon[i].nombre, salon[i].direccion);
						break ;
				}
			}
		}
		printf("-------------------------------aca termina----------------------");
	}
	return retorno;
}
