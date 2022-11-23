/*
 * inputs.c
 *
 *  Created on: 17 sep. 2022
 *      Author: santy
 */

#include "inputs.h"
/*
static int getInt(int* pResultado)
{
	char buffer[64];
	scanf("%s",buffer);
	*pResultado = atoi(buffer);
	return 1;
}
*/

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos)
{
	int ret=-1;
	int num;

	if (mensaje !=NULL && mensajeError!= NULL && minimo <= maximo && intentos >= 0)
	{
		while(intentos>0)
		{

			printf("%s",mensaje); //ingrese un numero
			if(scanf("%d",&num)==1)
			{
				if(num<=maximo && num>=minimo)
				break;
			}
				fflush(stdin);
				intentos--;
				printf("%s",mensajeError);
		}
			if(intentos!=0)
			{
				ret=1;
				*pResultado = num;
			}
	}
	return ret;
}

int utn_getNumeroPositivo(int* pResultado, char* mensaje, char* mensajeError, int minimo, int intentos)
{
	int ret=-1;
	int num;

	if (mensaje !=NULL && mensajeError!= NULL && minimo >= 0 && intentos >= 0)
	{
		while(intentos>0)
		{
			printf("%s", mensaje);
			if(scanf("%d",&num)==1)
			{
				if(num>=minimo)
				{
					break;
				}
			}
				fflush(stdin);
				intentos--;
				printf("%s", mensajeError);
		}
			if(intentos!=0)
			{
				ret=1;
				*pResultado = num;
			}
	}

	return ret;
}

int utn_getNumeroPositivoConDecimales(float* pResultado, char* mensaje, char* mensajeError, int minimo, int intentos)
{
	int ret=-1;
	float num;

	if (mensaje !=NULL && mensajeError!= NULL && minimo >= 0 && intentos >= 0)
	{
		while(intentos>0)
		{
			printf("%s",mensaje);
			if(scanf("%f",&num)==1)
			{
				if(num>=minimo)
				{
					break;
				}
			}
			fflush(stdin);
			intentos--;
			printf("%s",mensajeError);
		}
			if(intentos!=0)
			{
				ret=1;
				*pResultado = num;
			}
	}

	return ret;
}
