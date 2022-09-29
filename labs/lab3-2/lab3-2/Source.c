#include <stdio.h>
#include <stdlib.h>
int main()
{
	int mas[100] = { 0 };
	int i, num, a,n;
	printf("input number of numbers in arrey");
	scanf_s("%d", &num);
	if (num < 1 || num>100 || num%1 != 0)
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
		for (i = 0; i < num; i++)
		{
			mas[i] = rand();
		}
		break;
	}
	case 2:
	{
		for (i = 0; i < num; i++)
		{
			printf("mas[%d]= \n", i);
			scanf_s("%d", &mas[i]);
			if (mas[i]%1!=0)
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
	for (i = 0; i < num; i++)
	{
		if (mas[i] < 0)
		{
			num = num + 1;
			for (int end=n*2;end >= i; end--)
			{
				mas[end+1] = mas[end];
			}
			i = i + 1;
		}
	}
	for (i = 0; i < num; i++)
	{
		printf("%d \n",mas[i]);
	}
	return 0;
}