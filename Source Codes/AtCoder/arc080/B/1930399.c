#include<stdio.h>
int main()
{
    int h,w,n,i,j,k=0,m;
    scanf("%d%d",&h,&w);
    scanf("%d",&n);
    m=h*w;
    int a[n],s[m],t[h][w];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
     m=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<a[i];j++)
          s[m++]=i+1;
    }
    m--;
    for(j=0;j<w;j++)t[0][j]=s[m--];
    if(h>1)
    {
        i=1;
       j--;
    while(j>=0)
    {
        t[i++][j]=s[m--];
        if(i==h)
        {
             if(j==0)break;
            i--;
            j--;
            while(i!=0)
                t[i--][j]=s[m--];
        }
        if(i==0)
        {
            if(j==0)break;
            i++;
            j--;
            t[i++][j]=s[m--];
        }
    }

    }

    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
            printf("%d ",t[i][j]);
        printf("\n");
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&h,&w);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^