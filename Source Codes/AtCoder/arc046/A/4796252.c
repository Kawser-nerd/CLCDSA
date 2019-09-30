#include<stdio.h>

int main(){
	int n,i,k=1,j,num[10]={1};
	scanf("%d",&n);
	for(i=1;i<n;i++){
		int f=0;
		for(j=0;j<k+f;j++){
			num[j]++;
			if(num[j]>9){
				f=1;
				num[j]=1;
			}
		}
		if(f==1)k++;
	}
	for(j=k;j>=0;j--){
		if(num[j]!=0)printf("%d",num[j]);
	}
	puts("");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^