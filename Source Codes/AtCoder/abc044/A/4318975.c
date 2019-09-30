#include <stdio.h>

int main(void){
	int n,k,x,y,res=0;
	scanf("%d",&n);
	scanf("%d",&k);
	scanf("%d",&x);
	scanf("%d",&y);
	if(n > k){
		res += k*x + (n-k)*y;
	}else{
		res += x*n;
	}
	printf("%d\n",res);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&k);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&x);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&y);
  ^