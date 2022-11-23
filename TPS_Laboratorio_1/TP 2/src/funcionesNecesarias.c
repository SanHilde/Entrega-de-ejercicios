/*
 * funcionesNecesarias.c
 *
 *  Created on: 17 sep. 2022
 *      Author: santy
 */

#include "funcionesNecesarias.h"

int calcularAcumulador(eJugadores *estructura, float* acumulador)
{
	float suma=0;
	int retorno=ERROR;

	if (estructura != NULL)
	{
		for(int i = 0; i<CANT_JUGADORES; i++)
		{
			if((estructura+i)->isEmpty == OCUPADO)
			{
				suma = suma + (estructura+i)->salario;
			}
		}

		if (suma>=0)
		{
			*acumulador=suma;
			retorno = OK;
		}
	}
	return retorno;
}

int calcularContador(eJugadores *estructura, short* acumulador)
{
	float suma=0;
	int retorno=ERROR;

	if (estructura != NULL)
	{
		for(int i = 0; i<CANT_JUGADORES; i++)
		{
			if((estructura+i)->isEmpty == OCUPADO )
			{
				suma++;
			}
		}

		if (suma>=0)
		{
			*acumulador=suma;
			retorno = OK;
		}
	}
	return retorno;
}

int calcularContadorConFiltro(eJugadores *estructura, short* acumulador, int filtro)
{
	float suma=0;
	int retorno=ERROR;

	if (estructura != NULL)
	{
		for(int i = 0; i<CANT_JUGADORES; i++)
		{
			if((estructura+i)->isEmpty == OCUPADO && (estructura+i)->idConfederacion == filtro)
			{
				suma++;
			}
		}

		if (suma>=0)
		{
			*acumulador=suma;
			retorno = OK;
		}
	}
	return retorno;
}

int calcularConfMasAniosContratos (eJugadores *estructura, eConfederaciones *estructuraDos, short *pResultadoAcumulador, char *pResultadoID)
{
	int retorno = ERROR;
	short acumuladorAux=0;
	short acumuladorMayor;
	int idConfMayor;
	int bandera = 0 ;
	char cadenaAux[CANT_CARACTERES];
	char cadenaAuxEmpate[CANT_CARACTERES];
	int idConfMayorEmpate;
	short acumuladorAuxEmpate=0;

	if (estructura != NULL && pResultadoAcumulador != NULL && pResultadoID != NULL)
	{
		for(int i = 0; i<CANT_CONF; i++)
		{
			if((estructuraDos+i)->isEmpty == OCUPADO)
			{
				for(int j = 0; j<CANT_JUGADORES; j++)
				{
					if((estructura+j)->isEmpty == OCUPADO)
					{
						if((estructura+j)->idConfederacion == (estructuraDos+i)->id)
						{
							acumuladorAux = acumuladorAux + (estructura+j)->aniosContrato;
						}
					}
				}
				if (acumuladorAux==acumuladorMayor)
				{
					idConfMayorEmpate=(estructuraDos+i)->id;
					decodificacionId ( estructuraDos,&idConfMayorEmpate, cadenaAuxEmpate);
					strcat (cadenaAux, "-");
					strcat (cadenaAux, cadenaAuxEmpate);
					acumuladorAuxEmpate=acumuladorAux;

				}
				if (acumuladorAux>acumuladorMayor || bandera == 0)
				{
					idConfMayor=(estructuraDos+i)->id;
					decodificacionId ( estructuraDos,&idConfMayor, cadenaAux);//
					acumuladorMayor=acumuladorAux;
					bandera = OK;
				}

				acumuladorAux=0;
			}
		}

		if (acumuladorMayor>acumuladorAuxEmpate)
		{
			strcpy (pResultadoID, cadenaAux);
			*pResultadoAcumulador=acumuladorMayor;
		}else
		{
			*pResultadoAcumulador=acumuladorMayor;
			strcat (cadenaAux, " (empataron).");
			strcpy (pResultadoID, cadenaAux);
		}
		if (*pResultadoID>=0 && *pResultadoAcumulador>=0)
		{
		retorno = OK;
		}
	}
	return retorno;
}

