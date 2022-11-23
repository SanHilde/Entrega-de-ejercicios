/*
 * FuncionesExtras.c
 *
 *  Created on: 2 nov. 2022
 *      Author: santy
 */

#include "outputs.h"

int output_combinarCadenasConCaracter (char *cadenaPrincipal, char *cadenaASumar, char* caracterIntermedio)
{
	int retorno = -1;
	char cadenaAux[100];

	if (cadenaPrincipal != NULL && cadenaASumar != NULL)
	{
		strcpy (cadenaAux,cadenaPrincipal);
		strcat (cadenaPrincipal, caracterIntermedio);
		strcat (cadenaPrincipal, cadenaASumar);

		if (strcmp (cadenaAux,cadenaPrincipal)!= 0)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int output_correccionMayusculasCadena (char *cadena)
{
	int retorno = -1;
	char cadenaAux[150];

	if (cadena != NULL)
	{
		strcpy (cadenaAux,cadena);
		strlwr (cadena);
		*cadena = toupper (*cadena);

		for (int i=0; i<100; i++)
		{
			if (*(cadena+i)== ' ')
			{
				*(cadena+i+1)= toupper (*(cadena+i+1));
			}
		}

		if (strcmp (cadenaAux,cadena)!= 0)
		{
			retorno = 1;
		}
	}
	return retorno;
}


int output_respuesta (int valor)
{
	if (valor >= -1)
	{
		switch(valor)
		{
			case -1:
				printf("\nHubo un error en la operacion. Se cancelo la misma y no se guardaron los datos.\n\n");
				break;
			case 0:
				printf("\nOperacion cancelada.\n\n");
				break;
			case 1:
				printf("\nSe realizo la operacion con exito.\n\n");
				break;
		}
	}
	return valor;
}


void output_impresionFila (int cantCaracteres, int cantColumnas, char caracter)
{
	if ( cantCaracteres >= 0 && cantColumnas >= 0 && caracter >= '!')
	{
		for (int i=0; i<cantCaracteres+cantColumnas;i++)
		{
			printf ("%c", caracter);
		}
	}
}

int output_decodificacionId ( LinkedList* pArrayListSeleccion, int idAIdentificar, char *pIdIdentificado)
{
	char auxPais[30];
	int auxId;
	int retorno= ERROR;
	int bandera=ERROR;
	char auxSeleccion[100];
	char noConvocado[] = ("No convocado");
	int auxIndex;

	Seleccion* pSeleccion;


	if (pArrayListSeleccion != NULL && idAIdentificar >=0 && pIdIdentificado != NULL)
	{
		if (controller_buscarSeleccion (pArrayListSeleccion,idAIdentificar, &auxIndex) == 1)
		{
			if (auxIndex != -1)
			{
				pSeleccion = ll_get (pArrayListSeleccion,auxIndex);
				if (selec_getId(pSeleccion,&auxId) == 1 && selec_getPais(pSeleccion,auxPais) == 1)
				{
					if( idAIdentificar == auxId)
					{
						strcpy (auxSeleccion, auxPais);
						bandera = OK;
					}
				}
			} else
			{
				strcpy (auxSeleccion, noConvocado);
				bandera = OK;
			}
			if (bandera == OK)
			{
				retorno = OK;
				strcpy (pIdIdentificado, auxSeleccion);
			}
		}
	}
	return retorno;
}

int output_listarJugadorDecodificado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int index)
{
		int retorno = -1;
		Jugador* pJugador;
		int id;
		char nombreCompleto[100];
		int edad;
		char posicion[30];
		char nacionalidad[30];
		int idSeleccion;
		char idIdentificado[30];
		char mensajeError[] = ("Hubo un error al cargar al jugador");

		if (pArrayListJugador != NULL && pArrayListSeleccion != NULL && index>=0)
		{
			pJugador= ll_get(pArrayListJugador,index);

			if (jug_getId(pJugador,&id) == OK &&
			 jug_getNombreCompleto( pJugador,nombreCompleto)== OK &&
			 jug_getPosicion(pJugador,posicion)== OK &&
			 jug_getNacionalidad( pJugador,nacionalidad)== OK &&
			 jug_getEdad(pJugador,&edad)== OK &&
			 jug_getSIdSeleccion(pJugador,&idSeleccion)== OK &&
			 output_decodificacionId (pArrayListSeleccion, idSeleccion, idIdentificado)== OK)
			{
				printf("\n|%-5d|%-40s|%-25s|%-20s|%-5d|%-15s|",id,nombreCompleto,posicion,nacionalidad,edad,idIdentificado);
				retorno = 1;
			}else
			{
				printf("%s", mensajeError);
			}
		} else
		{
			printf("%s", mensajeError);
		}
	return retorno;
}

int output_listarJugadoresDecodificado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
		int retorno = -1;
		char mensajeError[] = ("Hubo un error al cargar al jugador");
		int cantJugadores;
		int cantColumnas=6;
		int cantCaracteres = 5+40+25+20+5+15+1;


		if (pArrayListJugador != NULL && pArrayListSeleccion != NULL )
		{
			cantJugadores =  ll_len(pArrayListJugador);
			output_impresionFila (cantCaracteres,cantColumnas,'=');
			printf ("\n|%-5s|%-40s|%-25s|%-20s|%-5s|%-15s|\n","ID","NOMBRE JUGADOR","POSICION","NACIONALIDAD","EDAD","SELECCION");
			output_impresionFila (cantCaracteres,cantColumnas,'=');

			for (int i=0; i<cantJugadores; i++)
			{
				output_listarJugadorDecodificado( pArrayListJugador, pArrayListSeleccion, i);
			}
			retorno = 1;
			printf("\n");
			output_impresionFila (cantCaracteres,cantColumnas,'=');
			printf("\n");
		} else
		{
			printf("%s", mensajeError);
		}
		return retorno;
}

