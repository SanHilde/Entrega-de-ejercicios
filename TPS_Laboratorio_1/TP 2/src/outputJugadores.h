
#ifndef ABMJUGADORES_H_


#include "abmJugadores.h"

/**
 * \fn void impresionDeCuadroJugadores(int)
 * \brief cabecera de cuadra para la impresion de lista de jugadores
 *
 * \param cantColumnas: cantidad de columnas que tendra el cuadro donde se hara la lista
 */
void impresionDeCuadroJugadores (int cantColumnas);

/**
 * \fn int listaJugadores(eJugadores*, eConfederaciones*, char*, int)
 * \brief funcion que imprime todos los jugadores cargados
 *
 * \param jugador: parametros donde se guardan los datos de la estructura principal
 * \param confederacion: parametros donde se guardan los datos de una segunda estructura que esta relacionada a la primera
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param cantColumnas: cantidad de columnas que tendra el cuadro donde se hara la lista
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int listaJugadores(eJugadores *jugador, eConfederaciones *confederacion, char* mensajeError, int cantColumnas);

/**
 * \fn void mostrarDatoJugadores(eJugadores*, eConfederaciones*, int, char*)
 * \brief funcion que muestra todos los datos de la estructura jugadores
 *
 * \param jugador: parametros donde se guardan los datos de la estructura principal
 * \param confederacion: parametros donde se guardan los datos de una segunda estructura que esta relacionada a la primera
 * \param indice: ubicación de donde se quiere extraer el dato
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 */
void mostrarDatoJugadores(eJugadores *jugador, eConfederaciones *confederacion,int indice, char* mensajeError);

/**
 * \fn void mostrarJugadoresFiltroConfederacion(eJugadores*, eConfederaciones*, char*, char*, int, int, int*)
 * \brief funcion que imprime todos los jugadores segun filtro elegido cargados
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param estructuraDos: parametros donde se guardan los datos de una segunda estructura que esta relacionada a la primera
 * \param mensajeErrorCarga: mensaje que aparece cuando shubo un error en la carga de de datos o no hay datos para mostrar
 * \param mensajeErrorGetNumero: mensaje que aparece cuando el numero esta por fuera del rango solicitado o si se ingresa caracteres
 * \param cantConf: cantidad de confederaciones posibles
 * \param cantColumnas: cantidad de columnas que tendra el cuadro donde se hara la lista
 * \param idAFiltrar: dato con el cual se filtra la lista
 */
void mostrarJugadoresFiltroConfederacion (eJugadores *estructura, eConfederaciones *estructuraDos, char* mensajeErrorCarga,
		char* mensajeErrorGetNumero, int cantConf, int cantColumnas, int *idAFiltrar);

/**
 * \fn int verificarLlenoJugadores(eJugadores*)
 * \brief verifica que haya al menos un dato cargado en la estructura
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int verificarLlenoJugadores(eJugadores *estructura);


#define ABMJUGADORES_H_



#endif /* ABMJUGADORES_H_ */
