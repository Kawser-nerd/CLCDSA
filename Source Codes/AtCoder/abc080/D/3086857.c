#include <stdio.h>
#define MAX_NUM 200000

int main() {
  int N, C;
  int s, t, c;
  
  scanf("%d %d", &N, &C);
  char programList[C][MAX_NUM];

  int i, j;
  for (i=0; i<C; i++) {
    for (j=0; j<MAX_NUM; j++) {
      programList[i][j] = 0;
    }
  }

  for (i=0; i<N; i++) {
    scanf("%d %d %d", &s, &t, &c);
    for (j=(s*2)-1; j<t*2; j++) {
      programList[c-1][j] = 1;
    }
  }
  
  int sum;
  int deckCount = 0;
  for (i=0; i<MAX_NUM; i++) {
    sum = 0;
    for(j=0; j<C; j++) {
      sum += programList[j][i];
    }
    if (sum > deckCount) {
      deckCount = sum;
    }
  }
  
  printf("%d\n", deckCount);
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &C);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &s, &t, &c);
     ^