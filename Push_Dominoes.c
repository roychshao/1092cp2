#include <stdio.h>
#include <string.h>

void process(char *status1,char *status2)
{
	int i;
	for(i=0;i<strlen(status2);++i)
	{
		if(status1[i] == '.')
		{
			if(i==0 && status1[i+1] == 'L')	//	leftest
				status2[i] = 'L';
			else if(i == strlen(status2)-1 && status1[i-1] == 'R')	//	rightest.
				status2[i] = 'R';
			else if(status1[i-1] == 'R' && status1[i+1] != 'L')	//	R.R || R..
			{
				status2[i] = 'R';
			}
			else if(status1[i-1] != 'R' && status1[i+1] == 'L')	//	L.L || ..L
			{
				status2[i] = 'L';
			}
		}
	}
}
int main(void)
{
	int time;
	char status1[1000000];
	char status2[1000000];
	gets(status2);
	strcpy(status1,status2);
	process(status1,status2);
	for(time=0;strcmp(status1,status2)!=0;++time)	//	when the process haven't terminate.
	{
		strcpy(status1,status2);	//	record status2 with status1.
		process(status1,status2);
	}
	puts(status2);
	return 0;
}





