
#ifndef PARSER_H_
#define PARSER_H_


/**
 * \fn int parser_JugadorFromText(FILE*, LinkedList*)
 * \brief parsea los datos ingresados en el archivo a la linkedlist en modo texto
 *
 * \param pFile puntero a archivo
 * \param pArrayListJugador puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/**
 * \fn int parser_JugadorFromBinary(FILE*, LinkedList*)
 * \brief parsea los datos ingresados en el archivo a la linkedlist en modo binario
 *
 * \param pFile puntero a archivo
 * \param pArrayListJugador puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

/**
 * \fn int parser_SeleccionFromText(FILE*, LinkedList*)
 * \brief parsea los datos ingresados en el archivo a la linkedlist en modo texto
 *
 * \param pFile puntero a archivo
 * \param pArrayListSeleccion puntero a linkedlist
 * \return: si el pasaje de datos es correcto y la funcion trabajo correctamente, el retono es 1, si hubo un error, el retorno es -1
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);


#endif /* PARSER_H_ */

