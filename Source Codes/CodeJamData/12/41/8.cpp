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

const int nmax = 10100;

int n;
int d[nmax], l[nmax], t[nmax];

void solve(){
	cin >> n;
	forn(i, n)
		cin >> d[i] >> l[i];
	int fin;
	cin >> fin;
	memset(t, 0, sizeof t);
	t[0] = d[0];
	bool win = 0;
	forn(i, n){
		if (d[i] + t[i] >= fin)
			win = 1;
		for (int j = i + 1; j < n; j ++)
			if (d[i] + t[i] >= d[j])
				t[j] = max(t[j], min(l[j], d[j] - d[i]));
	}
	if (win)
		puts("YES");
	else
		puts("NO");

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
