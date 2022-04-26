/*
 * informe.c
 *
 *  Created on: 17 feb. 2022
 *      Author: miguel
 */
#include "informe.h"

/*Ordena el array de empleados por apellido y sector de manera ascendente o descendente.*/
int sortEmployees(Employees* list , int len , int* order)
{
	int retorno = -1;
	int strResultado ;
	char auxLasname [NAME_LASTNAME_LENG];

	if(list != NULL && len > 0)
	{
		switch (*order)
		{
			case 1:
				printf("\nAscendente");
				for (int i = 0; i < len; ++i) {

					if(list[i].isEmpty == OCUPADO)
					{
						//Devuelve menor que cero si cadena1 es menor que cadena2.
						strResultado = strncmp(list[i].lastName , list[i+1].lastName, NAME_LASTNAME_LENG);
						if(strResultado < 0)
						{
							strncpy(auxLasname , list[i].lastName , NAME_LASTNAME_LENG);
							strncpy(list[i].lastName , list[i+1].lastName , NAME_LASTNAME_LENG);
							strncpy(list[i+1].lastName , auxLasname , NAME_LASTNAME_LENG);
						}
//						//Devuelve mayor que cero si cadena1 es mayor que cadena2.
//						if(strncmp(list[i].lastName , list[i+1].lastName, NAME_LASTNAME_LENG) > 0)
//						{
//						}
					}
				}
				for (int i = 0; i < len; ++i) {

					if(list[i].isEmpty == OCUPADO)
					{
						printf("\n LastName : %s ", list[i].lastName);
					}
				}

				break;
			case 2:
				printf("\nDescendente");
				for (int i = 0; i < len; ++i) {

					if(list[i].isEmpty == OCUPADO)
					{
						//Devuelve menor que cero si cadena1 es menor que cadena2.
						strResultado = strncmp(list[i].lastName , list[i+1].lastName, NAME_LASTNAME_LENG);
						if(strResultado < 0)
						{
							strncpy(auxLasname , list[i].lastName , NAME_LASTNAME_LENG);
							strncpy(list[i].lastName , list[i+1].lastName , NAME_LASTNAME_LENG);
							strncpy(list[i+1].lastName , auxLasname , NAME_LASTNAME_LENG);
						}
//						//Devuelve mayor que cero si cadena1 es mayor que cadena2.
//						if(strncmp(list[i].lastName , list[i+1].lastName, NAME_LASTNAME_LENG) > 0)
//						{
//						}
					}
				}
				for (int i = 0; i < len; ++i) {

					if(list[i].isEmpty == OCUPADO)
					{
						printf("\n LastName : %s ", list[i].lastName);
					}
				}
				break;

			default: printf("\nopcion ivalida");
				break;
		}

	}

	return retorno;
}
