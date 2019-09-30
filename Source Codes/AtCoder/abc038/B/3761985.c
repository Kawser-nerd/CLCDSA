#include <stdio.h>

int main() {
    int h1, w1, h2, w2;
    int flag = 0;

    scanf("%d %d", &h1, &w1);
    scanf("%d %d", &h2, &w2);

    if (h1 == h2) flag = 1;
    if (h1 == w2) flag = 1;
    if (w1 == h2) flag = 1;
    if (w1 == w2) flag = 1;

    if (flag == 1) printf("YES\n");
    else printf("NO\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &h1, &w1);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &h2, &w2);
     ^