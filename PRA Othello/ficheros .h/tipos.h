/**
 *  @file          tipos.h
 *  @brief         Definiciones de constantes y nuevos tipos para
 *                  jugar al Othello.
 *  @author        montse.garcia@urv.cat
 *  @version       1.0
 *  @date          27/6/19
 */

#ifndef tipos_h
#define tipos_h

/********* CONSTANTES *******/
/*
 @def T_LIMPIA_PANTALLA
 Definimos el comando segun el SO
 */
#ifdef __WIN__
#define T_LIMPIA_PANTALLA "cls"
#else
#define T_LIMPIA_PANTALLA "clear"
#endif

/**
 @def NFILAS_MAX
 Numero máximo de filas de las matrices.
 */
#define NFILAS_MAX     10
/**
 @def MCOLS_MAX
 Numero máximo de columnas de las matrices.
 */
#define MCOLS_MAX      10
/**
 @def MCOLS_MIN
 Numero máximo de columnas de las matrices.
 */
#define MCOLS_MIN      8
/**
 @def DIM_MIN
 Dimensión mínima de los tableros de juego.
 */
#define DIM_MIN			MCOLS_MIN
/**
 @def DIM_MAX
 Dimensión máxima de los tableros de juego.
 */
#define DIM_MAX			MCOLS_MAX
/**
 @def CADENA_MAX
 Tamaño máximo de las cadenas, incluyendo el centinela.
 */
#define CADENA_MAX		50
/**
 @def FICH_RECORDS
 Nombre del fichero que guarda los records del juego.
 */
#define FICH_RECORDS	"records.txt"
/**
 @def FICH_JUEGO
 Nombre del fichero que guarda el juego.
 */
#define FICH_JUEGO		"juego.dat"
/**
 @def ORIENTA_MAX
 Número máximo de orientaciones que podemos registrar en una tabla.
 */
#define ORIENTA_MAX		10
/**
 @def JUGADORES_MAX
 Número máximo de jugadores.
 */
#define JUGADORES_MAX	2

/**
 @def LS_DIM_MAX
 Tamaño máximo de la lista de coordenadas.
 */
#ifndef NFILAS_MAX
#define LS_DIM_MAX 100
#else
#define LS_DIM_MAX NFILAS_MAX * MCOLS_MAX
#endif

/**
 * @enun fichas_t.
 * Constantes de los símbolos para representar las fichas en el tablero.
 */
typedef enum
{
    FICHA_BLANCA = 'O',
    FICHA_NEGRA = '@',
    FICHA_VACIA = ' '
} fichas_t;

/**
 * @enun orientacion_t.
 * Constantes para definir las orientaciones.
 */
typedef enum
{
	NOROESTE=0, NORTE, NORESTE,
	OESTE, CENTRO, ESTE,
	SUROESTE, SUR, SURESTE
} orientacion_t;

/**
 * @enun relacion.
 * Determina la relación entre dos fechas: MENOR (-1), IGUALES (0), MAYOR (1).
 */
enum relacion {
	MENOR = -1,
	IGUALES,
	MAYOR
};

/**
 * @enun errores_t.
 * Posibles errores detectados en los diversos procedimientos.
 */
typedef enum
{
	ERROR_NUM_RECORDS = -1,
	ERROR_FICHERO_NO_EXISTE = -2
} errores_t;

/********* TIPOS DE DATOS ESTRUCTURADOS *******/

/**
 * @struct fecha_t
 * Información de una fecha
 */
typedef struct
{
	int dia, mes, anyo;
} fecha_t;

/**
 * @struct coord_t
 * Una coordenada.
 */
typedef struct
{
	/** La fila (y) */
	int fila;
	/** La columna (x) */
	int col;
} coord_t;

/**
 * @struct jugador_t
 * Información referente a un jugador: nombre, posibles jugadas, color...
 */
typedef struct
{
	char nombre[CADENA_MAX];
	char color;
	bool maquina;
	coord_t ultima_tirada;
	int puntuacion;
} jugador_t;

/**
 * @struct record_t
 * Información referente a un récord: nombre, fecha, color y puntuación.
 */
typedef struct
{
	char nombre[CADENA_MAX];
	fecha_t fecha;
	int puntos;
	char color;
} record_t;

#endif /* tipos_h */
