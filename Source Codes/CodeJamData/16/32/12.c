#include <stdio.h>
#include <stdlib.h>
int main() {
    int t,i,j,n,b,k,l;
    long long int m;
    long long int sum;
    int p[30];
    int edges[52][52];
    int b2[52];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        printf("Case #%d: ",i+1);
        scanf("%d %lld",&b,&m);
        long long int temp = 1;
        for(j=0;j<b-2;j++)
        {
            temp = temp <<1;
        }
        if(m<=temp)
        {
            printf("POSSIBLE\n");
            for(j=0;j<52;j++)
            {
                for(k=0;k<52;k++)
                {
                    edges[j][k] = 0;
                    //if(k-j==1)edges[j][k]=1;
                }
            }
            long long int temp2 = m;
            j =0;
            while(temp2>0)
            {
                if(temp2%2==1)
                b2[j]=1; 
                else b2[j] = 0;
                temp2 = temp2/2;
                if(b2[j]==1)
                {
                    j = j+1;
                    if((b-1-j)!=0)edges[0][b-1-j] = 1;
                    for(k=b-1-j;k<b;k++)
                    {
                        for(l=b-1-j;l<b;l++)
                        {
                            if(k<l)edges[k][l]=1;
                        }
                    }
                }
                else
                {
                    j = j+1;
                }
            }
            for(j=0;j<b;j++)
            {
                for(k=0;k<b;k++)
                {
                    printf("%d",edges[j][k]);
                }
                printf("\n");
            }
            
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }
	// your code goes here
	return 0;
}
