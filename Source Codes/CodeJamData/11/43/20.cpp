#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

ll n;
int m;
int ans, r;
int f[1000001];
int q[300000];

int main() {
	r = 0;
	for (int i = 2; i <= 1000000; i++)
		if (!f[i]) {
			q[r++] = i;
			if (i <= 1000)
				for (int j = i * i; j <= 1000000; j += i)
					f[j] = 1;
		}
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {

		cin >> n;
		int ans = 0;
		for (int i = 0; i < r && (ll)q[i] * q[i] <= n; i++) {
			ll j, k;
			for (j = 1, k = 0; (ll)j * q[i] <= n; j *= q[i], k++);
			ans += k - 1;
		}
		if (n > 1) ans++;
		printf ("Case #%d: %d\n", it, ans);
		cerr << it << endl;
	}
	return 0;
} 