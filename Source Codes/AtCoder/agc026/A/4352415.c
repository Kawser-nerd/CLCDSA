#include <stdio.h>

int main(void)
{
	int n,x[100];
	int count=0;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&(x[i]));
	}
	
	for(int j=0;j<n-1;j++){
		if(x[j]==x[j+1]){
			x[j+1]=n+1;
			count++;
		}
	}
	
	printf("%d\n",count);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&(x[i]));
   ^