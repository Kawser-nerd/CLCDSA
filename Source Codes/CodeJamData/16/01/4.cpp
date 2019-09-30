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
	int T, N;
	bool seen[10];
	int tot;
	
	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);
		
		scanf("%d", &N);
		
		if(N == 0) printf("INSOMNIA\n");
		else
		{
			REP(i, 0, 9) seen[i] = false;
			tot = 0;
			for(int k = 1; ; k++)
			{
				int M = k*N;
				while(M > 0)
				{
					int d = M%10;
					if(!seen[d])
					{
						seen[d] = true;
						tot++;
					}
					M = M/10;
				}
				if(tot == 10)
				{
					printf("%d\n", k*N);
					break;
				}
			}
		}
	}
	
	return 0;
}
