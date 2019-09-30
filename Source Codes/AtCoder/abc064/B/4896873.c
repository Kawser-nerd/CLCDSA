#include <stdio.h>

int  main(void)
{
	
	int n,a[101];
	int max=-1;
	int min=1001;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&(a[i]));
		
		if(a[i]>max){
			max=a[i];
		}
		
		if(a[i]<min){
			min=a[i];
		}
		
	}
	
	printf("%d\n",max-min);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&(a[i]));
   ^