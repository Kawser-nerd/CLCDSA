using namespace std;
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cstring>
#include<cmath>

typedef long double D; typedef long long LL; typedef pair<int,int> pii;
#define ALL(v) (v).begin(),(v).end()
#define REP(i, n) for (int i (0); i < (n); i ++)
#define FORIT(a,b, it) for(__typeof(b)it(a);it!=(b);++it)
#define FOREACH(v, it) FORIT((v).begin(),(v).end(),it)
#define len(v) ((int)(v).size())
#define append push_back
#define _ make_pair
#define fi first
#define se second
#define add insert
#define remove erase
#define TWO(x) (1<<(x))
#define UNIQUE(v) (v).erase(unique(ALL(v)),(v).end())
const int infInt (1010101010);
const LL  infLL  (4 * LL (infInt) * LL (infInt));

template<class T>void pv(T a,T b){FORIT(a,b,it)cout<<*it<<" ";cout<<endl;}

inline void chmin(int&x,int y){x=min(x,y);}
inline void chmax(int&x,int y){x=max(x,y);}

long double test(int l1, int l2, vector<long long> amount, long long A) {
	long double cost = 0;
	for (int i=0;  i<l1; i++) cost += A   - amount[i];
	for (int i=l1; i<l2; i++) cost += A+1 - amount[i];
	long double reward = 0;
	for (int i=0;  i<l1; i++) {
		reward += A - amount[i];
	}
	reward *= 36; reward /= (long double) l1;
	return reward - cost;
}

int main() {
	int T;
	scanf("%d",&T);
	for (int case_nr=1; case_nr<=T; case_nr++) {
		long long B;
		scanf("%lld", &B);
		const int N = 37;
		vector<long long> amount (N); // sorted low to high
		{
			int n;
			scanf("%d",&n);
			for (int i=0; i<n; i++) scanf("%lld", &amount[i]);
			sort(amount.begin(), amount.end());
		}
		long double answer = 0;
		for (int l1 = 1; l1 <= N; l1 ++) { // increase [l1..l2-1] to become too big
			for (int l2 = l1; l2 <= N; l2 ++) { // [l2..n-1] already are too big
				long long A_low = amount[l2 - 1];
				long long A_high = (l2 == N) ? (B) : (amount[l2] - 1);
				if (A_low > A_high) continue;
				// cost(A) = sum(i=0..l1-1) (A - amount[i]) + sum(i=l1..l2-1) (A+1 - amount[i])
				long long S = 0;
				for (int i=0;  i<l1; i++) S += amount[i];
				for (int i=l1; i<l2; i++) S += amount[i] - 1;
				// cost(A) = l2*A - S <= B
				// l2*A <= B + S
				// A <= (B + S) / l2
				if (B + S < 0) continue;
				A_high = min(A_high, (B + S) / l2);
				if (A_low > A_high) continue;
				answer = max(answer, test(l1, l2, amount, A_low));
				answer = max(answer, test(l1, l2, amount, A_high));
				// return(A) = 1/l1 * sum(i=0..l1-1) (36*(A - amount[i]))
				// val(A) = return(A) - cost(A)
				
				// constraint: cost(A) <= B. then check endpoints
			}
		}
		printf("Case #%d: %.10Lf\n", case_nr, answer);
	}
}
