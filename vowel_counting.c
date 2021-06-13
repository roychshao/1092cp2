#include <stdio.h>

long long dic[500][5];

long long sum(int i,int num)
{
	long long result = 0;
	for(int j=5;j>=5-num;--j)
	{
		result += dic[j][i];
	}
	return result;
}

int main()
{
	int i,j;
	int times;
	long long ans = 0;
	scanf("%d",&times);
	dic[0][0] = 1;
	dic[1][0] = 1;
	dic[2][0] = 1;
	dic[3][0] = 1;
	dic[4][0] = 1;
	for(i=0;i<times;++i)
	{
		j=i+1;
		dic[0][j] = sum(i,5);
		dic[1][j] = sum(i,4);
		dic[2][j] = sum(i,3);
		dic[3][j] = sum(i,2);
		dic[4][j] = sum(i,1);
	}
	i--;
	ans = dic[0][i]+dic[1][i]+dic[2][i]+dic[3][i]+dic[4][i];
	printf("%lld\n",ans);
	return 0;
}
