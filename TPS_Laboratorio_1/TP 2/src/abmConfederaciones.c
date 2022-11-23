
#include "abmConfederaciones.h"

int altaDatosConfederacion(eConfederaciones *estructura, char* mensajeErrorGetNumero, char* mensajeErrorGetNumeroPositivo, char* mensajeErrorGetCadena)
{
	int retorno;
	int indiceIncremental;
	int calculoAux;

	char mensajeErrorCarga[] = ("Hubo un error en la carga de datos. Se volvera al menu principal.\n\n");

	retorno = ERROR;
	buscarLibreConfederacion(estructura,&indiceIncremental);
	calculoAux = 100+ indiceIncremental;

	if(indiceIncremental > ERROR)
	{
		(estructura+indiceIncremental)->id = calculoAux;
		if (utn_getCadena((estructura+indiceIncremental)->nombre, CANT_CARACTERES, "\nIngrese siglas de la confederacion: ",
							mensajeErrorGetCadena,INTENTOS)==OK &&
		utn_getCadena((estructura+indiceIncremental)->region, CANT_CARACTERES, "\nIngrese la region a la que pertenece la confederacion: ",
						mensajeErrorGetCadena,INTENTOS)==OK &&
		utn_getNumeroIntSinMax (&(estructura+indiceIncremental)->anioCreacion,"\nIngrese el anio en el cual se creo la confederacion (debe ser mayor a 1850): ",
							mensajeErrorGetNumero, 1850,INTENTOS)== OK)
		{
			strupr ((estructura+indiceIncremental)->nombre);
			strupr ((estructura+indiceIncremental)->region);
			(estructura+indiceIncremental)->isEmpty=OCUPADO;
			retorno = OK;
		} else
		{
			printf ("%s", mensajeErrorCarga);
		}

	} else
	{
		printf("Lo siento, la lista esta llena.\n");
	}
	return retorno;
}

int bajarDatoConfederacion(eConfederaciones *estructura,char *mensaje, char *mensajeError, int minimo, int intentos, int maximo)
{
	int idABajar;
	int retorno=ERROR;
	int i;
	char confirmacion;

	if (utn_getNumeroInt(&idABajar, mensaje, mensajeError, minimo, maximo, intentos)==OK)
	{
		printf ("aca entre");
		buscarDatoConfederaciones(estructura,idABajar,&i);
		if (i>-1)
		{
			pedirConfirmacion ( &confirmacion,intentos);
			if(confirmacion == 'S')
		   {
				(estructura+i)->isEmpty=INACTIVO;
				retorno = OK;//Encontro al empleado y lo borro
		   }
		   else
		   {
			   retorno = CANCELAR;
		   }
		} else
		{
			printf ("El ID no existe.\n");
			retorno =CANCELAR;
		}
	}
    return retorno;
}

int buscarDatoConfederaciones(eConfederaciones *estructura,int datoABuscar, int* indice)
{

	int retorno = ERROR;
	*indice = ERROR;

	for(int i=0; i<CANT_CONF; i++)
    {
	   if(	(estructura+i)->isEmpty == OCUPADO && 	(estructura+i)->id == datoABuscar)
	   {
		   *indice = i;
		   retorno = OK;
		   printf ("lo encontre");
		   break;
	   }
    }

	return retorno;
}

int buscarLibreConfederacion(eConfederaciones *estructura , int *indice)
{

	*indice = ERROR;

	for(int i=0; i<CANT_CONF; i++)
    {
	   if((estructura+i)->isEmpty == LIBRE)
	   {
		   *indice = i;
		   return OK;
		   break;
	   }
    }

	return ERROR;
}


int hardCodeoConfederaciones (eConfederaciones *estructura, int cantidad,  short *indiceIncremental)
{
	eConfederaciones aux[]={
			{100, "CONMEBOL", "SUDAMERICA", 1916, OCUPADO},
			{101, "UEFA", "EUROPA", 1954, OCUPADO},
			{102, "AFC", "ASIA", 1954, OCUPADO},
			{103, "CAF", "AFRICA", 1957, OCUPADO},
			{104, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961, OCUPADO},
			{105, "OFC", "OCEANIA", 1966, OCUPADO} };

	int retorno =ERROR;
	int i;
	if (cantidad>0)
	{
		for (i=0; i<cantidad; i++)
		{
			*(estructura+i) = aux[i];
		}
		*indiceIncremental=i;
		retorno =OK;
	}
	return retorno;
}

