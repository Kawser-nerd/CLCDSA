#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

int N,K;
char s[1010];
int a[1010];

void main2(void){
	int i,j,ans=0;
	
	scanf("%s", s);
	scanf("%d", &K);
	
	N = strlen(s);
	REP(i,N) a[i] = ((s[i] == '-') ? 1 : 0);
	
	REP(i,N-K+1) if(a[i] == 1){
		ans++;
		REP(j,K) a[i+j] ^= 1;
	}
	
	REP(i,N) if(a[i] == 1){
		printf("IMPOSSIBLE\n");
		return;
	}
	
	printf("%d\n", ans);
}

int main(void){
	int TC,tc;
	scanf("%d", &TC);
	REP(tc,TC){
		printf("Case #%d: ", tc + 1);
		main2();
	}
	return 0;
}
