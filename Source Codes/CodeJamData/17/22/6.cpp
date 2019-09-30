#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }

template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }

string solve(int r, int y, int b) {
	string ret;
	FOR(i, r) ret.push_back('R');
	{
		string cur;
		FOR(i, sz(ret)) {
			cur.push_back(ret[i]);
			if (y) y--, cur.push_back('Y');
		}
		while (y--) cur.push_back('Y');
		ret = cur;
	}
	{
		string cur;
		FOR(i, sz(ret)) {
			cur.push_back(ret[i]);
			if (ret[i] == ret[(i + 1) % sz(ret)]) {
				if(b) b--, cur.push_back('B');
			}
		}
		ret = cur;

		cur = "";
		FOR(i, sz(ret)) {
			cur.push_back(ret[i]);
			if (ret[i] != 'B' && ret[(i + 1) % sz(ret)] != 'B') {
				if (b) b--, cur.push_back('B');
			}
		}

		while (b--) cur.push_back('B');
		ret = cur;
	}
	FOR(i, sz(ret)) {
		if(ret[i] == ret[(i+1)%sz(ret)]) return "";
	}
	return ret;
}

string solve() {
	int n; reader(n);
	int r, ry, y, yb, b, br;
	reader(r, ry, y);
	reader(yb, b, br);
	if (r == 0 && ry != 0 && y == 0 && yb == 0 && b != 0 && br == 0) {
		if (ry == b) {
			string ret;
			FOR(i, ry) {
				ret.push_back('O'); ret.push_back('B');
			}
			return ret;
		} else {
			return "";
		}
	}
	if (r != 0 && ry == 0 && y == 0 && yb != 0 && b == 0 && br == 0) {
		if (yb == r) {
			string ret;
			FOR(i, yb) {
				ret.push_back('G'); ret.push_back('R');
			}
			return ret;
		} else {
			return "";
		}
	}
	if (r == 0 && ry == 0 && y != 0 && yb == 0 && b == 0 && br != 0) {
		if (br == y) {
			string ret;
			FOR(i, br) {
				ret.push_back('V'); ret.push_back('Y');
			}
			return ret;
		} else {
			return "";
		}
	}

	if (yb && yb >= r) return "";
	if (br && br >= y) return "";
	if (ry && ry >= b) return "";
	r -= yb;
	y -= br;
	b -= ry;

	string ans = solve(r, y, b);
	if (sz(ans) == 0) return ans;

	string yb_part = "R";
	FOR(i, yb) {
		yb_part.push_back('G');
		yb_part.push_back('R');
	}
	FOR(i, sz(ans)) {
		if (ans[i] == 'R') {
			string l = ans.substr(0, i);
			string r = ans.substr(i + 1);
			ans = l + yb_part + r;
			break;
		}
	}
	string br_part = "Y";
	FOR(i, br) {
		br_part.push_back('V');
		br_part.push_back('Y');
	}
	FOR(i, sz(ans)) {
		if (ans[i] == 'Y') {
			string l = ans.substr(0, i);
			string r = ans.substr(i + 1);
			ans = l + br_part + r;
			break;
		}
	}
	string ry_part = "B";
	FOR(i, ry) {
		ry_part.push_back('O');
		ry_part.push_back('B');
	}
	FOR(i, sz(ans)) {
		if (ans[i] == 'B') {
			string l = ans.substr(0, i);
			string r = ans.substr(i + 1);
			ans = l + ry_part + r;
			break;
		}
	}

	return ans;
}

int main() {
	int t; reader(t);
	FOR(i, t) {
		string ans = solve();
		if (ans == "") ans = "IMPOSSIBLE";
		printf("Case #%d: ", i + 1);
		printf("%s\n", ans.c_str());
	}

	return 0;
}