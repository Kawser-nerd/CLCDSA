#include<stdio.h>
int A, B, C;
int main(){
	scanf("%d%d%d", &A, &B, &C);
	if(A+B==C){
		if(A-B==C){
			printf("?\n");
		}else{
			printf("+\n");
		}
	}else{
		if(A-B==C){
			printf("-\n");
		}else{
			printf("!\n");
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &A, &B, &C);
  ^