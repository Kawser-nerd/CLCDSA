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

int A[128];

int SolveTest(int test)
{
	int a, n;
	scanf("%d%d", &a, &n);

	int i;
	FOR(i, 0, n)
		scanf("%d", &A[i]);

	sort(A, A + n);

	int pos = 0;
	int res = n;
	FOR(i, 0, n)
	{
		while(pos != n && a > A[pos])
		{
			a += A[pos];
			++pos;
		}

		res = min(res, i + n - pos);
		if(pos == n)
			break;

		a += a - 1;
	}

	printf("Case #%d: %d\n", test + 1, res);
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
