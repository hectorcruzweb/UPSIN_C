#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "hrcp.h"

int buscar(float dato[],int tope, float num,int ini){
	if(dato[ini]==num)
		return ini;
	if(ini>=tope)
		return -1;
	else 
		return buscar(dato,tope,num,ini+1);
}

main(){
	float nums[]={1.1,1.24,3.4,4.3,2.6,7.6,5.7};
	int inicio=0,limite=6;
	float val=0;
	printf("Ingrese el valor: ");
	val=hc_float(5);
	int res=buscar(nums,limite,val,inicio);
	if(res==-1)
		printf("\nNo existe el valor");
	else
		printf("\n%d",res);
	getch();
}
