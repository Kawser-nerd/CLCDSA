#include <stdio.h>

int main() {
    char w[11] = { 0 };

    scanf("%s", w);
    printf("%s%s\n", w, "s");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", w);
     ^