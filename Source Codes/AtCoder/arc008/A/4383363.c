#include<stdio.h>

int main(){
		int n;
		scanf("%d",&n);
		if(n%10<=6)printf("%d\n",n/10*100+(n%10)*15);
		else if(n%10!=0)printf("%d\n",(n/10+1)*100);
		else printf("%d\n",n*10);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^