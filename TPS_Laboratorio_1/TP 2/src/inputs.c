/*
 * inputs.c
 *
 *  Created on: 17 sep. 2022
 *      Author: santy
 */

#include "inputs.h"
//#include "abm-jugador.h"



int utn_myGets ( char * cadena, int longitud)
{
	if (cadena != NULL && longitud >0 && fgets (cadena,longitud,stdin)==cadena)
	{
		fflush (stdin);
		if (cadena[ strlen (cadena)-1] == '\n' )
		{
			cadena[ strlen (cadena)-1] = '\0' ;
		}
		return OK;
	}
	return ERROR;
}

int utn_esNumericaInt ( char *cadena)
{
	int retorno;
	int i=0;

	if (cadena != NULL && strlen (cadena) > 0)//aca no deberia llamar a un puntero???
	{
		retorno = OK;
		do
		{
			if (*(cadena+i) < '0' || *(cadena+i) > '9' )
			{
				retorno = ERROR;
				break ;
			}
			i++;
		} while (*(cadena+i) != '\0' );
	}
	else
	{
		retorno = ERROR;
	}
	return retorno;

}

int utn_getInt ( int * pResultado)
{
	int retorno = ERROR;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (utn_myGets(buffer, sizeof (buffer))==OK && utn_esNumericaInt(buffer) == OK)
		{
			*pResultado = atoi (buffer); //atoi lo convierte a numeros
			retorno = OK;
		}
	}
	return retorno;

}

int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos)
{
	int ret=ERROR;
	int num;

	if (mensaje !=NULL && mensajeError!= NULL && minimo <= maximo && intentos >= 0 && pResultado!= NULL)
	{
		while(intentos>0)
		{
			fflush(stdin);
			printf("%s",mensaje); //ingrese un numero
			if(utn_getInt(&num)==OK)
			{
				if(num<=maximo && num>=minimo)
				break;
			}
				intentos--;
				printf("%s",mensajeError);
		}
			if(intentos!=0)
			{
				ret=OK;
				*pResultado = num;
			}
	}
	return ret;
}

int utn_getNumeroIntSinMax(int* pResultado, char* mensaje, char* mensajeError, int minimo, int intentos)
{
	int ret=ERROR;
	int num;

	if (mensaje !=NULL && mensajeError!= NULL && minimo >= 0 && intentos >= 0 && pResultado!= NULL)
	{
		while(intentos>0)
		{
			fflush(stdin);
			printf("%s", mensaje);
			if(scanf("%d",&num)==OK)
			{
				if(num>=minimo)
				{
					break;
				}
			}

				intentos--;
				printf("%s", mensajeError);
		}
			if(intentos!=0)
			{
				ret=OK;
				*pResultado = num;
			}
	}

	return ret;
}

int utn_esNumericaFloat ( char * cadena)
{
	int retorno;
	int contadorPunto = 0;
	int i=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = OK;
		do
		{
			if (*(cadena+i) == '/' || *(cadena+i) < '.' || *(cadena+i) > '9' || contadorPunto > 1 )
			{
				retorno = ERROR;
				break ;
			}
			if(*(cadena+i) == '.')
			{
				contadorPunto++;
			}
			i++;
		} while(*(cadena+i) != '\0');

	}
	else
	{
		retorno = ERROR;
	}

	return retorno;
}

int utn_getFloat ( float * pResultado)
{
	int retorno = ERROR;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (utn_myGets(buffer, sizeof (buffer))==OK && utn_esNumericaFloat(buffer) == OK)
		{
			*pResultado = atof (buffer);
			retorno = OK;
		}
	}
	return retorno;
}

int utn_getNumeroFloatSinMax(float* pResultado, char* mensaje, char* mensajeError, int minimo, int intentos)
{
	int ret=ERROR;
	float num;

	if (mensaje !=NULL && mensajeError!= NULL && minimo >= 0 && intentos >= 0 && pResultado!= NULL)
	{
		while(intentos>0)
		{
			fflush(stdin);
			printf("%s",mensaje);
			if(utn_getFloat(&num)==OK)
			{
				if(num>=minimo)
				{
					break;
				}
			}
			intentos--;
			printf("%s",mensajeError);
		}
			if(intentos!=0)
			{
				ret=OK;
				*pResultado = num;
			}
	}

	return ret;
}

int utn_esNumericaShort ( char * cadena)
{
	int retorno;
	int i=0;

	if (cadena != NULL && strlen (cadena) > 0)
	{
		retorno = OK;
		while (cadena[i] != '\0' )
		{
			if (cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = ERROR;
				break ;
			}
			i++;
		}
	}
	else
	{
		retorno = ERROR;
	}
	return retorno;

}

int utn_getShort ( short * pResultado)
{
	int retorno = ERROR;
	char buffer[64];
	if (pResultado != NULL)
	{
		if (utn_myGets(buffer, sizeof (buffer))==OK && utn_esNumericaShort(buffer) == OK)
		{
			*pResultado = atoi (buffer); //atoi lo convierte a numeros
			retorno = OK;
		}
	}
	return retorno;

}

int utn_getNumeroShort(short* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos)
{
	int ret=ERROR;
	short num;

	if (mensaje !=NULL && mensajeError!= NULL && minimo <= maximo && intentos >= 0 && pResultado!= NULL)
	{
		while(intentos>0)
		{
			fflush(stdin);
			printf("%s",mensaje); //ingrese un numero
			if(utn_getShort(&num)==OK)
			{
				if(num<=maximo && num>=minimo)
				break;
			}
				intentos--;
				printf("%s",mensajeError);
		}
			if(intentos!=0)
			{
				ret=OK;
				*pResultado = num;
			}
	}
	return ret;
}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, int intentos)
{
	char caracter;
	int ret=ERROR;

	if ( pResultado!= NULL && mensaje !=NULL && mensajeError!= NULL)
	{
		while(intentos>0)
		{
			printf("%s",mensaje);
			fflush(stdin);
			if (scanf("%c",&caracter)==OK)
			{
				ret=OK;
				break;
			}
			intentos--;
			printf("%s",mensajeError);
		}

		if(intentos!=0 )
		{
			*pResultado = caracter;
		}
	}

	return ret;
}

int utn_getCadena(char* pResultado, int len, char* mensaje, char* mensajeError,int intentos)
{
	int retorno=ERROR;
	char buffer[1024];
	int largoBuffer;

	if ( pResultado!= NULL && mensaje !=NULL && mensajeError!= NULL)
	{
		while (intentos > 0)
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]", buffer);

			largoBuffer = (int) strlen(buffer);

			if (len > largoBuffer)
			{
				retorno = OK;
				break;
			}
			intentos--;
			printf("%s", mensajeError);
		}

		if (intentos != 0)
		{
			strcpy(pResultado, buffer);
		}
	}
	return retorno;
}
