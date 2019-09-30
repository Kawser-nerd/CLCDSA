#include<stdio.h>
int a, b, i;
char x[5];
int ans;
int main(){
	scanf("%d%d", &a, &b);
	for(i=a; i<=b; i++){
		if((i%10)==(i/10000%10) && (i/10%10)==(i/1000%10)){
			ans++;
		}
	}
	printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &a, &b);
  ^