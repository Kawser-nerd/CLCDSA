#include<stdio.h>
int main()
{
    int n,i,j,k,l,max,min,b[200];
    while(scanf("%d",&n)!=EOF)
    {
        int count=0;
        int a[10]= {0};
        for(i=0; i<n; i++)
        {
            scanf("%d",&b[i]);
        }
        for(i=0; i<n; i++)
        {
            if(b[i]<=399)
            {
                if(a[0]==0)
                {
                    count++;
                    a[0]++;
                }
            }
            else if(b[i]<=799)
            {
                if(a[1]==0)
                {
                    count++;
                    a[1]++;
                }
            }
            else if(b[i]<=1199)
            {
                if(a[2]==0)
                {
                    count++;
                    a[2]++;
                }
            }
            else if(b[i]<=1599)
            {
                if(a[3]==0)
                {
                    count++;
                    a[3]++;
                }
            }
            else if(b[i]<=1999)
            {
                if(a[4]==0)
                {
                    count++;
                    a[4]++;
                }
            }
            else if(b[i]<=2399)
            {
                if(a[5]==0)
                {
                    count++;
                    a[5]++;
                }
            }
            else if(b[i]<=2799)
            {
                if(a[6]==0)
                {
                    count++;
                    a[6]++;
                }
            }
            else if(b[i]<=3199)
            {
                if(a[7]==0)
                {
                    count++;
                    a[7]++;
                }
            }

        }
        min=count;
        for(i=0; i<n; i++)
        {
            if(b[i]>=3200 && b[i]<=4800)
            {
                count++;
            }
        }
        if(min==0)
        {
            min=1;
        }
        max=count;
        printf("%d %d\n",min,max);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&b[i]);
             ^