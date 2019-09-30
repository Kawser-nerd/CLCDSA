#include <stdio.h>
#include <math.h>

int main(void) {
  long long int a, b, c, k, sum1, sum2, sum3;
  long long int big;

  big = (long)pow(10.0,18.0);

  scanf("%d %d %d %d", &a, &b, &c, &k);

  if (((a - b) > big) || ((a - b) < -big)) {
    printf("Unfare\n");
    return 1;
  }else if (((b - a) > big) || ((b - a) < -big)) {
    printf("Unfare\n");
    return 1;
  }

  if (k % 2 == 0) {
    printf("%d\n", a - b);
  }else {
    printf("%d\n", b - a);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
   scanf("%d %d %d %d", &a, &b, &c, &k);
         ^
./Main.c:10:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘long long int *’ [-Wformat=]
./Main.c:10:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 4 has type ‘long long int *’ [-Wformat=]
./Main.c:10:9: warning: format ‘%d’ expects argument of type ‘int *’, but argument 5 has type ‘long long int *’ [-Wformat=]
./Main.c:21:12: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
     printf("%d\n", a - b);
            ^
./Main.c:23:12: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
     printf("%d\n", b - a);
            ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result...