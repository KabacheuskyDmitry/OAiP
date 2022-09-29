#include <stdio.h>
#include <stdlib.h>
int main()
{
	int masA[100] = { 0 }, masB[100] = { 0 }, masAB[200] = {0};
	int i=0, num, a,b, n, rnd, between;
	printf("input number of numbers in arrey");
	scanf_s("%d", &num);
	if (num < 1 || num>100||num%1!=0)
	{
		printf("wrong input");
		return 0;
	}
	printf("press 1 to input random numbers \n press 2 to input numbers yourself");
	scanf_s("%d", &a);
	n = num;
	switch (a)
	{
	case 1:
	{
		masA[i] = rand();
		for (i = 1; i < num; i++)
		{
			for (int fl=0; fl != 1;)
			{
				rnd = rand();
				if (masA[i - 1] < rnd)
				{
					masA[i] = rnd;
					fl = 1;
				}
			}
		}
		break;
	}
	case 2:
	{
		i = 0;
		printf("mas[%d]= \n", i);
		scanf_s("%d", &masA[i]);
		for (i = 1; i < num; i++)
		{
			printf("mas[%d]= \n", i);
			scanf_s("%d", &masA[i]);
			if (masA[i] % 1 != 0)
			{
				printf("wrong input");
				return 0;
			}
			if (masA[i - 1] >masA[i])
			{
				printf("wrong input");
				return 0;
			}
		}
		break;
	}
	default:
		printf("wrong input");
		return 0;
	}
	printf("press 1 to input random numbers \n press 2 to input numbers yourself");
	scanf_s("%d", &b);
	switch (b)
	{
	case 1:
	{
		i = 0;
		masB[i] = rand();
		for (i = 1; i < num; i++)
		{
			for (int fl = 0; fl != 1;)
			{
				rnd = rand();
				if (masB[i - 1] > rnd)
				{
					masB[i] = rnd;
					fl = 1;
				}
			}
		}
		break;
	}
	case 2:
	{
		i = 0;
		printf("mas[%d]= \n", i);
		scanf_s("%d", &masB[i]);
		for (i = 1; i < num; i++)
		{
			printf("mas[%d]= \n", i);
			scanf_s("%d", &masB[i]);
			if (masB[i] % 1 != 0)
			{
				printf("wrong input");
				return 0;
			}
			if (masB[i - 1] < masB[i])
			{
				printf("wrong input");
				return 0;
			}
		}
		break;
	}
	default:
		printf("wrong input");
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		masAB[i] = masA[i];
	}
	for (i = n; i < 2*n; i++)
	{
		masAB[i] = masB[i-n];
	}
	i = 0;
	for (int j = 0; j <= 2 * n; j++)
	{
		for (int i = 0; i < 2 * n; i++)
		{
			if (masAB[i + 1] < masAB[i])
			{
				between = masAB[i];
				masAB[i] = masAB[i + 1];
				masAB[i + 1] = between;
			}
		}
	}
	for (int start = 0; start < 2 * n; start++)
	{
		masAB[start] = masAB[start+1];
	}



	for (i = 0; i < 2*num; i++)
	{
		printf("%d \n", masAB[i]);
	}
	return 0;
}