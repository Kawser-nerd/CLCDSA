#include<stdio.h>

int main(){
	int N,n,i;
	scanf("%d",&N);
	n=2025-N;
	for(i=1;i<=9;i++){
		if(n%i==0&&1<=n/i&&n/i<=9){
			printf("%d x %d\n",i,n/i);
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^