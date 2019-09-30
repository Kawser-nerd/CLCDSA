#include <stdio.h>
#include <math.h>

int main(void)
{
	int a,b,c,k,x,sum;
	int max=-1;
	
	scanf("%d%d%d%d",&a,&b,&c,&k);
	
	if(a>b&&a>c){
		max=a;
		sum=b+c;
	}else if(b>c&&b>a){
		max=b;
		sum=c+a;
	}else{
		max=c;
		sum=a+b;
	}
	
	x=pow(2,k);
	
	printf("%d\n",max*x+sum);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&a,&b,&c,&k);
  ^