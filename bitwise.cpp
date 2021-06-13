#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int left,right,llen,rlen;
	int ans = 0;
	cin >> left >> right;
	if(left == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	while(left && right)
	{		
		llen = log2(left);
		rlen = log2(right);
		if(llen != rlen)
			break;
		ans += (1<<llen);
		left -= (1<<llen);
		right -= (1<<llen);
	}
	cout << ans << endl;
	return 0;
}
