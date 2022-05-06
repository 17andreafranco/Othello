/**
 *  @file      tests_othello.c
 *  @brief     Tests unitarios para probar los procedimientos de la práctica Othello
 *	@authors   nom.cognom@estudiants.urv.cat
 *  @version   1.0
 *  @date      6/6/19
 */

#include "unit_test_ansi_C.h"
#include "generales.h"
#include "tablas.h"
#include "othello.h"

/**
 Procedimientos y variables auxiliares para las pruebas.
 */
int general_ok, general_num_tests;


/**
 @test Test del procedimiento siguiente_jugador()
 | Descripción    | Entradas             || Salidas Esperada|OK?|
 |-------------   |:-------:|:-----------:|:---------------:|---|
 |                | jugador |num_jugadores| j. siguiente    |   |
 | Prueba humo    | 1       | 3           | 2               |   |
 | Da la vuelta   | 1       | 2           | 0               |   |
*/
void test_siguiente_jugador (void)
{
    /* Declaración de variables locales */
    char name[] = "siguiente_jugador";
    int resultado;

    /* Inicialización variables */
    general_ok = 0;
    general_num_tests = 0;

    report_error("Test Suite:");
    report_error(name);

    /* Prueba 1: Prueba de humo */
    resultado = siguiente_jugador(1, 3);
    if (assert_int_equal(resultado, 2, "Test 1: Prueba de humo"))
    {
        general_ok++;
    }
    general_num_tests++;

    /* Prueba 2:  */




    report_results(name,general_num_tests,general_ok);
}

/**
 @test Test del procedimiento entero_aleatorio_acotado()
 | Descripción              | Entradas             || Salidas Esperada|OK?|
 |-------------             |:-------:|:-----------:|:---------------:|---|
 |                          | min     | max         | aleatorio       |   |
 | Prueba humo (x10)        | 1       | 3           | [1..3]          |   |

 */
void test_entero_aleatorio_acotado (void)
{
    /* Declaración de variables locales */
    char name[] = "entero_aleatorio_acotado";
    int i, resultado;

    /* Inicialización variables */
    general_ok = 0;
    general_num_tests = 0;

    /* Semilla fija para repetir las pruebas */
    srand(1);

    report_error("Test Suite:");
    report_error(name);

    /* Prueba 1: Prueba de humo */
    for (i=0; i<10; i++)
    {
        resultado = entero_aleatorio_acotado(1, 3);
        if (assert_int_less(0, resultado, "Test 1: Prueba de humo mayor") && assert_int_less(resultado, 4, "Test 1: Prueba de humo menor"))
        {
            general_ok++;
        }
        general_num_tests++;
    }

    /* Prueba 2: ____________________ */




    report_results(name,general_num_tests,general_ok);
}

/**
 @test Test del procedimiento caracter_aleatorio_acotado()
 | Descripción              | Entradas             || Salidas Esperada|OK?|
 |-------------             |:-------:|:-----------:|:---------------:|---|
 |                          | min     | max         | aleatorio       |   |
 | Prueba humo (x10)        | 'b'     | 'd'         | ['b'..'d']      |   |
 */
void test_caracter_aleatorio_acotado (void)
{
    /* Declaración de variables locales */
    char name[] = "entero_aleatorio_acotado";
    int i, resultado;

    /* Inicialización variables */
    general_ok = 0;
    general_num_tests = 0;

    report_error("Test Suite:");
    report_error(name);

    /* Prueba 1: Prueba de humo */
    for (i=0; i<10; i++)
    {
        resultado = caracter_aleatorio_acotado('b', 'd');
        if (assert_int_less('a', resultado,  "Test 1: Prueba de humo mayor") && assert_int_less(resultado, 'e', "Test 1: Prueba de humo menor"))
        {
            general_ok++;
        }
        general_num_tests++;
    }

    /* Prueba 2: ___________________ */




    report_results(name,general_num_tests,general_ok);
}

/**
 @test Test del tb_dentro_limites()
 | Descripción  | Entradas       |||| Salidas Esperada|OK?|
 |------------- |:--:|:--:|:--:|:--:|:---------------:|---|
 |                | f |c |nfilas| mcols |    resultado  |   |
 | Prueba humo    | 1 |2 | 10   | 10    |     cierto    |   |
 */
void test_tb_dentro_limites (void)
{
    /* Declaración de variables locales */
    char name[] = "siguiente_jugador";
    bool resultado;

    /* Inicialización variables */
    general_ok = 0;
    general_num_tests = 0;

    report_error("Test Suite:");
    report_error(name);

    /* Prueba 1: Prueba de humo */
    resultado = tb_dentro_limites(1, 2, 10, 10);
    if (assert_true(resultado, "Test 1: Prueba de humo"))
    {
        general_ok++;
    }
    general_num_tests++;

    /* Prueba 2: _____________ */



    report_results(name,general_num_tests,general_ok);
}

/**
 @test Test del procedimiento ot_cambia_color()
 | Descripción    | Entradas     | Salidas Esperada|OK?|
 |-------------   |:-------     :|:---------------:|---|
 |                | color_ficha | resultado    |   |
 | Prueba humo    | FICHA_BLANCA | FICHA_NEGRA  |   |
 | Ficha negra    | FICHA_NEGRA | FICHA_BLANCA  |   |
 | Error          | 'x'       | FICHA_VACIA              |   |

 */
void test_ot_cambia_color (void)
{
    /* Declaración de variables locales */
    char name[] = "ot_cambia_color";
    char resultado;

    /* Inicialización variables */
    general_ok = 0;
    general_num_tests = 0;

    report_error("Test Suite:");
    report_error(name);

    /* Prueba 1: Prueba de humo */
    resultado = ot_cambia_color(FICHA_BLANCA);
    if (assert_char_equal(resultado, FICHA_NEGRA, "Test 1: Prueba de humo"))
    {
        general_ok++;
    }
    general_num_tests++;

    /* Prueba 2: ____________________ */

    report_results(name,general_num_tests,general_ok);
}


/**
 Test_runner para los procedimientos de la práctica.

 @return (real) Porcentaje de pruebas superadas.
 */
float test_runner_othello (void)
{
    float ok, num_tests, correctos;
    char resultado[50];

    ok = 0;
    num_tests = 0;

    /* Test siguiente_jugador() */
    test_siguiente_jugador();
    ok +=general_ok;
    num_tests +=general_num_tests;

    /* Test entero_aleatorio_acotado() */
    test_entero_aleatorio_acotado();
    ok +=general_ok;
    num_tests +=general_num_tests;

    /* Test caracter_aleatorio_acotado() */
    test_caracter_aleatorio_acotado();
    ok +=general_ok;
    num_tests +=general_num_tests;

    /* Test tb_dentro_limites() */
    test_tb_dentro_limites();
    ok +=general_ok;
    num_tests +=general_num_tests;

    /* Test ot_cambia_color() */
    test_ot_cambia_color();
    ok +=general_ok;
    num_tests +=general_num_tests;

    /* Resumen */
    correctos = 100*ok/num_tests;
    sprintf (resultado, "\nCorrectos = %0.2f%c\n", correctos, '%');
    report_stdout(resultado);

    return correctos;
}

