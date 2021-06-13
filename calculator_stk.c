#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int prcd(char opert1, char opert2)
{
	if (opert2 == '(' || opert1 == '(')
		return 0;
	if (opert2 == ')' && opert1 != '(')
		return 1;
	if (opert1 == '*' && opert2 == '+')
		return 1;
	else if (opert1 == '*' && opert2 == '-')
		return 1;
	else if (opert1 == '*' && opert2 == '*')
		return 1;
	else if (opert1 == '*' && opert2 == '/')
		return 1;
	else if (opert1 == '/' && opert2 == '+')
		return 1;
	else if (opert1 == '/' && opert2 == '-')
		return 1;
	else if (opert1 == '/' && opert2 == '*')
		return 1;
	else if (opert1 == '/' && opert2 == '/')
		return 1;
	else if (opert1 == '+' && opert2 == '+')
		return 1;
	else if (opert1 == '+' && opert2 == '-')
		return 1;
	else if (opert1 == '-' && opert2 == '+')
		return 1;
	else if (opert1 == '-' && opert2 == '-')
		return 1;
	else
		return 0;
}

int empty(int index)
{
	if (index == -1)
		return 1;
	else
		return 0;
}

void push(char* stack, char obj, int index)
{
	stack[index] = obj;
}

void push_f(int* stack, int obj, int index)
{
	stack[index] = obj;
}

char pop(char* stack, int index)
{
	char temp;
	temp = stack[index];
	stack[index] = NULL;
	return temp;
}

int pop_f(int* stack, int index)
{
	int temp;
	temp = stack[index];
	stack[index] = 0;
	return temp;
}

char stacktop(char* stack, int index)
{
	char temp;
	temp = pop(stack, index);
	push(stack, temp, index);
	return temp;
}

int optindex = -1, postindex = -1, i = 0;
char postfix[1000][1000];

int oper(char symb, int op1, int op2)
{
	switch (symb)
	{
		case '+': return (int)(op1 + op2);
		case '-': return (int)(op1 - op2);
		case '*': return (int)(op1 * op2);
		case '/': return (int)(op1 / op2);
		default: printf("ERROR.\n");
	}
}

int getval(char* infix)
{
	int val = (int)(infix[i] - '0');
	i++;
	while (isdigit(infix[i]))
	{
		val = (val * 10) + (int)(infix[i] - '0');
		i++;
	}
	i--;
	return val;
}

int main()
{
	char infix[1000] = { NULL };
	char optstk[1000] = { NULL };
	int opndstk[1000] = { 0 };
	char topsymb;
	int optindex = -1, postindex = -1, opndindex = -1,temp = 0;
	fgets(infix, 1000, stdin);
	for (i = 0; i < strlen(infix) - 1; ++i)
	{
		if (isdigit(infix[i]))
		{
			postindex++;
			if ((infix[i - 1] == '-') && (i == 1 || (infix[i - 2] == '(')))
			{
				postfix[postindex][temp] = '-';
				temp++;
			}
			postfix[postindex][temp] = infix[i];
			i++, temp++;
			while (isdigit(infix[i]))
			{
				postfix[postindex][temp] = infix[i];
				i++, temp++;
			}
			temp = 0;
			i--;
		}
		else
		{
			if (infix[i] == '-' && (i == 0 || infix[i - 1] == '('))
			{
				continue;
			}
			while (!empty(optindex) && prcd(stacktop(optstk, optindex), infix[i]))
			//	if optstk is not empty and the objon the top is prior.
			{
				topsymb = pop(optstk, optindex);
				optindex--;
				postindex++;
				postfix[postindex][0] = topsymb;
			}
			if (empty(optindex) || infix[i] != ')')
			{
				optindex++;
				push(optstk, infix[i], optindex);
			}
			else
			{
				topsymb = pop(optstk, optindex);
				optindex--;
			}
		}
	}
	// put the remain opert into postfix.
	while (!empty(optindex))
	{
		topsymb = pop(optstk, optindex);
		optindex--;
		postindex++;
		postfix[postindex][0] = topsymb;
	}
	for(int j=0;j<=postindex;++j)
	{
		printf("%s ",postfix[j]);
	}
	printf("\n");
	// calculate.
	/*for (int j = 0; j <= postindex; ++j)
	{
		if (isdigit(postfix[j][0]) ||
				(postfix[j][0] == '-' && isdigit(postfix[j][1])))
		{
			opndindex++;
			push_f(opndstk, atoi(postfix[j]), opndindex);
		}
		else
		{
			int opnd2 = pop_f(opndstk, opndindex);
			opndindex--;
			int opnd1 = pop_f(opndstk, opndindex);
			opndindex--;
			int value = oper(postfix[j][0], opnd1, opnd2);
			opndindex++;
			push_f(opndstk, value, opndindex);
		}
	}
	printf("%d\n", opndstk[0]);*/
	return 0;
}
