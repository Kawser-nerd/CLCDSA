#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a;
    int b;
} level;

int cmp(const void *a, const void *b)
{
    if (((level *)a)->b != ((level *)b)->b) {
        return ((level *)a)->b - ((level *)b)->b;
    } else {
        return ((level *)a)->a - ((level *)b)->a;
    }
}

int main()
{
    int t, i, j, k;
    level a[1000];
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++) {
        int n, ans = 0, sum = 0;
        int p[1000] = {0};
        
        scanf("%d", &n);
        
        for (j = 0; j < n; j++) scanf("%d %d", &a[j].a, &a[j].b);
        
        qsort(a, n, sizeof(level), cmp);

        while (1) {
            for (j = n - 1; j >= 0; j--) {
                if (p[j] <= 1 && a[j].b <= sum) {
                    ans++;
                    sum += 2 - p[j];
                    
                    p[j] = 2;
                    
                    break;
                }
            }
            
            if (j >= 0) continue;
            
            for (j = n - 1; j >= 0; j--) {
                if (p[j] == 0 && a[j].a <= sum) {
                    ans++;
                    sum++;
                    
                    p[j] = 1;
                    
                    break;
                }
            }
            
            if (j < 0) break;
        }
        
        if (sum < 2 * n) {
            printf("Case #%d: Too Bad\n", i + 1);
        } else {
            printf("Case #%d: %d\n", i + 1, ans);
        }
    }
    
    return 0;
}
