#include <stdio.h>
#include <string.h>
void main()
{
	int cases;
	int N;
	int i,j;
	int n1;
	int arr[2501];
	scanf("%d",&cases);
	int n = 0;
	while(n<cases)
	{
		n++;
		printf("Case #%d: ",n);
		for(i=0;i<2501;i++)
		{
			arr[i]=0;
		}
		scanf("%d",&N);
		for(i=0;i<2*N-1;i++)
		{
			for(j=0;j<N;j++)
			{
				scanf("%d",&n1);
				arr[n1]++;
			}
		}
		for(i=0;i<2501;i++)
		{
			if(arr[i]%2)
			{
				printf("%d ",i);
			}
		}
		printf("\n");
	}
}
