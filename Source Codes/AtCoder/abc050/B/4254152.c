#include<stdio.h>
int main() {
	int N,t[100005],M,p,x,i,j;
	scanf("%d",&N);
	for(i=1; i<=N; i++) {
		scanf("%d",&t[i]);
	}
	scanf("%d",&M);
	for(i=0; i<M; i++) {
		int sum=0;
		scanf("%d %d",&p,&x);
		for(j=1; j<=N; j++) {
			if(j==p) {
				sum+=x;
				continue;
			}
			sum+=t[j];
		}
		printf("%d\n",sum);

	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t[i]);
   ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&M);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&p,&x);
   ^