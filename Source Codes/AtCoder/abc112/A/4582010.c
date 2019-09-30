#include <stdio.h>
int main(){
int n;
	scanf("%d",&n);
	if(n==1) puts("Hello World");
	else if(n==2){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d",a+b);}
		
		return 0;
		} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^