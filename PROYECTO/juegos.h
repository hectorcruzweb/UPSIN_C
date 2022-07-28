#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "hrcp.h"
#define tj 167
#ifndef juegos
#define juegos

FILE* f_juegos;
struct Juegos_s {
    int id;
    int id_e1;
    int id_e2;
    int id_j;
    int goles_e1;
    int goles_e2;
    char fecha[12];
};

struct Juegos_s calendario[tj] = { '\0' };

int juegos_asignados()
{
    int x = 0;
    Juegos_s data;
    if (!file_exists("juegos.txt"))
        return 0;
    f_juegos = fopen("juegos.txt", "rb");
    while ((fread(&data, sizeof(data), 1, f_juegos)) > 0) {
        x++;
    }
    fclose(f_juegos);
    return x;
}

Juegos_s* leer_juegos()
{
    int j1 = juegos_asignados();

    f_juegos = fopen("juegos.txt", "rb");

    if (f_juegos == NULL) {
        printf("error opening file !\n");
        exit(1);
    }

    Juegos_s* datos = (Juegos_s*)malloc(sizeof(Juegos_s) * j1);
    if (fread(datos, sizeof(Juegos_s), j1, f_juegos) != j1) {
        printf("No se han podido leer los %d datos.\n", j1);
        free(datos);
        exit(1);
    }
    if (fclose(f_juegos) == EOF) {
        free(datos);
        exit(1);
    }
    return datos;
}



bool torneo_funcional(){
	if(!file_exists("equipos.txt") || !file_exists("tipos.txt")|| !file_exists("jornadas.txt")|| !file_exists("juegos.txt")){
		//borramos todos los archivos y comenzamos nuevamente
		rm("equipos.txt");
		rm("tipos.txt");
		rm("jornadas.txt");
		rm("juegos.txt");
		system("cls");
		//Obligamos a crea un nuevo torneo
		main_s();
		text_center("<<< HA OCURRIDO UN ERROR, DEBE REINICIAR EL TORNEO >>>",14);
		getch();
		return false;
	}
	return true;
}

void display_juegos()
{
	if(!torneo_funcional())return;
	
	
    Juegos_s* datos;
    datos = leer_juegos();
    if (datos == NULL) {
        printf("No se han podido leer los datos.\n");
        exit(1);
    }

    for (int x = 0; x < tj; x++) {
        printf("\n%d -- %d vs %d", datos[x].id, datos[x].id_e1, datos[x].id_e2);
    }
    getch();
}

