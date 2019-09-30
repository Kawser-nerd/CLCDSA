#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int N, a[100000], count = 0, i;

    scanf("%d", &N);
    for(i=0; i<N; i++) {
        scanf("%d", &a[i]);
        while(a[i]%2 == 0) {
            a[i] /= 2;
        }
    }
    qsort(a, N, sizeof(a[0]), compare);
    for(i=1; i<N; i++) {
        if(a[i-1] != a[i]) {
            count++;
        }
    }
    printf("%d\n", count+1);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^