#include <stdio.h>
int main(){
 int f[100];
 int n,i,m=0;
 for(n=99;n>=0;n--)
  f[n]=0;
 scanf("%d",&n);
 n*=2;
 for(;n>0;n--){
  scanf("%d",&i);
  m+=i*f[i-1];
  if(f[i-1]==0)
   f[i-1]=1;
  else
   f[i-1]=0;
 }
 i=0;
 for(n=99;n>=0;n--){
  if(f[n]==1){
   if(i==1){
    m+=(n+1);
    i=0;
   }else{
    i=1;
   }
  }
 }
 printf("%d\n",m);
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&i);
   ^