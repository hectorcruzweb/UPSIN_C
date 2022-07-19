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

Juegos_s *leer_juegos(){
	int j1=juegos_asignados();
	
	f_juegos=fopen("juegos.txt","rb");
	
	if (f_juegos == NULL) {
        printf("error opening file !\n");
        exit(1);
    }
    
	Juegos_s *datos=(Juegos_s *)malloc(sizeof(Juegos_s) * j1);
	if(fread(datos,sizeof(datos),j1,f_juegos)!=j1){
		printf("No se han podido leer los %d datos.\n",j1);
		free(datos);
    	exit(1);
	}
	if (fclose(f_juegos)==EOF){
		free(datos);
		exit(1);
	}
	return datos;
}

void display_juegos(){
	Juegos_s *datos;
	datos=leer_juegos();
	if(datos==NULL){
		printf("No se han podido leer los datos.\n");
		exit(1);
	}
	
	
	for(int x=0;x<juegos_asignados();x++){
	 printf("\n Id %d Jor %d  %d vs %d", datos[x].id,datos[x].id_j,datos[x].id_e1,datos[x].id_e2);
		
		if(x>0){
			if(datos[x].id_j>datos[x-1].id_j){
				 printf("\n====================================\n");
			}
		}
	}
}

void  generar_calendario(int jornada,int dias_min,int dias_max,int tipo_j){
	if(tipo_j==1){
		//es jornada
		for(int x=(9*(jornada-1));x<(jornada*9);x++){
			int ee1=0,ee2=0;
			if(file_exists("juegos.txt")){
				//leer datos del archivo y verificar
				int j1=juegos_asignados();
				Juegos_s *datos;
				datos=leer_juegos();
				printf("jornada %d juego %d registros %d  %d vs %d \n",jornada,x+1,j1,datos[x-1].id_e1,datos[x-1].id_e2);
				//verificamos si el juego a programar es válido
				int seguir=0;
				while(seguir!=1){
					ee1=r_number(1,18);//Equipo 1
					ee2=r_number(1,18);//Equipo 2
					if(ee1!=ee2){
						//no son los mismos equipos randon
						//se deben buscar si el juego ya fue asignado
						int juego_valido=1;
						for(int j=0;j<j1;j++){
							if((datos[j].id_e1==ee1 && datos[j].id_e2==ee2) || (datos[j].id_e1==ee2 && datos[j].id_e2==ee1)) {
								juego_valido=0;
								break;
							}
						}
						for(int j=(9*(jornada-1));j<j1;j++){
							if((datos[j].id_e1==ee1 || datos[j].id_e1==ee2 || datos[j].id_e2==ee1 || datos[j].id_e2==ee2)) {
								juego_valido=0;
								break;
							}
							//buscar si no tienen juego asigando ya en la jornada
						}
						if(juego_valido==1){
							seguir=1;
							break;
						}
					}
				}
				//valido=1;
			}else{
				//crea el primer juego, sin importar cual sea
				ee1=1;ee2=2;
			}
			
				Juegos_s juego;
				juego.id=x+1;
				juego.goles_e1=0;
				juego.goles_e2=0;
				juego.id_e1=ee1;
				juego.id_e2=ee2;
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
#endif  
