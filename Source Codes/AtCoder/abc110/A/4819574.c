#include<stdio.h>
int main(void){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a<b){
		if(b<c){
			printf("%d",(10*c)+a+b);
		}else{
			printf("%d",(10*b)+a+c);
		}
	}else{
		if(a<c){
			printf("%d",(10*c)+a+b);
		}else{
			printf("%d",(10*a)+b+c);
		}
	}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^