#include<stdio.h>

int main()
{
	int a,b,c;
	scanf("%d %d",&a,&b);
	if(b>=1 && b<=9) c = 10*a + b;
	else if(b>=10 && b<=99) c = 100*a + b;
	else if(b=100) c = 1000*a + 100;
	int i;
	for(i=1;i<=1100;i++){
		if(c == i*i){
			printf("Yes");
			goto YES;
		};
	};
	printf("No");
	YES:;
	
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^