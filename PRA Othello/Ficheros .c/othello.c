/**
 *  @file       othello.c
 *  @brief      Implementación de los procedimientos específicos para el juego del Othello.
 *  @authors    paula.segala@estudiants.urv.cat
 *			    andrea.francoj@estudiants.urv.cat
 *  @version    1.0
 *  @date       4/7/19
 *
 *  Actualizar los datos del autor, versión y fecha con vuestros datos personales.
 */

#include "othello.h"

/** @addtogroup S11 Sesión 11
 * @{
 */

/**
 Cambia el color de la ficha: si la ficha era de color era negro, nos devuelve el color blanco (FICHA_BLANCA) y si era blanco, nos devuelve negro (FICHA_NEGRA).
 Si el color no es correcto, nos devolverá la FICHA_VACIA.

 @param color_ficha (Valor: caràcter) Color actual de la ficha.
 @return (caràcter) Devuelve el color contrario al recibido como parámetro o FICHA_VACIA en caso de error.
 */
char ot_cambia_color(char color_ficha)
{
    /* Variables locales */
    char ficha;
    ficha = FICHA_VACIA;

    /* Codigo */
    if (color_ficha == FICHA_NEGRA){
        ficha = FICHA_BLANCA;
    }
     if (color_ficha == FICHA_BLANCA){
        ficha = FICHA_NEGRA;
    }

    return ficha;
}
/** @} */

/** @addtogroup S12 Sesión 12
 * @{
 */

/**
 Inicializa el tablero de juego inicial, colocando las primeras fichas en el lugar correcto.

 @param tablero (Ref: tabla de carácter) Tablero con la situación del juego.
 @param dim (Valor: entero) Dimensión real con la que se jugará.
 */
void ot_tablero_inicial (char tablero[][MCOLS_MAX], int dim)
{

	if (dim == 8) //Tablero dimension 8
	{
	    tb_inicializa_matriz (tablero, 8, 8, FICHA_VACIA);

	    tablero[3][3]=FICHA_BLANCA;
		tablero[3][4]=FICHA_NEGRA;
		tablero[4][3]=FICHA_NEGRA;
		tablero[4][4]=FICHA_BLANCA;
	}

	if (dim == 9) //Tablero dimension 9
	{
	    tb_inicializa_matriz (tablero, 9, 9, FICHA_VACIA);

	    tablero[3][3]=FICHA_BLANCA;
		tablero[3][4]=FICHA_NEGRA;
		tablero[4][3]=FICHA_NEGRA;
		tablero[4][4]=FICHA_BLANCA;
	}

	if (dim == 10) //Tablero dimension 10
	{
	    tb_inicializa_matriz (tablero, 10, 10, FICHA_VACIA);

	    tablero[4][4]=FICHA_BLANCA;
		tablero[4][5]=FICHA_NEGRA;
		tablero[5][4]=FICHA_NEGRA;
		tablero[5][5]=FICHA_BLANCA;
	}
}

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
void ot_lee_jugador (jugador_t *jugador, char color)
{
    //Variables
    char maquina;
    bool maquina_b;

    //Inicializacion de variables
    maquina = 'c';

    //Codigo

    while((maquina != 'H')&&(maquina != 'M')&&(maquina != 'h')&&(maquina != 'm')){
    printf("\nH (Humano) o M (Maquina)? ");
    scanf(" %c",&maquina);
    }

    if ((maquina == 'M')||(maquina == 'm')){
        maquina_b = true;

        if (color == FICHA_BLANCA){
            strcpy (jugador -> nombre, "Maquina_Blancas");
        }
        else {
            strcpy (jugador -> nombre, "Maquina_Negras");
        }
    }
    if ((maquina == 'H')||(maquina == 'h')){
        maquina_b = false;

        printf("Indica el nombre: ");
        vacia_buffer_teclado();
        fgets (jugador -> nombre, CADENA_MAX, stdin);
        strtok (jugador -> nombre, "\n");
    }

    //Guardar datos en registro

    jugador->color = color;
    jugador->maquina = maquina_b;
    jugador->puntuacion = 2;
    jugador->ultima_tirada.fila = -1;
    jugador->ultima_tirada.col = '-';

}

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
void ot_obtener_datos_jugador (jugador_t *jugador, char nombre[], int *color, bool *maquina, int *fila, char *col, int *puntuacion)
{
    // Variables
    int x;

    //Codigo
    strcpy(nombre, jugador->nombre);
    *color = jugador->color;
    *maquina = jugador->maquina;


    *fila = jugador->ultima_tirada.fila + 1;
    x = jugador->ultima_tirada.col + 1;
    switch(x){
        case 1: *col='A';
        break;
        case 2: *col='B';
        break;
        case 3: *col='C';
        break;
        case 4: *col='D';
        break;
        case 5: *col='E';
        break;
        case 6: *col='F';
        break;
        case 7: *col='G';
        break;
        case 8: *col='H';
        break;
    }
    *puntuacion = jugador->puntuacion;
}

