/*
 * funcionesNecesarias.c
 *
 *  Created on: 17 sep. 2022
 *      Author: santy
 */

#include "funcionesNecesarias.h"
#include "inputs.h"

int calcularPromedio(float* pResultado, int total, int cantidad)
{
	int ret=-1;
	if (cantidad!=0)
	{
		*pResultado = (float) total / cantidad;
		ret=1;
	}
	return ret;
}

int calcularPorcentaje (float* pResultado, float numeroAAumentar, int porcentaje)
{
	int ret=-1;

	if(numeroAAumentar>=0 && porcentaje >=0)
	{
	*pResultado= numeroAAumentar * porcentaje / 100;
	ret= 1;
	}

	return ret;
}

int calcularAcumulador (float* pResultado, char* mensaje, char* mensajeError, int minimo, int intentos,
						char* mensajeCargaOK, char* mensajeErrorCarga)
{
	int ret;
	if (utn_getNumeroPositivoConDecimales(pResultado,mensaje,mensajeError,minimo,intentos)==1)
	{
		printf ("%s", mensajeCargaOK);
		ret=1;
	} else
	{
		printf ("%s", mensajeErrorCarga);//ver esto
		ret=-1;
	}

	return ret;

}

int cargaJugadores (int* pResultadoUno, int* pResultadoDos, char* mensajeUno, char* mensajeDos, char* mensajeErrorUno, char* mensajeErrorDos,
		int minimo, int maximo, int intentos, int *contador, char* mensajeCargaOK, char* mensajeErrorCarga)
{
	int ret;
	if (utn_getNumeroPositivo (pResultadoUno, mensajeUno, mensajeErrorUno, minimo, intentos)==1 &&
		utn_getNumero(pResultadoDos,mensajeDos, mensajeErrorDos, minimo, maximo, intentos)==1)
	{
		*contador=*contador+1;
		printf ("%s",mensajeCargaOK);
		//printf ("%d",*pResultadoUno );
		ret=1;
	}
	else
	{
		printf ("%s",mensajeErrorCarga);
		ret=-1;
	}
	return ret;
}
