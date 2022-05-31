#include <stdio.h>
#include "hrcp.h"
main()
{
	float val=0.0;
	printf("Ingrese un numero float: ");
	val=hc_float(7);
	printf("\n\n\n%.2f",val);
	
	
	int res=0;
	printf("Ingrese un numero int: ");
	res=hc_int(7);
	printf("\n\n\n%d",res);
}
