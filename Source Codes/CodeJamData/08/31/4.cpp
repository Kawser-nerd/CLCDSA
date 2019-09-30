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

int A[1 << 20];

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T, t;
	scanf("%d", &T);
	FOR(t, 0, T)
	{
		int P, K, L;
		scanf("%d%d%d", &P, &K, &L);

		int i;
		Int res = 0;
		FOR(i, 0, L)
			scanf("%d", &A[i]);

		sort(A, A + L);

		FOR(i, 0, L)
		{
			int a = A[L - 1 - i];
			res += (1 + i/K)*a;
		}

		printf("Case #%d: %lld\n", t + 1, res);
	}

	return 0;
};
