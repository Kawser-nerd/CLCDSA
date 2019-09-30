#include<stdio.h>
#include<math.h>
#include<string.h> 
int main() {
	int a,A,b=0;
	scanf("%d",&a);
	b=a/15;
	A=a*800-b*200;
	printf("%d",A);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^