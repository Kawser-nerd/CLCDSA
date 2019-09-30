#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <ppl.h>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;
using namespace Concurrency;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

critical_section criticalSection;

const int64 mod = 1000003;

const int maxn = 570000;

bool isPrime(int64 x) {
	for (int64 i = 2; i * i <= x; ++i)
		if (x % i == 0) return false;
	return true;
}

int64 pw(int64 x, int64 y) {
	int64 res = 1;
	while (y)  {
		if (y % 2LL == 1LL)
			res = (res * x) % mod, --y;
		else
			x = (x * x) % mod, y /= 2;
	}
	return res;
}

int64 inv(int64 x) {
	return pw(x, mod - 2);
}

int64 fact[maxn];
int64 rf[maxn];

int64 C(int n, int k) {
	if (k < 0 || k > n) return 0;
	int64 res = fact[n];
	res = (res * rf[k]) % mod;
	res = (res * rf[n - k]) % mod;
	return res;
}

struct Problem {
	int problemId;
	// problem data
	string s;

	// some data
	int64 res;

	void read() {
		cin >> s;
	}

	vector<int64> calc(int x, int k) {
		/*vector<vector<vector<int64> > > d = vector<vector<vector<int64> > >(k + 1, vector<vector<int64> >(x + 1, vector<int64>(x + 1, 0)));
		for (int i = 1; i <= x; ++i)
			d[1][i][i] = 1;
		for (int i = 1; i < k; ++i)
			for (int j = 1; j <= x; ++j)
				for (int t = 1; t <= x; ++t) {
					if (d[i][j][t] == 0) continue;
					for (int s = t; s + j <= x; ++s)
						d[i + 1][j + s][s] = (d[i + 1][j + s][s] + d[i][j][t]) % mod;
				}*/
		vector<int64> d(k + 1, 0);
		for (int i = 1; i <= k; ++i)
			d[i] = C(x - 1, i - 1);
		return d;
		/*vector<int64> res(k + 1, 0);
		for (int i = 0; i <= k; ++i)
			for (int j = 0; j <= x; ++j)
				res[i] += d[i][x][j];
		return res;*/
	}

	void solve_good() {
		criticalSection.lock();
		cerr << "Solving case " << problemId << "\n";
		criticalSection.unlock();
		int n = sz(s);
		int k = 0;
		char c = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == c) continue;
			++k;
			c = s[i];
		}

		sort(all(s));
		vi v;
		int cur = 0;
		c = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == c) {
				++cur;
				continue;
			}
			if (cur != 0)
				v.pb(cur);
			cur = 1;
			c = s[i];
		}

		if (cur > 0)
			v.pb(cur);

		vector<vector<vector<int64> > > d = vector<vector<vector<int64> > > (sz(v) + 1, vector<vector<int64> > (k + 2, vector<int64>(k + 2, 0)));
		d[0][0][0] = 1;
		for (int i = 0; i < sz(v); ++i) {
			vector<int64> a = calc(v[i], k);
			for (int j = 0; j <= k; ++j) 
				for (int h = 0; h <= max(0, j - 1); ++h) {
					int64 cur = d[i][j][h];
					if (cur == 0) continue;
					int up = k;
					for (int t = 0; j + t <= k && t <= up; ++t) {						
						for (int hh = 0; hh <= k && j + t + hh <= k; ++hh) { 
							if (a[t + hh] == 0) continue;
							//if (C(t + hh, t) != 1) cerr << "ok\n";
							int64 tmp = (a[t + hh] * 1LL) % mod;
							for (int h1 = 0; h1 <= max(0, t - 1); ++h1) for (int h2 = 0; h2 <= max(0, hh - 1); ++h2) {
								/*if (j == 0)
									d[i + 1][j + t] = (d[i + 1][j + t] + d[i][j] * a[t]) % mod;
								else
									d[i + 1][j + t] = (d[i + 1][j + t] + (((((d[i][j] * a[t]) % mod * rf[j - t + 1]) % mod) * fact[j + 1]) % mod) * rf[t]) % mod;*/
								int64 coef1 = t == 0 ? 1LL : (C(t - 1, h1) * C(j + 1 - h, t - h1)) % mod;
								int64 coef2 = hh == 0 ? 1LL : (C(hh - 1, h2) * C(h, hh - h2)) % mod;
								if (coef1 == 0 || coef2 == 0) continue;
								d[i + 1][j + t + hh][h - hh + h1 + 2 * h2] += (((cur * tmp) % mod * coef1) % mod * coef2) % mod;
								d[i + 1][j + t + hh][h - hh + h1 + 2 * h2] %= mod;
							}
						}
					}
				}
		}

		res = d[sz(v)][k][0];
		//for (int64 i = 1; i <= k; ++i)
		//	res = (res * i) % mod;
	}

	void solve() {
		int n = sz(s);
		int k = 0;
		char c = 0;
		for (int i = 0; i < n; ++i) {
			if (s[i] == c) continue;
			++k;
			c = s[i];
		}

		sort(all(s));
		res = 0;
		do {
			int K = 0;
			char c = 0;
			for (int i = 0; i < n; ++i) {
				if (s[i] == c) continue;
				++K;
				c = s[i];
			}
			if (k == K) ++res;
		} while (next_permutation(all(s)));
		res %= mod;
	}

	void save() {
		cout << res << "\n";
	}
};

int main()
{
	/*printf("100\n");
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 10; ++j)
			printf("%c", 'a' + (rand() % 3));
		printf("\n");
	}
	return 0;*/
	/*vi v;
	for (int i = 0; i < 9; ++i)
		v.pb(i);
	int cnt = 0, den = 0;
	do {
		bool ok = true;
		for (int i = 0; i < sz(v) - 1; ++i) {
			int x = v[i], y = v[i + 1];
			if (x == 0 && y == 1) ok = false;
			if (x == 1 && y == 0) ok = false;
			if (x == 2 && y == 3) ok = false;
			if (x == 3 && y == 2) ok = false;
		}
		if (!ok) ++cnt;
		++den;
	} while (next_permutation(all(v)));
	cout << cnt << " " << den << "\n";
	return 0;*/
	fact[0] = 1;
	for (int64 i = 1; i < maxn; ++i)
		fact[i] = (fact[i - 1] * i) % mod;
	for (int i = 0; i < maxn; ++i)
		rf[i] = inv(fact[i]);
	int nc;
	cin >> nc;
	vector<Problem> problems(nc);
	for (int it = 0; it < nc; ++it) {
		problems[it].problemId = it;
		problems[it].read();
	}

	parallel_for_each(all(problems), 
		[&](Problem& p) {
			p.solve_good();
		}
	);	

	for (int it = 0; it < nc; ++it) {
		printf("Case #%d: ", it + 1);
		problems[it].save();
	}
	return 0;
}
