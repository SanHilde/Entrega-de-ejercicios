#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <wchar.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "outputs.h"
#include "parser.h"

/**
 * \fn int controller_cargarJugadoresDesdeTexto(char*, LinkedList*)
 * \brief abre el archivo en modo texto tipo lectura y le pasa la direccion de memoria del linked list al parser
 *
 * \param path cadena de texto que necesita la funcion
 * \param pArrayListJugador puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);

/***
 * \fn int controller_cargarJugadoresDesdeBinario(char*, LinkedList*)
 * \brief abre el archivo en modo binario tipo lectura y le pasa la direccion de memoria del linked list al parser
 *
 * \param path cadena de texto que necesita la funcion
 * \param pArrayListJugador puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

/**
 * \fn int controller_agregarJugador(LinkedList*)
 * \brief pide los datos correspondientes para agregar un jugador
 *
 * \param pArrayListJugador puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_agregarJugador(LinkedList* pArrayListJugador);

/**
 * \fn int controller_editarJugador(LinkedList*)
 * \brief permite elegir que dato editar y pide el dato correspondiente nuevo
 *
 * \param pArrayListJugador puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int controller_editarJugador(LinkedList* pArrayListJugador);

/**
 * \fn int controller_removerJugador(LinkedList*)
 * \brief pide elegir que jugador eliminar, tambien libera el espacio de memoria ocupada por el mismo
 *
 * \param pArrayListJugador puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si se cancelo la ejecucion de la funcion a proposito 0, si hubo un error, el retorno es -1
 */
int controller_removerJugador(LinkedList* pArrayListJugador);

/**
 * \fn int controller_listarJugadores(LinkedList*)
 * \brief lista todos los  que estan dentro de la estructura guardada en la linked list
 *
 * \param pArrayListJugador puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_listarJugadores(LinkedList* pArrayListJugador);

/**
 * \fn int controller_ordenarJugadores(LinkedList*)
 * \brief ordena las distintas estructuras dentro de la linked list en funcion de los parametros de comparacion ingresados dentro
 *
 * \param pArrayListJugador puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_ordenarJugadores(LinkedList* pArrayListJugador);

/**
 * \fn int controller_guardarJugadoresModoTexto(char*, LinkedList*)
 * \brief abre el archivo en modo texto tipo escritura y le escribe los datos que se desean
 *
 * \param path cadena de texto que necesita la funcion
 * \param pArrayListJugador puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/**
 * \fn int controller_guardarJugadoresModoBinario(char*, LinkedList*)
 * \brief abre el archivo en modo binario tipo escritura y le escribe los datos que se desean
 *
 * \param path cadena de texto que necesita la funcion
 * \param pArrayListJugador puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

/**
 * \fn int controller_cargarSeleccionesDesdeTexto(char*, LinkedList*)
 * \brief abre el archivo en modo texto tipo lectura y le pasa la direccion de memoria del linked list al parser
 *
 * \param path cadena de texto que necesita la funcion
 * \param pArrayListSeleccion puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

/**
 * \fn int controller_editarSeleccion(LinkedList*)
 * \brief permite elegir que dato editar y pide el dato correspondiente nuevo
 *
 * \param pArrayListSeleccion puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);

/**
 * \fn int controller_listarSelecciones(LinkedList*)
 * \brief lista todos los  que estan dentro de la estructura guardada en la linked list
 *
 * \param pArrayListSeleccion puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

/**
 * \fn int controller_ordenarSelecciones(LinkedList*)
 * \brief ordena las distintas estructuras dentro de la linked list en funcion de los parametros de comparacion ingresados dentro
 *
 * \param pArrayListSeleccion puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/**
 * \fn int controller_guardarSeleccionesModoTexto(char*, LinkedList*)
 * \brief abre el archivo en modo texto tipo escritura y le escribe los datos que se desean
 *
 * \param path cadena de texto que necesita la funcion
 * \param pArrayListSeleccion puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

/**
 * \fn int controller_cargarConvocado(LinkedList*, LinkedList*)
 * \brief cambia el dato de convocacion del jugador elegido de 0 a la seleccion que uno elija
 *
 * \param pArrayListJugador puntero a linkedlist
 * \param pArrayListSeleccion puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_cargarConvocado (LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * \fn int controller_buscarSeleccion(LinkedList*, int, int*)
 * \brief busca el indice donde se almacena el id de la seleccion elegida
 *
 * \param pArrayListSeleccion puntero a linkedlist
 * \param idIngresado id con el cual se va a trabajar
 * \param index ubicación de donde se quiere extraer el dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_buscarSeleccion (LinkedList* pArrayListSeleccion, int idIngresado, int* index);

/**
 * \fn int controller_buscarJugador(LinkedList*, int, int*)
 * \brief busca el indice donde se almacena el id del jugador elegido
 *
 * \param pArrayListJugador puntero a linkedlist
 * \param idIngresado id con el cual se va a trabajar
 * \param index ubicación de donde se quiere extraer el dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_buscarJugador (LinkedList* pArrayListJugador, int idIngresado, int* index);

/**
 * \fn int controller_eliminarConvocado(LinkedList*, LinkedList*)
 * \brief cambia el dato de convocacion del jugador elegido que posee a 0
 *
 * \param pArrayListJugador puntero a linkedlist
 * \param pArrayListSeleccion puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_eliminarConvocado (LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * \fn int controller_calculadorJugadoresSeleccciones(LinkedList*, LinkedList*)
 * \brief revisa todos lo jugadores y si estos estan convocados en alguna seleccion, lo agrega a un contador
 *
 * \param pArrayListJugador puntero a linkedlist
 * \param pArrayListSeleccion puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  */
