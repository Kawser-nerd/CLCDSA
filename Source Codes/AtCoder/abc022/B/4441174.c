#include <stdio.h>
int main(void){
	int n,a,k[100001]={0},i,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(k[a]==1) count++;
		k[a]=1;
	}
	printf("%d\n",count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^