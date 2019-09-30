#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long
int a,b,c,d,i,j,n,m,k,kolt,l,p,ans;
map<pair<ll,ll>,int> bil;
int f(ll l,ll p,int c)
{
	if (l*c>=p) return 0;
	if (bil.count(mp(l,p))) return bil[mp(l,p)];
	ll a=l;
	int ans=INF;
	rep(h,100)
	{
		a*=c;
		if (a>=p) break;
		ans=min(ans,max(f(a,p,c),f(l,a,c))+1);
	}
	return bil[mp(l,p)]=ans;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&kolt);
	rep(hod,kolt)
	{
		scanf("%d%d%d",&l,&p,&c);
		ll a=l;
		b=0;
		ans=INF;
		bil.clear();
		ans=f(l,p,c);
		printf("Case #%d: %d\n",hod,ans);
	}
}
