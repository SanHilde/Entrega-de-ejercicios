
#ifndef ABMCONFEDERACIONES_H_
#include "inputs.h"

#define INTENTOS 3
#define LIBRE 1
#define OCUPADO 0
#define INACTIVO -1
#define CANCELAR 0

#define COLUMNA_UNO_CONF 7
#define COLUMNA_DOS_CONF 15
#define COLUMNA_TRES_CONF 25
#define COLUMNA_CUATRO_CONF 16

#define CANT_CARACTERES 50
#define CANT_JUGADORES 3000
#define CANT_CONF 10

/**
 * \struct
 * \brief estrucutura que permite guardar datos de la confederacion
 *
 */
typedef struct {
	int id;
	char nombre[CANT_CARACTERES];
	char region[CANT_CARACTERES];
	int anioCreacion;
	short isEmpty;
} eConfederaciones;

/**
 * \fn int altaDatosConfederacion(eConfederaciones*, char*, char*, char*)
 * \brief pide todos los datos que se necesitan cargar en la estrucutra, los valida con cada funcion pertinente y los deja dados de alta
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param mensajeErrorGetNumero: mensaje que aparece cuando el numero esta por fuera del rango solicitado o si se ingresa caracteres
 * \param mensajeErrorGetNumeroPositivo: mensaje que aparece cuando el numero esta por debajo del minimo o si se ingresa caracteres
 * \param mensajeErrorGetCadena: mensaje que aparece cuando se supero la cantidad de caracteres
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int altaDatosConfederacion(eConfederaciones *estructura, char* mensajeErrorGetNumero, char* mensajeErrorGetNumeroPositivo,
		char* mensajeErrorGetCadena);

/**
 * \fn int bajarDatoConfederacion(eConfederaciones*, char*, char*, int, int, int)
 * \brief da de baja un dato y lo deja inactivo
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param mensaje: mensaje que aparecera en el ingreso del dato, indica que se va a pedir
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param minimo: valor minimo que debe tener el dato ingresado, sirve para validar
 * \param maximo: valor maximo que debe tener el dato ingresado, sirve para validar
 * \param intentos: cantidad de intentos que se puede ingresa el dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int bajarDatoConfederacion(eConfederaciones *estructura,char *mensaje, char *mensajeError, int minimo, int maximo, int intentos );

/***
 * \fn int buscarDatoConfederaciones(eConfederaciones*, int, int*)
 * \brief busca un dato pedido y te devuelve el indice donde esta guardado, si este cumple con el estado solicitado
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param datoABuscar: dato que se pasa a la funcion para buscarlo en un bucle
 * \param indice: ubicación de donde se quiere extraer el dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int buscarDatoConfederaciones(eConfederaciones *estructura,int datoABuscar, int* indice);

/**
 * \fn int buscarLibreConfederacion(eConfederaciones*, int*)
 * \brief busca un indice libre de forma automatica, y te devuelve le indice para que lo puedas usar
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param indice: ubicación de donde se quiere extraer el dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int buscarLibreConfederacion(eConfederaciones *estructura , int *indice);

/**
 * \fn int hardCodeoConfederaciones(eConfederaciones*, int, short*)
 * \brief hardcodea datos para que queden cargados de forma automaticac
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param cantidad: numero que simboliza una cantidad necesaria para aplicar a la funcion
 * \param indiceIncremental: ubicación de donde se quiere extraer el dato y, a su vez, incrementa para devolverlo aumentado
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -5
 */
int hardCodeoConfederaciones (eConfederaciones *estructura, int cantidad,  short *indiceIncremental);

/**
 * \fn int inicializadorConfederaciones(eConfederaciones*)
 * \brief deja todos los valores de estado a libre, para que se puedan usar
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int inicializadorConfederaciones (eConfederaciones *estructura);

/**
 * \fn int modificarAnioConfederacion(eConfederaciones*, char*, char*, char*, int, int)
 * \brief modificar un dato especifico en la estructura
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param mensaje: mensaje que aparecera en el ingreso del dato, indica que se va a pedir
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param mensajeErrorCadena: mensaje que aparece cuando se supero la cantidad de caracteres
 * \param minimo: valor minimo que debe tener el dato ingresado, sirve para validar
 * \param maximo: valor maximo que debe tener el dato ingresado, sirve para validar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int modificarAnioConfederacion(eConfederaciones *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo, int maximo);

/**
 * \fn int modificarNombreConfederacion(eConfederaciones*, char*, char*, char*, int, int)
 * \brief modificar un dato especifico en la estructura
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param mensaje: mensaje que aparecera en el ingreso del dato, indica que se va a pedir
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param mensajeErrorCadena: mensaje que aparece cuando se supero la cantidad de caracteres
 * \param minimo: valor minimo que debe tener el dato ingresado, sirve para validar
 * \param maximo: valor maximo que debe tener el dato ingresado, sirve para validar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int modificarNombreConfederacion(eConfederaciones *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo, int maximo);

/**
 * \fn int modificarRegionConfederacion(eConfederaciones*, char*, char*, char*, int, int)
 * \brief modificar un dato especifico en la estructura
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param mensaje: mensaje que aparecera en el ingreso del dato, indica que se va a pedir
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param mensajeErrorCadena: mensaje que aparece cuando se supero la cantidad de caracteres
 * \param minimo: valor minimo que debe tener el dato ingresado, sirve para validar
 * \param maximo: valor maximo que debe tener el dato ingresado, sirve para validar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int modificarRegionConfederacion(eConfederaciones *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo, int maximo);

/**
 * \fn int pedirConfirmacion(char*, int)
 * \brief pregunta si realmente quiere realizar la accion anterior
 *
 * \param caracterConfirmacion: caracter que confirmara si se quiere realizar la accion o no, S para si y N para no
 * \param intentos: valor el representara la cantidad de veces que se puede ingresar un dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int pedirConfirmacion(char *caracterConfirmacion, int intentos);

#define ABMCONFEDERACIONES_H_



#endif /* ABMCONFEDERACIONES_H_ */






































































































































