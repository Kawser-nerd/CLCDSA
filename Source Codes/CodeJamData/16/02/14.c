#include <stdio.h>
#include <stdlib.h>

int solve(const char *data)
{
    int y = 0;
    int nn = 0;
    int np = 0;

    for (int i = 0; ; i++) {
        if ((nn > 0) && ((data[i] == '\0') || (data[i] == '+'))) {
            if (np > 0)
                y += 2;
            else
                y += 1;
            nn = 0;
            np = 1;
        }
        if (data[i] == '\0')
            break;
        else if (data[i] == '-')
            nn = 1;
        else if (data[i] == '+')
            np = 1;
    }

    return y;
}

int main() {
    char x[110];
    int n;
    int y;
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%s", x);
        y = solve(x);
        printf("Case #%d: %d\n", i+1, y);
    }
    return 0;
}
