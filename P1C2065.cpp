#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void hc_text(int lon, char* pnom)
{
    if (lon <= 0) {
        return;
    }
    //c>=65 && c<=90 may
    //c>=97 && c<=122 min
    //c==32 espace
    //c==164 ñ min
    //c==165 Ñ may
    int c = 0, x = 0;
    do {
        c = getch();
        if (c != 8 && c != 13) {
            if (x < lon) {
                printf("%c", c);
                *(pnom + x) = c;
                x++;
            }
        }
        else if (c == 8 && x > 0) {
            x--;
            printf("\b \b");
            *(pnom + x) = '\0';
        }
    } while (c != 13);
}




void concatenar(char* destino,char* origen, int pos){
	//destino => texto 1
	//origen => texto 2
	//strcat(destino,origen);
	if(pos>=strlen(origen)){
		//origen => jose
		return;
	}else{
		destino[strlen(destino)]=origen[pos];
		concatenar(destino,origen,pos+1);
	}
	return;
}



main()
{
    char opt;
    do {
        //crear un menu con la opcion de con recursividad y sin recursividad y la opcion salir
        //ASCII
        /*
        1-49
        2-50
        3-51
		*/
		system("cls");
		printf("1- Con recursividad\n");
		printf("2- Sin recursividad\n");
		printf("3- Salir del programa\n\n");
		printf("Seleccione 1 opcion:");
		opt=getch();
		char texto1[40]={'\0'};
		char texto2[40]={'\0'};
		
		if(opt==49 || opt==50){
			printf("\nIngrese la cadena 1: ");
			hc_text(40,texto1);
			printf("\nIngrese la cadena 2: ");
			hc_text(40,texto2);
			//quiere decir que el usuario eligio una opcion valida
			switch(opt){
				case 49:{
					//eligio el valor numero 1
					printf("\nLlamamos a la funcion recursiva");
					concatenar(texto1, texto2,0);
					break;
				}
				case 50:{
					//eligio el valor 2
					//ciclo para concatenar las variables
					//texto2 => 40, pedro  strlen 
					//strcat(variable1,variable2);
					for(int x=0;x<strlen(texto2);x++){
						//texto 1 = "Hola "
						//texto 2 = "jose"
						//"H" => 0, o =>1, l=>2, a=>3 " " =>4
						texto1[strlen(texto1)]=texto2[x];	
					}
					
					break;
				}
			}
			printf("\n\n\nResultado %s",texto1);
				getch();
		}
    } while (opt != 51);
    system("cls");
    printf("Ha elegido la opcion de salir, bye.\n\n\n");
}
