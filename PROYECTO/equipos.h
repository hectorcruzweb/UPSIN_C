#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include <time.h>
#include "hrcp.h"
#include "jornadas.h"
#define tdj 17
#define total_juegos_j tdj* jpj
#ifndef equipos  
#define equipos  
int tde=18;

FILE* f_equipos;

struct Equipos {
    int id;
    int puntos;
    int goles_anotados;
    int empates;
    int goles_recibidos;
    char nombre[30];
    int status;
};

Equipos *leer(char *filename,int *total){
	f_equipos=fopen(filename,"rb");
	if (f_equipos == NULL) {
        printf("error opening file !\n");
        exit(1);
    }
    if(fread(total,sizeof(int),1,f_equipos)!=1){
    	printf("No se han podido leer los %d datos.\n",1);
    	exit(1);
	}
	Equipos *datos=(Equipos *)malloc(sizeof(Equipos) * *total);
	if(fread(datos,sizeof(Equipos),*total,f_equipos)!=*total){
		printf("No se han podido leer los %d datos.\n",tde);
		free(datos);
    	exit(1);
	}
	if (fclose(f_equipos)==EOF){
		printf("No se ha podido cerrar el fichero.\n");
		free(datos);
		exit(1);
	}
	return datos;
}

void comenzar_torneo()
{
	if(file_exists("equipos.txt")){
		// se pregunta si se puede
		if(yes_no("YA EXISTE UN TORNEO EN CURSO, REINICIAR EL TORNEO? ",0,0,1,0)==2){
			return;	
		}
		//borramos todos los archivos y comenzamos nuevamente
		rm("equipos.txt");
		rm("tipos.txt");
		rm("jornadas.txt");
		rm("juegos.txt");
	}
    //Generar Equipos de la liga
    char lista_equipos[18][50] = { 
	"America", 
	"Atlas", 
	"Atletico San Luis", 
	"Cruz Azul", 
	"Chivas", 
	"Juarez FC", 
	"Leon", 
	"Monterrey", 
	"Mazatlan", 
	"Necaxa", 
	"Pachuca", 
	"Puebla", 
	"Pumas", 
	"Queretaro", 
	"Santos Laguna", 
	"Tigres", 
	"Toluca", 
	"Xolos de Tijuana"
	};
	
	int res;
    do {
        system("cls");
        main_s();
        last_y=3;
        text_x("*** LISTA DE EQUIPOS ***",27,last_y);last_y+=2;
        text_x("CLAVE",15,last_y);
        text_x("EQUIPO",35,last_y);
        for (int index = 0; index < tde; index++) {
        	last_y=7+index;
        	sprintf(ti, "%d", (index+1));text_x(ti,15,last_y);//clave
        	text_x(lista_equipos[index],35,last_y);//dato
		}
		last_y=6;
		res=yes_no("Modificar equipos participantes?",75,8,0,1);
		if(res==3){
			return;
		}
		if(res==1){
			//pedir nuevo equipo
			text_x("Capture el id del equipo:",72,20);
			int id=hc_int(2);
			if(id>=1 && id<=18){
				//pedir el nuevo nombre
				text_x("Nuevo nombre del equipo:",74,22);
				gotoxy(62,24);
				char nombre[30]={'\0'};
				hc_letters(25,nombre);
				char temp1[30]={'\0'};
				char temp2[30]={'\0'};
				int valido=1;
				for(int x=0;x<tde;x++){
						strcpy(temp1,lista_equipos[x]);
						strcpy(temp2,nombre);
						hc_toupper(temp1);
						hc_toupper(temp2);
						if(strcmp(temp1,temp2)==0 && id!=(x+1)){
							valido=0;
							text_x("Error, este equipo ya esta registrado.",75,26);
							getch();
							break;
						}
				}
				if(valido==1){
					strcpy(	lista_equipos[id-1],nombre);
				}
			
			}else{
				text_x("Ingrese un ID valido.",74,22);
				getch();
			}
		}
    } while (res==1);
	Equipos e_equipos[tde];
	int x = 0;
    do {
        int num_e = r_number(1, tde);
        for (int index = 0; index < tde; index++) {
        	if( e_equipos[index].id!=NULL){
        		if (num_e == e_equipos[index].id) {
	                //El quipo ya está
	                num_e = -1;
	                break;
            	}
			}
        }
        if (num_e != -1) {
            //asignamos equipo
            strcpy(e_equipos[x].nombre, lista_equipos[num_e - 1]);
            e_equipos[x].id = num_e;
            e_equipos[x].puntos = 0;
            e_equipos[x].goles_anotados = 0;
            e_equipos[x].empates = 0;
            e_equipos[x].goles_recibidos = 0;
            e_equipos[x].status = 1;
            x++;
        }
    } while (x < tde);
    f_equipos = fopen("equipos.txt", "wb");
    if (f_equipos == NULL) {
        printf("error opening file !\n");
        exit(1);
    }
    if(fwrite(&tde,sizeof(int),1,f_equipos)!=1){
    	printf("No se han escrito los %d datos.\n",tde);
    	exit(1);
	}
    if(fwrite(e_equipos, sizeof(Equipos), tde, f_equipos)!=tde){
    	printf("No se ha podido escribir el fichero.\n");
		exit(1);
	}
	if (fclose(f_equipos)==EOF){
		printf("No se ha podido cerrar el fichero.\n");
		exit(1);
	}
	system("cls");
	//Creamos los archivos para las jornadas y juegos
	crear_files_juegos_jornadas();
	main_s();
	text_center("<<< SE HA INICIADO UN NUEVO TORNEO >>>",14);
	getch();
}

void tabla_general(){
	Equipos *datos;
	datos=leer("equipos.txt",&tde);
	if(datos==NULL){
		printf("No se han podido leer los datos.\n");
		exit(1);
	}
	main_s();
	text_center("*** TABLA GENERAL DEL TORNEO ***",4);
	
	for(int x=0;x<tde;x++){
		text_center(("ok %s",datos[x].nombre),4+x+2);
		last_y=4+x+2+2;
	}
	
	text_center("<<< PRESIONE UNA TECLA PARA CONTINUAR >>>",last_y);
	getch();
}



#endif  
