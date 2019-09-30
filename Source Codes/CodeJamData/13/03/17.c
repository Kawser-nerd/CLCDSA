#include <stdio.h>

int check(long long x)
{
    int i, j;
    int a[20];
    
    for (i = 0; x > 0; i++) {
        a[i] = x % 10;
        x /= 10;
    }
    
    for (j = 0; j < i / 2; j++) {
        if (a[j] != a[i - j - 1]) return 0;
    }
    
    return 1;
}

int main()
{
    int c = 0, t, i;
    long long a[100];
    
    for (i = 1; i <= 10000000; i++) {
        if (check(i) && check((long long)i * i)) a[c++] = (long long)i * i;
    }
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int sum = 0, j;
        long long x, y;
        
        scanf("%lld %lld", &x, &y);
        
        for (j = 0; j < c; j++) {
            if (a[j] >= x && a[j] <= y) sum++;
        }
        
        printf("Case #%d: %d\n", i + 1, sum);
    }
    
    return 0;
}
