#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define MOD 1000003ll

ll inv[1000010],f[1000010],finv[1000010];

void pre(void){
	int i;
	
	inv[1] = 1;
	for(i=2;i<MOD;i++) inv[i] = (MOD - MOD/i) * inv[(int)(MOD%i)] % MOD;
	
	f[0] = finv[0] = 1;
	for(i=1;i<MOD;i++) f[i] = f[i-1] * i % MOD;
	for(i=1;i<MOD;i++) finv[i] = finv[i-1] * inv[i] % MOD;
}

string s;
int cnt[30];
vector <int> v;
ll dp[30][110]; // pos, runs

ll comb(ll N, ll K){
	if(N < K) return 0;
	return f[N] * finv[K] % MOD * finv[N-K] % MOD;
}

void calc(void){
	int N=v.size(),i,j,k,l;
	
	REP(i,N+1) REP(j,105) dp[i][j] = 0;
	dp[1][1] = 1;
	
	int sum = 0;
	for(i=1;i<N;i++){
		sum += v[i-1];
		for(j=1;j<105;j++) if(dp[i][j] != 0){
			int one = j+1, two = sum-j;
			for(k=0;j+k<105;k++) for(l=0;j+k+2*l<105;l++) if(k+l > 0){
				int j2 = j+k+2*l;
				ll tmp = comb(one,k) * comb(two,l) % MOD * comb(v[i]-1,k+l-1) % MOD;
				dp[i+1][j2] = (dp[i+1][j2] + dp[i][j] * tmp) % MOD;
			}
		}
	}
}

void main2(void){
	int i;
	
	cin >> s;
	
	REP(i,26) cnt[i] = 0;
	REP(i,s.length()) cnt[s[i]-'a']++;
	v.clear();
	REP(i,26) if(cnt[i] > 0) v.push_back(cnt[i]);
	
	int runs = 0;
	REP(i,s.length()) if(i == 0 || s[i] != s[i-1]) runs++;
	
	calc();
	int N = v.size();
	cout << dp[N][runs] << endl;
}

//////////////////////////////// multiple testcases ////////////////////////////////

int main(void){
	int T,t;
	pre();
	scanf("%d",&T);
	REP(t,T){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
