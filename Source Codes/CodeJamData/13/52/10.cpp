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

int X[1 << 10];
int Y[1 << 10];
int Z[1 << 10];
int I[1 << 10];
int B[1 << 10];
int S[1 << 10];
int S1[1 << 10];
int S2[1 << 10];

Int dist2(Int x, Int y)
{
	return x*x + y*y;
}

Int cross(Int x1, Int y1, Int x2, Int y2)
{
	return x1*y2 - y1*x2;
}

int Cmp(int a, int b)
{
	Int c = cross(X[a], Y[a], X[b], Y[b]);
	if(c != 0)
		return c > 0;

	return dist2(X[a], Y[a]) < dist2(X[b], Y[b]);
}

Int area(int S[], int n)
{
	int i;
	Int res = 0;
	FOR(i, 0, n)
	{
		int a = S[i];
		int b = S[(i + 1) % n];

		res += cross(X[a], Y[a], X[b], Y[b]);
	}

	if(res < 0)
		res = -res;

	return res;
}

int SolveTest(int test)
{
	int n;
	scanf("%d", &n);

	int i;
	FOR(i, 0, n)
		scanf("%d%d", &X[i], &Y[i]);

	PII Min(X[0], Y[0]);

	FOR(i, 0, n)
		Min = min(Min, PII(X[i], Y[i]));

	FOR(i, 0, n)
	{
		X[i] -= Min.first;
		Y[i] -= Min.second;
	}

	FOR(i, 0, n)
		I[i] = i;

	FOR(i, 0, n)
		if(X[i] == 0 && Y[i] == 0)
			break;

	if(i != 0)
		swap(I[0], I[i]);

	sort(I + 1, I + n, Cmp);

	int pos = n - 1;
	while(true)
	{
		int a = I[n - 1];
		int b = I[pos];

		if(cross(X[a], Y[a], X[b], Y[b]) != 0)
			break;

		--pos;
	}

	reverse(I + pos + 1, I + n);

	S[0] = I[0];
	S[1] = I[1];
	int cnt = 2;
	FOR(i, 2, n)
	{
		while(true)
		{
			if(cnt < 2)
				throw 0;

			int a = S[cnt - 1];
			int b = S[cnt - 2];
			int c = I[i];

			Int x1 = X[a] - X[b];
			Int y1 = Y[a] - Y[b];
			Int x2 = X[c] - X[a];
			Int y2 = Y[c] - Y[a];

			if(cross(x1, y1, x2, y2) >= 0)
				break;

			--cnt;
		}

		S[cnt] = I[i];
		++cnt;
	}

	CLEAR(B, 0);
	FOR(i, 0, cnt)
		B[ S[i] ] = 1;

	int cnt1 = 0;
	FOR(i, 0, cnt)
	{
		S1[cnt1] = S[i];
		++cnt1;
	}

	RFOR(i, n, 0)
	{
		int a = I[i];
		if(B[a] != 0)
			continue;

		S1[cnt1] = a;
		++cnt1;
	}

	FOR(i, 0, n)
		S2[i] = I[i];

	Int a1 = area(S1, n);
	Int a2 = area(S2, n);
	Int a3 = area(S, cnt);

	if(a1 + a2 <= a3)
		throw 0;

	if(a2 > a1)
	{
		FOR(i, 0, n)
			S1[i] = S2[i];
	}

	printf("Case #%d: ", test + 1);
	FOR(i, 0, n)
		printf("%d%c", S1[i], i == n - 1 ? '\n' : ' ');

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
