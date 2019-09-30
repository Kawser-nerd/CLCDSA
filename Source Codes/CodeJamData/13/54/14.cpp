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

char buf[256];
int B[21][1 << 20];
double R[21][1 << 20];

double f(int n, int mask)
{
	double& res = R[n][mask];
	if(B[n][mask] != -1)
		return res;

	B[n][mask] = 0;

	int i, j, k;
	int m = mask;
	FOR(i, 0, n)
	{
		int b = m & 1;
		m = ((b << n) | m) >> 1;
		if(m < mask)
			return res = f(n, m);
	}

	res = 0.0;
	if(mask == (1 << n) - 1)
		return res;

	int last = 0;
	RFOR(i, n, 0)
	{
		if((mask & (1 << i)) == 0)
			last = i;

		res += f(n, mask | (1 << last)) + n - (last - i);
	}

	res /= n;
	return res;
}

int SolveTest(int test)
{
	scanf("%s", buf);

	int n = strlen(buf);

	int i;
	int mask = 0;
	FOR(i, 0, n)
		if(buf[i] == 'X')
			mask |= 1 << i;

	printf("Case #%d: %.11lf\n", test + 1, f(n, mask));
	return 0;
}

int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);

	CLEAR(B, -1);
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
