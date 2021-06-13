#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int common[25000];
char input1[40000] = { NULL };
char input2[40000] = { NULL };
int input_i1[25000];
int input_i2[25000];
int i, comindex = 0, i1index = 0, i2index = 0;

int getval(char* arr)
{
	int value = (int)(arr[i] - '0');
	i++;
	while (isdigit(arr[i]))
	{
		value = value * 10 + (int)(arr[i] - '0');
		i++;
	}
	i--;
	return value;
}

void find(char* input1, char* input2)
{
	int flag = 0;
	int l = strlen(input1);
	for (i = 0; i < l; ++i)
	{
		if (isdigit(input1[i]) && input1[i] != ' ')
		{
			int val = getval(input1);
			input_i1[i1index] = val;
			i1index++;
		}
		else if (input1[i] == '-')
		{
			i++;
			int val = (-1) * getval(input1);
			input_i1[i1index] = val;
			i1index++;
		}
	}
	l = strlen(input2);
	for (i = 0; i < l; ++i)
	{
		if (isdigit(input2[i]))
		{
			int val = getval(input2);
			input_i2[i2index] = val;
			i2index++;
		}
		else if (input2[i] == '-')
		{
			i++;
			int val = (-1) * getval(input2);
			input_i2[i2index] = val;
			i2index++;
		}
	}
	for (int s = 0; s < i1index; ++s)
	{
		for (int t = 0; t < i2index; ++t)
		{
			if (input_i1[s] == input_i2[t])
			{
				for (int k = 0; k < comindex; ++k)
				{
					if (common[k] == input_i1[s])
						flag = 1;
				}
				if (!flag)
				{
					common[comindex] = input_i1[s];
					comindex++;
				}
				flag = 0;
			}
		}
	}
}

int cmp(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main()
{
	int n = 2, times;
	scanf("%d", &times);
	scanf(" ");
	fgets(input1, 40000, stdin);
	fgets(input2, 40000, stdin);
	find(input1, input2);
	if (times == 2)
	{
		qsort(common, comindex, sizeof(int), cmp);
		for (int j = 0; j < comindex; ++j)
		{
			if(common[j] != 6789)
				printf("%d ", common[j]);
		}
		return 0;
	}
	while (n < times)
	{
		fgets(input2, 40000, stdin);
		memset(input_i2, NULL, sizeof(input_i2));
		i2index = 0;
		int l = strlen(input2);
		for (i = 0; i < l - 1; ++i)
		{
			if (isdigit(input2[i]))
			{
				int val = getval(input2);
				input_i2[i2index] = val;
				i2index++;
			}
			else if (input2[i] == '-')
			{
				i++;
				int val = (-1) * getval(input2);
				input_i2[i2index] = val;
				i2index++;
			}
		}
		int flag = 0;
		for (int s = 0; s < comindex; ++s)
		{
			for (int t = 0; t < i2index; ++t)
			{
				if (common[s] == input_i2[t])
				{
					flag = 1;
				}
			}
			if (!flag)
			{
				common[s] = 6789;
			}
			flag = 0;
		}
		n++;
	}
	qsort(common, comindex, sizeof(int), cmp);
	for (i = 0; i < comindex; ++i)
	{
		if(common[i] != 6789)
			printf("%d ", common[i]);
	}
	return 0;
}
