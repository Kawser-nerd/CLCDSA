#include<stdio.h>

int main(){
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		if(n%(a+b)<=a&&n%(a+b)>0)puts("Ant");
		else puts("Bug");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&a,&b);
   ^