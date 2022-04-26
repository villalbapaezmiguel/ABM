/*
 ============================================================================
 Name        : pantalla.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "menu.h"

int main(void) {

	Employees list [EMPLOYEES_LEN];

	menu(list, EMPLOYEES_LEN);

//	char hola1 [51];
//	char hola2 [51];
//	char hola3 [51];
//	int resultado ;
//
//	strncpy(hola1, "buenas", sizeof(hola1));//6
//	strncpy(hola2, "buenas2", sizeof(hola2));//7
//	strncpy(hola3, "buenasss", sizeof(hola3));//8
//	//mayor >
//	//menor <
///*1-Devuelve el valor devuelve 0 si son iguales.
//2-Devuelve menor que cero si cadena1 es menor que cadena2.
//3-Devuelve mayor que cero si cadena1 es mayor que cadena2.*/
//
//	printf("\nhola1 : %s \nhola2 : %s \nhola3 : %s ", hola1, hola2 , hola3);
//
//	resultado = strncmp(hola3, hola2 , 51);
//	if( resultado < 0 )
//	{
//		printf("\nla cadena1 es menor que cadena2.");
//
//	}else
//	{
//		resultado = strncmp(hola3,hola2, 51);
//		printf("\nresultado : %d", resultado);
//		if( resultado > 0 )
//		{
//			printf("\nindica menos de cadena1 cadena2");
//
//		}
//	}


	return EXIT_SUCCESS;
}
