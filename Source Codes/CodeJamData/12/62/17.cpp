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

double AS[1 << 20];
double AX[1 << 20];
double BS[1 << 20];
double BX[1 << 20];

int Cmp(const pair<PII, int>& a, const pair<PII, int>& b)
{
	Int aa = a.first.first;
	Int bb = b.first.first;
	aa *= b.first.second;
	bb *= a.first.second;

	if(aa != bb)
		return aa < bb;

	return a.second > b.second;
}


void F(const vector< pair<PII, int> >& v, double S[], double X[])
{
	S[0] = 1;
	X[0] = 1;
	int i, j;
	int cnt = 1;
	FOR(i, 0, SIZE(v))
	{
		int t = v[i].second;
		int a = v[i].first.first;
		int b = v[i].first.second;

		FOR(j, 0, t)
		{
			X[cnt] = X[cnt - 1]*(b - a);
			X[cnt] /= b;

			S[cnt] = S[cnt - 1]*a;
			S[cnt] /= b;
			S[cnt] += X[cnt];
			++cnt;
		}
	}
}

int SolveTest(int test)
{
	int n, k;
	scanf("%d%d", &n, &k);

	vector< pair<PII, int> > v;
	int i, j;
	FOR(i, 0, n)
	{
		int a, b, c;
		scanf("%d/%d%d", &a, &b, &c);
		v.PB(MP(PII(a, b), c));
	}

	sort(ALL(v), Cmp);

	F(v, AS, AX);
	reverse(ALL(v));
	FOR(i, 0, n)
		v[i].first.first = v[i].first.second - v[i].first.first;

	F(v, BS, BX);

	double res = 0;
	FOR(i, 0, k + 1)
	{
		double t = AS[i]*BX[k - i] + BS[k - i]*AX[i] - AX[i]*BX[k - i];
		res = max(res, t);
	}

	printf("Case #%d: %.7lf\n", test + 1, 1.0 - res);
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
