#include<stdio.h>
int main(void)
{
   int h,w,n,ain[10000]={0},i1,i2,aout[100][100]={0},x=0,y=0;
   scanf("%d",&h);
   scanf("%d",&w);
   scanf("%d",&n);
   for(i1=0;i1<n;i1++){
      scanf("%d",&ain[i1]);
      for(i2=0;i2<ain[i1];i2++){
        if(x>=w) {y++;x--;}
        else if(x<0) {y++;x++;}
        {if(y%2) aout[y][x--]=i1+1;
         else aout[y][x++]=i1+1;
        }
      }
    }
    for(i1=0,i2=0;i1<h;i1++){
        for(i2=0;i2<w;i2++)
            printf("%d ",aout[i1][i2]);
        printf("\n");}
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&h);
    ^
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&w);
    ^
./Main.c:7:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&n);
    ^
./Main.c:9:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&ain[i1]);
       ^