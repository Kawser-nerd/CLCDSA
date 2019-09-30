#include <stdio.h>

#define N_MAX 12
#define M_MAX 66

int n;
int m;
int adjacent[N_MAX];

void print_binary(int x) {
        int i;
        
        for (i = 8 * sizeof(int) - 1; i >= 0; i--) {
                if (i < N_MAX) {
                        putchar(x >> i & 1 ? '1' : '0');
                }
        }
        
        putchar('\n');
}

void print_adjacent() {
        int i;
        
        for (i = 0; i < N_MAX; i++) {
                print_binary(adjacent[i]);
        }
}

int is_complete(int x) {
        int i;
        
        for (i = 0; i < N_MAX; i++) {
                if ((x >> i & 1) == 0) continue;
                if ((adjacent[i] & x) != x) return 0;
        }
        
        return 1;
}

int get_num_giin(int x) {
        int i, count = 0;
        
        for (i = 8 * sizeof(int) - 1; i >= 0; i--) {
                if (x >> i & 1) count++;
        }
        
        return count;
}

int main(void) {
        int i, xi, yi, max = -1;
        
        scanf("%d%d", &n, &m);
        
        for (i = 0; i < n; i++) {
                adjacent[i] += 1 << i;
        }
        
        for (i = 0; i < m; i++) {
                scanf("%d%d", &xi, &yi);
                xi--;
                yi--;
                adjacent[xi] += 1 << yi;
                adjacent[yi] += 1 << xi;
        }
        
        for (i = 1; i < 0x1000; i++) {
                if (is_complete(i)) {
                        if (get_num_giin(i) > max) max = get_num_giin(i);
                }
        }
        
        printf("%d\n", max);
        return 0;
} ./Main.c: In function ‘main’:
./Main.c:54:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &n, &m);
         ^
./Main.c:61:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%d%d", &xi, &yi);
                 ^