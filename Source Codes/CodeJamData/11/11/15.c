#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct _robot
{
	int curtime;
	int curpos;
} Robot;

int main(int argc, char *argv[])
{
	Robot obot, bbot, *curbot, *otherbot;
	char *pch, bot;
	int button;
	char buf[65536];
	int i, j, T, PG, PD;
	__int64 N;
	unsigned char bPossible;

	gets(buf);
	sscanf(buf, "%d", &T);
	for(i=0; i<T; i++)
	{
		gets(buf);
		sscanf(buf, "%I64d %d %d", &N, &PD, &PG);

		if((PG == 100 && PD != 100) || (PG == 0 && PD != 0))
			bPossible=0;
		else
		{
			bPossible=0;
			for(j=1; j<=N; j++)
			{
				if(j*PD % 100 == 0)
				{
					bPossible=1;
					break;
				}
			}
		}

		if(bPossible)
			printf("Case #%d: Possible\n",i+1);
		else
			printf("Case #%d: Broken\n",i+1);
	}

	return 0;
}