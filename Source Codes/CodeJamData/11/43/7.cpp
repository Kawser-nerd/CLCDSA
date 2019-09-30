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

bool u[1000001];
vector <int64> primes;

void calccalc () {
	int64 n;
	cin >> n;
	int64 res = 1;
	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	forn (i, primes.size()) {
		int64 v = primes[i] * primes[i];
		while (v <= n) {
			res ++;
			v *= primes[i];
		}
	}
	cout << res << endl;
}

int main ()
{
//	freopen ("input.txt", "r", stdin);
//	freopen ("output.txt", "w", stdout);
	seta (u, 0);
	for (int i = 2; i <= 1000000; i ++)
		if (!u[i]) {
			primes.pb (i);
			int64 v = i;
			while (v <= 1000000) {
				u[v] = 1;
				v += i;
			}
		}	
	int tt;
	cin >> tt;
	forn (ii, tt) {
		printf ("Case #%d: ", ii+1);
		calccalc ();
	}
	return 0;
}
