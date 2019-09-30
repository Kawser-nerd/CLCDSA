#include <stdio.h>
int main(){
	char a[5];
	int b;
	scanf("%s",&a);
	scanf("%d",&b);
	printf("%c%c\n",a[(b-1)/5],a[(b-1)%5]);
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[5]’ [-Wformat=]
  scanf("%s",&a);
        ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&a);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&b);
  ^