int inicializadorConfederaciones (eConfederaciones *estructura)
{
	int retorno=ERROR;
	if(CANT_CONF > 0)
	{
		for(int i=0; i<CANT_CONF; i++)
		{
			(estructura+i)->isEmpty = LIBRE;
		}
		retorno =OK;
	}
	return retorno;
}

int modificarAnioConfederacion(eConfederaciones *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo, int maximo)
{
	int idAModificiar;
	int modificacion;
	int i;
	char confirmacion;
	int retorno=ERROR;


	if (utn_getNumeroInt(&idAModificiar, mensaje, mensajeError, minimo, maximo, INTENTOS )==OK)
	{
		buscarDatoConfederaciones(estructura,idAModificiar, &i);

		if(i > ERROR)
		{
		   if (utn_getNumeroIntSinMax(&modificacion,"Ingrese el nuevo anio de creacion de confederacion: ",
				   "\nError, el numero debe ser mayor a 1850.\n\n",1850, INTENTOS)==OK)
		   {
			   pedirConfirmacion ( &confirmacion,INTENTOS);
				if(confirmacion == 'S')
			   {
				   (estructura+i)->anioCreacion=modificacion;
				   retorno = OK;
			   }
			   else
			   {
				   retorno =CANCELAR;
			   }
		   }else
		   {
		   retorno =ERROR;
		   }
		}
	}
	return retorno;
}

int modificarNombreConfederacion(eConfederaciones *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo, int maximo)
{
	int idAModificiar;
	char modificacion[CANT_CARACTERES];
	int i;
	char confirmacion;
	int retorno=ERROR;

	if (utn_getNumeroInt(&idAModificiar, mensaje, mensajeError, minimo, maximo, INTENTOS )==OK)
	{
		buscarDatoConfederaciones(estructura,idAModificiar, &i);

		if(i > ERROR)
		{

		   if (utn_getCadena(modificacion,CANT_CARACTERES,"Ingrese las nuevas siglas de la confederacion: ",mensajeErrorCadena, INTENTOS)==OK)
		   {
			   pedirConfirmacion ( &confirmacion,INTENTOS);
				if(confirmacion == 'S')
			   {
				   strcpy((estructura+i)->nombre,modificacion);
				   strupr ((estructura+i)->nombre);
				   retorno = OK;
			   }
			   else
			   {
				   retorno =CANCELAR;
			   }
		   }else
		   {
		   retorno =ERROR;
		   }
		}
	}
	return retorno;
}

int modificarRegionConfederacion(eConfederaciones *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo, int maximo)
{
	int idAModificiar;
	char modificacion[CANT_CARACTERES];
	int i;
	char confirmacion;
	int retorno=ERROR;

	if (utn_getNumeroInt(&idAModificiar, mensaje, mensajeError, minimo, maximo, INTENTOS )==OK)
	{
		buscarDatoConfederaciones(estructura,idAModificiar, &i);

		if(i > ERROR)
		{

		   if (utn_getCadena(modificacion,CANT_CARACTERES,"Ingrese la nueva region: ",mensajeErrorCadena, INTENTOS)==OK)
		   {
			   pedirConfirmacion ( &confirmacion,INTENTOS);
				if(confirmacion == 'S')
			   {
				   strcpy((estructura+i)->region,modificacion);
				   strupr ((estructura+i)->region);
				   retorno = OK;
			   }
			   else
			   {
				   retorno =CANCELAR;
			   }
		   }else
		   {
		   retorno =ERROR;
		   }
		}
	}
	return retorno;
}


int pedirConfirmacion (char *caracterConfirmacion, int intentos)
{
	int retorno=ERROR;
	do
	{
		if (utn_getCaracter(caracterConfirmacion, "¿Desea realizar la operacion? S/N: ",
				"Lo que se ingreso no es un caracter.\n", intentos)==OK)
		{
			retorno =OK;
		}

		*caracterConfirmacion = toupper (*caracterConfirmacion);
	} while (*caracterConfirmacion != 'S' && *caracterConfirmacion !='N');

	return retorno;
}
