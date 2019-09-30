#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *buffer = malloc(1024);
    int T;

    scanf("%d\n", &T);

    for (int t = 0; t < T; ++t) {
        int k;
        scanf("%s %d\n", buffer, &k);

        int len = strlen(buffer); 
        int moves = 0;
        
        for (int i = 0; i <= len - k; ++i) {
            if (buffer[i] == '+') continue;
            ++moves;
            for (int j = 0; j < k; ++j) {
                buffer[i+j] = 88 - buffer[i+j];
            }
        }

        int fail = 0;
        for (int i = 0; i < len; ++i) {
            if (buffer[i] == '-') {
                fail = 1;
                break;
            }
        }
        if (fail)
            printf("Case #%d: IMPOSSIBLE\n", t+1);
        else {
            printf("Case #%d: %d\n", t+1, moves);
        }
    }
    
    return 0;
}
