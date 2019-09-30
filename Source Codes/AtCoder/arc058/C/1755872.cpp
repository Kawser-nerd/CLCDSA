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

const LL MOD = 1000000000 + 7;
LL dp[41][1 << 16];

int main() {
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	dp[0][0] = 1;
	int mask = (1 << (x + y + z - 1)) - 1;
	int xyz = (1 << (x + y + z - 1)) | (1 << (y + z - 1)) | (1 << (z - 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << (x + y + z - 1)); j++) {
			for (int k = 1; k <= 10; k++) {
				int bit = (j << k) | (1 << (k - 1));
				if ((bit&xyz) == xyz)  continue;
				(dp[i + 1][bit&mask] += dp[i][j]) %= MOD;
			}
		}
	}
	LL ans = 1;
	for (int i = 0; i < n; i++) {
		(ans *= 10) %= MOD;
	}
	for (int i = 0; i < (1 << (x + y + z - 1)); i++) {
		ans = (ans - dp[n][i] + MOD) % MOD;
	}
	cout << ans << endl;
}