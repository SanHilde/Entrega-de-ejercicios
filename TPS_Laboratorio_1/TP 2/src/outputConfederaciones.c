
#include "outputConfederaciones.h"

int decodificacionId (eConfederaciones *estructura, int *idAIdentificar, char *pIdIdentificado)
{
	char auxConfederacion[CANT_CARACTERES];
	int retorno= ERROR;
	int bandera=ERROR;

	for( int j=0; j<CANT_CONF; j++ )
	{
		if( *idAIdentificar == (estructura+j)->id )
		{
			strcpy (auxConfederacion, (estructura+j)->nombre);
			bandera = OK;
			break;
		}
	}
	if (bandera == OK)
	{
		retorno = OK;
		strcpy (pIdIdentificado, auxConfederacion);
	}
	return retorno;
}

int decodificacionIdRegion (eConfederaciones *estructura, int *idAIdentificar, char *pIdIdentificado)
{
	char auxConfederacion[CANT_CARACTERES];
	int retorno= ERROR;
	int bandera=ERROR;

	for( int j=0; j<CANT_CONF; j++ )
	{
		if( *idAIdentificar == (estructura+j)->id )
		{
			strcpy (auxConfederacion, (estructura+j)->region);
			bandera = OK;
			break;
		}
	}
	if (bandera == OK)
	{
		retorno = OK;
		strcpy (pIdIdentificado, auxConfederacion);
	}
	return retorno;
}

void impresionDeCuadroConfederaciones (int cantColumnas)
{
	int total = COLUMNA_UNO_CONF+COLUMNA_DOS_CONF+COLUMNA_TRES_CONF+COLUMNA_CUATRO_CONF;

	impresionFila (total,cantColumnas, "=");
	printf ("\n|%-7s|%-15s|%-25s|A%cO DE CREACION|\n", "ID", "NOMBRE", "REGION", 165);
	impresionFila (total,cantColumnas, "-");
}

void impresionFila (int cantCaracteres, int cantColumnas, char *caracter)
{
		for (int i=0; i<cantCaracteres+cantColumnas;i++)
		{
			printf ("%s", caracter);
		}
}

int listaConfederaciones( eConfederaciones *confederacion, char* mensajeError, int cantColumnas)
{
	int retorno = ERROR;
	int total = COLUMNA_UNO_CONF+COLUMNA_DOS_CONF+COLUMNA_TRES_CONF+COLUMNA_CUATRO_CONF;
   if(verificarLlenoConfederacion(confederacion) == OK)
   {
	   impresionDeCuadroConfederaciones (cantColumnas);
	   for(int i=0; i<CANT_CONF; i++)
	   {
		   if((confederacion+i)->isEmpty == OCUPADO)
		   {
			   mostrarDatoConfederacion(confederacion, i, mensajeError);
		   }
	   }
	   printf ("\n");
	   impresionFila (total,cantColumnas,"-");
	   retorno = OK;
   }
   else
   {
	   printf("%s", mensajeError);
   }
   return retorno;
}

void mostrarDatoConfederacion( eConfederaciones *confederacion,int indice, char* mensajeError)
{

	if(indice > ERROR)
	{
		printf("\n|%-7d|%-15s|%-25s| \t%d\t  |", (confederacion+indice)->id,(confederacion+indice)->nombre,(confederacion+indice)->region,
								(confederacion+indice)->anioCreacion);
	}
	else
	{
		printf("%s", mensajeError);
	}
}



int rellenoDeVariable (char *cadena, int len)
{
	int cantCaract;
	char caractFaltantes[]= (" ");
	int retorno = ERROR;
	cantCaract = strlen (cadena);
	if (cantCaract<len)
	{
		for (int i=0; i<len-cantCaract;i++)
		{
			strcat (cadena, caractFaltantes);
		}
	}
	cantCaract = strlen (cadena);
	if (cantCaract==len)
	{
		retorno = OK;
	} else
	{
		cadena[ strlen (cadena)-1] = '\0' ;
		printf ("\nLa palabra superaba el limite de caracteres. Revisar codigo.");
	}
return retorno;
}

int rellenoDeVariableCentrado (char *cadena, int len)
{
	int cantCaract;
	int cantCaractFinal;
	char cadenaAux[] = (" ");
	int retorno = ERROR;
	int lenCentrado;

	cantCaract = strlen (cadena);
	printf ("\ncadena traida: %s",cadena);
	lenCentrado = (len-cantCaract)/2;
	//cadenaAux[strlen (cadenaAux)-1] = ' ' ;
	printf ("\nlen: %d, cant caract: %d, lenCentrado: %d, cadenaAux: %s", len, cantCaract, lenCentrado, cadenaAux);
	rellenoDeVariable (cadenaAux,lenCentrado);
	//strcpy (cadenaAuxDos, cadenaAux);
	//printf ("\ncantidad de espacios: %d", lenCentrado);
	//printf ("\ncadena: %s",cadena );
	printf ("\nespacios: %s",cadenaAux );
	//if (cantCaract<len)
//	{
		//for (int i=0; i<(len-cantCaract)/2;i++)
		//{
			//strcat (cadenaAux, caractFaltantes);
	//	}
//}

	strcat (cadenaAux, cadena);

	//cadenaAux[strlen (cadenaAux)-1] = '\0' ;
	strcpy (cadena,cadenaAux);
	rellenoDeVariable (cadena,len);
	printf ("\ncadena copiada:%s",cadena);
	cantCaractFinal = strlen (cadena);

	if (cantCaractFinal==len)
	{
		retorno = OK;
	} else
	{
		cadena[ strlen (cadena)-1] = '\0' ;
		printf ("\nLa palabra superaba el limite de caracteres. Revisar codigo.");
	}
return retorno;
}

int respuesta (int valor)
{
	switch(valor)
	{
		case -1:
			printf("\nHubo un error en la operacion.\n\n");
			break;
		case 0:
			printf("\nOperacion cancelada.\n\n");
			break;
		case 1:
			printf("\nSe realizo la operacion con exito.\n\n");
			break;
	}
	return valor;
}

int verificarLlenoConfederacion(eConfederaciones *estructura)
{
	int retorno;
	retorno = ERROR;

	for(int i=0; i<CANT_CONF; i++)
    {
	   if((estructura+i)->isEmpty == OCUPADO)
	   {
		   retorno = OK;
		   break;
	   }
    }
	return retorno;
}

