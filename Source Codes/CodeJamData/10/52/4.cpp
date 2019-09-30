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

int Res[1 << 17];
int B[1 << 17];
int A[128];

int SolveTest(int test)
{
	Int L;
	int N;
	scanf("%lld%d", &L, &N);

	int i, j;
	FOR(i, 0, N)
		scanf("%d", &A[i]);

	sort(A, A + N);
	int P = A[N - 1];

	CLEAR(Res, -1);
	CLEAR(B, 0);
	Res[0] = 0;
	deque<int> Q;
	Q.push_back(0);
	Int res = -1;
	while(!Q.empty())
	{
		int a = Q.front();
		Q.pop_front();
		if(B[a] != 0)
			continue;

		if(a == L % P)
		{
			res = L/P + Res[a];
			break;
		}

		B[a] = 1;
		FOR(j, 0, N)
		{
			int b = a + A[j];
			if(b < P)
			{
				if(Res[b] == -1)
				{
					Res[b] = Res[a] + 1;
					Q.push_back(b);
				}
			}
			else
			{
				if(Res[b - P] == -1 || Res[b - P] > Res[a])
				{
					Res[b - P] = Res[a];
					Q.push_front(b - P);
				}
			}
		}
	}

	if(res == -1)
		printf("Case #%d: IMPOSSIBLE\n", test + 1);
	else
		printf("Case #%d: %lld\n", test + 1, res);

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
