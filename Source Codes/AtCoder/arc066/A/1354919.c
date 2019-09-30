#include<stdio.h>
int main(){
	int n,i,a,M=1e9+7,b[100010]={};
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		b[a]++;
	}
	a=1;
	if(n%2)b[0]++;
		for(i=0;i<n;i++){//printf("%d %d %d\n",i,i%2==n%2?0:2,b[i]);
		if((i%2==n%2?0:2)-b[i])break;
		if(i%2)a=(a*2)%M;
	}
	printf("%d\n",i-n?0:a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^