#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
//    freopen("../input2.txt", "r", stdin);

    int N, M, a, b;
    int8_t odd[100000];

    memset(odd, 0, 100000);

    scanf("%d%d", &N, &M);

    for (int i = 0; i < M; i++) {
        scanf("%d%d", &a, &b);
        odd[a - 1] = odd[a - 1] ^ 1;
        odd[b - 1] = odd[b - 1] ^ 1;
        if (a < 1 || a > N || b < 1 || b > N || a == b)
            goto BadEnd;
    }

    short result = 1;
    for (int i = 0; i < N; i++) {
        if (odd[i]) {
            result = 0;
            break;
        }
    }

    if (result)
        printf("YES\n");
    else
        BadEnd:
        printf("NO\n");



    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &N, &M);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &a, &b);
         ^