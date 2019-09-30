#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		int D;
		cin >> D;
		vector<int> di;
		int limit = -1;
		for(i=0; i<D; i++)
		{
			cin >> j;
			di.push_back(j);
			if (limit < j) limit = j;
		}

		int best = 1000000;
		int ht;
		for(ht=1; ht<=limit; ht++)
		{
			int r = 0;
			for(i=0; i<di.size(); i++)
			{
				if (di[i] > ht)
				{
					r += di[i]/ht-1;
					if (di[i]%ht != 0)
						r++;
				}
			}
			r += ht;
			if (r < best)
				best = r;
		}
		printf("Case #%d: %d\n", cc, best);
	}
}
