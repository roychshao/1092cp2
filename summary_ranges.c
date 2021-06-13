#include <stdio.h>

void print(int head,int tail,int *input)
{
	if(input[head] == input[tail])
	{
		printf("%d\n",input[head]);
	}
	else
	{
		printf("%d->%d\n",input[head],input[tail]);
	}
}

int main()
{
	int input[20];
	int i=0,j;
	while(scanf("%d",&input[i])!=EOF)
	{
		i++;
	}
	if(i == 1)
		printf("%d",input[0]);
	int head = 0;
	int tail;
	int plus = 1;
	for(j=1;j<=i;++j)
	{
		if(input[j] == input[head]+plus)	// if in the same range.
		{
			plus++;
			continue;		
		}
		else
		{
			plus = 1;
			tail = j-1;
			print(head,tail,input);
			head = j;
		}
	}
	return 0;
}
