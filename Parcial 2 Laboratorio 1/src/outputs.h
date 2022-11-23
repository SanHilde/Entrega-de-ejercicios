/*
 * FuncionesExtras.h
 *
 *  Created on: 2 nov. 2022
 *      Author: santy
 */

#ifndef OUTPUTS_H_
#define OUTPUTS_H_

//#include <ctype.h>
//#include <wchar.h>
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include "LinkedList.h"
//#include "Jugador.h"
//#include "Seleccion.h"
#include "Controller.h"

/**
 * \fn int output_combinarCadenasConCaracter(char*, char*, char*)
 * \brief junta dos cadenas de caracter con un caracter ingresado en el medio
 *
 * \param cadenaPrincipal cadena maestra que se usa para acumular
 * \param cadenaASumar cadena a añadir en la principal
 * \param caracterIntermedio caracter que se va a poner entre las dos cadenas de caracteres
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int output_combinarCadenasConCaracter (char *cadenaPrincipal, char *cadenaASumar, char *caracterIntermedio); // completar

/**
 * \fn void impresionFila(int, int, char*)
 * \brief imprime linas que divide el cuadro
 *
 * \param cantCaracteres: cantidad de caracteres que debe imprimir
 * \param cantColumnas: cantidad de columnas que necesita el cuadro
 * \param caracter: caracter a imprimir
 */
void output_impresionFila (int cantCaracteres, int cantColumnas, char caracter);

/**
 * \fn void respuesta(int)
 * \brief imprime una respuesta segun el valor ingresado
 *
 * \param valor: valor a ingresar, el cual permite realizar determinada accion
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int output_respuesta(int valor);

/**
 * \fn int correccionMayusculasCadena(char*)
 * \brief corrige la cadena de caracteres ingresada y le pone mayuscula a cada palabra
 *
 * \param cadena: cadena de caracteres ingresada
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int output_correccionMayusculasCadena (char *cadena);

/**
 * \fn int output_decodificacionId(LinkedList*, int, char*)
 * \brief decodifica el id que se le pasa y devuelve a traves del puntero que significa ese id
 *
 * \param pArrayListSeleccion puntero a linkedlist
 * \param idAIdentificar id con el cual se va a trabajar
 * \param pIdIdentificado lo que significa el id ingresado
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int output_decodificacionId (LinkedList* pArrayListSeleccion, int idAIdentificar, char *pIdIdentificado);

/**
 * \fn int output_listarJugadorDecodificado(LinkedList*, LinkedList*, int)
 * \brief lista los datos vinculando ambas linkedlist
 *
 * \param pArrayListJugador puntero a linkedlist
 * \param pArrayListSeleccion puntero a linkedlist
 * \param index ubicación de donde se quiere extraer el dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int output_listarJugadorDecodificado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int index);

/**
 * \fn int output_listarJugadoresDecodificado(LinkedList*, LinkedList*)
 * \brief lista todos los datos vinculando ambas linkedlist
 *
 * \param pArrayListJugador puntero a linkedlist
 * \param pArrayListSeleccion puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int output_listarJugadoresDecodificado(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * \fn int output_listarJugadoresDecodificadoFiltro(LinkedList*, LinkedList*)
 * \brief
 *
 * \param pArrayListJugador puntero a linkedlist
 * \param pArrayListSeleccion puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int output_listarJugadoresDecodificadoFiltro(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * \fn int output_obtenerIdMax(int*)
 * \brief obtiene el dato guardado en un archivo y lo devuelve
 *
 * \param idMax: dato obtenido, devuelto a traves de funcion
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int output_obtenerIdMax (int* idMax);

/**
 * \fn int pedirConfirmacion(char*, int)
 * \brief pregunta si realmente quiere realizar la accion anterior
 *
 * \param caracterConfirmacion: caracter que confirmara si se quiere realizar la accion o no, S para si y N para no
 * \param intentos: valor el representara la cantidad de veces que se puede ingresar un dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int output_pedirConfirmacion(char *caracterConfirmacion, int intentos);

/**
 * \fn int output_decodificacionConf(LinkedList*, int, char*)
 * \brief decodifica que significa el id ingresado
 *
 * \param pArrayListSeleccion puntero a linkedlist
 * \param idAIdentificar id con el cual se va a trabajar
 * \param pConfDecodificada lo que significa el id ingresado
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int output_decodificacionConf ( LinkedList* pArrayListSeleccion, int idAIdentificar, char *pConfDecodificada);


#endif /* OUTPUTS_H_ */
