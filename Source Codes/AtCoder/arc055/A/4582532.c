#include<stdio.h>

int main(){
		int i,n;
		scanf("%d",&n);printf("1");
		for(i=1;i<n;i++)printf("0");
		puts("7");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);printf("1");
   ^