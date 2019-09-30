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
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr long long MOD = 1000000000 + 7;
constexpr double DINF = 100000000000000000.0;
constexpr long long INF = 9000000000000000000;
const double PI = acos(-1);

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

int main() {
	int n;
	string cmd;
	cin >> n >> cmd;

	LL ans = INF;

	string bt = "ABXY";
	REP(i, 4) REP(j, 4) REP(k, 4) REP(l, 4) {
		string L = "", R = "";
		L += bt[i]; L += bt[j];
		R += bt[k]; R += bt[l];

		LL count = 0;
		REP(m, n) {
			string sb = "";
			if (m < n - 1) sb = cmd.substr(m, 2);
			if (sb == L || sb == R) m++;
			count++;
		}
		ans=min(ans, count);
	}
	cout << ans << endl;
}