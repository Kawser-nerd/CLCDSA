#include<stdio.h>

int main(){
		int m,n,nl,ans=0,nok=0;
		scanf("%d%d%d",&m,&n,&nl);
		while(nl>0){
				ans+=nl;
				nok+=nl;
				nl=0;
				nl+=nok/m*n;
				nok=nok%m;
		}
		printf("%d\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&m,&n,&nl);
   ^