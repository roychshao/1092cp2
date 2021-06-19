#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int checked_num,int head,int tail,int *nums)
{
	int i;
	int flag = -1;
	for(i=head;i<tail;++i)
	{
		if(checked_num == nums[i])
			flag = i;
	}
	return flag;
}
	
int main(void)
{
	int nums[200000];	//	for input.
	int i = 0;
	int sum = 0;
	int head = 0,tail,ans = 0;
	int check_return;
	//	input data.
	while(scanf("%d",&nums[i])!=EOF)
	{
		if(nums[i]>100000)	//	nums[i] <= 10^5.
			abort();
		i++;		//	the quantity of elements in arrary.
	}
	for(tail=1;tail<i;++tail)
	{
		if(tail == head + 1)
			sum += nums[head];
		check_return = check(nums[tail],head,tail,nums);
		if(check_return < 0)
		{
			sum += nums[tail];
			if(sum > ans)
				ans = sum;
		}
		else if(check_return >=0)
		{
			head = check_return + 1;
			tail = head;
			if(sum > ans)
			{
				ans = sum;
			}
			sum = 0;
		}
	}
	printf("%d",ans);
	return 0;
}
