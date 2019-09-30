#include <stdio.h>

int e, r, n;
int a[10000];

long long min(long long a, long long b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

long long max(long long a, long long b)
{
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

long long dfs(int x, int y, long long z, long long w)
{
    int p = 0, q, i;
    long long sum = 0;
    
    if (x >= y) return 0;
    
    for (i = x; i < y; i++) {
        if (a[i] >= p) {
            p = a[i];
            q = i;
        }
    }
    
    sum += (min(e, z + (long long)r * (q - x)) - max(0, w - (long long)r * (y - q))) * p;
    
    sum += dfs(x, q, z, min(e, z + (long long)r * (q - x)));
    sum += dfs(q + 1, y, min(e, max(0, w - (long long)r * (y - q)) + r), w);
    
    return sum;
}

int main()
{
    int t, i;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int j;
        
        scanf("%d %d %d", &e, &r, &n);
        
        for (j = 0; j < n; j++) scanf("%d", &a[j]);
        
        printf("Case #%d: %lld\n", i + 1, dfs(0, n, e, 0));
    }
    
    return 0;
}
