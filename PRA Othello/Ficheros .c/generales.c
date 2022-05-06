/**
 *  @file 		generales.c
 *  @brief   	Procedimientos de uso general.
 *  @authors 	paula.segala@estudiants.urv.cat
 *				andrea.francoj@estudiants.urv.cat
 *  @version 	1.0
 *  @date     	27/6/19
 */

#include "generales.h"

/**
 Elimina los caracteres del buffer de teclado.
 */
void vacia_buffer_teclado(void)
{
    char ch;
    while (((ch = getchar()) != EOF) && (ch != '\n'));
}

/**
 Pausa la ejecución y espera que el usuario pulse la tecla de return/enter.
 */
void pausa(void)
{
    printf("\nPulsa \"Enter\" para continuar! ");
    vacia_buffer_teclado();
}

/** @addtogroup S11 Sesión 11
 * @{
 */

/**
 Determina el jugador que tendrá el turno siguiente.

 @param jugador (Valor: entero) Identificador del jugador que tiene el turno actualmente.
 @param num_jugadores (Valor: entero) Número total de jugadores del juego. Si el valor es inferior o igual a uno, no cambia el turno.
 @return (entero) Devuelve el identificador del siguiente jugador.
 */
int siguiente_jugador(int jugador, int num_jugadores)
{
    int siguiente;

    /* Escribe la expresión correspondiente */
    if (num_jugadores == 1){
        siguiente = jugador;
    }
    else if(num_jugadores > (jugador+1)){
        siguiente = jugador + 1;
    }
    else{
        siguiente = num_jugadores - (jugador+1);
    }

    return siguiente;      /* Datos de salida */
}

/**
 Determina un número aleatorio acotado [min..max]. Los valores mínimo y máximo pueden no estar ordenados.

 @param min (Valor: entero) Valor mínimo que puede tomar el número aleatorio.
 @param max (Valor: entero) Valor máximo que puede tomar el aleatorio.
 @return (entero) Devuelve un aleatorio perteneciente a [min..max].
 */
int entero_aleatorio_acotado (int min, int max)
{
    /* Variables locales */
    int numero;
    int x;

    /* La semilla se ha generado en el principal!!!
    no llamar a srand()!
    */

    /* Código */
    x = max;
    if(max<min) {
        max = min;
        min = x;
    }
    numero = rand() % (max-min + 1) + min;

    return numero;        /* Dato devuelto */
}

/**
 Determina un carácter aleatorio acotado [inf..sup]. Los valores inferiores y superiores se determinan según el código ascii correspondiente. Pueden no estar ordenados.

 @param inf (Valor: carácter) Carácter inferior que limita los carácteres válidos.
 @param sup (Valor: carácter) Carácter superior que limita los carácteres válidos.
 @return (carácter) Devuelve un aleatorio perteneciente a [inf..sup].
*/

char caracter_aleatorio_acotado (char inf, char sup)
{
    /* Variables locales */
    char letra;
    char x;

    /* La semilla se ha generado en el principal!!!
    no llamar a srand()!
    */

    /* Código */
    x = sup;
     if(sup<inf) {
        sup = inf;
        inf = x;
     }
        letra = rand() % (sup-inf + 1) + inf;

    return (letra);        /* Dato devuelto */
}

/** @} */

/** @addtogroup S12 Sesión 12
 * @{
 */

/**
 Muestra por pantalla la fecha formateada: dd-mmm-aaaa

 @param fecha (Ref: fecha_t) Fecha a escribir por pantalla.
 */

void escribe_fecha (fecha_t *fecha)
{
    switch (fecha->mes){
        case 1: printf("%d-ene-%d", fecha->dia, fecha->anyo);
        break;
        case 2: printf("%d-feb-%d", fecha->dia, fecha->anyo);
        break;
        case 3: printf("%d-mar-%d", fecha->dia, fecha->anyo);
        break;
        case 4: printf("%d-abr-%d", fecha->dia, fecha->anyo);
        break;
        case 5: printf("%d-may-%d", fecha->dia, fecha->anyo);
        break;
        case 6: printf("%d-jun-%d", fecha->dia, fecha->anyo);
        break;
        case 7: printf("%d-jul-%d", fecha->dia, fecha->anyo);
        break;
        case 8: printf("%d-ago-%d", fecha->dia, fecha->anyo);
        break;
        case 9: printf("%d-sep-%d", fecha->dia, fecha->anyo);
        break;
        case 10: printf("%d-oct-%d", fecha->dia, fecha->anyo);
        break;
        case 11: printf("%d-nov-%d", fecha->dia, fecha->anyo);
        break;
        case 12: printf("%d-dic-%d", fecha->dia, fecha->anyo);
        break;

    }
}

/**
 Lee las componentes de una coordenada de teclado.
 Después de leer el buffe debe quedar vacío.

 @param coord (Ref: coord_t) Guarda la coordenada leída por teclado (fila, col).
 @param coord_ini (Ref: coord_t) Valores inferiores que puede tomar la coordenada.
 @param coord_fi (Ref: coord_t) Valores superiores que pueden tomar la coordenada. Siempre superiores a coord_min.
 */
void lee_coordenada_acotada (coord_t *coord, coord_t *coord_ini, coord_t *coord_fi)
{
    /* Reemplazalo con tu código */
	fp_lee_coordenada_acotada(coord, coord_ini, coord_fi);
}

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
bool fechas_iguales (fecha_t *f1, fecha_t *f2)
{
	bool iguales = false;

	if ((f1->dia == f2->dia) && (f1->mes == f2->mes) && (f1->anyo == f2->anyo)){
	    iguales = true;
	}
	return (iguales);
}

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
int compara_fechas (fecha_t *f1, fecha_t *f2)
{
    /* Definición de variables locales si las necesitas. */
	int resultado = 0;
	bool iguales = false;

    /* Código */
	iguales = fechas_iguales(f1, f2);

	if (iguales == true){
	    resultado=0;
	}
	else if ((f1->anyo)>(f2->anyo)) {
        resultado = 1;
	}
    else if ((f1->anyo)<(f2->anyo)) {
        resultado = -1;
    }
    else if ((f1->mes)>(f2->mes)) {
        resultado = 1;
    }
    else if ((f1->mes)<(f2->mes)){
        resultado = -1;
    }
    else if ((f1->dia)>(f2->dia)){
        resultado = 1;
    }
    else{
        resultado = -1;
    }
	return (resultado);
}

/** @} */
