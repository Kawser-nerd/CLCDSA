#include <stdio.h>
#include <math.h>

#define LONG_FOR_MIN 6
#define SHORT_FOR_HOUR 30
#define SHORT_FOR_MIN 0.5

int main() {
    int n, m;
    float r;

    scanf("%d%d", &n, &m);

    if (n >= 12) {
        n = n - 12;
    }

    r = fabs((LONG_FOR_MIN * m) - ((SHORT_FOR_HOUR * n) + (SHORT_FOR_MIN * m)));

    if (r > 360 - r) {
        r = 360 - r;
    }

    printf("%f\n", r);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &m);
     ^