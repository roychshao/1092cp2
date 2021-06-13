#include <stdio.h>
#include <string.h>

int dp[100][100];

int main()
{
	int i, j, j_temp, quan;
	int nums[100];
	memset(dp, 0, sizeof(dp));
	scanf("%d", &quan);
	for (i = 0; i < quan; ++i)
	{
		scanf("%d", &nums[i]);
	}
	j_temp = quan;
	for (i = quan - 1; i >= 0; --i)
	{
		dp[i][i] = nums[i];
		for (j = i + 1; j < quan; ++j)
		{
			int a = nums[i] - dp[i + 1][j];
			int b = nums[j] - dp[i][j - 1];
			dp[i][j] = (a > b) ? a : b;
		}
	}
	if (dp[0][quan - 1] >= 0)
		printf("Ture");
	else
		printf("False");
	return 0;
}
