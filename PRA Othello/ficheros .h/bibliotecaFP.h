/**
 *  @file          bibliotecaFP.h
 *  @brief         Procedimientos generales para la asignatura de FP.
 *  @author        montse.garcia@urv.cat
 *  @version       1.0
 *  @date          27/6/19
 */

#ifndef bibliotecaFP_h
#define bibliotecaFP_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "tipos.h"
#include "generales.h"
#include "tablas.h"
#include "othello.h"

/***********************************************************
 * Generales
 ************************************************************/

/**
 Determina el jugador que tendrá el turno siguiente.

 @param jugador (Valor: entero) Identificador del jugador que tiene el turno actualmente.
 @param num_jugadores (Valor: entero) Número total de jugadores del juego. Si el valor es inferior o igual a uno, no cambia el turno.
 @return (entero) Devuelve el identificador del siguiente jugador.
 */
int fp_siguiente_jugador(int jugador, int num_jugadores);

/**
 Determina un número aleatorio acotado [min..max]. Los valores mínimo y máximo pueden no estar ordenados.

 @param min (Valor: entero) Valor mínimo que puede tomar el número aleatorio.
 @param max (Valor: entero) Valor máximo que puede tomar el aleatorio.
 @return (entero) Devuelve un aleatorio perteneciente a [min..max].
 */
int fp_entero_aleatorio_acotado (int min, int max);

/**
 Determina un carácter aleatorio acotado [inf..sup]. Los valores inferiores y superiores se determinan según el código ascii correspondiente. Pueden no estar ordenados.

 @param inf (Valor: carácter) Carácter inferior que limita los carácteres válidos.
 @param sup (Valor: carácter) Carácter superior que limita los carácteres válidos.
 @return (carácter) Devuelve un aleatorio perteneciente a [inf..sup].
 */
char fp_caracter_aleatorio_acotado (char inf, char sup);

/**
 Determina un número aleatorio acotado [min..max]. Los valores mínimo y máximo pueden no estar ordenados.

 @param texto (Ref: taula[] de carácter) Texto que se muestra al usuario.
 @param min (Valor: entero) Valor mínimo que puede tomar el número aleatorio.
 @param max (Valor: entero) Valor máximo que puede tomar el aleatorio.
 @return (entero) Devuelve un aleatorio perteneciente a [min..max].
 */
int fp_lee_entero_acotado (char texto[], int min, int max);

/**
 Lee un caracter acotado entre [min..max]. Comprueba que min >= max

 @param texto (Ref: taula[] de carácter) Texto informativo sobre el valor a leer.
 @param min (Valor: caràcter) Valor mínimo.
 @param max (Valor: caràcter) Valor máximo.
 @return (caràcter) Devuelve un valor entero entre [min..max].
 */
char fp_lee_caracter_acotado (char texto[], char min, char max);

/** Devuelve la fecha actual.

 @param hoy (Ref: fecha_t) Fecha actual del sistema.
 */
void fp_fecha_hoy (fecha_t *hoy);

/**
 Muestra por pantalla la fecha formateada: dd-mmm-aaaa

 @param fecha (Ref: fecha_t) Fecha a escribir por pantalla.
 */
void fp_escribe_fecha (fecha_t *fecha);

/**
 Compara dos fechas, f1 y f2, y devuelve cierto si son iguales.

 @param f1 (Ref: fecha_t) Primera fecha a evaluar.
 @param f2 (Ref: fecha_t) Segunda fecha a evaluar.
 @return (enter) Devuelve cierto si las fechas son iguales y
 falso en caso contrario.
 */
bool fp_fechas_iguales (fecha_t *f1, fecha_t *f2);

/**
 Compara dos fechas, f1 y f2, y devuelve un valor entero según la relación existente entre ellas:
 1 - f1 > f2  La primera fecha es más reciente que la segunda.
 0 - f1 = f2  Ambas fechas son iguales.
 -1 - f1 < f2  La segunda fecha es más antigua que la segunda.

 @param f1 (Ref: fecha_t) Primera fecha a evaluar.
 @param f2 (Ref: fecha_t) Segunda fecha a evaluar.
 @return (enter) Devuelve un valor según la relación existente entre las fechas:
 - 1 si f1 es más reciente que f2.
 - 0 si ambas son iguales.
 - -1 si f1 es más antigua que f2.
 */
