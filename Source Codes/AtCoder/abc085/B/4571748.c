#include <stdio.h>

int main(void)
{
	int n;
	
	scanf("%d",&n);
	
	int d[200];
	
	for(int i=0;i<n;i++){
		scanf("%d",&(d[i]));
	}
	
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(d[i]==d[j]){
				d[j]=0;
			}
		}
	}
	
	int count=0;
	
	for(int i=0;i<n;i++){
		if(d[i]!=0){
			count++;
		}
	}
	
	printf("%d\n",count);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&(d[i]));
   ^