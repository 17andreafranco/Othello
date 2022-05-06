/**
 *  @file  		main.c
 *  @brief     	Programa principal para probar y/o jugar al Othello.
 *  @authors 	paula.segala@estudiants.urv.cat
 *				andrea.francoj@estudiants.urv.cat
 *  @version   	1.0
 *  @date      	27/6/19
 *
 *  Actualizar los datos del autor, versión y fecha con vuestros datos específicos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "othello.h"
#include "generales.h"

/* COMENTAR SI NO TENÉIS LA LIBRERÍA */
float test_runner_othello (void);

/**
 Programa principal.
 Por defecto, siempre realiza, en primer lugar, el test de los procedimientos y, posteriormente, si todo ha sido correcto, ejecuta el menú principal.

 El programa admite un argumento (0/1), que permite ejecutar (1) u omitir (0) las pruebas de test.

 @return (int) Devuelve el control al Sistema Operativo sin error, si todo ha funcionado correctamente.
 */
int main(void)
{
    int op;
	float resultado;

	/* Inicializaciones generales */
	/* Semilla para generar números aleatorios diferentes en cada ejecución: ¡Una única vez en todo el proyecto! */

    /* Para ejecución real usar:
    srand((int)time(NULL));
    */

	/* Para probar usar, de esta forma, los aleatorios siempre serán los mismos.
    */
	srand(1);

    /* Menu */
    do{
        /* Pantalla de bienvenida */
        system(T_LIMPIA_PANTALLA);
        printf("\n0 - Salir\n1 - Tests\n2 - Jugar\n\nElige una opcion: ");
        scanf ("%d", &op);
        /* Después de leer, dejar siempre el buffer de teclado vacío */
        vacia_buffer_teclado();
        switch (op) {
            case 0:
                /* Salir del programa */
                printf("Adios!\n");
                pausa();
                break;
            case 1:
                /* Probar los procedimientos */
                resultado = test_runner_othello();
				printf("%.1f\n", resultado);
				pausa();
                break;
            case 2:
                /* Iniciar el juego */
                ot_inicio();
				printf ("Fin de juego!\n");
                pausa();
                break;
            default:
                printf("Opcion erronea!\n");
                pausa();
                break;
        }

    } while (op != 0);

    return 0;
}
