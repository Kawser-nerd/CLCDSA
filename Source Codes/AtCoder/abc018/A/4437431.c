#include <stdio.h>
int main(void){
	int A,B,C,a=1,b=1,c=1;
	scanf("%d%d%d",&A,&B,&C);
	if(A>B) b++;
	else a++;
	if(B>C) c++;
	else b++;
	if(C>A) a++;
	else c++;
	printf("%d\n%d\n%d\n",a,b,c);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&A,&B,&C);
  ^