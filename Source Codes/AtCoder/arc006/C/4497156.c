#include <stdio.h>
int main(){
  int N;
  scanf("%d", &N);
  int heya[N];
  int min_num;
  int min;
  for (int i = 0; i < N; i++) {
    heya[i] = 0;
  }

  for (int i = 0; i < N; i++) {
    int new;
    scanf("%d", &new);
    min_num = -1;
    min = -1;
    for (int j = 0; j < N; j++) {
      if (heya[j] == 0) {
        if (min_num != -1) {
          heya[min_num] = new;
          break;
        } else {
          heya[j] = new;
          break;
        }
      } else if (heya[j] >= new) {
        if ((heya[j] - new) < min || min == -1) {
          min_num = j;
          min = heya[j] - new;
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    if (heya[i] == 0) {
      printf("%d", i);
      break;
    }
    if (i == N-1) {
      printf("%d", N);
      break;
    }
  }
  printf("\n");
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &new);
     ^