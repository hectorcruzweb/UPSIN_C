/*
usar el getch para que mientras no sea el enter siga el ciclo

*/
#include <stdio.h>
#include<conio.h>
#include<windows.h>
#include <stdlib.h>
int fun_pro(int tipo);
main() {
	int res=0;
	printf("Captura una edad: ");
  	res=fun_pro(3);
  	printf("\n\n\n La edad es: %d\n\n", res);
  	
  	printf("Captura el numero de existencia: ");
  	res=fun_pro(10);
  	printf("\n\n\n La existencia es: %d\n\n", res);
}

int fun_pro(int dig=0){
	char car,number[dig]={};
	int pos=0,cant_c=10;
   	do {
	    car = getch();
	    if (car >= 48 && car <= 57) {
	    	if(pos<dig){
	    		number[pos]=car;
	    		pos++;
	    		printf("%c",car);
			}else{
				break;
			}
	    }else if(car==8 && pos>0){
	    		printf("\b \b");
	    		//tecla de retroceso
	    		pos--;
	    		number[pos]=NULL;
		}
  } while (car != 13 && pos<(dig+1));
  
  return atof(number);
}
