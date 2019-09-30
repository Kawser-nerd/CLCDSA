#include<stdio.h>
int main() {
	int N,K;
	scanf("%d %d",&N,&K);
	int a=1,i;
	for(i=0; i<N; i++) {
		if(i==0) {
			a=K;
		} else {
			a=a*(K-1);
		}
	}
	printf("%d\n",a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&K);
  ^