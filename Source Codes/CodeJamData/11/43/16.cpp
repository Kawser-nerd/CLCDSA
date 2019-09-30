#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T a) {return a > 0 ? a : (-a); }
template<class T> T sqr(T a) {return a * a; }

using namespace std;

const int MAXSQRT = 1000 * 1000 * 5;

bool prime[MAXSQRT];

void precalc() {
	for (int i = 0; i < MAXSQRT; ++i) prime[i] = true;
	prime[0] = prime[1] = false;
	for (int i = 0; i < MAXSQRT; ++i) if (prime[i]) {
		for (int j = 2; i * j < MAXSQRT; ++j)
			prime[i * j] = false;
	}
}

void solve(int testnum) {
	cerr << testnum << endl;
	long long n;
	cin >> n;
	long long ans = 1;
	for (long long i = 1; i * i <= n; ++i) if (prime[i]) {
		long long tmp = n;
		int deg = -1;
		while (tmp != 0) {
			tmp /= i;
			++deg;
		}
		ans += deg - 1;
	}
	if (n == 1) ans = 0;
	cout << "Case #" << testnum << ": " << ans << endl;
}

int main() {
	precalc();

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) solve(i + 1);
	return 0;
}
