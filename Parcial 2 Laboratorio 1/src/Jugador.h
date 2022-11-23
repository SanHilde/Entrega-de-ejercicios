#include "LinkedList.h"


#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
	//int isEmpty;
}Jugador;

/**
 * \fn Jugador jug_new*()
 * \brief reserva el espacio de memoria que requiere la estructura
 *
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
Jugador* jug_new();

/**
 * \fn Jugador jug_newParametros*(char*, char*, char*, char*, char*, char*)
 * \brief	carga los datos ingresados en la estructura
 *
 * \param idStr	dato a cargar
 * \param nombreCompletoStr	dato a cargar
 * \param edadStr	dato a cargar
 * \param posicionStr	dato a cargar
 * \param nacionalidadStr	dato a cargar
 * \param idSelccionStr	dato a cargar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

/**
 * \fn void jug_delete(Jugador*)
 * \brief	libera la memoria reservada en el puntero ingresado
 *
 * \param this puntero a estructura
 */
void jug_delete(Jugador* this);

/**
 * \fn int jug_setId(Jugador*, int)
 * \brief carga el dato ingresado en el puntero ingresado
 *
 * \param this puntero a estructura
 * \param id	dato a cargar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int jug_setId(Jugador* this,int id);
/**
 * \fn int jug_getId(Jugador*, int*)
 * \brief obtiene el dato del puntero ingresado
 *
 * \param this puntero a estructura
 * \param id dato que devuelve
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int jug_getId(Jugador* this,int* id);

/**
 * \fn int jug_setNombreCompleto(Jugador*, char*)
 * \brief carga el dato ingresado en el puntero ingresado
 *
 * \param this puntero a estructura
 * \param nombreCompleto	dato a cargar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);

/**
 * \fn int jug_getNombreCompleto(Jugador*, char*)
 * \brief	obtiene el dato del puntero ingresado
 *
 * \param this puntero a estructura
 * \param nombreCompleto dato que devuelve
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

/**
 * \fn int jug_setPosicion(Jugador*, char*)
 * \brief carga el dato ingresado en el puntero ingresado
 *
 * \param this puntero a estructura
 * \param posicion	dato a cargar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int jug_setPosicion(Jugador* this,char* posicion);
/**
 * \fn int jug_getPosicion(Jugador*, char*)
 * \brief	obtiene el dato del puntero ingresado
 *
 * \param this puntero a estructura
 * \param posicion	dato que devuelve
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int jug_getPosicion(Jugador* this,char* posicion);

/**
 * \fn int jug_setNacionalidad(Jugador*, char*)
 * \brief carga el dato ingresado en el puntero ingresado
 *
 * \param this puntero a estructura
 * \param nacionalidad	dato a cargar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad);

/**
 * \fn int jug_getNacionalidad(Jugador*, char*)
 * \brief	obtiene el dato del puntero ingresado
 *
 * \param this puntero a estructura
 * \param nacionalidad dato que devuelve
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

/**
 * \fn int jug_setEdad(Jugador*, int)
 * \brief carga el dato ingresado en el puntero ingresado
 *
 * \param this puntero a estructura
 * \param edad	dato que devuelve
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int jug_setEdad(Jugador* this,int edad);

/**
 * \fn int jug_getEdad(Jugador*, int*)
 * \brief	obtiene el dato del puntero ingresado
 *
 * \param this puntero a estructura
 * \param edad	dato a cargar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int jug_getEdad(Jugador* this,int* edad);

/**
 * \fn int jug_setIdSeleccion(Jugador*, int)
 * \brief carga el dato ingresado en el puntero ingresado
 *
 * \param this puntero a estructura
 * \param idSeleccion	dato a cargar
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion);

/**
 * \fn int jug_getSIdSeleccion(Jugador*, int*)
 * \brief	obtiene el dato del puntero ingresado
 *
 * \param this puntero a estructura
 * \param idSeleccion	dato que devuelve
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);

//int jug_setIsEmpty(Jugador* this,int isEmpty);
//int jug_getIsEmpty(Jugador* this,int* isEmpty);


#endif // jug_H_INCLUDED

