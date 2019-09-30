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

int A[64];
int L[64];
int R[64];

int SolveTest(int test)
{
	int n;
	scanf("%d", &n);

	int i;
	FOR(i, 0, n - 1)
		scanf("%d%d", &L[i + 1], &R[i + 1]);

	int limit = (1 << n)*n + 1;
	int cnt = 0;
	int pos = 1;
	CLEAR(A, 0);
	while(pos != n && cnt != limit)
	{
		int next = A[pos] == 1 ? R[pos] : L[pos];
		A[pos] ^= 1;
		pos = next;
		++cnt;
	}

	if(cnt == limit)
		printf("Case #%d: Infinity\n", test + 1);
	else
		printf("Case #%d: %d\n", test + 1, cnt);

	return 0;
}

int main()
{
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);

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
