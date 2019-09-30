#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<set>
#include<unordered_set>
#include <assert.h>
typedef long long int ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<signed(n);i++)
#define EREP(i,n) for(int i=1;i<=signed(n);i++)
#define ALL(a) (a).begin(),(a).end()
using std::cout;
using std::vector;
using std::endl;
using std::cin;
using std::string;
using std::min;
using std::max;
//#define EVEL 1
#ifdef EVEL
#define DEB(X) cout << #X << ":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
const ll MOD = 1000000007;
const ll INF = 9e9;
// typedef std::pair<int,int> P;
struct edge { int to, cost; };
#define VMAX 100000

int K;
ll N, ans = 0;
ll X[100010], Y[100010];
ll W_[3010][3010], B_[3010][3010];
auto W = W_ + 3;
std::string C[100010];
//yxyx
ll imos(int a, int b, int c, int d, int mode) {
	assert(c < 2 * K || d < 2*K);
	if (mode == 0) return W[c][d] - W[c][b - 1] - W[a - 1][d] + W[a - 1][b - 1];
	//else        return B[c][d] - B[c][b - 1] - B[a - 1][d] + B[a - 1][b - 1];
	return 0;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> N >> K;
	REP(i, N) {
		cin >> X[i] >> Y[i] >> C[i];
		X[i] %= 2 * K, Y[i] %= 2 * K;
		if (C[i] == "W")W[Y[i]][X[i]] += 1;
		else W[Y[i]][(X[i] + K) % (2 * K)] += 1;
	}
	REP(i, 2 * K)REP(j, 2 * K) {
		W[i][j + 1] += W[i][j];
		//B[i][j + 1] += B[i][j];
	}
	REP(i, 2 * K)REP(j, 2 * K) {
		W[i + 1][j] += W[i][j];
		//B[i + 1][j] += B[i][j];
	}

	//for (size_t i = 0; i < 2 * K; i++)
	//{
	//	for (size_t j = 0; j < 2 * K; j++)
	//	{
	//		cout << W[i][j] << ' ';
	//	}
	//	cout << endl;
	//}

	REP(i, K)REP(j, K)REP(k, 2) {
		ll tans = 0;
		tans += imos(0    ,     0,     i - 1,     j - 1, 0);
		tans += imos(0    , j + K,     i - 1, 2 * K - 1, 0);
		tans += imos(i    ,     j, i + K - 1, j + K - 1, 0);
		tans += imos(K + i,     0, 2 * K - 1,     j - 1, 0);
		tans += imos(K + i, j + K, 2 * K - 1, 2 * K - 1, 0);
		ans = max(tans, ans);
		ans = max(W[2*K-1][2*K-1] - tans, ans);
	}
	cout << ans << endl;
	return 0;
}