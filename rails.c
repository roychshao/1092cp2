#include <stdio.h>

int main()
{
	int max, rail[1000000], stack[1000000], j;
	while (scanf("%d", &max) != EOF)
	{
		int index = 0, counter = 0;
		for (int i = 1; i <= max; i++)
		{
			scanf("%d", &rail[i]);
		}
		// input.
		for (j = max ; j >= 0; j--)
		{
			if (rail[j] == max - counter)
			{
				counter++;
				continue;
			}
			else
			{
				while(stack[index-1] == max - counter)
				{
					counter++,index--;
				}
				stack[index] = rail[j];
				index++;
			}
		}
		if(counter != max+1)
		{
			printf("NIE\n");
		}
		else
			printf("TAK\n");
	}
	return 0;
}
