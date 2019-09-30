#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
// statics
using namespace std;
using int64 = int_fast64_t;
using PAIR = pair<int64, int64>;
constexpr int INF = 1 << 30;
constexpr int64 LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 3e5 + 1;

// init/input
#define int int64
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define VAR(type, ...) type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T &t) {cin>>t;}
template<typename First, typename...Rest> void MACRO_VAR_Scan(First &first, Rest&...rest) {cin>>first;MACRO_VAR_Scan(rest...);}
#define VEC(type, c, n) vector<type> c(n);for(auto &&i:c)cin>>i;

// out
#define OUT(dist) cout<<(dist);
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define SP cout<<" ";
#define BR cout<<endl;
#define zero(n) cout<<setfill('0')<<right<<setw(n)
#define debug(x) cerr<<#x<<":"<< (x);BR;

// utility
#define ALL(a) (a).begin(), (a).end()
#define EACH(i, a) for(auto &&i:(a))
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=0;--i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)

int fact[MAX_N];
int ifact[MAX_N];

int power(int x, int n) {
	int res = 1LL;
	while (n > 0) {
		if (n & 1) (res *= x) %= MOD;
		(x *= x) %= MOD;
		n >>= 1;
	}
	return res % MOD;
}

int inv(int x) {
	return power(x, MOD - 2);
}

int nCr(int n, int r) {
	if (n < 0 || r < 0 || r > n) return 0;
	if (r > n / 2) r = n - r;
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

void init_fact() {
  fact[0] = ifact[0] = 1;
	for (int i=1; i<MAX_N; ++i) {
		(fact[i] = fact[i - 1] * i) %= MOD;
		ifact[i] = inv(fact[i]);
	}
}

struct Eratosthenes {
  vector< bool > prime;
  Eratosthenes(int _size) {
    init(_size);
  }

  void init(int n) {
    prime.resize(n + 1);
    for(int i = 0; i < prime.size(); ++i) prime[i] = true;
    prime[0] = prime[1] = false;
    for(int i = 2; i*i < n; i++) {
      if (prime[i]) {
        for (int j = 0; i * (j + 2) < n; j++) {
					prime[i * (j + 2)] = false;
				}
      }
    }
  }

	map< int, int > prime_factorize(int n) {
		map< int, int > res;
		for (int i=2; i*i<=n; ++i) {
			if (!prime[i]) continue;
			if (n % i != 0) continue;
			int num = 0;
			while (n % i == 0) {
				res[i]++;  n /= i;
			}
		}
		if (n != 1) res[n]++;
		return res;
	}
};

signed main() {
  INIT;
	init_fact();
	VAR(int, n, m);

	Eratosthenes e(MAX_N);
	map< int, int > mp = e.prime_factorize(m);

	int ans = 1;
	EACH(mi, mp) {
		(ans *= nCr(mi.second + n - 1, n - 1)) %= MOD;
	}

	OUT(ans)BR;
  return 0;
}