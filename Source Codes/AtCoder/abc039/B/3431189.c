#include <stdio.h>

int main(void){
	int X,a;
	scanf("%d",&X);
	a = sqrt(X);
	a = sqrt(a);
	printf("%d",a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:6: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
  a = sqrt(X);
      ^
./Main.c:6:6: warning: incompatible implicit declaration of built-in function ‘sqrt’
./Main.c:6:6: note: include ‘<math.h>’ or provide a declaration of ‘sqrt’
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&X);
  ^