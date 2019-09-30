#include<stdio.h>

int main(){
	int f=0,n;
	scanf("%d",&n);
	if(n%4==0)f=1;
	if(n%100==0)f=0;
	if(n%400==0)f=1;
	if(f==1)puts("YES");
	else puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^