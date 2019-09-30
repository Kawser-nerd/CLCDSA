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

pair <double, ll> func(ll X, ll x, ll M){
	int k,bestk=1;
	ll best=0,besta=1;
	
	for(k=2;;k++){
		ll two = (1ll<<k);
		if(two > M) break;
		ll a = min(X/2,M/two);
		ll tmp = (two-2) * a;
		if(tmp >= best) {best = tmp; bestk = k; besta = a;}
	}
	
	if(x >= besta){
		double ans = (double)(x + best) / (double)(X + best);
		ll ans2 = min(min(x-besta,X-x),M/2);
		ll tmp = x + best;
		for(k=1;;k++){
			ll two = (1ll<<k);
			if(two-1 > tmp) break;
			if(tmp % (two-1) == 0){
				ll tmp2 = tmp / (two-1);
				if(tmp2 <= x && x+tmp2 <= X && x+tmp2+best <= M) ans2 = max(ans2,tmp2);
			}
		}
		return make_pair(ans,ans2);
	}
	
	double p = (double)(besta + best) / (double)(X + best);
	{
		pair <double, ll> ans = func(besta,x,M);
		ans.first *= p;
		return ans;
	}
}

void main2(void){
	ll A,M,V;
	cin >> A >> M >> V;
	pair <double, ll> ans = func(V,A,2*M);
	printf("%.9f %lld\n",ans.first,ans.second);
}

//////////////////////////////// multiple testcases ////////////////////////////////

int main(void){
	int T,t;
	scanf("%d",&T);
	REP(t,T){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
