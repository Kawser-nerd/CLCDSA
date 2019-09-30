#include <stdio.h>
int main (){
int i,a,b,k,s=100000,j;
  scanf ("%d",&k);
  for (i=1;i<k+1;i++){
  for (j=1;j<i+1;j++){
  b=i-j+k-(i*j);
     if (k-(i*j)<0){
    break;
    }
    if (s>b){
    s=b;
    }
  }
  }
  printf ("%d",s);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d",&k);
   ^