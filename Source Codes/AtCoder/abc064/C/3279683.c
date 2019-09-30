#include<stdio.h>
int main()
{
    int num[10]={0};
    int n,a,i,h,j=0,k=0,y;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a);
        if(a>=1 && a<=399)
        {
            num[1]++;
        }
        else if(a>=400 && a<=799)
        {
            num[2]++;
        }
        else if(a>=800 && a<=1199)
        {
            num[3]++;
        }
        else if(a>=1200 && a<=1599)
        {
            num[4]++;
        }
        else if(a>=1600 && a<=1999)
        {
            num[5]++;
        }
        else if(a>=2000 && a<=2399)
        {
            num[6]++;
        }
        else if(a>=2400 && a<=2799)
        {
            num[7]++;
        }
        else if(a>=2800 && a<=3199)
        {
            num[8]++;
        }
        else
        {
            j++;
        }
    }
    for(i=1; i<=8; i++)
    {
        if(num[i]>0)
        {
            k++;
        }
    }
    int x=8-k;
    if(n==1)printf("1 1\n");
    else if(k==0)
    {
        printf("%d %d\n",1,j);

    }
    else if(j==0)
    {

        printf("%d %d\n",k,k);
    }
    else
    {
          printf("%d %d\n",k,k+j);

    }



    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a);
         ^