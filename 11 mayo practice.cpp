/*
Ingrese 2 eades y muestre el promdedio de esas dos edades
*/
#include <stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>  
#include<ctype.h>  

main() {
	int age1=0,age2=0,i=0;
	float ave=0;
	char rep[]={};
	//for(int x=1;x<=5;x++){
	do{
		printf("Ingrese la edad 1:" );
		scanf("%d",&age1);
		printf("Ingrese la edad 2: ");
		scanf("%d",&age2);
		ave=float (age1+age2)/2;
		printf("El promedio es :%.2f \n\n\n\n",ave);	
		//printf("Press ENTER key to Continue\n");  
		//getch();
		//system("cls");
		do{
			printf("Repetir la lectura de edades S/N: ");
			scanf("%s",&rep);
			while(rep[i]) { 
				rep[i]=toupper(rep[i]); 
			    i++; 
	    	}
			//Sleep(3000); // Sleep three seconds    
			//convert all charracters tu upper
		}while((strcmp("SI",rep)!=0 && strcmp("S",rep)!=0) || (strcmp("NO",rep)!=0 && strcmp("N",rep)!=0));
		system("cls");
		// 
	}while(strcmp("SI",rep)==0 || strcmp("s",rep)==0);		
	//}
}
