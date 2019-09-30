#include <stdio.h>
#include <stdlib.h>
typedef struct position
{
    int x;
    int y;
    int h;
}T;
int main()
{
    int n,i,j,k,p=0,ch,h,Cx,Cy,H;
    scanf("%d",&n);
    T a[100];
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].h);
    }
     while(a[p].h==0)p++;
    for(i=0;i<=100;i++)
    {
        for(j=0;j<=100;j++)
        {
            ch=a[p].h+abs(i-a[p].x)+abs(j-a[p].y);
            for(k=0;k<n;k++)
            {
               h=ch-abs(i-a[k].x)-abs(j-a[k].y);
               if(h<0)h=0;
               if(h!=a[k].h)break;
            }

            if(k==n)
            {

                Cx=i;Cy=j;H=ch;printf("%d %d %d",Cx,Cy,H);return 0;
            }
        }

    }return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:16:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].h);
         ^