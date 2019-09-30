#include<stdio.h>

int main(){
	long x,y,k;
	scanf("%ld%ld%ld",&x,&y,&k);
	if(y>=k)printf("%ld\n",x+k);
	else printf("%ld\n",y+x-(k-y));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld%ld%ld",&x,&y,&k);
  ^