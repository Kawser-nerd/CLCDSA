#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

const int INF=1e9;
const ll INFF=1e17;
const double EPS=1e-9;
const ll MOD=1e9+7;
const int MAXN=2e5+10;
/*
	Complexity of Update, Query: O(log N)
	Complexity of Build: O(N)
*/
ll tree[4*MAXN],a[4*MAXN],lazy[4*MAXN];
void build(ll node,ll start,ll end){
	if(start==end)tree[node]=a[start];
	else{
		ll mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
void updateRange(ll node,ll start,ll end,ll l,ll r,ll val){
	if(lazy[node]!=0){
		tree[node]+=(end-start+1)*lazy[node];
		if(start!=end){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>end || start>r || end<l)return;
	if(start>=l && end<=r){
		tree[node]+=(end-start+1)*val;
		if(start!=end){
			lazy[node*2]+=val;
			lazy[node*2+1]+=val;
		}
		return;
	}
	ll mid=(start+end)/2;
	updateRange(node*2,start,mid,l,r,val);
	updateRange(node*2+1,mid+1,end,l,r,val);
	tree[node]=tree[node*2]+tree[node*2+1];
}
ll queryRange(ll node,ll start,ll end,ll l,ll r){
	if(start>end || start>r || end<l)return 0;
	if(lazy[node]!=0){
		tree[node]+=(end-start+1)*lazy[node];
		if(start!=end){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(start>=l && end<=r)return tree[node];
	ll mid=(start+end)/2;
	ll p1=queryRange(node*2,start,mid,l,r);
	ll p2=queryRange(node*2+1,mid+1,end,l,r);
	return p1+p2;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m,x[MAXN],cnt[MAXN],ans=0;
	cin >> n >> m;
	REP(i,n){cin >> x[i];cnt[x[i]]++;}
	REP(i,n)a[i]=0;build(1,0,n-1);
	FOR(i,1,n+1)if(cnt[i])updateRange(1,0,n-1,max(i-cnt[i],0LL),i-1,1);
	REP(i,n)if(!queryRange(1,0,n-1,i,i))ans++;
	REP(i,m){
		ll t1,t2;cin >> t1 >> t2;t1--;
		if(x[t1]-cnt[x[t1]]>=0)updateRange(1,0,n-1,x[t1]-cnt[x[t1]],x[t1]-cnt[x[t1]],-1);
		if(x[t1]-cnt[x[t1]]>=0 && !queryRange(1,0,n-1,x[t1]-cnt[x[t1]],x[t1]-cnt[x[t1]]))ans++;
		cnt[x[t1]]--;
		x[t1]=t2;
		cnt[t2]++;
		if(t2-cnt[t2]>=0){
			if(!queryRange(1,0,n-1,t2-cnt[t2],t2-cnt[t2]))ans--;
			updateRange(1,0,n-1,t2-cnt[t2],t2-cnt[t2],1);
		}
		cout << ans << '\n';
	}
	return 0;
}