#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

#define   M             100005
#define   ll            long long
#define   PI            atan(1.0)*4
#define   mst(x,v)      memset(x,v,sizeof(x))
#define   inf           1e9
#define   rush()        int T;scanf("%d",&T);while(T--)
#define   debug         puts("debug")

typedef   pair<int,int> P;


int main() {
/*
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
*/
	ll n,m,ans;
	scanf("%lld %lld",&n,&m);
	ans = abs((n-2)*(m-2));
	printf("%lld\n",ans);
}