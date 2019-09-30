//http://agc014.contest.atcoder.jp/tasks/agc014_b
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
//    freopen("../input3.txt", "r", stdin);

    int N, M, a, b;
    int odd[200000];

    memset(odd, 0, 800000);

    scanf("%d%d", &N, &M);

    for (int i = 0; i < M; i++) {
       scanf("%d%d", &a, &b);
        odd[a - 1]++;
        odd[b - 1]++;
        if (a < 1 || a > N || b < 1 || b > N || a == b)
            goto BadEnd;
    }

    short result = 1;
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (odd[i] % 2 == 1) {
            result = 0;
            break;
        }
        if (odd[i] > max)
            max = odd[i];
    }

    if (result)
        printf("YES\n");
    else
        BadEnd:
        printf("NO\n");

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &N, &M);
     ^
./Main.c:16:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%d%d", &a, &b);
        ^