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

int N, K;
int64 B, T;
int64 x[50], v[50];

void calc ()
{
	cin >> N >> K >> B >> T;
	forn (i, N)
		cin >> x[i];
	forn (i, N)
		cin >> v[i];
	int res = 0;
	int p = 0;
	ford (i, N)
	{
		if (K == 0)
			break;
		if ((B - x[i]) <= T * v[i])
		{
			K --;
			res += p;
		}
		else
			p ++;
	}
	if (K > 0)
		printf ("IMPOSSIBLE\n");
	else
		printf ("%d\n", res);			
}

int main ()
{
	int tt;
	scanf ("%d", &tt);
	forn (ii, tt)
	{
	        printf ("Case #%d: ", ii+1);
		calc ();
	}
	return 0;
}
