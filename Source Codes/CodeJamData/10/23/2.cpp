#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <complex>
#include <queue>
#include <functional>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;

template <class T> T sqr (T x) {return x * x;}

int n;
const int P = 100003;
int t[501][501];
int c[501][501];

int go (int n, int v)
{
	if (t[n][v] != -1)
		return t[n][v];
	if (v == 1)
		return t[n][v] = 1;
	int res = 0;
	for (int i = 1; i < v; i ++)
		res = ((int64)res + (int64)c[n-v-1][v-i-1] * (int64)go (v, i)) % (int64)P;
	return t[n][v] = res;
}

void calc ()
{
	int res = 0;
	cin >> n;
	for (int i = 1; i < n; i ++)
		res = (res + go (n, i)) % P;
	printf ("%d\n", res);
}

int main ()
{
	seta (t, 255);
	seta (c, 0);
	for (int i = 0; i <= 500; i ++)
		c[i][0] = 1;
	for (int i = 1; i <= 500; i ++)
		for (int j = 1; j <= i; j ++)
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % P;
	int tt;
	scanf ("%d", &tt);
	forn (ii, tt)
	{
	        printf ("Case #%d: ", ii+1);
		calc ();
	}
	return 0;
}
