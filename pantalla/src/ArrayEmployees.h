/*
 * ArrayEmployees.h
 *
 *  Created on: 5 oct. 2021
 *      Author: miguel
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define NAME_LASTNAME_LENG 51
#define VACIO 0
#define OCUPADO 1
#define EMPLOYEES_LEN 1000

#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct{
	int id ;
	char name[NAME_LASTNAME_LENG];
	char lastName[NAME_LASTNAME_LENG];
	float salary ;
	int sector ;
	int isEmpty;

}Employees;

int initEmployees(Employees* list , int len);
int addEmployees(Employees* list, int len , int id , char name[NAME_LASTNAME_LENG], char lastName[NAME_LASTNAME_LENG] ,float salary , int sector);
int findEmployeeById(Employees* list , int len , int id);
int removeEmployee(Employees* list , int len , int id);
int printEmployees(Employees* list , int len);
int buscarLugarLibre(Employees* list , int len , int* lugarLibre);
int modificar(Employees* list , int len , int* idModificar , char name[NAME_LASTNAME_LENG] ,
		char lastName[NAME_LASTNAME_LENG], float salary , int sector);

int addEmployeesForzado(Employees* list, int len , int id , char name[NAME_LASTNAME_LENG], char lastName[NAME_LASTNAME_LENG] ,float salary , int sector);


#endif /* ARRAYEMPLOYEES_H_ */
