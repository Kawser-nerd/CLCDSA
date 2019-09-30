#include<stdio.h>
#include<string.h>

char str[128][128];
int n,m;

int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char ddir[]=">v<^";

int valid(int x,int y) {
	return x>=0 && y>=0 && x<n && y<m;
}

int main() {
	int N,cs=0,i,j,f,d,k,l,ret;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++) scanf("%s",str[i]);
		f=1;
		ret=0;
		for(i=0;i<n && f;i++) for(j=0;j<m && f;j++) if (str[i][j]!='.') {
			for(l=0;l<4;l++) if (ddir[l]==str[i][j]) break;
			d=l;
			for(k=1;valid(i+dir[d][0]*k,j+dir[d][1]*k);k++)
				if (str[i+dir[d][0]*k][j+dir[d][1]*k]!='.') break;
			if (valid(i+dir[d][0]*k,j+dir[d][1]*k)) continue;
			ret++;
			for(l=0;l<4;l++) {
				for(k=1;valid(i+dir[l][0]*k,j+dir[l][1]*k);k++)
					if (str[i+dir[l][0]*k][j+dir[l][1]*k]!='.') break;
				if (valid(i+dir[l][0]*k,j+dir[l][1]*k)) break;
			}
			if (l>=4) f=0;
		}
		if (f) printf("Case #%d: %d\n",++cs,ret);
		else printf("Case #%d: IMPOSSIBLE\n",++cs);
	}
	return 0;
}
