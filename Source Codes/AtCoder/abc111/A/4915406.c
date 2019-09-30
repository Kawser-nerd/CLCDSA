#include<stdio.h>
int main(void)
{
	int n;
	scanf("%d",&n);
	if(n==111){
		printf("999\n");
	}
	else if(n==911){
		printf("199\n");
	}
	else if(n==191){
		printf("919\n");
	}
	else if(n==119){
		printf("991\n");
	}
	else if(n==991){
		printf("119\n");
	}
	else if(n==199){
		printf("911\n");
	}
	else if(n==919){
		printf("191\n");
	}
	else if(n==999){
		printf("111\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^