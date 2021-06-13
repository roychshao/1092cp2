#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

string arr;

int cal(int head, int tail)
{
	int counter = 0;
	for (int i = tail; i >= head; --i)
	{
		if (arr[i] == ')')
			counter++;
		else if (arr[i] == '(')
			counter--;
		if (counter)
			continue;
		if (arr[i] == '+')
		{
			return cal(head, i - 1) + cal(i + 1, tail);
		}
		else if (arr[i] == '-')
		{
			return cal(head, i - 1) - cal(i + 1, tail);
		}
	}
	for(int i = tail;i >= head;--i)
	{
		if (arr[i] == ')')
			counter++;
		else if (arr[i] == '(')
			counter--;
		if (counter)
			continue;
		if (arr[i] == '*')
		{
			return cal(head, i - 1) * cal(i + 1, tail);
		}
		else if (arr[i] == '/')
		{
			return cal(head, i - 1) / cal(i + 1, tail);
		}
	}
	int val = 0;
	if (arr[head] == '(' && arr[tail] == ')')
		return cal(head + 1, tail - 1);
	for (int i = head; i <= tail; ++i)
	{
		val = val * 10 + (int)(arr[i] - '0');
	}
	return val;
}

int main()
{
	int ans = 0;
	arr.clear();
	cin >> arr;
	ans = cal(0, arr.size() - 1);
	cout << ans;
}

