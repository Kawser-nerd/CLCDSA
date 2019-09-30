#include<stdio.h>
int main() {
	int i,j,h,w;
	char a[101];
	scanf("%d%d",&h,&w);
	for(i=0; i<h; i++) {
		scanf("%s",a);
		for(j=0; j<2; j++) {
			printf("%s\n",a);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a);
   ^