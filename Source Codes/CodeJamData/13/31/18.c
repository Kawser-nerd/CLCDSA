#include <stdio.h>

int main(void)
{
  int T;
  char buffer[1000010];
  long long n, c, t, l;
  int i, cases;
  scanf("%d", &T);
  for (cases=1; cases<=T; ++cases) {
    c = t = l = 0;
    scanf("%s%lld", buffer, &n);
    for (i=0; buffer[i]; ++i) {
      switch (buffer[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        l=0;
        break;
      default:
        ++l;
      }
      if (l < n) {
        t += c;
      } else {
        c = i - n + 2;
        if (c < 0)
          c = 0;
        t += c;
      }
    }
    printf("Case #%d: %lld\n", cases, t);
  }
  return 0;
}
