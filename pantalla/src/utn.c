#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

static int myGets (char* cadena , int longitud);
static int getInt (int* pResultado);
static int esNumerica(char* cadena );
static int getNombre(char* pResultado, int longitud);
static int getString(char* cadena, int longitud);
static int esNombre(char* cadena,int longitud);
static int getDescripcion(char* pResultado, int longitud);
static int esDescripcion(char* cadena,int longitud);

/*\brief Solicita un numero al usuario , lo valida , verifica y devuelve el resultado
 *\param pRespuesta Puntero al resultado alli se dejara el numero ingresado por el usuario
 *\param mensaje es El mensaje a ser mostrado
 *\param mensajeError Es el mensaje a ser mostrado en caso de error
 *\param minimo Valor minimo aceptado
 *\param maximo Valor maximo aceptado
 *\param reintentos Cantidad de reintentos en el caso de error
 *\return En caso de exito (0) , en caso de error (-1)
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	//1ro no sfijamos que todos los puntero tienen que ser != NULL
	int bufferInt;
	int retorno = -1;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) {

		while (reintentos >= 0)
		{
			printf("%s", mensaje);
			//scanf("%d", &bufferInt); //quiero que scanf me deje en esat direccion lo que acaba de leer
			//el usuario recien ingreso algo , entonces tenemos que ver si ese algo es mayo o igual al minimo
			if (getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{

				*pResultado = bufferInt;
				retorno = 0;
				break;

			} else
			{
				printf("\n%s", mensajeError);
				printf("\nle quedan : %d intentos ", reintentos);

			}

			reintentos--;
		}

	}

	return retorno;
}

int utn_getNumeroCaracter(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos) {
	char bufferChar;
	int retorno = -1;

	while (reintentos >= 0) {

		if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
				&& minimo <= maximo && reintentos >= 0) {

			printf("%s", mensaje);
			__fpurge(stdin);//tenemos que limpiar el buffer(espacio de memoria).
//para utlizar (__fpurge(stdin);) tenemos que incluir stdio_ext.h y quedaria : (#include <stdio_ext.h>)
			scanf("%c", &bufferChar);//la mascara de bufferChar tiene que ser %c solamente

			if (bufferChar >= minimo && bufferChar <= maximo) {

				*pResultado = bufferChar;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);

			}

		}
		reintentos --;
	}

	return retorno;

}
//int getInt(int *pNumero , char *mensaje , char *mensajeError, int minimo , int maximo , int repeticiones)
//{
//	int bufferInt;
//	int respuesta =-1;
//
//	while(repeticiones >= 0)
//	{
//		if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && repeticiones >= 0)
//		{
//			printf("%s",mensaje);
//			scanf("%d",&bufferInt);
//
//			if(bufferInt >= minimo && bufferInt <= maximo)
//			{
//				*pNumero = bufferInt ;
//				respuesta = 0;
//				break ;
//
//			}else{
//				printf("%s",mensajeError);
//			}
//
//		}
//	}
//
//	return respuesta;
//}

float getFloat(float *pNumero , char *mensaje , char *mensajeError, float minimo , float maximo , int repeticiones)
{
	float bufferFloat;
	int respuesta = -1;

	while(repeticiones >= 0)
	{
		if(pNumero != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && repeticiones >=0)
		{
			printf("%s",mensaje);
			scanf("%f",&bufferFloat);

			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pNumero = bufferFloat;
				respuesta = 0;
				break ;
			}else{
				printf("%s",mensajeError);
			}
		}
	}

	return respuesta;

}


int getChar(char *pLetra , char *mensaje , char *mensajeError, char minimo , char maximo , int repeticiones)
{
	char bufferChar ;
	int respuesta = -1;

	while(repeticiones >= 0)
	{
		if(pLetra != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && repeticiones >= 0)
		{
			printf("%s",mensaje);
			__fpurge(stdin);
			scanf("%c",&bufferChar);

			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*pLetra = bufferChar;
				respuesta = 0;
				break;
			}else{
				printf("%s",mensajeError);
			}

		}
	}
	return respuesta;

}

int get_Int(char mensaje[])
{
	int aux ;
	printf("%s",mensaje);
	scanf("%d",&aux);
	return aux;
}

float get_Float(char mensaje[]){

	float aux ;
	printf("%s",mensaje);
	scanf("%f",&aux);
	return aux;
}
float get_Char(char mensaje[]){

	char aux ;
	printf("%s",mensaje);
	__fpurge(stdin);

	scanf("%c",&aux);
	return aux;

}

static int myGets (char* cadena , int longitud)
{
	__fpurge(stdin);
/*fgets : significa que lee un archivo (en este caso : stdin)
 * 1er parametro : en donde se va a dejar la informacion
 * 2do parametro : la longitud o cantidad
 * 3er parametro : el archivo*/
	fgets(cadena,longitud, stdin);
	cadena[strlen(cadena)-1] = '\0';

