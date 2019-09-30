#include<stdio.h>

int main(void){
	int n,k,i,a;
	int ans = 0;
	int buf = 0;
	scanf("%d %d", &n, &k);
	
	for(i = 0; i < n; i++){
		scanf("%d", &a);
	}
	ans = (n + k - 3) / (k - 1);
	
	printf("%d\n", ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &k);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^