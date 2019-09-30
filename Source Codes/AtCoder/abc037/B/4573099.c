#include <stdio.h>
int main (){
int i,a,b,c,n,k,j;
scanf ("%d%d",&n,&k);
  int s[101]={0};
  for (i=0;i<k;i++){
  scanf ("%d%d%d",&a,&b,&c);
  for (j=a-1;j<b;j++){
  s[j]=c;
  }
  }
  for (i=0;i<n;i++){
  printf ("%d\n",s[i]);
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d%d",&n,&k);
 ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d%d%d",&a,&b,&c);
   ^