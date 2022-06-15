/*
Ejercicio 4 --> Competencia de atletismo
El comité de atletismo olímpico necesita un programa que genere la lista resultado de la eliminatorias de los 100 mts planos, 
para saber quienes de los 10 competidores representarán a México en los juegos olímpicos de 2024. 
Para ello, se necesita registrar el record del atleta (en seg) según su número durante la prueba de eliminatoria. 
Siendo beneficiados solamente los primeros 2 lugares de velocidad más rápida (sin importar que haya records iguales). 
Al final debe mostrar la lista de los competidores(su número) y velocidad ordenados de menor a mayor velocidad e indicando si está calificado o no.
Como extra, aplicar la prueba a féminas y varones, clasificando 4 records para las féminas.
*/
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>

//1 mujer- 2 hombre
void pruebas(char gender[]){
	float rec_a[10]={NULL};
	int num_a[10]={NULL};
	float temp_rec=0.0;
	int temp_num=0;
	
	/*printf("**INGRESE LOS RESULTADOS DE LA PRUEBA DE %s**\n\n",gender);
	for(int x=0;x<10;x++){
		printf("Record en seg. | Corredor numero %d: ",x+1);
		scanf("%f",&rec_a[x]);
		num_a[x]=x+1;
	}*/
	
	srand(time(NULL));
	for(int x=0;x<10;x++){
		double scaled = (double)rand()/RAND_MAX;
		rec_a[x]=(16.7 - 4.4 +1)*scaled + 4.4;
		num_a[x]=x+1;
	}
	//_Ordenar la lista de mayor al menor del record
	for(int x=0;x<10;x++){
		for(int y=x;y<10;y++){
			if(rec_a[y]<rec_a[x]){
				temp_rec=rec_a[x];
				rec_a[x]=rec_a[y];
				rec_a[y]=temp_rec;
				//acomodando numeros
				temp_num=num_a[x];
				num_a[x]=num_a[y];
				num_a[y]=temp_num;
			}
		}
	}
	//determinar cuales son los dos tiempos calificados para ir al torneo
	int max_lugar=1;
	float valid_record=rec_a[0];
	for(int x=1;x<10;x++){
		if(rec_a[x]>valid_record){
			valid_record=rec_a[x];
			max_lugar++;
		}
		if(strcmp(gender,"FEMINAS")==0){
			if(max_lugar==4){
				break;
			}
		}else{
			if(max_lugar==2){
				break;
			}
		}
		
	}
	printf("\n\n\n***ATLETAS (%s) CALIFICADOS A JUEGOS OLIMPICOS 2024***\n\n",gender);
	for(int x=0;x<10;x++){
		if(rec_a[x]<=valid_record){
			printf("Atleta #%d, Record %.2f (seg), -> Calificado \n",num_a[x],rec_a[x]);
		}else{
			printf("Atleta #%d, Record %.2f (seg), No Calificado \n",num_a[x],rec_a[x]);
		}
	}
}

main() {
	pruebas("FEMINAS");
	getch();
	pruebas("VARONES");
}


