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

const int mod = 1000003;

int n;
int m, rs;
string s;
int was[26][103][103];
int res[26][103][103];
int cnt[26];
int c[203][203];
int DIV[26][103];

int power (int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int go (int i, int A, int B) {
//	printf ("%d %d %d %d\n", i, A, B, rs);
	if (A + B > rs) re 0;
	if (i == 26) re int (A == 0 && B == rs);
	if (was[i][A][B]) re ::res[i][A][B];
	int res = 0;
	if (cnt[i] == 0) res = go (i + 1, A, B); else
	for (int C = 1; C <= cnt[i] && A + B + C <= rs; C++)
		for (int X = 0; X <= A && X <= C; X++)
			for (int Y = 0; Y <= B && X + Y <= C; Y++) {
				if (X + Y == 0) continue;
//				printf ("%d %d %d > %d %d %d\n", i, A, B, X, Y, C);
//				printf ("%d %d %d %d\n", c[A][X], c[B][Y], c[X + Y][C - (X + Y)]);
				int tmp = go (i + 1, A - X + (C - X - Y), B + 2 * X + Y);
				if (tmp == 0) continue;
				tmp = ((ll)tmp * c[A][X]) % mod;
				tmp = ((ll)tmp * c[B][Y]) % mod;
				tmp = ((ll)tmp * c[C - 1][X + Y - 1]) % mod;
				tmp = ((ll)tmp * DIV[i][C]) % mod;
				res = res + tmp;
				if (res >= mod) res -= mod;
			}
	was[i][A][B] = 1;
	::res[i][A][B] = res;
	re res;
}

int main () {
	for (int i = 0; i <= 201; i++)
		for (int j = 0; j <= i; j++)
				if (i == 0 || j % i == 0)
					c[i][j] = 1;
				else
					c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	int tt;
	scanf ("%d", &tt);
	for (int it = 1; it <= tt; it++) {
		cerr << it << endl;
		cin >> s;
		rs = 2;
		n = sz (s);
		for (int i = 1; i < n; i++)
			if (s[i] != s[i - 1])
				rs++;
		//printf ("%d\n", rs);
		memset (cnt, 0, sizeof (cnt));
		for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
		memset (DIV, 0, sizeof (DIV));
		for (int i = 0; i < 26; i++) {
			int cur = 1;
			for (int j = 1; j <= 102 && j <= cnt[i]; j++) {
				if (j > 1) {
					cur = ((ll)cur * (cnt[i] - j + 1)) % mod;
					cur = ((ll)cur * power (j - 1, mod - 2)) % mod;
				}
				DIV[i][j] = cur;
//				printf ("%d %d %d\n", i, j, cur);
			}
		}
		memset (was, 0, sizeof (was));
		printf ("Case #%d: %d\n", it, go (0, 0, 1));
	}
	return 0;
}
