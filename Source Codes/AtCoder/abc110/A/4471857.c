#include <stdio.h>

int main()
{
  int no,A,B,C;
  int array[3];
  
  scanf("%d%d%d",&A,&B,&C);
  array[0] = (A < B) ? B : A;
  array[1] = (A > B) ? B : A;
  if (array[0] < C){
    array[2] = array[1];
    array[1] = array[0];
    array[0] = C;
  }else if (array[1] < C){
    array[2] = array[1];
    array[1] = C;
  }else{
    array[2] = C;
  }
  
  printf("%d\n",10*array[0] + array[1] + array[2]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&A,&B,&C);
   ^