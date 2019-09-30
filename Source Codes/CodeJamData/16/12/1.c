
#include <stdio.h>

int main() {
    int cases;
    scanf("%d\n", &cases);
    for (int n = 1; n <= cases; ++n) {
        int number;
        scanf("%d\n", &number);
        char count[2500] = {0};
        for (int row = 0; row < 2 * number - 1; ++row)
            for (int col = 0; col < number; ++col) {
                int x;
                scanf("%d", &x);
                count[x - 1]++;
            }
        printf("Case #%d:", n);
        for (int col = 0; col < 2500; ++col)
            if (count[col] % 2 == 1)
                printf(" %d", col + 1);
        printf("\n");
    }
    return 0;
}