int controller_calculadorJugadoresSeleccciones (LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * \fn int controller_ordenarSeleccionPorID(void*, void*)
 * \brief compara los datos de ambos punteros y devuelve un valor en funcion de la comparacion
 *
 * \param punteroUno primer dato traido a traves de puntero
 * \param punteroDos segundo dato traido a traves de puntero
 * \return si idUno < idDos el retorno = -1, si idUno > idDos el retorno = 1
 * */
int controller_ordenarSeleccionPorID (void* punteroUno, void* punteroDos);

/**
 * \fn int controller_ordenarSeleccionPorConf(void*, void*)
 * \brief compara los datos de ambos punteros y devuelve un valor en funcion de la comparacion
 *
 * \param punteroUno primer dato traido a traves de puntero
 * \param punteroDos segundo dato traido a traves de puntero
 * \return si confUno < confDos el retorno = -1, si confUno > confDos el retorno = 1
 */
int controller_ordenarSeleccionPorConf (void* punteroUno, void* punteroDos);

/**
 * \fn int controller_ordenarJugadoresPorNombre(void*, void*)
 * \brief
 *
 * \param punteroUno primer dato traido a traves de puntero
 * \param punteroDos segundo dato traido a traves de puntero
 * \return si datoUno < datoDos el retorno = -1, si datoUno > datoDos el retorno = 1
 */
int controller_ordenarJugadoresPorNombre (void* punteroUno, void* punteroDos);

/**
 * \fn int controller_ordenarJugadoresPorEdad(void*, void*)
 * \brief compara los datos de ambos punteros y devuelve un valor en funcion de la comparacion
 *
 * \param punteroUno primer dato traido a traves de puntero
 * \param punteroDos segundo dato traido a traves de puntero
 * \return si datoUno < datoDos el retorno = -1, si datoUno > datoDos el retorno = 1
 */
int controller_ordenarJugadoresPorEdad (void* punteroUno, void* punteroDos);

/**
 * \fn int controller_ordenarJugadoresPorNacionalidad(void*, void*)
 * \brief compara los datos de ambos punteros y devuelve un valor en funcion de la comparacion
 *
 * \param punteroUno primer dato traido a traves de puntero
 * \param punteroDos segundo dato traido a traves de puntero
 * \return si datoUno < datoDos el retorno = -1, si datoUno > datoDos el retorno = 1
 */
int controller_ordenarJugadoresPorNacionalidad (void* punteroUno, void* punteroDos);

/**
 * \fn int controller_ordenarJugadoresPorID(void*, void*)
 * \brief
 *
 * \param punteroUno primer dato traido a traves de puntero
 * \param punteroDos segundo dato traido a traves de puntero
 * \return si datoUno < datoDos el retorno = -1, si datoUno > datoDos el retorno = 1
 */
int controller_ordenarJugadoresPorID (void* punteroUno, void* punteroDos);

/**
 * \fn int controller_unificacionDatosSeleccion(LinkedList*, char*, int)
 * \brief junta todos los datos que posee un puntero de una estructura y los guarda en una sola variable de texto, separados por coma
 *
 * \param pArrayListSeleccion puntero a linkedlist
 * \param datoCompleto
 * \param indice ubicación de donde se quiere extraer el dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 *  *  */
int controller_unificacionDatosSeleccion (LinkedList* pArrayListSeleccion, char* datoCompleto, int indice);

/**
 * \fn int controller_unificacionDatosJugadores(LinkedList*, char*, int)
 * \brief junta todos los datos que posee un puntero de una estructura y los guarda en una sola variable de texto, separados por coma
 *
 * \param pArrayListJugador puntero a linkedlist
 * \param datoCompleto
 * \param indice ubicación de donde se quiere extraer el dato
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int controller_unificacionDatosJugadores (LinkedList* pArrayListJugador, char* datoCompleto, int indice);

/**
 * \fn int controller_generarNombreCompleto(char*)
 * \brief pide todos los datos necesarios para generar una cadena de caracteres con un nombre completo
 *
 * \param nombreCompleto puntero a variable que almacena el nombre completo
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int controller_generarNombreCompleto (char* nombreCompleto); //completar

#endif /* CONTROLLER_H_ */
