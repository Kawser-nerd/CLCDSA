#include <stdio.h>

int main(void){
	int n,d,x,a[100];
	scanf("%d",&n);
	scanf("%d %d",&d,&x);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		x += d / a[i];
		if(d % a[i] != 0)x++;
	}
	printf("%d\n",x);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&d,&x);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^