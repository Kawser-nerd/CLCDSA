#include <stdio.h>

int ABS(int a){
	if(a >= 0){
		return a;
	}
	else{
		return -a;
	}
}

int main(){
	int A, B;
	scanf("%d%d", &A, &B);
	if(ABS(A) < ABS(B)){
		printf("Ant\n");
	}
	else if(ABS(A) == ABS(B)){
		printf("Draw\n");
	}
	else{
		printf("Bug\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &A, &B);
  ^