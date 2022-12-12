#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
	int** pointer;
	int line, row, i, j, * size, num, buffer,a;
	printf("input amountcy of lines in the arrey");
	scanf_s("%d", &line);
	while (line < 1 || line>100 || line % 1 != 0 || getchar() != '\n')
	{
		printf("wrong input");
		rewind(stdin);
		scanf_s("%d ", &line);
	}

	pointer = (int**)malloc(line * sizeof(int));
	num = 1;
	size = (int*)malloc(num * sizeof(int));
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
				size[i] = (int*)malloc(num * sizeof(int));
				pointer[i] = (int*)malloc(size[i] * sizeof(int));
				for (j=0;;j++)
				{
					pointer[i][j] = rand() % 201 - 100;
					printf("%d ",pointer[i][j]);
					if (pointer[i][j] == 100)
					{
						size[i] = j + 1;
						break;
					}
					else
					{
						num = num + 1;
						size = (int*)realloc(size, num * sizeof(int*));
					}
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
				size[i] = (int*)malloc(num * sizeof(int));
				pointer[i] = (int*)malloc(size[i] * sizeof(int));
				for (j = 0;; j++)
				{
					printf("mas[%d][%d]=", i, j);
					while (scanf_s("%d", &pointer[i][j]) != 1 || getchar() != '\n')
					{
						printf("wrong input \n");
						rewind(stdin);
					}
					if (pointer[i][j] == 100)
					{
						size[i] = j+1;
						break;
					}
					else
					{
						num = num + 1;
						size = (int*)realloc(size, num*sizeof(int*));
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
	for (i = 0; i < line; i++)
	{
		for (j = 0; j < size[i]; j++)
		{
			for (int repeet = 0; repeet <100;repeet++)
			{
				if (pointer[i][j] < 0)
				{
					for (int j1 = j; j1 <size[i];j1++)
					{
						pointer[i][j1] = pointer[i][j1 + 1];
					}
					size[i] = size[i] - 1;
					
				}
				if (pointer[i][j] == 100)
				{
					break;
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