/*
 * Informes.c
 *
 *  Created on: 5 nov. 2021
 *      Author: miguel
 */

#include "Informes.h"

int imprimir_contratacionCuit(Contratacion* contratacion , int len , char* cuit)
{
	int retorno = -1;
	int validacionCuit = -1;

	if(contratacion != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(contratacion[i].isEmpty == OCUPADO)
			{
				validacionCuit = strncmp(cuit, contratacion[i].cuit ,CUIT_LEN);
				if(validacionCuit == 0)
				{
					printf("\nID : %d || Archivo : %s || Cuit del cliente : %s ||  IdPantlla : %d || Dias : %d",contratacion[i].id , contratacion[i].archivo,contratacion[i].cuit , contratacion[i].idPantallas , contratacion[i].dias);
					retorno = 1;

				}
			}
		}
	}

	return retorno;
}






int imprimir_Contratacion_Informe(Contratacion* contratacion , int lenContratacion , Pantalla* pantalla , int lenPantalla , char* auxiliar)
{
	int retorno = -1;
	int indiceArrayPantalla;

	if((contratacion != NULL && lenContratacion > 0) && (pantalla != NULL && lenPantalla >0 ) && auxiliar != NULL)
	{
		for (int i = 0; i < lenContratacion; ++i) {
			if(contratacion[i].isEmpty == VACIO)
			{
				continue;
			}

			if(strncmp(contratacion[i].cuit,auxiliar , CUIT_LEN )== 0)
			{
				buscarPorId(pantalla, lenPantalla, contratacion[i].idPantallas, &indiceArrayPantalla);
				printf("\nCONTRATACIONES : ID : %d || Archivo : %s || Cuit del cliente : %s ||  IdPantlla : %d || Dias : %d",contratacion[i].id , contratacion[i].archivo,contratacion[i].cuit , contratacion[i].idPantallas , contratacion[i].dias);
				printf("\nPANTALLAS : ID : %d || Nombre : %s || Direccion : %s || Precio : %f || Tipo : %d \n",pantalla[indiceArrayPantalla].id,pantalla[indiceArrayPantalla].nombre , pantalla[indiceArrayPantalla].direccion, pantalla[indiceArrayPantalla].precio , pantalla[indiceArrayPantalla].tipo);

			}
		}

	}

	return retorno;
}

int listaImporte_A_Pagar_Informe(Contratacion* contratacion, int lenContratacion , Pantalla* pantalla , int lenPantalla , float* precioFinalPorDias , char* auxCuit)
{
	int retorno = -1;
	int acumuladorDIasCliente = 0;
	float precioPantalla = 0;
	int validarCuit = -1;
	int contador = 0;
	float sumaPrecioFinal = 0;

	if(contratacion != NULL && lenContratacion > 0)
	{
		imprimir_contratacionCuit(contratacion, lenContratacion, auxCuit);
		printf("\n---------------------------------------------------------\n");
		for (int i = 0; i < lenContratacion ; ++i) {

			if(contratacion[i].isEmpty == OCUPADO)
			{
				validarCuit = strncmp(auxCuit, contratacion[i].cuit, CUIT_LEN);

				if(validarCuit == 0)
				{
					retorno =1;
					acumuladorDIasCliente = contratacion[i].dias;//los dias acumulados
					precioPantalla = pantalla[i].precio;//el precio por pantalla
					//el resultado nos dio mal , tenemos que ver cual fue el problema y resolverlo :
					// el resultado  del cuit 1234 tiene que ser : 1860.0000 y nos dio : 2240.0000
					*precioFinalPorDias = precioPantalla * acumuladorDIasCliente;
					sumaPrecioFinal += *precioFinalPorDias;
					contador ++;
					printf("\nCuit : %s || direccion : %s || Dias : %d || Precio por dia : %f || contador : %d || suma %f", contratacion[i].cuit , pantalla[i].direccion , contratacion[i].dias , pantalla[i].precio , contador , sumaPrecioFinal);

				}

			}

		}
		*precioFinalPorDias = sumaPrecioFinal ;
	}

	return retorno;//falta probarlo
}

int listar_Contratacion_Informe(Contratacion* contratacion , int lenContratacion , Pantalla* pantalla , int lenPantalla , char* auxiliar)
{
	int retorno = -1;
	int indiceArrayPantalla;
	float auxiliarImporte ;

	if((contratacion != NULL && lenContratacion > 0) && (pantalla != NULL && lenPantalla >0 ) && auxiliar != NULL)
	{
		for (int i = 0; i < lenContratacion; ++i) {

			if(contratacion[i].isEmpty == VACIO)
			{
				continue;
			}
			if(strncmp(contratacion[i].cuit,auxiliar , CUIT_LEN )== 0)
			{
				retorno = 1;
				buscarPorId(pantalla, lenPantalla, contratacion[i].idPantallas, &indiceArrayPantalla);


				auxiliarImporte = contratacion[i].dias * pantalla[i].precio ;
				printf("\n ID : %d || Archivo : %s || Cuit del cliente : %s ||  IdPantlla : %d || Dias : %d || Importe : %f"
																									,contratacion[i].id
																									,contratacion[i].archivo
																									,contratacion[i].cuit
																									,contratacion[i].idPantallas
																									,contratacion[i].dias
																									,auxiliarImporte);

			}
		}

	}

	return retorno;
}
#define CLIENTES_LEN 1000
#define EXISTE 0
#define NO_EXISTE 1
//mio
int listaDeCadaCliente (Contratacion* contratacion , int lenContratacion )
{
	int retorno = -1;

	char listaClientesCuit [CLIENTES_LEN][CUIT_LEN];
	int bandera = NO_EXISTE;
	int indiceLibre = 0;

	if(contratacion != NULL && lenContratacion > 0)
	{

		for (int i = 0; i < CLIENTES_LEN; ++i) {

			strncpy(listaClientesCuit[i], "", CUIT_LEN);
		}

		for (int i = 0; i < lenContratacion; ++i) {//clientes

			if(contratacion[i].isEmpty == OCUPADO)
			{
				bandera = NO_EXISTE;
				for (int j = 0; j < CLIENTES_LEN; ++j) {//cuits

					if(strncmp(contratacion[i].cuit,listaClientesCuit[j], CUIT_LEN) == 0)//Problema :no entra a ninguna de las dos condiciones
					{
				//		printf("\nexiste");
						bandera = EXISTE;
						break;
					}
				}
				if(bandera == NO_EXISTE)
				{
		//			printf("\nentro");
					strncpy(listaClientesCuit[indiceLibre] , contratacion[i].cuit , CUIT_LEN);
					bandera = NO_EXISTE;
					indiceLibre++;
				}

			}
		}

		for (int i = 0; i < indiceLibre; ++i) {

			printf("\nCLIENTE - CUIT : %s", listaClientesCuit[i]);
		}
	}



	return retorno;
}








