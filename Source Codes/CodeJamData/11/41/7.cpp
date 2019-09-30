#pragma comment(linker, "/STACK:60000000")
#define _CRT_SECURE_NO_WARNINGS

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

double X, R, S, T;
int n;
vector < pair < double, double > > A;


void calccalc () {
	cin >> X >> S >> R >> T >> n;
	A.clear ();
	double pr = 0;
	forn (i, n) {
		double l, r, w;
		cin >> l >> r >> w;
		A.pb (mp (0, l - pr));
		A.pb (mp (w, r-l));
		pr = r;
	}
	A.pb (mp (0, X - pr));
	sort (all (A));
        double res = 0;
        for (int i = 0; i < I A.size(); i ++) {
                double ll = 0;
                double rr = A[i].sc;
                double ww = A[i].fs;
        	double t = min ((rr - ll) / (ww + R), T);
        	T -= t;
        	res += t;
        	ll += (ww + R) * t;
        	t = (rr - ll) / (ww + S);
        	res += t;
     	}
     	printf ("%.10lf\n", res);
	
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	int tt;
	cin >> tt;
	forn (ii, tt) {
		printf ("Case #%d: ", ii+1);
		calccalc ();
	}
	
	return 0;
}
