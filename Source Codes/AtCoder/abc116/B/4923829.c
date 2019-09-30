#include <stdio.h>

int main(){
  int s;
  scanf("%d",&s);
  int count[1000001] = {0};
  int num = 0;
  int a = s;
  while(1){
    num++;
    count[a] += 1;
    if(count[a] > 1) break;
    if(a % 2 == 0) a /= 2;
    else a = 3 * a + 1;
  }
  printf("%d\n",num);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&s);
   ^