#include<stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))

int main(){
		int p,q,r,a,b,c,ans=0;
		scanf("%d%d%d%d%d%d",&p,&q,&r,&a,&b,&c);
		ans=max(ans,(p/a)*(q/b)*(r/c));
		ans=max(ans,(p/a)*(q/c)*(r/b));
		ans=max(ans,(p/b)*(q/a)*(r/c));
		ans=max(ans,(p/b)*(q/c)*(r/a));
		ans=max(ans,(p/c)*(q/a)*(r/b));
		ans=max(ans,(p/c)*(q/b)*(r/a));
		printf("%d\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d%d",&p,&q,&r,&a,&b,&c);
   ^