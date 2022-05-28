/*
Hacer un programa que capture y 
calcule el promedio de estatura de 
una cierta cantidad de un grupo.
*/

#include <stdio.h>
#include<conio.h>
#include<windows.h>

main() {
  int alu = 0,gru=0;
  float est = 0.0, pro = 0.0,pro_g=0.0,proma=0.0,prome=0.0;
  
  printf("Ingrese el numero de grupos: ");
  scanf("%d", & gru);
  printf("\n\n\n");
  
   for (int y = 1; y <= gru; y++) {
	  printf("Ingrese el numero de alumnos del grupo %d:",y);
	  scanf("%d", & alu);
	  pro=0;
	  printf("\n\n\n");
	  for (int x = 1; x <= alu; x++) {
	    printf("Ingrese la estatura del alumno  %d del grupo %d :", x,y );
	    scanf("%f", & est);
		pro = pro + (est / alu);
	  }
	  //saco el promedio menor
	  if(prome==0){
	  	prome=pro;
	  }else if(pro<prome){
	  	prome=pro;
	  }
	  //saco el prom mayor
	  if(pro>proma){
	  	proma=pro;
	  }
	  printf("\n\n El promedio del grupo %d de estatura de estos %d alumnos es %.2f \n\n\n", y,alu, pro);
  }
  printf("\n\n El promedio mayor es %.2f y el promedio menor es %.2f \n\n\n", proma,prome);

  //system("cls");
}
