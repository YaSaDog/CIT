/* YaSaDog, 7.12.2022 */

#include <stdio.h>
#include <math.h>

#include "C01_QUAD.h"

void UnitTest(char *FileName)
{
	float a, b, c, rootsNum, correctRootsNum, x1 = 0, x2 = 0, correctX1, correctX2;
	int cnt;
	int flag = 0;

	FILE *F;
	if ((F = fopen(FileName, "r")) == NULL)
	{
		printf("File error\n");
		return;
	}

	cnt = 0;
	while (!feof(F))
	{
		fscanf(F, "%f", &a);
		fscanf(F, "%f", &b);
		fscanf(F, "%f", &c);

		fscanf(F, "%f", &correctRootsNum);
		fscanf(F, "%f", &correctX1);
		fscanf(F, "%f", &correctX2);

		solveQuadratic(a, b, c, &rootsNum, &x1, &x2);
		
		if (rootsNum == correctRootsNum && x1 == correctX1 && x2 == correctX2)
			printf("  Test %i: OK\n", cnt);
		else
		{
			printf("  Test %i: FAIL\n", cnt);
			flag++;
		}

		cnt++;
	}

	if (flag == 0)
		printf("OK: Tests are passed\n");
	else
	{
		printf("!FAIL: Tests are not passed\n");
		exit(1);
	}

	fclose(F);
}

float Discriminant(float a, float b, float c)
{
	return b * b - 4 * a * c;
}

/* Function for user purposes */
void solveQuadEq(float a, float b, float c)
{
	int rootsNum;
	float x1, x2;

	solveQuadratic(a, b, c, &rootsNum, &x1, &x2);

	if (rootsNum == 0)
		printf("No solutions\n");
	else if (rootsNum == 1)
		printf("x = %f\n", x1);
	else
		printf("x1 = %f; x2 = %f\n", x1, x2);
}


void solveQuadratic(float a, float b, float c, float *rootsNum, float *x1, float *x2)
{
	if (a == 0)
	{
		if (b == 0)
			if (c == 0)
				*rootsNum = -1;
			else
				*rootsNum = 0;
		else
		{
			*rootsNum = 1;
			*x1 = -c / b;
			*x2 = *x1;
		}
	}
	else
	{
		float d = Discriminant(a, b, c);
		 
		if (d < 0)
			*rootsNum = 0;
		else
		{
			float sqrD = sqrtf(d);
			float _x1 = (-b - sqrD) / (2 * a);
			if (d == 0)
			{
				*rootsNum = 1;
				*x1 = _x1;
				*x2 = *x1;
			}
			else
			{
				*rootsNum = 2;
				*x1 = _x1;
				*x2 = (-b + sqrD) / (2 * a);
			}
		}
	}
}