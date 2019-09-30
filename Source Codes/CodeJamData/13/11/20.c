#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)

int T;
unsigned long long int r, t;

unsigned long long int S(unsigned long long int a, unsigned long long int n){
    unsigned long long int x = (a << 1ULL) + ((n - 1) * 4ULL) >> 1ULL;
    if (x > t) return x;
    double y = log10(x) + log10(n);
    if (y > 18.1) return (t + 1);
    unsigned long long int res = (x * n);
    return res;
}

unsigned long long int F(unsigned long long int n){
    unsigned long long int x = (r << 1ULL) + 1;
    unsigned long long int y = S(x, n);
    return y;
}

int main(){
    int line, i, j;

    scanf("%d", &T);
    for (line = 1; line <= T; line++){
        scanf("%llu %llu", &r, &t);

        unsigned long long int low = 1, high = 2000000000;
        for (; ;){
            if (low == high || (low + 1) == high) break;

            unsigned long long int mid = (low + high) >> 1ULL;
            unsigned long long int x = F(mid);
            if (x <= t) low = mid;
            else high = mid;
        }

        printf("Case #%d: ", line);
        unsigned long long int x = F(low);
        unsigned long long int y = F(high);

        if (y <= t) printf("%llu\n", high);
        else printf("%llu\n", low);
    }
    return 0;
}
