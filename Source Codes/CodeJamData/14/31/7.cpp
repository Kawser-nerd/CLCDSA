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

Int gcd(Int a, Int b)
{
	return a == 0 ? b : gcd(b % a, a);
}

int SolveTest(int test)
{
	Int p, q;
	scanf("%lld/%lld", &p, &q);

	Int g = gcd(p, q);
	p /= g;
	q /= g;

	Int t = 1;
	int cnt = 0;
	while (t < q)
	{
		t <<= 1;
		++cnt;
	}

	if (t != q)
		printf("Case #%d: impossible\n", test + 1);
	else
	{
		while (p != 1)
		{
			p >>= 1;
			--cnt;
		}

		printf("Case #%d: %d\n", test + 1, cnt);
	}

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
