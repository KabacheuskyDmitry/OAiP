#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
	int *pointer;
	int line, row, i, j, a, num, buffer;
	printf("input amountcy of lines in the arrey");
	scanf_s("%d", &line);
	while (line < 1 || line>100 || line % 1 != 0 || getchar() != '\n')
	{
		printf("wrong input");
		rewind(stdin);
		scanf_s("%d ", &line);
	}
	
	pointer = (int*)malloc(line * sizeof(int));
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
							pointer[i] = rand() % 201 - 100;
					}
					printf("your arrey");
					for (i = 0; i < line; i++)
					{
						printf("%5d ", pointer[i]);
					}
					printf("\n");
					stop = stop + 1;
					break;
				}
				case 2:
				{
					for (i = 0; i < line; i++)
					{
						printf("mas[%d]=", i);
						while ((scanf_s("%d", &pointer[i])) != 1 || getchar() != '\n')
						{
							printf("wrong input \n");
							rewind(stdin);
						}
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
		for (i = 0; i < line;i++)
		{
			num = pointer[i];
			while (pointer[i + 1] == num)
			{
				for (int buffer1 = i+1; buffer1 < line;buffer1++)
				{
					pointer[buffer1] = pointer[buffer1 + 1];
				}
				line = line--;

			}
			for (buffer=i+1; buffer < line;buffer++)
			{
				for (j = 0;j < line;j++)
				{
					if (pointer[buffer] == num)
					{
						for (int buffer1 = buffer; buffer1 < line;buffer1++)
						{
							pointer[buffer1] = pointer[buffer1 + 1];
						}
						line = line--;
					}
				}
			}
		}


		for (i = 0; i < line; i++)
		{
				printf("%5d ", pointer[i]);
		}

	
	return 0;
}