/*
 * Arcade.c
 *
 *  Created on: 19 oct. 2021
 *      Author: miguel
 */
#include "Arcade.h"

static int nuevoIdArcade();
/*brief: Iinicializamos todos los arcades en 1
 * brief: Arcade* arcade
 * brief: int len es el tamaño que tiene el array arcade
 * brief: return  retorna 1 si salio todo bien , de lo contrario -1 */
int inicializarArcade(Arcade* arcade , int len)
{
	int retorno = -1;

	if(arcade != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			arcade[i].isEmpty = 1;
			retorno = 1;
		}
	}

	return retorno ;

}

/*brief: vamos generando nuevos Id
 * brief: return  va a ir retornarndo el incremento del contador ,
 * de esta manera vamos haciendo un id de forma incremental y que no se puedan haber identificadores iguales*/
static int nuevoIdArcade()
{
	static int contador = 0;

	return contador++;
}

/*brief : esta funcion puede modificar su Arcade con el Id
 *param : Arcade* arcade
 *param : int len es la longitud del array
 *param : int id es el id que nos va a servir para modificar en esa posicion
 *return : retorna 1 si todo salio bien , de lo contrario retornara -1*/
int modidicarArcade(Arcade* arcade , int len , int id)
{
	int retorno = -1 ;
	int opcion ;
	int cantidadJuagadores ;
	char nombreJugo[63];

	if(arcade != NULL && len > 0 )
	{

		if(utn_getNumero(&opcion, "\nIngrese lo que quiera modificar :\n1- cantidad de jugadores \n2- Juego que contiene :", "\nERROR ", 1,3, 2) == 0)
		{

			switch(opcion)
			{
				case 1:
					if(utn_getNumero(&cantidadJuagadores,"\nIngrese la cantidad de jugadores : ", "\nERROR ", 1, 5, 2)==0)
					{
						retorno = 1;
						arcade[id].cantidadJuagadores = cantidadJuagadores;
					}
					break ;
				case 2:
					if(pedirTexto(nombreJugo, 63, "\nIngrese el nuevo nombre del juego :", "\nERROR ", 2)== 0)
					{
						retorno = 1;
						strncpy(arcade[id].nombreJuego, nombreJugo , sizeof(arcade[id].nombreJuego));
					}
					break ;
			}
		}
	}
	return retorno;

}

/*bief : eliminamos un arcade
 *param : Arcade* arcade
 *param : int len
 *param : int* id
 *return : retorna 1 si todo salio bien , de lo contrario -1 */
int eliminiarArcadeId(Arcade* arcade , int len , int* id)
{
	int retornar = -1;
	int validarId ;

	if(arcade != NULL && len >0)
	{
		if(utn_getNumero(&validarId,"\nIntente ingresar nuevamente el Id a eliminar para confirmar : ", "\nError Id no valido ",1, 1000, 2)== 0)
		{
			while(validarId != *id)
			{
				utn_getNumero(&validarId,"\nERROR. Intente ingresar nuevamente el Id a eliminar para confirmar : ", "\nError Id no valido ",1, 1000, 2);
			}
			arcade[validarId].isEmpty = 1;
		}
	}

	return retornar ;
}

/*brief : buscamos la posicion de un arcade mediante su Id
 *param :  Arcade* arcade
 *param : int len
 *param : int id
 *param : int* idEncontrado
 *return : retorna 1 si todo salio bien , de lo contrario -1 */
int buscarArcadePorId(Arcade* arcade , int len , int id , int* idEncontrado)
{
	int retorno = -1;
	if(arcade != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(arcade[i].isEmpty == 1 )
			{
				if(arcade[i].id == id)
				{
					retorno = 1;
					*idEncontrado = i;
					break ;
				}
			}
		}

	}

	return retorno;
}

/*brief : imprime todos los arcades que estan en 0 (ocupados )
 *param: Arcade* arcade
 *param: int len
 *param: return retorna 1 si todo salio bien , de lo contrario -1*/
int imprimirArcade(Arcade* arcade , int len )
{
	int retorno = -1;

	if(arcade != NULL  && len > 0)
	{
		printf("------------------------aca comieza-------------------------------------");
		for (int i = 0; i < len; ++i) {

			if(arcade[i].isEmpty == 0)
			{
				retorno = 1;
				if(arcade[i].tipoSonido == 1)
				{
					printf("\nNacionalidad : %s , tipo de sonido : Mono , cantidad de jugadores : %d ,"
							"capacidad maxima de fichas : %d , Id del salon : %d , nombre del juego : %s",
							arcade[i].nacionalidad , arcade[i].cantidadJuagadores , arcade[i].capacidadFichas ,
							arcade[i].idSalon , arcade[i].nombreJuego);
					break;
				}else{
					printf("\nNacionalidad : %s , tipo de sonido : Estereo , cantidad de jugadores : %d ,"
							"capacidad maxima de fichas : %d , Id del salon : %d , nombre del juego : %s",
							arcade[i].nacionalidad , arcade[i].cantidadJuagadores , arcade[i].capacidadFichas ,
							arcade[i].idSalon , arcade[i].nombreJuego);
					break;
				}
			}
		}
		printf("-----------------------aca termina--------------------------------------");
	}
	return retorno;
}


/*brief : Imprime todos los juegos que no se repiten
 *param : Arcade* arcade
 *param : int len
 *return : retorna  1 si todo salio bien , de lo contrario -1*/
int imprimirJuegoSinRepeti(Arcade* arcade , int len )
{
	int retorno = -1;
	int nombreIgual = 0;

	if(arcade != NULL && len > 0)
	{
		retorno = 1;
		printf("-------------------comienza aca-----------------------");
		for (int i = 0; i < len; ++i) {

			if(arcade[i].isEmpty == 0)
			{
				for (int j = i+1; j < len; ++j) {

					if(strcmp(arcade[i].nombreJuego , arcade[j].nombreJuego)== 0)
					{
						nombreIgual = 1;
					}
					if(nombreIgual == 0)
					{
						printf("\nNombre juego : %s , su Id : %d ", arcade[i].nombreJuego , arcade[i].id);
					}

				}

			}

		}
		printf("-----------------------termina aca---------------------.-----");

	}
	return retorno;
}

