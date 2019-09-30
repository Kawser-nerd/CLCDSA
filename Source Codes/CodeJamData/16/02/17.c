
#include <stdio.h>

int main() {
    int cases;
    scanf("%d\n", &cases);
    for (int n = 1; n <= cases; ++n) {
        char line[101];
        scanf("%s\n", line);
        int count = 0;
        char previous = '?';
        char const * ptr = line;
        while (*ptr) {
            if (*ptr != previous) {
                ++count;
                previous = *ptr;
            }
            ++ptr;
        }
        if (ptr[-1] == '+')
            --count;
        printf("Case #%d: %d\n", n, count);
    }
    return 0;
}
