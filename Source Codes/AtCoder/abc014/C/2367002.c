#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000000

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);

    int *color = (int *) calloc(SIZE + 1, sizeof(int));
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        color[a]++;
        if (b+1 <= SIZE) {
            color[b+1]--;
        }
    }

    int max = 0;
    int tmp = 0;
    for (int i = 0; i <= SIZE; ++i) {
        tmp += color[i];
        if (tmp > max) {
            max = tmp;
        }
    }
    printf("%d\n", max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a, &b);
         ^