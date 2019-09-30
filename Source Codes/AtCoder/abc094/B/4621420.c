#include<stdio.h>
int min(int a, int b){return a>b?b:a;}
int n, m, x, a, i;
int now[2];
int main(){
	scanf("%d%d%d", &n, &m, &x);
	for(i=0; i<m; i++){
		scanf("%d", &a);
		now[a<x]++;
	}
	printf("%d\n", min(now[0], now[1]));
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &n, &m, &x);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^