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


using namespace std;

int main()
{
	int T;
	int N, J;
	
	scanf("%d\n", &T);

	for(int t = 1; t <= T; t++)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d:\n", t);

		scanf("%d %d", &N, &J);
		
		if(N == 16)
		{
			REP(i, 0, J-1)
			{
				bool yes[7];
				REP(j, 0, 6)
				{
					if((i & (1 << j))) yes[j] = true;
					else yes[j] = false;
				}
				printf("1");
				REP(j, 0, 6)
				{
					if(yes[j]) printf("1");
					else printf("0");
				}
				REP(j, 0, 6)
				{
					if(yes[6-j]) printf("1");
					else printf("0");
				}
				printf("1");
				
				printf(" 3 2 5 2 7 2 3 2 11\n");
			}
		}
		
		if(N == 32)
		{
			REP(i, 0, J-1)
			{
				bool yes[15];
				REP(j, 0, 14)
				{
					if((i & (1 << j))) yes[j] = true;
					else yes[j] = false;
				}
				printf("1");
				REP(j, 0, 14)
				{
					if(yes[j]) printf("1");
					else printf("0");
				}
				REP(j, 0, 14)
				{
					if(yes[14-j]) printf("1");
					else printf("0");
				}
				printf("1");
				
				printf(" 3 2 5 2 7 2 3 2 11\n");
			}
		}
		
	}

	return 0;
}
