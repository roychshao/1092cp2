#include <stdio.h>
#include <math.h>

int main(void)
{
	int n,i,j;
	int ans[1000000];
	scanf("%d",&n);
	ans[0] = 0 , ans[1] = 1;
	for(i=2;i<=n;++i)
	{
		ans[i] = i;	// all replaced by 1.	
		for(j=0;j*j<=i;++j)	// if the last square number+1 have fewer steps, than replace it.
		{
			if(ans[i]>ans[i-j*j]+1)
				ans[i] = ans[i-j*j]+1;
		}
	}
	printf("%d\n",ans[n]);
	return 0;
}
			

