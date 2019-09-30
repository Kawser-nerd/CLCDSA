#include<stdio.h>
int main(void)
{
	int n,a,b;
	scanf("%d",&n);
	if(n==1){
		printf("Hello World\n");
	}
	else{
		scanf("%d %d",&a,&b);
		printf("%d\n",a+b);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^