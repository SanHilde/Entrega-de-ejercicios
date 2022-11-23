
#ifndef ABMCONFEDERACIONES_H_


#include "abmConfederaciones.h"

/**
 * \fn int decodificacionId(eConfederaciones*, int*, char*)
 * \brief recobe un id y devuelve lo que significa ese id
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param idAIdentificar: id que recibe
 * \param pIdIdentificado: la caracteristica del id
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int decodificacionId (eConfederaciones *estructura, int *idAIdentificar, char *pIdIdentificado);

/**
 * \fn int decodificacionId(eConfederaciones*, int*, char*)
 * \brief recobe un id y devuelve lo que significa ese id
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param idAIdentificar: id que recibe
 * \param pIdIdentificado: la caracteristica del id
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int decodificacionIdRegion (eConfederaciones *estructura, int *idAIdentificar, char *pIdIdentificado);

/**
 * \fn void impresionDeCuadroConfederaciones(int)
 * \brief imprime encabezado de cuadro para mostrar datos
 *
 * \param cantColumnas: cantidad de columnas que necesita el cuadro
 */
void impresionDeCuadroConfederaciones (int cantColumnas);

/**
 * \fn void impresionFila(int, int, char*)
 * \brief imprime linas que divide el cuadro
 *
 * \param cantCaracteres: cantidad de caracteres que debe imprimir
 * \param cantColumnas: cantidad de columnas que necesita el cuadro
 * \param caracter: caracter a imprimir
 */
void impresionFila (int cantCaracteres, int cantColumnas, char *caracter);

/**
 * \fn int listaConfederaciones(eConfederaciones*, char*, int)
 * \brief recorre a modo de lista todos los datos en la estructura
 *
 * \param confederacion: variable donde se guardan los datos de la estructura
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param cantColumnas: cantidad de columnas que necesita el cuadro
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int listaConfederaciones( eConfederaciones *confederacion, char* mensajeError, int cantColumnas);

/**
 * \fn void mostrarDatoConfederacion(eConfederaciones*, int, char*)
 * \brief imprime el dato solicitado
 *
 * \param confederacion: variable donde se guardan los datos de la estructura
 * \param indice: ubicación de donde se quiere extraer el dato
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 */
void mostrarDatoConfederacion( eConfederaciones *confederacion,int indice, char* mensajeError);

/**
 * \fn int rellenoDeVariable(char*, int)
 * \brief funcion que llenera la cadena de caracteres para que quede bien contra un lateral
 *
 * \param cadena: cadena de caracteres a rellenar
 * \param len: largo que debe tener la cadena de caracteres final
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int rellenoDeVariable (char *cadena, int len);

/**
 * \fn int rellenoDeVariableCentrado(char*, int)
 * \brief funcion que llenera la cadena de caracteres para que quede bien centrada
 *
 * \param cadena: cadena de caracteres a rellenar
 * \param len: largo que debe tener la cadena de caracteres final
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int rellenoDeVariableCentrado (char *cadena, int len);

/**
 * \fn void respuesta(int)
 * \brief imprime una respuesta segun el valor ingresado
 *
 * \param valor: valor a ingresar, el cual permite realizar determinada accion
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int respuesta(int valor);

/**
 * \fn int verificarLlenoConfederacion(eConfederaciones*)
 * \brief verifica que haya al menos un dato cargado en la estructura
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int verificarLlenoConfederacion(eConfederaciones *estructura);


#define ABMCONFEDERACIONES_H_



#endif /* ABMCONFEDERACIONES_H_ */
