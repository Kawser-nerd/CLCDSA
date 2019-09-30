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

int A[2][1 << 10];
int C[2][1 << 10];

int SolveTest(int test)
{
	int N;
	scanf("%d", &N);

	int res = 0;
	CLEAR(A, -1);

	A[0][2] = 1;
	A[1][2] = 0;
	C[0][2] = C[1][2] = 1;

	A[0][1] = 0;
	A[1][1] = -1;
	C[0][1] = C[1][1] = 1;

	A[0][0] = A[1][0] = -1;
	C[0][0] = C[0][1] = 1;

	int i;
	FOR(i, 3, N)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;

		if(a < b)
			swap(a, b);

		A[0][i] = a;
		A[1][i] = b;
		C[0][i] = C[1][i] = 1;
	}

	RFOR(i, N, 2)
	{
		int a = A[0][i];
		int b = A[1][i];
		int pos = A[0][a] == b ? 0 : 1;

		res = max(res, C[0][i] + C[1][i] + C[pos][a]);

		C[pos][a] = max(C[pos][a], C[0][i] + C[1][i]);
	}

	printf("Case #%d: %d\n", test + 1, res);

	return 0;
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

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
