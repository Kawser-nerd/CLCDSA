#include <stdio.h>
#include <stdlib.h>

float result(long a, long b)
{
}

int check(int i, int j, int** adj)
{
    int l;
    for(l=0;l<10;l++)
    {
        if(adj[i][l]==j)
            return 1;
        else if(adj[i][l]==-1)
            return 0;
    }
    return 0;
}

int main()
{

	int t,n;
	long a,b;
	scanf("%d",&t);
	
	int i,j,k,l;
	float res;
	
	for(j=0;j<t;j++)
	{
	    scanf("%d",&n);
        int **path = (int**)malloc(n*sizeof(int*));
        int** adj = (int**)malloc(n*sizeof(int*));
        
        int t;
        for(i=0;i<n;i++)
        {
            path[i] = (int*)malloc(n*sizeof(int));
            adj[i] = (int*)malloc(10*sizeof(int));
            scanf("%d",&t);
            for(k=0;k<t;k++)
            {
                scanf("%d",&adj[i][k]);
                adj[i][k] = adj[i][k]-1;
            }
            for(k=t;k<10;k++)
                adj[i][k] = -1;
        }
        
        for(i=0;i<n;i++)
        {
            for(k=0;k<n;k++)
            {
                if(check(i,k,adj)==1)
                    path[i][k] = 1;
                else
                    path[i][k] = 0;	    
		    }
		}
		
		int flag = 0;
		
		for(k=0;k<n;k++)
		{
		    for(i=0;i<n;i++)
		    {
		        for(l=0;l<n;l++)
		        {
		            if((path[i][k]==1)&&(path[k][l]==1))
		                path[i][l] = path[i][l]+1;
		            if(path[i][l]>=2)
		            {
		                flag = 1;
		                break;
		            }
		        }
		        if(flag==1)
		            break;
		    }
		    if(flag==1)
		        break;
		}
		
		if(flag==1)             
		    printf("Case #%d: Yes\n",j+1);
		else
		    printf("Case #%d: No\n",j+1);
	}
	
	return 0;
}
