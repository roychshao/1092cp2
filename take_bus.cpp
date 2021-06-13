#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

struct node
{
	int BusOrder;
	struct node* next;
};
typedef struct node Node;

int intersect[500][500];
Node station[1000000];
queue<pair<int,int>> que;
int busused[500] = { 0 };	

void addnode(int stop,int busorder)
{
	Node* current = &station[stop];
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->BusOrder = busorder;
	newnode->next = NULL;
	while (current->next != NULL)
	{
		current = current->next;
		intersect[current->BusOrder][busorder] = 1;
		intersect[busorder][current->BusOrder] = 1;
	}
	current->next = newnode;
}

int BFS(int busquan)
{
	pair<int,int> temp;
	while (!que.empty())
		que.pop();
	for (int i = 0; i < busquan; ++i)
	{
		if (busused[i] == -2)
		{
			que.push({ i,1 });
			busused[i] = 1;
		}
	}
	while (!que.empty())
	{
		temp = que.front();
		for (int i = 0; i < busquan; ++i)
		{
			if (intersect[temp.first][i] && busused[i] == 2)
			{
				return temp.second + 1;
			}
			else if (intersect[temp.first][i] && busused[i] == 1)
				continue;
			else if(intersect[temp.first][i] && busused[i] == 0)
			{
				que.push({ i,temp.second + 1 });
				busused[i] = 1;
			}
		}
		que.pop();
	}
	return -1;
}

int main()
{
	int source, target,ans = 0;
	int n, k, temp ,i = 0;
	cin >> source >> target;
	cin >> n;
	memset(intersect, 0, sizeof(intersect));
	while (i < n)
	{
		cin >> k;
		for (int j = 0; j < k; ++j)
		{
			cin >> temp;
			if (temp == source)
				busused[i] = -2;
			else if (temp == target && busused[i] == -2)
				ans = 1;
			else if(temp == target)
				busused[i] = 2;
			addnode(temp,i);
		}
		i++;
	}
	if (ans == 0)
		ans = BFS(i);
	cout << ans << endl;
	return 0;
}
