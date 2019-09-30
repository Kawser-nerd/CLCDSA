#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int f[105][105], g[105][105];

int main(){
	int t, n, m; bool bl;
	scanf("%d",&t);
	
	rrep(ti,t){
		scanf("%d%d",&n,&m);
		rep(i,n)rep(j,m) f[i][j] = 100;
		rep(i,n)rep(j,m) scanf("%d",&g[i][j]);
		
		for(int h = 99; h >= 1; h--){
			rep(i,n){
				bl = true;
				rep(j,m) if(g[i][j] > h) bl = false;
				if(bl) rep(j,m) f[i][j] = h;
			}
			rep(j,m){
				bl = true;
				rep(i,n) if(g[i][j] > h) bl = false;
				if(bl) rep(i,n) f[i][j] = h;
			}
		}
		
		bl = true;
		rep(i,n)rep(j,m) if(f[i][j] != g[i][j]) bl = false;
		
		printf("Case #%d: ",ti);
		puts(bl?"YES":"NO");
	}
	
	return 0;
}