void generar_calendario()
{
    //los 18 equipos deben jugar con el resto 17 equipos durante las 17 jornadas
    int index=0;
    //Jornada 1
    calendario[index].id_e1=2;calendario[index].id_e2=7;index++;
    calendario[index].id_e1=11;calendario[index].id_e2=1;index++;
    calendario[index].id_e1=12;calendario[index].id_e2=6;index++;
    calendario[index].id_e1=14;calendario[index].id_e2=9;index++;
    calendario[index].id_e1=15;calendario[index].id_e2=3;index++;
    calendario[index].id_e1=16;calendario[index].id_e2=10;index++;
    calendario[index].id_e1=18;calendario[index].id_e2=13;index++;
    calendario[index].id_e1=4;calendario[index].id_e2=8;index++;
    calendario[index].id_e1=5;calendario[index].id_e2=17;index++;
    //jornada 2
	calendario[index].id_e1=1;calendario[index].id_e2=14;index++;
	calendario[index].id_e1=13;calendario[index].id_e2=16;index++;
	calendario[index].id_e1=17;calendario[index].id_e2=4;index++;
	calendario[index].id_e1=3;calendario[index].id_e2=18;index++;
	calendario[index].id_e1=6;calendario[index].id_e2=5;index++;
	calendario[index].id_e1=7;calendario[index].id_e2=11;index++;
	calendario[index].id_e1=8;calendario[index].id_e2=15;index++;
	calendario[index].id_e1=9;calendario[index].id_e2=12;index++;
	calendario[index].id_e1=10;calendario[index].id_e2=2;index++;
	//jornada 3
	calendario[index].id_e1=1;calendario[index].id_e2=9;index++;
	calendario[index].id_e1=2;calendario[index].id_e2=13;index++;
	calendario[index].id_e1=11;calendario[index].id_e2=10;index++;
	calendario[index].id_e1=14;calendario[index].id_e2=7;index++;
	calendario[index].id_e1=15;calendario[index].id_e2=17;index++;
	calendario[index].id_e1=16;calendario[index].id_e2=3;index++;
	calendario[index].id_e1=18;calendario[index].id_e2=8;index++;
	calendario[index].id_e1=4;calendario[index].id_e2=6;index++;
	calendario[index].id_e1=5;calendario[index].id_e2=12;index++;
	//jornada 4
	calendario[index].id_e1=12;calendario[index].id_e2=4;index++;
	calendario[index].id_e1=13;calendario[index].id_e2=11;index++;
	calendario[index].id_e1=17;calendario[index].id_e2=18;index++;
	calendario[index].id_e1=3;calendario[index].id_e2=2;index++;
	calendario[index].id_e1=6;calendario[index].id_e2=15;index++;
	calendario[index].id_e1=7;calendario[index].id_e2=1;index++;
	calendario[index].id_e1=8;calendario[index].id_e2=16;index++;
	calendario[index].id_e1=9;calendario[index].id_e2=5;index++;
	calendario[index].id_e1=10;calendario[index].id_e2=14;index++;
	//jornada 5
	calendario[index].id_e1=1;calendario[index].id_e2=10;index++;
	calendario[index].id_e1=2;calendario[index].id_e2=8;index++;
	calendario[index].id_e1=11;calendario[index].id_e2=3;index++;
	calendario[index].id_e1=14;calendario[index].id_e2=13;index++;
	calendario[index].id_e1=15;calendario[index].id_e2=12;index++;
	calendario[index].id_e1=16;calendario[index].id_e2=17;index++;
	calendario[index].id_e1=18;calendario[index].id_e2=6;index++;
	calendario[index].id_e1=4;calendario[index].id_e2=5;index++;
	calendario[index].id_e1=7;calendario[index].id_e2=9;index++;
	//jornada 6
	calendario[index].id_e1=12;calendario[index].id_e2=18;index++;
	calendario[index].id_e1=13;calendario[index].id_e2=1;index++;
	calendario[index].id_e1=17;calendario[index].id_e2=2;index++;
	calendario[index].id_e1=3;calendario[index].id_e2=14;index++;
	calendario[index].id_e1=5;calendario[index].id_e2=15;index++;
	calendario[index].id_e1=6;calendario[index].id_e2=16;index++;
	calendario[index].id_e1=8;calendario[index].id_e2=11;index++;
	calendario[index].id_e1=9;calendario[index].id_e2=4;index++;
	calendario[index].id_e1=10;calendario[index].id_e2=7;index++;
	//jornada 7
	calendario[index].id_e1=1;calendario[index].id_e2=3;index++;
	calendario[index].id_e1=2;calendario[index].id_e2=6;index++;
	calendario[index].id_e1=11;calendario[index].id_e2=17;index++;
	calendario[index].id_e1=14;calendario[index].id_e2=8;index++;
	calendario[index].id_e1=15;calendario[index].id_e2=4;index++;
	calendario[index].id_e1=16;calendario[index].id_e2=12;index++;
	calendario[index].id_e1=18;calendario[index].id_e2=5;index++;
	calendario[index].id_e1=7;calendario[index].id_e2=13;index++;
	calendario[index].id_e1=10;calendario[index].id_e2=9;index++;
    //jornada 8
	calendario[index].id_e1=12;calendario[index].id_e2=2;index++;
	calendario[index].id_e1=13;calendario[index].id_e2=10;index++;
	calendario[index].id_e1=17;calendario[index].id_e2=14;index++;
	calendario[index].id_e1=3;calendario[index].id_e2=7;index++;
	calendario[index].id_e1=4;calendario[index].id_e2=18;index++;
	calendario[index].id_e1=5;calendario[index].id_e2=16;index++;
	calendario[index].id_e1=6;calendario[index].id_e2=11;index++;
	calendario[index].id_e1=8;calendario[index].id_e2=1;index++;
	calendario[index].id_e1=9;calendario[index].id_e2=15;index++;
   	//jornada 9
	calendario[index].id_e1=1;calendario[index].id_e2=17;index++;
	calendario[index].id_e1=2;calendario[index].id_e2=5;index++;
	calendario[index].id_e1=11;calendario[index].id_e2=12;index++;
	calendario[index].id_e1=13;calendario[index].id_e2=9;index++;
	calendario[index].id_e1=14;calendario[index].id_e2=6;index++;
	calendario[index].id_e1=16;calendario[index].id_e2=4;index++;
	calendario[index].id_e1=18;calendario[index].id_e2=15;index++;
	calendario[index].id_e1=7;calendario[index].id_e2=8;index++;
	calendario[index].id_e1=10;calendario[index].id_e2=3;index++;
    //jornada 10
	calendario[index].id_e1=12;calendario[index].id_e2=14;index++;
	calendario[index].id_e1=15;calendario[index].id_e2=16;index++;
	calendario[index].id_e1=17;calendario[index].id_e2=7;index++;
	calendario[index].id_e1=3;calendario[index].id_e2=13;index++;
	calendario[index].id_e1=4;calendario[index].id_e2=2;index++;
	calendario[index].id_e1=5;calendario[index].id_e2=11;index++;
	calendario[index].id_e1=6;calendario[index].id_e2=1;index++;
	calendario[index].id_e1=8;calendario[index].id_e2=10;index++;
	calendario[index].id_e1=9;calendario[index].id_e2=18;index++;
    //jornada 11
	calendario[index].id_e1=1;calendario[index].id_e2=12;index++;
	calendario[index].id_e1=2;calendario[index].id_e2=15;index++;
	calendario[index].id_e1=11;calendario[index].id_e2=4;index++;
	calendario[index].id_e1=13;calendario[index].id_e2=8;index++;
	calendario[index].id_e1=14;calendario[index].id_e2=5;index++;
	calendario[index].id_e1=16;calendario[index].id_e2=18;index++;
	calendario[index].id_e1=3;calendario[index].id_e2=9;index++;
	calendario[index].id_e1=7;calendario[index].id_e2=6;index++;
	calendario[index].id_e1=10;calendario[index].id_e2=17;index++;
    //jornada 12
	calendario[index].id_e1=12;calendario[index].id_e2=7;index++;
	calendario[index].id_e1=15;calendario[index].id_e2=11;index++;
	calendario[index].id_e1=17;calendario[index].id_e2=13;index++;
	calendario[index].id_e1=18;calendario[index].id_e2=2;index++;
	calendario[index].id_e1=4;calendario[index].id_e2=14;index++;
	calendario[index].id_e1=5;calendario[index].id_e2=1;index++;
	calendario[index].id_e1=6;calendario[index].id_e2=10;index++;
	calendario[index].id_e1=8;calendario[index].id_e2=3;index++;
	calendario[index].id_e1=9;calendario[index].id_e2=16;index++;
    //jornada 13
	calendario[index].id_e1=1;calendario[index].id_e2=4;index++;
	calendario[index].id_e1=2;calendario[index].id_e2=16;index++;
	calendario[index].id_e1=11;calendario[index].id_e2=18;index++;
	calendario[index].id_e1=13;calendario[index].id_e2=6;index++;
	calendario[index].id_e1=14;calendario[index].id_e2=15;index++;
	calendario[index].id_e1=3;calendario[index].id_e2=17;index++;
	calendario[index].id_e1=7;calendario[index].id_e2=5;index++;
	calendario[index].id_e1=8;calendario[index].id_e2=9;index++;
	calendario[index].id_e1=10;calendario[index].id_e2=12;index++;
	//jornada 14
	calendario[index].id_e1=12;calendario[index].id_e2=13;index++;
	calendario[index].id_e1=15;calendario[index].id_e2=1;index++;
	calendario[index].id_e1=16;calendario[index].id_e2=11;index++;
	calendario[index].id_e1=17;calendario[index].id_e2=8;index++;
	calendario[index].id_e1=18;calendario[index].id_e2=14;index++;
	calendario[index].id_e1=4;calendario[index].id_e2=7;index++;
	calendario[index].id_e1=5;calendario[index].id_e2=10;index++;
	calendario[index].id_e1=6;calendario[index].id_e2=3;index++;
	calendario[index].id_e1=9;calendario[index].id_e2=2;index++;
	//jornada 15
	calendario[index].id_e1=1;calendario[index].id_e2=18;index++;
	calendario[index].id_e1=11;calendario[index].id_e2=2;index++;
	calendario[index].id_e1=13;calendario[index].id_e2=5;index++;
	calendario[index].id_e1=14;calendario[index].id_e2=16;index++;
	calendario[index].id_e1=17;calendario[index].id_e2=9;index++;
	calendario[index].id_e1=3;calendario[index].id_e2=12;index++;
	calendario[index].id_e1=7;calendario[index].id_e2=15;index++;
	calendario[index].id_e1=8;calendario[index].id_e2=6;index++;
	calendario[index].id_e1=10;calendario[index].id_e2=4;index++;
	//jornada 16
	calendario[index].id_e1=2;calendario[index].id_e2=14;index++;
	calendario[index].id_e1=11;calendario[index].id_e2=9;index++;
	calendario[index].id_e1=12;calendario[index].id_e2=8;index++;
	calendario[index].id_e1=15;calendario[index].id_e2=10;index++;
	calendario[index].id_e1=16;calendario[index].id_e2=1;index++;
	calendario[index].id_e1=18;calendario[index].id_e2=7;index++;
	calendario[index].id_e1=4;calendario[index].id_e2=13;index++;
	calendario[index].id_e1=5;calendario[index].id_e2=3;index++;
	calendario[index].id_e1=6;calendario[index].id_e2=17;index++;
	//jornada 17
	calendario[index].id_e1=1;calendario[index].id_e2=2;index++;
	calendario[index].id_e1=13;calendario[index].id_e2=15;index++;
	calendario[index].id_e1=14;calendario[index].id_e2=11;index++;
	calendario[index].id_e1=17;calendario[index].id_e2=12;index++;
	calendario[index].id_e1=3;calendario[index].id_e2=4;index++;
	calendario[index].id_e1=7;calendario[index].id_e2=16;index++;
	calendario[index].id_e1=8;calendario[index].id_e2=5;index++;
	calendario[index].id_e1=9;calendario[index].id_e2=6;index++;
	calendario[index].id_e1=10;calendario[index].id_e2=18;
    /*
	date_add_days(fecha_inicial,jornada[x].fecha_1);
	fecha_inicial+=6;
	date_add_days(fecha_inicial,jornada[x].fecha_2);
	fecha_inicial+=1;	
	//printf("jornada %d %s - %s\n",x+1,jornada[x].fecha_1,jornada[x].fecha_2);
    jornada[x].id = x+1;
    jornada[x].tipo_id = 1;
	*/
    //creados los juegos asigno a sus respectivas jornadas.
    //imprimo lista de juegos de jornadas
    int jor=1;
    int dias=1;
    for (int j = 0; j < 153; j++) {
    		calendario[j].id=j+1;
    		calendario[j].id_j=jor;
    		date_add_days(r_number(dias,dias+6),calendario[j].fecha);
            //printf("juego %d - %d vs %d --> %s \n", calendario[j].id,calendario[j].id_e1, calendario[j].id_e2,calendario[j].fecha);
            if((j+1)%9==0){
            	//printf("Fin jornada %d\n",jor);
            	jor++;
            	dias+=7;
			}
    }
    
    
    int id_juego=153;
    //Creando cuartos de final de ida
    for (int j = id_juego; j < (id_juego+4); j++) {
    		calendario[j].id=j+1;
    		calendario[j].id_j=18;
    		calendario[j].id_e1=0;
    		calendario[j].id_e2=0;
    		date_add_days(r_number(dias,dias+3),calendario[j].fecha);
    }
    dias+=4;
    id_juego+=4;
    //Creando cuartos de final de vuelta
    for (int j = id_juego; j < (id_juego+4); j++) {
    		calendario[j].id=j+1;
    		calendario[j].id_j=19;
    		calendario[j].id_e1=0;
    		calendario[j].id_e2=0;
    		date_add_days(r_number(dias,dias+3),calendario[j].fecha);
    }
    dias+=4;
    id_juego+=4;
    //Creando semi final de ida
    for (int j = id_juego; j < (id_juego+2); j++) {
    		calendario[j].id=j+1;
    		calendario[j].id_j=20;
    		calendario[j].id_e1=0;
    		calendario[j].id_e2=0;
    		date_add_days(r_number(dias,dias+3),calendario[j].fecha);
    }
    
    dias+=4;
    id_juego+=2;
    //Creando semi final de vuelta
    for (int j = id_juego; j < (id_juego+2); j++) {
    		calendario[j].id=j+1;
    		calendario[j].id_j=21;
    		calendario[j].id_e1=0;
    		calendario[j].id_e2=0;
    		date_add_days(r_number(dias,dias+3),calendario[j].fecha);
    }
    
    dias+=4;
    id_juego+=2;
    //Creando final de ida
    calendario[id_juego].id=id_juego+1;
    calendario[id_juego].id_j=22;
    calendario[id_juego].id_e1=0;
    calendario[id_juego].id_e2=0;
    date_add_days(dias,calendario[id_juego].fecha);
    id_juego++;
    calendario[id_juego].id=id_juego+1;
    calendario[id_juego].id_j=23;
    calendario[id_juego].id_e1=0;
    calendario[id_juego].id_e2=0;
    date_add_days(dias+6,calendario[id_juego].fecha);
    
    int total_partidos=tj;
    f_juegos = fopen("juegos.txt", "ab");
	if (f_juegos == NULL) {
	    printf("error opening file !\n");
	    exit(1);
	}
	if(fwrite(calendario, sizeof(Juegos_s), total_partidos, f_juegos)!=total_partidos){
		exit(1);
	}
	if (fclose(f_juegos)==EOF){
		exit(1);
	}
	/*
    for (int j = 0; j < tj; j++) {
            printf("juego %d - %d vs %d --> %s id j %d\n", calendario[j].id,calendario[j].id_e1, calendario[j].id_e2,calendario[j].fecha,calendario[j].id_j);
    }*/
}

#endif
