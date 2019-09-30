#include<stdio.h>
#include<string.h>

	int main()
	{
		char A[100001];
		scanf("%s",A);
		int i;
		int n = strlen(A);
		int flag = 0;
		if( n > 2)
		{
		
		for(i=0;i<n-2;++i)
		{
			if( A[i] == A[i+1] || A[i] == A[i+2] || A[i+1] == A[i+2])
			{
				printf("%d %d",i+1,i+3);
				flag = 1;
				break;
			}
			
		}
	       }
	    else
		{
			if( A[0] == A[1])
			{
				printf("1 2");
				flag = 1;
			}
		 } 
	
		if(flag == 0)
		{
			printf("-1 -1");
		}
		return 0;
	} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",A);
   ^