#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
  int a, b, i, len, position, count;
  char s[10];

  while (scanf("%d %d\n%s", &a, &b, s) != EOF) {
    count = 0;
    len = strlen(s);

    if (a + b + 1 != len) {
      puts("No");
      continue;
    }

    for (i = 0; i < len; i++) {
      if (s[i] == '-') {
        count++;
        position = i;
      }
    }
    if (count != 1 || position != a) {
      puts("No");
    } else {
      puts("Yes");
    }
  }

  return 0;
}