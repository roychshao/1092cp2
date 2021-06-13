#include <stdio.h>
#include <string.h>

int board[200][200];
int path[200][200],p[200][200];
int xdir[4] = { 0,1,0,-1 };
int ydir[4] = { 1,0,-1,0 };
int temp = 0;

void PrintPath(int i, int j, int ans)
{
	printf("%d %d\n", i, j);
	if (path[i][j] <= ans)
	{
		for (int t = 0; t < 4; ++t)
		{
			if (path[i + xdir[t]][j + ydir[t]] == (path[i][j] + 1))
				PrintPath(i + xdir[t], j + ydir[t], ans);
		}
	}
}

void DFS(int i, int j,int n, int m, int counter)
{
	p[i][j] = counter;
	for (int t = 0; t < 4; ++t)
	{
		if ((i + xdir[t]) < 0 || (i + xdir[t]) >= n
				|| (j + ydir[t]) < 0 || (j + ydir[t]) >= m)
			continue;
		if (board[i + xdir[t]][j + ydir[t]] > board[i][j])
		{
			counter++;
			DFS(i + xdir[t], j + ydir[t], n, m, counter);
			p[i + xdir[t]][j + ydir[t]] = 0;
			counter--;
		}
	}
	if (counter > temp)
	{
		temp = counter;
		memcpy(path, p, sizeof(path));
	}
}

int main()
{
	int n, m, ans = 1, maxi = 0, maxj = 0;
	scanf("%d%d", &n, &m);
	memset(board, 0, sizeof(board));
	memset(path, 0, sizeof(path));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d",&board[i][j]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			memset(p, 0, sizeof(p));
			DFS(i, j, n, m, 1);
			if (temp > ans)
			{
				ans = temp;
				maxi = i;
				maxj = j;
			}
		}
	}
	printf("%d\n",ans);
	PrintPath(maxi,maxj,ans);
}
