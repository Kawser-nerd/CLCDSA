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
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int t[1010];
int used[1010];
int n;
double f[1010];

void solve(){
	memset(used, 0, sizeof used);
	cin >> n;
	forn(i, n){
		cin >> t[i];
		t[i] --;
	}
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		f[i] = f[i-1] * 2.0;
	f[0] = 0;
	double res = 0;
	for (int i = 0; i < n; i++)
		if (!used[i]){
			int c = 0;
			for (int j = i; !used[j]; j = t[j]){
				used[j] ++;
				c ++;
			}
			if (c > 1)
				res += c;
		}
	printf("%0.9lf\n", res);
}


int main ()
{
	int tst;
	cin >> tst;
	forn(i, tst){
		printf("Case #%d: ", i + 1);
		solve();
	}

		return 0;
}
