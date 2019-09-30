#include<stdio.h>

int main(){
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		if(n>=5)printf("%d\n",b*5+a*(n-5));
		else printf("%d\n",b*n);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&a,&b);
   ^