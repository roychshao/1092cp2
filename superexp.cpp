#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int mypow(int x,int k,int p)
{
	x %= p;
	int res = 1;
	for(int s=0;s<k;++s)
	{
		res *= x;
		res %= p;
	}
	return res;
}

int superpow(int x,vector<int>& y,int p)
{
	if(y.empty()) return 1;
	int last = y.back();
	y.pop_back();
	int part1 = mypow(x,last,p);
	int part2 = mypow(superpow(x,y,p),10,p);
	return (part1 * part2)%p;
}

int main()
{
	int times, i = 0,j = 0,ans;
	int x,p;
	vector<int>y;
	char input[10];
	scanf("%d", &times);
	while (i < times)
	{
		j = 0;
		y.clear();
		scanf("%d",&x);
		memset(input,0,10);
		scanf("%s",input);
		while(j < strlen(input))
		{
			y.push_back((int)(input[j] - '0'));
			j++;
		}
		scanf("%d",&p);
		cout<<"x is:"<<x<<endl;
		cout<<"y is:";
		for(j=0;j<y.size();++j)
		{
			cout << y[j];
		}
		cout << endl;
		cout<<"p is:"<< p << endl;
		ans = superpow(x,y,p);
		cout<<"ans is:" << ans << endl;
		i++;
	}
	return 0;
}

