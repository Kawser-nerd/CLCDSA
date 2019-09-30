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
#define p0 p1234124
#define p1 p123154
#define fill(x,y) memset(x,y,sizeof(x))
                         
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
int m, k;

double q0[1000001], q1[1000001], q2[1000001];

double v[1000001];

int main () {
	double start = clock ();
	double last = clock ();
	int tt;
	cin >> tt;

	for (int it = 1; it <= tt; it++) {
		
		scanf ("%d%d", &n, &k);
		int o = 0;
		for (int i = 0; i < n; i++) {
			int a, b, c;
			scanf ("%d/%d %d", &a, &b, &c);
			for (int j = 0; j < c; j++) v[o++] = (a + 0.0) / b;
		}

		sort (v, v + o);
		reverse (v, v + o);

		q0[o] = q1[o] = q2[o] = 0;
		for (int j = o - 1; j >= 0; j--) {
			q0[j] = (q0[j + 1] + q1[j + 1]) * v[j];
			q1[j] = (q1[j + 1] + q2[j + 1]) * (1 - v[j]);
			q2[j] = v[j];
//			printf ("%.10f %.10f %.10f\n", q0[j], q1[j], q2[j]);
		}

		double p0 = 1, p1 = 0, p2 = 0;

		double ans = 1;

		for (int i = 0; i < k; i++) {
			int j = o - (k - i);
//			printf ("%.10f %.10f %.10f %d = %.10f\n", p0, p1, p2, j, p2 + (p0 + p1) * (q0[j] + q1[j]) - p1 * q0[j] + p1 * q2[j]);
			ans = min (ans, p2 + (p0 + p1) * (q0[j] + q1[j]) - p1 * q0[j] + p1 * q2[j]);
			p2 += p1 * v[i];
			p1 = (p0 + p1) * (1 - v[i]);
			p0 = p0 * v[i];
		}
		
		cout << "Case #" << it << ": ";

		printf ("%.10f", ans);



		cout << endl;
		double current = clock ();
		fprintf (stderr, "%d / %d = %.10f : %.10f\n", it, tt, (current - last) / CLOCKS_PER_SEC, (current - start) / CLOCKS_PER_SEC);
		last = current;
	}
	return 0;
}
