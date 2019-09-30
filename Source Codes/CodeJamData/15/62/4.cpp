#include <cstdio>
#include <numeric>
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
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int N = 1000*1000;
//const int N = 20;
const int mod = 1000*1000*1000+7;

int n;
int m;
int f[N + 1];
int rf[N + 1];
int res[N + 1];
int sum[N + 1];

int power (int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int cnk (int n, int k) {
	if (n < 0 || k < 0 || k > n) re 0;
	re ((ll)f[n] * rf[k] % mod * rf[n - k]) % mod;
}

int main () {
	f[0] = 1;
	rf[0] = 1;
	res[0] = 1;
	sum[0] = 1;
	for (int i = 1; i <= N; i++) {
		f[i] = ((ll)f[i - 1] * i) % mod;
		rf[i] = power (f[i], mod - 2);
		res[i] = 0;
        if (i > 1) res[i] = ((ll)sum[i - 2] * f[i] % mod * f[i - 1]) % mod;
		sum[i] = (sum[i - 1] + (ll)res[i] * rf[i] % mod * rf[i]) % mod;
	}
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n >> m;
		int ans = 0;
		for (int i = m; i <= n; i++) {
			ans = (ans + (ll)cnk (n, i) * cnk (n, i) % mod * f[i] % mod * res[n - i]) % mod;
		}
		cout << "Case #" << it << ": " << ans << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}