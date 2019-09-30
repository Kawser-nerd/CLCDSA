#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

void run (void) {
  const i32 m = 200000;
  char *s = (char *) calloc (m + 1, sizeof (char));
  scanf ("%s", s);
  i64 ans = 0;
  i32 b = 0;
  for (i32 i = 0; s[i] != '\0'; ++i) {
    if (s[i] == 'B') {
      b++;
    } else {
      ans += b;
    }
  }
  printf ("%" PRIi64 "\n", ans);
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%s", s);
   ^