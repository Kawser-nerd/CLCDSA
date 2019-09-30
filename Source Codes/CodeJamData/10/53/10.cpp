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

ll bf(vector<pair<int,int> > start) {
	ll ret=0;
	while(true) {
//		printf("%2lld: ",ret); REPSZ(i,start) printf("(%d,%d)",start[i].first,start[i].second); puts("");
		bool found=false;
		REPSZ(i,start) if(start[i].second>=2) {
			++ret;
			start[i].second-=2;
			if(i+1>=SZ(start)||start[i+1].first!=start[i].first+1) {
				start.insert(start.begin()+i+1,MP(start[i].first+1,0));
			}
			start[i+1].second++;
			if(i-1<0||start[i-1].first!=start[i].first-1) {
				start.insert(start.begin()+i,MP(start[i].first-1,0));
				++i;
			}
			start[i-1].second++;
			found=true; break;
		}
		if(!found) break;
	}
	return ret;
}

ll sum(ll h,int cnt) {
	return (h+h-cnt+1)*cnt/2;
}

void run(int casenr) {
	int npos; scanf("%d",&npos);
	vector<pair<int,int> > start(npos); REP(i,npos) scanf("%d%d",&start[i].first,&start[i].second);
	
	vector<pair<int,int> > onesegs;
	int ind=0,at=INT_MIN,cnt=0,ones=0,carry=0;
	ll ret=0;
	while(ind<npos||cnt>0||carry>0) {
		if(ind<npos&&at==start[ind].first) { cnt+=start[ind].second; ++ind; }
//		printf("at=%d, cnt=%d, ones=%d, carry=%d, ind=%d, ret=%lld ",at,cnt,ones,carry,ind,ret);
//		REPSZ(i,onesegs) printf("(%d,%d)",onesegs[i].first,onesegs[i].second); puts("");
		if(cnt==0) {
			if(ones>0) onesegs.PB(MP(at-ones,at-1));
			ones=0;
			if(carry==0) {
				at=start[ind].first;
				cnt=0;
				carry=0;
			} else {
				++at;
				cnt=carry;
				carry=0;
			}
		} else if(cnt==1) {
			++ones;
			++at;
			cnt=carry;
			carry=0;
		} else if(cnt>=ones+2) {
			int now=ones+1;
			ret+=sum(ones+1,now);
			cnt-=now+1;
			carry+=now;
			ones++;
		} else if(cnt==ones+1) {
			int now=cnt-1;
			ret+=sum(ones+1,now);
			cnt-=ones;
			carry+=ones;
			onesegs.PB(MP(at-ones-1,at-ones-1+ones-1));
			ones=0;
		} else {
			int now=cnt-1;
			ret+=sum(ones+1,now);
			cnt-=now;
			carry+=now;
			onesegs.PB(MP(at-ones-1,at-ones-1+now-1));
			if(now<ones) onesegs.PB(MP(at-(ones-now),at-1));
			ones=0;
		}
		while(SZ(onesegs)>0&&onesegs.back().second==at-ones-1) {
			ones+=onesegs.back().second-onesegs.back().first+1;
			onesegs.pop_back();
		}
	}
	printf("Case #%d: %lld\n",casenr,ret);
/*	ll check=bf(start);
	if(check!=ret&&check<=211) {
		printf("got %lld, need %lld\n",ret,check);
		REPSZ(i,start) printf("%d %d\n",start[i].first,start[i].second);
		assert(false);
	}
	printf("Case #%d: %lld\n",casenr,check); */
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run(i);
	return 0;
}
