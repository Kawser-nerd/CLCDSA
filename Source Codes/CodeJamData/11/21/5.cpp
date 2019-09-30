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

int n;
int m;
char w[101][101];
int cnt[100], win[100];
double wp[100], owp[100], oowp[100];

int main() {
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {
		scanf ("%d", &n);
		gets (w[0]);
		for (int i = 0; i < n; i++)
			gets (w[i]);
		for (int i = 0; i < n; i++) {
			cnt[i] = 0;
			win[i] = 0;
			for (int j = 0; j < n; j++)
				if (w[i][j] == '0') cnt[i]++; else
				if (w[i][j] == '1') { cnt[i]++; win[i]++; }
			wp[i] = (win[i] + 0.0) / cnt[i];
		}
		for (int i = 0; i < n; i++) {
			owp[i] = 0;
			int cur = 0;
			for (int j = 0; j < n; j++)
				if (w[i][j] != '.') {
					int ocnt = cnt[j], owin = win[j];
					if (w[j][i] == '1') { owin--; ocnt--; } else
					if (w[j][i] == '0') ocnt--;
					owp[i] += (owin + 0.0) / ocnt;
					cur++;
				}
			owp[i] /= cur;
		}
		for (int i = 0; i < n; i++) {
			int cur = 0;
			oowp[i] = 0;
			for (int j = 0; j < n; j++)	
				if (w[i][j] != '.') {
					oowp[i] += owp[j];
					cur++;
				}	
			oowp[i] /= cur;
		}
		printf ("Case #%d:\n", it);
		for (int i = 0; i < n; i++)
			printf ("%.10f\n", 0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]);
	}
	return 0;
}