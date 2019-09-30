#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
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
template<class T> T sqr(T x) { re x * x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

const int mod = 1000*1000*1000+7;

int n;
int m;
int res[10001][10001];
int diag[10001][10001];
int col[10001][10001];

int power (int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		b /= 2;
		a = ((ll)a * a) % mod;
	}
	re c;
}

#ifdef PARALLEL
int main (int argv, char **argc) {
	if (argv < 4) {
		printf ("wrong command line\n");
		re 0;
	}
	int PART = stoi (argc[1]);
	int NUM = stoi (argc[2]);
	freopen (argc[3], "r", stdin);
	freopen (argc[4], "w", stdout);
#else
int main () {
#endif
	int tt;
	cin >> tt;
#ifdef PARALLEL
	int CNT = (tt + NUM - 1) / NUM;
#endif
	n = 10000;
	for (int i = 1; i <= n; i++) {
		int rev = power (i - 1, mod - 2);
		for (int j = 0; j < i; j++) {
			ll tmp = 0;
			if (j > 1) tmp += diag[i - 2][j - 2];
			if (i - 2 >= j) tmp += col[i - 2][j];
			tmp += 1 + int (j > 0 && j + 1 < i);
			tmp %= mod;
			res[i][j] = (tmp * rev) % mod;
			diag[i][j] = res[i][j];
			if (j > 0) diag[i][j] = (diag[i][j] + diag[i - 1][j - 1]) % mod;
			col[i][j] = res[i][j];
			if (j + 1 < i) col[i][j] = (col[i][j] + col[i - 1][j]) % mod;
		}
	}
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d", &n, &m);
#ifdef PARALLEL
		if ((it - 1) >= PART * CNT && (it - 1) < (PART + 1) * CNT) {
#endif
			cout << "Case #" << it << ": " << res[n][m - 1];
			cout << endl;
#ifdef PARALLEL
			fprintf (stderr, "%d / %d = %.2f | %.2f\n", it - PART * CNT, CNT, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / (it - PART * CNT) * CNT) / CLOCKS_PER_SEC);
		}	
#else
			fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
#endif
	}
	return 0;
}