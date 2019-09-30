#include<stdio.h>

int main(){
		int n,i,ans=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
				int ab[2];
				scanf("%d%d",&ab[0],&ab[1]);
				ans+=ab[0]*ab[1];
		}
		printf("%d\n",ans+ans/20);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&ab[0],&ab[1]);
     ^