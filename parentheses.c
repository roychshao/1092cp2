#include <stdio.h>
#include <string.h>

int main()
{
	char input[30];
	fgets(input, sizeof(input), stdin);
	int i, left = 0, right = 0,flag1,flag2;
	int len = strlen(input);
	for (i = 0; i < len; ++i)
	{
		if (input[i] == ')')
			right++;
	}
	for (i = 0; i < len; ++i)
	{
		if(input[i] != '(' && input[i] != ')')
		{
			printf("%c",input[i]);
			continue;
		}
		if (input[i] == '(')
		{
			for (int j = i + 1; j < len; ++j)
			{
				if (input[j] == ')' && right > 0)
				{
					right--;
					printf("(");
					break;
				}
			}
		}
		else if(input[i] == ')')
		{
			for(int j = i-1;j>=0;--j)
			{
				if(input[j] == '(')
				{
					printf(")");
					input[j] = '*';
					break;
				}
			}
		}
	}
	return 0;
}
