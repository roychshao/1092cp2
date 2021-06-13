#include <stdio.h>
#include <string.h>

int board[362880][9];
int bindex = 0;
int list[10];
int chosen[10];

void search(int depth, int n)
{
	if (depth == n)
	{
		for (int i = 0; i < n; ++i)
		{
			board[bindex][i] = list[i];
		}
		bindex++;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (chosen[i]) continue;
			chosen[i] = 1;
			list[depth] = i+1;
			search(depth + 1, n);
			chosen[i] = 0;
			list[depth] = -1;
		}
	}
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	memset(list, NULL, sizeof(list));
	memset(chosen, NULL, sizeof(chosen));
	for (int i = 0; i <= n; ++i)
	{
		list[i] = i;
	}
	search(0, n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d", board[k-1][i]);
	}
	printf("\n");
	return 0;
}

