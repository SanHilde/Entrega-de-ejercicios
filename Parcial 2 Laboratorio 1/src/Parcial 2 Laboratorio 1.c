/*
 ============================================================================
 Name        : Parcial.c
 Author      : Santiago Hildebrandt
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//#include <stdio.h>
//#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "outputs.h"

#define INTENTOS 3

int main(void) {

	setbuf(stdout,NULL);

    int opcionMenuPrincipal = 0;
    //int opcionSubMenu = 0;
    char confirmacion;
    int numeroMinimoValidacion=1;
    int contadorCambios=0;
    char mensajeErrorGetNumero[] = ("El dato ingresado esta fuera del rango solicitado.\n");
	char mensajeErrorBandera[] = ("\nNo hay datos cargados, no se puede ingresar.\n\n");
	//char mensajeSalida[] = ("Usted selecciono salir, vuelve al menu anterior.\n\n");

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* listaFiltrados = ll_newLinkedList();
    LinkedList* listaMap = ll_newLinkedList();

    do{
    	utn_getNumeroInt(&opcionMenuPrincipal,
						"\n\tMenu principal\n"
						"Seleccione que desea realizar:\n"
						"1-Cargar de archivo\n"
    					"2-Imprimir lista\n"
						"3-Ordenar\n"
						"4-Filtro\n"
						"5-Mapeo \n"
						"6-Guardar en archivo\n"
						"7-Salir\n"
						"Numero ingresado: ",
						mensajeErrorGetNumero,
						numeroMinimoValidacion,
						7,
						INTENTOS);

        switch(opcionMenuPrincipal)
        {
        case 1:
        	if (ll_isEmpty(listaJugadores)!=0 && ll_isEmpty(listaSelecciones)!=0)
        	{
				output_respuesta(controller_cargarSeleccionesDesdeTexto("selecciones.csv" , listaSelecciones));
				output_respuesta(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores));
				if (controller_ordenarSelecciones(listaSelecciones) != 1)
				{
					printf("Hubo un error al ordenar las selecciones");
				}
        	} else
        	{
        		printf ("\nEsta queriendo cargar nuevamente los datos, si lo hace, se perdera lo que no esta guardado y se volvera al "
        				"ultimo guardado que tuvo. \n\n");
        		output_pedirConfirmacion (&confirmacion,INTENTOS);
				if (confirmacion=='S')
				{
					ll_clear (listaSelecciones);
					ll_clear (listaJugadores);
					output_respuesta(controller_cargarSeleccionesDesdeTexto("selecciones.csv" , listaSelecciones));
					output_respuesta(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores));
					if (controller_ordenarSelecciones(listaSelecciones) != 1)
					{
						printf("Hubo un error al ordenar las selecciones");
					}
				} else
				{
					printf ("\nOperacion cancelada. Vuelve al menu principal\n");
					opcionMenuPrincipal=0;
				}
        	}
        	break;
        case 2:
			if (ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0)
			{
			output_listarJugadoresDecodificado (listaJugadores,listaSelecciones);
			controller_calculadorJugadoresSeleccciones (listaJugadores, listaSelecciones);
			controller_listarSelecciones (listaSelecciones);
			} else
			{
				printf ("%s",mensajeErrorBandera);
			}
        	break;
        case 3:
        	if (ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0)
			{
				if (ll_sort(listaJugadores,controller_ordenarJugadoresPorNacionalidad , 1)==0)
				{
					output_listarJugadoresDecodificado (listaJugadores,listaSelecciones);
				}
				controller_ordenarJugadores (listaJugadores);
				controller_ordenarSelecciones(listaSelecciones);

			} else
			{
				printf ("%s",mensajeErrorBandera);
			}
        	break;
        case 4:
        	if (ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0)
			{
        		listaFiltrados = ll_filter(listaJugadores,controller_filtrarJugadorConvocado);
				if (listaFiltrados != NULL)
				{
					output_listarJugadoresDecodificado (listaFiltrados,listaSelecciones);
				} else
				{
					printf ("La lista esta vacia\n");
				}
				contadorCambios++;
			} else
			{
				printf ("%s",mensajeErrorBandera);
			}
        	break;
        case 5:
        	if (ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0)
			{
        		listaMap = ll_map(listaJugadores,controller_mapearJugadorEdad);
				if (listaMap != NULL)
				{
					//output_listarJugadoresDecodificado (listaMap,listaSelecciones);
					output_respuesta(controller_guardarJugadoresModoTexto ("jugadoresMapeados.csv",listaMap));
				} else
				{
					printf ("La lista esta vacia\n");
				}
				contadorCambios++;
			} else
			{
				printf ("%s",mensajeErrorBandera);
			}
        	break;
        case 6:
              	if (ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0)
      			{
      				if (contadorCambios != 0)
      				{
      					if (listaFiltrados != NULL)
      					{
      					controller_calculadorJugadoresSeleccciones (listaJugadores, listaSelecciones);
      					output_respuesta(controller_guardarJugadoresModoTexto ("jugadoresFiltrados.csv",listaFiltrados));
      					} else
      					{
      						printf ("La lista esta vacia, quiere guardar igualmente?\n");
      					}
      					if (output_respuesta(controller_guardarSeleccionesModoTexto("selecciones.csv" , listaSelecciones))== 1)
      					{
      						contadorCambios =0;
      					}
      				} else
      				{
      					printf ("\nNo hay cambios para guardar.\n");
      				}
      			} else
      			{
      				printf ("%s",mensajeErrorBandera);
      			}
/*
      			 if (ll_isEmpty(listaJugadores)==0 && ll_isEmpty(listaSelecciones)==0)
      			{
      				output_respuesta(controller_guardarJugadoresModoBinario ("listaSeleccionesBinario.dat",listaJugadores));
      			} else
      			{
      				printf ("%s",mensajeErrorBandera);
      			}
*/
      			break;
        case 7:
			if (contadorCambios != 0)
			{
				printf ("\nEsta queriendo salir sin haber guardado los cambios.\n");
			}
			output_pedirConfirmacion (&confirmacion,INTENTOS);
			if (confirmacion=='S')
			{
				printf ("\nEligio salir. El programa finalizo. ");
			} else
			{
				opcionMenuPrincipal=0;
			}
			break;
			}
    }while(opcionMenuPrincipal != 7);

    ll_deleteLinkedList(listaSelecciones);
    ll_deleteLinkedList(listaJugadores);
    ll_deleteLinkedList(listaFiltrados);
    ll_deleteLinkedList(listaMap);
    return 0;
}


