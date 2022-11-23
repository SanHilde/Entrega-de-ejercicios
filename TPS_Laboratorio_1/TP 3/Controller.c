
#include "Controller.h"

#define INTENTOS 3


/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE* listaAux=NULL;

	int retorno =-1;

	if (pArrayListJugador != NULL && path != NULL)
	{
		if ((listaAux = fopen(path,"r")) != NULL)
		{
			if (parser_JugadorFromText(listaAux , pArrayListJugador) == OK)
			{
				retorno = 1;
			}
		} else
		{
			printf ("\nHubo un error al abrir el archivo.");
		}


	} else
	{
		printf ("\nHubo un error en la carga de la lista.");
	}

	fclose(listaAux);
	return retorno;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	FILE* listaAux=NULL;

		int retorno =-1;

		if (pArrayListJugador != NULL && path != NULL)
		{
			if ((listaAux = fopen(path,"rb")) != NULL )
			{
				if (parser_JugadorFromBinary(listaAux , pArrayListJugador) == OK)
				{
					retorno = 1;
				}
			}else
			{
				printf ("\nHubo un error al abrir el archivo.");
			}
		} else
		{
			printf ("\nHubo un error en la carga de la lista.");
		}

		fclose(listaAux);
		return retorno;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	char id[30];
	int idAux;
	char nombreCompleto[100];
	int edad;
	char edadAux[30];
	char posicion[30];
	char nacionalidad[30];
	char idSeleccion[]=("0");
	char mensajeErrorGetCadena[] = ("El texto solicitado supero el limite de caracteres o no ingreso solo letras (no usar espacios).\n");
	char mensajeErrorGetNumero[] = ("El dato ingresado esta fuera del rango solicitado.\n");
	int cantCaracteresTitulo;
	char auxTitulo[30];
	char confirmacion;
	char auxPosicion[30];
	char caracterIntermedio[] = (" ");
	int control;
	Jugador* pJugador=NULL;
	FILE* listaAux=NULL;

	if (pArrayListJugador != NULL )
	{
		if (output_obtenerIdMax (&idAux)==1)
		{
			if (controller_generarNombreCompleto (nombreCompleto) == 1 &&
			utn_getNumeroInt (&edad,"\nIngrese la edad (mayor a 16 y menor a 80) del jugador: ",mensajeErrorGetNumero, 16,80,INTENTOS) == 1 &&
			utn_getCadena(nacionalidad, 30, "\nIngrese la nacionalidad del jugador: ",mensajeErrorGetCadena,INTENTOS)== 1 &&
			utn_getCadena(posicion, 30, "\nIngrese la posicion del jugador: ",mensajeErrorGetCadena,INTENTOS) == 1 )
			{
				printf ("¿Desea aclarar el carril de la posicion? Ej: izquierdo, derecho o central.\n");
				output_pedirConfirmacion (&confirmacion,INTENTOS);
				if (confirmacion=='S')
				{
					if (utn_getCadena(auxPosicion, 30, "\nEspecifique el carril de la posicion del jugador: ",mensajeErrorGetCadena,INTENTOS) == 1 )
					{
						control = output_combinarCadenasConCaracter (posicion, auxPosicion, caracterIntermedio);
					}
				}
				sprintf(edadAux, "%d", edad);
				sprintf(id, "%d", idAux);
				control = output_correccionMayusculasCadena (nombreCompleto);
				control = output_correccionMayusculasCadena (posicion);
				control = output_correccionMayusculasCadena (nacionalidad);
				pJugador = jug_newParametros(id,nombreCompleto,edadAux,posicion,nacionalidad,idSeleccion);
				if (pJugador != NULL)
				{
					if (ll_add (pArrayListJugador, pJugador) == 0)
					{
						idAux++;
						sprintf(id, "%d", idAux);
						if ((listaAux = fopen("IdUnicoAutonomo.csv","w")) != NULL)
						{
							strcpy (auxTitulo,"Proximo ID a usar: ");
							strcat (auxTitulo, id);
							cantCaracteresTitulo=strlen (auxTitulo);
							if (fwrite(&auxTitulo,sizeof(char),cantCaracteresTitulo,listaAux)<cantCaracteresTitulo)
							{
								printf ("\nHubo un error al intentar escribir en el archivo.");
								retorno = -1;
							} else
							{
								retorno = 1;
							}
							fclose(listaAux);
						}else
						{
							printf ("\nHubo un error al abrir el archivo.");
						}
					}else
					{
						printf ("Error al cargar el dato a la linked list.\n");
					}
				}else
				{
					printf ("Error al generar el puntero del jugador.\n");
				}
			}else
			{
				printf ("Error al guardas el dato recien escrito.\n");
			}
		} else
		{
			printf ("No se pudo abrir el archivo");
		}
	} else
	{
		printf ("Error al leer el puntero a la linked list.\n");
	}

	if (control == ERROR)
	{
		printf ("Hubo un error en las correccion de los textos. Revisar codigo.\n");
		retorno = ERROR;
	}
    return retorno;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */

