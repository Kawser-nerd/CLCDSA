#include <stdio.h>
#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define RREP(i,a,b) for(int i=(a);i>=(b);i++)
int h,w,a,li[15][15],s=0;

int min(int a, int b){
	if(a>b) return b;
	else return a;
}

int main(void){
	scanf("%d %d",&h,&w);
	REP(i,0,10) REP(j,0,10) scanf("%d", &li[i][j]);
	REP(k,0,10) REP(i,0,10) REP(j,0,10) li[i][j]=min(li[i][j], li[i][k]+li[k][j]);
	REP(i,0,h) REP(j,0,w){
		scanf("%d",&a);
		if(a==-1) continue;
		else s+=li[a][1];
	}
	
	printf("%d\n",s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&h,&w);
  ^
./Main.c:13:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  REP(i,0,10) REP(j,0,10) scanf("%d", &li[i][j]);
                          ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^