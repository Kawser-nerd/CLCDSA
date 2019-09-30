#include<stdio.h>
int N, A, B, D, now, i;
char S;
int main(){
	scanf("%d %d %d\n", &N, &A, &B);
	for(i=0; i<N; i++){
		S=getchar(); getchar(); getchar(); getchar();
		scanf("%d\n", &D);
		if(D<A){D=A;}
		else if(D>B){D=B;}
		now += S=='E'?D:-D;
	}
	if(now==0){
		printf("0\n");
	}else if(now > 0){
		printf("East %d\n", now);
	}else{
		printf("West %d\n", -now);
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d\n", &N, &A, &B);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d\n", &D);
   ^