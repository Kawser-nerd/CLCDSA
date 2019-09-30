#include <stdio.h>
int main (){
int s,k,sum;
scanf ("%d",&s);
for (int i=0;i<s;i++){
scanf ("%d",&k);
if (k<3){
  sum=sum+k-1;
}
  else if(k<7){
  sum=sum+k-3;
  }
  else if(k<9){
  sum=sum+k-7;
  }
  else {
  sum=sum+k-9;
  }
}
printf ("%d\n",sum);  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&s);
 ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf ("%d",&k);
 ^