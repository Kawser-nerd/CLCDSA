#include<stdio.h>
int main(){	
	int a,b;	
	char s;	
	scanf("%d\n",&a);	
	scanf("%c",&s);	
	scanf("%d",&b);	
	if(s=='+')	  
	printf("%d\n",a+b);	
	else	  
	printf("%d\n",a-b);	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n",&a); 
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&s); 
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&b); 
  ^