#include <stdio.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,n)  FOR(i,0,n)
int main(){
	int N, C, s, t, c;
	short using[30][100001] = {};
	scanf("%d%d", &N,&C);
	REP(i,30) REP(j,100001) using[i][j] = 0;
	REP(i,N) {
		scanf("%d%d%d",&s,&t,&c);
		FOR(j,s-1,t) using[c-1][j] = 1;
	}

	int dup, max = 0;
	FOR(i,0,100001) {
		dup = 0;
		FOR(j,0,C) if(using[j][i]) dup++;
		if(max < dup) max = dup;
	}
	printf("%d",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N,&C);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&s,&t,&c);
   ^