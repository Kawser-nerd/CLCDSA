#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a > b)?(a):(b))

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int n, h;
    int i;
    scanf("%d %d", &n, &h);
    int a[n], b[n];
    for(i=0;i<n;i++) scanf("%d %d", &a[i], &b[i]);
    
    int max_a = 0;
    
    for(i=0;i<n;i++){
        max_a = max(max_a, a[i]);
    }
    
    qsort(b, n, sizeof(int), compare_int);
    
    int sum = 0;
    int count = 0;
    
    for(i=n-1;b[i]>=max_a;i--){
        count += 1;
        sum += b[i];
        if (sum >= h){
            printf("%d", count);
            return 0;
        }
    }
    
    while(sum < h){
        count += 1;
        sum += max_a;
    }
    
    printf("%d", count);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &h);
     ^
./Main.c:16:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i=0;i<n;i++) scanf("%d %d", &a[i], &b[i]);
                      ^