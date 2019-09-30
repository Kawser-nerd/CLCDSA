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
#define INF (1l<<60)

ll sum(ll x, ll y){
	return min(x+y, INF);
}

ll prod(ll x, ll y){
	if(x == 0 || y == 0) return 0;
	if(y <= INF / x) return x * y;
	return INF;
}

ll M,C;
int N;
ll price[210],day[210];
vector <pair <ll, ll> > intervals; // day, price

ll func(ll low, ll high, ll init, ll slant, ll xsum){
	// low K <= xsum <= high K
	ll Kmin = (xsum + high - 1) / high;
	ll Kmax = xsum / max(low, 1ll);
	
	if(Kmin > Kmax) return INF;
	
	ll ans = slant * xsum;
	ll tmp = xsum * low - init;
	if(tmp > 0) ans += Kmin * tmp; else ans += Kmax * tmp;
	return ans;
}

ll minysum(ll xsum){
	int K = intervals.size();
	ll low = 0;
	ll init = C;
	ll ans = INF;
	
	REP(i,K){
		ll high = low + intervals[i].first;
		ll tmp = func(low, high, init, intervals[i].second, xsum);
		ans = min(ans, tmp);
		init = sum(init, prod(high - low, intervals[i].second));
		low = high;
	}
	
	return ans;
}

void main2(void){
	int i;
	
	cin >> M >> C >> N;
	REP(i,N) {cin >> price[i] >> day[i]; day[i]--;}
	
	intervals.clear();
	ll d = 0;
	while(1){
		int x = -1;
		REP(i,N) if(day[i] > d && (x == -1 || price[i] < price[x])) x = i;
		intervals.push_back(make_pair(day[x]-d,price[x]));
		d = day[x];
	}
	
	ll low = 0, high = INF; // can eat low days
	while(high-low > 1){
		ll mid = (high + low) / 2;
		if(minysum(mid) <= M) low = mid; else high = mid;
	}
	
	cout << low << endl;
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
