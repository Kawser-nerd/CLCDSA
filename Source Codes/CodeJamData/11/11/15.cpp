#include <assert.h> 
#include <ctype.h> 
#include <float.h> 
#include <math.h> 
#include <stdio.h> 
#include <string> 
#include <stdlib.h> 
#include <time.h> 
#include <algorithm> 
#include <numeric> 
#include <functional> 
#include <utility> 
#include <vector> 
#include <list> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <sstream> 
#include <iostream> 
#include <memory.h>

using namespace std; 

#define rep(i,n) for(int i=0;i<(n);++i)
#define clr(a,b) memset(a,b,sizeof(a)); 
#define all(c) (c).begin(), (c).end() 
#define inf 1000000000 

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<int> vi;


int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);

	for (int nTest = 1; nTest <= T; nTest++)
	{		
		long long N, PD, PG;
		cin >> N >> PD >> PG;

		bool ok = false;

		for (ll D = 1; D <= N; D++)
		{
			if (D > 10000)
				break;

			if ((D * PD) % 100 != 0)
				continue;

			int winToday = D * PD / 100;
			
			if (winToday != D && PG == 100)
				continue;

			if (winToday != 0 && PG == 0)
				continue;

			ok = true;
			break;
		}
		



		printf("Case #%d: %s\n", nTest, ok ? "Possible" : "Broken");
		fflush(stdout);
	} 

 
	return 0;
}


