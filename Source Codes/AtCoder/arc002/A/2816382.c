#include<stdio.h>

int main(){
	int y;
	scanf("%d",&y);
	if(y%400==0||y%100!=0&&y%4==0)puts("YES");
	else puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&y);
  ^