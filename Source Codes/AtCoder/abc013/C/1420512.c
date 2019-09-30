#include <limits.h>
#include <math.h>
#include <stdio.h>

long n, h, a, b, c, d, e;

int main(void) {
    long i, j, to_eat, max, cost, min_cost = LONG_MAX;
    
    scanf("%ld%ld", &n, &h);
    scanf("%ld%ld%ld%ld%ld", &a, &b, &c, &d, &e);
    
    n -= h / e;
    h %= e;
    b += e;
    d += e;
    
    if (n < 0) {
        printf("0\n");
        return 0;
    }
    
    to_eat = e * n - h + 1;
    max = ceil(to_eat / (double)b);
    
    for (i = 0; i <= max; ++i) {
        if (to_eat - b * i <= 0) {
            j = 0;
        } else {
            j = ceil((to_eat - b * i) / (double)d);
        }
        
        cost = a * i + c * j;
        
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    
    printf("%ld\n", min_cost);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld", &n, &h);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld%ld%ld%ld", &a, &b, &c, &d, &e);
     ^