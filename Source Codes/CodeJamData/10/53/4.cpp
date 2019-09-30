#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
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

int A[1 << 10];

int SolveTest(int test)
{
	int N;
	scanf("%d", &N);
	int i, j;
	int cnt = 0;
	FOR(i, 0, N)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		FOR(j, 0, b)
		{
			A[cnt] = a;
			++cnt;
		}
	}

	N = cnt;

	int res = 0;
	while(true)
	{
		sort(A, A + N);
		FOR(i, 0, N - 1)
			if(A[i] == A[i + 1])
				break;

		if(i == N - 1)
			break;

		--A[i];
		++A[i + 1];
		++res;
	}

	printf("Case #%d: %d\n", test + 1, res);

	return 0;
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

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
