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
int p[2000];
int a[2000];
int b[2000];
int g[2000][2000];
int cnt[2000];
int was[2001];
vi q;

int go (int x) {
	was[x] = 1;
	for (int i = 0; i < n; i++)
		if (g[x][i] && !was[i])
			go (i);
	q.pb (x);
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {

		scanf ("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = 0;
		for (int i = 0; i < n; i++) scanf ("%d", &a[i]);
		for (int i = 0; i < n; i++) scanf ("%d", &b[i]);
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (a[i] >= a[j]) g[i][j] = 1;
				if (b[i] <= b[j]) g[j][i] = 1;
			}
		for (int i = 0; i < n; i++) {
			if (a[i] > 1) {
				for (int j = i - 1; j >= 0; j--)
					if (a[j] == a[i] - 1) {
						g[i][j] = 1;
						break;
					}
			}
			if (b[i] > 1) {
				for (int j = i + 1; j < n; j++)
					if (b[j] == b[i] - 1) {
						g[i][j] = 1;
						break;
					}
			}
		}	
		memset (was, 0, sizeof (was));
		memset (cnt, 0, sizeof (cnt));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cnt[i] += g[i][j];
//		for (int i = 0; i < n; i++) printf ("%d %d\n", i + 1, cnt[i]);
		for (int i = 0; i < n; i++) {
			int k;
			for (int j = 0; j < n; j++)
				if (!was[j] && cnt[j] == 0) {
					k = j;
					break;
				}
			p[k] = i + 1;
			was[k] = 1;
			for (int j = 0; j < n; j++)
				if (g[j][k])
					cnt[j]--;
		}
		cout << "Case #" << it << ":";
		for (int i = 0; i < n; i++) printf (" %d", p[i]);
		cout << endl;

		cerr << it << " / " << tt << endl;
		for (int i = 0; i < n; i++) {
			int cur = 0;
			for (int j = 0; j < i; j++)
				if (p[i] > p[j])
					cur = max (cur, a[j]);
			cur++;
//			printf ("%d %d %d\n", i + 1, a[i], cur);
			if (cur != a[i]) {
				printf ("bad\n");
				re 0;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			int cur = 0;
			for (int j = i + 1; j < n; j++)
				if (p[i] > p[j])
					cur = max (cur, b[j]);
			cur++;
//			printf ("%d %d %d\n", i + 1, b[i], cur);
			if (cur != b[i]) {
				printf ("bad\n");
				re 0;
			}
		}
	}
	return 0;
}