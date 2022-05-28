/*
PR - 12 DE MAYO 2022 / Ejemplo 4
Capturar los 3 �ngulos de un tri�ngulo, mostrando por pantalla
el tipo de tri�ngulo que es. De acuerdo a lo siguiente:
la suma de los 3 �ngulos debe ser 180�
Tri�ngulo equilatero > 3 �ngulos iguales
Tri�ngulo isoceles > 2 �ngulos iguales y 1 diferente
Tri�ngulo ecaleno > 3 �ngulos diferentes
*/
#include <stdio.h>
#include<conio.h> 

main() {
	float a1=0,a2=0,a3=0,tot=0;
	printf("Ingrese el Angulo 1:" );
	scanf("%f",&a1);
	printf("Ingrese el Angulo 2: ");
	scanf("%f",&a2);
	printf("Ingrese el Angulo 3: ");
	scanf("%f",&a3);
	tot=a1+a2+a3;
	if(tot!=180){
		printf("La captura de angulos no es valida, por lo tanto no es un triangulo");
	}else{
		if(a1==a2 && a2==a3){
			printf("Es un triangulo equilatero");
		}else  if(a1==a2 || a1==a3 || a2==a3) {
			printf("Es un triangulo isosceles");
		}else{
			printf("Es un triangulo Escaleno");
		}
	}
}
