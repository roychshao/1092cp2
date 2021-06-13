#include <stdio.h>
#include <string.h>

int maxlen(int *a,int *b,int a_len,int b_len)
{
	int dp[1010][1010];
	memset(dp,0,sizeof(dp));
	for(int i=a_len-1;i>=0;i--)
	{
		for(int j=b_len-1;j>=0;j--)
		{
			if(a[i] == b[j])
			{
				dp[j][i] = dp[j+1][i+1]+1;
			}
		}
	}
	int maxm = 0;
	for(int i = 0;i < a_len;++i)
	{
		for(int j = 0;j < b_len;++j)
		{
			if(dp[i][j] > maxm)
				maxm = dp[i][j];
		}
	}
	return maxm;
}


int main()
{
	int a_len,b_len,i=0,j=0;
	int a[1010],b[1010];
	scanf("%d",&a_len);
	for(i=0;i<a_len;++i)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&b_len);
	for(i=0;i<b_len;++i)
	{
		scanf("%d",&b[i]);
	}
	printf("%d\n",maxlen(a,b,a_len,b_len));
	return 0;
}
