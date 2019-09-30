#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1010;

int g[maxn][20], dep[maxn], fnd[maxn];
int task, cs=0, n;
bool fnsh;

void dfs(int x){
	if ( fnsh ) return;
	for (int i=1; i<=g[x][0]; i++){
		int y = g[x][i];
		if ( fnd[y] ){
			fnsh = true;
			return;
		}
		fnd[y] = true;
		dfs( y );
	}
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("a.out","w",stdout);

	for(scanf("%d", &task); task--;){
		scanf("%d", &n);
		memset(g, 0, sizeof(g));
		memset(dep, 0, sizeof(dep));
		for (int i=1; i<=n; i++){
			int m, x;
			for (scanf("%d", &m); m--;){
				scanf("%d", &x);
				g[i][++g[i][0]] = x;
				dep[x]++;
			}
		}
		fnsh = false;
		for (int i=1; i<=n; i++)
		{
			memset(fnd,0,sizeof(fnd));
			dfs( i );
			if (fnsh) break;
		}
		if ( fnsh )
			printf("Case #%d: Yes\n", ++cs);
		else 
			printf("Case #%d: No\n", ++cs);
	}
	return 0;
}
