#include<stdio.h>

unsigned long findcost(int choice[100], int cells[100], int Q, int P)
{
	int i,j,k;
	int jail[10000]={0,0};
	unsigned long cost=0;
	int left,right;

	for (j=0;j<Q;j++) {

	for (i=0;i<Q;i++)
	{
		if (choice[i]==j) {
			jail[cells[i]-1]=1;
				break;
		}
	}

	for (left=cells[i]-2; left>=0; left--)
	{
//printf("left:%d\n",left);
		if (jail[left]==0)
			cost++;
		else
			break;
	}

	for (right=cells[i]; right<P;right++)
	{
//printf("right:%d\n",right);
	if (jail[right]==0)
			cost++;
		else
			break;
	}

	}
	
	return cost;	
}

int main()
{
	int N;
	int tc;
	scanf("%d\n", &N);

	for (tc=1; tc<=N; tc++)
	{
		int P, Q;
		int cells[100];
		int choice[100];
		int chosen[100]={0};
		int cost;
		int i, j, k;
		int pow;
		unsigned long loopcount;
		unsigned long mincost, currcost;

//		int memoize[10000][100];

		scanf("%d", &P);
		scanf("%d", &Q);
		for (i=0; i< Q; i++)
			scanf("%d", &cells[i]);
/*
		choisesmade=0;
		while (choicesmade<Q)
		{
			choicesmade++;
			for (i=0;i<q; i++)
			{
				if (chosen[i]==0)
				{
					newchoice = 
				}
			}
			choice[choicesmade]=
			
		}	
*/
		loopcount=1;
		for (i=0;i<Q;i++)
			loopcount *=Q;

		mincost=0xffffffffffffffff;
		for (i=0;i<loopcount;i++)
		{
			pow=i;
//			printf("i=%d\n",i);
			for (j=0;j<Q;j++) {
				chosen[j]=pow%Q;
				pow=pow/Q;
				for (k=0; k<j; k++)
					if (chosen[k]==chosen[j])
						goto duplicatelist;
			}
/*			for (j=0; j<Q; j++)
				printf("%d ",chosen[j]);
			printf("\n");*/
			currcost = findcost(chosen,cells, Q, P);
			if (currcost<mincost)
				mincost=currcost;
		duplicatelist: ;
		}
		printf("Case #%d: %d\n", tc, mincost);
		
	}
	return 0;
}
