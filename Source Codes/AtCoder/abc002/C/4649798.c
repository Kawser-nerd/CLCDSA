#include <stdio.h>

int abs(int x) {
  return (x < 0) ? -x : x;
}

int main(void) {
  int X[3], Y[3];
  for(int i = 0; i < 3; i++) {
    scanf("%d%d", &X[i], &Y[i]);
  }

  // X[0] -> 0, Y[0] -> 0;
  X[1] -= X[0];
  X[2] -= X[0];
  Y[1] -= Y[0];
  Y[2] -= Y[0];

  // (0,0), (x2, y2), (x3, y3)
  double Tri = abs(X[1] * Y[2] - Y[1] * X[2]) / 2.0;
  printf("%.1f\n", Tri);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &X[i], &Y[i]);
     ^