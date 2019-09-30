#include <stdio.h>

int main(void)
{
	int n,p[100];
	int max=-1;
	int sum=0;
	
	scanf("%d",&n);
	
	int i=0;
	
	while(i<n){
		scanf("%d",&(p[i]));
		
		if(max<p[i]){
			max=p[i];
		}
		
		sum=sum+p[i];
		
		i++;
		
	}
	
	printf("%d\n",sum-max/2);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&(p[i]));
   ^