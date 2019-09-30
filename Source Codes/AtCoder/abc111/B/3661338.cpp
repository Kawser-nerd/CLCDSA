#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int l[9] = {111, 222, 333, 444, 555, 666, 777, 888, 999};
    for (int i = 0; i < 9; i++) {
        if (n <= l[i]) {
            printf("%d\n", l[i]);
            return 0;
        }
    }
    return 0;
}