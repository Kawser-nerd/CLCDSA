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

const string task = "b";
const string inp = task + ".in";
const string oup = task + ".out";

void solve(){
	long long l,p,c;
	cin >> l >> p >> c;
	long long cnt = 0;
	long long l1 = l;
	while (l1 * c < p){
		cnt ++;
		l1 *= c;
	}
	long long res = 0;
	while (cnt >= 1){
		res ++;
		cnt /= 2;
	}
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
