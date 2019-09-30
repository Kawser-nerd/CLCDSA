#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iostream>
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

#define PARALLEL 1

/* UWAGA NA PAMIEC!
   Moze byc potrzebne nawet Z razy wiecej pamieci w trakcie dzialania,
   chyba ze bedzie sie ja alokowac i zwalniac w solve() wtedy moze byc
   potrzebne do <liczba rdzeni> razy wiecej.
   Kompilowac z --openmp
 */

const int MOD = 1000000007;
const int A = 26;

class solver {
	public:
		// wczytujemy caly input dla jednego zestawu danych
		void input() {
			cin >> n;
			arr.resize(n);
			REP(i,n) cin >> arr[i];
		}
		
		// skminiamy rozwiazanie
		void solve() {
			fact.PB(1);
			FOR(i,1,100) fact.PB(fact.back() * i % MOD);
			
			VI all(A, 0);
			VI nxt(A, -1);
			VI inside(A, 0), beg(A, 0), last(A, 0), in(A, 0);
			REP(i,n)
			{
				int pref = 1;
				while(pref < SIZE(arr[i]) && arr[i][pref] == arr[i][0]) pref++;
				int suf = 1;
				while(suf < SIZE(arr[i]) && arr[i][SIZE(arr[i])-suf-1] == arr[i].back()) suf++;
				if(pref == SIZE(arr[i])) {
					all[(int)arr[i][0]-'a']++;
					continue;
				}
				for(int k=pref;k<SIZE(arr[i])-suf;k++)
					inside[(int)arr[i][k]-'a'] = 1;
				beg[(int)arr[i][0]-'a'] = 1;
				last[(int)arr[i].back()-'a'] = 1;
				if(nxt[(int)arr[i][0]-'a'] != -1 && nxt[(int)arr[i][0]-'a'] != arr[i].back()-'a') {
					res = 0;
					return;
				}
				nxt[(int)arr[i][0]-'a'] = arr[i].back()-'a';
				if(in[(int)arr[i].back()-'a']) {
					res = 0;
					return;
				}
				in[(int)arr[i].back()-'a'] = 1;
			}
			REP(i,A)
				if(inside[i] && (beg[i] || last[i])) {
					res = 0;
					return;
				}
			REP(i,A)
			{
				VI vis(A, 0);
				int u = i;
				do {
					vis[u] = 1;
					u = nxt[u];
				} while(u != -1 && !vis[u]);
				if(u != -1) {
					res = 0;
					return;
				}
			}
			int cc = 0;
			REP(i,A)
				if(all[i] > 0 || beg[i] || last[i])
					cc++;
			REP(i,A)
				if(nxt[i] != -1)
					cc--;
			res = fact[cc];
			REP(i,A)
			{
				res = res * fact[all[i]] % MOD;
			}
		}
		
		// wypisujemy output
		void output() {
			printf("%lld\n", res);
		}
	private:
		int n;
		vector<string> arr;
		VLL fact;
		LL res;
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
