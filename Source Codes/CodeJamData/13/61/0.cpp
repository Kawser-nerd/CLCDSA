#define _CRT_SECURE_NO_WARNINGS
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

Int A[1 << 12];
Int B[1 << 12];
Int T[1 << 12];

Int find(Int a, Int b, Int t, Int c)
{
	if(a <= c && c <= b)
		return t + c - a;

	return -1;
}

int SolveTest(int test)
{
	int C;
	Int X, N;
	scanf("%d%lld%lld", &C, &X, &N);
	X += X;

	int i, j, k;
	int cnt = 0;
	FOR(i, 0, C)
	{
		Int s, e, t;
		scanf("%lld%lld%lld", &s, &e, &t);
		--s;
		--e;

		Int len = (e - s + N) % N;
		Int total = 2*len;
		Int time = 2*t;
		s = (s + t) % N;

		while(total >= 0)
		{
			Int a = min(total, N - 1 - s);

			A[cnt] = s;
			B[cnt] = s + a;
			T[cnt] = time;
			++cnt;

			s = (s + a + 1) % N;
			time = time + a + 1;
			total -= a + 1;
		}
	}

	vector<Int> v;
	v.PB(0);
	v.PB(N - 1);
	FOR(i, 0, cnt)
	{
		Int arr[] = {A[i], B[i]};
		FOR(j, 0, 2)
			FOR(k, -1, 2)
			{
				Int a = arr[j] + k;
				if(0 <= a && a < N)
					v.PB(a);
			}
	}

	sort(ALL(v));
	v.resize(unique(ALL(v)) - v.begin());

	Int res = 0;
	FOR(i, 0, SIZE(v))
	{
		vector<Int> w;
		w.PB(-1);
		w.PB(X + 1);
		FOR(j, 0, cnt)
		{
			Int time = find(A[j], B[j], T[j], v[i]);
			if(time != -1)
				w.PB(time);
		}

		sort(ALL(w));
		FOR(j, 1, SIZE(w))
		{
			Int a = w[j - 1] + 1;
			Int b = w[j] - 1;
			if(a % 2 != 0)
				++a;
			if(b % 2 != 0)
				--b;

			res = max(res, (b - a)/2);
		}
	}

	printf("Case #%d: %lld\n", test + 1, res);
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
