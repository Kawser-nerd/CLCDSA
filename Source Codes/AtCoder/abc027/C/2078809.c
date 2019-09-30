#include<stdio.h>

// 3 -> ???
// 4 -> ???

int main(void){
  long long num;
  int depth = 0;
  long long x = 1;
  scanf("%lld", &num);
  for(long long n = num; n > 0; n /= 2)
    depth++;
  // printf("%d\n", depth);
  if(depth % 2 == 0){
    int turn = 0;
    while(1){
      if(turn == 0){
        x = x * 2;
        if(x > num){
          printf("Aoki\n");
          break;
        }
        turn++;
      } else {
        x = x * 2 + 1;
        if(x > num){
          printf("Takahashi\n");
          break;
        }
        turn--;
      }
    }
  } else {
    int turn = 0;
    while(1){
      if(turn == 0){
        x = x * 2 + 1;
        if(x > num){
          printf("Aoki\n");
          break;
        }
        turn++;
      } else {
        x = x * 2;
        if(x > num){
          printf("Takahashi\n");
          break;
        }
        turn--;
      }
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &num);
   ^