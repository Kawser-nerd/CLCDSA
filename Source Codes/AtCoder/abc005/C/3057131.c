#include<stdio.h>

int main(){
	int T,N,M,i,a=0,b=0;
	scanf("%d %d",&T,&N);
	int A[N];
	for(i=0;i<N;i++) scanf("%d",&A[i]);
	scanf("%d",&M);
	int B[M];
	for(i=0;i<M;i++) scanf("%d",&B[i]);
	
	for(;;){
		if(A[a]>B[b]){
			puts("no");
			break;
		}
		else if(A[a]+T>=B[b]){
			a++;
			b++;
		}
		else{
			a++;
		}

		if(b==M){
			puts("yes");
			break;
		}
		if(a==N){
			puts("no");
			break;
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&T,&N);
  ^
./Main.c:7:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<N;i++) scanf("%d",&A[i]);
                   ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&M);
  ^
./Main.c:10:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<M;i++) scanf("%d",&B[i]);
                   ^