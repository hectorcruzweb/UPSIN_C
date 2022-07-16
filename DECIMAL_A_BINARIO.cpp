#include "stdio.h"
main()
{
	int n, bin[100];
	int i = 0;
	printf ("Ingrese el numero decimal: ");
	scanf("%d", &n);
	while (n>0)
	{
		bin[i] = n % 2;
		i = i + 1;
		n = n / 2;
	}
	for (i--; i >= 0; i--)
		printf("%d", bin[i]);
	printf("\n");
}
