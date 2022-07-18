#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include <time.h>
#include "hrcp.h"
#include "juegos.h"
#ifndef jornadas  
#define jornadas  

FILE* f_tipos;
FILE* f_jornadas;
int tdt=7;

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



Tipo *leer_tipos(char *filename,int *total){
	f_tipos=fopen(filename,"rb");
	if (f_tipos == NULL) {
        printf("error opening file !\n");
        exit(1);
    }
    if(fread(total,sizeof(int),1,f_tipos)!=1){
    	exit(1);
	}
	Tipo *datos=(Tipo *)malloc(sizeof(Tipo) * *total);
	if(fread(datos,sizeof(Tipo),*total,f_tipos)!=*total){
		free(datos);
    	exit(1);
	}
	if (fclose(f_tipos)==EOF){
		free(datos);
		exit(1);
	}
	return datos;
}

Jornada *leer_jornadas(char *filename,int *total){
	f_jornadas=fopen(filename,"rb");
	if (f_tipos == NULL) {
        printf("error opening file !\n");
        exit(1);
    }
    if(fread(total,sizeof(int),1,f_jornadas)!=1){
    	exit(1);
	}
	Jornada *datos=(Jornada *)malloc(sizeof(Jornada) * *total);
	if(fread(datos,sizeof(Jornada),*total,f_jornadas)!=*total){
		free(datos);
    	exit(1);
	}
	if (fclose(f_jornadas)==EOF){
		free(datos);
		exit(1);
	}
	return datos;
}

void crear_files_juegos_jornadas(){
	//Creando tipos de jornadas
	Tipo tipos[tdt];
	strcpy(tipos[0].tipo, "Jornada");
    tipos[0].id = 1;
    strcpy(tipos[1].tipo, "4's de Final, ida");
    tipos[1].id = 2;
    strcpy(tipos[2].tipo, "4's de Final, vuelta");
    tipos[2].id = 3;
    strcpy(tipos[3].tipo, "Semi Final, ida");
    tipos[3].id = 4;
    strcpy(tipos[4].tipo, "Semi Final, vuelta");
    tipos[4].id = 5;
    strcpy(tipos[5].tipo, "Final, ida");
    tipos[5].id = 6;
    strcpy(tipos[6].tipo, "Final, vuelta");
    tipos[6].id = 7;
    f_tipos = fopen("tipos.txt", "wb");
    if (f_tipos == NULL) {
        printf("error opening file !\n");
        exit(1);
    }
    if(fwrite(&tdt,sizeof(int),1,f_tipos)!=1){
    	exit(1);
	}
    if(fwrite(tipos, sizeof(Tipo), tdt, f_tipos)!=tdt){
		exit(1);
	}
	if (fclose(f_tipos)==EOF){
		exit(1);
	}
	
	//Creando las jornadas de juegos
	int t_j=17+8+4+2;
	Jornada jornada[t_j];
	char fecha[]={'\0'};
	int fecha_inicial=1;
	for(int x=0;x<t_j;x++){
		if(x<17){
			generar_calendario(x+1,fecha_inicial,fecha_inicial+6,1);
			//puras jornadas
			date_add_days(fecha_inicial,jornada[x].fecha_1);
			fecha_inicial+=6;
			date_add_days(fecha_inicial,jornada[x].fecha_2);
			fecha_inicial+=1;	
			//printf("jornada %d %s - %s\n",x+1,jornada[x].fecha_1,jornada[x].fecha_2);
    		jornada[x].id = x+1;
    		jornada[x].tipo_id = 1;
		}else if(x<21){
			//cuartos de ida
			date_add_days(fecha_inicial,jornada[x].fecha_1);
			date_add_days(fecha_inicial+2,jornada[x].fecha_2);
			//printf("Cuartos de ida %d %s - %s\n",x+1,jornada[x].fecha_1,jornada[x].fecha_2);
    		jornada[x].id = x+1;
    		jornada[x].tipo_id = 2;
		}else if(x<25){
			//cuartos de vuelta
			date_add_days(fecha_inicial+3,jornada[x].fecha_1);
			date_add_days(fecha_inicial+6,jornada[x].fecha_2);
			//printf("Cuartos de vuelta %d %s - %s\n",x+1,jornada[x].fecha_1,jornada[x].fecha_2);
    		jornada[x].id = x+1;
    		jornada[x].tipo_id = 3;
		}else if(x<27){
			//semifinal de ida
			date_add_days(fecha_inicial+7,jornada[x].fecha_1);
			date_add_days(fecha_inicial+9,jornada[x].fecha_2);
			//printf("Semi de ida %d %s - %s\n",x+1,jornada[x].fecha_1,jornada[x].fecha_2);
    		jornada[x].id = x+1;
    		jornada[x].tipo_id = 4;
		}
		else if(x<29){
			//semifinal de vuelta
			date_add_days(fecha_inicial+10,jornada[x].fecha_1);
			date_add_days(fecha_inicial+13,jornada[x].fecha_2);
			//printf("Semi de vuelta %d %s - %s\n",x+1,jornada[x].fecha_1,jornada[x].fecha_2);
    		jornada[x].id = x+1;
    		jornada[x].tipo_id = 5;
		}
		else if(x<30){
			//final de ida
			date_add_days(fecha_inicial+14,jornada[x].fecha_1);
			date_add_days(fecha_inicial+16,jornada[x].fecha_2);
			//printf("Final de ida %d %s - %s\n",x+1,jornada[x].fecha_1,jornada[x].fecha_2);
    		jornada[x].id = x+1;
    		jornada[x].tipo_id = 6;
		}else if(x<31){
			//final de vuelta
			date_add_days(fecha_inicial+17,jornada[x].fecha_1);
			date_add_days(fecha_inicial+20,jornada[x].fecha_2);
			//printf("Final de vuelta %d %s - %s\n",x+1,jornada[x].fecha_1,jornada[x].fecha_2);
    		jornada[x].id = x+1;
    		jornada[x].tipo_id = 7;
		}
	}
		
		f_jornadas = fopen("jornadas.txt", "wb");
	    if (f_tipos == NULL) {
	        printf("error opening file !\n");
	        exit(1);
	    }
	    if(fwrite(&t_j,sizeof(int),1,f_jornadas)!=1){
	    	exit(1);
		}
	    if(fwrite(jornada, sizeof(Jornada), t_j, f_jornadas)!=t_j){
			exit(1);
		}
		if (fclose(f_jornadas)==EOF){
			exit(1);
		}
	getch();
}

#endif  
