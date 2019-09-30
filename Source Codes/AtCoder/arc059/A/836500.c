#include<stdio.h>
#include<math.h>
	
	int main()
	{
		int n;
		int A[102];
		int mean1,mean2;
		int sum = 0;
		float m;
		scanf("%d",&n);
		int i;
		for(i=0;i<n;++i)
		{
			scanf("%d",&A[i]);
			sum = sum + A[i];
		}
		
		m = (float)sum/n ;
		mean1 = ceil(m);
		mean2 = floor(m);
		int min1= 0 ,min2 = 0;
		for(i = 0;i<n;++i)
		{
			min1 = min1 + (mean1 - A[i])*(mean1- A[i]);
			min2 = min2 + (mean2 - A[i])*(mean2 - A[i]);
		}
		
		if(min1 > min2)
		{
			printf("%d",min2);
		}
		else
		{
			printf("%d",min1);
		}
		
		
		return 0;
	} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:15:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&A[i]);
    ^