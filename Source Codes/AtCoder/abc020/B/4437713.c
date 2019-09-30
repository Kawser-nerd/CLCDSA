#include <stdio.h>
int main(void){
	char a[8],b[4];
	scanf("%s%s",a,b);
	strcat(a,b);
	printf("%ld\n",2*(atol(a)));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: implicit declaration of function ‘strcat’ [-Wimplicit-function-declaration]
  strcat(a,b);
  ^
./Main.c:5:2: warning: incompatible implicit declaration of built-in function ‘strcat’
./Main.c:5:2: note: include ‘<string.h>’ or provide a declaration of ‘strcat’
./Main.c:6:20: warning: implicit declaration of function ‘atol’ [-Wimplicit-function-declaration]
  printf("%ld\n",2*(atol(a)));
                    ^
./Main.c:6:9: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘int’ [-Wformat=]
  printf("%ld\n",2*(atol(a)));
         ^
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",a,b);
  ^