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
# include <tuple>
# include <unordered_map>
# include <numeric>
# include <complex>
# include <bitset>
# include <random>
# include <chrono>
# include <cstdlib>
# include <tuple>
# include <array>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
constexpr int INF = 2147483647;
constexpr int HINF = INF / 2;
constexpr double DINF = 100000000000000000.0;
constexpr double HDINF = 50000000000000000.0;
constexpr long long LINF = 9223372036854775807;
constexpr long long HLINF = 4500000000000000000;
const double PI = acos(-1);
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
# define ALL(x)      (x).begin(),(x).end()
# define UNIQUE(c)   sort(ALL((c)));(c).erase(unique(ALL((c))),(c).end())
# define LOWER(s)    transform(ALL((s)),(s).begin(),TL<char>)
# define UPPER(s)    transform(ALL((s)),(s).begin(),TU<char>)
# define FOR(i,a,b)  for(LL i=(a);i<(b);i++)
# define RFOR(i,a,b) for(LL i=(a);i>=(b);i--)
# define REP(i,n)    FOR(i,0,n)
# define INIT        std::ios::sync_with_stdio(false);std::cin.tie(0)

int N;
char C[4020];
int A[4020];
int smB[2020][4020];
int smW[2020][4020];
int idxB[2020];
int idxW[2020];

int memo[2020][2020];
int f(int b, int w) {
	if (b == N && w == N) return 0;
	if (0 <= memo[b][w]) return memo[b][w];

	int res = INF;

	if (b != N) {
		int cnt = 0;
		if (0 <= idxB[b + 1] - 1) cnt += smB[b + 1][idxB[b + 1] - 1];
		if (0 <= idxB[b + 1] - 1) cnt += smW[w + 1][idxB[b + 1] - 1];

		res = min(res, f(b + 1, w) + cnt);
	}

	if (w != N) {
		int cnt = 0;
		if (0 <= idxW[w + 1] - 1) cnt += smB[b + 1][idxW[w + 1] - 1];
		if (0 <= idxW[w + 1] - 1) cnt += smW[w + 1][idxW[w + 1] - 1];
		res = min(res, f(b, w + 1) + cnt);
	}

	return memo[b][w] = res;
}

int main() {
	cin >> N;
	REP(i, 2 * N) cin >> C[i] >> A[i];

	REP(i, 2 * N) {
		if (C[i] == 'B') smB[A[i]][i]++;
		else smW[A[i]][i]++;
	}
	REP(i, N + 5) {
		FOR(j, 1, 2 * N) smB[i][j] += smB[i][j - 1];
		FOR(j, 1, 2 * N) smW[i][j] += smW[i][j - 1];
	}
	REP(j, 2 * N) {
		for (int i = N + 4; i >= 0; i--) smB[i][j] += smB[i + 1][j];
		for (int i = N + 4; i >= 0; i--) smW[i][j] += smW[i + 1][j];
	}

	REP(i, 2 * N) {
		if (C[i] == 'B') idxB[A[i]] = i;
		if (C[i] == 'W') idxW[A[i]] = i;
	}

	REP(i, N + 1) REP(j, N + 1) memo[i][j] = -1;
	cout << f(0, 0) << endl;
}