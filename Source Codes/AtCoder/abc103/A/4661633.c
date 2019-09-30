#include <stdio.h>
int absolute(int a,int b) {
  if (a < b) {
    return b - a;
  } else {
    return a - b;
  }
}
int main() {
  int A[3];
  scanf("%d %d %d",&A[0],&A[1],&A[2]);
  int ans[6];
  ans[0] = absolute(A[0],A[1]) + absolute(A[1],A[2]);
  ans[1] = absolute(A[0],A[1]) + absolute(A[0],A[2]);
  ans[2] = absolute(A[0],A[2]) + absolute(A[1],A[2]);
  ans[3] = absolute(A[0],A[2]) + absolute(A[1],A[0]);
  ans[4] = absolute(A[1],A[2]) + absolute(A[0],A[2]);
  ans[5] = absolute(A[1],A[2]) + absolute(A[0],A[1]);
  int i;
  int temp = ans[0];
  for (i = 0;i < 5;++i) {
    if (temp > ans[i]) {
      temp = ans[i];
    }
  }
  printf("%d\n",temp);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&A[0],&A[1],&A[2]);
   ^