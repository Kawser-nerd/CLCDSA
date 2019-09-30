#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#define let(i,a) __typeof(a)i=a
#define MOD 1000000007
using namespace std;

long long N, SN, SM, X, Y, Z;

template <class T>
struct fenwick_tree {
  vector<T> x;
  fenwick_tree(int n) : x(n, 0) { }
  T sum(int i, int j) {
    if (i == 0) {
      T S = 0;
	  for (j; j >= 0; j = (j & (j + 1)) - 1) {
		  S = (S + x[j]) % MOD;
	}
      return S;
    } else return (sum(0, j) - sum(0, i-1) + MOD) % MOD;
  }
  void add(int k, T a) {
	for (; k < x.size(); k |= k+1) {
		x[k] = (x[k] + a) % MOD;
	}
  }
};

int main() {
	scanf("%lld", &N);
	for (int case_n = 1; case_n <= N; case_n++) {
		scanf("%lld%lld%lld%lld%lld", &SN, &SM, &X, &Y, &Z);
		vector<long long> A(SM), S(SN);
		for (long long i = 0; i < SM; i++) {
			scanf("%lld", &A[i]);
		}
		map<long long, int> RANK;
		RANK.clear();
		for (long long i = 0; i < SN; i++) {
			S[i] = A[i % SM];
			RANK[S[i]] = 1;
			A[i % SM] = (X * A[i % SM] + Y * (i + 1)) % Z;
		}
		int rank = 0;
		for (let(it, RANK.begin()); it != RANK.end(); it++) {
			it->second = ++rank;
		}
		fenwick_tree<long long> F(rank + 1);
		for (long long i = 0; i < SN; i++) {
			//printf("%d ", RANK[S[i]]);
			F.add(RANK[S[i]], 1 + F.sum(0, RANK[S[i]] - 1));
		}
		//puts("");
		printf("Case #%d: %lld\n", case_n, F.sum(0, rank) % MOD);
	}
	return 0;
}
