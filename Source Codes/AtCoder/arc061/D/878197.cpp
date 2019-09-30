#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define mod  1000000007
ll modpow(ll x,ll n)
{
	ll res=1;
	while(n>0)
	{
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[1000005],R[1000005],th[1000005],tw[1000005];
void make(){
	F[0] = th[0] = tw[0] = 1;
	for(int i=1;i<1000005;i++){
		F[i] = F[i-1]*i%mod;
		th[i]  = th[i-1]*3LL%mod;
		tw[i] = tw[i-1]*2LL%mod;
	}
	for(int i=0;i<1000005;i++) R[i] = modpow(F[i],mod-2);
}
ll C(int n,int m){
	return F[n] * R[m] % mod * R[n-m] % mod;
}
int main(){
	int n,m,k; cin >> n >> m >> k;
	if(m>k) swap(m,k);
	make();
	ll ret = 0;
	for(int i=0;i<=m;i++){
		//for(int j=0;j<=k;j++){
			ll sum = C(n+i-1,n-1) * tw[i] % mod;
			sum *= th[m+k-i];
			sum %= mod;
			ret += sum;
	//	}
	}
	ll beg = tw[m];
	for(int i=m+1;i<=k;i++){
		//for(int j=0;j<=k;j++){
			beg = beg*2LL-C(i-1,m);
			beg = (beg%mod+mod)%mod;
			ll sum = C(n+i-1,n-1) * beg % mod;
			sum *= th[m+k-i];
			sum %= mod;
			ret += sum;
	//	}
	}
	for(int i=k+1;i<=m+k;i++){
		//for(int j=0;j<=k;j++){
			beg = beg*2LL-C(i-1,m)-C(i-1,i-k-1);
			beg = (beg%mod+mod)%mod;
			ll sum = C(n+i-1,n-1) * beg % mod;
			sum *= th[m+k-i];
			sum %= mod;
			ret += sum;
	//	}
	}
	cout << ret%mod << endl;
}