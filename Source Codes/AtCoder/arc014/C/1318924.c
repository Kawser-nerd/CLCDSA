#include<stdio.h>
int main(){
	int r=0,g=0,b=0,n;
	char c;
	scanf("%d",&n);
	while(n--){
		scanf(" %c",&c);
		c-'B'?c-'G'?r++:g++:b++;
	}
	printf("%d\n",r%2+g%2+b%2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf(" %c",&c);
   ^