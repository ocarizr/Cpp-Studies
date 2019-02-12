#include <stdlib.h>
#include <stdio.h>
#include "functionSum.h"

void main()
{
	int a, b;
	printf("Hello World!\n");
	
	printf("The First number: ");
	scanf("%d", &a);
	
	printf("The Second number: ");
	scanf("%d", &b);
	
	printf("The sum of the numbers: %d\n", SomaNumeros(a, b));
	
	system("pause");
}
