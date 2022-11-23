/*
 ============================================================================
 Name        : tps_laboratorio_2.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "outputJugadores.h"
#include "funcionesNecesarias.h"

int main(void) {

	setbuf (stdout ,NULL);

	eJugadores jugador[CANT_JUGADORES];
	eConfederaciones confederacion[CANT_CONF];

	int opcionMenuPrincipal;
	int opcionInterna;
	int opcionDeModificacion;
	int cantColumnasJugadores=8;
	char confirmacion;
	int numeroMinimoValidacion=1;
	float acumuladorSalarios;
	float promedioSalarios;
	int contadorSuperiorPromedio;
	int idBuscada;
	short masAniosDeContrato;
	char pIdIdentificado[CANT_CARACTERES];
	short auxContadorPorcentaje;
	float porcentajeJugadores;
	int minimoConfederacion=100;
	int maximoConfederacion;
	int confederacionElegida;


	char mensajeErrorGetNumero[] = ("El dato ingresado esta fuera del rango solicitado.\n");
	char mensajeErrorGetNumeroPositivo[] = ("El dato ingresado debe ser mayor a 0.\n");
	char mensajeErrorGetCadena[] = ("El texto solicitado supero el limite de caracteres.\n");
	char mensajeErrorCarga[] = ("\n\nNo hay datos para mostrar.\n");
	char mensajeErrorBandera[] = ("\nNo hay datos cargados, no se puede ingresar.\n\n");
	char mensajeErrorCalculo[] = ("Hubo un error en la generacion de calculos.\n\n");
	char mensajeBusquedaId[] = ("\nIngrese el ID a realizar operacion: ");
	char mensajeSalida[] = ("Usted selecciono salir, vuelve al menu anterior.\n\n");


	int contadorActivosJugadores=0;
	int contadorActivosConf=0;
	short indiceIncrementalJug=0;
	short indiceIncrementalConf=0;
	short jugadoresTotales=0;



	if (inicializadorJugadores (jugador)==OK && inicializadorConfederaciones (confederacion)==OK &&
		hardCodeoJugadores (jugador, 4, &indiceIncrementalJug)==OK &&
		hardCodeoConfederaciones (confederacion, 6, &indiceIncrementalConf)==OK	) //
	{
		contadorActivosConf=indiceIncrementalConf;
		do
		{
			maximoConfederacion=99 + (int)indiceIncrementalConf;
			utn_getNumeroInt(&opcionMenuPrincipal,
							"\t\tMenu principal\n"
							"Seleccione que desea realizar:\n"
							"1-Alta\n"
							"2-Baja\n"
							"3-Modificacion\n"
							"4-Informes\n"
							"5-Salir\n"
							"Numero ingresado: ",
							mensajeErrorGetNumero,
							numeroMinimoValidacion,
							5,
							INTENTOS);

			switch (opcionMenuPrincipal)
			{
			case 1:
				do
				{
					utn_getNumeroInt(&opcionInterna,
									"\nSeleccione que desea dar de alta:\n"
									"1-Jugador\n"
									"2-Confederacion\n"
									"3-Salir\n"
									"Numero ingresado: ",
									mensajeErrorGetNumero,
									numeroMinimoValidacion,
									3,
									INTENTOS);
					switch (opcionInterna)
					{
						case 1:
							if (contadorActivosConf>0)
							{
								if(altaDatosJugador(jugador, confederacion, mensajeErrorGetNumero, mensajeErrorGetNumeroPositivo,
										mensajeErrorGetCadena,indiceIncrementalConf) == OK)
							   {
								   printf("\nSe dio de alta correctamente.\n");
								   contadorActivosJugadores++;
							   }
							} else
							{
								printf ("\nNo hay confederaciones cargadas. Cargue al menos una.\n\n");
							}
							break;
						case 2:
							if(altaDatosConfederacion(confederacion, mensajeErrorGetNumero, mensajeErrorGetNumeroPositivo,
									mensajeErrorGetCadena) == OK)
						   {
								contadorActivosConf++;
								indiceIncrementalConf++;
							   printf("\nSe dio de alta correctamente.\n");
						   }
							break;
						case 3:
							printf ("%s", mensajeSalida);
							break;
					}
				}while (opcionInterna != 3);
				break;
			case 2:
				if (contadorActivosJugadores> 0 )
				{
					do
					{
						utn_getNumeroInt(&opcionInterna,
										"\nSeleccione que desea bajar:\n"
										"1-Jugador\n"
										"2-Confederacion\n"
										"3-Salir\n"
										"Numero ingresado: ",
										mensajeErrorGetNumero,
										numeroMinimoValidacion,
										3,
										INTENTOS);
						switch (opcionInterna)
						{
							case 1:
								ordenarPorId (jugador);
								listaJugadores(jugador, confederacion,mensajeErrorCarga,cantColumnasJugadores);
								if(respuesta(bajarDatoJugador(jugador, mensajeBusquedaId,mensajeErrorGetNumeroPositivo,numeroMinimoValidacion,
										INTENTOS))== OK)
								{
									contadorActivosJugadores--;
								}
								break;
							case 2:
								listaConfederaciones(confederacion, mensajeErrorCarga, 4);
								if(respuesta(bajarDatoConfederacion(confederacion, mensajeBusquedaId,mensajeErrorGetNumeroPositivo,
										minimoConfederacion,INTENTOS,maximoConfederacion))== OK)
								{
									contadorActivosConf--;
								}
								break;
							case 3:
								printf ("%s", mensajeSalida);
								break;
						}
					}while (opcionInterna != 3);
				}
				 else
				{
					 printf ("%s", mensajeErrorBandera);
				}
				break;
			case 3:
				if (contadorActivosJugadores> 0 )
				{
					do
					{
						utn_getNumeroInt(&opcionInterna,
										"\nSeleccione que desea modificar:\n"
										"1-Jugador\n"
										"2-Confederacion\n"
										"3-Salir\n"
										"Numero ingresado: ",
										mensajeErrorGetNumero,
										numeroMinimoValidacion,
										3,
										INTENTOS);
						switch (opcionInterna)
						{
							case 1:
								do
								{
									ordenarPorId (jugador);
									listaJugadores(jugador, confederacion,mensajeErrorCarga,cantColumnasJugadores);

									utn_getNumeroInt(&opcionDeModificacion,
													"\n¿Que desea modificar?\n"
													"1-Nombre del jugador\n"
													"2-Posicion del jugador\n"
													"3-Numero de camiseta del jugador\n"
													"4-Confederacion del jugador\n"
													"5-Salario del jugador\n"
													"6-Anio de contrado del jugador\n"
													"7-Salir\n"
													"Numero ingresado: ",
													mensajeErrorGetNumero,
													numeroMinimoValidacion,
													7,
													INTENTOS);

										switch (opcionDeModificacion)
										{
										case 1:
											respuesta(modificarNombreJugador (jugador, mensajeBusquedaId, mensajeErrorGetNumeroPositivo,
													mensajeErrorGetCadena, numeroMinimoValidacion));
											break;
										case 2:
											respuesta(modificarPosicionJugador (jugador, mensajeBusquedaId, mensajeErrorGetNumeroPositivo,
													mensajeErrorGetCadena, numeroMinimoValidacion));
											break;
										case 3:
											respuesta(modificarCamisetaJugador (jugador, mensajeBusquedaId, mensajeErrorGetNumeroPositivo,
													mensajeErrorGetCadena, numeroMinimoValidacion));
											break;
										case 4:
											respuesta(modificarConfederacionJugador (jugador, confederacion, mensajeBusquedaId,
													mensajeErrorGetNumeroPositivo, mensajeErrorCarga, mensajeErrorGetCadena, numeroMinimoValidacion,
													indiceIncrementalConf));
											break;
										case 5:
											respuesta(modificarSalarioJugador (jugador, mensajeBusquedaId, mensajeErrorGetNumeroPositivo,
													mensajeErrorGetCadena, numeroMinimoValidacion));
											break;
										case 6:
											respuesta(modificarAniosContratoJugador (jugador, mensajeBusquedaId, mensajeErrorGetNumeroPositivo,
													mensajeErrorGetCadena, numeroMinimoValidacion));
											break;
										case 7:
											printf ("%s", mensajeSalida);
											break;
										}
								} while (opcionDeModificacion != 7 );
								break;
							case 2:
								do
								{
									listaConfederaciones(confederacion, mensajeErrorCarga, 4);

									utn_getNumeroInt(&opcionDeModificacion,
													"\n¿Que desea modificar?\n"
													"1-Siglas de la confederacion\n"
													"2-Region de la confederacion\n"
													"3-Anio de creacion de la confederacion\n"
													"4-Salir\n"
													"Numero ingresado: ",
													mensajeErrorGetNumero,
													numeroMinimoValidacion,
													7,
													INTENTOS);

										switch (opcionDeModificacion)
										{
										case 1:
											respuesta(modificarNombreConfederacion (confederacion, mensajeBusquedaId, mensajeErrorGetNumero,
													mensajeErrorGetCadena, minimoConfederacion, maximoConfederacion));
											break;
										case 2:
											respuesta(modificarRegionConfederacion (confederacion, mensajeBusquedaId, mensajeErrorGetNumero,
													mensajeErrorGetCadena, minimoConfederacion, maximoConfederacion));
											break;
										case 3:
											respuesta(modificarAnioConfederacion (confederacion, mensajeBusquedaId, mensajeErrorGetNumero,
													mensajeErrorGetCadena, minimoConfederacion, maximoConfederacion));
											break;
										case 4:
											printf ("%s", mensajeSalida);
											break;
										}
								} while (opcionDeModificacion != 4 );
								break;
							case 3:
								printf ("%s", mensajeSalida);
								break;
						}
					}while (opcionInterna != 3);
				}
				 else
				{
					 printf ("%s", mensajeErrorBandera);
				}
				break;
			case 4:
				if (contadorActivosJugadores>0)
				{
					calcularContador(jugador, &jugadoresTotales);
					do
					{
					utn_getNumeroInt(&opcionInterna,
									"\n\n\t\tInformes\n"
									"Seleccione que desea ver:\n"
									"1-Listado de los jugadores ordenados por confederacion\n"
									"2-Listado de confederaciones con sus jugadores\n"
									"3-Informe de los salarios\n"
									"4-Informe de confederacion, contratos\n"
									"5-Informe de confederacion, porcentaje jugadores\n"
									"6-Informe de regiones, mayor cantidad de jugadores\n"
									"7-Salir\n"
									"Numero ingresado: ",
									mensajeErrorGetNumero,
									numeroMinimoValidacion,
									7,
									INTENTOS);

						switch (opcionInterna)
						{
						case 1:
							ordenarPorConfederacion (jugador, confederacion);
							listaJugadores(jugador, confederacion,mensajeErrorCarga,cantColumnasJugadores);
							break;
						case 2:
							ordenarPorId (jugador);
							listaConfederaciones(confederacion, mensajeErrorCarga, 4);
							if (utn_getNumeroInt (&idBuscada,"\n\nSeleccione el ID de la confederacion que quiera ver sus jugadores.\n"
									"ID ingresado: ", mensajeErrorGetNumero, minimoConfederacion, (99+indiceIncrementalConf), INTENTOS)==OK)
							{
								mostrarJugadoresFiltroConfederacion (jugador,confederacion,
									mensajeErrorCarga,mensajeErrorGetNumero, indiceIncrementalConf,cantColumnasJugadores,&idBuscada);
							} else
							{
								printf ("Hubo un error al ingresar el ID, vuelve al menu.\n");
							}
							break;
						case 3:
							if( calcularAcumulador(jugador, &acumuladorSalarios) == OK &&
								calcularPromedio(&promedioSalarios, &acumuladorSalarios,&jugadoresTotales) == OK &&
								contadorSuperiorAPromedio(jugador, &promedioSalarios,&contadorSuperiorPromedio) == OK)
							{
								printf ("Total de todos los salarios: %.2f.\n"
										"Promedio de todos los salarios : %.2f.\n"
										"Cantidad de jugadores que superan el promedio: %d.\n",
										acumuladorSalarios,promedioSalarios, contadorSuperiorPromedio);
							} else
							{
								printf ("%s", mensajeErrorCalculo);
							}
							break;
						case 4:
							if (calcularConfMasAniosContratos (jugador, confederacion, &masAniosDeContrato, pIdIdentificado)==OK)
							{
								printf ("\nConfederacion con mas anio de contrato: %s\n"
										"Cantidad de a%cos: %d.\n",
										pIdIdentificado,164,masAniosDeContrato);
							} else
							{
								printf ("%s", mensajeErrorCalculo);
							}
							break;
						case 5:
							printf ("\nPorcentaje de jugadores por confederacion:\n");
							for (int i=0;i<CANT_CONF; i++)
							{
								if ((confederacion+i)->isEmpty==OCUPADO)
								{
									idBuscada = minimoConfederacion+i;
									if (calcularContadorConFiltro(jugador, &auxContadorPorcentaje, idBuscada) == OK )
									{
										porcentajeJugadores = (float) auxContadorPorcentaje*100/jugadoresTotales;
										decodificacionId (confederacion, &idBuscada, pIdIdentificado);
										printf ("%s: %.1f %c de los jugadores.\n", pIdIdentificado, porcentajeJugadores, 37);

									} else
									{
										printf ("%s", mensajeErrorCalculo);
									}
								}
							}
							break;
						case 6:
							if (calcularConfMasJugadores (jugador, confederacion, pIdIdentificado, &idBuscada)==OK)
							{
								if (idBuscada != 0)
								{
								printf ("La region con mas jugadores es: %s\n.", pIdIdentificado);
								ordenarPorId (jugador);
								mostrarJugadoresFiltroConfederacion (jugador,confederacion,
																	mensajeErrorCarga,mensajeErrorGetNumero,
																	indiceIncrementalConf,cantColumnasJugadores,&idBuscada);
								} else
								{
									printf ("Las regiones con mas jugadores son: %s\n", pIdIdentificado);
									ordenarPorId (jugador);
									listaConfederaciones(confederacion, mensajeErrorCarga, 4);
									if (utn_getNumeroInt (&confederacionElegida,"\nComo hubo un empate en las regiones. Seleccione cual desea ver listado.\n"
											"ID ingresado: ", mensajeErrorGetNumero, minimoConfederacion, (99+indiceIncrementalConf), INTENTOS)==OK)
									{
										mostrarJugadoresFiltroConfederacion (jugador,confederacion,
											mensajeErrorCarga,mensajeErrorGetNumero, indiceIncrementalConf,cantColumnasJugadores,&confederacionElegida);
									} else
									{
										printf ("Hubo un error al ingresar el ID, vuelve al menu.\n");
									}
							}
							}else
							{
								printf ("%s", mensajeErrorCalculo);
							}
							break;
						case 7:
							printf ("%s", mensajeSalida);
							break;
						}
					} while (opcionInterna!=7);
				} else
				{
					printf ("%s", mensajeErrorBandera);
				}
				break;
			case 5:
				pedirConfirmacion ( &confirmacion,INTENTOS);
				if (confirmacion=='S')
				{
					printf ("Eligio salir. El programa finalizo. ");
					break;
				}
				else
				{
					opcionMenuPrincipal=6;
				}
			}
		} while (opcionMenuPrincipal!=5);

	} else
	{
		printf ("Hubo un error al inicializar.");
	}

	return EXIT_SUCCESS;
}

