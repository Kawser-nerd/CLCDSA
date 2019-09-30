#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define I 2
#define J 3
#define K 4

int cross[4][4] = {
    {1, 2, 3, 4},
    {2, -1, 4, -3},
    {3, -4, -1, 2},
    {4, 3, -2, -1}
};

int signum(int i) {
    return (i >= 0) ? 1 : -1;
}

int main()
{
    int T; scanf("%d", &T);
    for (int test = 0; test < T; test++) {
        int L, X; scanf("%d %d\n", &L, &X);

        char c; int found_i[9] = { 0 }; int found_j[9] = { 0 };
        for (int i = 0; i < 9; i++) found_i[i] = INT_MAX;
        int cur = 1;
        for (int i = 1; i <= L; i++) {
            scanf("%c", &c);
            c = c - 'i' + 2;

            cur = cross[abs(cur) - 1][c - 1] * signum(cur);

            switch (cur) {
                case -K:
                    found_i[4 + -J] = min(found_i[4 + -J], i);
                    found_j[4 + -1] = max(found_j[4 + -1], i);
                    break;

                case -J:
                    found_i[4 + K] = min(found_i[4 + K], i);
                    found_j[4 + -I] = max(found_j[4 + -I], i);
                    break;

                case -I:
                    found_i[4 + -1] = min(found_i[4 + -1], i);
                    found_j[4 + J] = max(found_j[4 + J], i);
                    break;

                case -1:
                    found_i[4 + -I] = min(found_i[4 + -I], i);
                    found_j[4 + -K] = max(found_j[4 + -K], i);
                    break;

                case 1:
                    found_i[4 + I] = min(found_i[4 + I], i);
                    found_j[4 + K] = max(found_j[4 + K], i);
                    break;

                case I:
                    found_i[4 + 1] = min(found_i[4 + 1], i);
                    found_j[4 + -J] = max(found_j[4 + -J], i);
                    break;

                case J:
                    found_i[4 + -K] = min(found_i[4 + -K], i);
                    found_j[4 + I] = max(found_j[4 + I], i);
                    break;

                case K:
                    found_i[4 + J] = min(found_i[4 + J], i);
                    found_j[4 + 1] = max(found_j[4 + 1], i);
                    break;
            }
        }

        int value = cur;
        if (value == 1) goto no;
        else if (value == -1 && !(X % 2)) goto no;
        else if (value != -1 && ((X % 2) || !(X % 4))) goto no;

        int got_i = 0; if (found_i[4 + 1] != INT_MAX) got_i = 1;
        if (found_j[4 + 1] > found_i[4 + 1]) goto yes;

        while (--X) {
            if (got_i && found_j[4 + cur]) goto yes;

            if (found_i[4 + cur] != INT_MAX)
                got_i = 1;

            if (got_i && found_j[4 + cur] > found_i[4 + cur]) goto yes;

            cur = cross[abs(cur) - 1][abs(value) - 1] * signum(cur) * signum(value);
        }

        no:
            printf("Case #%d: NO\n", test + 1); continue;


        yes:
            printf("Case #%d: YES\n", test + 1); continue;
    }

    return 0;
}