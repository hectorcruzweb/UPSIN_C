#include <stdio.h>
#include "hrcp.h"

main(){
	char fecnac[11]={NULL}, matricula[10]={NULL},nombre[25]={NULL},a_pat[25]={NULL},a_mat[10]={NULL};
	int edad=0;
	float est=0.0;
	gotoxy(10,1);
	printf("Matricula: ");
	gotoxy(80,1);
	printf("Fecha de nacimiento:");
	gotoxy(10,4);
	printf("Nombre del alumno:");
	gotoxy(40,4);
	printf("Apellido paterno:");
	gotoxy(80,4);
	printf("Apellido materno:");
	gotoxy(10,7);
	printf("Edad:");
	gotoxy(80,7);
	printf("Estatura:");
	
	
	
	gotoxy(10,2);
	hc_letters(10,matricula);
	gotoxy(80,2);
	valifec(fecnac);
	gotoxy(10,5);
	hc_letters(25,nombre);
	gotoxy(40,5);
	hc_letters(25,a_pat);
	gotoxy(80,5);
	hc_letters(25,a_mat);
	gotoxy(10,8);
	edad=hc_int(3);
	gotoxy(80,8);
	edad=hc_float(4);
	getch();
}



