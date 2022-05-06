/**
 *  @file    	generales.h
 *  @brief   	Procedimientos generales.
 *  @authors	nom.cognom@estudiants.urv.cat
 *				nom.cognom@estudiants.urv.cat
 *  @version 	1.0
 *  @date      	27/6/19
 */

#ifndef generales_h
#define generales_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "bibliotecaFP.h"
#include "tipos.h"

/**
 Elimina los caracteres del buffer de teclado.
 */
void vacia_buffer_teclado(void);

/**
 Pausa la ejecución y espera que el usuario pulse la tecla de return/enter.
 */
void pausa(void);

/** @addtogroup S11 Sesión 11
 * @{
 */

/**
 Determina el jugador que tendrá el turno siguiente.

 @param jugador (Valor: entero) Identificador del jugador que tiene el turno actualmente.
 @param num_jugadores (Valor: entero) Número total de jugadores del juego. Si el valor es inferior o igual a uno, no cambia el turno.
 @return (entero) Devuelve el identificador del siguiente jugador.
 */
int siguiente_jugador(int jugador, int num_jugadores);

/**
 Determina un número aleatorio acotado [min..max]. Los valores mínimo y máximo pueden no estar ordenados.

 @param min (Valor: entero) Valor mínimo que puede tomar el número aleatorio.
 @param max (Valor: entero) Valor máximo que puede tomar el aleatorio.
 @return (entero) Devuelve un aleatorio perteneciente a [min..max].
 */
int entero_aleatorio_acotado (int min, int max);

/**
 Determina un carácter aleatorio acotado [inf..sup]. Los valores inferiores y superiores se determinan según el código ascii correspondiente. Pueden no estar ordenados.

 @param inf (Valor: carácter) Carácter inferior que limita los carácteres válidos.
 @param sup (Valor: carácter) Carácter superior que limita los carácteres válidos.
 @return (carácter) Devuelve un aleatorio perteneciente a [inf..sup].
 */
char caracter_aleatorio_acotado (char inf, char sup);

/** @} */

/** @addtogroup S12 Sesión 12
 * @{
 */

/**
 Muestra por pantalla la fecha formateada: dd-mmm-aaaa

 @param fecha (Ref: fecha_t) Fecha a escribir por pantalla.
 */
void escribe_fecha (fecha_t *fecha);

/**
 Lee las componentes de una coordenada de teclado.
 Después de leer el buffe debe quedar vacío.

 @param coord (Ref: coord_t) Guarda la coordenada leída por teclado.
 @param coord_min (Ref: coord_t) Valores inferiores que puede tomar la coordenada.
 @param coord_max (Ref: coord_t) Valores superiores que pueden tomar la coordenada. Siempre superiores a coord_min.
 */
void lee_coordenada_acotada (coord_t *coord, coord_t *coord_min, coord_t *coord_max);

/** @} */

/** @addtogroup SNE Procedimientos no evaluables.
 * @{
 */

/**
 Compara dos fechas, f1 y f2, y devuelve cierto si son iguales.

 @param f1 (Ref: fecha_t) Primera fecha a evaluar.
 @param f2 (Ref: fecha_t) Segunda fecha a evaluar.
 @return (enter) Devuelve cierto si las fechas son iguales y
 falso en caso contrario.
 */
bool fechas_iguales (fecha_t *f1, fecha_t *f2);

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
int compara_fechas (fecha_t *f1, fecha_t *f2);

/** @} */

#endif /* generales_h */
