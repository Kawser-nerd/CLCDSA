#include <stdio.h>
#include <stdlib.h>

int V(int d[10],int c[10][10]);
int main()
{
    int m, n, i, j, temp, sum=0;
    int a[11]={0},c[10][10],d[10];
    scanf("%d%d",&m,&n);
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&temp);
            a[1+temp]++;
        }
    }
    for(i=0;i<10;i++) d[i]=c[i][1];
    while(V(d,c));
    for(i=0;i<10;i++)
    {
        sum+=a[i+1]*d[i];
    }printf("%d",sum);
    return 0;
}
int V(int d[10],int c[10][10])
{
    int count =0,i,j,temp;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(d[i]>d[j]+c[i][j])
            {
                d[i]=d[j]+c[i][j];
                count++;
            }
        }
    }
    return count;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&m,&n);
     ^
./Main.c:14:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&c[i][j]);
             ^
./Main.c:21:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&temp);
             ^