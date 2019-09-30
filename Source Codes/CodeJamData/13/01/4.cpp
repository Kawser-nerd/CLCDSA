#include <stdio.h>
char dat[4][10];

int o[10], x[10];
void count(char c,int p){
	if (c == 'T' || c == 'O') o[p] ++;
	if (c == 'T' || c == 'X') x[p] ++;
}
int main() {
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);

	int T;
	scanf("%d",&T);
	while(T-->0) {
		for (int i=0;i<10;i++) o[i]=x[i] = 0;
		for (int i=0;i<4;i++) scanf("%s",dat[i]);
		bool complete = true;
		for (int i=0;i<4;i++) {
			count(dat[i][i], 8);
			count(dat[i][3-i], 9);
			for (int j=0;j<4;j++) {
				count(dat[i][j], i);
				count(dat[i][j], 4+j);
				if (dat[i][j] == '.')complete = false;
			}
		}

		bool owin, xwin;
		owin = xwin = false;
		for (int i=0;i<10;i++) {
			if (o[i] == 4) owin = true;
			if (x[i] == 4) xwin = true;
		}

		static int cs = 1;
		printf("Case #%d: ", cs ++);

		if (owin) printf("O won");
		else if(xwin) printf("X won");
		else if(complete) printf("Draw");
		else printf("Game has not completed");
		
		printf("\n");
	}
	return 0;
}