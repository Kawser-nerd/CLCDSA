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

const int MX = 205, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

int n;
int s[MX*2], si, s2[MX*2], si2, ans[MX], ansi;
bool used[MX], op[MX], opn[MX], ch[MX];
vector<int> c[MX], l[MX];

bool dfs(int v, int t){
	if(v == t) return true;
	if(used[v]) return false;
	used[v] = true;
	int a;
	rep(i,c[v].size()){
		a = c[v][i];
		if(op[a]) continue;
		rep(j,l[a].size()) if(dfs(l[a][j],t)) return true;
	}
	return false;
}

int sch(int t){
	rep(i,MX) used[i] = false;
	int res = -1, v;
	rep(i,c[t].size()){
		v = c[t][i];
		if(op[v]) continue;
		res = v;
		rep(j,l[v].size()) if(dfs(l[v][j],t)) return v;
	}
	return res;
}

bool ok(int x, int cnt){
	rep(i,si) s2[i] = s[i];
	si2 = si;
	rep(i,n) op[i] = opn[i];
	
	rep(ci,cnt){
		while(x == -1 && si2) x = sch(s2[--si2]);
		if(x == -1) return false;
		
		op[x] = true;
		rep(i,l[x].size()) s2[si2++] = l[x][i];
		x = -1;
	}
	return true;
}

int main(){
	int t, k, a, b;
	bool can;
	
	scanf("%d",&t);
	
	rrep(ti,t){
		scanf("%d%d",&k,&n);
		rep(i,MX){ c[i].clear(); l[i].clear(); opn[i] = false;}
		si = 0;
		rep(i,k){ scanf("%d",&a); s[si++] = a;}
		
		rep(i,n){
			scanf("%d%d",&a,&b);
			c[a].pb(i);
			rep(j,b){
				scanf("%d",&a);
				l[i].pb(a);
			}
		}
		
		can = true;
		rep(ai,n){
			rep(i,MX) ch[i] = false;
			ans[ai] = INF;
			rep(i,si){
				if(ch[s[i]]) continue;
				ch[s[i]] = true;
				si--; swap(s[i],s[si]);
				rep(j,c[s[si]].size()){
					a = c[s[si]][j];
					if(!opn[a] && ok(a,n-ai)) mins(ans[ai],a);
				}
				swap(s[i],s[si]); si++;
			}
			a = ans[ai];
			if(a == INF){ can = false; break;}
			opn[a] = true;
			rep(i,si){
				if(!ch[s[i]]) continue;
				ch[s[i]] = false;
				rep(j,c[s[i]].size()) if(c[s[i]][j] == a){
					si--; swap(s[i],s[si]);
					goto br;
				}
			}
		br:
			rep(i,l[a].size()) s[si++] = l[a][i];
		}
		
		printf("Case #%d:",ti);
		if(can){
			rep(i,n) printf(" %d",ans[i]+1);
			puts("");
		} else puts(" IMPOSSIBLE");
	}
	
	return 0;
}





