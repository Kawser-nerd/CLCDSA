#include<stdio.h>
int N, M, i;
int main(){
	scanf("%d%d", &N, &M);
	if((N<<1)<=M && M<=(N<<2)){
		if(M<N*3){
			printf("%d %d 0\n", N*3-M, M-(N<<1));
		}else if(M>N*3){
			printf("0 %d %d\n", (N<<2)-M, M-N*3);
		}else{
			printf("0 %d 0\n", N);
		}
	}else{
		printf("-1 -1 -1\n");
	}
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^