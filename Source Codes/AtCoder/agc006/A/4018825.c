#include<stdio.h>

int main(){
		int n,i,ans,k=0;
		char s[101],t[101];
		scanf("%d",&n);
		ans=n*2;
		scanf("%s",s);
		scanf("%s",t);
		for(i=0;i<n;i++){
				int j;
				for(j=n-i-1;j<n;j++){
						if(s[j]!=t[j-n+i+1])break;
				}
				if(j==n)k=i+1;
		}
		printf("%d\n",ans-k);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",t);
   ^