#include <stdio.h>

#define MAX_SIZE 1000000

int main(void) {
    int s, i, a[MAX_SIZE];
    int f = 0;
    if (scanf("%3d", &s) != EOF) {
        a[0] = s;
        for (i = 1; i < MAX_SIZE; i++) {
            if (a[i-1] % 2 == 0) {
                a[i] = a[i-1]/2;
            } else {
                a[i] = a[i-1]*3+1;
            }
            for (int j = 0; j < i; j++) {
                if (a[j] == a[i]) {
                    f = 1;
                    break;
                }
            }
            if (f) break;
        }
        printf("%d", i+1);
    }
    return 0;
}