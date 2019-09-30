#include <stdio.h>
int main(void){
    int N, Y;
    if (scanf("%d %d", &N, &Y) == -1) return -1;
    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N - x; y++) {
            int z = N - x - y;
            if (10000 * x + 5000 * y + 1000 * z == Y) {
                printf("%d %d %d\n", x, y, z);
                return 0;
            }
        }
    }
    printf("-1 -1 -1\n");
    return 0;
}