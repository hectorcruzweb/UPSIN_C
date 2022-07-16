#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Función recursiva, genera el factorial de un número dado.
long long recursiva(int numero)
{
    if (numero == 0)
    	return 1;
    else
    	return (numero * recursiva(numero - 1));
}

main()
{
    int numero;
    unsigned long long int res = 1;
    char opt;
    do {
        //creamos el menú
        system("cls");
        printf("\n*** MENU DE OPERACION *** ");
        printf("\n\n(1) -- Con Recursividad. \n");
        printf("(2) -- Sin Recursividad. \n");
        printf("(3) -- Salir \n");
        printf("\nElija una opcion: ");
        opt = getch();
        if(opt==49 || opt==50){
        	res=1;
        	//eligio 1 o 2
        	printf("\n\nIngrese un numero: ");
		    scanf("%d", &numero);
		    if (numero < 0){
		    	// No aplica para numeros negativos
		    	printf("\n\nNo existen numeros factoriales negativos.");
			}
		    else {
		    	//Se procede con la operación
		        switch (opt) {
			        case 50: {
			        	//si eligió la opción número 1 - Con ciclo
			            for (int x = 1; x <= numero; ++x) {
			            	res *= x;
			            }
			            printf("\n<< Resultado utilizando el ciclo >>");
			            break;
			        }
			        case 49: {
			        	//si eligió la opción número 2 - Con recursividad
			            res=recursiva(numero);
			            printf("\n<< Resultado utilizando recursividad >>");
			            break;
			        }
		        }
		        printf("\n\nEl factorial del numero %d es: %llu", numero, res);
		    }
		    getch();
		}
    } while (opt!=51);
    system("cls");
    printf("Ha elegido la opcion de salir, bye.\n\n\n");
}
