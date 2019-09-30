#include<stdio.h>
 
 int main(void){
 int n,t[100],i,j,temp;
 scanf("%d",&n);
 for(i=0;i<n;i++){
     scanf("%d",&t[i]);
     }
 for(i=0;i<n;i++){
  for(j=n-1;j>i;j--){
      if(t[j]<t[j-1]){
      temp=t[j-1];
      t[j-1]=t[j];
      t[j]=temp;
      }
     }
   }
   printf("%d\n",t[0]);
   return 0;
 } ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%d",&t[i]);
      ^