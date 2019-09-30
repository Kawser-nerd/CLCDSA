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

int check(ll x) {
	ll o = sqrt(x);
	for (ll d = max(0ll, o - 5); d <= o + 5; d++)
		if (d * d == x)
			re 1;
	re 0;
}

void print(ll x) {
	string s = "";
	while (x) {
		s += (char) (48 + x % 2);
		x /= 2;
	}
	reverse(all(s));
	cout << s << endl;
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin >> tc;
	rep(tt, tc) {
		printf("Case #%d: ", tt + 1);

		string s;
		cin >> s;
		ll l = 0, r = 0;
		int col = 0;
		ll mas[60];
		rep(i, sz(s)) {
			if (s[i] == '?') {
				l = l * 2;
				r = r * 2 + 1;
				mas[col++] = (1ll << (sz(s) - i - 1));;
			}
			else {
				l = l * 2 + s[i] - 48;
				r = r * 2 + s[i] - 48;
			}
		}

		rep(i, (1 << col)) {
			ll sum = l;
			rep(j, col)
			if (i & (1 << j))
				sum += mas[j];
			if (check(sum)) {
				print(sum);
				break;
			}
		}
	}

	re 0;
}

