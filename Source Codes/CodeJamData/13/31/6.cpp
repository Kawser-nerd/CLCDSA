#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <complex>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef stringstream ss;

#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define clr(t, v) memset((t), (v), sizeof(t))
#define w(a) #a << ": " << (a) << "  "

#define rep(i, n) for (int i = 0, _##i = (n); i < _##i; ++i)
#define dwn(i, n) for (int i = (n); --i >= 0;)
#define repr(i, l, r) for (int i = (l), _##i = (r); i < _##i; ++i)
#define dwnr(i, l, r) for (int i = (r), _##i = (l); --i >= _##i;)
#define repi(i, a) for (__typeof((a).begin()) i = (a).begin(), _##i=(a).end(); i != _##i; ++i)
#define dwni(i, a) for (__typeof((a).rbegin()) i = (a).rbegin(), _##i=(a).rend(); i != _##i; ++i)

bool is(char c) {
	return c != 'a' && c != 'e' && c != 'o' && c != 'i' && c != 'u';
}

char str[1001000];
bool ok[1001000];

void go() {
	memset(ok, 0, sizeof(ok));
	cin >> str;
	int k;
	cin >> k;
	int len = strlen(str);
	int c = 0;
	rep (i, len) {
		if (is(str[i])) {
			c++;
		} else {
			c = 0;
		}
		if (c >= k) {
			ok[i] = true;
		}
	}
	ll ans = 0;
	int p = -1;
	repr (i, k - 1, len) {
		if (ok[i]) p = i;
		if (p != -1) {
			ans += p - (k - 1) + 1;
		}
	}
	cout << ans;
	
}

int main() { freopen("a.in", "r", stdin); freopen("a.out", "w", stdout);
	cout << fixed << setprecision(12);
	
	int testn;
	cin >> testn;
	for (int testc = 1; testc <= testn; ++testc) {
		cout << "Case #" << testc << ": ";
		go();
		cout << '\n';
	}
}
