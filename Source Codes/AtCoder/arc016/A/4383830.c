#include<stdio.h>

int main(){
		int n,m;
		scanf("%d%d",&n,&m);
		printf("%d\n",((m-1)>=1?(m-1):2));
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^