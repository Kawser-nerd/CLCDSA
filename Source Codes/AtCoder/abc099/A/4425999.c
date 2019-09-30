#include <stdio.h>
int main(Void){
	int n;
	scanf("%d",&n);
	if(n<=999) printf("ABC\n");
	else printf("ABD\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:2:5: warning: type of ‘Void’ defaults to ‘int’ [-Wimplicit-int]
 int main(Void){
     ^
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^