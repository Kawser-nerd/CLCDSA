#include <stdio.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int A, B, ans1, ans2;
	scanf("%d%d", &A, &B);
	ans1 = max(900 + A % 100 - B, max((A / 100) * 100 + 90 + A % 10 - B, (A / 10) * 10 + 9 - B));
	ans2 = max(A - (100 + B % 100), max(A - ((B / 100) * 100 + B % 10), A - (B / 10) * 10));
	printf("%d\n", max(ans1, ans2));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &A, &B);
  ^