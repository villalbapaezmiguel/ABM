/*
 * ABM_SalonArcade.c
 *
 *  Created on: 20 oct. 2021
 *      Author: miguel
 */

#include "ABM_SalonArcade.h"

/*brief : es un contador global que va incrementando en uno
 * return : retorna el contador mas uno*/
static int nuevoIdArcade(void)
{
	static int contador = 0;

	return (contador++);
}

/*brief : Crear un nuevo usuario para el sistema
 *param : Arcade* arcade
 *param : int lenArcade
 *param : Salones* salon
 *param : int lenSalon
 *return :  retorna 1 si topdo salio bien , de lo contrario -1*/
int crearNuevoUsuario(Arcade* arcade , int lenArcade , Salones* salon , int lenSalon)
{
	int retorno = -1;
	char nacionalidad [63];
	int tipoSonido ;
	int cantidadJugadores ;
	int capacidadFichas;
	int idSalon ;
	int posicionId;
	if((arcade != NULL && salon != NULL) && (lenArcade >0 && lenSalon >0))
	{

		for (int i = 0; i < lenArcade; ++i) {


			if(arcade[i].isEmpty == 1)
			{
				arcade[i].isEmpty = 0;
				arcade[i].id = nuevoIdArcade();
				retorno = 1;
				if(pedirTexto(nacionalidad, 63, "\nIngrese nacionalidad :", "\nERROR ", 2)==0)
				{
					if(utn_getNumero(&tipoSonido, "\nIngrese tipo de sonido :\n1- Mono || 2- Estereo","\nERROR", 1, 2, 2)==0)
					{
						if(utn_getNumero(&cantidadJugadores,"\nIngrese cantidad de jugfadores (entre 1 y 5) :" , "\nERROR ", 1, 5, 2)==0)
						{
							if(utn_getNumero(&capacidadFichas, "\nIngrese cuantas fichas tiene el arcade : ", "\nERRO ", 1, 100, 2)== 0)
							{
								imprimirSalon(salon, lenSalon);

								if(utn_getNumero(&idSalon, "\nIngrese el saon donde pertenece :","\nERRO ",0, 100, 2) == 0)
								{
									while(buscarPorId(salon, lenSalon, idSalon, &posicionId) != 1)
									{
										utn_getNumero(&idSalon, "\nERROR Ingrese el salon donde pertenece :","\nERRO ",0, 100, 2);
									}

									strncpy(arcade[i].nacionalidad, nacionalidad , sizeof(arcade[i].nacionalidad));
									arcade[i].tipoSonido = tipoSonido;
									arcade[i].cantidadJuagadores = cantidadJugadores ;
									arcade[i].capacidadFichas = capacidadFichas;
									arcade[i].idSalon = idSalon ;
									pedirTexto(arcade[i].nombreJuego, lenArcade, "\nIngrese el nombre de este juego :", "\nERROR ", 2);
									break ;
								}

							}


						}
					}
				}

			}

		}
	}

	return retorno;
}//strncpy(salon[i].nombre,nombre,sizeof(salon[i].nombre));


/*brief : elimina un salon completo junto con sus enlaces
 *param : Salones* salones
 *param : int lenSalon
 *param : Arcade* arcade
 *param : int lenArcade
 *param : int id
 *return : retorna 1 si todo salio bien , de lo contrario -1*/
int eliminarSalon(Salones* salones , int lenSalon , Arcade* arcade , int lenArcade, int id )
{

	int retorno  =-1;

	if((salones != NULL && arcade != NULL) && (lenSalon > 0 && lenArcade > 0))
	{
		salones[id].flagEmpty  = 1;

		for (int i = 0; i < lenSalon; ++i) {

			if(salones[i].flagEmpty == 0)
			{
				if(salones[i].id == id)
				{
					salones[i].flagEmpty = 1;
					retorno = 1;
					break;
				}
			}
		}

	}

	return retorno;
}
