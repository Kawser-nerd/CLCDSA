#pragma comment(linker, "/STACK:32000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <stdarg.h>
#include <memory.h>
#include <string.h>

using namespace std;

const double pi = 3.1415926535897932384626433832795;
#define ALL(x) x.begin(), x.end()
#define LL long long
#define MP make_pair
#define PB push_back
#define CLR(a,b) memset(a, b, sizeof(a))
template<class T> inline T Sqr(const T &x) { return x*x; }
template<class T> inline T Abs(const T &x) { return x >= 0 ? x : -x; }
#define fo(i, n) for (int i = 0; i < (n); i++)
#define foz(i, a) for (int i = 0; i < (a).size(); i++)

void init()
{

}

#define maxn 1005

int a[maxn], b[maxn];
int state[maxn];
int n;

void solvecase()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
	for (int i = 0; i < n; i++)
	{
		state[i] = 0;
	}
	int cur = 0, complete = 0, res = 0;
	while (complete < n)
	{
		bool f = false;
		for (int i = 0; i < n; i++) if (state[i] != 2 && cur >= b[i])
		{
			cur += 2 - state[i];
			state[i] = 2;
			complete++;
			res++;
			f = true;
			break;
		}
		if (f) continue;
		int idx = -1;
		for (int i = 0; i < n; i++) if (state[i] == 0 && cur >= a[i])
		{
			if (idx == -1 || b[i] > b[idx]) idx = i;			
		}
		if (idx == -1)
		{
			printf("Too Bad");
			return;
		}
		state[idx] = 1;
		cur++;
		res++;		
	}
	printf("%d", res);
}

void solve() {
	init();
	int n_tests;
	scanf("%d", &n_tests);
	for (int i = 1; i <= n_tests; i++)
	{
		printf("Case #%d: ", i);
		solvecase();
		printf("\n");
	}
}

#define problem_letter "B"
//#define fname "test"
//#define fname problem_letter "-small-attempt0"
//#define fname problem_letter "-small-attempt1"
//#define fname problem_letter "-small-attempt2"
#define fname problem_letter "-large"

int main()
{
	freopen(fname ".in", "r", stdin);
	freopen(fname ".out", "w", stdout);
	solve();
	return 0;
}