#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);

  int a[6]={0};
  for (int i=0; i<N; ++i) {
    double MT, mT;
    scanf("%lf %lf", &MT, &mT);

    if (MT >= 35.0) {
      ++a[0];
    } else if (MT >= 30.0) {
      ++a[1];
    } else if (MT >= 25.0) {
      ++a[2];
    } else if (MT < 0.0) {
      ++a[5];
    }
    if (mT >= 25.0) {
      ++a[3];
    }
    if (MT >= 0.0 && mT < 0.0) {
      ++a[4];
    }
  }

  printf("%d %d %d %d %d %d\n",
         a[0], a[1], a[2], a[3], a[4], a[5]);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf %lf", &MT, &mT);
     ^