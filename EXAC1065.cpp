/*
Cinco miembros de un club contra la obesisdad desean saber cuánto han bajado o subido de
peso desde la última vez que se reunieron. Para esto de debe realizar un ritual de pesaje en
donde cada uno se pesa en diez básculas distintas para asi tener el promedio más exacto de su peso.
Si existe diferencia positiva significa que subieron de peso. Pero si la diferencia es negativa, significa
que bajaron. Lo que el problema requiere es que por cada persona se imprima un letrero que diga: "SUBIO" o "BAJÓ" 
y la cantidad de kilos que subió o bajó de peso.
*/
#include <stdio.h>

main() {
  float pro_anterior = 0.0, pro_actual = 0.0, peso_anterior = 0.0, peso_actual = 0.0, dif = 0.0;
  for (int x = 1; x <= 5; x++) {
    printf("****AMIGO NUMERO  %d *****\n", x);
    printf("---- PESO ANTERIOR -----\n");
    pro_anterior = 0.0;
    pro_actual = 0.0;
    for (int y = 1; y <= 10; y++) {
      printf("Peso anterior en bascula %d: ", y);
      scanf("%f", & peso_anterior);
      pro_anterior += (peso_anterior / 10);
    }
    printf("\n ---- PESO ACTUAL -----\n");
    for (int y = 1; y <= 10; y++) {
      printf("Peso actual en bascula %d: ", y);
      scanf("%f", & peso_actual);
      pro_actual += (peso_actual / 10);
    }
    dif = pro_actual - pro_anterior;
    printf("\n\n");
    if (dif == 0) {
      printf("---- No subio ni bajo de peso. ------");
    } else {
      if (dif > 0) {
        printf("***** Subio %.2f KG. *****", dif);
      } else {
        dif = dif * (-1);
        printf("***** Bajo %.2f KG. *****", dif);
      }
    }
    printf("\n\n\n");
  }
}
