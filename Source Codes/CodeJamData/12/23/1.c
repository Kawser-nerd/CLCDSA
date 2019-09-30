#include <map>
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

int N;
int n[30];

int main()
{
	int cc,ca;
	int i,j,k;

	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> N;
		for(i=0; i<N; i++) cin >> n[i];
		map<int, vector<int> > ss;

		printf("Case #%d:\n", cc);
		int r1=0,r2=0;
		for(k=1; k<(1<<N); k++)
		{
			vector<int> v;
			int s = 0;
			for(i=0; i<N; i++)
			{
				if ((k&(1<<i)) != 0)
					s += n[i];
			}
			int found = 0;
			for(i=0; i<ss[s].size(); i++)
			{
				if ( (ss[s][i] & k) == 0)
				{
					found = ss[s][i];
					break;
				}
			}
			if (found > 0)
			{
				r1 = found; r2 = k; break;
			}
			ss[s].push_back(k);
		}
		if (r1 == 0)
			printf("Impossible\n");
		else
		{
			int f = 0;
			for(i=0; i<N; i++)
			{
				if ( (r1&(1<<i)) != 0)
				{
					if (f++ > 0) printf(" ");
					printf("%d", n[i]);
				}
			}
			printf("\n");
			f = 0;
			for(i=0; i<N; i++)
			{
				if ( (r2&(1<<i)) != 0)
				{
					if (f++ > 0) printf(" ");
					printf("%d", n[i]);
				}
			}
			printf("\n");

		}
	}
}