//	scanf("%s",buffer);
//	strncpy(cadena,buffer, longitud);//strncpy(su destino , la fuente , cantidad a copiar);


	return 0;
}
static int getInt (int* pResultado)
{
	int retorno = -1;
	char buffer [4096];
	//scanf("%s",buffer); no lo usamos mas

	if(myGets(buffer, sizeof(buffer)) == 0 && esNumerica (buffer))
	{
		retorno  = 0;
		*pResultado = atoi(buffer);//lo que hace atoi es convertir una cadena en un entero
	}

	return retorno;
}

static int esNumerica(char* cadena )
{
	int retorno = 1 ;
	int i = 0;

	if(cadena[0] == '-')
	{
		i = 1;
	}
	for (; cadena[i] != '\0'; ++i) {

		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;

		}
	}

	return retorno ;

}

/*
 * \brief Verifica si el valor recibido es numerico
 * \param str Arrary con la cadena a ser analizado
 *  \return 1 si es numerico y 0 si no lo es
 */
int esNumericos(char str[])
{
	int i = 0;

	while(str[i] != '\0')
	{
		if(str[i] < '0' || str[i] > '9')
		{
			return 0;
		}
		i++;
	}
	return 1;
}

/*
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Arrary con la cadena a ser analizada
 *  \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */
int esSoloLetras(char str[])
{
	int i = 0;

	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

/*
 * \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param str Arrary con la cadena a ser analizada
 *  \return 1 si contiene solo espacios letras y  numeros , 0 si no lo es
 */
int esAlfaNumerico(char str[])
{
	int i = 0;

	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
		{
			return 0;
		}
		i++;
	}
	return 1;

}

/*
 * \brief Verifica si el valor recibido contiene solo letras y numeros
 * \param str Arrary con la cadena a ser analizada
 *  \return 1 si contiene solo espacios letras y  numeros , 0 si no lo es
 */
int esTelefono(char str[])
{
	int i = 0;
	int contadorGuiones = 0;
	int retorno ;

	while(str[i] != '\0')
	{

		if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
		{
			retorno = 0;
		}

		if(str[i] == '-')
		{
			contadorGuiones ++;
		}
		i++;

	}
	if(contadorGuiones == 1)//debe tener un guion
	{
		retorno = 1;
	}

	return retorno;
}


int calcularMayor(int numUno , int numDos , int *pNumeroMayor)
{
	int retorno = -1 ;

	if(pNumeroMayor != NULL)
	{
		if(numUno == numDos)
		{
			retorno = 0;

		} else if (numUno > numDos)
		{
			retorno = 1;
			*pNumeroMayor = numUno;

		} else if (numDos > numUno)
		{

			retorno = 1;
			*pNumeroMayor = numDos;
		}

	}

	return retorno ;

}

int pedirTexto(char* pResultado ,int leng, char* mensaje , char* mensajeError , int reintentos)
{
	int retorno = -1;

	for (int i = 0; i < reintentos; ++i) {

		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL )
		{
			printf("%s", mensaje);
			__fpurge(stdin);

			if(fgets(pResultado,leng,stdin) != NULL)
			{
				retorno = 0;
				break;
			}else{
				printf("%s",mensajeError);
			}

		}
	}

	return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Obtiene un string valido como nombre
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un m??ximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tama??o de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


/**
 * \brief Solicita una descripcion al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero flotante y -1 si no
 *
 */
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/**
 * \brief Obtiene un string valido como descripcion
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es una descripcion valida
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
