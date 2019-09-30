#include <stdio.h>

char g[6][6];

int check(int x,int y,int dx,int dy,char c) {
	int i,n;
	for(n=i=0;i<4;i++) {
		if(g[x][y]==c || g[x][y]=='T') n++;
		x+=dx; y+=dy;
	}
	return n==4;
}

int won(char c) {
	int i;
	for(i=0;i<4;i++) {
		if(check(0,i,1,0,c)) return 1;
		if(check(i,0,0,1,c)) return 1;
	}
	if(check(0,0,1,1,c)) return 1;
	if(check(0,3,1,-1,c)) return 1;
	return 0;
}

int main() {
	int T,i,j,z,no=1;
	scanf("%d",&T);
	while(T--) {
		for(i=0;i<4;i++) scanf("%s",g[i]);
		printf("Case #%d: ",no++);
		if(won('O')) puts("O won");
		else if(won('X')) puts("X won");
		else {
			for(i=z=0;i<4;i++) for(j=0;j<4;j++) if(g[i][j]=='.') z=1;
			if(z) puts("Game has not completed");
			else puts("Draw");
		}
	}
	return 0;
}
