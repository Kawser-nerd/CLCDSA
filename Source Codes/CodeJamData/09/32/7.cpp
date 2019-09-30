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

#define eps 1e-9

#define FOR(i,n,m) for(i=(n); i<(m); ++i)
#define RFOR(i,n,m) for(i=(n)-1; i>=(m); --i)
#define CLEAR(x,y) memset((x), (y), sizeof(x))
#define COPY(x,y) memcpy((x),(y),sizeof(x))
#define PB push_back
#define MP make_pair
#define SIZE(v) ((int)((v).size()))
#define ALL(v) (v).begin(), (v).end()

int main()
{
//	freopen("B-small.in", "r", stdin);
//	freopen("B-small.out", "w", stdout);
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T, ts;
	scanf("%d", &T);
	for (ts = 0; ts < T; ++ts)
	{
		int N;
		double V[3] = {0};
		int VI[3] = {0};
		double X[3] = {0};
		scanf("%d", &N);
		int i, j;
		for (i = 0; i < N; ++i)
		{
			for (j = 0; j < 3; ++j)
			{
				int a;
				scanf("%d", &a);
				X[j] += a;
			}
			for (j = 0; j < 3; ++j)
			{
				int a;
				scanf("%d", &a);
				V[j] += a;
				VI[j] += a;
			}
		}
		for (i = 0; i < 3; ++i)
		{
			X[i] /= N;
			V[i] /= N;
		}
		double t = 0, z = 0;
		for (i = 0; i < 3; ++i)
		{
			t -= V[i]*X[i];
			z += V[i]*V[i];
		}
		double r0 = sqrt(X[0]*X[0] + X[1]*X[1] + X[2]*X[2]);
		double rd, rt;
		if (VI[0] == 0 && VI[1] == 0 && VI[2] == 0)
		{
			rd = r0;
			rt = 0;
		}
		else
		{
			t /= z;
			if (t > 0)
			{
				double r = sqrt((X[0]+V[0]*t)*(X[0]+V[0]*t) + (X[1]+V[1]*t)*(X[1]+V[1]*t) + (X[2]+V[2]*t)*(X[2]+V[2]*t));
				if (r + eps < r0)
				{
					rd = r;
					rt = t;
				}
				else
				{
					rd = r0;
					rt = 0;
				}
			}
			else
			{
				rd = r0;
				rt = 0;
			}
		}

		printf("Case #%d: %.8lf %.8lf\n", ts+1, rd, rt);

	}
	return 0;
}