//profe
#define CANTIDAD_CLIENTES_LEN 1000
int info_ImprimirContratacionesImportePorCliente(Contratacion* contratacion , int lenContratacion , Pantalla* pantalla , int lenPantalla )
{

	int retorno = -1;
	//aray de strings(ya que los cuits son de tipo char )
	char listaCuit[CANTIDAD_CLIENTES_LEN][CUIT_LEN];//la primera dimension : la cantidad de elementos || la segunda dimension : la cantidad de de caracteres que queres tener
	int flagExistreCuit = 0;
	int indiceCuitLibre = 0;
	/*tenemos que compara a cada uno con los que ya estan en la lista y sino esta en la lista agregarlo*/
	/*esta es una buena estratgia por si tenes una lista y queres reducir a los no repetidos : agarramos al primero (y ya que el primero
	 * y el primero no esta repetido)listo lo agregamos a la lista,  y apartir de ahi antes tenesmos que llamar una funcion que nos dija si el nuevo elemento que tenemos esta en la lista (si esta en la lista
	 * lo agrego , sino no)  */
	//auxdeuda es del punto dos :
	float auxdeuda;
	//inicializamos nuestro array de clientes
	for (int i = 0; i < CANTIDAD_CLIENTES_LEN; ++i) {

		strncpy(listaCuit[i], "", CUIT_LEN);//adentro simpre tiene basura , asi que tenemso que inicializarlo como vacios
	}


	for (int j = 0; j < lenContratacion; ++j) {//recorremos el array de contratciones

		flagExistreCuit = 0;
		if(contratacion[j].isEmpty == VACIO)
		{
			continue ;
		}

		for (int k = 0; k < indiceCuitLibre; ++k) {//recorremos mi lista de cuit y vamos comparando

			if(strncmp(contratacion[j].cuit, listaCuit[k], CUIT_LEN)== 0)
			{
				flagExistreCuit = 1;
				break;
			}
		}//tenemos que compara el cuit que acabo de encontrar(osea el primero) contra lo que esta en la lista
		if(flagExistreCuit == 0)//si entro aca significa que no estaba en la lista
		{
			strncpy(listaCuit[indiceCuitLibre], contratacion[j].cuit, CUIT_LEN);//lo copiamos en listaCuit
			indiceCuitLibre++;
			//agregamos
		}
	}

	for (int l = 0; l < indiceCuitLibre; ++l) {

		printf("\n\n Cliente - CUIT : %s \n",listaCuit[l]);
		imprimir_Contratacion_Informe(contratacion, lenContratacion, pantalla, lenPantalla, listaCuit[l]);
	}

	float deudaMaxima =0;
	int IdClienteDeudaMaxima = 0;
	for (int l = 0; l < indiceCuitLibre; ++l) {

		info_calcularDeudaCliente(contratacion, lenContratacion, pantalla, lenPantalla, listaCuit[l], &auxdeuda);

		if(deudaMaxima < auxdeuda)
		{
			deudaMaxima = auxdeuda ;
			IdClienteDeudaMaxima = l;//lo tenemso que hacer por nuestra cuenta (info_calcularDeudaCliente este tambien)
		}

		printf("\n\n Cliente - CUIT : %s debe %f \n",listaCuit[l], auxdeuda);
	}

	printf("\nEl Cliente  con deuda mas alto es del cuit : %s y debe : %f",listaCuit[IdClienteDeudaMaxima], deudaMaxima);
	int a ;

	a = sizeof(int);
	printf("\n int mide : %i", a);
	return retorno ;
}

//profe
int info_calcularDeudaCliente(Contratacion* contratacion , int lenContratacion , Pantalla* pantalla , int lenPantalla , char* auxiliar , float* deuda)
{
	int retorno = -1;
	int indiceArrayPantalla;
	float auxdeuda = 0;

	if((contratacion != NULL && lenContratacion > 0) && (pantalla != NULL && lenPantalla >0 ) && auxiliar != NULL)
	{
		for (int i = 0; i < lenContratacion; ++i) {

			if(contratacion[i].isEmpty == VACIO)
			{
				continue;
			}
			if(strncmp(contratacion[i].cuit,auxiliar , CUIT_LEN )== 0)
			{
				retorno = 1;
				buscarPorId(pantalla, lenPantalla, contratacion[i].idPantallas, &indiceArrayPantalla);


				auxdeuda = auxdeuda + (contratacion[i].dias * pantalla[indiceArrayPantalla].precio);

			}
		}
		*deuda = auxdeuda;

	}

	return retorno;
}

