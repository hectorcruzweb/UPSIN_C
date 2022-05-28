#include <stdio.h>
#include<conio.h>
#include<stdlib.h>

int buscar(float num);
main() {
  float data = 0.0;
  printf("Ingrese el numero: ");
  scanf("%f",&data);
  //system("cls");
  int res=buscar(data);
  res>=0?printf("\n\n El numero  %0.2f esta en posicion %d. \n\n\n", data, res):printf("Numero no encontrado \n\n\n");
  /*
  if(buscar(data)>=0){
  	printf("\n\n El numero  %0.2f esta en posicion %d. \n\n\n", data, buscar(data));
  }
  else{
  	printf("Numero no encontrado \n\n\n");
  }
  */
}


int buscar(float num) {
  float arr[] = {
    1.1,
    2.4,
    3.3,
    10.0,
    0.36,
    6.6,
    23.36,
    45.9,
    87.5,
    25.6
  };
  for (int x = 0; x < 10; x++) {
    if (arr[x] == num) {
      return x;
    }
  }
  //no enontro nada y retorno esto para saber que no se encontró
  return -1;
}
