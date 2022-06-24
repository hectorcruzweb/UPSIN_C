#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>




main() {
	char dato[100]={},newdato[100]={};
	printf("Ingrese la cadena de texto: ");
	scanf("%[^\n]",&dato);
	for(int x=0;x<strlen(dato);x++){
		newdato[x]=dato[x];
	}
	printf("%s",newdato);
}


