#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

#define modp(x) (((x)%P+P)%P)
#define mod(x,y) (((x)%(y)+(y))%(y))

#define INF (1LL<<60)

#define MAX 2020202

long long hituyo[MAX+10];

main(){
	long long casenum,totcase;
	scanf("%lld",&totcase);
	for(long long casenum=1;casenum<=totcase;casenum++){
		long long m;
		long long fee;
		long long n;
		scanf("%lld%lld%lld",&m,&fee,&n);
		vector<pair<long long, long long> > food(n); //p,s
		for(long long i=0;i<n;i++){
			scanf("%lld%lld",&food[i].first,&food[i].second);
			food[i].second++;
			//printf("P=%lld S=%lld\n",food[i].first,food[i].second);
		}
		
		hituyo[0]=0;
		for(int t=1;t<=MAX;t++){
			long long mini=INF,mi=-1;
			for(int i=0;i<n;i++){
				if(t<=food[i].second){
					if(food[i].first<mini){mini=food[i].first;mi=i;}
				}
			}
			if(mi==-1)hituyo[t]=INF;
			else hituyo[t]=hituyo[t-1]+mini;
			//if(hituyo[t]!=INF)printf("%d: %lld (%lld)\n",t,hituyo[t],mi);
		}
		
		long long ans=0;
		
		for(long long d=1;d*fee<=m;d++){
			long long nokori=m-d*fee;
			long long lb=0,ub=MAX-10;
			for(;ub-lb>1;){
				long long mid=(ub+lb)/2;
				long long cost=d*hituyo[mid/d]+(mid%d)*(hituyo[mid/d+1]-hituyo[mid/d]);
				if(d>0 && hituyo[mid/d]>=INF)cost=INF;
				if((mid%d)>0 && hituyo[mid/d+1]>=INF)cost=INF;
				//if(d<10)printf("%lld:cost=%lld\n",mid,cost);
				if(cost>nokori)ub=mid;
				else lb=mid;
			}
			//if(lb>MAX-20)printf("%lld yaba\n",d);
			ans=max(ans,lb);
		}
		printf("Case #%lld: %lld\n",casenum,ans);
		
	}
}