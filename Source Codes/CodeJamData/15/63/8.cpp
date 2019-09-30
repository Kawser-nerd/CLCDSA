#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Frac {
	ll p, q;
	Frac(int p, int q) : p(p), q(q) {}
};
bool operator<(Frac a, Frac b) {
	return a.p * b.q < b.p * a.q;
}

int solve() {
	int N;
	cin >> N;
	double F;
	cin >> F;
	int f = (int)(F * 1000000);
	// cerr << f << endl;
	string str;
	cin >> str;
	int sum = 0;
	vi culm(N+1);
	rep(i,0,N) {
		culm[i] = sum;
		sum += str[i] - '0';
	}
	culm[N] = sum;
	pair<Frac, int> best(Frac(1000000001, 1), -1);
	rep(i,0,N) {
		rep(len, 1, N-i+1) {
			int s = culm[i + len] - culm[i];
			Frac res(s * 1000000 - f * len, len);
			if (res.p < 0) res.p *= -1;
			best = min(best, make_pair(res, i));
		}
	}
	return best.second;
}

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	rep(i,0,N) {
		cout << "Case #" << i + 1 << ": ";
		cout << solve() << endl;
	}
}
