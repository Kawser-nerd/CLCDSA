#include<stdio.h>
int A, B;
int min(int a, int b){return a>b?b:a;}
int main(){
	scanf("%d%d", &A, &B);
	printf("%d\n", min((10+A-B)%10, (10+B-A)%10));
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &A, &B);
  ^