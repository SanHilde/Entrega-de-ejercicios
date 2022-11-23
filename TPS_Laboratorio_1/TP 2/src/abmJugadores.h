

#ifndef ABMJUGADORES_H_
#include "outputConfederaciones.h"

#define COLUMNA_UNO_JUGADOR 7
#define COLUMNA_DOS_JUGADOR 30
#define COLUMNA_TRES_JUGADOR 15
#define COLUMNA_CUATRO_JUGADOR 15
#define COLUMNA_CINCO_JUGADOR 18
#define COLUMNA_SEIS_JUGADOR 15
#define COLUMNA_SIETE_JUGADOR 15

/**
 * \struct
 * \brief estrucutura que permite guardar datos del jugador
 *
 */
typedef struct {
	int id;
	char nombre[CANT_CARACTERES];
	char posicion[CANT_CARACTERES];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
} eJugadores;

/**
 * \fn int altaDatosJugador(eJugadores*, eConfederaciones*, char*, char*, char*, int)
 * \brief pide todos los datos que se necesitan cargar en la estrucutra, los valida con cada funcion pertinente y los deja dados de alta
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param estructuraDos: parametros donde se guardan los datos de una segunda estructura que esta relacionada a la primera
 * \param mensajeErrorGetNumero: mensaje que aparece cuando el numero esta por fuera del rango solicitado o si se ingresa caracteres
 * \param mensajeErrorGetNumeroPositivo: mensaje que aparece cuando el numero esta por debajo del minimo o si se ingresa caracteres
 * \param mensajeErrorGetCadena: mensaje que aparece cuando se supero la cantidad de caracteres
 * \param cantConf
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int altaDatosJugador(eJugadores *estructura, eConfederaciones *estructuraDos, char* mensajeErrorGetNumero, char* mensajeErrorGetNumeroPositivo,
char* mensajeErrorGetCadena, int cantConf);

/**
 * \fn int bajarDatoJugador(eJugadores*, char*, char*, int, int)
 * \brief da de baja un dato y lo deja inactivo
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param mensaje: mensaje que aparecera en el ingreso del dato, indica que se va a pedir
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param minimo: valor minimo que debe tener el dato ingresado, sirve para validar
 * \param intentos: cantidad de intentos que se puede ingresa el dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int bajarDatoJugador(eJugadores *estructura,char *mensaje, char *mensajeError, int minimo, int intentos );

/**
 * \fn int buscarDato(eJugadores*, int, int*)
 * \brief busca un dato pedido y te devuelve el indice donde esta guardado, si este cumple con el estado solicitado
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param datoABuscar: valor el cual se buscara en un bucle for
 * \param indice: ubicación de donde se quiere extraer el dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int buscarDatoJugador(eJugadores *estructura,int datoABuscar, int* indice);

/**
 * \fn int buscarLibreJugador(eJugadores*, int*)
 * \brief busca un indice libre de forma automatica, y te devuelve le indice para que lo puedas usar
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param indice: ubicación de donde se quiere extraer el dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int buscarLibreJugador(eJugadores *estructura , int *indice);

/**
 * \fn int hardCodeoJugadores(eJugadores*, int, short*)
 * \brief hardcodea datos para que queden cargados de forma automaticac
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param cantidad
 * \param indiceIncremental: ubicación de donde se quiere extraer el dato y, a su vez, incrementa para devolverlo aumentado
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int hardCodeoJugadores (eJugadores *estructura, int cantidad, short *indiceIncremental);

/**
 * \fn int inicializadorJugadores(eJugadores*)
 * \brief deja todos los valores de estado a libre, para que se puedan usar
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura1
 * \return
 */
