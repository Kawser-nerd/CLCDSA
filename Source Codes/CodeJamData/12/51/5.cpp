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

int L[1 << 10];
int P[1 << 10];
pair<PII, int> A[1 << 10];

int Cmp(const pair<PII, int> a, const pair<PII, int>& b)
{
	int diff = a.first.first*b.first.second - a.first.second*b.first.first;
	if(diff != 0)
		return diff > 0 ? 1 : 0;

	return a.second < b.second ? 1 : 0;
}

int SolveTest(int test)
{
	int n;
	scanf("%d", &n);

	int i;
	FOR(i, 0, n)
		scanf("%d", &L[i]);
	FOR(i, 0, n)
		scanf("%d", &P[i]);

	FOR(i, 0, n)
		A[i] = MP(PII(P[i], L[i]), i);

	sort(A, A + n, Cmp);

	printf("Case #%d:", test + 1);
	FOR(i, 0, n)
		printf(" %d", A[i].second);

	printf("\n");
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
