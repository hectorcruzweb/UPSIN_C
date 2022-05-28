/*
Con el uso del getch
Pedir una tecla y que se repita el ciclo do while mientras que no se capture el enter(13)
Filtrar solo numeros y vocales
*/
#include <stdio.h>

#include<conio.h>

#include<windows.h>

void get_character();

main() {
  get_character();
}

void get_character() {
  int n = 0, v = 0, c = 0;
  char car;
  do {
    printf("Captura un caracter: ");
    car = getch();
    printf("%c \n", car);
    //system("cls");
    //esta es para sacar los numeros
    if (car >= 48 && car <= 57) {
      n++;
    } else if (car == 65 || car == 97 || car == 69 || car == 101 || car == 79 || car == 111 || car == 73 || car == 105 || car == 85 || car == 117) {
      //sacamos las vocales
      v++;
    } else if (car >= 97 && car <= 122 || car >= 65 && car <= 90) {
      //sacamos las consonantes
      c++;
    }
    //printf("El caracter es %c \n\n\n\n",car);
  } while (car != 13);
  system("cls");
  printf("Se teclaron %d numeros, %d vocales y %d consonantes %c \n\n\n\n", n, v, c);
}
