#include <stdio.h>
#define MAX(A, B) (((A) < (B)) ? (B) : (A))
#define MIN(A, B) (((A) < (B)) ? (A) : (B))
#define ABS(A) (((A) < 0 ) ? (0 - A) : (A))

int main() {
  int p[15] = {2, 3, 5, 7, 11, 13, 17, 19, 
               23, 29, 31, 37, 41, 43, 47};
  int a[15] = {0};
  int q[5] = {73, 23, 13, 3, 1};
  int b[5] = {0};
  int N;
  scanf ("%d", &N);
  int f;
  for (int i=0; i<N; i++) {
    f = i + 1;
    for (int j=0; j<15; j++) {
      while (f != 1 && f % p[j] == 0) {
        f /= p[j];
        a[j]++;
      }
    }
  }
  for (int i=0; i<5; i++) {
    for (int j=0; j<15; j++) 
      if (a[j] > q[i])
        b[i]++;
  }
  int c = 0;
  int d = 0;
  c += b[0];
  c += b[1] * (b[4] - 1);
  c += b[2] * (b[3] - 1);
  c += b[3] * (b[3] - 1) * (b[4] - 2) / 2;
  printf("%d\n", c);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%d", &N);
   ^