#include<stdio.h>
int n;
int main(){
	scanf("%d", &n);
	if(n%2){
		printf("%d\n", n+1);
	}else{
		printf("%d\n", n-1);
	}
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^