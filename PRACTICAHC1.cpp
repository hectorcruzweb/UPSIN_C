/*
Ejercicio 1 -> Calculadora
Realizar un programa que permita al usuario ingresar dos números y en base a un menú de opciones (sumar, restar, dividir y multiplicar), 
permitirle elegir la operación a realizar con los números capturados. El programa debe seguir funcionando siempre y 
cuando el usuario no elija la opción de salir.
*/
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

/*
Ascii Codes
1 - 49
2- 50
3- 51
4- 52
5- 53
*/

main() {
	float n1=0.0,n2=0.0,res=0.0;
	char c;
	int res_valido=1;
	do{
		system("cls");
		printf("*** CALCULADORA UPSIN TCI 3-2 *** \n\n");
		printf("\n*** MENU DE OPERACIONES *** ");
		printf("\n\n(1) -- Sumar \n");
		printf("(2) -- Restar \n");
		printf("(3) -- Dividir \n");
		printf("(4) -- Multiplicar \n");
		printf("(5) -- Salir \n\n");
		do{
			printf("Elija una opcion del menu: ");
			c=getch();
			if(c>53 || c<49){
				printf("\r");
			}
		}while(c>53 || c<49);
		if(c==53){
			continue;
		}
		
		printf("\n\nIngrese el numero 1: ");
		scanf("%f",&n1);
		printf("Ingrese el numero 2: ");
		scanf("%f",&n2);
		
		res_valido=1;
		if(c==49){
			//sumar
			res=n1+n2;
		}else if(c==50){
			//restar
			res=n1-n2;
		}else if(c==51){
			//dividir
			if(n2==0){
				res_valido=0;
				printf("\nError matematico.");
			}else{
				res=n1/n2;
			}
		}else if(c==52){
			//multiplicar
			res=n1*n2;
		}else{
			res_valido=0;
		}
		if(res_valido==1){
			printf("\n\nEl resultado es: %.2f",res);
		}
		getch();
	}while(c!=53);
}


