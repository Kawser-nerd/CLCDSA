#include <stdio.h>
int max(int c[3]){
  int max = c[0];
  int i;
  for(i=1;i<3;i++){
    if(max < c[i]) max = c[i];
    
  }
  return max;
}

int main(void){
  int a, b, c[3], M;
  scanf("%d",&a);
  scanf("%d",&b);
  c[0] = a + b;
  c[1] = a - b;
  c[2] = a * b;
  M = max(c);
  printf("%d\n",M);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b);
   ^