/* YaSaDog, 7.12.2022 */

#include <math.h>

#include "C01_QUAD.h"


float Discriminant(float a, float b, float c)
{
	return b * b - 4 * a * c;
}

void solveQuadratic(float a, float b, float c)
{
	if (a == 0)
	{
		if (b == 0)
			if (c == 0)
				printf("Solution is any number\n");
			else
				printf("No solutions\n");
		else
			printf("x = %.2f", -c / b);
	}
	else
	{
		float d = Discriminant(a, b, c);
		 
		if (d < 0)
			printf("No solutions\n");
		else
		{
			float sqrD = sqrtf(d);
			float x1 = (-b + sqrD) / (2 * a);
			if (d == 0)
				printf("x = %.2f", x1);
			else
				printf("x1 = %.2f, x2 = %.2f", x1, (-b - sqrD) / (2 * a));
		}
	}
}