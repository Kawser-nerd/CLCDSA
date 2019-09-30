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

char buf[1 << 20];

int SolveTest(int test)
{
	int N, M;
	scanf("%d%d", &N, &M);

	set<string> Set;
	Set.insert("");

	int i, j;
	FOR(i, 0, N)
	{
		scanf("%s", buf);
		Set.insert(buf);
	}

	int res = SIZE(Set);
	FOR(i, 0, M)
	{
		scanf("%s", buf);
		Set.insert(buf);

		int len = strlen(buf);
		FOR(j, 0, len + 1)
			if(buf[j] == '/' || buf[j] == 0)
			{
				buf[j] = 0;
				Set.insert(buf);
				buf[j] = '/';
			}
	}

	printf("Case #%d: %d\n", test + 1, SIZE(Set) - res);

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
