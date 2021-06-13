#include <stdio.h>

int nums[100000];
int sums[100000];

int main()
{
	int len,target;
	scanf("%d",&len);
	for(int i=0;i<len;++i)
	{
		scanf("%d",&nums[i]);
	}
	scanf("%d",&target);
	sums[0] = nums[0];
	for(int i=1;i<len;++i)
	{
		sums[i] = sums[i-1]+nums[i];
	}
	int head=0,tail=0,ans=100001,sum=0;
	int flag = 0;
	while(tail < len)
	{
		sum = sums[tail]-sums[head-1];
		if(sum >= target)
		{
			flag = 1;
			if((tail-head+1) < ans)
				ans = (tail-head+1);
			head++;
		}
		else
			tail++;
	}
	if(flag)
		printf("%d\n",ans);
	else
		printf("0\n");
	return 0;
}
