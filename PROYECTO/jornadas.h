#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include <time.h>
#include "hrcp.h"
#ifndef jornadas  
#define jornadas  

FILE* f_tipos;

struct Tipo {
    int id;
    char tipo[25];
};

struct Jornada{
    int id;
    char fecha_1[12];
    char fecha_2[12];
    int tipo_id;
};

struct Juegos {
    int id;
    int num;
    int id_e1;
    int id_e2;
    int id_j;
    int goles_e1;
    int goles_e2;
};

void crear_files_juegos_jornadas(){
	
	int tdt=7;
	Tipo tipos[tdt];
	strcpy(tipos[0].tipo, "Jornada");
    tipos[0].id = 1;
    strcpy(tipos[1].tipo, "4's de Final de ida");
    tipos[1].id = 2;
    strcpy(tipos[2].tipo, "4's de Final de vuelta");
    tipos[2].id = 3;
    strcpy(tipos[3].tipo, "Semi Final de ida");
    tipos[3].id = 4;
    strcpy(tipos[4].tipo, "Semi Final de vuelta");
    tipos[4].id = 5;
    strcpy(tipos[5].tipo, "Final de ida");
    tipos[5].id = 6;
    strcpy(tipos[6].tipo, "Final de vuleta");
    tipos[6].id = 7;
    
    
    
    
    f_tipos = fopen("tipos.txt", "wb");
    if (f_tipos == NULL) {
        printf("error opening file !\n");
        exit(1);
    }
    if(fwrite(&tdt,sizeof(int),1,f_tipos)!=1){
    	printf("No se han escrito los %d datos.\n",4);
    	exit(1);
	}
    if(fwrite(tipos, sizeof(Tipo), tdt, f_tipos)!=tdt){
    	printf("No se ha podido escribir el fichero.\n");
		exit(1);
	}
	if (fclose(f_tipos)==EOF){
		printf("No se ha podido cerrar el fichero.\n");
		exit(1);
	}	
	//text_center("<<< SE HA INICIADO UN NUEVO TORNEO >>>",18);
}

#endif  