int fp_compara_fechas (fecha_t *f1, fecha_t *f2);

/***********************************************************
 * Tablas, matrices y cadenas
 ************************************************************/

/**
 Devuelve cierto si el carácter se encuentra en la cadena.

 @param caracter (Valor: caràcter) Caracter a buscar.
 @param cadena char (Ref: taula[] de caràcter) Cadena que contiene los caracteres donde se busca.
 @return (booleà) Devuelve cierto si el carácter se encuentra en la cadena y falso en caso contrario.
 */
bool fp_pertenece_cadena(char caracter, char cadena[]);

/**
 Lee un carácter de teclado. Valida que el carácter pertenezca a una determinada cadena.
 Después de ejecutar este procedimiento, el buffer queda vacío.

 @param cadena (Ref: taula[] de caràcter) Cadena que contiene los caracteres que el usuario puede elegir.
 @param texto (Ref: taula[] de caràcter) Texto que se muestra al usuario.
 @return (caràcter) Devuelve el carácter tecleado por el usuario.
 */
char fp_lee_caracter_cadena (char cadena[], char texto[]);

/**
 Lee una cadena de teclado, eliminando el salto de línea.

 @param cadena (Ref: tabla[] de caràcter) Cadena que leeremos.
 @param dim (Valor: enter) Dimensión de la cadena. Tamaño máximo.
 @return (entero) Devuelve el tamaño de la cadena leída.
 */
int fp_lee_cadena (char cadena[], int dim);

/**
 Dada una orientacion, calcula el valor de los incrementos de fila y columna correspondientes.
 NO N NE
 O  C  E
 SO S SE

 @param orientacion (Valor: orientacion_t) Constante que indica una de las orientaciones.
 @param incf (Ref: enter) Incremento que se debe aplicar a las filas para seguir la orientación.
 @param incc (Ref: enter) Incremento que se debe aplicar a las columnas para seguir la orientación.
 */
void fp_tb_calcula_incrementos (orientacion_t orientacion, int *incf, int *incc);

/**
 Incializa toda la matriz con un determinado carácter que se pasa como parámetro.

 @param matriz (Ref: taula[][MCOLS_MAX] de carácter) Matriz que se inicializará.
 @param nfilas (Valor: enter) Número real de filas de la matriz.
 @param mcols (Valor: enter) Número real de columnas de la matriz (<= MCOLS_MAX)
 @param caracter (Valor: caràcter) Carácter con el que se va a inicializar toda la matriz.
 */
void fp_tb_inicializa_matriz (char matriz[][MCOLS_MAX], int nfilas, int mcols, char caracter);

/** Busca en una matriz un determinado carácter e
 *  indica la fila y la columna donde se encuentra.
 *
 * @param matriz (Ref: taula[][MCOLS_MAX] de caràcter) Matriz donde buscamos.
 * @param nfilas (Valor: enter) Número de filas de la matriz (nfilas > 0).
 * @param mcols (Valor: enter) Número de columans de la matriz (mcols > 0).
 * @param f (Ref: enter) Fila donde se ha encontrado el caracter buscado.
 * @param c (Ref: enter) Columna donde se ha encontrado el caracter buscado.
 * @param caracter (Valor: caràcter) Caracter que se está buscando.
 * @return (booleà) Retorna cierto si lo ha encontrado y falso en caso contrario.
 */
bool fp_tb_busca_matriz (
					  /* Parámetros de entrada */   	char matriz[][MCOLS_MAX],
					  int nfilas, int mcols,
					  /* Parámetros de salida */		int *f, int *c,
					  /* Parámetros de entrada */		char caracter);

/**
 Determinan si una fila y columna dada están dentro de los límites de una matriz [nfilas][mcols]

 @param f (Valor: entero) Número de la fila.
 @param c (Valor: entero) Número de la columna.
 @param nfilas (Valor: entero) Número máximo de filas de la matriz.
 @param mcols (Valor: entero) Número máximo de columnas de la matriz.
 @return (booleà) Devuelve cierto si la fila pertenece a [0..nfilas) y
 columna pertenece a [0..mcols) y falso en caso contrario.
 */
