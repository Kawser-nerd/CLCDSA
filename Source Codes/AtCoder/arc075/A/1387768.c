#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int sum(int *data, int n) {
    int i;
    int result = 0;
    for (i = 0; i < n; i++) {
        result += data[i];
    }
    return result;
}

int main(void) {
    int n,i;
    int result;
    scanf("%d", &n);
    int a[n];
    for (i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), compare);
    result = sum(a,n);
    if (result % 10 == 0) {
        for (i=0; i<n; i++) {
            if (a[i] % 10 != 0) {
                result -= a[i];
                break;
            }
        }
        if (result == sum(a,n)) {
            result = 0;
        }
    }
    printf("%d\n", result);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:24:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^