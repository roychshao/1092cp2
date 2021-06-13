#include <stdio.h>

int main()
{
	long long n,output;
	scanf("%lld",&n);
	output = ((n+1)*(n+2)*(n+3)*(n+4))/24;
	printf("%lld\n",output);
	return 0;
}
