//#pragma comment(linker, "/STACK:134217728")

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

Int A[64];

int SolveTest(int test)
{
	Int b;
	int n;
	scanf("%lld%d", &b, &n);

	CLEAR(A, 0);
	int i, j, k;
	FOR(i, 0, n)
		scanf("%lld", &A[i]);

	sort(A, A + 37);

	double res = 0;
	FOR(i, 0, 37)
		FOR(j, 1, i + 1)
		{
			Int Min = -1, Max = A[i];
			while(Max - Min > 1)
			{
				Int Mid = (Max + Min)/2;

				Int sum = 0;
				FOR(k, 0, i)
				{
					Int need = Mid;
					if(k >= j)
						++need;

					sum += max(0LL, need - A[k]);
				}

				if(sum <= b)
					Min = Mid;
				else
					Max = Mid;
			}

			int fail = 0;
			Int sum = 0;
			FOR(k, 0, j)
			{
				if(A[k] > Min)
					fail = 1;

				sum += max(0LL, Min - A[k]);
			}

			if(fail != 0 || Min < 0)
				continue;

			Int all = sum;
			FOR(k, j, i)
				all += max(0LL, Max - A[k]);

			double r = 36*sum/(j + 0.0) - all;
			if(res < r)
			{
				res = r;
			}
		}

	printf("Case #%d: %.11lf\n", test + 1, res);
	return 0;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
