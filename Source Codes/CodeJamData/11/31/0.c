#include<stdio.h>

char a[64][64];
int n,m;

int main() {
	int i,j,N,cs=0;
	for(scanf("%d",&N);N--;) {
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++) scanf("%s",a[i]);
		printf("Case #%d:\n",++cs);
		for(i=0;i<n;i++) {
			for(j=0;j<m;j++) if (a[i][j]=='#') {
				if (j==m-1 || a[i][j+1]!='#') break;
				if (i==n-1) break;
				if (a[i+1][j]!='#' || a[i+1][j+1]!='#') break;
				a[i][j]=a[i+1][j+1]='/';
				a[i][j+1]=a[i+1][j]='\\';
			}
			if (j<m) break;
		}
		if (i<n) puts("Impossible"); else for(i=0;i<n;i++) puts(a[i]);
	}
	return 0;
}
