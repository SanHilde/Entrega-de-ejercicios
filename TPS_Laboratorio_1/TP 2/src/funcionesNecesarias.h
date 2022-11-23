/*
 * funcionesNecesarias.h
 *
 *  Created on: 17 sep. 2022
 *      Author: santy
 */

#ifndef FUNCIONESNECESARIAS_H_

#include "abmJugadores.h"


/**
 * \fn int calcularAcumulador(eJugadores*, float*)
 * \brief acumula todos los precios para dar un total
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param acumulador: variable donde se van acumulando
 * \return si el pasaje de datos es correcto y el calculo del porcentaje tambien, el retono es 1, si hubo un error, el retorno es -1
 */
int calcularAcumulador(eJugadores *estructura, float* acumulador);

/**
 * \fn int calcularContador(eJugadores*, short*)
 * \brief contador de datos activos
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param acumulador: variable donde se van acumulando
 * \return si el pasaje de datos es correcto y el calculo del porcentaje tambien, el retono es 1, si hubo un error, el retorno es -1
 */
int calcularContador(eJugadores *estructura, short* acumulador);

/**
 * \fn int calcularContadorConFiltro(eJugadores*, short*, int)
 * \brief contador que posee un filtro a la hora de elegir el parametro a contar
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param acumulador: variable donde se van acumulando
 * \param filtro: dato que se desea filtrar
 * \return si el pasaje de datos es correcto y el calculo del porcentaje tambien, el retono es 1, si hubo un error, el retorno es -1
 */
int calcularContadorConFiltro(eJugadores *estructura, short* acumulador, int filtro);

/**
 * \fn int calcularConfMasAniosContratos(eJugadores*, eConfederaciones*, short*, int*)
 * \brief calcula quien posee un parametro maximo y te devuelve el parametro y el id de este
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param estructuraDos: parametros donde se guardan los datos de una segunda estructura que esta relacionada a la primera
 * \param pResultadoAcumulador: variable donde se van acumulando
 * \param pResultadoID: dato que devuelve la funcion, a partir de lo que calculo
 * \return si el pasaje de datos es correcto y el calculo del porcentaje tambien, el retono es 1, si hubo un error, el retorno es -1
 */
int calcularConfMasAniosContratos (eJugadores *estructura, eConfederaciones *estructuraDos,
									short *pResultadoAcumulador, char *pResultadoID);

/**
 * \fn int calcularConfMasJugadores(eJugadores*, eConfederaciones*, int*)
 * \brief calcula quien posee un parametro maximo y te devuelve el id de este
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param estructuraDos: parametros donde se guardan los datos de una segunda estructura que esta relacionada a la primera
 * \param pResultadoID: dato que devuelve la funcion, a partir de lo que calculo en tipo char
 * \param pResultadoID: dato que devuelve la funcion, a partir de lo que calculo en tipo int
 * \return si el pasaje de datos es correcto y el calculo del porcentaje tambien, el retono es 1, si hubo un error, el retorno es -1
 */
int calcularConfMasJugadores (eJugadores *estructura, eConfederaciones *estructuraDos, char *pResultadoID, int *pResultadoIDint);

/**
 * \fn int calcularPromedio(float* resultado,  float* total, short* cantidad);
 * \brief esta funcion valida que, dentro de la misma se realice un promedio de forma correcta, donde se divide una numero resultado de una
 * acumulacion de numeros por otro resultado de la cantidad de numeros sumados. Como no se puede dividir por 0, si se llega a ingresar como
 * cantidad a dividir 0, este devolvera en la funcion un return distinto a si se hizo bien.
 *
 * \param pResultado: resultado de la operacion realizada, se devuelve a traves de puntero, como flotante (debido a que puede llegar a
 * tener decimales)
 * \param total: numero al cual se realizara el promedio, aquel resultado de la suma de numeros acumulados
 * \param cantidad: numero con el cual se realiza el promedio, aquel resultado de la suma de la cantidad de numeros ingresados
 * \return si el pasaje de datos es correcto y el calculo del promedio tambien, el retono es 1, si hubo un error, el retorno es -1
 */
int calcularPromedio(float* pResultado, float* total, short* cantidad);

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
 * \fn void contadorSuperiorAPromedio(eJugadores*, float*, int*,)
 * \brief cuenta cuantos datos superan el requisito
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param promedio: valor el cual se utiliza para la comparacion
 * \param contador: variable que fue acumulando la cantidad de datos que cumplieron con el requisito
 * \return si el pasaje de datos es correcto y el calculo del porcentaje tambien, el retono es 1, si hubo un error, el retorno es -1
 */
int contadorSuperiorAPromedio(eJugadores *estructura, float* promedio, int *contador);

#define FUNCIONESNECESARIAS_H_
#endif /* FUNCIONESNECESARIAS_H_ */
