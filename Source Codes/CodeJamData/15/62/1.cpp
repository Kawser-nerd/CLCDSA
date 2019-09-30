#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define MOD 1000000007ll

#define MAX 1000010

ll F[MAX],Finv[MAX],inv[MAX];
ll dp0[MAX],dp1[MAX];

ll comb(int N, int K){
	return F[N] * Finv[K] % MOD * Finv[N-K] % MOD;
}
	
void pre(void){
	int i;
	
	inv[1] = 1;
	for(i=2;i<MAX;i++) inv[i] = inv[MOD%i] * (MOD - MOD/i) % MOD;
	F[0] = Finv[0] = 1;
	for(i=1;i<MAX;i++){
		F[i] = F[i-1] * i % MOD;
		Finv[i] = Finv[i-1] * inv[i] % MOD;
	}
	
	dp0[0] = 1;
	for(i=1;i<MAX;i++){
		dp0[i] = dp1[i-1] * (i - 1) % MOD;
		dp1[i] = (dp0[i-1] + dp1[i-1] * (i - 1)) % MOD;
	}
}
	
void main2(void){
	int i,N,X;
	
	cin >> N >> X;
	ll ans = 0;
	for(i=X;i<=N;i++){
		ll c = comb(N, i);
		ll tmp = c * c % MOD * F[i] % MOD * F[N-i] % MOD * dp0[N-i] % MOD;
		ans = (ans + tmp) % MOD;
	}
	
	cout << ans << endl;
}
	
int main(void){
	pre();
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
