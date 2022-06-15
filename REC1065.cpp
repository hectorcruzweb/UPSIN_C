/*
En un autódromo, calcular el promedio de tiempo, en el que el auto da vueltas.
Mostrar tambien el tiempo mayor y el tiempo menor.
*/
#include <stdio.h>

main() {
	int vueltas=0;
	float pro=0.0,menor=0.0,mayor=0.0,tiempo=0.0;
	printf("Numero de vueltas que dio el auto: ");
	scanf("%d",&vueltas);
	for(int x=1;x<=vueltas;x++){
		printf("Tiempo en vuelta %d:",x);
		scanf("%f",&tiempo);
		pro+=(tiempo/vueltas);
		if(x==1){
			menor=tiempo;
		}else{
			if(tiempo<menor){
				menor=tiempo;
			}
		}
		if(tiempo>mayor){
			mayor=tiempo;
		}
	}
	printf("\nTiempo promedio %.2f:",pro);
	printf("\nTiempo menor %.2f:",menor);
	printf("\nTiempo mayor %.2f:",mayor);
}

