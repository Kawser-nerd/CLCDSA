#include<stdio.h>
#include<math.h>
#include<string.h> 
int main() {
	int a,b,w;
	scanf("%d %d %d",&w,&a,&b);
	if(a>b){
		int temp=a;
		a=b;
		b=temp;
	}
	if(a+w<b){
		printf("%d",b-w-a);
	}else{
		printf("0");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&w,&a,&b);
  ^