bool fp_tb_dentro_limites (int f, int c, int nfilas, int mcols);

/**
Busca un carácter en una matriz de nfilas x mcols, a partir de una determinada posicion (fila,col). La busqueda se realiza en una determinada orientacion.
No se evalua la casilla inicial (fila, col)
El procedimiento devuelve si existe o no. En caso de que existe, la casilla donde se encuentra el elemento se devuelve a partir de los mismos parametros de entrada fila y col.

@param matriz (Ref: tabla[][MCOLS_MAX] de carácter) Matriz de caracteres donde buscamos.
@param nfilas (Valor: entero) Número real de filas de la matriz (<= NFILAS_MAX).
@param mcols (Valor: entero) Número real de columnas de la matriz (<= MCOLS_MAX).
@param f (Ref: entero) Fila inicial y, fila en la que se encuentra.
@param c (Ref: entero) Columna inicial y, columna en la que se encuentra.
@param orientacion (Valor: enter) Orientación en la que se va a buscar.
@param caracter (Valor: char) Carácter que se desea buscar.
@return (booleà) Devuelve cierto si se ha encontrado el carácter y
falso en caso contrario.
*/
bool fp_tb_busca_orientacion(char matriz[][MCOLS_MAX], int nfilas, int mcols, int *f, int *c, int orientacion, char caracter);

/**
 A partir de una posición de la matriz (fila y columna determinadas), crea una tabla con todas las orientaciones en las que la casilla adyacente contiene el carácter que se pasa como parámetro.
 Devuelve el número de veces que se ha encontrado el carácter.
 La casilla del centro no se evalúa.
 0:NOROESTE, 1:NORTE, 2:NORESTE,
 3:OESTE, 4:CENTRO, 5:ESTE,
 6:SUROESTE, 7:SUR, 8:SURESTE

 @param matriz (Ref: tabla[][MCOLS_MAX] de carácter) Matriz de caracteres donde buscamos.
 @param nfilas (Valor: entero) Número real de filas de la matriz (<= NFILAS_MAX).
 @param mcols (Valor: entero) Número real de columnas de la matriz (<= MCOLS_MAX).
 @param fila (Valor: entero) Fila.
 @param col (Valor: entero) Columna.
 @param caracter (Valor: char) Carácter que se desea buscar.
 @param orientaciones (Ref: taula[] de enter) Orientación en la que se están volteando las fichas. Como máximo habrá 9 orientaciones.
 @return (enter) Número total de posibles orientaciones encontradas.
 */
int fp_tb_orientaciones (char matriz[][MCOLS_MAX], int nfilas, int mcols, int fila, int col, char caracter, int orientaciones[]);

/**
 Cuenta las veces que aparece un determinado caràcter dentro de una matriz de caracteres.

 @param matriz (Ref: taula[][MCOLS_MAX] de caràcter) Matriz dónde vamos a buscar.
 @param nfilas (Valor: enter) Número máximo de filas de la matriz.
 @param mcols (Valor: enter) Número máximo de columnas de la matriz (<= MCOLS_MAX)
 @param caracter (Valor: caràcter) Carácter que vamos buscar y contar.
 @return (enter) Devuelve el número de veces que se encuentra el carcacter en la matriz.
 */
int fp_tb_cuenta_en_matriz (char matriz[][MCOLS_MAX], int nfilas, int mcols, char caracter);

/***********************************************************
 * Othello
 ************************************************************/

/**
 Intercamba el color: si el color era negro, nos devuelve blanco y si era blanco, nos devuelve negro.

 @param color_ficha (Valor: caràcter) Color actual de la ficha.
 @return (caràcter) Devuelve el color contrario al recibido como parámetro.
 */
char fp_ot_cambia_color(char color_ficha);

/**
 Inicializa el tablero inicial para el juego del Othello.

 @param tablero (Ref: taula[][MCOLS_MAX] de caràcter) Tablero de juego, puede ser de 8x8, 9x9 o 10x10.
 @param dim (Valor: enter) Dimensión del tablero (8, 9 o 10).
 */
