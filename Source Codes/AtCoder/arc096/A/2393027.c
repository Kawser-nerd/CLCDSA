#include <stdio.h>
#include <stdlib.h>
void MergeSort(long long int x[ ],long long int left,long long int right);
        long long int temp[200001];
int main (void){
int A,B,C;
int X,Y;
scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);
if(2*C>=A+B){
  printf("%d\n",A*X+B*Y);
}else if(2*C<=A&&2*C<=B){
  if(X>=Y){
    printf("%d\n",C*2*X);
  }else{
    printf("%d\n",C*2*Y);
  }
}else if(2*C<=A||2*C<=B){
  if (2*C<=A) {
    if (X>=Y) {
      printf("%d\n",C*2*X);
    }else{
      printf("%d\n",C*2*X+B*(Y-X));
    }
  }else{
    if (Y>=X) {
      printf("%d\n",C*2*Y);
    }else{
      printf("%d\n",C*2*Y+A*(X-Y));
    }
  }
}else{
  if (X>=Y) {
    printf("%d\n",C*2*Y+A*(X-Y));
  }else{
    printf("%d\n",C*2*X+B*(Y-X));
  }
}
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);
 ^