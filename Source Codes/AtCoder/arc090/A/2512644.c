#include<stdio.h>
     
    int main(){
      int n,a[2][100],i,sum=0,max=0,j;
      scanf("%d",&n);
      for(i=0;i<n;i++)
        scanf("%d",&a[0][i]);
      for(i=0;i<n;i++)
        scanf("%d",&a[1][i]);
      for(i=0;i<n;i++){
        sum=0;
        for(j=0;j<n;j++){
          if(j<=i)
            sum+=a[0][j];
          if(j>=i)
            sum+=a[1][j];
        }
        if(max<sum) max=sum;
      }
      printf("%d\n",max);
    } ./Main.c: In function ‘main’:
./Main.c:5:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&n);
       ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[0][i]);
         ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[1][i]);
         ^