#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  int N,num,cnt=0;
  int nums[100010] = {};
  scanf("%d",&N);
  for(int i=0; i<N; i++) {
    scanf("%d",&num);
    if(nums[num] != 0) cnt++;
    nums[num]++;
  }
  printf("%d\n",cnt);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&num);
     ^