void fp_ot_tablero_inicial (char tablero[][MCOLS_MAX], int dim);

/**
 Permite dar valor inicial a los datos de un jugador:
 1. si es o no una máquina,
 2. nombre, si es humano,
 3. color asignado,
 4. puntuación = 2

 @param jugador (Ref: jugador_t) Información del jugador.
 @param color (Valor: carácter) Color asigando al jugador.
 */
void fp_ot_lee_jugador (jugador_t *jugador, char color);

/**
 Recupera la información de un jugador: nombre, puntuación...

 @param jugador (Ref: jugador_t) Registro con todos los datos del jugador.
 @param nombre (Ref: taula[] de caràcter) Cadena con el nombre del jugador.
 @param color (Ref: enter) Color con el que juega el jugador.
 @param maquina (Ref: booleà) Cierto si es tipo máquina y falso si es humano.
 @param fila (Ref: enter) Fila de la última tirada [1..dim]
 @param col (Ref: caracter) Columna de la última tirada ['A'..dim]
 @param puntuacion (Ref: enter) Puntuación del jugador.
 */
void fp_ot_obtener_datos_jugador (jugador_t *jugador, char nombre[], int *color, bool *maquina, int *fila, char *col, int *puntuacion);

/**
 Muestra por pantalla la información completa del juego: tableros, jugadores... También actualiza la puntuación de los jugadores.

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Tablero de juego.
 @param dim (Valor: entero) Dimensión del tablero con la que se ha creado el juego.
 @param jugadores (Ref: tabla[] de jugador_t) Información de los jugadores.
 @param turno (Valor: entero) Indica que jugador tiene el turno.
 */
void fp_ot_muestra_info_juego (char tablero[][MCOLS_MAX], int dim, jugador_t jugadores[], int turno);

/**
 Guarda toda la información de un juego en un fichero binario, para poder recuperalo posteriormente. La información se guarda en el fichero en el siguiente orden: dimensión, turno, tablero, jugadores.

 @param nom_fichero (Ref: tabla[] de carácter) Nombre del fichero binario en el que se guardará el juego.
 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Tablero con la situación del juego.
 @param dim entero (Valor: entero) Dimensión real con la que se jugaba.
 @param jugadores (Ref: tabla[] de jugador_t) Tabla con la información de cada uno de los jugadores.
 @param turno (Valor: entero) Información de que jugador tiene el turno para comenzar a jugar.
 @return (boolano) Devuelve cierto si el juego se ha guardado correctamente y falso en caso contrario.
 */
bool fp_ot_guarda_juego (char nom_fichero[], char tablero[][MCOLS_MAX], int dim, jugador_t jugadores[], int turno);

/**
 Recupera toda la información de un juego guardado en un fichero binario. Puede ocurrir que el fichero esté vacío. La información se guarda en el fichero en el siguiente orden: dimensión, turno, tablero, jugadores.

 @param nom_fichero (Ref: tabla[] de carácter) Nombre del fichero binario en el que está guardado el juego.
 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Tablero con la situación del juego.
 @param dim (Ref: entero) Dimensión real con la que se jugaba.
 @param jugadores (Ref: tabla[] de jugador_t) Tabla con la información de cada uno de los jugadores.
 @param turno (Ref: entero) Información de que jugador tiene el turno para comenzar a jugar.
 @return (booleano) Devuelve cierto si se ha recuperado el juego correctamente o falso en caso contrario.
 */
bool fp_ot_recupera_juego (char nom_fichero[], char tablero[][MCOLS_MAX], int *dim, jugador_t jugadores[], int *turno);

/**
 Ordena una tabla de records siguiendo el método de INSERCIÓN. Se ordenarán por puntuación, de mayor a menor. En caso de puntuaciones iguales, se ordenará por fecha, de más reciente a más antigua.

 @param records (Ref: tabla[] de record_t) Tabla que contiene los records a ordenar.
 @param dim (Valor: entero) Dimensión de la tabla, número de récords que contiene la tabla.
 */
void fp_ot_ordena_records (record_t records[], int dim);

