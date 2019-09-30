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

int n;

#define PARALLEL 1

/* UWAGA NA PAMIEC!
   Moze byc potrzebne nawet Z razy wiecej pamieci w trakcie dzialania,
   chyba ze bedzie sie ja alokowac i zwalniac w solve() wtedy moze byc
   potrzebne do <liczba rdzeni> razy wiecej.
   Kompilowac z --openmp
 */

LL gcd(LL a, LL b) { return b ? gcd(b, a%b) : a; }

bool power_of_2(LL x) {
	if(x == 1) return true;
	if(x%2) return false;
	return power_of_2(x/2);
}

class solver {
	public:
		// wczytujemy caly input dla jednego zestawu danych
		void input() {
			scanf("%lld/%lld", &a, &b);
		}
		
		// skminiamy rozwiazanie
		void solve() {
			res = 0;
			LL d = gcd(a, b);
			a /= d;
			b /= d;
			if(!power_of_2(b)) {
				res = -1;
				return;
			}
			while(b != 1)
			{
				res++;
				b /= 2;
			}
			while(a != 1)
			{
				a /= 2;
				res--;
			}
		}
		
		// wypisujemy output
		void output() {
			if(res == -1) printf("impossible\n");
			else printf("%d\n", res);
		}
	private:
		int res;
		LL a, b;
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
