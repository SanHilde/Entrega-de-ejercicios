
#include "outputJugadores.h"

void impresionDeCuadroJugadores (int cantColumnas)
{
	int total = COLUMNA_UNO_JUGADOR+COLUMNA_DOS_JUGADOR+COLUMNA_TRES_JUGADOR+COLUMNA_CUATRO_JUGADOR+COLUMNA_CINCO_JUGADOR+
			COLUMNA_SEIS_JUGADOR+COLUMNA_SIETE_JUGADOR;
/*
	char columnaUno[] = ("ID");
	char columnaDos[] = ("NOMBRE");
	char columnaTres[] = ("POSICION");
	char columnaCuatro[] = ("N° CAMISETA");
	char columnaCinco[] = ("SUELDO");
	char columnaSeis[] = ("CONFEDERACION");
	char columnaSiete[] = ("AS DE CONTRATO");
*/
	//rellenoDeVariableCentrado (columnaUno,COLUMNA_UNO_JUGADOR);
	//rellenoDeVariableCentrado (columnaDos,COLUMNA_DOS_JUGADOR);
	//printf ("\naca estoy %s",columnaDos);
	//printf ("\n");
	impresionFila (total,cantColumnas, "=");
	//printf ("\n|%s|%s|%s|%s|%s|%s|%s|\n", columnaUno, columnaDos, columnaTres, columnaCuatro, columnaCinco, columnaSeis, columnaSiete );
	printf ("\n|%-7s|%-30s|%-15s|%-18s|%-15s|%-15s|A%cOS DE CONTRATO|\n", "ID", "NOMBRE", "POSICION", "N° CAMISETA", "SUELDO", "CONFEDERACION", 165);
	impresionFila (total,cantColumnas, "-");
}

int listaJugadores(eJugadores *jugador, eConfederaciones *confederacion, char* mensajeError, int cantColumnas)
{
	int retorno = ERROR;
	int total = COLUMNA_UNO_JUGADOR+COLUMNA_DOS_JUGADOR+COLUMNA_TRES_JUGADOR+COLUMNA_CUATRO_JUGADOR+COLUMNA_CINCO_JUGADOR+COLUMNA_SEIS_JUGADOR+COLUMNA_SIETE_JUGADOR;
	if(verificarLlenoJugadores(jugador) == OK)
	{
	   impresionDeCuadroJugadores(cantColumnas);
	   for(int i=0; i<CANT_JUGADORES; i++)
	   {
		   if((jugador+i)->isEmpty == OCUPADO)
		   {
			  mostrarDatoJugadores(jugador, confederacion, i, mensajeError);
		   }
	   }
	   printf ("\n");
	   impresionFila (total,cantColumnas,"-");
	   retorno = OK;
	}
	else
	{
	   printf("%s", mensajeError);
	}
	return retorno;
}

void mostrarDatoJugadores(eJugadores *jugador, eConfederaciones *confederacion,int indice, char* mensajeError)
{
	char pIdIdentificado[CANT_CARACTERES];

	if(indice > -1)
	{
		if ( decodificacionId (confederacion, &(jugador+indice)->idConfederacion, pIdIdentificado) == OK &&
		rellenoDeVariable ((jugador+indice)->nombre ,COLUMNA_DOS_JUGADOR)==OK &&
		rellenoDeVariable ((jugador+indice)->posicion ,COLUMNA_TRES_JUGADOR)==OK &&
		rellenoDeVariable (pIdIdentificado ,COLUMNA_SEIS_JUGADOR)== OK)
		{
		printf("\n|%d\t|%s|%s|\t%hd\t |%.2f\t |%s|\t%hd\t  |", (jugador+indice)->id,(jugador+indice)->nombre,(jugador+indice)->posicion,
						(jugador+indice)->numeroCamiseta,(jugador+indice)->salario,pIdIdentificado,(jugador+indice)->aniosContrato);
		} else
		{
			printf("Hubo un error en la carga de este jugador");
		}
	}
	else
	{
		printf("%s", mensajeError);
	}
}

void mostrarJugadoresFiltroConfederacion (eJugadores *estructura, eConfederaciones *estructuraDos, char* mensajeErrorCarga,
		char* mensajeErrorGetNumero, int cantConf, int cantColumnas, int *idAFiltrar)
{
	int bandera=ERROR;
	int i;
	int total = COLUMNA_UNO_JUGADOR+COLUMNA_DOS_JUGADOR+COLUMNA_TRES_JUGADOR+COLUMNA_CUATRO_JUGADOR+COLUMNA_CINCO_JUGADOR+
			COLUMNA_SEIS_JUGADOR+COLUMNA_SIETE_JUGADOR;

	impresionDeCuadroJugadores(cantColumnas);
	for( i=0; i<CANT_JUGADORES; i++)
	{
		if ((estructura+i)->isEmpty == OCUPADO && (estructura+i)->idConfederacion == *idAFiltrar)
		{
			mostrarDatoJugadores(estructura, estructuraDos, i, mensajeErrorCarga);
			bandera =OK;
		}
	}
	printf ("\n");
	impresionFila (total,cantColumnas,"-");
	if (bandera != OK)
	{
		printf ("\nNo hay jugadores para mostrar\n\n");
	}
}

int verificarLlenoJugadores(eJugadores *estructura)
{
	int retorno;
	retorno = ERROR;

	for(int i=0; i<CANT_JUGADORES; i++)
    {
	   if((estructura+i)->isEmpty == OCUPADO)
	   {
		   retorno = OK;
		   break;
	   }
    }

	return retorno;
}
