#include <stdio.h>

int size_a,size_b,la,ra,lb,rb;
int a[10000],b[10000];
int a_low,b_low;

void process()
{
	int mid,total_len = (ra - la) + (rb - lb);
	int counter = 0;
	int median1 = 0,median2 = 0;
	a_low = la,b_low = lb;
	mid = total_len/2-1;
	while(counter < mid)
	{
		if(a_low == ra && b_low < rb)
			b_low++;
		else if(b_low == rb && a_low < ra)
			a_low++;
		else if(a[a_low] <= b[b_low])
			a_low++;
		else if(a[a_low] > b[b_low])
			b_low++;
		counter++;
	}
	if(a_low == ra && b_low < rb)
		median1 = b[b_low++];
	else if(b_low == rb && a_low < ra)
		median1 = a[a_low++];
	else if(a[a_low] <= b[b_low])
		median1 = a[a_low++];
	else
		median1 = b[b_low++];
	if(a_low == ra && b_low < rb)
		median2 = b[b_low++];
	else if(b_low == rb && a_low < ra)
		median2 = a[a_low++];
	else if(a[a_low] <= b[b_low])
		median2 = a[a_low++];
	else
		median2 = b[b_low++];
	if(total_len%2==0)
		printf("%d %d\n",median1,median2);
	else
		printf("%d\n",median2);
}

int main()
{
	int i,times;
	scanf("%d",&size_a);
	for(i=0;i<size_a;++i)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&size_b);
	for(i=0;i<size_b;++i)
	{
		scanf("%d",&b[i]);
	}
	scanf("%d",&times);
	i = 0;
	while(i < times)
	{
		scanf("%d%d%d%d",&la,&ra,&lb,&rb);
		process();
		i++;
	}
	return 0;
}	

