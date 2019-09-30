#include <stdio.h>
#include <stdlib.h>
int main() {
    int t,i,j,n,flag,k,j2,flag2;
    long long int sum;
    int p[30];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        printf("Case #%d: ",i+1);
        scanf("%d",&n);
        for(j=0,sum=0;j<n;j++)
        {
            scanf("%d",&p[j]);
            sum = sum+p[j];
        }
        while(sum>0)
        {
            flag = -1;
            flag2=-1;
            for(j=0;j<n;j++)
            {
                p[j]=p[j]-1;sum=sum-1;
                flag=-1;
                for(k=0;k<n;k++)
                {
                    if(p[k]>sum/2)
                    {flag = 1;p[j]++;sum++;
                    break;}
                }
            
                if(flag==1)
                {
                    ;
                }
                else
                {
                    printf("%c ",65+j);break;
                }
            }
            if(flag==1)
            {
                for(j=0;j<n;j++)
                {
                    for(j2=0;j2<n;j2++)
                    {
                        p[j]=p[j]-1;sum=sum-1;
                        p[j2]--;sum--;
                        flag2=-1;
                        for(k=0;k<n;k++)
                        {
                            if(p[k]>sum/2)
                            {flag2 = 1;p[j]++;sum++;p[j2]++;sum++;
                            break;}
                        }
                    
                        if(flag2==1)
                        {
                            ;
                        }
                        else
                        {
                            printf("%c%c ",65+j,65+j2);break;
                        }                
                    }
                    if(flag2==-1)
                    break;
                }
            }
        }
        printf("\n");
    }
	// your code goes here
	return 0;
}
