#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXL 100
#define MAXS 100
#define EPS (1E-15)
#define THRESHOLD (1E-6)

char target[MAXL+1], keyboard[200],buffer[200];
int bufIndex[MAXS];
int K,L,S;

int next()
{
	int s;

	for(s=0;s<S;s++)
	{
		if(++bufIndex[s]==K)
			bufIndex[s]=0;
		buffer[s]=keyboard[bufIndex[s]];

		if(bufIndex[s]==0)
		{
			if(s==S-1)
				return 0;
		}
		else
			break;
	}
	return 1;
}

int countOccurrences()
{
	int res = 0, i, pos;

	for(i=0;i<=S-L;i++)
	{
		for(pos=i;pos<i+L;pos++)
			if(target[pos-i] != buffer[pos])
				break;
		if(pos==i+L)
			res++;
	}
	return res;
}

void initMonkey()
{
	int s;

	for(s=0;s<S;s++)
	{
		bufIndex[s]=0;
		buffer[s]=keyboard[0];
	}
	buffer[S]=0;
}


int main()
{
	int T,tcase,maxOcc;
	int firstOverlapPos, count;
	double answer;


	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{

		scanf("%d %d %d\n", &K, &L, &S);
		scanf("%s\n", keyboard);
		scanf("%s\n", target);
		count = 0;
		initMonkey();
		do
			count += countOccurrences();
		while(next());

		for(firstOverlapPos=1;firstOverlapPos<L;firstOverlapPos++)
			if( strncmp(target, target+firstOverlapPos, L-firstOverlapPos) == 0 )
				break;
		maxOcc = 1 + (S-L)/firstOverlapPos;
		if(count == 0)
			answer = 0.0;
		else
			answer = maxOcc - count / pow(K,S);

		printf("Case #%d: %.8f\n",tcase,answer);
	}

	return 0;
}

