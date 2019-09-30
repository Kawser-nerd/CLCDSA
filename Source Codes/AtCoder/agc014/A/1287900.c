#include "stdio.h"

int main(){
	
	int a,b,c,a1,b1,c1;
	
	scanf("%d %d %d",&a,&b,&c);
	
	int count=0;
	
	while(1){
		if((a%2==1)||(b%2==1)||(c%2==1)){
			break;
		}
		
		if((a==b)&&(a==c)){
			count=-1;
			break;
		}
		
		a1=a,b1=b,c1=c;//can i group together for one row?//ok
		
		a=(b1+c1)/2;
		b=(c1+a1)/2;
		c=(a1+b1)/2;//can i group together with the above//ok
		
		count++;
	}
	
	printf("%d\n",count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^