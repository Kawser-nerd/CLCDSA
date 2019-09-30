#include <stdio.h>

int main(void){
	int H,W;
	int h,w;
	scanf("%d%d",&H,&W);
	scanf("%d%d",&h,&w);
	printf("%d",(H-h)*(W-w));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&H,&W);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^