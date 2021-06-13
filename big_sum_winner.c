#include <stdio.h>
//this might be right ans.

int max(int i,int j)
{
	return (i>j)?i:j;
}

int main()
{
	int n;
	int nums[100];
	int dp[200][200];
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&nums[i]);
	}
	for(int i=0;i<n;++i)
	{
		dp[i][i] = nums[i];
	}
	for(int len=1;len<n;++len)
	{
		for(int i=0,j=len;j<n;++i,++j)
		{
			dp[i][j] = max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
		}
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	if(dp[0][n-1]>=0)
		printf("True");
	else
		printf("False");
	return 0;
}
