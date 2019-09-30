#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXD 1000
#define MAXP 1000

typedef struct
{
	int pancakes, diners, cuts, cost;
} Data;

int DataCompare(const void * aa, const void * bb)
{
	Data *a,*b;

	a = (Data *) aa;
	b = (Data *) bb;
	if(a->cost < b->cost)
		return -1;
	else if(a->cost > b->cost)
		return 1;
	else if(a->diners < b->diners)
		return 1;
	else if(a->diners > b->diners)
		return -1;
	else
		return 0;
}

int main()
{
	int T,tcase,D,i,Pi,maxPi,M,Pcount[MAXP+1],totalCuts,minutes,totalPancakes;
	Data data[MAXD];


	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d",&D);
		for(i=0;i<=MAXP;i++)
			Pcount[i]=0;
		totalPancakes = 0;
		maxPi = 0;
		for(i=0;i<D;i++)
		{
			scanf("%d",&Pi);
			if(maxPi < Pi)
				maxPi = Pi;
			Pcount[Pi]++;
			totalPancakes += Pi;
		}
		M=0;
		for(Pi=1;Pi<=MAXP;Pi++)
		{
			if(Pcount[Pi])
			{
				data[M].pancakes = Pi;
				data[M].diners = Pcount[Pi];
				data[M].cuts = 0;
				data[M].cost = Pi;
				M++;
			}
		}
		M--;
		minutes = maxPi;
		totalCuts=0;
		while(totalCuts + data[M].diners < maxPi)
		{
			totalCuts += data[M].diners;
			data[M].cuts++;
			data[M].cost = ceil( data[M].pancakes*1.0 / (data[M].cuts + 1) );
			qsort(data,M+1,sizeof(Data),DataCompare);
			if(totalCuts + data[M].cost < minutes)
				minutes = totalCuts + data[M].cost;
		}
		printf("Case #%d: %d\n",tcase,minutes);
	}

	return 0;
}

