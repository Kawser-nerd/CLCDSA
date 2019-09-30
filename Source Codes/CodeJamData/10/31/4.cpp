#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())
#define sqr(a) (a)*(a)

typedef long long int64;
typedef pair<int,int> pii;

const int inf = (int)1E+9;
const double eps = 1e-9;

const string task = "a";
const string inp = task + ".in";
const string oup = task + ".out";

int n;
int a[100100];
int b[100100];

void solve(){
	cin >> n;
	forn(i,n)
		cin >> a[i] >> b[i];
	int res = 0;
	forn(i,n)
		forn(j,i)
			if ((a[i] > a[j] && b[i] < b[j]) || (a[i] < a[j] && b[i] > b[j]))
				res ++;
	cout << res << endl;


}

int main(){
	freopen(inp.data(), "rt", stdin);
	freopen(oup.data(),"wt", stdout);

	int tst;
	cin >> tst;
	forn(i,tst){
		printf("Case #%d: ", i+1);
		solve();
	}

	return 0;
}
