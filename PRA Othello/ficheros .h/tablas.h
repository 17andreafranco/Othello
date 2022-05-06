/**
 *  @file       tablas.h
 *  @brief      Procedimientos generales para trabajar con tablas, cadenas y matrices.
 *  @authors    nom.cognom@estudiants.urv.cat
 *              nom.cognom@estudiants.urv.cat
 *  @version    1.0
 *  @date       27/6/19
 */

#ifndef tablas_h
#define tablas_h

#include <stdio.h>
#include <stdbool.h>
#include "tipos.h"
#include "bibliotecaFP.h"

/** @addtogroup S11 Sesión 11
 * @{
 */

/**
 Determinan si una fila y columna dada están dentro de los límites de una matriz [nfilas][mcols]

 @param f (Valor: entero) Número de la fila.
 @param c (Valor: entero) Número de la columna.
 @param nfilas (Valor: entero) Número máximo de filas de la matriz.
 @param mcols (Valor: entero) Número máximo de columnas de la matriz.
 @return (booleà) Devuelve cierto si la fila pertenece a [0..nfilas) y
 columna pertenece a [0..mcols) y falso en caso contrario.
 */
bool tb_dentro_limites (int f, int c, int nfilas, int mcols);

/**
 Busca un carácter en una matriz de nfilas x mcols, a partir de una determinada posicion (fila,col). La busqueda se realiza en una determinada orientacion.
 No se evalua la casilla inicial (fila, col)
 El procedimiento devuelve si existe o no. En caso de que existe, la casilla donde se encuentra el elemento se devuelve a partir de los mismos parametros de entrada fila y col.

 @param matriz (Ref: tabla[][MCOLS_MAX] de carácter) Matriz de caracteres donde buscamos.
 @param nfilas (Valor: entero) Número real de filas de la matriz (<= NFILAS_MAX i > 0).
 @param mcols (Valor: entero) Número real de columnas de la matriz (<= MCOLS_MAX i > 0).
 @param f (Ref: entero) Fila inicial y, fila en la que se encuentra.
 @param c (Ref: entero) Columna inicial y, columna en la que se encuentra.
 @param orientacion (Valor: enter) Orientación en la que se va a buscar.
 @param car (Valor: char) Carácter que se desea buscar.
 @return (booleà) Devuelve cierto si se ha encontrado el carácter y
 falso en caso contrario.
 */
bool tb_busca_orientacion(char matriz[][MCOLS_MAX], int nfilas, int mcols, int *f, int *c, int orientacion, char car);

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
 @param f (Valor: entero) Fila.
 @param c (Valor: entero) Columna.
 @param caracter (Valor: char) Carácter que se desea buscar.
 @param orientaciones (Ref: taula[] de enter) Orientación en la que se están volteando las fichas. Como máximo habrá 9 orientaciones.
 @return (enter) Número total de posibles orientaciones encontradas.
 */
int tb_orientaciones (char matriz[][MCOLS_MAX], int nfilas, int mcols, int f, int c, char caracter, int orientaciones[]);

/** @} */

/** @addtogroup SNE Procedimientos no evaluables.
 * @{
 */

/**
 Devuelve cierto si el carácter se encuentra en la cadena.

 @param caracter (Valor: caràcter) Caracter a buscar.
 @param cadena char (Ref: taula[] de caràcter) Cadena que contiene los caracteres donde se busca.
 @return (booleà) Devuelve cierto si el carácter se encuentra en la cadena y falso en caso contrario.
 */
bool pertenece_cadena(char caracter, char cadena[]);

/**
 Lee un carácter de teclado. Valida que el carácter pertenezca a una determinada cadena.
 Después de ejecutar este procedimiento, el buffer queda vacío.

 @param cadena (Ref: taula[] de caràcter) Cadena que contiene los caracteres que el usuario puede elegir.
 @param texto (Ref: taula[] de caràcter) Texto que se muestra al usuario.
 @return (caràcter) Devuelve el carácter tecleado por el usuario.
 */
char lee_caracter_cadena (char cadena[], char texto[]);

/** Inicializa una matriz con un carácter.
 *
 * @param matriz (Ref: taula[][MCOLS_MAX] de caràcter) Matriz a inicializar.
 * @param nfilas (Valor: enter) Número de filas de la matriz (nfilas > 0).
 * @param mcols (Valor: enter) Número de columans de la matriz (mcols > 0).
 * @param caracter (Valor: caràcter) Caracter con el que se inicializa.
 */
void tb_inicializa_matriz (
						   /* Parámetros de salida */   char matriz[][MCOLS_MAX],
						   /* Parámetros de entrada */	 int nfilas, int mcols, char caracter);

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
bool tb_busca_matriz (
					  /* Parámetros de entrada */   	char matriz[][MCOLS_MAX],
					  int nfilas, int mcols,
					  /* Parámetros de salida */		int *f, int *c,
					  /* Parámetros de entrada */		char caracter);

/** Determina los incrementos de fila y columna para recorrer una matriz
 *  siguiendo la orientación indicada.
 *
 * @param orientacion (Valor: enter) Identificación de la orientación.
 * @param incf (Ref: enter) Incremento aplicable a las filas.
 * @param incc (Ref: enter) Incremento aplicable a las columnas.
 */
void tb_calcula_incrementos (
							 /* Parámetros de entrada */	int orientacion,
							 /* Parámetros de salida */		int *incf, int *incc);

/** @} */

#endif /* tablas_h */
