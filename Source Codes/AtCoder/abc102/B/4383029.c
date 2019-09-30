#include<stdio.h>

int main(){

   int a,i,max,min,b[100];

   scanf("%d",&a);
   for(i=0;i<a;i++){
      scanf("%d",&b[i]);
   }
   max=b[0];
   min=b[0];

   for(i=0;i<a;i++){
      if(max<b[i]) max=b[i];
      else if (min>b[i]) min=b[i];
   }
   printf("%d",max-min);
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a);
    ^
./Main.c:9:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&b[i]);
       ^