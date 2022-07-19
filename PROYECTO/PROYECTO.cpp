/*
Con el uso del getch
Pedir una tecla y que se repita el ciclo do while mientras que no se capture el enter(13)
Filtrar solo numeros y vocales
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "hrcp.h"
#include "equipos.h"
#include "jornadas.h"

main()
{
	system("color 06");
	//Seed el random
	srand(time(NULL));
    char opt;
    do {
        //creamos el menú
        system("cls");
        main_s();
        last_y=8;
        text_center("*** SIMULADOR DE TORNEO DE LA LIGA MX 2022 ***",last_y);
        text_center("(1) -- Comenzar Torneo",last_y+3);
        text_center("(2) -- Juegos",last_y+5);
        text_center("(3) -- Ver Tabla General",last_y+7);
        text_center("(4) -- Salir",last_y+9);
        text_center("ELIJA UNA OPCION:",last_y+13);
        opt = getch();
        if (opt == 49 || opt == 50 || opt == 51) {
        	system("cls");
            //Se procede con la operación
            if(opt!=49){
            	if(error_torneo()){
            		continue;
				}
			}
            switch (opt) {
	            case 49: {
	                comenzar_torneo();
	                break;
	            }
	            case 50: {
	            	rm("juegos.txt");
	            	//printf("%d",juegos_asignados());
	            	//getch();
					crear_files_juegos_jornadas();
	                break;
	            }
	            case 51: {
	            	display_juegos();
	            	//tabla_general();
	            	getch();
	                break;
	            }
            }
        }
    } while (opt != 52);
    system("cls");
    main_s();
    text_center("<<< SE HAN GUARDADO LOS CAMBIOS. PRESIONE UNA TECLA PARA CONTINUAR >>>",15);
    getch();
    system("cls");
}

