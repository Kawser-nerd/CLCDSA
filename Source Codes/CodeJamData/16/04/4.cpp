#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)
#define LOOP(i, v) for(int i = 0; i < v.size(); i++)
#define EPS 1e-9
#define INF 1e12
#define debug(x) cerr << "DEBUG : " << (#x) << " => " << (x) << endl


int main()
{
	int T;
	int K, C, S;
	
	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d:", t);
		
		scanf("%d %d %d\n", &K, &C, &S);
		
		if(S*C < K) printf(" IMPOSSIBLE\n");
		else
		{
			int x = 0;
			while(x < K)
			{
				cerr << x << endl;
				// (x, x+1, ..., x+C-1)
				long long int h = 0;
				REP(i, x, min(x+C-1, K-1))
				{
					h *= K;
					h += i;
				}
				printf(" %lld", h+1);
				x += C;
			}
			printf("\n");
		}

	}
	return 0;
}
