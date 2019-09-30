#include <stdio.h>
#include <stdlib.h>

int c[1100], p[1100];

int main(){
	int t; scanf("%d", &t);
	for(int i=1; i<=t; ++i) {
		memset(c,0,sizeof(c));
		memset(p,0,sizeof(p));
		int n,s,m; scanf("%d%d%d", &n,&s,&m);
		for(int j=1; j<=m; ++j) {
			int x,y; scanf("%d%d",&x,&y);
			++c[x],++p[y];
		}
		int ans=0,sc=0;
		for(int j=1; j<=n; ++j) {
			sc += c[j];
			if ( (sc+j-1)/j > ans) ans = (sc+j-1)/j;
		}
		for(int j=1; j<=m; ++j) {
			if (p[j] > ans) ans = p[j];
		}
		int tot=0;
		for(int j=1; j<=n; ++j){
			if (c[j] > ans) tot+=c[j]-ans;
		}
		printf("Case #%d: %d %d\n", i,ans,tot);
	}
}
