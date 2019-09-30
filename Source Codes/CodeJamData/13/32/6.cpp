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

stack<char> s;
int x, y;
void fixx(int a) {
	if (x <= 0) {
		x += a;
		s.push('W');
	} else {
		x -= a;
		s.push('E');
	}
}
void fixy(int b) {
	if (y <= 0) {
		y += b;
		s.push('S');
	} else {
		y -= b;
		s.push('N');
	}
}

void go() {
	cin >> x >> y;
	int t = abs(x) + abs(y);
	int ans = 0;
	repr (i, 1, 1000000) {
		int u = i * (i + 1) / 2;
		if ((u % 2) == (t % 2) && u >= t) {
			ans = i;
			break;
		}
	}
	dwnr (i, 1, ans + 1) {
		if (abs(x) >= abs(y)) {
			fixx(i);
		} else {
			fixy(i);
		}
	}
	while (s.size()) {
		cout << s.top();
		s.pop();
	}
//	cout << x << ' ' << y << endl;
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
