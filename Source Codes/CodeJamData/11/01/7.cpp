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

int solve(){
	int n, res, a, b;
	a = b = 0;
	res = 0;
	cin >> n;
	int now[2], t[2];
	now[0] = now[1] = 1;
	t[0] = t[1] = 0;
	forn(i, n){
		char a;
		int x;
		cin >> a >> x;
		int add = 0;
		if (a == 'O') a = 0;
		else
		a = 1;
		int q = fabs(now[a] - x);
		q = max(0, q - t[a]);
		t[a^1] += q+1;
		t[a] = 0;
		res += q+1;
		now[a] = x;
	}
	return res;
}	        

int main ()
{
	int tst;
	cin >> tst;
	forn(i, tst)
		printf("Case #%d: %d\n", i + 1, solve());
		return 0;
}
