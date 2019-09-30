#include <stdio.h>
int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}
int main(){
	int A, B, C, D, E;
	scanf("%d%d%d%d%d", &A, &B, &C, &D, &E);
	printf("%d\n", max(A + D + E, B + C + E));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d", &A, &B, &C, &D, &E);
  ^