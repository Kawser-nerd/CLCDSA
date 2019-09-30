#ifndef LOCAL_BOBER
#pragma comment(linker, "/STACK:134217728")
#endif

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

int col[10100];

int mas[10000];

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin >> tc;
	rep(tt, tc) {
		printf("Case #%d: ", tt + 1);
		cin >> n;
		fill(col, 0);
		rep(i, n) {
			int a;
			cin >> a;
			col[a]++;
		}

		if (n == 0) {
			cout << 0 << endl;
			continue;
		}

		int ans = 1000;
		int c = 0;
		int l = 0, r = 0;
		for (int i = 0; i <= 10001; i++) {
			if (col[i] > 0) {
				//cout << c << ' ' << i << ' ' << col[i] << endl;
			}
			if (c == col[i])
				continue;
			if (c < col[i]) {
				rep(j, col[i] - c)
					mas[r++] = i;
				c = col[i];
			}
			else {
				rep(j, c - col[i]) {
					ans = min(ans, i - mas[l++]);
				}
				c = col[i];
			}
		}
		cout << ans << endl;
	}

	re 0;
}

