#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int32_t i32;
typedef int64_t i64;

i64 gcd (i64 a, i64 b) {
  i64 r = a % b;
  while (r > 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int cond (i64 a, i64 b, i64 c, i64 d) {
  if (b > a) return 0;
  if (b > d) return 0;
  if (c >= b) return 1;
  //b <= a, b <= d, c < b
  if (d % b == 0) {
    a -= (a - c + b - 1) / b * b;
    return a >= 0;
  }
  //b <= a, b < d, c < b
  //F(n) = a + (d - b) * m - b * n >= c ?
  i64 g = gcd (b, d);
  return (b - 1) / g == c / g;
}

void run (void) {
  i32 t;
  scanf ("%" SCNi32, &t);
  while (t--) {
    i64 a, b, c, d;
    scanf ("%" SCNi64 "%" SCNi64 "%" SCNi64 "%" SCNi64, &a, &b, &c, &d);
    puts (cond (a, b, c, d) ? "Yes" : "No");
  }
}

int main (void) {
  run ();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf ("%" SCNi32, &t);
   ^
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf ("%" SCNi64 "%" SCNi64 "%" SCNi64 "%" SCNi64, &a, &b, &c, &d);
     ^