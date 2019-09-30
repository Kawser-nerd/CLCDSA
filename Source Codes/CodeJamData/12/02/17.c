#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int T, N, S, p, t, tc, i, c, s;
    scanf("%d", &T);
    for(tc=1; tc<=T; ++tc) {
        scanf("%d %d %d", &N, &S, &p);
        c = s = 0;
        for(i=0; i<N; ++i) {
            scanf("%d", &t);
            if(t >= 3*p-2) {
                ++c;
            } else if(t >= 3*p-4 && t > 0) {
                ++s;
            }
        }
        printf("Case #%d: %d\n", tc, c + (s>S ? S : s));
    }
    return 0;
}

