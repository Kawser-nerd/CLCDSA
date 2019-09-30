#include <stdio.h>

int main(void) {
  int A, B;
  if (scanf("%d%d",&A,&B) && B%A) {
    printf("%d",B-A);
  } else {
    printf("%d",A+B);
  }
  return 0;
}