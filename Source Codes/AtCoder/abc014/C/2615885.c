#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int main(void)
{
    int n, a, b, c[1000001] = {0}, sum = 0, ans = 0, i;
    
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d%d", &a, &b);
        c[a]++, c[b+1]--;
    }
    for(i=1; i<1000001; i++) {
        c[i] += c[i-1];
    }
    
    qsort(c, 1000001, sizeof(c[0]), compare);
    printf("%d\n", c[0]);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &a, &b);
         ^