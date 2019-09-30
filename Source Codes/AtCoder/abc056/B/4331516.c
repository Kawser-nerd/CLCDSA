#include<stdio.h>

int main(){
	int W,a,b;
	scanf("%d%d%d",&W,&a,&b);
	int res;
	if(a>b){
		if(a-b<=W){
			printf("0");
		}
		else if(a-b>W){
			printf("%d",a-b-W);
		}
	}
	else if(a<b){
		if(b-a<=W){
			printf("0");
		}
		else if(b-a>W){
			printf("%d",b-a-W);
		}
	}
	else{
		printf("0");
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&W,&a,&b);
  ^