#include<stdio.h>

int main(){
		int n,q,l,r,t,i,a[100]={0},j;
		scanf("%d%d",&n,&q);
		for(i=0;i<q;i++){
				scanf("%d%d%d",&l,&r,&t);
				for(j=l-1;j<=r-1;j++){
						a[j]=t;
				}
		}
		for(i=0;i<n;i++)printf("%d\n",a[i]);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&q);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&l,&r,&t);
     ^