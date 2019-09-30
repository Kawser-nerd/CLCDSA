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

int P[110];
int R[110][110];

int main()
{
//	freopen("C-small.in", "r", stdin);
//	freopen("C-small.out", "w", stdout);
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	int T, t;
	scanf("%d", &T);
	for (t = 0; t < T; ++t)
	{
		int	M, N;
		scanf("%d%d", &M, &N);
		int i;
		for (i = 0; i < N; ++i)
			scanf("%d", &P[i]);
		P[i] = 0;
		P[i+1] = M+1;
		N += 2;
		sort(P, P + N);
		CLEAR(R, 0);
		int L;
		for (L = 2; L < N; ++L)
			for (i = 0; i+L < N; ++i)
			{
				int e = i+L;
				R[i][e] = 1000000000;
				int j;
				for (j = i+1; j < e; ++j)
					R[i][e] = min(R[i][e], R[i][j] + R[j][e] + P[e]-P[i]-2);
			}
		int res = R[0][N-1];
		printf("Case #%d: %d\n", t+1, res);
	}
	return 0;
}