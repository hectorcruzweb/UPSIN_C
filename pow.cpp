
#include <stdio.h>

float potencia(float num,float pot){
	if(pot==0)return 1;
	return num*potencia(num,pot-1);
}

main() {
	/*float n=2,result=1;
	int pow=6;
  	for(int x=pow;x>0;x--){
  		result*=n;
	}*/
  printf("%.2f",potencia(2,5));
}

