
#define _CRT_SECURE_NO_DEPRECATE 

#include <string> 
#include <vector> 
#include <map> 
#include <list> 
#include <set> 
#include <queue> 
#include <iostream> 
#include <sstream> 
#include <stack> 
#include <deque> 
#include <cmath> 
#include <memory.h> 
#include <cstdlib> 
#include <cstdio> 
#include <cctype> 
#include <algorithm> 
#include <utility> 

using namespace std; 

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define RFOR(i, b, a) for(int i = b - 1; i >= a; --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define MIN(A, B) ((A) < (B) ? (A) : (B))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define ABS(A) ((A) < 0 ? (-(A)) : (A))
#define ALL(V) V.begin(), V.end()
#define SIZE(V) (int)V.size()
#define pb push_back
#define mp make_pair
#define EPS 1e-7
#define Pi 3.14159265358979

typedef long long Long;
typedef unsigned long long ULong;
typedef unsigned int Uint;
typedef unsigned char Uchar;
typedef vector <int> VI;
typedef pair <int, int> PI;

#define SZ 10

int tests;

int t[SZ];

int n;

int gcd(int a, int b)
{
	while(a && b)
	{
		a %= b;
		swap(a, b);
	}
	return a + b;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &tests);
	REP(I, tests)
	{
		scanf("%d", &n);
		REP(i, n)
			scanf("%d", &t[i]);
		sort(t, t + n);
		int g = t[n - 1] - t[0];
		FOR(i, 1, n - 1)
			g = gcd(g, t[n - 1] - t[i]);
		int y = ((-t[0])%g + g)%g;
		printf("Case #%d: %d\n", I + 1, y);
	}
	return 0;
}