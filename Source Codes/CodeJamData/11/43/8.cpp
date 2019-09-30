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

#define M 1000010
bool prime[M];

void pre(void){
	int i,j;
	for(i=2;i<M;i++) prime[i] = true;
	for(i=2;i<M;i++) if(prime[i]) for(j=2*i;j<M;j+=i) prime[j] = false;
}

void main2(void){
	ll N,p;
	
	cin >> N;
	if(N == 1){
		cout << 0 << endl;
		return;
	}
	
	ll ans = 1;
	for(p=2;p*p<=N;p++) if(prime[p]){
		int cnt = 0;
		ll x = N;
		while(1){
			x /= p;
			if(x == 0) break; else cnt++;
		}
		ans += cnt - 1;
	}
	
	cout << ans << endl;
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
