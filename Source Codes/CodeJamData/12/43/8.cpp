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

const int nmax = 3000;

int n;
long long res[nmax], a[nmax];

/*
bool solve(int l, int r, int dd){
	res[l] = dd;
	
	if (l > r || l == n - 1) return 1;
	if (l == r) return 0;

	
	int w = a[l];
	if (w > r) return 0;
	int nl = l;
	while (a[nl] == w) {
		res[nl] = dd;
		nl ++;
	}
	if (!solve(nl, w - 1, dd)) return 0;
	res[w] = res[l] + 1;
	for (int i = nl; i < w; i ++)
		res[w] = max(res[w], res[l] + 1 + 1ll * (res[i] - res[l]) * (w - nl + 1) / (i - nl + 1));
	if (w < r && !solve(w, r, res[w])) return 0;
	return 1;
}
*/

bool check(){
	forn(i, n)
		if (a[i] > 1e9 || a[i] < 0)
			return 0;
	forn(i, n - 1){
		int p = i + 1;
		for (int j = i + 1; j < n; j ++)
			if ((res[j] - res[i]) * (p - i) > (res[p] - res[i]) * (j - i))
				p = j;
		if (p != a[i])
			return 0;
	}
	return 1;
}

int dd[nmax];

bool gg(int st){
	memset(dd, 0, sizeof dd);
     res[n-1] = 1e9;
	for (int i = n - 2; i >= 0; i --){
		int j = a[i];
		int nj = a[j];
		int up = 1;
		if (j < n - 1){
			up = (res[nj] - res[j]) * (j - i);
			up = (up + nj - j - 1) / (nj - j) + st;
		}
		res[i] = res[j] - up;
	}
	long long sm = 1e9;
	forn(i, n)
		sm = min(sm, res[i]);
	forn(i, n)
		res[i] -= sm;
	if (!check())
		return 0;
	else{
		forn(i, n){
			printf("%d", (int)res[i]);
			if (i + 1 < n)
				printf(" ");
			else
				puts("");
		}
		return 1;
	}

}


bool gg2(int st){
	memset(dd, 0, sizeof dd);
	forn(i, n)
		dd[i] = st;
	forn(i, n)
		dd[a[i]] ++;
     res[n-1] = 1e9;
	for (int i = n - 2; i >= 0; i --){
		int j = a[i];
		int nj = a[j];
		int up = 1;
		if (j < n - 1){
			up = (res[nj] - res[j]) * (j - i);
			up = (up + nj - j - 1) / (nj - j) + dd[j];
			dd[j] --;
		}
		res[i] = res[j] - up;
	}
	long long sm = 1e9;
	forn(i, n)
		sm = min(sm, res[i]);
	forn(i, n)
		res[i] -= sm;
	if (!check())
		return 0;
	else{
		forn(i, n){
			printf("%d", (int)res[i]);
			if (i + 1 < n)
				printf(" ");
			else
				puts("");
		}
		return 1;
	}

}

void solve(){
	cin >> n;
	forn(i, n - 1){
		cin >> a[i];
		a[i] --;
	}
	
	forn(i, 6)
		if (gg(i))
			return;
	forn(i, 6)
		if (gg2(i - 1))
			return;
	puts("Impossible");
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
