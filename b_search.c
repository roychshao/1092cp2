#include <stdio.h>
#include <string.h>
#include <ctype.h>

int nums[100000000];
int counter = 0;
int iindex = 0;

int search(int target,int left, int right)
{
	if(iindex == 0)
		return -1;
	while(left < right)
	{
		counter+=1;
		int mid = left + (right - left) / 2;
		if(nums[mid] == target)
		{
			return mid;
		}
		else if(nums[mid] < target)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	if(left != iindex-1 && nums[left] == target)
		return left;
	return -1;
}

int main()
{
	int target;
	int ans = 0;
	scanf("%d", &target);
	while(scanf("%d",&nums[iindex]) != EOF)
	{
		iindex++;
	}	
	ans = search(target,0, iindex);
	printf("%d\n",ans);
	if(ans != -1)
	{
		printf("%d",counter);
	}
	return 0;
}