/** @} */

/** @addtogroup S13 Sesión 13
 * @{
 */

 /**

 */

 /**
 Guarda y muestra al usuario los records

 @param jugadores (Valor: jugador_t) Registro con todos los datos del jugdor
 */

 void ot_muestra_record (jugador_t jugadores[DIM_MAX]){

  //Variables
     bool save;
     int num_record;
     record_t records[DIM_MAX];

    //Comprobar quien ha hecho más puntos

    if (jugadores[0].puntuacion > jugadores[1].puntuacion)
     {
        printf("Guardando record!\n");
        save = ot_guarda_record (FICH_RECORDS, jugadores[0].nombre, jugadores[0].puntuacion, jugadores[0].color);

     }

    else
    {
        printf("Guardando record!\n");
        save = ot_guarda_record (FICH_RECORDS, jugadores[1].nombre, jugadores[1].puntuacion, jugadores[1].color);
    }

    // Mostrar los records por pantalla
    num_record = ot_recupera_records (FICH_RECORDS, records, DIM_MAX);

    if (num_record > 0)
    {
        ot_ordena_records(records, num_record);
        ot_escribe_records(records, num_record);
    }
    else
    {
        printf ("No hay records guardados!\n");
    }

    if (save == false)
    {
        printf("No se ha podido guardar\n");
    }

 }
/**
 @param tablero (Ref: tabla de carácter) Tablero con la situación del juego.
 @param dim (Valor: entero) Dimensión real con la que se jugará.
 @param jugadores (Valor: jugador_t) Registro con todos los datos del jugdor
 @param turno (Valor: entero) Información de que jugador tiene el turno para comenzar a jugar.

 */

void ot_opcion_j (char tablero[][MCOLS_MAX], jugador_t jugadores[DIM_MAX], int dim,int turno)
{
    //Variables
    bool fin, save;
    char op;

    //Iniciacion de variables

    fin = false;

    //Menu jugar
       system(T_LIMPIA_PANTALLA);
       fp_ot_muestra_info_juego(tablero, dim, jugadores, turno);

        do
        {
            printf("\nP - Pausar el jugo y volver al menu inicial.\nC - Continuar el juego hasta al final sin volver a preguntar.\nS - Seguir con la siguiente jugada. Depues de la misma volvera a preguntar.\n");
            scanf(" %c",&op);
            vacia_buffer_teclado();

        switch(op)
            {
                case 'C': // Continuar sin menu
                while (fin != true)
                    {
                        fp_ot_muestra_info_juego(tablero, dim, jugadores, turno);
                        fin = ot_juega(tablero, dim, jugadores, &turno);

                        if (fin == true){
                            ot_muestra_record (jugadores);
                        }
                    }
                    break;

                case 'S': // Siguiente turno
                    fp_ot_muestra_info_juego(tablero, dim, jugadores, turno);
                    fin = ot_juega(tablero, dim, jugadores, &turno);

                    if (fin == true){
                        ot_muestra_record (jugadores);
                    }
                    break;

             }while(fin == true);

        }while((op != 'P')); // Pausar

        //Guardado de partida si no se ha terminado
        if (fin == false)
             {
                printf("Guardando partida!\n");
                save = ot_guarda_juego (FICH_JUEGO, tablero, dim, jugadores, turno);
             }

        // Mensaje si no se ha podio guardar
        if (save == false)
            {
                printf("No se ha podido guardar\n");
            }

}
/**
Procedimiento inicial del juego.
Muestra un menú al usuario con las diversas opciones de juego, y organiza todos los procedimientos de acuerdo con las diversas opciones. Controlará que se ejecutan de forma correcta.
*/
void ot_inicio (void){

     //Variables
     int dim, turno, num_record;

     jugador_t jugadores[DIM_MAX];

     record_t records[DIM_MAX];

     char op, tablero [NFILAS_MAX][MCOLS_MAX];

     bool save;


    system(T_LIMPIA_PANTALLA);

    //Menu principal
    do
    {
     printf ("Escoge opcion:\nN - Crear juego.\nC - Cargar partida.\nR - Recuperar records.\nS - Salir.\n\n");
     scanf(" %c", &op);

     //Realitzar l'opcio impresa per teclat
     vacia_buffer_teclado();

     switch (op)
     {
          case 'N': //Nueva partida
               system(T_LIMPIA_PANTALLA);
               ot_crea_juego(tablero, &dim, jugadores, &turno);
               ot_opcion_j (tablero,jugadores, dim, turno);
               break;

          case 'C': // Cargar pertida
                system(T_LIMPIA_PANTALLA);
                save = ot_recupera_juego (FICH_JUEGO,tablero,&dim, jugadores,&turno);

                if(save == false)
                {
                    printf("Partida no encontrada, crea una partida\n");
                }
                else
                {
                    ot_opcion_j (tablero,jugadores, dim, turno);
                }
                break;

          case 'R': //Mostrar records
              num_record = ot_recupera_records (FICH_RECORDS, records, DIM_MAX);
              if (num_record > 0)
                {
                    ot_ordena_records(records, num_record);
                    ot_escribe_records(records, num_record);
                }
             else
                {
                    printf ("No hay records guardados!\n");
                }
    }
  }while(op != 'S'); // Salir
}

