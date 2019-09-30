#include <stdio.h>
#define MAX_L 1000000

int is_vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
  int T, t, n, i, count, path;
  long long sum;
  int a[MAX_L];
  char name[MAX_L + 5];

  scanf("%d", &T);
  for(t = 1; t <= T; t++) {
    scanf("%s%d", name, &n);

    a[0] = !is_vowel(name[0]);
    for(i = 1; name[i]; i++) {
      if(is_vowel(name[i])) {
        a[i] = 0;
      } else {
        a[i] = a[i - 1] + 1;
      }
    }

    sum = path = a[0] >= n;
    for(i = 1; name[i]; i++) {
      if(a[i] >= n) {
        path = i - n + 2;
      }
      sum += path;
    }

    printf("Case #%d: %lld\n", t, sum);
  }
  return 0;
}