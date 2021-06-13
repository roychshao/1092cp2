#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point
{
	int x;
	int y;
	double slope;
}Point;

Point dp[5000][5000];
double temp[5000];

void print(int times)
{
	for (int i = 0; i < times; ++i)
	{
		for (int j = i + 1; j < times; ++j)
		{
			printf("%.3lf ", dp[i][j].slope);
		}
		printf("\n");
	}
}

int cmp(const void* a, const void* b)
{
	return (*(double*)a > * (double*)b) ? 1 : -1;
}

int main()
{
	int i, times, ans = 0, tmp = 0, counter = 0;
	scanf("%d", &times);
	for (i = 0; i < times; ++i)
	{
		scanf("%d%d", &dp[0][i].x, &dp[0][i].y);
	}
	for (i = 0; i < times; ++i)
	{
		counter = 0;
		memset(temp, 0, sizeof(temp));
		for (int j = i + 1; j < times; ++j)
		{
			if ((double)dp[0][j].x - (double)dp[0][i].x == 0)
				dp[i][j].slope = 99999;
			else
				dp[i][j].slope = ((double)dp[0][j].y - (double)dp[0][i].y) / ((double)dp[0][j].x - (double)dp[0][i].x);
			temp[counter] = dp[i][j].slope;
			counter++;
		}
		tmp = 0;
		qsort(temp, times - i - 1, sizeof(double), cmp);
		for (int j = 0; j < times - i - 1; ++j)
		{
			printf("%.3f ", temp[j]);
		}
		printf("\n");
		double now = temp[0];
		for (int j = 0; j < times-i-1; ++j)
		{
			if (temp[j] == now)
			{
				tmp++;
				if (tmp > ans)
					ans = tmp;
			}
			else
			{
				now = temp[j];
				tmp = 1;
			}
		}
	}
	print(times);
	printf("%d\n", ans + 1);
	return 0;
}

