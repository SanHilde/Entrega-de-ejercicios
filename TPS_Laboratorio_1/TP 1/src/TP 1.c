/*
 ============================================================================
 Name        : TP 1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "funcionesNecesarias.h"

#define INTENTOS 3
//#define JUGADORES_CARGADO_MINIMO 22
#define NUMERO_MINIMO_VALIDACIONES_CERO 0
#define NUMERO_MINIMO_VALIDACIONES_UNO 1
#define VALIDACION_CORRECTA 1

int main(void)
{
	int opcionPrincipal;
	int opcionInterna;
	int numeroCargado;
	int numeroCargadoLiga;
	//case 1 menu principal
	float costoHospedaje=0;
	float costoComida=0;
	float costoTransporte=0;
	//case 2 menu principal
	int jugadorArquero=0;
	int jugadorDefensor=0;
	int jugadorMediocampista=0;
	int jugadorDelantero=0;
	int contadorAFC=0;
	int contadorCAF=0;
	int contadorCONCACAF=0;
	int contadorCONMEBOL=0;
	int contadorUEFA=0;
	int contadorOFC=0;
	int contadorJugadores=0;
	float promedioAFC;
	float promedioCAF;
	float promedioCONCACAF;
	float promedioCONMEBOL;
	float promedioUEFA;
	float promedioOFC;
	//case 3 menu principal
	float costoMantenimiento=0;
	float costoMantenimientoNuevo;
	float aumento;
	int aumentoPorcentaje=35;

	//mensajes estandar
	char mensajeErrorFuncionNumero[] = ("El dato ingresado no esta dentro del rango solicitado. Reingrese dato.\n\n "); //mensaje estandar para cuando hay error en la validacion de datos en la funcion
	char mensajeCargaCorrecta[] = ("Se valido correctamente el dato, se cargo correctamente.\n\n"); //mensaje estandar para cuando se cargo correctamente el dato.
	char mensajeErrorFuncionNumeroPositivo[] = ("\nError, el dato ingresado es incorrecto, debe ser un numero superior a 0.\n\n"); // mensaje estandar para cuando hay error en la funcion especifica
	char mensajeLimiteJugadores[] = ("Se llego al limite de jugadores para esta posicion, elija otra. Vuelve al menu principal. \n\n");
	char mensajeErrorCargaDatos[] = ("\nHubo un error en la carga de datos. Se volvera al menu principal.\n\n"); //mensaje estandar para cuando hay error en la carga de datos en el main
	char subMenuLigas [] = ("\nElija la liga en la cual el jugador desarrolla sus actividades normalmente: \n"
							"1. AFC en Asia\n"
							"2. CAF en África\n"
							"3. CONCACAF en zona del Norte\n"
							"4. CONMEBOL en Sudamérica\n"
							"5. UEFA en Europa \n"
							"6. OFC en Oceanía\n"
							"Opcion a elegir: ");

	do{
		setbuf (stdout, NULL);
		printf ("\t\tMenu principal\n"
				"1. Ingreso de los costos de mantenimiento\n"
				"\tCosto de hospedaje -> $%.2f\n"
				"\tCosto de comida -> $%.2f\n"
				"\tCosto de transporte -> $%.2f\n"
				"2. Carga de jugadores\n"
				"\tArqueros -> %d\n"
				"\tDefensores -> %d\n"
				"\tMediocampistas -> %d\n"
				"\tDelanteros -> %d\n"
				"3. Realizar todos los calculos\n"
				"4. Informar todos los resultados\n"
				"5. Salir\n",
				costoHospedaje,
				costoComida,
				costoTransporte,
				jugadorArquero,
				jugadorDefensor,
				jugadorMediocampista,
				jugadorDelantero);

//se puede cambiar mensaje 1 y mensaje 2
		if (utn_getNumero (&opcionPrincipal,
				"Opcion a elegir: ",
				"\n\nDato ingresado incorrecto, ingrese uno de los siguientes numeros:\n"
				"1. Ingreso de los costos de mantenimiento\n"
				"2. Carga de jugadores\n"
				"3. Realizar todos los calculos\n"
				"4. Informar todos los resultados\n"
				"5. Salir\n",
				NUMERO_MINIMO_VALIDACIONES_UNO,5,INTENTOS)==VALIDACION_CORRECTA)
		{
			switch (opcionPrincipal)
				{
				case 1:
				{
					if (utn_getNumero (&opcionInterna,
							"\nQue desea cargar?\n"
							"1. Costo de hospedaje\n"
							"2. Costo de comida\n"
							"3. Costo de transporte\n"
							"Opcion a elegir: ",
							mensajeErrorFuncionNumero,
							NUMERO_MINIMO_VALIDACIONES_UNO,3,INTENTOS)!=VALIDACION_CORRECTA)
					{
						printf ("%s", mensajeErrorCargaDatos);
					}

					{
						switch (opcionInterna)
						{
						case 1:
						{

							calcularAcumulador (&costoHospedaje,
												"\nSelecciono costo de hospedaje, ingrese el monto a cargar: ",
												mensajeErrorFuncionNumeroPositivo,
												NUMERO_MINIMO_VALIDACIONES_CERO,
												INTENTOS,
												mensajeCargaCorrecta,
												mensajeErrorCargaDatos);
						}
							break;
						case 2:
						{
							calcularAcumulador (&costoComida,
												"\nSelecciono costo de comida, ingrese el monto a cargar: ",
												mensajeErrorFuncionNumeroPositivo,
												NUMERO_MINIMO_VALIDACIONES_CERO,
												INTENTOS,
												mensajeCargaCorrecta,
												mensajeErrorCargaDatos);
						}
							break;
						case 3:
						{
							calcularAcumulador (&costoTransporte,
												"\nSelecciono costo de transporte, ingrese el monto a cargar: ",
												mensajeErrorFuncionNumeroPositivo,
												NUMERO_MINIMO_VALIDACIONES_CERO,
												INTENTOS,
												mensajeCargaCorrecta,
												mensajeErrorCargaDatos);
						}
							break;
						}
					}

				}
					break; //de la opcion 1 del menu principal
				case 2:
				{

						if (utn_getNumero (&opcionInterna,
										"\nQue posicion desea cargar?\n"
										"1. Arquero\n"
										"2. Defensor\n"
										"3. Mediocampista\n"
										"4. Delantero\n"
										"\nOpcion a elegir: ",
										mensajeErrorFuncionNumero,
										NUMERO_MINIMO_VALIDACIONES_UNO,4,INTENTOS)==VALIDACION_CORRECTA)
						{
							switch (opcionInterna)
							{
							case 1:
							{
								if (jugadorArquero<2)
								{
									cargaJugadores (&numeroCargado,
													&numeroCargadoLiga,
													"\nSelecciono arquero, cargue el numero de la camiseta: ",
													subMenuLigas,
													mensajeErrorFuncionNumeroPositivo,
													mensajeErrorFuncionNumero,
													NUMERO_MINIMO_VALIDACIONES_UNO,
													6,
													INTENTOS,
													&jugadorArquero,
													mensajeCargaCorrecta,
													mensajeErrorCargaDatos);
								} else
								{
									printf ("%s", mensajeLimiteJugadores);
								}
							}
								break;
							case 2:
							{
								if (jugadorDefensor<8)
								{
									cargaJugadores (&numeroCargado,
													&numeroCargadoLiga,
													"\nSelecciono defensor, cargue el numero de la camiseta: ",
													subMenuLigas,
													mensajeErrorFuncionNumeroPositivo,
													mensajeErrorFuncionNumero,
													NUMERO_MINIMO_VALIDACIONES_UNO,
													6,
													INTENTOS,
													&jugadorDefensor,
													mensajeCargaCorrecta,
													mensajeErrorCargaDatos);
								} else
								{
									printf ("%s", mensajeLimiteJugadores);
								}
							}
								break;
							case 3:
							{
								if (jugadorMediocampista<8)
								{
									cargaJugadores (&numeroCargado,
													&numeroCargadoLiga,
													"\nSelecciono mediocampista, cargue el numero de la camiseta: ",
													subMenuLigas,
													mensajeErrorFuncionNumeroPositivo,
													mensajeErrorFuncionNumero,
													NUMERO_MINIMO_VALIDACIONES_UNO,
													6,
													INTENTOS,
													&jugadorMediocampista,
													mensajeCargaCorrecta,
													mensajeErrorCargaDatos);

								} else
								{
									printf ("%s", mensajeLimiteJugadores);
								}
							}
								break;
							case 4:
							{
								if (jugadorDelantero<4)
								{
									cargaJugadores (&numeroCargado,
													&numeroCargadoLiga,
													"\nSelecciono delantero, cargue el numero de la camiseta: ",
													subMenuLigas,
													mensajeErrorFuncionNumeroPositivo,
													mensajeErrorFuncionNumero,
													NUMERO_MINIMO_VALIDACIONES_UNO,
													6,
													INTENTOS,
													&jugadorDelantero,
													mensajeCargaCorrecta,
													mensajeErrorCargaDatos);

								} else
								{
									printf ("%s", mensajeLimiteJugadores);
								}
							}
								break;
							}
						}
						switch (numeroCargadoLiga)
						{
						case 1:
							contadorAFC++;
							break;
						case 2:
							contadorCAF++;
							break;
						case 3:
							contadorCONCACAF++;
							break;
						case 4:
							contadorCONMEBOL++;
							break;
						case 5:
							contadorUEFA++;
							break;
						case 6:
							contadorOFC++;
							break;
						}
						contadorJugadores++;
				}
					break;
				case 3: //opcion 3 del menu principal
					if (contadorJugadores!= NUMERO_MINIMO_VALIDACIONES_CERO && costoHospedaje!=NUMERO_MINIMO_VALIDACIONES_CERO
						&& costoComida!=NUMERO_MINIMO_VALIDACIONES_CERO && costoTransporte!=NUMERO_MINIMO_VALIDACIONES_CERO)
					{
						costoMantenimiento = costoHospedaje + costoComida + costoTransporte;

						if( calcularPromedio (&promedioAFC,contadorAFC, contadorJugadores)==VALIDACION_CORRECTA &&
							calcularPromedio (&promedioCAF, contadorCAF, contadorJugadores)==VALIDACION_CORRECTA &&
							calcularPromedio (&promedioCONCACAF, contadorCONCACAF, contadorJugadores)==VALIDACION_CORRECTA &&
							calcularPromedio (&promedioCONMEBOL, contadorCONMEBOL, contadorJugadores)==VALIDACION_CORRECTA &&
							calcularPromedio (&promedioUEFA,contadorUEFA, contadorJugadores)==VALIDACION_CORRECTA &&
							calcularPromedio (&promedioOFC, contadorOFC, contadorJugadores)==VALIDACION_CORRECTA &&
							costoMantenimiento>0)

						{
								if (contadorUEFA>contadorAFC && contadorUEFA>contadorCAF && contadorUEFA>contadorCONCACAF &&
										contadorUEFA>contadorCONMEBOL && contadorUEFA> contadorOFC)
								{
									if (calcularPorcentaje (&aumento, costoMantenimiento, aumentoPorcentaje)==VALIDACION_CORRECTA)
									{
										costoMantenimientoNuevo = costoMantenimiento + aumento;
										printf ("Los calculos de mantenimiento, promedios y aumento se realizaron de forma correcta.\n\n");
									}
									else
									{
										printf ("Hubo un error en la generacion de calculos en el aumento.\n\n");
									}

								}
								else
								{
									costoMantenimientoNuevo=0;
									printf ("Los calculos de promedios y costos se realizaron de forma correcta.\n\n");
								}
						}
						else
						{
							printf ("Hubo un error en la generacion de calculos en los promedios y costos.\n\n");
						}
					}
					else
					{
						printf ("Aun falta cargar datos. Vuelve al menu principal. \n\n");
					}
					break;
				case 4: //opcion 4 del menu principal
					if (costoMantenimiento>0)
					{
					if (costoMantenimientoNuevo>0)
					{
					printf ("\n\n\t\t Informe de resultados\n"
							"Promedio de jugadores AFC: %.2f\n"
							"Promedio de jugadores CAF: %.2f\n"
							"Promedio de jugadores CONCACAF: %.2f\n"
							"Promedio de jugadores CONMEBOL: %.2f\n"
							"Promedio de jugadores UEFA: %.2f\n"
							"Promedio de jugadores OFC: %.2f\n"
							"El costo de mantenimiento era de $%.2f y recibio un aumento de $%.2f, por lo cual su nuevo valor es $%.2f.\n\n",
							promedioAFC,promedioCAF,promedioCONCACAF,promedioCONMEBOL,promedioUEFA,promedioOFC,
							costoMantenimiento, aumento, costoMantenimientoNuevo);
					}
					else
					{
						printf ("\n\n\t\t Informe de resultados\n"
								"Promedio de jugadores AFC: %.2f\n"
								"Promedio de jugadores CAF: %.2f\n"
								"Promedio de jugadores CONCACAF: %.2f\n"
								"Promedio de jugadores CONMEBOL: %.2f\n"
								"Promedio de jugadores UEFA: %.2f\n"
								"Promedio de jugadores OFC: %.2f\n"
								"El costo de mantenimiento es de $%.2f.\n\n",
								promedioAFC,promedioCAF,promedioCONCACAF,promedioCONMEBOL,promedioUEFA,promedioOFC, costoMantenimiento);
					}
					} else
					{
						printf("Aun no se puede ingresar a esta opcion, debe hacer los calculos primero.\n");
					}
					break;
				case 5: //opcion 5 del menu principal
					printf ("\n\nPrograma finalizado.");
					break;
				}
		} else
		{
			printf ("\n\nHubo un error en la eleccion del menu principal, el programa se finalizo.");
			break;
		}
	} while (opcionPrincipal!=5);

	return EXIT_SUCCESS;
}
