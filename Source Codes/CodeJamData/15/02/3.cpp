#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;


int main()
{
	int T;
	int D;
	int possible, best;
	int P[1005];

	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);

		scanf("%d", &D);

		for(int i = 0; i < D; i++)
		{
			scanf("%d", &P[i]);
		}

		best = 10000;

		for(int x = 1005; x >= 1; x--)
		{
			// We try to only have pots with maximum x
			int moves = 0;
			for(int i = 0; i < D; i++)
			{
				if(P[i] % x == 0) moves += P[i]/x - 1;
				else
				{
					moves += P[i]/x;
				}
			}
			possible = moves + x;
			best = min(best, possible);
		}
		printf("%d\n", best);
	}

	return 0;
}
