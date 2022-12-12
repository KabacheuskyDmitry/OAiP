#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
	int** pointer;
	int line, i, j, * size, a,buffer, k;
	printf("input amountcy of lines in the arrey");
	scanf_s("%d", &line);
	while (line < 1 || line>100 || line % 1 != 0 || getchar() != '\n')
	{
		printf("wrong input");
		rewind(stdin);
		scanf_s("%d ", &line);
	}

	pointer = (int**)malloc(line * sizeof(int));
	size = (int*)malloc(line * sizeof(int));
	printf("press 1 to input random numbers\npress 2 to input numbers yourself");
	scanf_s("%d", &a);
	while (getchar() != '\n')
	{
		printf("wrong input");
		rewind(stdin);
		scanf_s("%d", &a);
	}
	for (int stop = 0;stop != 1;)
	{

		switch (a)
		{
		case 1:
		{

			for (i = 0; i < line; i++)
			{
				printf("input amountcy of numbers in this line");
				while (scanf_s("%d", &size[i]) != 1 || getchar() != '\n')
				{
					printf("wrong input \n");
					rewind(stdin);
				}
				pointer[i] = (int*)malloc(size[i] * sizeof(int));
				for (j = 0;j < size[i];j++)
				{
					pointer[i][j] = rand() % 201 - 100;
				}
			}
			printf("your arrey");
			for (i = 0; i < line; i++)
			{
				for (j;j < size[i];j++)
				{
					printf("%5d ", pointer[i][j]);
				}
			}
			printf("\n");
			stop = stop + 1;
			break;
		}
		case 2:
		{
			for (i = 0; i < line; i++)
			{
				printf("input amountcy of numbers in this line");
				while (scanf_s("%d", &size[i]) != 1 || getchar() != '\n')
				{
					printf("wrong input \n");
					rewind(stdin);
				}
				pointer[i] = (int*)malloc(size[i] * sizeof(int));
				for (j = 0; j < size[i]; j++)
				{
					printf("mas[%d][%d]=", i, j);
					while (scanf_s("%d", &pointer[i][j]) != 1 || getchar() != '\n')
					{
						printf("wrong input \n");
						rewind(stdin);
					}
				}
				printf("\n");
			}
			stop = stop + 1;
			break;
		}
		default:
			printf("wrong input, try again\n");
			rewind(stdin);
			printf("press 1 to input random numbers\npress 2 to input numbers yourself");
			scanf_s("%d", &a);
		}
	}
	printf("how a lot times you want to move numbers to left? \n");
	scanf_s("%d", &k);
	for (i = 0; i < line; i++)
	{
		for (int counter = 0;counter < k;counter++)
		{
			j = 0;
			buffer = pointer[i][j];
			for (j = 0;j <size[i];j++)
			{
				if (j == size[i]-1)
				{
					pointer[i][size[i]-1] = buffer;
				}
				else
				{
					pointer[i][j] = pointer[i][j + 1];
				}
			}

		}
	}

	for (i = 0; i < line; i++)
	{
		for (j = 0; j < size[i]; j++)
		{
			printf("%5d", pointer[i][j]);
		}
		printf("\n");
	}
	return 0;
}
