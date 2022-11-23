/*
 * inputs.h
 *
 *  Created on: 17 sep. 2022
 *      Author: santy
 */

#ifndef INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ERROR -1
#define OK 1



/**
 * \fn int utn_myGets(char*, int)
 * \brief esta funcion permite ingresar una cadena de caracteres
 *
 * \param cadena: cadena de caracteres ingresada
 * \param longitud: cantidad de caracteres que puede tener la cadena
 * \return si el pasaje de datos es correcto y el calculo del promedio tambien, el retono es 1, si hubo un error, el retorno es -1
 */

int utn_myGets ( char * cadena, int longitud);

/**
 * \fn int utn_esNumericaInt(char*)
 * \brief esta funcion valida si la cadena de caracteres ingresada esta compuesta solo por datos de tipo int
 *
 * \param cadena: cadena de caracteres ingresada
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int utn_esNumericaInt ( char * cadena);

/**
 * \fn int utn_getInt(int*)
 * \brief esta funcion convierte la cadena de caracteres en un dato tipo int
 *
 * \param pResultado: devuelve el resultado convertido a dato tipo int
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int utn_getInt ( int * pResultado);

/**
 * \fn int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);
 * \brief esta funcion valida que solo se ingresen numeros y entre dos valores, en una cierta cantidad de intentos
 *
 * \param pResultado: a traves de puntero, devuelve el valor que se ingreso
 * \param mensaje: a traves de puntero, mensaje que explica que se necesita ingresar
 * \param mensajeError: a traves de puntero, mensaje que aparece en caso de haber ingresado algo mal
 * \param minimo: valor minimo que tiene que superar el valor ingresado
 * \param maximo: valor maximo que no puede superar el valor ingresado
 * \param intentos: la cantidad de intentos que se pueden ingresar valores
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);

/**
 * \fn int utn_getNumeroIntSinMax(int* pResultado, char* mensaje, char* mensajeError, int minimo, int intentos);
 * \brief esta funcion valida que solo se ingresen numeros y mayores a 0 en una cierta cantidad de intentos
 *
 * \param pResultado: a traves de puntero, devuelve el valor que se ingreso
 * \param mensaje: a traves de puntero, mensaje que explica que se necesita ingresar
 * \param mensajeError: a traves de puntero, mensaje que aparece en caso de haber ingresado algo mal
 * \param minimo: valor minimo que tiene que superar el valor ingresado
 * \param intentos: la cantidad de intentos que se pueden ingresar valores
 * \return: si el numero es mayor a 0, retorno 1, y si se pasa la cantidad de intentos fallidos maximos, el retorno es -1
 */
int utn_getNumeroIntSinMax(int* pResultado, char* mensaje, char* mensajeError, int minimo, int intentos);

/**
 * \fn int utn_esNumericaShort(char*)
 * \brief esta funcion valida si la cadena de caracteres ingresada esta compuesta solo por datos de tipo short
 *
 * \param cadena: cadena de caracteres ingresada
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int utn_esNumericaShort ( char * cadena);

/**
 * \fn int utn_getShort(short*)
 * \brief esta funcion convierte la cadena de caracteres en un dato tipo short
 *
 * \param pResultado: devuelve el resultado convertido a dato tipo short
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int utn_getShort ( short * pResultado);

/**
 * \fn int utn_getNumeroShort(short*, char*, char*, int, int, int)
 * \brief
 *
 * \param pResultado: a traves de puntero, devuelve el valor que se ingreso
 * \param mensaje: a traves de puntero, mensaje que explica que se necesita ingresar
 * \param mensajeError: a traves de puntero, mensaje que aparece en caso de haber ingresado algo mal
 * \param minimo: valor minimo que tiene que superar el valor ingresado
 * \param maximo: valor maximo que no puede superar el valor ingresado
 * \param intentos: la cantidad de intentos que se pueden ingresar valores
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int utn_getNumeroShort(short* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);

/**
 * \fn int utn_esNumericaFloat(char*)
 * \brief esta funcion valida si la cadena de caracteres ingresada esta compuesta solo por datos de tipo float
 *
 * \param cadena: cadena de caracteres ingresada
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int utn_esNumericaFloat ( char * cadena);

/**
 * \fn int utn_getFloat(float*)
 * \brief esta funcion convierte la cadena de caracteres en un dato tipo float
 *
 * \param pResultado: devuelve el resultado convertido a dato tipo float
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int utn_getFloat ( float * pResultado);

/**
 * \fn int utn_getNumeroFloatSinMax(float* pResultado, char* mensaje, char* mensajeError, int minimo, int intentos);
 * \brief esta funcion valida que solo se ingresen numeros y mayores a 0 en una cierta cantidad de intentos, permite que tenga decimales
 *
 * \param pResultado: a traves de puntero, devuelve el valor que se ingreso con decimales
 * \param mensaje: a traves de puntero, mensaje que explica que se necesita ingresar
 * \param mensajeError: a traves de puntero, mensaje que aparece en caso de haber ingresado algo mal
 * \param minimo: valor minimo que tiene que superar el valor ingresado
 * \param intentos: la cantidad de intentos que se pueden ingresar valores
 * \return: si el numero es mayor a 0, retorno 1, y si se pasa la cantidad de intentos fallidos maximos, el retorno es -1
 */
int utn_getNumeroFloatSinMax(float* pResultado, char* mensaje, char* mensajeError, int minimo, int intentos);

/**
 * \fn int utn_getCaracter(char*, char*, char*, int)
 * \brief pide un caracter y valida que este cumpla con las condiciones
 *
 * \param pResultado: a traves de puntero, devuelve el dato que se ingreso
 * \param mensaje: a traves de puntero, mensaje que explica que se necesita ingresar
 * \param mensajeError: a traves de puntero, mensaje que aparece en caso de haber ingresado algo mal
 * \param intentos: la cantidad de intentos que se pueden ingresar caracteres
 * \return si se paso el dato correctamente retorno 1, y si se pasa la cantidad de intentos fallidos maximos, el retorno es -1
 */
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, int intentos);

/**
 * \fn int utn_getCadena(char*, int, char*, char*, int)
 * \brief pide una cadena de caracteres y valida que esta este dentro del la cantidad de caracteres que se puso como validacion
 *
 * \param pResultado: a traves de puntero, devuelve la cadena que se ingreso
 * \param len: largo que debe cumplir la cadena a tener como maximo
 * \param mensaje: a traves de puntero, mensaje que explica que se necesita ingresar
 * \param mensajeError: a traves de puntero, mensaje que aparece en caso de haber ingresado algo mal
 * \param intentos: la cantidad de intentos que se pueden ingresar cadenas de caracteres
 * \return si se paso el dato correctamente retorno 1, y si se pasa la cantidad de intentos fallidos maximos, el retorno es -1
 */
int utn_getCadena(char* pResultado, int len, char* mensaje, char* mensajeError,int intentos);


/**
 * \fn int utn_esCadenaAbecedario(char*)
 * \brief verifica que lo que se ingrese sea una cadena de caracteres que solo posea letras del abecedario
 *
 * \param cadena cadena a verificar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int utn_esCadenaAbecedario ( char *cadena);//completar

/**
 * \fn int utn_getCadenaAbecedario(char*)
 * \brief pide una cadena de caracteres que solo posea letras del abecedario
 *
 * \param pResultado cadena resultante
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int utn_getCadenaAbecedario ( char * pResultado);


#define INPUTS_H_
#endif /* INPUTS_H_ */
