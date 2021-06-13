#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string s, p;
	cin >> s;
	cin >> p;
	int len_s = s.length();
	int len_p = p.length();
	int dp[100][100];
	for (int i = 0; i <= len_s; ++i) 
	{
		for (int j = 0; j <= len_p; ++j) 
		{
			if (i == 0 && j == 0) 
			{
				dp[i][j] = 1;
				continue;
			}
			if (j == 0) 
			{
				dp[i][j] = 0;
				continue;
			}
			if (i == 0) 
			{
				if (p[j - 1] == '*' && dp[i][j - 2] == 1) 
				{ 
					dp[i][j] = 1;
				}
				else 
				{
					dp[i][j] = 0;
				}
				continue;
			}
			if (p[j - 1] == '*' && (dp[i][j - 1] == 1 || dp[i][j - 2] == 1)) 
			{
				dp[i][j] = 1;
			}
			else if (p[j - 1] == '*' && dp[i - 1][j] == 1 && (p[j - 2] == '.' || s[i - 1] == p[j - 2]))
			{ 
				dp[i][j] = 1;
			}
			else if ((p[j - 1] == '.' || s[i - 1] == p[j - 1]) && dp[i - 1][j - 1] == 1) 
			{
				dp[i][j] = 1;
			}
			else 
			{
				dp[i][j] = 0;
			}
		}
	}
	if (dp[len_s][len_p] == 1)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}
