#include <stdio.h>

int main(){
	int n;
  	scanf("%d",&n);

  	printf("%s\n",n%2==0?"Blue":"Red");
  	return 0;  
} ./Main.c: In function ‘main’:
./Main.c:5:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&n);
    ^