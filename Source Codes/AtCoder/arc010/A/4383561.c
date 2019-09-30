#include<stdio.h>

int main(){
		int n,m,a,b,i,c[100];
		scanf("%d%d%d%d",&n,&m,&a,&b);
		for(i=0;i<m;i++)scanf("%d",&c[i]);
		for(i=0;i<m;i++){
				if(n<=a)n+=b;
				n-=c[i];
				if(n<0){
						printf("%d\n",i+1);
						return 0;
				}
		}
		puts("complete");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&n,&m,&a,&b);
   ^
./Main.c:6:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<m;i++)scanf("%d",&c[i]);
                   ^