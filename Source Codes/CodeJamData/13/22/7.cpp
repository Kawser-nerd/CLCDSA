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

const int nmax = 100100;

int n, x, y;
int cnt[nmax];

int write(double p) {
	printf("%0.9lf\n", p);
	return 0;
}

double calc(int l, int r, int len, int y) {
	if (l > 2 * len) {
		r += l - 2 * len;
		l = 2 * len;
	}
	if (r > 2 * len) {
		l += r - 2 * len;
		r = 2 * len;
	}
//	cerr << " " << l << " " << r << " " << y << endl;

	if (r > y) return 1;
	return 0;
}

int solve(){
	x = abs(x);
	if ((x + y) % 2 != 0) return write(0);
	int now = 1;
	int len = 1;
	int h = 0;
	while (now + len * 4 + 1 <= n) {
		h += 2;
		now += len * 4 + 1;
		len ++;
	}
	if (x + y <= h) return write(1);
	int rem = n - now;
//	cerr << h << " " << len << " "<< rem << endl;
	if (rem == 0) return write(0);
	if (x + y > h + 2) return write(0);
//	write(0.5);
	{
	double res = 0;
	double now = 1;//pow(0.5, rem + .0);
	int q = rem;
	for (int i = 0; i <= rem; i ++) {
		res += calc(i, rem - i, len, y) * now * pow(0.5, q + .0);
		now = now * (rem - i) / (i + 1);
		while (q > 0 && now > 1) {
			now /= 2;
			q --;
		}
	}
	write(res);
	}
	return 0;
}

int main ()
{
//	freopen("input.txt", "r", stdin);
	int n1;
	cin >> n1;

	forn(i, n1){
		cin >> n >> x >> y;
		printf("Case #%d: ", i + 1);
		solve();
	}

	
	return 0;
}
