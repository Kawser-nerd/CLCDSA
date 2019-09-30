#include<stdio.h>


unsigned long  check(unsigned long A){
	if(A%4==0) return A;
	else if(A%4==1) return 1;
	else if(A%4==2) return A^1;
	else if(A%4==3) return 0;
	return 0;
}

int main(){
	unsigned long A,B;
	scanf("%lu %lu",&A, &B);
	if(A < 1){
		printf("%lu\n",check(B));
		return 0;
	}
	printf("%lu\n",check(A-1)^check(B));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lu %lu",&A, &B);
  ^