/**
 Guarda toda la información de un juego en un fichero binario, para poder recuperalo posteriormente. La información se guarda en el fichero en el siguiente orden: dimensión, turno, tablero, jugadores.

 @param nom_fichero (Ref: tabla[] de carácter) Nombre del fichero binario en el que se guardará el juego.
 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Tablero con la situación del juego.
 @param dim entero (Valor: entero) Dimensión real con la que se jugaba.
 @param jugadores (Ref: tabla[] de jugador_t) Tabla con la información de cada uno de los jugadores.
 @param turno (Valor: entero) Información de que jugador tiene el turno para comenzar a jugar.
 @return (boolano) Devuelve cierto si el juego se ha guardado correctamente y falso en caso contrario.
 */
bool ot_guarda_juego (char nom_fichero[], char tablero[][MCOLS_MAX], int dim, jugador_t jugadores[], int turno)
{
    // Variables
    bool res;
    FILE *f;

    /* Se debe respetar el orden a la hora de guardar los dato: es muy IMPORTANTE */
    // Codigo
    f = fopen(nom_fichero,"wb");
    res = false;

    //Guardar datos en fichero binario
    if (f != NULL){
       res = true;
            fwrite(&dim, sizeof(int), 1 , f);
            fwrite(&turno, sizeof(int), 1 , f);
            fwrite(tablero, sizeof(char), NFILAS_MAX*MCOLS_MAX , f);
            fwrite(jugadores,sizeof(jugador_t),2,f);
        fclose(f);
    }

    return (res);
}

/**
 Recupera toda la información de un juego guardado en un fichero binario. Puede ocurrir que el fichero esté vacío. La información se guarda en el fichero en el siguiente orden: dimensión, turno, tablero, jugadores.

 @param nom_fichero (Ref: tabla[] de carácter) Nombre del fichero binario en el que está guardado el juego.
 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Tablero con la situación del juego.
 @param dim (Ref: entero) Dimensión real con la que se jugaba.
 @param jugadores (Ref: tabla[] de jugador_t) Tabla con la información de cada uno de los jugadores.
 @param turno (Ref: entero) Información de que jugador tiene el turno para comenzar a jugar.
 @return (booleano) Devuelve cierto si se ha recuperado el juego correctamente o falso en caso contrario.
 */
bool ot_recupera_juego (char nom_fichero[], char tablero[][MCOLS_MAX], int *dim, jugador_t jugadores[], int *turno)
{
    // Variables
    bool res=false;
    FILE *f;

    /* Cuidado con el orden, es muy IMPORTANTE */

    //Leer datos de fichero binario
    f = fopen(nom_fichero, "rb");
    if (f != NULL)
    {
       fread (dim, sizeof(int), 1, f);
        if (feof(f)){
            res = false;
        }
        else{
            fread (turno, sizeof(int), 1, f);
            fread(tablero, sizeof(char), NFILAS_MAX*MCOLS_MAX , f);
            fread (jugadores, sizeof(jugador_t), 2, f);
            res = true;
        }
        fclose (f);
    }

    return (res);
  }


/**
 Ordena una tabla de records. Se ordenarán por puntuación, de mayor a menor. En caso de puntuaciones iguales, se ordenará por fecha, de más reciente a más antigua.

 @param records (Ref: tabla[] de record_t) Tabla que contiene los records a ordenar.
 @param dim (Valor: entero) Dimensión de la tabla, número de récords que contiene la tabla.
 */
