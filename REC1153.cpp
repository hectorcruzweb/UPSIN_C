#include <stdio.h>

main() {
	int numvueltas=0,x=0;
	float pro=0.0,tiempo=0.0,tiempomenor=0.0,tiempomayor=0.0;
	printf("Total de vueltas que se dio ");
	scanf("%d",&numvueltas);
	do{
		printf("Tiempos en vuelta ");
		scanf("%f",&tiempo);
		pro+=(tiempo);
		if(x==0)
			tiempomenor=tiempo;
		else if(tiempo<tiempomenor)
			tiempomenor=tiempo;			
		if(tiempo>tiempomayor)
			tiempomayor=tiempo;
		x++;
	}while(x<numvueltas);
	pro=pro/numvueltas;
	
	printf("Tiempo promedio %.2f ",pro);
	printf("Tiempo menor %.2f ",tiempomenor);
	printf("Tiempo mayor %.2f ",tiempomayor);
}