int inicializadorJugadores (eJugadores *estructura);
/**
 * \fn int modificarAniosContratoJugador(eJugadores*, char*, char*, char*, int)
 * \brief modificar un dato especifico en la estructura
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param mensaje: mensaje que aparecera en el ingreso del dato, indica que se va a pedir
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param mensajeErrorCadena: mensaje que aparece cuando se supero la cantidad de caracteres
 * \param minimo: valor minimo que debe tener el dato ingresado, sirve para validar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int modificarAniosContratoJugador(eJugadores *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo);

/**
 * \fn int modificarCamisetaJugador(eJugadores*, char*, char*, char*, int)
 * \brief modificar un dato especifico en la estructura
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param mensaje: mensaje que aparecera en el ingreso del dato, indica que se va a pedir
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param mensajeErrorCadena: mensaje que aparece cuando se supero la cantidad de caracteres
 * \param minimo: valor minimo que debe tener el dato ingresado, sirve para validar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int modificarCamisetaJugador(eJugadores *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo);

/**
 * \fn int modificarConfederacionJugador(eJugadores*, eConfederaciones*, char*, char*, char*, char*, int, int)
 * \brief modificar un dato especifico en la estructura
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param estructuraDos: parametros donde se guardan los datos de una segunda estructura que esta relacionada a la primera
 * \param mensaje: mensaje que aparecera en el ingreso del dato, indica que se va a pedir
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param mensajeErrorCarga: mensaje que aparece cuando shubo un error en la carga de de datos o no hay datos para mostrar
 * \param mensajeErrorCadena: mensaje que aparece cuando se supero la cantidad de caracteres
 * \param minimo: valor minimo que debe tener el dato ingresado, sirve para validar
 * \param cantConf
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int modificarConfederacionJugador(eJugadores *estructura, eConfederaciones *estrucutraDos, char* mensaje, char* mensajeError,
char* mensajeErrorCarga, char* mensajeErrorCadena, int minimo, int cantConf);

/**
 * \fn int modificarNombreJugador(eJugadores*, char*, char*, char*, int)
 * \brief modificar un dato especifico en la estructura
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param mensaje: mensaje que aparecera en el ingreso del dato, indica que se va a pedir
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param mensajeErrorCadena: mensaje que aparece cuando se supero la cantidad de caracteres
 * \param minimo: valor minimo que debe tener el dato ingresado, sirve para validar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int modificarNombreJugador(eJugadores *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo);

/**
 * \fn int modificarPosicionJugador(eJugadores*, char*, char*, char*, int)
 * \brief modificar un dato especifico en la estructura
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param mensaje: mensaje que aparecera en el ingreso del dato, indica que se va a pedir
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param mensajeErrorCadena: mensaje que aparece cuando se supero la cantidad de caracteres
 * \param minimo: valor minimo que debe tener el dato ingresado, sirve para validar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int modificarPosicionJugador(eJugadores *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo);

/**
 * \fn int modificarSalarioJugador(eJugadores*, char*, char*, char*, int)
 * \brief modificar un dato especifico en la estructura
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param mensaje: mensaje que aparecera en el ingreso del dato, indica que se va a pedir
 * \param mensajeError: mensaje que aparece cuando hay algo que salio mal en la funcion
 * \param mensajeErrorCadena: mensaje que aparece cuando se supero la cantidad de caracteres
 * \param minimo: valor minimo que debe tener el dato ingresado, sirve para validar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int modificarSalarioJugador(eJugadores *estructura, char* mensaje, char* mensajeError, char* mensajeErrorCadena, int minimo);

/**
 * \fn void ordenarPorConfederacion(eJugadores*, eConfederaciones*)
 * \brief ordena los datos por algun parametro
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 * \param estructuraDos: parametros donde se guardan los datos de una segunda estructura que esta relacionada a la primera
 */
void ordenarPorConfederacion (eJugadores *estructura, eConfederaciones *estructuraDos);

/**
 * \fn void ordenarPorId(eJugadores*)
 * \brief ordena los datos por algun parametro
 *
 * \param estructura:  parametros donde se guardan los datos de la estructura
 */
void ordenarPorId (eJugadores *estructura);

/**
 * \fn int correccionMayusculasCadena(char*)
 * \brief corrige la cadena de caracteres ingresada y le pone mayuscula a cada palabra
 *
 * \param cadena: cadena de caracteres ingresada
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int correccionMayusculasCadena (char *cadena);

/**
 * \fn int validarPosicion(char*, char*)
 * \brief valida que las posicion cargada sea una de las sugeridas
 *
 * \param cadena: cadena de caracteres ingresada
 * \param mensajeErrorCadena: mensaje que aparece cuando se supero la cantidad de caracteres
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int validarPosicion (char *cadena,char *mensajeErrorGetCadena);


#define ABMJUGADORES_H_



#endif /* ABMJUGADORES_H_ */
















































































































































