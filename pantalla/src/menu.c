/*
 * menu.c
 *
 *  Created on: 15 feb. 2022
 *      Author: miguel
 */

#include "menu.h"

void menu (Employees* list , int len)
{
	int opcion ;
	int auxLugarLibre ;
	int auxIdBaja ;
	int auxIdBajaOpcion ;
	int auxIdModificar ;

	int auxOrden ;
	if(list != NULL && len > 0)
	{
		initEmployees(list, len);

		addEmployeesForzado(list, len, 0, "MIguel", "hola ", 9500, 10);
		addEmployeesForzado(list, len, 1, "Oscar", "holaaaaaa ", 5500, 2);
		addEmployeesForzado(list, len, 2, "Adrian", "hol ", 100, 3);
		addEmployeesForzado(list, len, 3, "Gustavo", "h ", 9900, 4);

		printf("WELCOME AT MY MENU !!!");
		do {
			printf("\n1) alta \n2)baja \n3)modificacion \n4)Imprimir \n5)Listado \n6)Salir");
			if(utn_getNumero(&opcion, "\nIngrese una Opcion :", "\nOpcion invalida ", 1, 6, 2) == 0)
			{
				switch(opcion)
				{
					case 1 :
						printf("\n one");
						if(buscarLugarLibre(list, len, &auxLugarLibre) == 1)
						{
							if(addEmployees(list, len, auxLugarLibre, list[auxLugarLibre].name, list[auxLugarLibre].lastName, list[auxLugarLibre].salary, list[auxLugarLibre].sector) == 1)
							{
								printf("ya se agrego a la lista");
							}

						}else{
							printf("\nNO se encontro lugar libre ");
						}
						break;
					case 2 :
						printf("\n two");
						if(utn_getNumero(&auxIdBaja, "\nIngrese el ID a dar de baja :", "\nERROR ",0, 1000, 2) == 0)
						{
							 if(findEmployeeById(list, len, auxIdBaja) != -1)
							 {
								 printf("\nSe encontro el ID %d || name : %s || lastName: %s || salary: %f || sector: %d ",
										 list[auxIdBaja].id , list[auxIdBaja].name ,list[auxIdBaja].lastName , list[auxIdBaja].salary , list[auxIdBaja].sector);

								 do {
								 	 if(utn_getNumero(&auxIdBajaOpcion, "\nDesea darlo de baja : \n1- SI \n2- NO :", "\nERROR", 1, 2, 2) == 0)
								 	{
								 		 switch(auxIdBajaOpcion)
								 		 {
								 		 case 1 :
								 			 if(removeEmployee(list, len, auxIdBaja) == 1)
								 			 {
								 				 printf("\nLIsto ya de dio de baja.");
								 			 }
								 			 break;
								 		 case 2 :
								 			 printf("\n no se dio nada de baja ");
								 			 break;
								 		 default : printf("\nOpcion invalida ");
								 		 }
								 	}
								} while (auxIdBajaOpcion != 1 && auxIdBajaOpcion != 2);


							 }else{
								 printf("\nNO se encontro .");
							 }
						}
						break;
					case 3 :
						printf("\n three");
						if(utn_getNumero(&auxIdModificar, "\nIngrese el ID a modificar :", "\nERROR ",0, 1000, 2) == 0)
						{
							if(findEmployeeById(list, len, auxIdModificar) != -1)
							{
								if(modificar(list, len, &auxIdModificar, list[auxIdModificar].name, list[auxIdModificar].lastName, list[auxIdModificar].salary, list[auxIdModificar].sector)== 1)
								{
									printf("\nLa modificacion esta completada ");
								}
							}else{
								printf("\nNo se encontro Id");
							}
						}
						break;
					case 4 :
						printEmployees(list, len);
						break;
					case 5 :

						do {
							printf("\n1)Ascendente \n2)Descendente");
							if(utn_getNumero(&auxOrden, "\nIgrese una opcion :", "\nERROR", 1, 2, 2)== 0)
							{

								sortEmployees(list, len, &auxOrden);
							}

						} while (auxOrden != 1 && auxOrden != 2);
						break;
					default : printf("saliste del programa !!");
						break;
				}

			}
		} while (opcion != 6);


	}


}
