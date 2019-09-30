#include <stdio.h>
// ?????????
void Judge(int A, int B, int C) {
    int plus = A+B;
    int minus = A-B;
    if ( plus==C && minus==C ) {
        printf("?\n");
    } else if (plus==C && minus!=C) {
        printf("+\n");
    } else if (plus!=C && minus==C) {
        printf("-\n");
    } else {
        printf("!\n");
    }
}
int main(int argc, char const *argv[]) {
    // ??
    int A, B, C;
    // ??
    scanf("%d %d %d", &A, &B, &C);
    // ??
    Judge(A, B, C);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &A, &B, &C);
     ^