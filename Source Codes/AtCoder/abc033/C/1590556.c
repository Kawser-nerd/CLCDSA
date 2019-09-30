#include <stdio.h>
static int c, is_zero, sum;
int main(void) {
    while ((c = getchar()) != EOF)
        if (c == '0')
            is_zero = 1;
        else if (c == '+' || c == '\n')
            if (is_zero)
                is_zero = 0;
            else
                ++sum;
    printf("%d\n", sum);
    return 0;
}