void ot_ordena_records (record_t records[], int dim)
{
    // variables
	int i, fecha;
    record_t j;
	bool canvi;

	// Inicializacion de variables
	i = 0;
	fecha = 0;
	canvi = false;

	//Codigo
	if (dim < 2){
        i = dim;
	}

	else{
	    while (i!=dim){
	        if (records[i].puntos < records[i+1].puntos){
	            j = records[i];
	            records[i] = records[i+1];
	            records[i+1] = j;
	            canvi = true;
	        }
	        else if (records[i].puntos == records[i+1].puntos){
	            fecha = compara_fechas(&records[i].fecha, &records[i+1].fecha);

	            if (fecha == -1){
	                j = records[i];
	                records[i] = records[i+1];
    	            records[i+1] = j;
	                canvi = true;

	            }
	        }
	        if (canvi != true){
	            i++;
	        }
	        else if (canvi == true){
                    i=0;
	        }
	        canvi = false;
	    }
	}

}

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
bool ot_decide_casilla_auto (char tablero[][MCOLS_MAX], int dim, int *f, int *c, jugador_t *jugador)
{
    /* Variables locales */
    bool valida;
    coord_t casillas_posibles[MCOLS_MAX*MCOLS_MAX];
    int i,x;

    /* Inicializar */
    valida = true;
    i = 0;
    x = 0;

    /* Crea una lista de casillas posibles para el jugador */
    x = fp_ot_lista_posibles (tablero, dim, jugador->color, casillas_posibles);
    /* Determina casillas */
    i = entero_aleatorio_acotado (0, x-1);

    *f = casillas_posibles[i].fila;
    *c = casillas_posibles[i].col;

    jugador->ultima_tirada.fila = casillas_posibles[i].fila;
    jugador->ultima_tirada.col = casillas_posibles[i].col;

    if (x == 0)
    {
        valida = false;
    }

   /* Devuelve el resultado */
    return (valida);
}

/**
 Camia la letra intoducida por el jugador por el numero correspondiente en el tablero del [0...dim-1]

 @param fila (Ref: enter) Fila entrada per teclat [1..dim]
 @param col_ll (Valor: caracter) Columna entrada per teclat ['A'..dim]
 @param col (Ref: enter) Columna pasada a numero [1..dim]
 */
void ot_obtener_num_fila_col ( int *fila, char col_ll, int *col)
{
    // Codidigo
    *fila = *fila - 1;

    switch(col_ll){
        case 'A': *col= 0;
        break;
        case 'B': *col= 1;
        break;
        case 'C': *col= 2;
        break;
        case 'D': *col= 3;
        break;
        case 'E': *col= 4;
        break;
        case 'F': *col= 5;
        break;
        case 'G': *col= 6;
        break;
        case 'H': *col= 7;
        break;
    }
}

/**
 Permite al jugador decidir la casilla en la que desea colocar la ficha. Antes de retornar, comprueba que la casilla es una casilla válida.

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Es el tablero del juego.
 @param dim (Valor: entero) Dimensión con la que se está jugando.
 @param f (Ref: entero) Es la fila de la matriz dónde se colocará la ficha.
 @param c (Ref: entero) Es la columna de la matriz dónde se colocará la ficha.
 @param jugador (Ref: jugador_t) Es la información de jugador.
 @return (booleano) Devuelve cierto si existe una casilla válida para jugar o falso en caso contrario.
 */
