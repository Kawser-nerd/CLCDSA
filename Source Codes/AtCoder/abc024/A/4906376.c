#include <stdio.h>
int main(void){
	int a,b,c,k,s,t;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);
	int ans = a*s+b*t;
	if(s+t>=k)ans -= c*(s+t);
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d%d%d",&a,&b,&c,&k,&s,&t);
  ^