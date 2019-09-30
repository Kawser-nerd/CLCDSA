
#include <stdio.h>

int main() {
    int cases;
    scanf("%d\n", &cases);
    for (int n = 1; n <= cases; ++n) {
        char line[1001];
        scanf("%s\n", line);
        char buffer[3000] = {0};
        char * left = buffer + 1500;
        char * right = left;
        char * remaining = line;
        *--left = *remaining++;
        while (*remaining) {
            if (*left > *remaining)
                *right++ = *remaining;
            else
                *--left = *remaining;
            ++remaining;
        }
        printf("Case #%d: %s\n", n, left);
    }
    return 0;
}
