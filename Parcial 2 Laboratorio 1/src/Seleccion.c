#include "Seleccion.h"
#include <stdio.h>
#include <stdlib.h>

Seleccion* selec_new()
{
	Seleccion* pSeleccion;

	pSeleccion = (Seleccion*) malloc(sizeof(Seleccion));
	if (pSeleccion!= NULL)
	{
	 return pSeleccion;
	} else
	{
		printf ("Memoria llena.\n");
		return NULL;
	}
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	Seleccion* pSeleccion;
	int auxId;
	int auxConvocados;

	auxId = atoi(idStr);
	auxConvocados = atoi(convocadosStr);

	pSeleccion = selec_new();

	if(pSeleccion != NULL)
	{
		if (selec_setConvocados(pSeleccion,auxConvocados)== 1)
		{
			pSeleccion->id=auxId;
			strcpy(pSeleccion->pais,paisStr);
			strcpy(pSeleccion->confederacion,confederacionStr);
		} else
		{
			printf ("Hubo un error en la carga de la seleccion de id: %d\n", auxId);
			pSeleccion= NULL;
		}
	}
	return pSeleccion;
}

void selec_delete(Seleccion* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int selec_setId(Seleccion* this,int id)
{
int retorno = -1;

	if(this !=  NULL && id >0)
	{
		this->id=id;
		retorno= 1;
	}
	return retorno;
}

int selec_getId(Seleccion* this,int* id)
{
	int retorno = -1;

	if(this !=  NULL && id!=  NULL)
	{
		*id= this->id;
		retorno= 1;
	}

	return retorno;
}

int selec_setPais(Seleccion* this,char* pais)
{
	int retorno = -1;

	if(this !=  NULL && pais !=NULL)
	{
		strcpy(this->pais,pais);
		retorno= 1;
	}
	return retorno;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = -1;

	if(this !=  NULL && pais !=NULL)
	{
		strcpy(pais, this->pais);
		retorno= 1;
	}
	return retorno;
}

int selec_setConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;

	if(this !=  NULL && confederacion >=0)
	{
		strcpy(this->confederacion,confederacion);
		retorno= 1;
	}
	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;

	if(this !=  NULL && confederacion !=NULL)
	{
		strcpy(confederacion, this->confederacion);
		retorno= 1;
	}
	return retorno;
}
/*
int selec_setIsEmpty(Seleccion* this,int isEmpty)
{
	int retorno = -1;

	if(this !=  NULL && isEmpty >=0)
	{
		this->isEmpty=isEmpty;
		retorno= 1;
	}
	return retorno;
}

int selec_getIsEmpty(Seleccion* this,int* isEmpty)
{
	int retorno = -1;

	if(this !=  NULL && isEmpty!=  NULL)
	{
		*isEmpty= this->isEmpty;
		retorno= 1;
	}

	return retorno;
}
*/

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;

	if(this !=  NULL && convocados >=0)
	{
		this->convocados=convocados;
		retorno= 1;
	}
	return retorno;
}

int selec_getConvocados(Seleccion* this,int* convocados)
{
	int retorno = -1;

	if(this !=  NULL && convocados!=  NULL)
	{
		*convocados= this->convocados;
		retorno= 1;
	}

	return retorno;
}
