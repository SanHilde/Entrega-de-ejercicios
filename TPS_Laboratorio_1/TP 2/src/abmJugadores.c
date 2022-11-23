
#include "abmJugadores.h"

int altaDatosJugador(eJugadores *estructura, eConfederaciones *estructuraDos, char* mensajeErrorGetNumero, char* mensajeErrorGetNumeroPositivo,
				char* mensajeErrorGetCadena, int cantConf)
{
	int retorno;
	int indiceIncremental;
	int calculoAux;

	char mensajeErrorCarga[] = ("Hubo un error en la carga de datos. Se volvera al menu principal.\n\n");
	calculoAux = 99+ cantConf;
	retorno = ERROR;
	buscarLibreJugador(estructura,&indiceIncremental);

	if(indiceIncremental > ERROR)
	{
		(estructura+indiceIncremental)->id = indiceIncremental+1;
		if (utn_getCadena((estructura+indiceIncremental)->nombre, CANT_CARACTERES, "\nIngrese nombre del jugador: ",
							mensajeErrorGetCadena,INTENTOS)==OK &&
		utn_getNumeroShort (&(estructura+indiceIncremental)->numeroCamiseta,"\nIngrese la camiseta (mayor a 0) del jugador: ",
						mensajeErrorGetNumero, 1,99,INTENTOS)==OK &&
		listaConfederaciones(estructuraDos, mensajeErrorCarga, 4)==OK &&
		utn_getNumeroInt (&(estructura+indiceIncremental)->idConfederacion,"\nIngrese el ID de la confederacion del jugador: ",
							mensajeErrorGetNumero, 100,calculoAux,INTENTOS)== OK &&
		utn_getNumeroFloatSinMax (&(estructura+indiceIncremental)->salario,"\nIngrese el salario del jugador: ",
							mensajeErrorGetNumeroPositivo, 1,INTENTOS) == OK &&
		utn_getNumeroShort (&(estructura+indiceIncremental)->aniosContrato,"\nIngrese la cantidad de anios por la cual firmo el jugador: ",
							mensajeErrorGetNumeroPositivo, 1,10,INTENTOS)==OK &&
		utn_getCadena((estructura+indiceIncremental)->posicion, CANT_CARACTERES, "\nIngrese posicion del jugador\n"
						"Arquero-Defensor-Mediocampista-Delantero\nPosicion: ",mensajeErrorGetCadena,INTENTOS)==OK &&
		correccionMayusculasCadena ((estructura+indiceIncremental)->nombre)==OK &&
		correccionMayusculasCadena ((estructura+indiceIncremental)->posicion)== OK &&
		validarPosicion ((estructura+indiceIncremental)->posicion,mensajeErrorGetCadena )== OK)
		{
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

int bajarDatoJugador(eJugadores *estructura,char *mensaje, char *mensajeError, int minimo, int intentos )
{
	int idABajar;
	int retorno=ERROR;
	int i;
	char confirmacion;

	if (utn_getNumeroIntSinMax(&idABajar, mensaje, mensajeError, minimo, intentos)==OK)
	{
		buscarDatoJugador(estructura,idABajar,&i);
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

int buscarDatoJugador(eJugadores *estructura,int datoABuscar, int* indice)
{

	int retorno = ERROR;
	*indice = ERROR;

	for(int i=0; i<CANT_JUGADORES; i++)
    {
	   if(	(estructura+i)->isEmpty == OCUPADO && 	(estructura+i)->id == datoABuscar)
	   {
		   *indice = i;
		   retorno = OK;
		   break;
	   }
    }

	return retorno;
}

int buscarLibreJugador(eJugadores *estructura , int *indice)
{

	*indice = ERROR;

	for(int i=0; i<CANT_JUGADORES; i++)
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

int hardCodeoJugadores (eJugadores *estructura, int cantidad, short *indiceIncremental)
{
	eJugadores aux[]={
			{1, "Lionel Messi", "Delantero", 10, 101, 200000.00,4, OCUPADO},
			{2, "Givanildo Vieira (Hulk)","Delantero",7, 100, 100000.00, 3, OCUPADO},
			{3, "Mohamed El Shenawy","Arquero",1, 103, 80000.00, 2, OCUPADO},
			{4, "Enzo Copetti","Delantero", 11, 100, 86000.00, 4, OCUPADO}};

	int retorno =ERROR;
	int i;
	if (cantidad>0)
	{
		for (i=0; i<cantidad; i++)
		{
			*(estructura+i) = aux[i];
		}
		retorno =OK;
		*indiceIncremental=i;
	}
	return retorno;
}

int inicializadorJugadores (eJugadores *estructura)
{
	int retorno=ERROR;
	if(CANT_JUGADORES > 0)
	{
		for(int i=0; i<CANT_JUGADORES; i++)
		{
			(estructura+i)->isEmpty = LIBRE;
		}
		retorno =OK;
	}
	return retorno;
}

int modificarAniosContratoJugador(eJugadores *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo)
{
	int idAModificiar;
	int modificacion;
	int i;
	char confirmacion;
	int retorno=ERROR;

	if (utn_getNumeroIntSinMax(&idAModificiar, mensaje, mensajeError, minimo, INTENTOS )==OK)
	{
		buscarDatoJugador(estructura,idAModificiar, &i);

		if(i > ERROR)
		{
		   if (utn_getNumeroIntSinMax(&modificacion,"Ingrese el nuevo numero (mayor a 0) de anios de contrato del jugador: ","\nError, el numero debe ser"
				   "mayor a 0.\n",1, INTENTOS)==OK)
		   {
			   pedirConfirmacion ( &confirmacion,INTENTOS);
				if(confirmacion == 'S')
			   {
				   (estructura+i)->aniosContrato=modificacion;
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
		} else
		{
			printf ("\nNo se encontro el ID.\n");
		}
	}
	return retorno;
}

int modificarCamisetaJugador(eJugadores *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo)
{
	int idAModificiar;
	int modificacion;
	int i;
	char confirmacion;
	int retorno=ERROR;

	if (utn_getNumeroIntSinMax(&idAModificiar, mensaje, mensajeError, minimo, INTENTOS )==OK)
	{
		buscarDatoJugador(estructura,idAModificiar, &i);

		if(i > -1)
		{
		   if (utn_getNumeroIntSinMax(&modificacion,"Ingrese el nuevo numero (mayor a 0) de camiseta del jugador: ","Error, el numero debe ser mayor"
				   "a 0.\n",1, INTENTOS)==OK)
		   {
			   pedirConfirmacion ( &confirmacion,INTENTOS);
				if(confirmacion == 'S')
			   {
				   (estructura+i)->numeroCamiseta=modificacion;
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

int modificarConfederacionJugador(eJugadores *estructura, eConfederaciones *estrucutraDos, char* mensaje, char* mensajeError,
		char* mensajeErrorCarga, char* mensajeErrorCadena, int minimo, int cantConf)
{
	int idAModificiar;
	int modificacion;
	int i;
	char confirmacion;
	int retorno=ERROR;
	int calculoAux = 100+cantConf;


	if (utn_getNumeroIntSinMax(&idAModificiar, mensaje, mensajeError, minimo, INTENTOS )==OK)
	{
		buscarDatoJugador(estructura,idAModificiar, &i);

		if(i > ERROR)
		{
			listaConfederaciones(estrucutraDos, mensajeErrorCarga, 4);
		   if (utn_getNumeroInt(&modificacion,"\nIngrese el nuevo ID de confederacion del jugador: ",mensajeError,100,calculoAux, INTENTOS)==OK)
		   {
			   pedirConfirmacion ( &confirmacion,INTENTOS);
				if(confirmacion == 'S')
			   {
				   (estructura+i)->idConfederacion=modificacion;
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
		} else
		{
			printf ("\nNo se encontro el ID.\n");
		}
	}
	return retorno;
}

int modificarNombreJugador(eJugadores *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo)
{
	int idAModificiar;
	char modificacion[CANT_CARACTERES];
	int i;
	char confirmacion;
	int retorno=ERROR;

	if (utn_getNumeroIntSinMax(&idAModificiar, mensaje, mensajeError, minimo, INTENTOS )==OK)
	{
		buscarDatoJugador(estructura,idAModificiar, &i);

		if(i > ERROR)
		{

		   if (utn_getCadena(modificacion,CANT_CARACTERES,"Ingrese el nuevo nombre del jugador: ",mensajeErrorCadena, INTENTOS)==OK)
		   {
			   pedirConfirmacion ( &confirmacion,INTENTOS);
				if(confirmacion == 'S')
			   {
				   strcpy((estructura+i)->nombre,modificacion);
				   if (correccionMayusculasCadena ((estructura+i)->nombre)== OK)
				   {
					   retorno = OK;
				   }
			   }
			   else
			   {
				   retorno =CANCELAR;
			   }
		   }else
		   {
		   retorno =ERROR;
		   }
		} else
		{
			printf ("\nNo se encontro el ID.\n");
		}
	}
	return retorno;
}

int modificarPosicionJugador(eJugadores *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo)
{
	int idAModificiar;
	char modificacion[CANT_CARACTERES];
	int i;
	char confirmacion;
	int retorno=ERROR;

	if (utn_getNumeroIntSinMax(&idAModificiar, mensaje, mensajeError, minimo, INTENTOS )==OK)
	{
		buscarDatoJugador(estructura,idAModificiar, &i);

		if(i > ERROR)
		{

		   if (utn_getCadena(modificacion,CANT_CARACTERES,"\nIngrese la nueva posicion del jugador\n"
					"Arquero-Defensor-Mediocampista-Delantero\nPosicion: ",mensajeErrorCadena, INTENTOS)==OK &&
			correccionMayusculasCadena (modificacion) == OK &&
			validarPosicion (modificacion,mensajeErrorCadena )== OK)
		   {
			   pedirConfirmacion ( &confirmacion,INTENTOS);
				if(confirmacion == 'S')
			   {
				   strcpy((estructura+i)->posicion,modificacion);
					if (correccionMayusculasCadena ((estructura+i)->posicion)== OK )
					{
						retorno = OK;
					}
			   }
			   else
			   {
				   retorno =CANCELAR;
			   }
		   }else
		   {
		   retorno =ERROR;
		   }
		} else
		{
			printf ("\nNo se encontro el ID.\n");
		}
	}
	return retorno;
}

int modificarSalarioJugador(eJugadores *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo)
{
	int idAModificiar;
	float modificacion;
	int i;
	char confirmacion;
	int retorno=ERROR;

	if (utn_getNumeroIntSinMax(&idAModificiar, mensaje, mensajeError, minimo, INTENTOS )==OK)
	{
		buscarDatoJugador(estructura,idAModificiar, &i);

		if(i > ERROR)
		{
		   if (utn_getNumeroFloatSinMax(&modificacion,"Ingrese el nuevo salario del jugador: ","\nError, el numero debe ser"
				   "mayor a 0.\n",1, INTENTOS)==OK)
		   {
			   pedirConfirmacion ( &confirmacion,INTENTOS);
				if(confirmacion == 'S')
			   {
				   (estructura+i)->salario=modificacion;
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
		} else
		{
			printf ("\nNo se encontro el ID.\n");
		}
	}
	return retorno;
}

void ordenarPorConfederacion (eJugadores *estructura, eConfederaciones *estructuraDos)
{
	int i;
	int j;
	int k;
	int l;
	int auxConfUno;
	int auxConfDos;
	eJugadores aux;

	for( i=0; i<CANT_JUGADORES-1; i++)
	{
		if ((estructura+i)->isEmpty == OCUPADO)
		{
			for( j=i+1; j<CANT_JUGADORES; j++ )
			{
				if((estructura+j)->isEmpty == OCUPADO)
				{
					if ((estructura+i)->idConfederacion!=(estructura+j)->idConfederacion)

					{
						for( k=0; k<CANT_CONF; k++ )
						{
							if( (estructura+i)->idConfederacion == (estructuraDos+k)->id )
							{
								auxConfUno=k;
								break;
							}

						}
						for( l=0; l<CANT_CONF; l++ )
						{
							if( (estructura+j)->idConfederacion == (estructuraDos+l)->id )
							{
								auxConfDos = l;
								break;
							}
						}
						if (strcmp ((estructuraDos+auxConfUno)->nombre,(estructuraDos+auxConfDos)->nombre)>0)
						{
							aux=*(estructura+i);
							*(estructura+i)=*(estructura+j);
							*(estructura+j)=aux;
						}
					} else
					{
						if ((estructura+i)->idConfederacion==(estructura+j)->idConfederacion)
						{
							if (strcmp ((estructura+i)->nombre,(estructura+j)->nombre)>0)
							{
								aux=*(estructura+i);
								*(estructura+i)=*(estructura+j);
								*(estructura+j)=aux;
							}
						}
					}
				}
			}
		}
	}
}

void ordenarPorId (eJugadores *estructura)
{
	int i;
	int j;
	eJugadores aux;

	for( i=0; i<CANT_JUGADORES-1; i++)
	{
		if ((estructura+i)->isEmpty == OCUPADO)
		{
			for( j=i+1; j<CANT_JUGADORES; j++ )
			{
				if((estructura+j)->isEmpty == OCUPADO)
				{
					if ((estructura+i)->id>(estructura+j)->id)
					{
						aux=*(estructura+i);
						*(estructura+i)=*(estructura+j);
						*(estructura+j)=aux;
					}
				}
			}
		}
	}
}

int correccionMayusculasCadena (char *cadena)
{
	int retorno = ERROR;
	char cadenaAux[CANT_CARACTERES];

	strcpy (cadenaAux,cadena);
	strlwr (cadena);
	*cadena = toupper (*cadena);

	for (int i=0; i<CANT_CARACTERES; i++)
	{
		if (*(cadena+i)== ' ')
		{
			*(cadena+i+1)= toupper (*(cadena+i+1));
		}
	}

	if (strcmp (cadenaAux,cadena)!= 0)
	{
		retorno = OK;
	}

	return retorno;
}

int validarPosicion (char *cadena,char *mensajeErrorGetCadena)
{
	int retorno = ERROR;

	if (cadena != NULL && mensajeErrorGetCadena != NULL)
	{
	while (strcmp(cadena,"Arquero")!=0 &&
			strcmp(cadena, "Defensor")!=0 &&
			strcmp(cadena,"Mediocampista")!=0 &&
			strcmp(cadena,"Delantero" )!= 0)
			{
				printf ("Lo que ingreso no es una posicion de las requeridas.\n");
				utn_getCadena(cadena, CANT_CARACTERES, "\nIngrese posicion del jugador\n"
							"Arquero-Defensor-Mediocampista-Delantero\nPosicion: ",mensajeErrorGetCadena,INTENTOS);
				correccionMayusculasCadena (cadena);
			}
	retorno = OK;
	}
	return retorno;
}
