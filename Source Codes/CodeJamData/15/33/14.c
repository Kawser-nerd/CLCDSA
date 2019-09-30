#include<stdio.h>
int isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a subset of set[0..j-1]
    //  with sum equal to i
    int subset[sum+1][n+1];
 	int i,j;
    // If sum is 0, then answer is true
    for ( i = 0; i <= n; i++)
      subset[0][i] = 1;
 
    // If sum is not 0 and set is empty, then answer is false
    for (i = 1; i <= sum; i++)
      subset[i][0] = 0;
 
     // Fill the subset table in botton up manner
     for ( i = 1; i <= sum; i++)
     {
       for ( j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }
 
    /* // uncomment this code to print table
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     } */
 
     return subset[sum][n];
}
int main()
{
	int i,t,ans,j,c,d,v;
	int count;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d %d %d",&c,&d,&v);
		int arr[100];
		int test[31]={0};
		for(j=0;j<d;j++)
		{
			scanf("%d",&arr[j]);
			test[arr[j]]=1;

		}
		count=d;
		ans=0;
		
		for(j=1;j<=v;j++)
		{
			if(test[j]!=1)
			{
				if(isSubsetSum(arr,count,j)!=1)
				{
					
					arr[count]=j;
					count++;
					ans++;
				}
			}
		}
		//printf("%d",isSubsetSum(arr,count,3));
		printf("Case #%d: %d\n",i,ans);

	}

}
