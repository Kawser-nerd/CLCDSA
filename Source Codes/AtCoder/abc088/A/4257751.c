#include <stdio.h>
 
int main(void)
{	int n,a;
	 scanf("%d%d",&n,&a);
 	if(n%500 <= a){printf("Yes");}
 	else{printf("No");}
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&a);
   ^