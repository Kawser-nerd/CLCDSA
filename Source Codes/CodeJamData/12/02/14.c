#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
  int tests, i;

  scanf("%d\n", &tests);

  for (int test=1; test<=tests; test++) {
    // input and calculate
    int n, s, p;
    int result = 0;
    scanf("%d %d %d", &n, &s, &p);
    debug("N=%d, S=%d, p=%d, 3*p=%d\n", n, s, p, 3*p);
    if (p <= 10) {
      for (i=0; i<n; i++) {
        int t;
        scanf("%d", &t);
        if (3*p <= t+2) {
          debug("taking %d\n", t);
          result++;
        }
        else if (t > 0 && s > 0 && 3*p <= t+4) {
          debug("taking %d (surprising %d)\n", t, s);
          result++, s--;
        }
        else
          debug("leaving %d\n", t);
      }
    }
    else
      debug("p > 10!\n");      
    // output
    printf("Case #%d: %d\n", test, result);
  }
  return 0;
}
