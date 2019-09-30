#include <stdio.h>
#include <stdlib.h>

int solve(int n)
{
    int nn;
    int nt;
    int s = 0;
    int d;
    if (n == 0) {
        return 0;
    }
    while (s != ((1 << 10) - 1)) {
        nn += n;
        nt = nn;
        while (nt > 0) {
            d = nt % 10;
            s |= 1 << d;
            nt /= 10;
        }
    }
    return nn;
}

int main() {
    int n;
    int x;
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d", &x);
        x = solve(x);
        if (x > 0) {
            printf("Case #%d: %d\n", i+1, x);
        } else {
            printf("Case #%d: INSOMNIA\n", i+1);
        }
    }
    return 0;
}
