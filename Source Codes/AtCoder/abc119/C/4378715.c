#include <stdio.h>
#include <stdlib.h>

static int N, A, B, C;
static int LEN[8];

int min(int x, int y) {
  return (x < y) ? x : y;
}

int search(int i, int a, int b, int c) {
  if(i == N) {
    int cost = abs(a - A) + abs(b - B) + abs(c - C) - 30;
    if (a == 0 || b == 0 || c == 0) {
      return (int)100000000;
    } else {
      return (int)cost;
    }
  }
  
  int cost1 = search(i+1, a, b, c);
  int cost2 = search(i+1, a+LEN[i], b, c) + 10;
  int cost3 = search(i+1, a, b+LEN[i], c) + 10;
  int cost4 = search(i+1, a, b, c+LEN[i]) + 10;
  return min(min(cost1, cost2), min(cost3, cost4));
}

int main(void) {
  scanf("%d%d%d%d", &N, &A, &B, &C);
  for(int i = 0; i < N; i++) {
    scanf("%d", &LEN[i]);
  }
  printf("%d\n", search(0, 0, 0, 0));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d", &N, &A, &B, &C);
   ^
./Main.c:31:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &LEN[i]);
     ^