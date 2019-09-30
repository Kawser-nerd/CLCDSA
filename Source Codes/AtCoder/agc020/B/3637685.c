#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//?????
	int n;
	int a[100010];
	long long int min,max;
	
	//??????
	int i,j,k,l;
	int flag=0;
	int ans=0;
	int count=0;
	int temp,temp1,temp2;
	//????????
	scanf("%d",&n);
	
	for(i=n-1;i>=0;i--){
		scanf("%d",&a[i]);
	}
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	min=2;
	max=2;
	
	for(i=0;i<n;i++){
		if((min+a[i]-1)/a[i]>max/a[i]){
			printf("-1");
			return 0;
		}
		min=((min+a[i]-1)/a[i])*a[i];
		max=(max/a[i])*a[i]+a[i]-1;
//		printf("min=%lld,max=%lld\n",min,max);
	}
	
	
	
	
//	printf("??????\n");
	//??
	
	printf("%lld %lld",min,max);
	
//	printf("???????\n");
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^