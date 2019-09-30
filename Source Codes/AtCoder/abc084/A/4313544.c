#include <stdio.h>

int main(int argc, char **argv) {
  int m;

  while (scanf("%d", &m) != EOF) {
    printf("%d\n", 48 - m);
  }

  return 0;
}