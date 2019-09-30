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

#define MOD 1000000007

string S[256];
int A[256];
int C[256];
int Next[256];
int Prev[256];
int B[256];

Int dfs(int a)
{
	if (a == -1)
		return 1;

	B[a] = 1;
	Int res = 1;

	int i;
	FOR(i, 0, C[a])
		res = res * (i + 1) % MOD;

	return res * dfs(Next[a]) % MOD;
}

Int f(int n)
{
	CLEAR(A, 0);
	CLEAR(C, 0);
	CLEAR(Next, -1);
	CLEAR(Prev, -1);

	int i, j;
	FOR(i, 0, n)
	{
		char first = S[i].front();
		char last = S[i].back();
		FOR(j, 1, SIZE(S[i]) - 1)
		{
			char mid = S[i][j];
			if (A[mid] == 0)
				++A[mid];
			else
				return 0;
		}

		if (first == last)
		{
			if (SIZE(S[i]) == 1)
				++C[first];
			else
				return 0;
		}
		else
		{
			if (Next[first] != -1)
				return 0;
			if (Prev[last] != -1)
				return 0;

			Next[first] = last;
			Prev[last] = first;
		}
	}

	FOR(i, 0, 256)
	if (A[i] != 0 && (C[i] != 0 || Next[i] != -1 || Prev[i] != -1))
		return 0;

	Int res = 1;
	int cnt = 0;
	CLEAR(B, 0);
	FOR(i, 0, 256)
	if (B[i] == 0 && Prev[i] == -1)
	{
		if (C[i] != 0 || Next[i] != -1)
			++cnt;

		res *= dfs(i);
		res %= MOD;
	}

	FOR(i, 0, cnt)
		res = res * (i + 1) % MOD;

	FOR(i, 0, 256)
	if (B[i] == 0)
		return 0;

	return res;
}

int SolveTest(int test)
{
	int n;
	scanf("%d", &n);

	int i, j;
	FOR(i, 0, n)
	{
		char buf[128];
		scanf("%s", buf);
		int len = strlen(buf);

		string s;
		int prev = 0;
		FOR(j, 1, len + 1)
		if (j == len || buf[j] != buf[prev])
		{
			s.push_back(buf[prev]);
			prev = j;
		}

		S[i] = s;
	}

	printf("Case #%d: %d\n", test + 1, int(f(n)));

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
