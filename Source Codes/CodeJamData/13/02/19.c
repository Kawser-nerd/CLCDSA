#include <stdio.h>
#include <string.h>

int g[111][111];
int try[111][111];
int x,y;

int can() {
	int i,j,maks,ch;
	for(i=0;i<x;i++) for(j=0;j<y;j++) try[i][j]=100;
	do {
		ch=0;
		for(i=0;i<x;i++) {
			maks=0;
			for(j=0;j<y;j++) if(maks<g[i][j]) maks=g[i][j];
			for(j=0;j<y;j++) if(try[i][j]>maks) try[i][j]=maks,ch=1;
		}
		for(j=0;j<y;j++) {
			maks=0;
			for(i=0;i<x;i++) if(maks<g[i][j]) maks=g[i][j];
			for(i=0;i<x;i++) if(try[i][j]>maks) try[i][j]=maks,ch=1;
		}
	} while(ch);
	for(i=0;i<x;i++) for(j=0;j<y;j++) if(try[i][j]!=g[i][j]) return 0;
	return 1;
}

int main() {
	int T,no=1,i,j;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&x,&y);
		for(i=0;i<x;i++) for(j=0;j<y;j++) scanf("%d",&g[i][j]);
		printf("Case #%d: %s\n",no++,can()?"YES":"NO");
	}
	return 0;
}
