#include <stdio.h>
#include <stdlib.h>
int main()
{
	int mas[100] = {0};
	int i,num,a,max=0,last_pos=0,sum=0;
	printf("input number of numbers in arrey");
	scanf_s("%d",&num);
	if (num < 1 || num>100 || num % 1 != 0)
	{
		printf("wrong input");
		return 0;
	}
	printf("press 1 to input random numbers \n press 2 to input numbers yourself");
	scanf_s("%d",&a);
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
		if (mas[i] > max)
			max = mas[i];
	}
	for (i = 0; i < num; i++)
	{
		if (mas[i] > 0)
		{
			last_pos = i;
		}
	}
	for (i = 0; i < last_pos;i++)
	{
		sum = sum + mas[i];
	}
	printf("%d, %d", max,sum);
	return 0;
}