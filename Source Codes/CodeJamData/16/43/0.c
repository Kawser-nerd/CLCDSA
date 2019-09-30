#include <stdio.h>

char g[111][111];
int par[99999],x,y,p,o;

void getxy(int p,int *x2,int *y2,int *dx,int *dy) {
	if(p<x) { *x2=p,*y2=0,*dx=0,*dy=1; return; }
	p-=x;
	if(p<y) { *x2=x-1,*y2=p,*dx=-1,*dy=0; return; }
	p-=y;
	if(p<x) { *x2=x-p-1,*y2=y-1,*dx=0,*dy=-1; return; }
	p-=x;
	*x2=0; *y2=y-p-1; *dx=1; *dy=0;
}

int check() {
	int i,x2,y2,dx,dy,out;
	for(i=0;i<o;i+=2) {
		getxy(par[i],&x2,&y2,&dx,&dy);
		do {
			if     (dx && g[y2][x2]=='/') dy=-dx,dx=0;
			else if(dx && g[y2][x2]=='\\') dy=dx,dx=0;
			else if(dy && g[y2][x2]=='/') dx=-dy,dy=0;
			else if(dy && g[y2][x2]=='\\') dx=dy,dy=0;
			x2+=dx; y2+=dy;
		} while(x2>=0 && y2>=0 && x2<x && y2<y);
		if(y2<0) out=x2;
		else if(x2==x) out=y2+x;
		else if(y2==y) out=x+y+x-x2-1;
		else out=x+y+x+y-y2-1;
		if(out!=par[i+1]) return 0;
	}
	return 1;
}

void solve() {
	int i,j,mask;
	scanf("%d %d",&y,&x);
	p=x*y;
	o=x+x+y+y;
	for(i=0;i<o;i++) scanf("%d",&par[i]),par[i]--;
	for(mask=0;mask<(1<<p);mask++) {
		for(i=0;i<p;i++) if(mask&(1<<i)) g[i%y][i/y]='/';
		else g[i%y][i/y]='\\';
		if(check()) {
			for(i=0;i<y;i++) {
				for(j=0;j<x;j++) putchar(g[i][j]);
				putchar('\n');
			}
			return;
		}
	}
	puts("IMPOSSIBLE");
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d:\n",caseno++),solve();
	return 0;
}