bool ot_decide_casilla_manual (char tablero[][MCOLS_MAX], int dim, int *f, int *c, jugador_t *jugador)
{
    /* Variables locales */
    bool valida;
    char c_ll;
    int p, cont;
    coord_t casillas_posibles[MCOLS_MAX*MCOLS_MAX];

    valida = false;
    cont = 0;

    /* Crea una lista de casillas posibles para el jugador */
    p = fp_ot_lista_posibles (tablero, dim, jugador->color, casillas_posibles);

    /* Solicita una jugada y comprueba que sea válida */

            printf("Fila [1...dim]: ");
            scanf("%d", f);

            printf("Columna [MAJ]: ");
            scanf(" %c", &c_ll);

   ot_obtener_num_fila_col (f, c_ll, c);


    while((valida == false)&&(p != 0)){

        if((casillas_posibles[cont].fila == *f)&&(casillas_posibles[cont].col == *c)){

            jugador->ultima_tirada.fila = *f;
            jugador->ultima_tirada.col = *c;

            valida = true;
        }
        else{
            cont++;
        }


        if(cont == p){

            printf("Casilla no valida.\n\nFila (1...dim): ");
            scanf("%d", f);

            printf("Columna (MAJ): ");
            scanf(" %c", &c_ll);

            ot_obtener_num_fila_col (f, c_ll, c);

            cont = 0;
        }

    }
    if (p == 0){
        printf("No hay mas movimientos!");
    }

    /* Devuelve el resultado */
    return (valida);
}

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
void ot_crea_juego(char tablero[][MCOLS_MAX], int *dim, jugador_t jugadores[], int *turno)
{
    //Variables
    jugador_t aux;
    char color;
    int num;

    // Inicializacion

    color = FICHA_NEGRA;

    //Codigo

        // Pedir dimencion
        printf("Dimension del tablero[8..10]: ");
        scanf("%d", dim);

        if ((*dim != 8) && (*dim != 9) && (*dim != 10)){ //Dimension erronia sera 8
                printf("La dimension sera 8\n");
                *dim = 8;
        }

        ot_tablero_inicial(tablero, *dim); // Inicializar tablero

        num = entero_aleatorio_acotado(1, 2); // Numero aleatrio

        if (num == 1){ //Ficha aleatoria
            color = FICHA_BLANCA;
        }
        else if (num == 2){
            color = FICHA_NEGRA;
        }

        //Guardar color
        ot_lee_jugador(&aux, color);
        jugadores[0]= aux;

        color = ot_cambia_color(color);

        ot_lee_jugador(&aux, color);
        jugadores[1] = aux;

        // Determinar turno
       if(jugadores[0].color == FICHA_NEGRA){
              *turno = 0;

       }
       else{
          *turno = 1;
       }
}
/**
 Procedimiento principal del juego. Es el que determina la dinámica del juego: cada jugador elije su jugada y pasa el turno al siguiente.
 El juego termina cuando no quedan casillas o cuando ninguno de los jugadores tiene una jugada posible. Cuando acaba, se guarda el récord del ganador en el fichero.

 @param tablero (Ref: tabla[][MCOLS_MAX] de carácter) Es el tablero del juego.
 @param dim (Valor: entero) Dimensión con la que se está jugando.
 @param jugadores (Ref: tabla[] de jugador_t) Es la información de los jugadores.
 @param turno (Ref: entero) Indica el jugador que tiene el turno de juego.
 @return (booleano) Devuelve cierto si el juego ha acabado y falso en caso contrario.
 */
bool ot_juega (char tablero[][MCOLS_MAX], int dim, jugador_t jugadores[], int *turno)
{
	bool fin;

	/* Reemplazalo con tu código */
	fin = fp_ot_juega (tablero, dim, jugadores, turno);

    return (fin);
}
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
void ot_escribe_record(record_t *record)
{
    //Codigo
    escribe_fecha(&record->fecha);
    // Cambia color banco a negro
    if(record->color == FICHA_BLANCA)
    {
        printf("\tBlancas\t");
    }
    // Cambia color negro a blanco
    else
    {
        if(record->color == FICHA_NEGRA)
        {
            printf("\tNegras\t");
        }
    }
    printf("%d\t", record->puntos);
    printf("%s\n", record->nombre);
}

/**
 Imprime un número determinado de los récords guardados en la tabla.

 @param records (Ref: tabla[] de record_t) Tabla con los records, ordenados o no.
 @param num_records (Valor: entero) Número máximo de registros a imprimir.
 */
void ot_escribe_records(record_t records[], int num_records)
{
    /* Definición de variables locales si las necesitas. */
	int i;
	i=1;
	record_t aux;
    /* Código */
    aux.puntos = records[0].puntos;

    strcpy(aux.nombre, records[0].nombre);

	aux.color=records[0].color;

	while(i<=num_records)
	{
	    ot_escribe_record(&records[i-1]);
	    if(records[i-1].puntos<records[i].puntos)
	    {
	        aux.puntos=records[i].puntos;

	        strcpy(aux.nombre, records[i].nombre);

	        aux.color=records[i].color;
	    }

	    i++;
	}

	/* Resumen final */
    printf ("--------------------------------------\n");
    printf ("Total records: %d\n", i-1);
    printf ("Mejor ha sido %s (%c), con %d puntos\n", aux.nombre, aux.color, aux.puntos);
}

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
bool ot_guarda_record (char nom_fichero[], char nombre[], int puntuacion, char color)
{
	bool res;

	/* No entra en la evaluación de la práctica */
	res = fp_ot_guarda_record(nom_fichero, nombre, puntuacion, color);

	return (res);
}

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
int ot_recupera_records (char nom_fichero[], record_t records[], int dim)
{
	int num_records;

	/* No entra en la evaluación de la práctica */
	num_records = fp_ot_recupera_records (nom_fichero, records, dim);

	return (num_records);
}
/** @} */
