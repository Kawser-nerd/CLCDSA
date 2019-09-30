#include <stdio.h>
int main(void){
	int h,w,hh,ww;
	scanf("%d %d %d %d", &h,&w,&hh,&ww);
	if(h == hh || h == ww || w == hh || w == ww) puts("YES");
	else puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d", &h,&w,&hh,&ww);
  ^