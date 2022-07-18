#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include <time.h>
#include "hrcp.h"
#ifndef juegos  
#define juegos  
int total_juegos_torneo=(17*9)+8+4+2;
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


int juegos_asignados(){
	int x=0;
	Juegos_s data;
	if(!file_exists("juegos.txt"))return 0;
    f_juegos = fopen("juegos.txt", "rb");
    while ((fread(&data, sizeof(data), 1, f_juegos)) > 0)
    {
    	x++;
    } 
	fclose(f_juegos);
	return x;
}

Juegos_s *leer_juegos(char *filename,int *total){
	f_juegos=fopen(filename,"rb");
	if (f_juegos == NULL) {
        printf("error opening file !\n");
        exit(1);
    }
    if(fread(total,sizeof(int),1,f_juegos)!=1){
    	exit(1);
	}
	Juegos_s *datos=(Juegos_s *)malloc(sizeof(Juegos_s) * *total);
	if(fread(datos,sizeof(datos),*total,f_juegos)!=*total){
		printf("No se han podido leer los %d datos.\n",*total);
		free(datos);
    	exit(1);
	}
	if (fclose(f_juegos)==EOF){
		free(datos);
		exit(1);
	}
	return datos;
}

void  generar_calendario(int jornada,int dias_min,int dias_max,int tipo_j){
	if(tipo_j==1){
		//es jornada
		for(int x=(9*(jornada-1));x<(jornada*9);x++){
			int valido=0;
			int e1=1,e2=18;
			if(file_exists("juegos.txt")){
				//leer datos del archivo y verificar
				int j1=juegos_asignados();
				Juegos_s *datos=leer_juegos("juegos.txt",&j1);
				printf("jornada %d juego %d registros %d  %d vs %d \n",jornada,x+1,j1,datos[x].id_e1,datos[x].id_e2);
				//verificamos si el juego a programar es válido
				int seguir=0;
				while(seguir!=1){
					e1=r_number(1,18);//Equipo 1
					e2=r_number(1,18);//Equipo 2
					if(e1==e2){
						//son los mismos equipos, no aplica
						//printf("%d vs %d \n",e1,e2);
						//getch();
						//system("cls");
						continue;
					}else{
						//no son los mismos equipos randon
						//se deben buscar si el juego ya fue asignado
						int juego_valido=1;
						for(int j=0;j<j1;j++){
							if((datos[j].id_e1==e1 && datos[j].id_e2==e2) || (datos[j].id_e1==e2 && datos[j].id_e2==e1)) {
								//juego no valido
								//printf("No aplica %d vs %d \n",e1,e2);
								//getch();
								juego_valido=0;
								break;
							}
						}
						for(int j=(9*(jornada-1));j<j1;j++){
							if((datos[j].id_e1==e1 || datos[j].id_e1==e2 || datos[j].id_e2==e1 || datos[j].id_e2==e2)) {
								//juego no valido
								juego_valido=0;
								break;
							}
							//buscar si no tienen juego asigando ya en la jornada
						}
						if(juego_valido==1){
							seguir=1;
							valido=1;
						}
					}
				}
				
				//valido=1;
			}else{
				//crea el primer juego, sin importar cual sea
				valido=1;
			}
			if(valido==1){
				Juegos_s juego;
				juego.id=x+1;
				juego.goles_e1=0;
				juego.goles_e2=0;
				juego.id_e1=e1;
				juego.id_e2=e2;
				juego.id_j=jornada;
				date_add_days(r_number(dias_min,dias_max),juego.fecha);
				//guardo el primer juego
				f_juegos = fopen("juegos.txt", "ab");
			    if (f_juegos == NULL) {
			        printf("error opening file juegos.txt !\n");
			        exit(1);
			    }
			    if(fwrite(&juego,sizeof(juego), 1, f_juegos)!=1);
				fclose(f_juegos);
			}
		}
	}
}
#endif  
