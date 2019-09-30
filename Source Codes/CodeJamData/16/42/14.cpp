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

int n;
int m;

double answer;
int mask;
double res[201][201];
double x[200];

int gen (int i, int j, int a, int b) {
	if (j == m) {	
		if (res[m][m / 2] > answer) {
			answer = res[m][m / 2];
//			mask = cur;
		}
		re 0;
	}
	if (j + (n - i) < m) re 0;
	if (i >= a && i <= b) gen (i + 1, j, a, b); else {
		memset (res[j + 1], 0, sizeof (res[j + 1]));
		for (int k = 0; k <= j; k++) {
			res[j + 1][k] += res[j][k] * (1 - x[i]);
			res[j + 1][k + 1] += res[j][k] * x[i];
		}
		gen (i + 1, j + 1, a, b);
	}	
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; i++) scanf ("%lf", &x[i]);
		sort (x, x + n);
		answer = 0;
		res[0][0] = 1;
		for (int i = 0; i + n - m <= n; i++) gen (0, 0, i, i + n - m - 1);
		cout.precision (15);
		cout << "Case #" << it << ": " << answer;
		cout << endl;
/*		for (int i = 0; i < n; i++) printf ("%.2f ", x[i]);
		printf ("\n");
		for (int i = 0; i < n; i++) printf ("%d", (mask >> i) & 1);
		printf ("\n");*/
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}