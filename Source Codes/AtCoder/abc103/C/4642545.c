#include<stdio.h>

int main(){
	int a,i,N,m=0;
	scanf("%d",&N);

	for(i=0;i<N;i++){
		scanf("%d",&a);
		m+=a;
	}
	printf("%d\n",m-N);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^