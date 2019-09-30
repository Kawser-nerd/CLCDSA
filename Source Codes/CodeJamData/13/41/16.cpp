#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <vector>

using namespace std;

typedef long long int64;
//typedef double old_double;
//#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


const int MAXN = 2100;
const int64 MOD = 1000002013;


int n, m;
pair<int,int> a[MAXN];
int cnt[MAXN];


void read() {
    cin >> n >> m;
    forn(i, m)
        cin >> a[i].first >> a[i].second >> cnt[i];
}


inline int64 sum(int64 n) {
    return n * (n + 1) / 2 % MOD;
}


inline int64 calc_ans(int64 l, int64 r, int64 cnt) {
    int64 d = r - l;
    int64 res = (sum(n) - sum(n - d) + MOD) % MOD;
    cnt %= MOD;
    return res * cnt % MOD;
}


void solve() {
    vector<int> vec;
    forn(i, m) {
        vec.push_back(a[i].first);
        vec.push_back(a[i].second);
    }
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());

    vector<int64> vals(vec.size() - 1);
    forn(i, m) {
        int l = int(lower_bound(all(vec), a[i].first) - vec.begin());
        int r = int(lower_bound(all(vec), a[i].second) - vec.begin());
        fore(j, l, r)
            vals[j] += cnt[i];
    }

    int64 new_ans = 0;
    forn(l, vec.size() - 1) {
        while (vals[l]) {
            int r = l;
            int64 mi = vals[l];
            while (r + 1 < (int)vals.size() && vals[r + 1]) {
                ++r;
                mi = min(mi, vals[r]);
            }

            fore(i, l, r + 1)
                vals[i] -= mi;

            if (mi == 0)
                throw;

            new_ans += calc_ans(vec[l], vec[r + 1], mi);
        }
    }

    int64 old_ans = 0;
    forn(i, m)
        old_ans += calc_ans(a[i].first, a[i].second, cnt[i]);

    int64 diff = old_ans - new_ans;
    diff %= MOD;
    if (diff < 0)
        diff += MOD;
    cout << diff << endl;
}


int main() {
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);

	int ts;
	cin >> ts;
	forn(tt, ts) {
		read();
		if (!cin)  throw;
		printf("Case #%d: ", tt + 1);
		solve();
	}
}
