#include<stdio.h>
int T, N, M, A[100], B, a, i;
short f;
int main(){
	scanf("%d", &T);
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", A+i);
	}
	scanf("%d", &M);
	if(N<M){
		printf("no\n");
		return 0;
	}
	f=1;
	for(i=0; i<M; i++){
		scanf("%d", &B);
		while(a<N && A[a]+T<B){a++;}
		if(a>=N || A[a]>B){f=0; break;}
		a++;
	}
	if(f){
		printf("yes\n");
	}else{
		printf("no\n");
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &T);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", A+i);
   ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &M);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &B);
   ^