int calcularConfMasJugadores (eJugadores *estructura, eConfederaciones *estructuraDos, char *pResultadoID, int *pResultadoIDint)
{
	int retorno = ERROR;
	short acumuladorAux=0;
	short acumuladorMayor;
	int idConfMayor;
	int bandera = 0 ;
	char cadenaAux[CANT_CARACTERES];
	char cadenaAuxEmpate[CANT_CARACTERES];
	int idConfMayorEmpate;
	short acumuladorAuxEmpate=0;

	if (estructura != NULL  && pResultadoID != NULL)
	{
		for(int i = 0; i<CANT_CONF; i++)
		{
			if((estructuraDos+i)->isEmpty == OCUPADO)
			{
				for(int j = 0; j<CANT_JUGADORES; j++)
				{
					if((estructura+j)->isEmpty == OCUPADO)
					{
						if((estructura+j)->idConfederacion == (estructuraDos+i)->id)
						{
							acumuladorAux++;
						}
					}
				}

				if (acumuladorAux==acumuladorMayor && bandera==OK)
				{
					idConfMayorEmpate=(estructuraDos+i)->id;
					decodificacionIdRegion ( estructuraDos,&idConfMayorEmpate, cadenaAuxEmpate);
					strcat (cadenaAux, "-");
					strcat (cadenaAux, cadenaAuxEmpate);
					acumuladorAuxEmpate=acumuladorAux;
				}
				if (acumuladorAux>acumuladorMayor || bandera == 0)
				{
					idConfMayor=(estructuraDos+i)->id;
					decodificacionIdRegion ( estructuraDos,&idConfMayor, cadenaAux);//
					acumuladorMayor=acumuladorAux;
					bandera = OK;
				}

				acumuladorAux=0;
			}
		}

		if (acumuladorMayor>acumuladorAuxEmpate)
		{
			strcpy (pResultadoID, cadenaAux);
			*pResultadoIDint=idConfMayor;
		}else
		{
			strcat (cadenaAux, " (empataron)");
			strcpy (pResultadoID, cadenaAux);
			*pResultadoIDint=0;
		}

		if (pResultadoID != NULL && *pResultadoID>=0)
		{
		retorno = OK;
		}
	}
	return retorno;
}

int calcularPromedio(float* pResultado, float* total, short* cantidad)
{
	int ret=ERROR;
	float resultado;
	if (pResultado != NULL)
	{
		if (cantidad!=0)
		{
			resultado = *total / *cantidad;

		} else
		{
			*pResultado = 0;
		}

		if (resultado >=0)
		{
			*pResultado = resultado;
			ret=OK;
		}
	}
	return ret;
}

int calcularPorcentaje (float* pResultado, float numeroUno, int numeroDos)
{
	int ret=ERROR;
	if (pResultado != NULL)
	{
		if(numeroUno>=0 && numeroDos >=0)
		{
		*pResultado= numeroUno * numeroDos / 100;
		ret= OK;
		//printf ("%f", *pResultado);
		}
	}

	return ret;
}

int contadorSuperiorAPromedio(eJugadores *estructura, float* promedio, int *contador )
{
	int retorno = ERROR;
	int contadorInterno=0;
	if (estructura != NULL && *promedio>=0 && contador != NULL)
	{
		for(int i = 0; i<CANT_JUGADORES; i++)
		{
			if((estructura+i)->isEmpty == OCUPADO && *promedio<(estructura+i)->salario)
			{
				contadorInterno++;
			}
		}
	}
	if (contadorInterno>=0)
	{
		*contador=contadorInterno;
		retorno = OK;
	}
	return retorno;
}


