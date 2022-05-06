/**
 *  @file  		othello.h
 *  @brief     	Constantes y definición de procedimientos para el juego del Othello.
 *  @authors 	nom.cognom@estudiants.urv.cat
 *				nom.cognom@estudiants.urv.cat
 *  @version   	1.0
 *  @date      	4/7/19
 *
 *  Actualizar los datos del autor, versión y fecha con vuestros datos personales.
 */

#ifndef othello_h
#define othello_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "bibliotecaFP.h"
#include "generales.h"
#include "tablas.h"

/** @addtogroup S11 Sesión 11
 * @{
 */

/**
 Cambia el color de la ficha: si la ficha era de color era negro, nos devuelve el color blanco (FICHA_BLANCA) y si era blanco, nos devuelve negro (FICHA_NEGRA).
 Si el color no es correcto, nos devolverá la FICHA_VACIA.

 @param color_ficha (Valor: caràcter) Color actual de la ficha.
 @return (caràcter) Devuelve el color contrario al recibido como parámetro o FICHA_VACIA en caso de error.
 */
char ot_cambia_color(char color_ficha);

/** @} */

/** @addtogroup S12 Sesión 12
 * @{
 */

/**
 Inicializa el tablero de juego inicial, colocando las primeras fichas en el lugar correcto.

 @param tablero (Ref: tabla de carácter) Tablero con la situación del juego.
 @param dim (Valor: entero) Dimensión real con la que se jugará.
 */
void ot_tablero_inicial (char tablero[][DIM_MAX], int dim);

/**
 Permite dar valor inicial a los datos de un jugador:
 1. si es o no una máquina,
 2. nombre: si es humano pedirlo, o maquina_color si es máquina
 3. color asignado,
 4. última tirada = (-1, '-') coordenada no válida.
 5. puntuación inicial = 2
 
 @param jugador (Ref: jugador_t) Información del jugador.
 @param color (Valor: carácter) Color asigando al jugador.
 */
void ot_lee_jugador (jugador_t *jugador, char color);

/**
 Recupera la información de un jugador: nombre, puntuación...

 @param jugador (Ref: jugador_t) Datos del jugador.
 @param nombre (Ref: taula[] de caràcter) Nombre del jugador.
 @param color (Ref: enter) Color del jugador.
 @param maquina (Ref: booleà) Cierto si es tipo máquina y falso si es humano.
 @param fila (Ref: enter) Fila de la última tirada [1..dim]
 @param col (Ref: caracter) Columna de la última tirada ['A'..dim]
 @param puntuacion (Ref: enter) Puntuación del jugador.
 */
void ot_obtener_datos_jugador (jugador_t *jugador, char nombre[], int *color, bool *maquina, int *fila, char *col, int *puntuacion);

/** @} */

/** @addtogroup S13 Sesión 13
 * @{
 */

 /**
 Procedimiento inicial del juego.

 Mostrará al usuario el menú con las diversas opciones y controlará que éstas se seleccionan y se ejecutan de forma correcta.
 */
void ot_inicio(void);

/**
 Guarda toda la información de un juego en un fichero binario, para poder recuperalo posteriormente. La información se guarda en el fichero en el siguiente orden: dimensión, turno, tablero, jugadores.

 @param nom_fichero (Ref: tabla[] de carácter) Nombre del fichero binario en el que se guardará el juego.
 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Tablero con la situación del juego.
 @param dim entero (Valor: entero) Dimensión real con la que se jugaba.
 @param jugadores (Ref: tabla[] de jugador_t) Tabla con la información de cada uno de los jugadores.
 @param turno (Valor: entero) Información de que jugador tiene el turno para comenzar a jugar.
 @return (boolano) Devuelve cierto si el juego se ha guardado correctamente y falso en caso contrario.
 */
bool ot_guarda_juego (char nom_fichero[], char tablero[][MCOLS_MAX], int dim, jugador_t jugadores[], int turno);

/**
 Recupera toda la información de un juego guardado en un fichero binario. Puede ocurrir que el fichero esté vacío. La información se guarda en el fichero en el siguiente orden: dimensión, turno, tablero, jugadores.

 @param nom_fichero (Ref: tabla[] de carácter) Nombre del fichero binario en el que está guardado el juego.
 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Tablero con la situación del juego.
 @param dim (Ref: entero) Dimensión real con la que se jugaba.
 @param jugadores (Ref: tabla[] de jugador_t) Tabla con la información de cada uno de los jugadores.
 @param turno (Ref: entero) Información de que jugador tiene el turno para comenzar a jugar.
 @return (booleano) Devuelve cierto si se ha recuperado el juego correctamente o falso en caso contrario.
 */
bool ot_recupera_juego (char nom_fichero[], char tablero[][MCOLS_MAX], int *dim, jugador_t jugadores[], int *turno);

/**
 Ordena una tabla de records. Se ordenarán por puntuación, de mayor a menor. En caso de puntuaciones iguales, se ordenará por fecha, de más reciente a más antigua.

 @param records (Ref: tabla[] de record_t) Tabla que contiene los records a ordenar.
 @param dim (Valor: entero) Dimensión de la tabla, número de récords que contiene la tabla.
 */
void ot_ordena_records (record_t records[], int dim);

/** @} */

/** @addtogroup S14 Sesión 14
 * @{
 */

