#include <stdio.h>
#include <string.h>
#include <ctype.h>

//isalpha(),isdigit(),ispunct()

char chess[1000][1000] = { '0' };

void print(void)
{
	int i, j;
	for (i = 0; i < 1000; ++i)
	{   
		for (j = 0; j < 1000; ++j)
		{
			if(isalpha(chess[i][j]) || ispunct(chess[i][j]))
				printf("%c", chess[i][j]);
		}
	}
}

void diagonal(int *i, int *j, int *input_count, char* input)
{
	while (*i > 0)
	{
		*i--,*j++;
		if (input[*input_count] == NULL)
		{
			return;
		}
		chess[*i][*j] = input[*input_count];
		*input_count++;
	}
}

int main(void)
{
	int rownum,print_flag = 0;
	int input_count = 0;
	int i = 0, j = 0;
	char input[1000];
	gets(input);
	scanf("%d", &rownum);
	while (input[input_count] != NULL)
	{
		chess[i][j] = input[input_count];
		input_count++;
		if (i == rownum - 1)       // start to go up with diagonal line.
		{
			diagonal(&i,&j,&input_count,input);     // i, j,input_count are called by reference.
		}
		i++;
	}
	if(!print_flag)
	{                                                                                                         print();
		return 0;
	}
}


