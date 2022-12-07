/* YaSaDog, 7.12.2022 */

#include <stdio.h>

#include "C01_QUAD.h"


void main(void)
{
	float a, b, c;
	printf("C01_QUAD\nQuadratic equations solver\nax^2 + bx + c = 0\n");

	printf("a = ");
	scanf("%f", &a);

	printf("b = ");
	scanf("%f", &b);

	printf("c = ");
	scanf("%f", &c);

	solveQuadratic(a, b, c);

	getchar();
	getchar();
}