#include <stdio.h>

int main(void)
{
	int n,k,l[100],no;
	int count=0;
	int sum=0;
	
	scanf("%d%d",&n,&k);
	
	for(int i=0;i<n;i++){
		
		scanf("%d",&(l[i]));
		
	}
	
	
	while(count<k){
		
		int max=-1;
		
		for(int i=0;i<n;i++){
			
			if(max<l[i]){
				max=l[i];
				no=i;
			}
			
		}
		
		count++;
		
		l[no]=-2;
		
		sum=sum+max;
	}
	
	printf("%d\n",sum);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&(l[i]));
   ^