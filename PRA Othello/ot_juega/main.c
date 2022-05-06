#include <stdio.h>
#include <stdlib.h>

/** Procedimiento principal del juego. Es el que determina la dinámica del juego:
Diseña el algoritmo para poder jugar al Othello. Cada jugador, por turnos, selecciona una casilla para colocar su ficha, una vez colocada, se voltean todas las fichas del contricante que quedan entre la ficha recien puesta y el resto de fichas que están en el tablero.

Si un jugador no puede poner una ficha el turno pasa al siguiente jugador.

El juego acaba cuando el tablero está completo o cuando ninguno de los dos jugadores puede poner ficha.

Además de todos los procedimientos diseñados anteriormente, disponéis del procedimiento fp_ot_pon_ficha().  Dicho procedimiento es encarga de colocar una ficha (blanca o negra) en el tablero, en la fila y columna indicada. Además se encargará de voltear las fichas que correspondan.

/* Pone una ficha en el tablero y actualiza el resto de las fichas,
 * volteando las que correspondan.
 * No comprueba si la casilla es válida o no.
 *
 * @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Tablero de juego.
 * @param dim (Valor: entero) Dimensión real con la que se juega.
 * @param f (Valor: entero) Fila del tablero en la que se va a colocar la ficha.
 * @param c (Valor: entero) Columna del tablero en la que se va a colocar la ficha.
 * @param ficha (Valor: carácter) Ficha que se va a colocar: FICHA_BLANCA o FICHA_NEGRA.
 * @return (entero) Devuelve el número de fichas que han cambiado al color actual,
 * incluyendo la que se acaba de poner.
*/
funció fp_ot_pon_ficha (
		/* Parámetros de entrada/salida  */  var tablero: taula [][MCOLS_MAX] de caràcter,
		/* Parámetros de entrada */          dim: enter, f: enter, c: enter,
                                                     ficha: caràcter) retorna enter és;

/*

 * cada jugador elije su jugada y pasa el turno al siguiente.
 * El juego termina cuando no quedan casillas o
 * cuando ninguno de los jugadores tiene una jugada posible.
 * Cuando acaba, se guarda el récord del ganador en el fichero.
 *
 * @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Es el tablero del juego.
 * @param dim (Valor: entero) Dimensión con la que se está jugando.
 * @param jugadores (Ref: tabla[] de jugador_t) Es la información de los jugadores.
 * @param turno (Ref: entero) Indica el jugador que tiene el turno de juego.
 * @return (booleano) Devuelve cierto si el juego ha acabado y falso en caso contrario.
*/
bool ot_tablero_lleno(char tablero[][MCOLS_MAX], int dim)
{
    int f,c;
    bool tablero_lleno;

    f = 0;
    c = 0;
    tablero_lleno = true;

    while ((f<dim)&&(tablero_lleno != false)){
        while ((c<dim)&&(tablero_lleno!= false)){
            if(tablero[f][c] != FICHA_NEGRA)||(tablero[f][c] != FICHA_BLANCA){
                    tablero_lleno = false;
            }
        }
        c = 0;
        f++;
    }
}
bool fp_ot_juega (char tablero[][MCOLS_MAX], int dim, jugador_t jugadores[], int *turno)

{
    bool valida, tablero_completa, res, fin_juego;
    jugador_t aux;
    int cont, num_fichas, v1, v2;
    coord_t casillas_posibles;

    cont = *turno;
    valida = true;
    tablero_completa = false;

    while ((fin_juego != false)||(tablero_completo != true)){

        if (jugadores[cont].maquina == 'H'){

           valida = ot_decide_casilla_manual (tablero, dim, &f, &c, aux);

               if (valida == true){
                   jugadores[cont] = aux;
                   num_fichas = fp_ot_pon_ficha (tablero, dim, f, c, jugadores[cont].color);
               }
        }

        else if (jugadores[cont].maquina == 'M'){

            valida = ot_decide_casilla_auto(tablero, dim, f, c, jugadores[cont].color);

                if (valida == true){
                    jugadores[cont] = aux;
                    num_fichas = fp_ot_pon_ficha (tablero, dim, f, c, jugadores[cont].color);
                   }
        }

        tablero_completo = ot_tablero_lleno(tablero,dim);

        v1 = fp_ot_lista_posibles (tablero, dim, jugadores[0].color, casillas_posibles);
        v2 = fp_ot_lista_posibles (tablero, dim, jugadores[1].color, casillas_posibles);

        if ((v1!=0)&&(v2 != 0)){
            cont = siguiente_jugador (cont, 2);
        }

        else if ((v1== 0)&&(v2 == 0)){
            fin_juego=true;
        }
        else if (v1 == 0){
            cont = 1;
        }
        else{
            cont = 0;
        }
    }


        if(jugadores[0].puntos > jugadores[1].puntos){

            strcpy (nom_fichero, "record.txt");
            res = fp_ot_guarda_record(nom_fichero,jugadores[0].nombre, jigadores[0].puntos, jugadores[0].color);


        else{
            strcpy (nom_fichero, "record.txt");
            res = fp_ot_guarda_record(nom_fichero,jugadores[1].nombre, jugadores[1].puntos, jugadores[1].color);
            }
        }

        if (res == true){
                printf("Record guardado\n");
        }
        else{
                printf("No se ha podido guardar el record\n");
        }

    return (fin_partida);
}

