#include<stdio.h>
int main(){
	int s;
	int f[1000001];
	int i,j,k;
	for(i=0;i<1000001;i++)f[i]=0;
	scanf("%d",&s);
	f[1]=s;
	for(i=2;i<1000001;i++){
		k=f[i-1]%2;
		if( k==0 )f[i]=f[i-1]/2;
		else f[i]=3*f[i-1]+1;
		for(j=i-1;j>0;j--){
			if(f[i]==f[j]){
				printf("%d ",i);
				goto out;
			}
		}
	}
	out:
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&s);
  ^