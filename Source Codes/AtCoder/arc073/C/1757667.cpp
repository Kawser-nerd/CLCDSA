# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
# include <bitset>
# include <complex>
# include <numeric>
#include <tuple>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int INF = 2000000000;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
#define ALL(x)   (x).begin(),(x).end()
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define mp       make_pair
#define eb       emplace_back
typedef pair<LL, LL> P;
typedef pair<LL, P> PP;

int n, a[202020], b[202020], maxl = -INF, minl = INF, omaxl, ominl, c[202020];
int comp(int x, int y) {
	return a[x]<a[y];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		 c[i] = i;
		if (a[i]>b[i])swap(a[i], b[i]);
		if (maxl<b[i])maxl = b[i], omaxl = a[i];
		if (minl>a[i])minl = a[i], ominl = b[i];
	}
	int _mx = omaxl, _mn = ominl;
	for (int i = 1; i <= n; ++i)
		_mx = max(_mx, a[i]), _mn = min(_mn, b[i]);
	long long ans = 1ll * (maxl - _mn)*(_mx - minl);
	sort(c + 1, c + n + 1, comp);
	int x = INF;
	for (int i = 1; i <= n; ++i)
		ans = min(ans, 1ll * (maxl - minl)*(_mx - min(a[c[i]], x))), x = min(b[c[i]], x), _mx = max(_mx, b[c[i]]);
	cout << ans << endl;
}