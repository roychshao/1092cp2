#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct info
{
	int arr[4];
	int times;
}Info;

int n;
int code[4];
int lock[505][4];
int used[10][10][10][10];
queue<Info> que;

bool find(int *mani)
{
	for (int i = 0; i < n; ++i)
	{
		if (mani[0] == lock[i][0] &&
			mani[1] == lock[i][1] &&
			mani[2] == lock[i][2] &&
			mani[3] == lock[i][3])
			return true;
	}
	return false;
}

void adjust(int* arr)
{
	for (int i = 0; i < 4; ++i)
		arr[i] = (arr[i] + 10) % 10;
}

bool record(int* arr)
{
	if (used[arr[0]][arr[1]][arr[2]][arr[3]])
		return true;
	else
		used[arr[0]][arr[1]][arr[2]][arr[3]] = 1;
	return false;
}

int BFS()
{
	//	initial status
	Info temp;
	memset(temp.arr,0,sizeof(temp.arr)), temp.times = 0;
	que.push(temp);
	used[0][0][0][0] = 1;
	while (!que.empty())
	{
		temp = que.front();
		adjust(temp.arr);
		//	if find the answer
		if (memcmp(temp.arr, code,sizeof(temp.arr)) == 0)
			return temp.times;
		//	if lock
		if (find(temp.arr))
			que.pop();
		else
		{
			//	process and push
			temp.times++;
			temp.arr[0]++, adjust(temp.arr);
			if(!record(temp.arr))	
				que.push(temp);
			temp.arr[0]--, temp.arr[1]++ , adjust(temp.arr);
			if (!record(temp.arr))
				que.push(temp);
			temp.arr[1]--, temp.arr[2]++ , adjust(temp.arr);
			if (!record(temp.arr))
				que.push(temp);
			temp.arr[2]--, temp.arr[3]++ , adjust(temp.arr);
			if (!record(temp.arr))
				que.push(temp);
			temp.arr[3]--, temp.arr[0]-- , adjust(temp.arr);
			if (!record(temp.arr))
				que.push(temp);
			temp.arr[0]++, temp.arr[1]-- , adjust(temp.arr);
			if (!record(temp.arr))
				que.push(temp);
			temp.arr[1]++, temp.arr[2]-- , adjust(temp.arr);
			if (!record(temp.arr))
				que.push(temp);
			temp.arr[2]++, temp.arr[3]-- , adjust(temp.arr);
			if (!record(temp.arr))
				que.push(temp);
		}
		que.pop();
	}
	return -1;
}

int main()
{
	char tmp[5];
	memset(used, 0, sizeof(used));
	cin >> tmp;
	for (int i = 0; i < 4; ++i)
		code[i] = tmp[i] - '0';
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		if (strcmp(tmp, "0000") == 0)
		{
			cout << -1 << endl;
			return 0;
		}
		for (int j = 0; j < 4; ++j)
		{
			lock[i][j] = tmp[j] - '0';
		}
	}
	int ans = BFS();
	cout << ans << endl;
	return 0;
}
