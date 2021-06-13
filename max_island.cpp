#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <map>
using namespace std;

int area[505][505], counter = 0;
int check[100] = { 0 }, cindex = 0;
pair<int, int> dir[4] = { {0,1},{1,0},{0,-1},{-1,0} };
map<int, int> corr;

void dfs(int i, int j, int color, int n)
{
	area[i][j] = color;
	counter++;
	for (int t = 0; t < 4; ++t)
	{
		if (i + dir[t].first >= 0 && i + dir[t].first < n
				&& j + dir[t].second >= 0 && j + dir[t].second < n)
		{
			if (area[i + dir[t].first][j + dir[t].second] == 1)
				dfs(i + dir[t].first, j + dir[t].second, color, n);
		}
	}
}

void paint(int n)
{
	int color = 2;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (area[i][j] == 1)
			{
				counter = 0;
				dfs(i, j, color, n);
				corr.insert({ color,counter });
				color++;
			}
		}
	}
}

bool repeat(int number)
{
	for (int i = 0; i < cindex; ++i)
	{
		if (check[i] == number)
			return true;
	}
	return false;
}

int main()
{
	int n, temp = 0, ans = 0, number;
	map<int, int>::iterator itr;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> area[i][j];
		}
	}
	paint(n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (area[i][j] == 0)
			{
				for (int t = 0; t < 4; ++t)
				{
					if ((i + dir[t].first) >= 0 && (i + dir[t].first) < n
							&& (j + dir[t].second) >= 0 && (j + dir[t].second) < n)
					{
						if (area[i + dir[t].first][j + dir[t].second] > 0)
						{
							number = area[i + dir[t].first][j + dir[t].second];
							if (!repeat(number))
							{
								check[cindex++] = number;
								itr = corr.find(number);
								temp += itr->second;
							}
						}
					}
				}
				memset(check, 0, sizeof(check));
				cindex = 0;
				if (temp > ans)
					ans = temp;
				temp = 0;
			}
		}
	}
	cout << ans + 1 << endl;
	return 0;
}
