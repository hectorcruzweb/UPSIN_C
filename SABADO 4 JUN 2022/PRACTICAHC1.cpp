/*
Ejercicio 1 -> Calculadora
Realizar un programa que permita al usuario ingresar dos n�meros y en base a un men� de opciones (sumar, restar, dividir, multiplicar y salir), 
permitirle elegir la operaci�n a realizar con los n�meros capturados. El programa debe seguir funcionando siempre y 
cuando el usuario no elija la opci�n de salir.
*/
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "../hrcp.h";
/*
Ascii Codes
1 - 49
2- 50
3- 51
4- 52
5- 53
*/



main() {
	// declaraci�n de variables
	//n1= numero 1, n2=  numero 2, res= resultado de la operacion
	float n1=0.0,n2=0.0,res=0.0;	
	char car;
	
	
	do{
		//creamos el men�
		system("cls");
		printf("*** CALCULADORA UPSIN TCI 3-2 *** \n\n");
		printf("\n*** MENU DE OPERACIONES *** ");
		printf("\n\n(1) -- Sumar \n");
		printf("(2) -- Restar \n");
		printf("(3) -- Dividir \n");
		printf("(4) -- Multiplicar \n");
		printf("(5) -- Salir \n\n");
		//guardamos la opcion del usuario
		//validar la opci�n del usuario
		do{
			printf("Elija una opcion del menu del 1 al 5: ");
			car=getch();
			printf("%c",car);
			if(car>53 || car<49){
				printf("\r");	
			}
		}while(car>53 || car<49);
		
		if(car==53){
			//la opcion elegida fue salir, por lo tanto deberia de no continuar con el ingreso de los numeros
			break;
		}
		
		
		printf("\n\nIngrese el numero 1: ");
		//scanf("%f",&n1);
		n1=hc_float(7);
		printf("\nIngrese el numero 2: ");
		//scanf("%f",&n2);
		n2=hc_float(7);
		/*
		Ascii Codes
		1 - 49
		2- 50
		3- 51
		4- 52
		5- 53
		*/
		int res_valido=1;//resultado v�lido
		if(car==49){
			//sumar
			res=n1+n2;
		}else if(car==50){
			//restar
			res=n1-n2;
		}else if(car==51){
			//dividir
			if(n2==0){
				//error matem�tico -> infinito
				res_valido=0;
			}else{
				res=n1/n2;
			}
		}else if(car==52){
			//multiplicar
			res=n1*n2;
		}
		if(res_valido==1){
			printf("\n\n\nResultado: %f",res);
		}else{
			printf("\nError matematico al dividir por 0");
		}
		getch();
	// el ciclo funcionar� mientras el usuario no elija la opci�n (5) Salir (53 ascii)
	}while(car!=53);
}


