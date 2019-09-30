#include <stdio.h>

char s[111][111];
int r,c;

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int follow(int x,int y) {
	int d;
	if(s[x][y]=='^') d=3;
	else if(s[x][y]=='v') d=1;
	else if(s[x][y]=='<') d=2;
	else if(s[x][y]=='>') d=0;
	else printf("error"),d=-1;
	while(1) {
		x+=dx[d]; y+=dy[d];
		if(x<0 || y<0 || x>=r || y>=c) return 1;
		if(s[x][y]!='.') return 0;
	}
}

int solve2() {
	int i,j,cnt=0;
	for(i=0;i<r;i++) for(j=0;j<c;j++) if(s[i][j]!='.' && follow(i,j)) cnt++;
	return cnt;
}

int impossible() {
	int i,j,cnt;
	char z;
	for(i=0;i<r;i++) for(j=0;j<c;j++) if(s[i][j]!='.') {
		z=s[i][j];
		cnt=0;
		s[i][j]='^'; cnt+=follow(i,j);
		s[i][j]='v'; cnt+=follow(i,j);
		s[i][j]='<'; cnt+=follow(i,j);
		s[i][j]='>'; cnt+=follow(i,j);
		s[i][j]=z;
		if(cnt==4) return 1;
	}
	return 0;
}

void solve() {
	int i;
	scanf("%d %d",&r,&c);
	for(i=0;i<r;i++) scanf("%s",s[i]);
	if(impossible()) puts("IMPOSSIBLE");
	else printf("%d\n",solve2());
}

int main() {
	int T,caseno=1;
	scanf("%d",&T);
	while(T--) printf("Case #%d: ",caseno++),solve();
	return 0;
}
