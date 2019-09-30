#include<stdio.h>

int main(void){
	unsigned long long int n,a,b,x1,x2,r=0,i;
	scanf("%llu%llu%llu",&n,&a,&b);
	scanf("%llu",&x1);
	for(i = 1;i < n;i++){
		scanf("%llu",&x2);
		if(b < (x2-x1)*a){r+=b;}
		else{r+=((x2-x1)*a);}
		x1 = x2;
	}
	printf("%llu\n",r);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu%llu%llu",&n,&a,&b);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu",&x1);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu",&x2);
   ^