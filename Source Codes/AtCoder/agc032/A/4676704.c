#include<stdio.h>

int main(){
	int n,i,j,k,b[100];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&b[i]);
	int f=0;
	for(i=0;i<n;i++){
		f+=b[i];
		if(b[i]>i+1){
			puts("-1");
			return 0;
		}
	}
	if(f>n*(n+1)/2){
		puts("-1");
		return 0;
	}
	int ans[100],ansc=0;
	for(i=n-1;i>=0;i--){
		for(k=i;k>=0;k--){
		if(b[k]==k+1){
			ans[ansc++]=b[k];
			for(j=0;j+k+1<=i;j++){
				b[k+j]=b[k+j+1];
			}
			break;
		}
		}
	}
	for(i=n-1;i>=0;i--)printf("%d\n",ans[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d",&b[i]);
                  ^