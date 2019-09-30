#include<stdio.h>

int main(){
		int n,i;
		scanf("%d",&n);
		for(i=2;i*i<=n;i++){
				if(n%i==0){
						puts("NO");
						return 0;
				}
		}
		if(n==1)puts("NO");
		else puts("YES");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^