/**
 * Decide la casilla dónde colocar la ficha del jugador de forma automática.

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Es el tablero del juego.
 @param dim (Valor: entero) Dimensión con la que se está jugando.
 @param f (Ref: entero) Es la fila de la matriz dónde se colocará la ficha.
 @param c (Ref: entero) Es la columna de la matriz dónde se colocará la ficha.
 @param jugador (Ref: jugador_t) Es la información de jugador.
 @return (booleano) Devuelve cierto si existe una casilla válida para jugar o falso en caso contrario.
 */
bool fp_ot_decide_casilla_auto (char tablero[][MCOLS_MAX], int dim, int *f, int *c, jugador_t *jugador);

/**
 Permite al jugador decidir la casilla en la que desea colocar la ficha. Antes de retornar, comprueba que la casilla es una casilla válida.

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Es el tablero del juego.
 @param dim (Valor: entero) Dimensión con la que se está jugando.
 @param f (Ref: entero) Es la fila de la matriz dónde se colocará la ficha.
 @param c (Ref: entero) Es la columna de la matriz dónde se colocará la ficha.
 @param jugador (Ref: jugador_t) Es la información de jugador.
 @return (booleano) Devuelve cierto si existe una casilla válida para jugar o falso en caso contrario.
 */
bool fp_ot_decide_casilla_manual (char tablero[][MCOLS_MAX], int dim, int *f, int *c, jugador_t *jugador);

/**
 Inicializa todos los elementos necesarios para poder jugar al Othello:
 - dimensión de los tableros,
 - inicializar el tablero de juego
 - determinar de forma aleatoria que jugador tiene el turno, es decir, que jugador que juegará con las negras.
 - leer los datos de los jugadores,

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Tablero de juego que se inicializará con la posición inicial del juego.
 @param dim (Ref: entero) Dimensión real con la que se jugará. Si es erróneo, por defecto será de 8x8.
 @param jugadores (Ref: tabla de jugador_t) Tabla con la información de cada uno de los jugadores.
 @param turno (Ref: entero) Información de qué jugador tiene el turno para comenzar a jugar.
 */
void fp_ot_crea_juego(char tablero[][MCOLS_MAX], int *dim, jugador_t jugadores[], int *turno);

/**
 Procedimiento principal del juego. Es el que determina la dinámica del juego: cada jugador elije su jugada y pasa el turno al siguiente.
 El juego termina cuando no quedan casillas o cuando ninguno de los jugadores tiene una jugada posible. Cuando acaba, se guarda el récord del ganador en el fichero.

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Es el tablero del juego.
 @param dim (Valor: entero) Dimensión con la que se está jugando.
 @param jugadores (Ref: tabla[] de jugador_t) Es la información de los jugadores.
 @param turno (Ref: entero) Indica el jugador que tiene el turno de juego.
 @return (booleano) Devuelve cierto si el juego ha acabado y falso en caso contrario.
 */
bool fp_ot_juega (char tablero[][MCOLS_MAX], int dim, jugador_t jugadores[], int *turno);

/***********************************************************
 * Othello: procedimientos adicionales
 ************************************************************/

/**
 Muestra las opciones del juego, ocultando aquellas que no se pueden elegir.
 Devuelve la opción elegida.
 Opcional: Controlar que la opción sea válida o no.

 @param creado (Valor: booleano) Indica si existe un juego creado o no.
 @return (carácter) Devuelve la opción elegida.
 */
char fp_ot_menu(bool creado);

/**
 Imprime por pantalla la información de un récord siguiendo el siguiente formato:
 dd-mmm-aa  Color   Puntuación  Nombre
 Separados por tabulación y con salto de ĺínea al final.

 @param record (Ref: record_t) Registro con toda la información del récord.
 */
void fp_ot_escribe_record(record_t *record);

/**
 Imprime un número determinado de los récords guardados en la tabla.

 @param records (Ref: tabla[] de record_t) Tabla con los records, ordenados o no.
 @param num_records (Valor: entero) Número máximo de registros a imprimir.
*/
void fp_ot_escribe_records(record_t records[], int num_records);

