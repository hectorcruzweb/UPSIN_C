/*
Ejercicio 2 --> Papelería escolar
La papeleria ABC quiere controlar las ventas por concepto de engargolado de manuales a un precio de $25.00 a sus clientes, 
dando un descuento los dias jueves y viernes del 15% sobre el total de la venta. 
Al final requiere hacer el corte de caja y saber cuanto se ganó y cuanto dejó de percibir por concepto de descuento.
*/
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

/*
Ascii Codes
1 -49
2- 50
3- 51
4- 52
5- 53
*/

main() {
	int cant=0;
	float total_v=0.0,total_d=.0;
	char opt,day;
	printf("\nElija el dia de la semana");
	printf("\n\n(1) -- Lunes \n");
	printf("(2) -- Martes \n");
	printf("(3) -- Miercoles \n");
	printf("(4) -- Jueves \n");
	printf("(5) -- Viernes \n\n");
	do{
		printf("Dia de la semana: ");
		day=getch();
		if(day<49 || day>53){
			printf("\r");
		}
	}while(day<49 || day>53);
	

	do{
		system("cls");
		printf("Menu de usuarios ");
		printf("\n\n(1) -- Vender \n");
		printf("(2) -- Corte de caja \n");
		printf("\nSeleccione la operacion: ");
		opt=getch();
		if(opt==49){
			//vender
				printf("\n\nCantidad de manuales: ");
				scanf("%d",&cant);
				if(day==52 || day==53){
					//aplica descuento;
					total_v=total_v+(cant*25*.85);
					total_d=total_d+(cant*25*.15);
				}else{
					total_v=total_v+(cant*25);
				}
				printf("\n\n*******Se imprime ticket*******");
				getch();
		}else if(opt==50){
			//imprimir corte de caja y listo
			system("cls");
			printf("Corte de caja \n\n");
			printf("$Total de venta: %.2f\n",total_v);
			printf("$Total descontado: %.2f\n",total_d);
		}
	}while(opt==49 || (opt>50 || opt<49));
}


