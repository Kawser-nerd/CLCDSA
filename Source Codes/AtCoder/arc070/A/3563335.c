#include<stdio.h>

int sankaku(int x){return (x*(x+1))/2;}

int main(void){
	int i,x;
	scanf("%d",&x);
	for(i = 1;i <= 100000;i++){
		if(x <= sankaku(i)){printf("%d\n",i);return 0;}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&x);
  ^