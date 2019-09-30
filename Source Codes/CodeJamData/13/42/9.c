#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		int N,P;
		cin >> N >> P;
		int r1,r2;

		r1 = 0;
		for(i=0; i<(1<<N); i++)
		{
			int maylost = 0;
			int p = 1;
			j = i;
			while(j >= p)
			{
				j -= p; p*=2;
				maylost++;
			}

			int halv = (1<<(N-1));
			int rank = 0;
			for(j=0; j<maylost; j++)
			{
				rank += halv;
				halv /= 2;
			}
		//	printf("%d %d\n", i, rank);
			if (rank+1 > P)
				break;
			r1 = i;
		}
		r2 = 0;
		for(i=0; i<(1<<N); i++)
		{
			int maywin = 0;
			int p = 1;
			j = i;
			while(j >= p)
			{
				j -= p; p*=2;
				maywin++;
			}

			int rank = (1<<(N-maywin));

//			printf("%d %d\n", (1<<N)-1-i, rank);
			r2 = (1<<N)-1-i;
			if (rank <= P)
				break;
		}

		printf("Case #%d: %d %d\n", cc, r1, r2);
	}
}
