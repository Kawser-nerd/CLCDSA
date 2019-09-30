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
int a,b,c,d,i,j,n,m,k,kolt,ans;
vector<pii> seen;
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&kolt);
	rep(hod,kolt)
	{
		printf("Case #%d: ",hod);
		scanf("%d",&n);
		seen.clear();
		rept(i,n)
		{
			scanf("%d%d",&a,&b);
			seen.pb(mp(a,b));
		}
		SORT(seen);
		ans=0;
		rept(i,L(seen))
		{
			rept(j,i)
			{
				if (seen[j].y>seen[i].y) ++ans;
			}
		}
		printf("%d\n",ans);
	}
}
