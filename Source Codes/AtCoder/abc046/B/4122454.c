#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	int res;
	res=K*pow((K-1),(N-1));
	printf("%d",res);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&K);
  ^