#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	int order;
	struct Node* next;
	struct Node* previous;
}Block;

Block table[26];
int record[26];

void put(int cmd2, int cmd4)
{
	Block* CMD2 = &table[record[cmd2]];
	Block* CMD4 = &table[record[cmd4]];
	while (CMD2->order != cmd2)
		CMD2 = CMD2->next;
	while (CMD4->next != NULL)
		CMD4 = CMD4->next;
	CMD4->next = CMD2;
	Block* temp;
	temp = CMD2->previous;
	temp->next = NULL;
	CMD2->previous = CMD4;
	while (CMD2 != NULL)
	{
		record[CMD2->order] = record[CMD4->order];
		CMD2 = CMD2->next;
	}
}

void putback(int cmd)
{
	Block* head = &table[record[cmd]];
	Block* tail;
	while (head->order != cmd)
		head = head->next;
	tail = head;
	while (tail->next != NULL)
		tail = tail->next;
	Block* temp;
	while (tail != head)
	{
		table[tail->order].next = tail;
		temp = tail->previous;
		temp->next = NULL;
		tail->previous = &table[tail->order];
		record[tail->order] = tail->order;
		tail = temp;
	}
}

void print(int quan)
{
	int i = 0;
	Block* temp;
	for (i = 0; i < quan; ++i)
	{
		printf("%d: ", i);
		temp = table[i].next;
		while (temp != NULL)
		{
			printf("%d ", temp->order);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main()
{
	int i, quan;
	char cmd1[5], cmd3[5];
	int cmd2, cmd4;
	while (scanf("%d", &quan) != EOF)
	{
		for (i = 0; i < quan; ++i)
		{
			Block* ptr;
			table[i].order = 25;
			table[i].next = (Block*)malloc(sizeof(Block));
			ptr = table[i].next;
			ptr->previous = &table[i];
			ptr->order = i;
			ptr->next = NULL;
			record[i] = i;
		}
		while (1)
		{
			scanf("%s", cmd1);
			if (strcmp(cmd1, "quit") == 0)
				break;
			scanf("%d", &cmd2);
			scanf("%s", cmd3);
			scanf("%d", &cmd4);
			if ((cmd2 == cmd4) || record[cmd2] == record[cmd4])
				continue;
			if (strcmp(cmd1, "move") == 0)
			{
				if (strcmp(cmd3, "onto") == 0)
				{
					putback(cmd2);
					putback(cmd4);
					put(cmd2, cmd4);
				}
				else if (strcmp(cmd3, "over") == 0)
				{
					putback(cmd2);
					put(cmd2, cmd4);
				}
			}
			else if (strcmp(cmd1, "pile") == 0)
			{
				if (strcmp(cmd3, "onto") == 0)
				{
					putback(cmd4);
					put(cmd2, cmd4);
				}
				else if (strcmp(cmd3, "over") == 0)
				{
					put(cmd2, cmd4);
				}
			}
		}
		print(quan);
	}
	return 0;
}