/**
 Guarda la puntuación, nombre y color de las fichas del jugador ganador en el fichero de texto.
 También guarda la fecha actual.
 La información en el fichero sigue el siguiente formato:

 puntuación\\tnombre\\tcolor_fichas\\tdd-mm-aa\n

 @param nom_fichero (Ref: tabla[] de caractér) Nombre del fichero que contiene todos los récords de los juegos.
 @param nombre (Ref: tabla[] de carácter) Nombre del jugador.
 @param puntuacion (Valor: entero) Puntuación conseguida por el jugador, es decir, número de fichas de su color al final de la partida.
 @param color (Valor: carácter) Color de las fichas con las que jugaba.
 @return (booleano) Devuelve cierto si el récord se ha podido añadir al fichero y falso en caso contrario.
 */
bool fp_ot_guarda_record (char nom_fichero[], char nombre[], int puntuacion, char color);

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
int fp_ot_recupera_records (char nom_fichero[], record_t records[], int dim);

/**
 Muestra por pantalla la información básica de un jugador: nombre, puntuación...

 @param jugador (Ref: jugador_t) Información del jugador.
 */
void fp_ot_escribe_jugador (jugador_t *jugador);

/**
 Crea una lista con todas las casillas que son válidas para colocar una ficha de un color determinado.

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Tablero de juego.
 @param dim (Valor: entero) Dimensión real con la que se juega (>0).
 @param color (Valor: entero) Color de la ficha que se desea colocar.
 @param casillas (Ref: tabla[] de coord_t) Tabla con todas las casillas válidas para jugar.
 @return (entero) Devuelve el número de casillas válidas para jugar.
 */
int fp_ot_lista_posibles (char tablero[][MCOLS_MAX], int dim, char color, coord_t casillas[]);

/**
 Pone una ficha en el tablero y actualiza el resto de las fichas, volteando las que correspondan.
 No comprueba si la casilla es válida o no, únicamente que es una posible jugada.

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Tablero de juego.
 @param dim (Valor: entero) Dimensión real con la que se juega.
 @param f (Valor: entero) Fila del tablero en la que se va a colocar la ficha.
 @param c (Valor: entero) Columna del tablero en la que se va a colocar la ficha.
 @param ficha (Valor: carácter) Ficha que se va a colocar: FICHA_BLANCA o FICHA_NEGRA.
 @return (entero) Devuelve el número de fichas que han cambiado al color actual, incluyendo la que se acaba de poner.
 */
int fp_ot_pon_ficha (char tablero[][MCOLS_MAX], int dim, int f, int c, char ficha);

/***********************************************************
 * Coordenadas
 ************************************************************/

/**
 Lee las componentes de una coordenada de teclado.
 Después de leer el buffe debe quedar vacío.

 @param coord (Ref: coord_t) Guarda la coordenada leída por teclado.
 @param coord_ini (Ref: coord_t) Valores inferiores que puede tomar la coordenada.
 @param coord_fi (Ref: coord_t) Valores superiores que pueden tomar la coordenada. Siempre superiores a coord_min.
 */
void fp_lee_coordenada_acotada (coord_t *coord, coord_t *coord_ini, coord_t *coord_fi);

/**
 Convierte una combinación de fila (entero) y columna (carácter) a una coordenada.
 Fila [1..8/10] -> coord.fila [0..7/9]
 Columna ['A'..'H'/'J'] -> coord.col [0..7/9]

 @param f (Valor: entero) Fila de la casilla. Va de 1 a 8 o 10, según la dimensión del tablero.
 @param c (Valor: carácter) Columna de la casilla. Va de 'A' a 'H' o 'J', según la dimensión del tablero.
 @param coord (Ref: coord_t) fila y columna de la casilla en formato coordenada.
 */
void fp_convertir_a_coord (int f, char c, coord_t *coord);

/**
 Busca una coordenada en una lista de coordenadas.

 @param coordenadas (Ref: tabla[] de coord_t) Fila de la casilla. Va de 1 a 8 o 10, según la dimensión del tablero.
 @param dim (Valor: enter) Dimensión de la tabla de coordenadas (>=0).
 @param coord (Ref: coord_t) Coordenada a buscar.
 @return (booleano) Devuelve cierto si encuentra la coordenada en la tabla y falso en caso contrario.
 */
bool fp_busca_coordenada (coord_t coordenadas[], int dim, coord_t *coord);

#endif /* bibliotecaFP_h */
