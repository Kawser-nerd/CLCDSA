#include <stdio.h>

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int X,Y;
int a[110][110];
int xmax[110],ymax[110];

int func(void){
	int i,j;
	
	REP(i,X) xmax[i] = 0;
	REP(i,X) REP(j,Y) if(a[i][j] > xmax[i]) xmax[i] = a[i][j];
	REP(i,Y) ymax[i] = 0;
	REP(i,X) REP(j,Y) if(a[i][j] > ymax[j]) ymax[j] = a[i][j];
	
	REP(i,X) REP(j,Y) if(a[i][j] < xmax[i] && a[i][j] < ymax[j]) return 0;
	return 1;
}

int main(void){
	int T,t,i,j;
	
	scanf("%d", &T);
	REP(t,T){
		scanf("%d%d", &X, &Y);
		REP(i,X) REP(j,Y) scanf("%d", &a[i][j]);
		int ans = func();
		printf("Case #%d: ", t+1);
		if(ans) printf("YES\n"); else printf("NO\n");
	}
	
	return 0;
}
