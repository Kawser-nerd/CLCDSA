#include<stdio.h>
int N, n, a, sum, i;
int main(){
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", &a);
		if(a!=0){
			sum += a;
			n++;
		}
	}
	printf("%d\n", (sum+n-1)/n);
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^