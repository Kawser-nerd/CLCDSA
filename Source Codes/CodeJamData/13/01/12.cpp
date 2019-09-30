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

char f[4][4];

int main(){
	int t;
	bool e, o, x;
	char c;
	scanf("%d",&t);
	
	rrep(ti,t){
		e = false;
		rep(i,4){
			rep(j,4){
				scanf(" %c",&c);
				if(c == '.') e = true;
				f[i][j] = c;
			}
		}
		
		rep(i,4){
			o = x = true;
			rep(j,4){
				if(f[i][j] == '.') o = x = false;
				if(f[i][j] == 'O') x = false;
				if(f[i][j] == 'X') o = false;
			}
			if(o || x) goto end;
		}
		rep(j,4){
			o = x = true;
			rep(i,4){
				if(f[i][j] == '.') o = x = false;
				if(f[i][j] == 'O') x = false;
				if(f[i][j] == 'X') o = false;
			}
			if(o || x) goto end;
		}
		
		o = x = true;
		rep(i,4){
			if(f[i][i] == '.') o = x = false;
			if(f[i][i] == 'O') x = false;
			if(f[i][i] == 'X') o = false;
		}
		if(o || x) goto end;
		o = x = true;
		rep(i,4){
			if(f[i][3-i] == '.') o = x = false;
			if(f[i][3-i] == 'O') x = false;
			if(f[i][3-i] == 'X') o = false;
		}
		if(o || x) goto end;
		
	end:
		printf("Case #%d: ",ti);
		if(o) puts("O won");
		else if(x) puts("X won");
		else if(e) puts("Game has not completed");
		else puts("Draw");
	}
	
	return 0;
}





