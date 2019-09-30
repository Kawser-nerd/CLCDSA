#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vb> vvb;
typedef vector<vs> vvs;
typedef vector<vl> vvl;

int inf = 0x3f3f3f3f;
double eps = 10e-10;
ll mod = 1000000007ll;

#define rep(k, a, b) for (int k = (a); k < int(b); k++)
#define sz(a) int(a.size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define x first
#define y second
#define mi(r, c, v) vvi(r, vi(c, v))
#define rrep(k, a, b) for (int k = (a); k >= int(b); k--)
#define irep(k, a) for (auto& k : (a))
#define md(r, c, v) vvd(r, vd(c, v))
#define mb(r, c, v) vvb(r, vb(c, v))
#define ms(r, c, v) vvs(r, vs(c, v))
#define ml(r, c, v) vvl(r, vl(c, v))
#define mc(r, c, v) vs(r, string(c, v))
#define add(i, j) ((i) + (j)) % mod
#define mul(i, j) ((i) * (j)) % mod

int sign(int n) {
	if (n > 0)
		return 1;
	else if (n < 0)
		return -1;
	else
		return 0;
}

// 1 = 1, 2 = i, 3 = j, 4 = k
int mult(int x, int y) {
	if (abs(x) == 1 || abs(y) == 1)
		return x * y;
	if (abs(x) == abs(y))
		return -sign(x) * sign(y);
	if (abs(x) == 2 && abs(y) == 3)
		return 4 * sign(x) * sign(y);
	if (abs(x) == 3 && abs(y) == 2)
		return -4 * sign(x) * sign(y);
	if (abs(x) == 3 && abs(y) == 4)
		return 2 * sign(x) * sign(y);
	if (abs(x) == 4 && abs(y) == 3)
		return -2 * sign(x) * sign(y);
	if (abs(x) == 4 && abs(y) == 2)
		return 3 * sign(x) * sign(y);
	if (abs(x) == 2 && abs(y) == 4)
		return -3 * sign(x) * sign(y);
}

int main() {
	int T, L;
	long long n;
	cin >> T;
	rep(X, 0, T) {
		cin >> L >> n;
		string s, s2;
		int prod = 1;
		cin >> s;

		if (n >= 12)
			n = (n % 4) + 8;
		rep(i, 0, n)
			s2 += s;

		int counter = 0;
		irep(c, s2) {
			prod = mult(prod, c - 'i' + 2);
			if (counter == 0 && prod == 2) {
				counter++;
				prod = 1;
			} else if (counter == 1 && prod == 3) {
				counter++;
				prod = 1;
			}
		}

		printf("Case #%d: %s\n", X + 1, counter == 2 && prod == 4 ? "YES" : "NO");
	}
}
