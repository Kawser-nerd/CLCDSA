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

int a, n;
int x[120];

int solve(){
	cin >> a >> n;
	forn(i, n)
		cin >> x[i];
	sort(x, x + n);
	int res = n;
	int now = a;
	int cur = 0;
	forn(i, n) {
		while (x[i] >= now) {
			if (now == 1) break;
			now += now - 1;
			cur ++;
		}
		if (x[i] >= now) break;
		now += x[i];
		res = min(res, cur + n - i - 1);
	}
	cout << res << endl;
}

int main ()
{
	int n;
	cin >> n;

	forn(i, n){
		printf("Case #%d: ", i + 1);
		solve();
	}

	
	return 0;
}
