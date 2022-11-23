#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED
//#define CANT_SELECCIONES 32


typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
	//int isEmpty;
}Seleccion;

/**
 * \fn Seleccion selec_new*()
 * \brief reserva el espacio de memoria que requiere la estructura
 *
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
Seleccion* selec_new();

/**
 * \fn Seleccion selec_newParametros*(char*, char*, char*, char*)
 * \brief carga los datos ingresados en la estructura
 *
 * \param idStr dato a cargar
 * \param paisStr dato a cargar
 * \param confederacionStr dato a cargar
 * \param convocadosStr dato a cargar
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);

/**
 * \fn void selec_delete(Seleccion*)
 * \brief libera la memoria reservada en el puntero ingresado
 *
 * \param this puntero a estructura
 */
void selec_delete(Seleccion* this);

/**
 * \fn int selec_setId(Seleccion*, int)
 * \brief carga el dato ingresado en el puntero ingresado
 *
 * \param this puntero a estructura
 * \param id dato a cargar
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int selec_setId(Seleccion* this,int id);

/**
 * \fn int selec_getId(Seleccion*, int*)
 * \brief obtiene el dato del puntero ingresado
 *
 * \param this puntero a estructura
 * \param id dato que devuelve
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int selec_getId(Seleccion* this,int* id);

/**
 * \fn int selec_setPais(Seleccion*, char*)
 * \brief carga el dato ingresado en el puntero ingresado
 *
 * \param this puntero a estructura
 * \param pais dato a cargar
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int selec_setPais(Seleccion* this,char* pais);

/**
 * \fn int selec_getPais(Seleccion*, char*)
 * \brief obtiene el dato del puntero ingresado
 *
 * \param this puntero a estructura
 * \param pais dato que devuelve
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int selec_getPais(Seleccion* this,char* pais);

/**
 * \fn int selec_setConfederacion(Seleccion*, char*)
 * \brief carga el dato ingresado en el puntero ingresado
 *
 * \param this puntero a estructura
 * \param confederacion dato a cargar
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int selec_setConfederacion(Seleccion* this,char* confederacion);

/**
 * \fn int selec_getConfederacion(Seleccion*, char*)
 * \brief obtiene el dato del puntero ingresado
 *
 * \param this puntero a estructura
 * \param confederacion dato que devuelve
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int selec_getConfederacion(Seleccion* this,char* confederacion);

/**
 * \fn int selec_setIsEmpty(Seleccion*, int)
 * \brief carga el dato ingresado en el puntero ingresado
 *
 * \param this puntero a estructura
 * \param isEmpty dato a cargar
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int selec_setIsEmpty(Seleccion* this,int isEmpty);

/**
 * \fn int selec_getIsEmpty(Seleccion*, int*)
 * \brief obtiene el dato del puntero ingresado
 *
 * \param this puntero a estructura
 * \param isEmpty dato que devuelve
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int selec_getIsEmpty(Seleccion* this,int* isEmpty);

/**
 * \fn int selec_setConvocados(Seleccion*, int)
 * \brief carga el dato ingresado en el puntero ingresado
 *
 * \param this puntero a estructura
 * \param convocados dato a cargar
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int selec_setConvocados(Seleccion* this,int convocados);

/**
 * \fn int selec_getConvocados(Seleccion*, int*)
 * \brief obtiene el dato del puntero ingresado
 *
 * \param this puntero a estructura
 * \param convocados dato que devuelve
 * \return si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int selec_getConvocados(Seleccion* this,int* convocados);



#endif // selec_H_INCLUDED

