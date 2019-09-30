#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  

int n;
int x[1000],cnt[1000],t[1000];

pair<ll,ll> y[500000]; int ny;

ll calc() {
	ll ret=LLONG_MAX;
	ny=0; REP(i,n) REP(j,cnt[i]) y[ny++]=MP((ll)(360-x[i])*(t[i]+j),(ll)360*(t[i]+j));
	sort(y,y+ny);
	priority_queue<pair<ll,ll>> q;
	ll base=0;
	REP(i,ny) {
		while(SZ(q)>0&&-q.top().first<=y[i].first) {
			ll a=-q.top().first,b=q.top().second,na=a+b; q.pop();
			//printf("processing %lld, popping %lld (%lld)\n",y[i].first,a,b);
			++base; q.push(MP(-na,b)); if(base>=ret) return ret;
		}
		q.push(MP(-y[i].first-y[i].second,y[i].second));
		ll cur=ny-i-1+base;
		if(cur<ret) ret=cur;
	}
	return ret;
}

void run(int casenr) {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d%d",&x[i],&cnt[i],&t[i]);
	printf("Case #%d: %lld\n",casenr,calc());
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
