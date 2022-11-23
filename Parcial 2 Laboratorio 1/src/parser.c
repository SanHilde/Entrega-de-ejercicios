#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "inputs.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
		char id[30];
		char nombreCompleto[100];
		char edad[30];
		char posicion[30];
		char nacionalidad[30];
		char idSeleccion[30];

		Jugador* pJugador;

		int retornoFscanf;
		int retorno =-1;

		if (pArrayListJugador != NULL && pFile != NULL)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);

			while(feof(pFile) == 0)
			{
				retornoFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,
						idSeleccion);
				if(retornoFscanf == 6)
				{
					pJugador = jug_newParametros(id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);

					if (pJugador != NULL && ll_add (pArrayListJugador, pJugador) == 0)
					{
						retorno =1;
					} else
					{
						printf ("Error al cargar el dato.\n");
						retorno =-1;
						break;
					}
				} else
				{
					printf ("Error al escanear la lista.\n");
					retorno =-1;
					break;
				}
			}
		} else
		{
			printf ("\nHubo un error en el parseo de la lista.");
		}

    return retorno;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int id;
	char idChar[30];
	char nombreCompleto[100];
	int edad;
	char edadChar[30];
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	char idSeleccionChar[30];
	Jugador jugadorAux;
	Jugador* pJugador=NULL;
	int cant;
	int retorno =-1;

	if (pArrayListJugador != NULL && pFile != NULL)
	{
		do
		{
			cant = fread(&jugadorAux,sizeof(Jugador),1,pFile);
			if ( cant == 1 && jug_getId(&jugadorAux,&id) == OK && jug_getNombreCompleto(&jugadorAux,nombreCompleto) == OK &&
			jug_getPosicion(&jugadorAux,posicion) == OK && jug_getNacionalidad( &jugadorAux,nacionalidad) == OK &&
			jug_getEdad(&jugadorAux,&edad) == OK)
			{
				jug_getSIdSeleccion(&jugadorAux,&idSeleccion);
				sprintf(idChar, "%d", id);
				sprintf(edadChar, "%d", edad);
				sprintf(idSeleccionChar, "%d", idSeleccion);
				pJugador = jug_newParametros(idChar,nombreCompleto,edadChar,posicion,nacionalidad,idSeleccionChar);
				if (pJugador == NULL || ll_add (pArrayListJugador, pJugador) != 0)
				{
					printf ("Error al cargar el dato.\n");
					retorno =-1;
					break;
				}
			} else
			{
				if (feof(pFile))
				{
					retorno =1;
					break;
				}

				printf ("Error al cargar el dato.\n");
				retorno =-1;
				break;
			}
		} while (feof(pFile) == 0);
	} else
	{
		printf ("\nHubo un error en el parseo de la lista.");
	}

return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	Seleccion* pSeleccion;
	char id[30];
	char pais[30];
	char confederacion[30];
	char convocados[30];

	int retornoFscanf;
	int retorno =-1;

	if (pArrayListSeleccion != NULL && pFile != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);

		while(feof(pFile) == 0)
		{
			retornoFscanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
			if(retornoFscanf == 4)
			{
				pSeleccion = selec_newParametros(id,pais,confederacion,convocados);
				if (pSeleccion != NULL && ll_add (pArrayListSeleccion, pSeleccion) == 0)
				{
					retorno =1;
				} else
				{
					printf ("Error al cargar el dato.\n");
					retorno =-1;
					break;
				}
			} else
			{
				printf ("Error al cargar el dato.\n");
				retorno =-1;
				break;
			}
		}

	} else
	{
		printf ("\nHubo un error en la parseo de la lista.");
	}
    return retorno;
}

