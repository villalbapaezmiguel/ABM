/*
 * Menu.c
 *
 *  Created on: 28 oct. 2021
 *      Author: miguel
 */


#include "Menu.h"


int menu(Pantalla* pantalla , int lenPantalla , Contratacion* contratacion , int lenContratacion)
{
	int retorno  =-1;

	int opcion ;
	int lugarLibrePantalla ;
	int idBaja ;
	int idPosicion;
	int idModificar ;
	int idPosicionModificar ;



//	int auxIdContratacion ;
//	int auxIdPosicion ;
	int lugarLibreContratacion ;
	int idPosicionContratacion ;
	int idContratacion = 0;
	int idModificarContratacion;

	printf("BIENVENIDOS !!");

	inicializar(pantalla, lenPantalla);
	inicializar_contratacion(contratacion, lenContratacion);

	pedirDatosForzada(pantalla, lenPantalla, 0, "Pantalla 1", "9 de Julio ",120, 1);
	pedirDatosForzada(pantalla, lenPantalla, 1, "Pantalla 2", "copihue 880 ",22, 2);
	pedirDatosForzada(pantalla, lenPantalla, 2, "Pantalla 3", "Santa Marta ",70, 1);
	pedirDatosForzada(pantalla, lenPantalla, 3, "Pantalla 4", "Belgrano ",50, 2);



	pedirDatos_contratacionForzada(contratacion, lenContratacion, 0, &idContratacion,1,"archivo1.mov", "1234", 2);
	pedirDatos_contratacionForzada(contratacion, lenContratacion, 1, &idContratacion,1,"archivo2.mov", "1234", 10);
	pedirDatos_contratacionForzada(contratacion, lenContratacion, 2, &idContratacion,1,"archivo3.mov", "1234", 20);
	pedirDatos_contratacionForzada(contratacion, lenContratacion, 3, &idContratacion,0,"archivo4.mov", "110", 2);
	pedirDatos_contratacionForzada(contratacion, lenContratacion, 4, &idContratacion,0,"archivo5.mov", "110", 10);
	pedirDatos_contratacionForzada(contratacion, lenContratacion, 5, &idContratacion,2,"archivo6.mov", "110", 20);
	pedirDatos_contratacionForzada(contratacion, lenContratacion, 6, &idContratacion,3,"archivo7.mov", "111", 5);

	while(opcion !=11)
	{
		printf("\n1- ALTA DE PANTALLA  \n2- MODIFICAR DATO DE PANTALLA \n3- BAJA DE PANTALLA \n4- CONTRATAR UNA PUBLICIDAD \n5- MODIFICAR CONDICIONES DE PUBLICACION \n6- CANCELAR PUBLICACION \n7- CONSULTA FACTURACION  \n8- LISTAR CONTRATACIONES \n9- LISTA DE PANTALLA \n10- INFORMAR  ");
		utn_getNumero(&opcion, "\nIngrese opcion : ", "\nERROR opcion no valida", 1, 10, 2);
		switch(opcion)
		{
		case 1:
			printf("\n-------------------- ALTA------------------------\n");
			if(buscarLugarLIbre(pantalla, lenPantalla, &lugarLibrePantalla) == 1)
			{
				if(pedirDatos(pantalla, lenPantalla, lugarLibrePantalla)== 1)
				{
					printf("\n----------------ALTA FINALIZADA-----------------\n");
					break;
				}

			}else{
				printf("\nYA NO HAY MAS LUGARES LIBRES !!");
			}

			break;
		case 2:
			printf("\n------------------------MODIFICACION-------------------------\n");
			if(utn_getNumero(&idModificar, "\nIngrese el ID a modificar :", "\nERROR ", 0, 200, 2)==0)
			{
				if(buscarPorId(pantalla, lenPantalla, idModificar, &idPosicionModificar) == 1)
				{
					if(modificar(pantalla, lenPantalla, idModificar, idPosicionModificar)== 1)
					{
						printf("\n--------------------------MODIFICACION FINALIZADA-----------------------\n");
						break;
					}
				}else{
					printf("\nESE ID NO EXISTE !!");
				}
			}
			break;
		case 3:
			printf("\n------------------------- BAJA------------------------\n");
			if(utn_getNumero(&idBaja, "\nIngrese el ID que quiere dar de baja : ", "\nERROR ",0, 200, 2)==0)
			{
				if(buscarPorId(pantalla, lenPantalla, idBaja, &idPosicion) == 1)
				{
					if(baja(pantalla, lenPantalla, &idBaja) == 1)
					{
						printf("\n-------------BAJA FINALIZADA----------------------\n");
						break;
					}
				}else{
					printf("\nESE ID NO EXISTE !!");
				}
			}

			break;
		case 4:
			printf("\n|-------------------CONTRATAR UNA PUBLICIDAD------------------|--");//creo que hay que revizar todo el 4 aja , tenemos que ver como vinculamos el los datos de contratacion con los de pantalla
			printf("\nv-------------------LISTA DE PANTALLAS------------------------v\n");
			if(imprimir(pantalla, lenPantalla)== 1)
			{
				if(utn_getNumero(&lugarLibreContratacion, "\nIngrese el ID de la pantalla la cual quiere cargar una Publicidad :", "\nERROR ", 0, 1000, 2) == 0)
				{
					if(buscarPorId_contratacion(contratacion, lenContratacion, lugarLibreContratacion, &idPosicionContratacion)== 1)
					{//no me deberia dejar entrar si pongo un id que no este en la lista
						if(buscarLugarLIbre_contratacion(contratacion, lenContratacion, &idPosicionContratacion) == 1)
						{
							if(pedirDatos_contratacion(contratacion, lenContratacion, idPosicionContratacion ,idContratacion )== 1)
							{
								printf("\n----------------CONTRATAR UNA PUBLICIDAD FINALIZADA-----------------\n");
								break;
							}
						}
					}else{
						printf("\n NO EXISTE ESE ID!!\n");
					}
				}
			}


//			imprimir(pantalla, lenPantalla);
//
//			if(utn_getNumero(&auxIdContratacion, "\ningrese el id de la pantalla en donde quiere publicarlo : ", "\nERROR", 0, 100, 2) == 0)
//			{
//				if(buscarPorId_contratacion(contratacion, lenContratacion, auxIdContratacion, &auxIdPosicion) == 1)
//				{
//					if(modificar_contratacion(contratacion, lenContratacion, auxIdContratacion, auxIdPosicion)== 1)
//					{
//						printf("\n--------------------------CONTRATAR UNA PUBLICIDAD FINALIZADA-----------------------\n");
//					}
//				}
//			}
//			if(ordenarPorNombre(pantalla, lenPantalla) == 1)
//			{
//				printf("\n---------------CONTRATAR UNA PUBLICIDAD FINALIZADA---------------");
//			}
			break;
		case 5:
			/*​ Se pedirá que se ingrese el cuit del cliente y se
			listaran todas las pantallas de video que el cliente tiene contratadas mostrando todos sus
			campos. Luego de ingresar el ID de la pantalla, se permitirá modificar la cantidad de días
			contratados​ ​ para​ ​ la​ ​ misma.*/

			printf("\n--------------------MODIFICAR CONDICIONES DE PUBLICACION ---------------------");
			char auxCuit [CUIT_LEN];
			int retornoValorCuit , controladorCmp = -1;
			retornoValorCuit = utn_getDni(auxCuit, CUIT_LEN, "\nIngrese el Cuit del cliente : ", "\nERROR ", 2);
			int x = -1;

			if(retornoValorCuit == 0)
			{
				for (int i = 0; i < lenContratacion; ++i) {

					for (int j = 0; j < lenContratacion; ++j) {

						controladorCmp = strncmp(auxCuit, contratacion[j].cuit, sizeof(auxCuit));
						if( controladorCmp == 0)
						{
							printf("\nsi existe (tu cuit : %s) (el cuit existente : %s)", auxCuit , contratacion[j].cuit);
							x = 1;
							break;
						}
						if(x == 1)
						{
							break;
						}
					}
					if(x != 1)
					{
						printf("\nNO EXIStE (el cuitque ingresaste : %s) ", auxCuit );
						for (int m = 0; m < lenContratacion; ++m) {
							if(contratacion[m].isEmpty == OCUPADO)
							{
								printf("\nEstos son los cuit disponibles : ID : %d || cuit del ese ID : %s", contratacion[m].idPantallas , contratacion[m].cuit);
							}
						}

						retornoValorCuit = utn_getDni(auxCuit, CUIT_LEN, "\nIngrese el Cuit del cliente : ", "\nERROR ", 2);
					}else if(x == 1)
					{
						break;
					}
				}

//
//				while(controladorCmp != 0)
//				{
//					for (int j = 0; j < CUIT_LEN; ++j) {
//
//						if(strncmp(auxCuit, contratacion[j].cuit ,CUIT_LEN)== 0)
//						{
//							printf("\nENTRO !!");
//							controladorCmp = 0;
//							break ;
//						}
//					}
//					if(controladorCmp != 0)
//					{
//						printf("\nNo existe !!");
//						printf("\ncuit : %s",contratacion[i].cuit);
//						retornoValorCuit = utn_getDni(auxCuit, CUIT_LEN, "\nIngrese el Cuit del cliente : ", "\nERROR ", 2);
//						controladorCmp= strncmp(auxCuit, contratacion[i].cuit ,sizeof(auxCuit));
//
//					}
//					i++;
				}
				if(controladorCmp == 0)
				{
					printf("\nEXISTEEE\n");

					imprimir_Contratacion_Informe(contratacion, lenContratacion, pantalla, lenPantalla, auxCuit);
//					imprimir_contratacionCuit(contratacion, lenContratacion, auxCuit);

					if(utn_getNumero(&idModificarContratacion, "\nIngrese el ID de la pantalla a modificar :", "\nERROR ", 0, 1000, 2) == 0)
					{

						modificar_contratacion(contratacion, lenContratacion, idModificarContratacion, idModificarContratacion, pantalla, lenPantalla);
						printf("\nModifico el ID : %d y su direccion es : %s ", contratacion[idModificarContratacion].id , pantalla[idModificarContratacion].direccion);
					}
					break;
				}

			break;
		case 6:
			printf("\n------------------------ CANCELAR CONTRATACION----------------\n");

			char auxCuitCliente [CUIT_LEN];
			int idCancelarContratacion ;
			int posicionIdCancelar ;
			int retornoBajaCmp =-1;
			int bandera = -1;
			if(utn_getDni(auxCuitCliente, CUIT_LEN, "\nIngrese el Cuit del cliente : ","\nERROR ", 2) == 0)
			{
				for (int i = 0; i < lenContratacion; ++i) {

					for (int j = 0; j < lenContratacion; ++j) {

						retornoBajaCmp = strncmp(auxCuitCliente, contratacion[j].cuit, sizeof(auxCuitCliente));
						if(retornoBajaCmp == 0)
						{
							printf("\nSI EXISTE !!");
							bandera = 1;
							imprimir_contratacionCuit(contratacion, lenContratacion, auxCuitCliente);
							if(utn_getNumero(&idCancelarContratacion, "\nIngrese ID de la pantalla  la cual quiera cancelar la contratcion : ", "\nERROR", 0, 200, 2)== 0)
							{
								if(buscarPorId_contratacion(contratacion, lenContratacion, idCancelarContratacion, &posicionIdCancelar) == 1)//posicion parece que esta mal
								{
									baja_contratacion(contratacion, lenContratacion, &idCancelarContratacion);
									printf("\n--------------------------CANCELAR CONTRATACION FINALIZADA--------------------\n");

								}else{
									printf("\nNO SE ENCONTRO EL ID DE LA PANTALLA !!");
								}
							}

							break;
						}
					}
					if(bandera == 1)
					{
						break;
					}else{
						printf("\nNO EXIStE (el cuitque que ingresaste : %s) ", auxCuitCliente );
						break;
					}
				}
			}
/*tenemos un problema : cuando ingresamos un Id que no esta dentro de los rangos del cuit que ingresamos , nos lo toma igual
 * tenemos que tratar de hacer un filtrado para que solo tome los id de los compos que abarca el cuit*/
			break;
		case 7:
			printf("\n------------------------ CONSULTA FACTURACION ----------------\n");
			char auxCuitFacturacion [CUIT_LEN];
			int retornoCuitFacturacion , retornoCmpFacturacion = -1;
			retornoCuitFacturacion = utn_getDni(auxCuitFacturacion, CUIT_LEN, "\nIngrese el Cuit del cliente : ", "\nERROR ", 2);
			int flag = -1;
		//	float preciofinal;  /*esta varible es de mi funcion */

			if(retornoCuitFacturacion == 0)
			{
				for (int i = 0; i < lenContratacion; ++i) {

					for (int j = 0; j < lenContratacion; ++j) {

						retornoCmpFacturacion = strncmp(auxCuitFacturacion, contratacion[j].cuit, sizeof(auxCuitFacturacion));
						if( retornoCmpFacturacion == 0)
						{
							printf("\nsi existe (tu cuit : %s) (el cuit existente : %s)", auxCuitFacturacion , contratacion[j].cuit);
							flag = 1;
//							listaImporte_A_Pagar_Informe(contratacion, lenContratacion, pantalla, lenPantalla, &preciofinal, auxCuitFacturacion);
//							printf("\nEL precio final a pagar es de : %f ", preciofinal);

							if(listar_Contratacion_Informe(contratacion, lenContratacion, pantalla, lenPantalla, auxCuitFacturacion) == 1)
							{
								printf("\nbien");// al final solo teniamos que informar los montos totales a pagar por cada direccion , no hacia falta sumarlos y informarlos , pero bien ah kaka
							}
							break;
						}
					}
					if(flag != 1)
					{
						printf("\nNO EXIStE (el cuitque que ingresaste : %s) ", auxCuitFacturacion );
						for (int m = 0; m < lenContratacion; ++m) {
							if(contratacion[m].isEmpty == OCUPADO)
							{
								printf("\nEstos son los cuit disponibles : ID : %d || cuit del ese ID : %s", contratacion[m].idPantallas , contratacion[m].cuit);
							}
						}

						retornoCuitFacturacion = utn_getDni(auxCuitFacturacion, CUIT_LEN, "\nIngrese el Cuit del cliente : ", "\nERROR ", 2);
					}else if(flag == 1){
						break ;
					}
				}
			}

			break;
		case 8:
			printf("\n------------------------LISTAR CONTRATACIONES---------------\n");
			imprimir_contratacion(contratacion, lenContratacion);
			break;
		case 9:
			printf("\n------------------------ LISTAR PANTALLA----------------\n");
			imprimir(pantalla, lenPantalla);
			break;
		case 10:
			printf("\n------------------------ INFORMAR----------------\n");

//			listaDeCadaCliente(contratacion, lenContratacion);
			info_ImprimirContratacionesImportePorCliente(contratacion, lenContratacion, pantalla , lenPantalla);
//			listaDeCadaCliente(contratacion, lenContratacion, pantalla, lenPantalla/*, char* auxCuit*/);
			break;
		}
	}

	return retorno ;
}

