#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
//#include <iostream>
#include <numeric>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
//#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b);i>=(e);--i)

#define PB push_back
#define ALL(V) (V).begin(),(V).end()
#define SIZE(V) ((int)(V).size())

#define MP make_pair
#define ST first
#define ND second

#define DBG

#ifdef DBG
	#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
	#define debug(...)
#endif

int __stmp;
#define scanf __stmp=scanf


const int INF = 1000000001;
const int MAX = 100000;

#define PARALLEL 0

/* UWAGA NA PAMIEC!
   Moze byc potrzebne nawet Z razy wiecej pamieci w trakcie dzialania,
   chyba ze bedzie sie ja alokowac i zwalniac w solve() wtedy moze byc
   potrzebne do <liczba rdzeni> razy wiecej.
   Kompilowac z --openmp
 */

inline void remax(int &a, int b) { if(b > a) a = b; }

class solver {
	public:
		// wczytujemy caly input dla jednego zestawu danych
		void input() {
			scanf("%d %d %d", &n, &m, &k);
		}
		
		// skminiamy rozwiazanie
		void solve() {
			if(m > n) swap(n, m);
			int border = 2*(n+m) - 4;
			vector<vector<VVI>> dp(n, vector<VVI>(m, VVI(m, VI(border+100, 0))));
			// int dp[n][m][m][border+100];
			// memset(dp, 0, sizeof dp);
			REP(a,m)
				FOR(b,a,m-1)
					dp[0][a][b][b-a+1] = b-a+1;
			REP(i,n-1)
				REP(a,m)
					FOR(b,a,m-1)
						FOR(s,1,border)
							if(dp[i][a][b][s]) {
								FOR(aa,max(0,a-1),min(m-1,a+1))
									FOR(bb,max(aa,b-1),min(m-1,b+1))
										remax(dp[i+1][aa][bb][s+1+(aa!=bb)], dp[i][a][b][s] + (bb-aa+1));
							}
			res = k;
			FOR(i,1,n-1)
				REP(a,m)
					FOR(b,a,m-1)
						FOR(s,1,border)
						{
							// printf("[%d][%d][%d][%d] = %d\n", i, a, b, s, dp[i][a][b][s]);
							if(dp[i][a][b][s] >= k) {
								int t = s;
								if(b > a + 1)
									t += (b-a+1)-2;
								res = min(res, t);
							}
						}
		}
		
		// wypisujemy output
		void output() {
			printf("%d\n", res);
		}
	private:
		int n, m, k;
		int res;
};

int main(int argc, char *argv[]) {
	int case_id = argc == 2 ? atoi(argv[1])-1 : -1;
	int Z;
	scanf("%d", &Z);
	vector<solver> S(Z);
	REP(z,Z) S[z].input();
	if(case_id == -1) {
		#if PARALLEL == 1
			#pragma omp parallel for schedule(dynamic)
		#endif
		REP(z,Z) S[z].solve();
	} else {
		S[case_id].solve();
	}
	REP(z,Z)
	{
		if(case_id == -1 || z == case_id) {
			printf("Case #%d: ", z+1);
			S[z].output();
		}
	}
	return 0;
}