int output_listarJugadoresDecodificadoFiltro(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
		int retorno = -1;
		char mensajeError[] = ("Hubo un error al cargar al jugador");
		int cantJugadores;
		int cantColumnas=6;
		int cantCaracteres = 5+40+25+20+5+15+1;
		int idSeleccionJugador;
		Jugador* pJugador;

		if (pArrayListJugador != NULL && pArrayListSeleccion != NULL )
		{
			cantJugadores =  ll_len(pArrayListJugador);
			output_impresionFila (cantCaracteres,cantColumnas,'=');
			printf ("\n|%-5s|%-40s|%-25s|%-20s|%-5s|%-15s|\n","ID","NOMBRE JUGADOR","POSICION","NACIONALIDAD","EDAD","SELECCION");
			output_impresionFila (cantCaracteres,cantColumnas,'=');

			for (int i=0; i<cantJugadores; i++)
			{
				pJugador = ll_get (pArrayListJugador, i);
				if (jug_getSIdSeleccion (pJugador,&idSeleccionJugador)==1 && idSeleccionJugador != 0)
				{
					output_listarJugadorDecodificado( pArrayListJugador, pArrayListSeleccion, i);
				}
			}
			retorno = 1;
			printf("\n");
			output_impresionFila (cantCaracteres,cantColumnas,'=');
			printf("\n");
		} else
		{
			printf("%s", mensajeError);
		}
		return retorno;
}

int output_obtenerIdMax (int* idMax)
{
	int retorno = -1;
	char idMaxAux[30];
	char auxTitulo[30];

	FILE* listaAux;

	if (idMax != NULL)
	{
		if ((listaAux = fopen("IdUnicoAutonomo.csv","r"))!= NULL)
		{
			fscanf(listaAux,"%[^:]: %[^\n]\n",auxTitulo, idMaxAux);
			fclose(listaAux);
			*idMax = atoi(idMaxAux);
			retorno = 1;
		} else
		{
			printf ("\nHubo un error al abrir el archivo.");
		}
	}

	return retorno;
}

int output_pedirConfirmacion (char *caracterConfirmacion, int intentos)
{
	int retorno=ERROR;
	do
	{
		if (utn_getCaracter(caracterConfirmacion, "¿Desea realizar la operacion? S/N (S para si / N para no): ",
				"Lo que se ingreso no es un caracter.\n", intentos)==OK)
		{
			retorno =OK;
		}

		*caracterConfirmacion = toupper (*caracterConfirmacion);
	} while (*caracterConfirmacion != 'S' && *caracterConfirmacion !='N');

	return retorno;
}

int output_decodificacionConf ( LinkedList* pArrayListSeleccion, int idAIdentificar, char *pConfDecodificada)
{
	char auxConf[30];
	int auxId;
	int retorno= ERROR;
	int bandera=ERROR;
	char auxSeleccion[100];
	char noConvocado[] = ("No convocado");
	int auxIndex;

	Seleccion* pSeleccion;


	if (pArrayListSeleccion != NULL && idAIdentificar >=0 && pConfDecodificada != NULL)
	{
		if (controller_buscarSeleccion (pArrayListSeleccion,idAIdentificar, &auxIndex) == 1)
		{
			pSeleccion = ll_get (pArrayListSeleccion,auxIndex);
			if (selec_getId(pSeleccion,&auxId) == 1 && selec_getConfederacion(pSeleccion,auxConf) == 1)
			{
					if( idAIdentificar == auxId)
					{
						strcpy (auxSeleccion, auxConf);
						bandera = OK;
					} else
					{
						strcpy (auxSeleccion, noConvocado);
						bandera = OK;
					}

				if (bandera == OK)
				{
					retorno = OK;
					strcpy (pConfDecodificada, auxSeleccion);
				}
			}
		}
	}
	return retorno;
}
