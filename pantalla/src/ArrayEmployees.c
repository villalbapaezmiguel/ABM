/*
 * ArrayEmployees.c
 *
 *  Created on: 5 oct. 2021
 *      Author: miguel
 */
#include "ArrayEmployees.h"
static int nuevoId(void);

int initEmployees(Employees* list , int len)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		retorno = 1;
		for (int i = 0; i < len; ++i) {

			list[i].isEmpty = VACIO;

		}
	}

	return retorno;
}

/*agregar en un array de empleados existentes los valores recibidos como parametros en la primera posicion libre*/
int addEmployees(Employees* list, int len , int id , char name[NAME_LASTNAME_LENG], char lastName[NAME_LASTNAME_LENG] ,float salary , int sector)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		if(list[id].isEmpty == VACIO)//si el espacio de memoria se encuntra vacio pasa , sino no
		{
			if(utn_getNombre(name, NAME_LASTNAME_LENG, "\nIngrese nombre : ", "\nERROR ", 2) == 0 &&
				utn_getDescripcion(lastName, NAME_LASTNAME_LENG, "\nIngrese apellido : ", "\nERROR ", 2) == 0 &&
				getFloat(&salary, "\nIngrese el salario (de 1 hasta 10000): ", "\nERROR ", 1, 10000, 2) == 0 &&
				utn_getNumero(&sector, "\nIngrese el sector (de 0 hasta 1000): ", "\nERROR ", 0, 1000, 2) == 0)
			{
				strncpy(list[id].name , name , sizeof(list[id].name));
				strncpy(list[id].lastName , lastName , sizeof(list[id].lastName));
				list[id].salary = salary;
				list[id].sector = sector;
				list[id].isEmpty = OCUPADO;
				list[id].id = id;
				retorno = 1;

				//revisar : si encontraba el mismo Id se generaria uno nuevo
//				for (int i = 0; i < len; ++i) {//recorre toda la lista
//
//					if(list[id].id == list[i].id)//si el id en del Id pasado como parametro es encontrado en la lista pasa
//					{
//						list[id].id = nuevoId();//cambia el valor del Id anterior por uno nuevo
//					}
//				}

			}
		}
	}

	return retorno;
}

/*busca el empleado por su id
retorna -1  si la posicion no se encontro  , retorna un numero x mayor o igual a 0  si se encontro */
int findEmployeeById(Employees* list , int len , int id)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(list[i].id == id && list[i].isEmpty == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

/*elimna de manera logica (isEmpty flag en 1 0 vacio ) un empleado recibiendo como parametro su id*/
int removeEmployee(Employees* list , int len , int id)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(list[i].id == id && list[i].isEmpty == OCUPADO)
			{
				list[i].isEmpty = VACIO;
				retorno = 1;
				break;
			}
		}

	}


	return retorno;
}

/*imprime el array de empleados de forma encolumnada y solo los que tengan el isEmpty OCUPADO
 * todavia no esta listo*/
int printEmployees(Employees* list , int len)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		retorno = 1;
		for (int i = 0; i < len; ++i) {

			if(list[i].isEmpty == OCUPADO)
			{
				printf("\nID: %d || Name: %s || lastName: %s || salary: %f || sector: %d ",
				list[i].id , list[i].name , list[i].lastName , list[i].salary , list[i].sector  );
			}
		}

	}


	return retorno;
}


static int nuevoId(void)
{
	static int contador = 0;

	return contador++;
}

/*busca la primera posicion libre
 * retorna 1 si la encontro , -1 si no la encontro*/
int buscarLugarLibre(Employees* list , int len , int* lugarLibre)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for (int i = 0; i < len; ++i) {

			if(list[i].isEmpty == VACIO )
			{
				*lugarLibre = i ;
				retorno = 1;
				break;

			}

		}

	}

	return retorno;
}

int modificar(Employees* list , int len , int* idModificar , char name[NAME_LASTNAME_LENG] ,
		char lastName[NAME_LASTNAME_LENG], float salary , int sector)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		if(list[*idModificar].isEmpty == OCUPADO)
		{
			if(utn_getNombre(name, NAME_LASTNAME_LENG, "\nIngrese Nuevo nombre: ", "\nERROR ", 2) == 0 &&
				utn_getDescripcion(lastName, NAME_LASTNAME_LENG, "\nIngrese Nuevo apellido ","\nERROR " , 2) == 0 &&
				getFloat(&salary, "\nIngrese nuevo salario (1 a 10000):", "\nERROR", 1, 10000, 2) == 0 &&
				utn_getNumero(&sector, "\nIngrese el Nuevo sector (1 a 10000):","\nERROR", 1, 1000, 2) == 0)
			{
				strncpy(list[*idModificar].name ,name , sizeof(list[*idModificar].name));
				strncpy(list[*idModificar].lastName ,lastName , sizeof(list[*idModificar].lastName));
				list[*idModificar].salary = salary ;
				list[*idModificar].sector = sector;
				retorno =1;
			}
		}

	}

	return retorno;

}

/*retorna 1 se esta todo bien y sinp -1*/
int addEmployeesForzado(Employees* list, int len , int id , char name[NAME_LASTNAME_LENG], char lastName[NAME_LASTNAME_LENG] ,float salary , int sector)
{
	int retorno  = -1;

	if(list != NULL && len)
	{
		strncpy(list[id].name , name , sizeof(list[id].name));
		strncpy(list[id].lastName , lastName, sizeof(list[id].lastName));
		list[id].salary = salary ;
		list[id].sector = sector ;
		list[id].isEmpty = OCUPADO;
		list[id].id = nuevoId();
		retorno = 1;
	}
	return retorno;
}
