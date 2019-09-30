#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cctype>
#include <memory>
#include <vector>
#include <list>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long Int;
typedef long double Double;
typedef vector<int> VInt;
typedef vector< vector<int> > VVInt;
typedef pair<int,int> PII;

#define FOR(i,n,m) for(i=(n); i<(m); ++i)
#define RFOR(i,n,m) for(i=(n)-1; i>=(m); --i)
#define CLEAR(x,y) memset((x), (y), sizeof(x))
#define COPY(x,y) memcpy((x),(y),sizeof(x))
#define PB push_back
#define MP make_pair
#define SIZE(v) ((int)((v).size()))
#define ALL(v) (v).begin(), (v).end()

char S[110];
int U[110];
int V[300];

int main()
{
//	freopen("A-small.in", "r", stdin);
//	freopen("A-small.out", "w", stdout);
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T, t;
	scanf("%d", &T);
	for (t = 0; t < T; ++t)
	{
		CLEAR(V, -1);
		CLEAR(U, 0);
		scanf("%s", S);
		int i, j;
		V[S[0]] = 1;
		U[1] = 1;
		int m = 1;
		for (i = 1; S[i]; ++i)
			if (V[S[i]] == -1)
			{
				j = 0;
				while (U[j])
					++j;
				V[S[i]] = j;
				U[j] = 1;
				m = max(m, j);
			}
		++m;
		Int res = 0;
		for (i = 0; S[i]; ++i)
		{
			res = res * m + V[S[i]];
		}
		printf("Case #%d: %lld\n", t+1, res);
	}
	return 0;
}