int controller_editarJugador(LinkedList* pArrayListJugador)
{
    int retorno =-1;
	int opcionSubMenu;
	int numeroMinimoValidacion = 1;
	char mensajeErrorGetNumero[] = ("El dato ingresado esta fuera del rango solicitado.\n");
	char mensajeErrorGetCadena[] = ("El texto solicitado supero el limite de caracteres o no ingreso solo letras (no usar espacios).\n");
	char mensajeErrorID[] = ("El ID ingresado no existe.");
	char mensajeSalida[] = ("Usted selecciono salir, vuelve al menu anterior.\n\n");
	char mensajeErrorDato[] =("\nHubo un error en el guardado del dato. Se cancelo la operacion.\n");
	char mensajeErrorCarga[] =("\nHubo un error en la carga del dato. Se cancelo la operacion.\n");
	char mensajeEscape[] = ("\nIngrese 0 para cancelar.\n");
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idMax;
	int indiceJugador;
	int idJugador;
	char confirmacion;
	char auxPosicion[30];
	char caracterIntermedio[] = (" ");
	int control;
	Jugador* pJugador= NULL;

    if (pArrayListJugador != NULL && output_obtenerIdMax (&idMax) == 1)
    {
    	do{
			if (utn_getNumeroInt(&opcionSubMenu,
							"\n\n\tSubMenu modificacion\n"
							"Seleccione que desea modificar:\n"
							"1-Nombre\n"
							"2-Edad\n"
							"3-Posicion\n"
							"4-Nacionalidad\n"
							"5-Salir\n"
							"Numero ingresado: ",
							mensajeErrorGetNumero,
							numeroMinimoValidacion,
							5,
							INTENTOS)==1)
			{

				printf ("%s", mensajeEscape);
				switch (opcionSubMenu)
				{
					case 1:
						do
						{
							if (utn_getNumeroInt (&idJugador,"\nIngrese el id del jugador que desea modificar: ",mensajeErrorGetNumero, 0,idMax-1,
								INTENTOS)== 1 && idJugador !=0)
							{
								if( controller_buscarJugador (pArrayListJugador,idJugador, &indiceJugador) == 1)
								{
									pJugador = ll_get (pArrayListJugador, indiceJugador);
									if (controller_generarNombreCompleto (nombreCompleto) == 1)
									{
										control = output_correccionMayusculasCadena (nombreCompleto);
										if ( jug_setNombreCompleto (pJugador, nombreCompleto) == 1)
										{
											opcionSubMenu = 5;
											retorno = 1;
											break;
										} else
										{
											printf ("%s", mensajeErrorCarga);
											break;
										}
									} else
									{
										printf ("%s", mensajeErrorDato);
										break;
									}
								} else
								{
									printf ("%s",mensajeErrorID);
									break;
								}
							}  else
							{
								printf ("%s", mensajeErrorDato);
								break;
							}
						} while (idJugador != 0 );
						break;
					case 2:
						do
						{
							if (utn_getNumeroInt (&idJugador,"\nIngrese el id del jugador que desea modificar: ",mensajeErrorGetNumero, 0,idMax-1,
								INTENTOS)== 1 && idJugador !=0)
							{
								if( controller_buscarJugador (pArrayListJugador,idJugador, &indiceJugador) == 1)
								{
									pJugador = ll_get (pArrayListJugador, indiceJugador);
									if (utn_getNumeroInt (&edad,"\nIngrese la edad (mayor a 16 y menor a 80) del jugador: ",
											mensajeErrorGetNumero, 16,80,INTENTOS)== 1)
									{
										if (jug_setEdad (pJugador, edad) == 1)
										{
											opcionSubMenu = 5;
											retorno = 1;
											break;
										} else
										{
											printf ("%s", mensajeErrorCarga);
											break;
										}
									} else
									{
										printf ("%s", mensajeErrorDato);
										break;
									}
								} else
								{
									printf ("%s",mensajeErrorID);
									break;
								}
							}  else
							{
								printf ("%s", mensajeErrorDato);
								break;
							}
						} while (idJugador != 0 );
						break;
					case 3:
						do
						{
							if (utn_getNumeroInt (&idJugador,"\nIngrese el id del jugador que desea modificar: ",mensajeErrorGetNumero, 0,idMax-1,
								INTENTOS)== 1 && idJugador !=0)
							{
								if( controller_buscarJugador (pArrayListJugador,idJugador, &indiceJugador) == 1)
								{
									pJugador = ll_get (pArrayListJugador, indiceJugador);
									if (utn_getCadena(posicion, 30, "\nIngrese la posicion del jugador: ",mensajeErrorGetCadena,INTENTOS)== 1)
									{
										control = output_correccionMayusculasCadena (posicion);
										if ( jug_setPosicion (pJugador, posicion) == 1)
										{
											printf ("¿Desea aclarar el carril de la posicion? Ej: izquierdo, derecho o central.\n");
											output_pedirConfirmacion (&confirmacion,INTENTOS);
											if (confirmacion=='S')
											{
												if (utn_getCadena(auxPosicion, 30, "\nEspecifique el carril de la posicion del jugador: ",mensajeErrorGetCadena,INTENTOS) == 1 )
												{
													control = output_combinarCadenasConCaracter (posicion, auxPosicion, caracterIntermedio);
												}
											}
											opcionSubMenu = 5;
											retorno = 1;
											break;
										} else
										{
											printf ("%s", mensajeErrorCarga);
											break;
										}
									} else
									{
										printf ("%s", mensajeErrorDato);
										break;
									}
								} else
								{
									printf ("%s",mensajeErrorID);
									break;
								}
							}  else
							{
								printf ("%s", mensajeErrorDato);
								break;
							}
						} while (idJugador != 0 );
						break;
					case 4:
						do
						{
							if (utn_getNumeroInt (&idJugador,"\nIngrese el id del jugador que desea modificar: ",mensajeErrorGetNumero, 0,idMax-1,
								INTENTOS)== 1 && idJugador !=0)
							{
								if( controller_buscarJugador (pArrayListJugador,idJugador, &indiceJugador) == 1)
								{
									pJugador = ll_get (pArrayListJugador, indiceJugador);
									if (utn_getCadena(nacionalidad, 30, "\nIngrese la nacionalidad del jugador: ",mensajeErrorGetCadena,INTENTOS)== 1)
									{
										control = output_correccionMayusculasCadena (nacionalidad);
										if ( jug_setNacionalidad (pJugador, nacionalidad) == 1)
										{
											opcionSubMenu = 5;
											retorno = 1;
											break;
										} else
										{
											printf ("%s", mensajeErrorCarga);
											break;
										}
									} else
									{
										printf ("%s", mensajeErrorDato);
										break;
									}
								} else
								{
									printf ("%s",mensajeErrorID);
									break;
								}
							}  else
							{
								printf ("%s", mensajeErrorDato);
								break;
							}
						} while (idJugador != 0 );
						break;
					case 5:
						printf ("%s",mensajeSalida);
						retorno = 1;
						break;
				}
			} else
			{
				printf ("%s", mensajeErrorDato);
				break;
			}
		} while (opcionSubMenu != 5);
    }

    if (control == ERROR)
    {
		printf ("Hubo un error en las correccion de los textos. Revisar codigo.\n");
		retorno = ERROR;
    }
	return retorno;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int idMax;
	int indiceJugador;
	char mensajeEscape[] = ("\nIngrese 0 para cancelar.\n");
	int idJugador=0;
	char mensajeErrorGetNumero[] = ("El dato ingresado esta fuera del rango solicitado.\n");
	char confirmacion;

	Jugador *pJugador;

	if (pArrayListJugador != NULL && output_obtenerIdMax (&idMax) ==1)
	{
		printf ("%s", mensajeEscape);
		if (utn_getNumeroInt (&idJugador,"\nIngrese el id del jugador que desea quitar: ",mensajeErrorGetNumero, 0,idMax-1,
				INTENTOS)== 1)
		{
			if (idJugador !=0)
			{
				if (controller_buscarJugador (pArrayListJugador,idJugador, &indiceJugador) == 1)
				{
					pJugador = ll_get (pArrayListJugador, indiceJugador);
					if (output_pedirConfirmacion(&confirmacion,INTENTOS)== OK)
					{
						if (confirmacion=='S')
						{
							if(ll_remove(pArrayListJugador,indiceJugador)==0)
							{
								jug_delete(pJugador);
								retorno = 1;
							} else
							{
								printf ("Error al liberar la memoria de la linkedlist.\n");
							}
						} else
						{
							retorno = 0;
						}
					} else
					{
						printf ("Error al guardar la confirmacion.\n");
					}
				} else
				{
					printf ("El ID ingresado no existe");
				}
			}
		} else
		{
			printf ("Error al guardar el dato.\n");
		}
	}

	if (idJugador == 0 )
	{
		retorno = 0;
	}
	return retorno;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* pJugador;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	char mensajeError[] = ("Hubo un error al cargar al jugador");
	int cantJugadores;


	if (pArrayListJugador != NULL )
	{
		cantJugadores =  ll_len(pArrayListJugador);

		for (int i=0; i<cantJugadores; i++)
		{
			pJugador= ll_get(pArrayListJugador,i);

			if (jug_getId(pJugador,&id) == OK &&
			 jug_getNombreCompleto( pJugador,nombreCompleto)== OK &&
			 jug_getPosicion(pJugador,posicion)== OK &&
			 jug_getNacionalidad( pJugador,nacionalidad)== OK &&
			 jug_getEdad(pJugador,&edad)== OK &&
			 jug_getSIdSeleccion(pJugador,&idSeleccion)== OK)
			{
				printf("\n|%-5d|%-30s|%-25s|%-20s|%-5d|%-15d|",id,nombreCompleto,posicion,nacionalidad,edad,idSeleccion);
			} else
			{
				printf("%s", mensajeError);
			}
		}
		retorno = 1;

	} else
	{
		printf("Error al obtener la direccion de memoria de linkedlist");
	}
	return retorno;
}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	if (pArrayListJugador != NULL )
	{
		if (ll_sort(pArrayListJugador,controller_ordenarJugadoresPorID , 1)==0)
		{
			retorno =1;
		} else
		{
			printf ("Error al intentar ordenar.\n");
		}
	} else
	{
		printf ("Hubo un error al intentar cargar la linkedlist.\n");
	}

    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno =-1;
	FILE* listaAux= NULL;
	char datoCompleto[300];
	char titulo[200];
	int cantCaracteresTitulo;
	int cantCaracteresDato;
	int bandera=0;

		if (pArrayListJugador != NULL && path != NULL)
		{
			if ((listaAux = fopen(path,"w")) != NULL)
			{
				strcpy (titulo,"id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
				cantCaracteresTitulo=strlen (titulo);

				if (fwrite(&titulo,sizeof(char),cantCaracteresTitulo,listaAux)<cantCaracteresTitulo)
				{
					printf("Error al intentar escribir el titulo.\n");
					retorno = -1;
				} else
				{
					for (int i=0;i<=ll_len (pArrayListJugador); i++)
					{
						if (controller_unificacionDatosJugadores (pArrayListJugador,datoCompleto,i)==1)
						{
							cantCaracteresDato=strlen (datoCompleto);
							if (fwrite(&datoCompleto,sizeof(char),cantCaracteresDato,listaAux)<cantCaracteresDato)
							{
								printf("Error al intentar escribir el dato.\n");
								bandera = 1;
								break;
							}
						} else
						{
							printf ("Error al intentar unificar los datos en una variable\n");
						}
					}
					if (bandera == 0)
					{
					retorno = 1;
					}
				}
				fclose(listaAux);
			}
		}
    return retorno;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno =-1;
	int idMax;
    char confederacionDeco[15];
    int indiceSeleccion;
	int opcionSubMenu;
	int cant;
	int bandera=0;
    char mensajeErrorGetNumero[] = ("El dato ingresado esta fuera del rango solicitado.\n");
	char mensajeSalida[] = ("Usted selecciono salir, vuelve al menu anterior.\n\n");
    char confIngresada[15];
    FILE* listaAux= NULL;
	Jugador* pJugador=NULL;
	LinkedList* listaSeleccion= ll_newLinkedList();

	if (pArrayListJugador != NULL && path != NULL)
	{
		if (output_obtenerIdMax (&idMax) == 1 &&
			utn_getNumeroInt(&opcionSubMenu,
							"\n\n\tFiltrar jugadores segun confederacion\n"
							"Seleccione que desea confederacion desea filtrar:\n"
							"1-AFC\n"
							"2-CAF\n"
							"3-CONCACAF\n"
							"4-CONMEBOL\n"
							"5-UEFA\n"
							"6-Salir\n"
							"Numero ingresado: ",
							mensajeErrorGetNumero,
							1,
							6,
							INTENTOS) == 1)
		{
				switch (opcionSubMenu)
				{
					case 1:
						strcpy (confIngresada,"AFC");
						break;
					case 2:
						strcpy (confIngresada,"CAF");
						break;
					case 3:
						strcpy (confIngresada,"CONCACAF");
						break;
					case 4:
						strcpy (confIngresada,"CONMEBOL");
						break;
					case 5:
						strcpy (confIngresada,"UEFA");
						break;
					case 6:
						printf ("%s", mensajeSalida);
						break;
				}
			if (opcionSubMenu != 6)
			{
				if(controller_cargarSeleccionesDesdeTexto("selecciones.csv" , listaSeleccion)==1 &&
					(listaAux = fopen(path,"wb")) != NULL && output_obtenerIdMax (&idMax) == 1)
				{
					for (int i=0; i<idMax ;i++)
					{
						pJugador = ll_get (pArrayListJugador, i);
						if (jug_getSIdSeleccion (pJugador, &indiceSeleccion)== 1)
						{
							if (indiceSeleccion != 0)
							{
								output_decodificacionConf (listaSeleccion,indiceSeleccion, confederacionDeco);
								if (strcmp (confIngresada, confederacionDeco)==0)
								{
									retorno = 1;
									cant=fwrite(pJugador,sizeof(Jugador),1,listaAux);
									if (cant != 1)
									{
										retorno = -1;
										break;
									}
								}
							}
							bandera = 1;
						}
					}
					fclose(listaAux);
				} else
				{
					printf ("\nHubo un error al abrir y cargar los archivos.");
				}
			}
		}
	}

		ll_deleteLinkedList(listaSeleccion);
		if (bandera == 1 && retorno ==-1)
		{
			printf ("\nNo hay jugadores convocados en esta confederacion. La lista generada estara vacia.");
			retorno = 1;
		}
	return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE* listaAux;
	int retorno =-1;

	if (pArrayListSeleccion != NULL && path != NULL)
	{
		if ((listaAux = fopen(path,"r")) != NULL)
		{
			if (parser_SeleccionFromText(listaAux , pArrayListSeleccion) == OK)
			{
				retorno = 1;
			}
			fclose(listaAux);
		} else
		{
			printf ("\nHubo un error al abrir el archivo.");
		}
	} else
	{
		printf ("\nHubo un error en la carga de la lista.");
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Seleccion* pSeleccion;
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	char mensajeError[] = ("Hubo un error al cargar al jugador");
	int cantSelecciones;
	int cantColumnas=4;
	int cantCaracteres = 5+20+15+10+1;

	if (pArrayListSeleccion != NULL )
	{
		cantSelecciones =  ll_len(pArrayListSeleccion);
		output_impresionFila (cantCaracteres,cantColumnas,'=');
		printf ("\n|%-5s|%-20s|%-15s|%-10s|\n","ID","PAIS"," CONFEDERACION ","CONVOCADOS");
		output_impresionFila (cantCaracteres,cantColumnas,'=');
		for (int i=0; i<cantSelecciones; i++)
		{
			pSeleccion= ll_get(pArrayListSeleccion,i);
			if (selec_getId(pSeleccion,&id) == OK &&
				selec_getPais( pSeleccion,pais)== OK &&
				selec_getConfederacion(pSeleccion,confederacion)== OK &&
				selec_getConvocados( pSeleccion,&convocados)== OK)
			{
				printf("\n|%-5d|%-20s|%-15s|%-10d|",id,pais,confederacion,convocados);
			} else
			{
				printf("%s", mensajeError);
			}
		}
		printf ("\n");
		output_impresionFila (cantCaracteres,cantColumnas,'=');
		printf ("\n");
		retorno = 1;
	} else
	{
		printf("%s", mensajeError);
	}
	return retorno;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{

	int retorno = -1;
	if (pArrayListSeleccion != NULL )
	{
		if (ll_sort(pArrayListSeleccion,controller_ordenarSeleccionPorID , 1)==0)
		{
			retorno =1;
		} else
		{
			printf ("Hubo un error al ordenar los datos.\n");
		}
	} else
	{
		printf ("Hubo un error al intentar cargar la linkedlist.\n");
	}

    return retorno;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{

	int retorno =-1;
	FILE* listaAux= NULL;
	char datoCompleto[300];
	char titulo[200];
	int cantCaracteresTitulo;
	int cantCaracteresDato;
	int bandera=0;

	if (pArrayListSeleccion != NULL && path != NULL)
	{
		if ((listaAux = fopen(path,"w")) != NULL )
		{
			strcpy (titulo,"id,pais,confederacion,convocados\n");
			cantCaracteresTitulo=strlen (titulo);
			if (fwrite(&titulo,sizeof(char),cantCaracteresTitulo,listaAux)<cantCaracteresTitulo)
			{
				retorno = -1;
			} else
			{
				for (int i=0;i<ll_len (pArrayListSeleccion); i++)
				{
					if (controller_unificacionDatosSeleccion (pArrayListSeleccion, datoCompleto,i)== 1)
					{
						 cantCaracteresDato=strlen (datoCompleto);
						if (fwrite(&datoCompleto,sizeof(char),cantCaracteresDato,listaAux)<cantCaracteresDato)
						{
						bandera = 1;
						break;
						}
					}
				}
				if (bandera == 0)
				{
				retorno = 1;
				}
			}
		fclose(listaAux);
		}  else
		{
			printf ("\nHubo un error al abrir el archivo.");
		}
	}
	return retorno;
}

int controller_buscarSeleccion (LinkedList* pArrayListSeleccion, int idIngresado, int* index)
{
	int retorno = -1;
	int cantSelecciones;
	int idAux;
	Seleccion* pSeleccion=NULL;

	if (pArrayListSeleccion != NULL && idIngresado >= 0 && index != NULL)
	{
		if (idIngresado != 0)
		{
			cantSelecciones =  ll_len(pArrayListSeleccion);
			for (int i=0 ; i<cantSelecciones; i++)
			{
				pSeleccion = ll_get (pArrayListSeleccion,i);
				if (selec_getId (pSeleccion, &idAux) == 1)
				{
					if (idAux == idIngresado)
					{
						*index= i;
						retorno = 1;
						break;
					}
				}
			}
		} else
		{
			*index= -1;
			retorno = 1;
		}
	}

	return retorno;
}

int controller_buscarJugador (LinkedList* pArrayListJugador, int idIngresado, int* index)
{
	int retorno = -1;
	int cantJugadores;
	int idAux;
	Jugador* pJugador;

	if (pArrayListJugador != NULL && idIngresado >= 0 && index != NULL)
	{
		cantJugadores =  ll_len(pArrayListJugador);
		for (int i=0 ; i<cantJugadores; i++)
		{
			pJugador = ll_get (pArrayListJugador,i);
			if (jug_getId (pJugador, &idAux) == 1)
			{
				if (idAux == idIngresado)
				{
					*index= i;
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}


int controller_cargarConvocado (LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno=-1;
	int idJugador=0;
	int idSeleccion;
	int idSeleccionDelJugador;
	int idMax;
	char mensajeErrorGetNumero[] = ("El dato ingresado esta fuera del rango solicitado.\n");
	char mensajeEscape[] = ("\nIngrese 0 para cancelar.\n");
	int cantSelecciones;
	int cantConvocados;
	int auxSalida=-1;
	int indiceSeleccion;
	int indiceJugador;

	Seleccion* pSeleccion;
	Jugador* pJugador;
	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		if (output_obtenerIdMax (&idMax) == 1 && output_listarJugadoresDecodificado (pArrayListJugador,pArrayListSeleccion)== 1)
		{
			printf ("%s", mensajeEscape);
			if (utn_getNumeroInt (&idJugador,"\nIngrese el id del jugador que desea convocar: ",mensajeErrorGetNumero, 0,idMax-1,INTENTOS)== 1
					&& idJugador !=0)
			{
				if (controller_buscarJugador (pArrayListJugador,idJugador, &indiceJugador) == 1)
				{
					pJugador = ll_get (pArrayListJugador, indiceJugador);
					if (jug_getSIdSeleccion (pJugador,&idSeleccionDelJugador)==1)
					{
						while (idSeleccionDelJugador != 0)
						{
							printf ("\nEl jugador seleccionado ya esta convocado.");
							if (utn_getNumeroInt (&idJugador,"\nIngrese el id del jugador que desea convocar: ",mensajeErrorGetNumero, 0,idMax-1,INTENTOS)== 1
									&& idJugador !=0 )
							{
								if (controller_buscarJugador (pArrayListJugador,idJugador, &indiceJugador) == 1)
								{
									pJugador = ll_get (pArrayListJugador, indiceJugador);
									if(jug_getSIdSeleccion (pJugador,&idSeleccionDelJugador) != 1)
									{
										idSeleccionDelJugador = -1;
									}
								} else
								{
									printf ("\nEl id ingresado no existe.");
									idSeleccionDelJugador = -1;
								}
							} else
							{
								idSeleccionDelJugador = -1;
								break;
							}
						}
						if (idSeleccionDelJugador != -1 && controller_listarSelecciones(pArrayListSeleccion)==1)
						{
							printf ("%s", mensajeEscape);
							cantSelecciones =  ll_len(pArrayListSeleccion);
							do
							{
								auxSalida = utn_getNumeroInt (&idSeleccion,"\nIngrese el id de la seleccion a la cual ingresar al jugador: ",
										mensajeErrorGetNumero, 0, cantSelecciones,INTENTOS);
								if (auxSalida == 1 && idSeleccion != 0 && controller_buscarSeleccion (pArrayListSeleccion,idSeleccion,&indiceSeleccion)==1)
								{
									pSeleccion = ll_get (pArrayListSeleccion,indiceSeleccion);
									if (selec_getConvocados(pSeleccion,&cantConvocados) == 1 && cantConvocados<22 )
									{
										jug_setIdSeleccion(pJugador,idSeleccion);
										retorno = 1;
									} else
									{
										printf ("\nLa seleccion que ingreso supero el limite de convocados.\n\n");
									}
								}
								if (retorno == 1)
								{
									break;
								}
							} while (idSeleccion != 0 && auxSalida != -1 );
						}
					}
				} else
				{
					printf ("El ID ingresado no existe.");
				}
			}
			if (idJugador == 0 || idSeleccion == 0 )
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

int controller_eliminarConvocado (LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int idMax;
	int indiceJugador;
	int indiceSeleccion;
	int idSeleccionDelJugador;
	char mensajeEscape[] = ("\nIngrese 0 para cancelar.\n");
	int idJugador=0;
	char mensajeErrorGetNumero[] = ("El dato ingresado esta fuera del rango solicitado.\n");
	char confirmacion;

	Jugador *pJugador;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		if (output_obtenerIdMax (&idMax) == 1 && output_listarJugadoresDecodificado (pArrayListJugador,pArrayListSeleccion) == 1)
		{
			printf ("%s", mensajeEscape);
			if (utn_getNumeroInt (&idJugador,"\nIngrese el id del jugador que desea quitar la convocacion: ",mensajeErrorGetNumero,
					0,idMax-1,INTENTOS)== 1 && idJugador !=0)
			{
				if (controller_buscarJugador (pArrayListJugador,idJugador, &indiceJugador)== 1)
				{
					pJugador = ll_get (pArrayListJugador, indiceJugador);
					if (jug_getSIdSeleccion (pJugador,&idSeleccionDelJugador)==1)
					{
						while (idSeleccionDelJugador == 0)
						{
							printf ("\nEl jugador seleccionado no esta convocado.");
							if (utn_getNumeroInt (&idJugador,"\nIngrese el id del jugador que desea quitar la convocacion: ",mensajeErrorGetNumero,
									0,idMax-1,INTENTOS)== 1 && idJugador !=0)
							{
								if (controller_buscarJugador (pArrayListJugador,idJugador, &indiceJugador)== 1)
								{
									pJugador = ll_get (pArrayListJugador, indiceJugador);
									if(jug_getSIdSeleccion (pJugador,&idSeleccionDelJugador) != 1)
									{
										idSeleccionDelJugador = -1;
									}
								} else
								{
									printf("El ID ingresado no existe.");
								}
							} else
							{
								idSeleccionDelJugador = -1;
								break;
							}
						}
						if (idSeleccionDelJugador != -1)
						{
							if (output_pedirConfirmacion(&confirmacion,INTENTOS)==1)
							{
								if (confirmacion=='S')
								{
									if (controller_buscarSeleccion (pArrayListSeleccion,idSeleccionDelJugador,&indiceSeleccion) == 1)
									{
										if (jug_setIdSeleccion (pJugador, 0) == 1)
										{
												retorno = 1;
										}
									}
								} else
								{
									retorno = 0;
								}
							}
						}
					}
				} else
				{
					printf ("El id ingresado no existe");
				}
			}
		}
	}

	if (idJugador == 0 )
	{
		retorno = 0;
	}
	return retorno;
}


int controller_calculadorJugadoresSeleccciones (LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int idMax;
	int indiceJugador;
	int indiceSeleccion;
	int idSeleccionDelJugador;
	int bandera = 0;
	int idSeleccion;
	int cantSelecciones;
	int cantConvocadosAux;

	Jugador *pJugador=NULL;
	Seleccion *pSeleccion=NULL;

	if (pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		cantSelecciones =  ll_len(pArrayListSeleccion);
		for (int i=0; i<=cantSelecciones; i++)
		{
			if (controller_buscarSeleccion (pArrayListSeleccion,i,&indiceSeleccion) == 1)
			{	if (indiceSeleccion != -1)
				{
					pSeleccion = ll_get (pArrayListSeleccion,indiceSeleccion);
					if (selec_setConvocados (pSeleccion,0) != 1)
					{
						printf ("Error al intentar inicializar todas las selecciones antes del calculo.\n");
						bandera =1;
						break;
					}
				}
			} else
			{
				printf ("Hubo un error al buscar el ID de la seleccion.\n");
			}
		}
		if (bandera == 0)
		{
			if (output_obtenerIdMax (&idMax) == 1)
			{
				for (int j=1; j<idMax; j++)
				{
					if (controller_buscarJugador (pArrayListJugador,j, &indiceJugador)==1)
					{
						pJugador = ll_get (pArrayListJugador, indiceJugador);
						for (int i=0; i<=cantSelecciones; i++)
						{
							if (controller_buscarSeleccion (pArrayListSeleccion,i,&indiceSeleccion) == 1)
							{
								pSeleccion = ll_get (pArrayListSeleccion,indiceSeleccion);
								if (jug_getSIdSeleccion (pJugador,&idSeleccionDelJugador) == 1 && selec_getId (pSeleccion,&idSeleccion) == 1//)
									&& idSeleccion == idSeleccionDelJugador)
								{
									if (selec_getConvocados(pSeleccion,&cantConvocadosAux) == 1)
									{
										cantConvocadosAux++;
										if (selec_setConvocados (pSeleccion,cantConvocadosAux) != 1)
										{
											printf ("Error al intentar convocar al jugador.\n");
											bandera = 1;
											break;
										}
									}else
									{
										printf ("Error al intentar obtener la cantidad de convocados en la seleccion.\n");
									}
								}
							}else
							{
								printf ("Error al intentar buscar la seleccion.\n");
							}
						}
					}
				}
			} else
			{
				printf ("Error al intentar obtener el id maximo de los jugadores.\n");
			}
		}
		retorno = 1;
	}
	if (bandera == 1 )
	{
		retorno = -1;
	}
	return retorno;
}

int controller_ordenarSeleccionPorID (void* punteroUno, void* punteroDos)
{
	int retorno = 0;
	int idUno;
	int idDos;
	Seleccion* pSeleccionUno;
	Seleccion* pSeleccionDos;

	pSeleccionUno = (Seleccion*)punteroUno;
	pSeleccionDos = (Seleccion*)punteroDos;

	if (punteroUno != NULL && punteroDos != NULL)
	{
		if (selec_getId (pSeleccionUno, &idUno) == 1 && selec_getId (pSeleccionDos, &idDos) == 1)
		{
			if(idUno > idDos)
			{
				retorno = 1;
			} else
			{
				if(idUno < idDos)
				{
					retorno = -1;
				}
			}
		}
	} else
	{
		printf ("Error al intentar cargar los datos de los punteros.\n");
	}
	return retorno;
}

int controller_ordenarSeleccionPorConf (void* punteroUno, void* punteroDos)
{
	int retorno = 0;
	char confUno[30];
	char confDos[30];
	Seleccion* pSeleccionUno;
	Seleccion* pSeleccionDos;

	pSeleccionUno = (Seleccion*)punteroUno;
	pSeleccionDos = (Seleccion*)punteroDos;

	if (punteroUno != NULL && punteroDos != NULL)
	{
		if (selec_getConfederacion (pSeleccionUno, confUno) == 1 && selec_getConfederacion (pSeleccionDos, confDos) == 1)
		{
			if (strcmp (confUno,confDos)>0)
			{
				retorno = 1;
			} else
			{
				if(	strcmp (confUno,confDos)<0)
				{
					retorno = -1;
				}
			}
		}
	} else
	{
		printf ("Error al intentar cargar los datos de los punteros.\n");
	}

	return retorno;
}

int controller_ordenarJugadoresPorNombre (void* punteroUno, void* punteroDos)
{
	int retorno = 0;
	char datoUno[30];
	char datoDos[30];
	Jugador* pJugadorUno;
	Jugador* pJugadorDos;

	pJugadorUno = (Jugador*)punteroUno;
	pJugadorDos = (Jugador*)punteroDos;

	if (punteroUno != NULL && punteroDos != NULL)
	{
		if (jug_getNombreCompleto (pJugadorUno, datoUno) == 1 && jug_getNombreCompleto (pJugadorDos, datoDos) == 1)
		{
			if (strcmp (datoUno,datoDos)>0)
			{
				retorno = 1;
			} else
			{
				if(strcmp (datoUno,datoDos)<0)
				{
					retorno = -1;
				}
			}
		}
	} else
	{
		printf ("Error al intentar cargar los datos de los punteros.\n");
	}

	return retorno;
}

int controller_ordenarJugadoresPorEdad (void* punteroUno, void* punteroDos)
{
	int retorno = 0;
	int datoUno;
	int datoDos;
	char nombreUno[30];
	char nombreDos[30];
	Jugador* pJugadorUno;
	Jugador* pJugadorDos;

	pJugadorUno = (Jugador*)punteroUno;
	pJugadorDos = (Jugador*)punteroDos;

	if (punteroUno != NULL && punteroDos != NULL)
	{
		if (jug_getEdad (pJugadorUno, &datoUno) == 1 && jug_getEdad (pJugadorDos, &datoDos) == 1)
		{
			if(datoUno > datoDos)
			{
				retorno = 1;
			} else
			{
				if(datoUno < datoDos)
				{
					retorno = -1;
				} else
				{
					if (datoUno == datoDos)
					{
						if (jug_getNombreCompleto (pJugadorUno, nombreUno) == 1 && jug_getNombreCompleto (pJugadorDos, nombreDos) == 1)
						{
							if (strcmp (nombreUno,nombreDos)>0)
							{
								retorno = 1;
							} else
							{
								if(strcmp (nombreUno,nombreDos)<0)
								{
									retorno = -1;
								}
							}
						}
					}
				}
			}
		}
	} else
	{
		printf ("Error al intentar cargar los datos de los punteros.\n");
	}
	return retorno;
}

int controller_ordenarJugadoresPorNacionalidad (void* punteroUno, void* punteroDos)
{
	int retorno = 0;
	char datoUno[30];
	char datoDos[30];
	char nombreUno[30];
	char nombreDos[30];
	Jugador* pJugadorUno;
	Jugador* pJugadorDos;

	pJugadorUno = (Jugador*)punteroUno;
	pJugadorDos = (Jugador*)punteroDos;

	if (punteroUno != NULL && punteroDos != NULL)
	{
		if (jug_getNacionalidad (pJugadorUno, datoUno) == 1 && jug_getNacionalidad (pJugadorDos, datoDos) == 1)
		{
			if (strcmp (datoUno,datoDos)>0)
			{
				retorno = 1;
			} else
			{
				if(strcmp (datoUno,datoDos)<0)
				{
					retorno = -1;
				} else
				{
					if (datoUno == datoDos)
					{
						if (jug_getNombreCompleto (pJugadorUno, nombreUno) == 1 && jug_getNombreCompleto (pJugadorDos, nombreDos) == 1)
						{
							if (strcmp (nombreUno,nombreDos)>0)
							{
								retorno = 1;
							} else
							{
								if(strcmp (nombreUno,nombreDos)<0)
								{
									retorno = -1;
								}
							}
						}
					}
				}
			}
		}
	} else
	{
		printf ("Error al intentar cargar los datosde los punteros.\n");
	}
	return retorno;
}

int controller_ordenarJugadoresPorID (void* punteroUno, void* punteroDos)
{
	int retorno = 0;
	int datoUno;
	int datoDos;
	Jugador* pJugadorUno;
	Jugador* pJugadorDos;

	pJugadorUno = (Jugador*)punteroUno;
	pJugadorDos = (Jugador*)punteroDos;

	if (punteroUno != NULL && punteroDos != NULL)
	{
		if (jug_getId (pJugadorUno, &datoUno) == 1 && jug_getId (pJugadorDos, &datoDos) == 1)
		{
			if(datoUno > datoDos)
			{
				retorno = 1;
			} else
			{
				if(datoUno < datoDos)
				{
					retorno = -1;
				}
			}
		}
	}
	return retorno;
}

int controller_unificacionDatosSeleccion (LinkedList* pArrayListSeleccion, char* datoCompleto, int indice)
{
	int retorno =-1;
	char idChar[30];
	char pais[30];
	char confederacion[30];
	char convocadosChar[30];
	int convocados;
	int id;
	int control;
	char caracterIntermedio[]=(",");

	Seleccion* pSeleccion=NULL;

	if (pArrayListSeleccion != NULL && datoCompleto != NULL && indice >= 0)
	{
		pSeleccion= ll_get (pArrayListSeleccion,indice);

		 if (selec_getId(pSeleccion,&id)== 1 &&
		 selec_getPais(pSeleccion,pais)== 1 &&
		 selec_getConfederacion(pSeleccion,confederacion)== 1 &&
		 selec_getConvocados(pSeleccion,&convocados)== 1 )
		 {
			sprintf(idChar, "%d", id);
			sprintf(convocadosChar, "%d", convocados);

			strcpy (datoCompleto,idChar);
			control = output_combinarCadenasConCaracter (datoCompleto, pais, caracterIntermedio);
			control = output_combinarCadenasConCaracter (datoCompleto, confederacion, caracterIntermedio);
			control = output_combinarCadenasConCaracter (datoCompleto, convocadosChar, caracterIntermedio);
			strcat (datoCompleto,"\n");

			retorno =1;
		 } else
		{
			printf ("Hubo un error al guardar los datos.\n");
		}
	} else
	{
		printf ("Hubo un error al usar los punteros.\n");
	}
	if (control ==ERROR)
	{
		printf ("Hubo un error en las correcciones de los textos. Revisar codigo.\n");
	}
	 return retorno;
}

int controller_unificacionDatosJugadores (LinkedList* pArrayListJugador, char* datoCompleto, int indice)
{
	int retorno =-1;

	char idChar[30];
	char nombreCompleto[30];
	char edadChar[30];
	char posicion[30];
	char nacionalidad[30];
	char idSelecionChar[30];
	int edad;
	int id;
	int idSeleccion;
	char caracterIntermedio[]=(",");
	int control;

	Jugador* pJugador=NULL;

	if (pArrayListJugador != NULL && datoCompleto != NULL && indice>=0)
	{
		pJugador= ll_get (pArrayListJugador,indice);

		 if (jug_getId(pJugador,&id)== 1 &&
		 jug_getNombreCompleto(pJugador,nombreCompleto)== 1 &&
		 jug_getPosicion(pJugador,posicion)== 1 &&
		 jug_getNacionalidad(pJugador,nacionalidad)== 1 &&
		 jug_getEdad(pJugador,&edad)== 1 &&
		 jug_getSIdSeleccion(pJugador,&idSeleccion)== 1)
		 {
			sprintf(idChar, "%d", id);
			sprintf(edadChar, "%d", edad);
			sprintf(idSelecionChar, "%d", idSeleccion);
			strcpy (datoCompleto,idChar);
			control = output_combinarCadenasConCaracter (datoCompleto, nombreCompleto, caracterIntermedio);
			control = output_combinarCadenasConCaracter (datoCompleto, edadChar, caracterIntermedio);
			control = output_combinarCadenasConCaracter (datoCompleto, posicion, caracterIntermedio);
			control = output_combinarCadenasConCaracter (datoCompleto, nacionalidad, caracterIntermedio);
			control = output_combinarCadenasConCaracter (datoCompleto, idSelecionChar, caracterIntermedio);
			strcat (datoCompleto,"\n");
			retorno =1;
		 } else
		{
			printf ("Hubo un error al guardar los datos.\n");
		}
	} else
	{
		printf ("Hubo un error al usar los punteros.\n");
	}
	if (control ==ERROR)
	{
		printf ("Hubo un error en las correcciones de los textos. Revisar codigo.\n");
	}
	 return retorno;
 }

int controller_generarNombreCompleto (char* nombreCompleto)
{
	int retorno = -1;
	char auxApellido[30];
	char auxSegundoApellido[30];
	char auxSegundoNombre[30];
	char caracterConfirmacion;
	char caracterIntermedio[]=(" ");
	int control;
	char mensajeErrorGetCadena[] = ("El texto solicitado supero el limite de caracteres o no ingreso solo letras (no usar espacios).\n");

	if (nombreCompleto != NULL)
	{
		if (utn_getCadena(nombreCompleto, 100, "\nIngrese nombre (solo primer nombre) del jugador: ",mensajeErrorGetCadena,INTENTOS) == 1 &&
		utn_getCadena(auxApellido, 30, "\nIngrese apellido del jugador: ",mensajeErrorGetCadena,INTENTOS) == 1)
		{
			printf ("\nSi el jugador tiene segundo nombre, se lo puede agregar.\n");
			output_pedirConfirmacion ( &caracterConfirmacion, INTENTOS);
			if (caracterConfirmacion=='S')
			{
				if (utn_getCadena(auxSegundoNombre, 30, "\nIngrese segundo nombre del jugador: ",mensajeErrorGetCadena,INTENTOS) == 1)
				{
					control = output_combinarCadenasConCaracter (nombreCompleto, auxSegundoNombre, caracterIntermedio);
				} else
				{
					printf ("Hubo un error al guardar los datos.\n");
					control = -1;
				}
			}
			control = output_combinarCadenasConCaracter (nombreCompleto, auxApellido, caracterIntermedio);
			printf ("\nSi el jugador tiene segundo apellido, se lo puede agregar.\n");
			output_pedirConfirmacion ( &caracterConfirmacion, INTENTOS);
			if (caracterConfirmacion=='S')
			{
				if (utn_getCadena(auxSegundoApellido, 30, "\nIngrese segundo apellido del jugador: ",mensajeErrorGetCadena,INTENTOS) == 1)
				{
					control = output_combinarCadenasConCaracter (nombreCompleto, auxSegundoApellido, caracterIntermedio);
				} else
				{
					printf ("Hubo un error al guardar los datos.\n");
					control = -1;
				}
			}
			retorno = 1;
		} else
		{
			printf ("Hubo un error al guardar los datos.\n");
		}
	}
	if (control == -1)
	{
		printf ("Hubo un error en las correcciones de los textos. Revisar codigo.\n");
		retorno = -1;
	}

	return retorno;
}
