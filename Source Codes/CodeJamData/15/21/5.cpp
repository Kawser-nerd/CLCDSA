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

Int rev(Int n, Int mod)
{
	Int res = 0;
	while (mod != 1)
	{
		res = 10 * res + n % 10;
		n /= 10;
		mod /= 10;
	}

	return res;
}

Int f(Int n)
{
	if (n < 10)
		return n;

	Int res = 10;
	Int num = 10;
	Int left = 10;
	Int right = 10;
	while (10 * num <= n)
	{
		res += left + right - 1;
		num *= 10;
		if (left < right)
			left *= 10;
		else
			right *= 10;
	}

	Int r = n - num;

	Int a = n % right;
	Int b = rev(n / right, left);

	if (b == 1)
		return res + a;

	if (a != 0)
		r = min(r, a + b);
	else
	{
		Int c = rev(n / right - 1, left);
		r = min(r, right + c);
	}

	return r + res;
}

int SolveTest(int test)
{
	Int n;
	scanf("%lld", &n);
	printf("Case #%d: %lld\n", test + 1, f(n));
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
