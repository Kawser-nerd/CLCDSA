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
int c[501][501];
int res[501][501];

int main() {
	for (int i = 0; i <= 500; i++)
		for (int j = 0; j <= i; j++)
			if (i == 0 || j % i == 0)
				c[i][j] = 1;
			else
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 100003;
	memset (res, 0, sizeof (res));
	res[1][0] = 1;
	for (int i = 2; i <= 500; i++)
		for (int j = 1; j < i; j++)
			for (int k = 0; k < j; k++)
				res[i][j] = (res[i][j] + (long long)c[i - j - 1][j - k - 1] * res[j][k]) % 100003;
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		int n;
		scanf ("%d", &n);
		int ans = 0;
		for (int i = 1; i <= n; i++) ans = (ans + res[n][i]) % 100003;
		printf ("Case #%d: %d\n", it + 1, ans);
	}
	return 0;
}