/**
 * Decide la casilla dónde colocar la ficha del jugador de forma automática.

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Es el tablero del juego.
 @param dim (Valor: entero) Dimensión con la que se está jugando.
 @param f (Ref: entero) Es la fila de la matriz dónde se colocará la ficha.
 @param c (Ref: entero) Es la columna de la matriz dónde se colocará la ficha.
 @param jugador (Ref: jugador_t) Es la información de jugador.
 @return (booleano) Devuelve cierto si existe una casilla válida para jugar o falso en caso contrario.
 */
bool ot_decide_casilla_auto (char tablero[][MCOLS_MAX], int dim, int *f, int *c, jugador_t *jugador);

/**
 Permite al jugador decidir la casilla en la que desea colocar la ficha. Antes de retornar, comprueba que la casilla es una casilla válida.

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Es el tablero del juego.
 @param dim (Valor: entero) Dimensión con la que se está jugando.
 @param f (Ref: entero) Es la fila de la matriz dónde se colocará la ficha.
 @param c (Ref: entero) Es la columna de la matriz dónde se colocará la ficha.
 @param jugador (Ref: jugador_t) Es la información de jugador.
 @return (booleano) Devuelve cierto si existe una casilla válida para jugar o falso en caso contrario.
 */
bool ot_decide_casilla_manual (char tablero[][MCOLS_MAX], int dim, int *f, int *c, jugador_t *jugador);

/**
 Inicializa todos los elementos necesarios para poder jugar al Othello:
 - dimensión de los tableros,
 - determinar de forma aleatoria que jugador tiene el turno, es decir, que jugador juega con las negras.
 - leer los datos de los jugadores,
 - inicializar el tablero de juego

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Tablero de juego que se inicializará con la posición inicial del juego.
 @param dim (Ref: entero) Dimensión real con la que se jugará. Si es erróneo, por defecto será de 8x8.
 @param jugadores (Ref: tabla[] de jugador_t) Tabla con la información de cada uno de los jugadores.
 @param turno (Ref: entero) Información de qué jugador tiene el turno para comenzar a jugar.
 */
void ot_crea_juego(char tablero[][MCOLS_MAX], int *dim, jugador_t jugadores[], int *turno);

/**
 Procedimiento principal del juego. Es el que determina la dinámica del juego: cada jugador elije su jugada y pasa el turno al siguiente.
 El juego termina cuando no quedan casillas o cuando ninguno de los jugadores tiene una jugada posible. Cuando acaba, se guarda el récord del ganador en el fichero.

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Es el tablero del juego.
 @param dim (Valor: entero) Dimensión con la que se está jugando.
 @param jugadores (Ref: tabla[] de jugador_t) Es la información de los jugadores.
 @param turno (Ref: entero) Indica el jugador que tiene el turno de juego.
 @return (booleano) Devuelve cierto si el juego ha acabado y falso en caso contrario.
 */
bool ot_juega (char tablero[][MCOLS_MAX], int dim, jugador_t jugadores[], int *turno);

/** @} */

/** @addtogroup SNE Procedimientos no evaluables.
 * @{
 */

/**
 Imprime por pantalla la información de un récord siguiendo el siguiente formato:
 dd-mmm-aa  Color   Puntuación  Nombre
 Separados por tabulación y con salto de ĺínea al final.
 
 @param record (Ref: record_t) Registro con toda la información del récord.
 */
void ot_escribe_record(record_t *record);

/**
 Imprime un número determinado de los récords guardados en la tabla.
 
 @param records (Ref: tabla[] de record_t) Tabla con los records, ordenados o no.
 @param num_records (Valor: entero) Número máximo de registros a imprimir.
 */
void ot_escribe_records(record_t records[], int num_records);

/**
 Guarda la puntuación, nombre y color de las fichas del jugador ganador en el fichero de texto.
 También guarda la fecha actual.
 La información en el fichero sigue el siguiente formato:
 
 puntuación\tnombre\tcolor_fichas\tdd-mm-aa\n
 
 @param nom_fichero (Ref: tabla[] de caractér) Nombre del fichero que contiene todos los récords de los juegos.
 @param nombre (Ref: tabla[] de carácter) Nombre del jugador.
 @param puntuacion (Valor: entero) Puntuación conseguida por el jugador, es decir, número de fichas de su color al final de la partida.
 @param color (Valor: carácter) Color de las fichas con las que jugaba.
 @return (booleano) Devuelve cierto si el récord se ha podido añadir al fichero y falso en caso contrario.
 */
bool ot_guarda_record (char nom_fichero[], char nombre[], int puntuacion, char color);

/**
 Recupera del fichero los records (ordenados o no),
 indicando el número de récords reales que se ha recuperado del fichero.
 Muestra un mensaje de error si el fichero no existe y devuelve -1.
 ERROR: FICHERO NO EXISTE
 
 @param nom_fichero (Ref: tabla[] de carácter) Nombre del fichero que contiene los récords.
 @param records (Ref: tabla[] de record_t) Tabla donde es guardan los récords.
 @param dim (Valor: entero) Dimensión máxima de la tabla de récords. (>0)
 @return (entero) Devuelve el número de récords guardados en la tabla
 o -1 si se ha producido un error.
 */
int ot_recupera_records (char nom_fichero[], record_t records[], int dim);

/** @} */

#endif /* othello_h */
