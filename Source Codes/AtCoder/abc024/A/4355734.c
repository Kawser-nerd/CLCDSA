#include <stdio.h>

int main(void)
{
	int a,b,c,k,s,t;
	scanf("%d %d %d %d\n%d %d",&a,&b,&c,&k,&s,&t);
	
	if(s+t<k){
		printf("%d\n",a*s+b*t);
	}else{
		printf("%d\n",a*s+b*t-c*(s+t));
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d\n%d %d",&a,&b,&c,&k,&s,&t);
  ^