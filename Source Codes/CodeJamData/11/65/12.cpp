#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define prev prev239
#define next next239
#define hash hash239
#define rank rank239
#define sqrt(x) sqrt(abs(x))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;

template<class T> T abs(T x) {return x > 0 ? x : -x;}

int n;
int m;

double val[100];
double nval[100];

ii next[100];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	cin >> tc;
	rep(tt, tc) {
		printf("Case #%d: ", tt + 1);

		ll a, v;
		cin >> a >> m >> v;

		rep(i, v)
			val[i] = (double)i / v;

		val[0] = 0;
		val[v] = 1;

		rep(z, 10000) {
			for (int i = 1; i < v; i++) {
				nval[i] = 0;
				for (int b = 1; b <= min((int)i, m); b++) {
					ll tb = b;
					double p = .5;
					while (tb <= m) {
						double tmp = (1 - p) * val[min(i + b, (int)v)] + p * val[max(0ll, i - 2 * tb + b)];
						if (nval[i] <= tmp + 1e-8) {
							nval[i] = tmp;
							next[i] = mp(b, tb);
						}
						tb *= 2;
						p /= 2;
					}
				}
			}

			for (int i = 1; i < v; i++)
				val[i] = nval[i];
		}

/*		cout << endl;
		rep(i, v + 1)
		cout << i << ' ' << val[i] << endl;*/
		printf("%.6lf %d\n", val[a], next[a].fi);
	}


	re 0;
}

