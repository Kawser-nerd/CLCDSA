#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define INF 1LL<<62
#define MAXT 500001
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,N;
ll w[500001];
vector<int> t[500001];
ll dp[1<<20];
ll maxi[1<<22],lazy[1<<22];
int prevt[500001];
inline void lazy_evaluate_node(int k){
	maxi[k]+=lazy[k];
	if(k<N-1){
		lazy[k*2+1]+=lazy[k];
		lazy[k*2+2]+=lazy[k];
	}
	lazy[k]=0;
}

inline void update_node(int k){
	if(k<N-1)maxi[k]=max(maxi[k*2+1],maxi[k*2+2]);
}

void update(int a,int b,ll x,int k=0,int l=0,int r=N){
	lazy_evaluate_node(k);
	if(r<=a || b<=l)return;
	if(a<=l && r<=b){
		lazy[k]+=x;
		lazy_evaluate_node(k);
		return;
	}
	update(a,b,x,k*2+1,l,(l+r)/2);
	update(a,b,x,k*2+2,(l+r)/2,r);
	update_node(k);
}

ll get(int a,int b,int k=0,int l=0,int r=N){
	lazy_evaluate_node(k);
	if(r<=a || b<=l)return -INF;
	if(a<=l && r<=b)return maxi[k];
	ll vl=get(a,b,k*2+1,l,(l+r)/2);
	ll vr=get(a,b,k*2+2,(l+r)/2,r);
	update_node(k);
	return max(vl,vr);
}

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=0;i<n;i++){
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			int a;
			scanf("%d",&a);
			t[a/2].push_back(i);
		}
	}
	N=1;
	while(N<MAXT)N*=2;
	ll res=0;
	for(int i=1;i<=MAXT;i++){
		for(int j=0;j<t[i].size();j++){
			update(prevt[t[i][j]],i,w[t[i][j]]);
			prevt[t[i][j]]=i;
		}
		dp[i]=get(0,i);
		update(i,i+1,dp[i]);
		//if(i<20)printf("%d %lld\n",i,dp[i]);
		res=max(res,dp[i]);
	}
	printf("%lld\n",res);
	return 0;
} ./Main.cpp:52:26: warning: shifting a negative signed value is undefined [-Wshift-negative-value]
        if(r<=a || b<=l)return -INF;
                               ~^~~
./Main.cpp:12:16: note: expanded from macro 'INF'
#define INF 1LL<<62
               ^
1 warning generated.