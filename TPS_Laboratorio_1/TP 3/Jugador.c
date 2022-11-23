#include "Jugador.h"
#include <stdio.h>
#include <stdlib.h>

#define OCUPADO 0

Jugador* jug_new()
{
    Jugador* pJugador;

    pJugador = (Jugador*) malloc(sizeof(Jugador));
    if (pJugador!= NULL)
    {
     return pJugador;
    } else
    {
    	printf ("Memoria llena.\n");
    	return NULL;
    }
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	Jugador* pJugador;
	int auxId;
	int auxEdad;
	int idSeleccion;

	auxId = atoi(idStr);
	auxEdad = atoi(edadStr);
	idSeleccion = atoi(idSelccionStr);

	pJugador = jug_new();

	if(pJugador != NULL)
	{
		if (jug_setId(pJugador,auxId)== -1 ||
		 jug_setNombreCompleto(pJugador,nombreCompletoStr)== -1 ||
		 jug_setPosicion(pJugador,posicionStr)== -1 ||
		 jug_setNacionalidad(pJugador,nacionalidadStr)== -1 ||
		 jug_setEdad(pJugador,auxEdad)== -1 ||
		 jug_setIdSeleccion(pJugador,idSeleccion)== -1)
		{
			//jug_setIsEmpty(pJugador,OCUPADO);
			printf ("Hubo un error en la carga del jugador de id: %d\n", auxId);
			pJugador= NULL;
		}
	}
	return pJugador;
}

void jug_delete(Jugador* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int jug_setId(Jugador* this,int id)
{
	int retorno = -1;

	if(this !=  NULL && id >0)
	{
		this->id=id;
		retorno= 1;
	}
	return retorno;
}

int jug_getId(Jugador* this,int* id)
{
	int retorno = -1;

	if(this !=  NULL && id!=  NULL)
	{
		*id= this->id;
		retorno= 1;
	}

	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

	if(this !=  NULL && nombreCompleto !=NULL)
	{
		strcpy(this->nombreCompleto,nombreCompleto);
		retorno= 1;
	}
	return retorno;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

		if(this !=  NULL && nombreCompleto !=NULL)
		{
			strcpy(nombreCompleto, this->nombreCompleto);
			retorno= 1;
		}

		return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

		if(this !=  NULL && posicion !=NULL)
		{
			strcpy(this->posicion,posicion);
			retorno= 1;
		}
	return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if(this !=  NULL && posicion !=NULL)
	{
		strcpy(posicion, this->posicion);
		retorno= 1;
	}

	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

		if(this !=  NULL && nacionalidad !=NULL)
		{
			strcpy(this->nacionalidad,nacionalidad);
			retorno= 1;
		}
	return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

	if(this !=  NULL && nacionalidad !=NULL)
	{
		strcpy(nacionalidad, this->nacionalidad);
		retorno= 1;
	}

	return retorno;
}

int jug_setEdad(Jugador* this,int edad)
{
	int retorno = -1;

		if(this !=  NULL && edad >0)
		{
			this->edad=edad;
			retorno= 1;
		}
	return retorno;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = -1;

	if(this !=  NULL && edad!=  NULL)
	{
		*edad= this->edad;
		retorno= 1;
	}

	return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = -1;

		if(this !=  NULL && idSeleccion >=0)
		{
			this->idSeleccion=idSeleccion;
			retorno= 1;
		}
	return retorno;
}

int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = -1;

	if(this !=  NULL && idSeleccion !=  NULL)
	{
		*idSeleccion= this->idSeleccion;
		retorno= 1;
	}

	return retorno;
}
/*
int jug_setIsEmpty(Jugador* this,int isEmpty)
{
	int retorno = -1;

		if(this !=  NULL && isEmpty >= 0)
		{
			this->isEmpty=isEmpty;
			retorno= 1;
		}
	return retorno;
}

int jug_getIsEmpty(Jugador* this,int* isEmpty)
{
	int retorno = -1;

	if(this !=  NULL && isEmpty !=  NULL)
	{
		*isEmpty= this->isEmpty;
		retorno= 1;
	}

	return retorno;
}
*/
