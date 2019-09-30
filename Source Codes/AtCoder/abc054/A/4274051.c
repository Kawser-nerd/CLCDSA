#include <stdio.h>

int main(void){
  int A,B;
  scanf("%d%d",&A,&B);

  int rank[13] = {12,0,1,2,3,4,5,6,7,8,9,10,11};

  A--; B--;
  if(rank[A] > rank[B]) printf("Alice\n");
  else if(rank[A] < rank[B]) printf("Bob\n");
  else printf("Draw\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&A,&B);
   ^