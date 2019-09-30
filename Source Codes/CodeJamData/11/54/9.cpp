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

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

int64 Sqrt(int64 x) {
	int64 down = 0, up = 1LL << 30LL;
	while (up - down > 1) {
		int64 t = (up + down) / 2LL;
		if (t * t <= x)
			down = t;
		else
			up = t;
	}
	if (up * up < x) cerr << "AAA\n";
	return down;
}

void solve() {
	string s;
	cin >> s;
	int n = 0;
	for (int i = 0; i < sz(s); ++i)
		if (s[i] == '?') ++n;
	string res;
	for (int mask = 0; mask < (1 << n); ++mask) {
		int k = 0;
		int64 x = 0;
		res = s;
		for (int i = 0; i < sz(s); ++i) {
			x *= 2LL;
			if (s[i] == '0') continue;
			if (s[i] == '1') {
				++x;
				continue;
			}
			int cur = (mask >> k) & 1;
			res[i] = cur + '0';
			x += cur;
			++k;
		}
		int64 y = Sqrt(x);
		if (y * y == x) {
			break;
		}
	}
	cout << res << "\n";
}

int main()
{
	int nc;
	cin >> nc;
	for (int it = 0; it < nc; ++it) {
		printf("Case #%d: ", it + 1);
		solve();
	}
	return 0;
}
