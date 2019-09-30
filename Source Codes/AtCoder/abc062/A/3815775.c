#include<stdio.h>
char G[13]={0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};
short X, Y;
int main(){
	scanf("%hd%hd", &X, &Y);
	if(G[X]==G[Y]){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%hd%hd", &X, &Y);
  ^