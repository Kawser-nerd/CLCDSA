#include<stdio.h>
int n, d, a, i;
int ans;
int main(){
	scanf("%d%d%d", &n, &d, &ans);
	for(i=0; i<n; i++){
		scanf("%d", &a);
		ans += (d-1)/a+1;
	}
	printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &n, &d, &ans);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^