/*
 * funcionesNecesarias.h
 *
 *  Created on: 17 sep. 2022
 *      Author: santy
 */

#ifndef FUNCIONESNECESARIAS_H_
#define FUNCIONESNECESARIAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/**
 * \fn int calcularPromedio(float* resultado, int total, int contador);
 * \brief esta funcion valida que, dentro de la misma se realice un promedio de forma correcta, donde se divide una numero resultado de una
 * acumulacion de numeros por otro resultado de la cantidad de numeros sumados. Como no se puede dividir por 0, si se llega a ingresar como
 * cantidad a dividir 0, este devolvera en la funcion un return distinto a si se hizo bien.
 *
 * \param pResultado: resultado de la operacion realizada, se devuelve a traves de puntero, como flotante (debido a que puede llegar a
 * tener decimales)
 * \param total: numero al cual se realizara el promedio, aquel resultado de la suma de numeros acumulados
 * \param contador: numero con el cual se realiza el promedio, aquel resultado de la suma de la cantidad de numeros ingresados
 * \return si el pasaje de datos es correcto y el calculo del promedio tambien, el retono es 1, si hubo un error, el retorno es -1
 */
int calcularPromedio(float* pResultado, int total, int cantidad);

/**
 * \fn int calcularPorcentaje (float* pResultado, float numeroAAumentar, int porcentaje);
 * \brief esta funcion valida que, dentro de la misma, se calcule correctamente el porcentaje (valor ingresado a traves de la funcion)
 * de un numero (tambien ingresado en la funcion)
 *
* \param pResultado: resultado de la operacion realizada, se devuelve a traves de puntero, como flotante (debido a que puede llegar a
 * tener decimales)
 * \param numeroAAumentar: numero al cual se realizara el aumento
 * \param porcentaje: valor de porcentaje con el cual se trabajara
 * \return si el pasaje de datos es correcto y el calculo del porcentaje tambien, el retono es 1, si hubo un error, el retorno es -1
 */
int calcularPorcentaje (float* pResultado, float numeroAAumentar, int porcentaje);

/**
 * \fn int calcularAcumulador (float* pResultado, char* mensaje, char* mensajeError, int minimo, int intentos,
						char* mensajeCargaOK, char* mensajeErrorCarga);
 * \brief esta funcion valida que, dentro de la misma, se puedan cargar un numero positivo, con decimales (si se carga mas
 * de uno en el mismo lugar, se guarda el ultimo subido)
 *
 * \param pResultado: a traves de puntero, devuelve el valor que se ingreso
 * \param mensaje: mensaje que explica que se necesita ingresar
 * \param mensajeError: mensaje que aparece en caso de haber ingresado el valor mal
 * \param minimo: valor minimo que tiene que superar el valor ingresado
 * \param maximo: valor maximo que no puede superar el valor ingresado
 * \param intentos: la cantidad de intentos que se pueden ingresar valores
 * \param mensajeCargaOK: mensaje que avisa que la operacion se realizo sin problemas
 * \param mensajeErrorCarga: mensaje que avisa que hubo un error en la operacion
 * \return: si la operacion se realizo correctamente, devuelve 1, caso contrario, devuelve -1
 */
int calcularAcumulador (float* pResultado, char* mensaje, char* mensajeError, int minimo, int intentos,
						char* mensajeCargaOK, char* mensajeErrorCarga);
/**
 * \fn int cargaJugadores (int* pResultadoUno, int* pResultadoDos, char* mensajeUno, char* mensajeDos, char* mensajeErrorUno, char* mensajeErrorDos,
		int minimo, int maximo, int intentos, int *contador, char* mensajeCargaOK, char* mensajeErrorCarga);
 * \brief esta funcion valida que, dentro de la misma, se puedan cargar dos numeros, uno positivo y otro dentro de un rango, al cargase estos
 * datos, se aumentara un contador en 1, y este contador lo devolvera la funcion como dato
 *
 *
 * \param pResultadoUno: a traves de puntero, devuelve el valor que se ingreso
 * \param pResultadoDos: a traves de puntero, devuelve el valor que se ingreso
 * \param mensajeUno: que explica que se necesita ingresar en la primer subfuncion
 * \param mensajeDos: que explica que se necesita ingresar en la segunda subfuncion
 * \param mensajeErrorUno: mensaje que aparece en caso de haber ingresado el valor mal en la primer subfuncion
 * \param mensajeErrorDos: mensaje que aparece en caso de haber ingresado el valor mal en la segunda subfuncion
 * \param minimo: valor minimo que tiene que superar el valor ingresado
 * \param maximo: valor maximo que no puede superar el valor ingresado
 * \param intentos: la cantidad de intentos que se pueden ingresar valores
 * \param contador: cuenta cuantas veces se ingresaron datos en esta funcion
 * \param mensajeCargaOK: mensaje que avisa que la operacion se realizo sin problemas
 * \param mensajeErrorCarga: mensaje que avisa que hubo un error en la operacion
 * \return: si la operacion se realizo correctamente, devuelve 1, caso contrario, devuelve -1
 */
int cargaJugadores (int* pResultadoUno, int* pResultadoDos, char* mensajeUno, char* mensajeDos, char* mensajeErrorUno, char* mensajeErrorDos,
		int minimo, int maximo, int intentos, int *contador, char* mensajeCargaOK, char* mensajeErrorCarga);



#endif /* FUNCIONESNECESARIAS_H_ */
