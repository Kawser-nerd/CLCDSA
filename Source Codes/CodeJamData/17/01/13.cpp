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
	string s;
	int K;
	
	scanf("%d\n", &T);

	REP(t, 1, T)
	{
		fprintf(stderr, "Cas %d\n", t);
		printf("Case #%d: ", t);
		
		cin >> s;
		scanf("%d\n", &K);
		int tot = 0;
		
		LOOP(i, s)
		{
			if(i+K-1 < s.size() && s[i] == '-')
			{
				//fprintf(stderr, "Change %d\n", i);
				tot++;
				REP(j, 0, K-1)
				{
					if(s[i+j] == '-') s[i+j] = '+';
					else s[i+j] = '-';
				}
			}
		}
		bool ok = true;
		LOOP(i, s)
		{
			if(s[i] == '-') ok = false;
		}
		if(ok) printf("%d\n", tot);
		else printf("IMPOSSIBLE\n");
	}
	
	return 0;
}
