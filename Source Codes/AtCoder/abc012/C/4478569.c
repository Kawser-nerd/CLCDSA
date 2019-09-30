#include <stdio.h>
// ????????
void Search (int N) {
    int Sum = 0;
    for (size_t i = 1; i <= 9; i++) {
        for (size_t j = 1; j <= 9; j++) {
            Sum += i*j;
        }
    }
    int dif = Sum - N;
    int dan = 1;
    while (dan <= 9) {
        if (dif%dan == 0 && dif/dan<=9) {
            printf("%d x %d\n", dan, dif/dan );
        }
        dan ++;
    }
}

int main(int argc, char const *argv[]) {
    // ??
    int N;
    // ??
    scanf("%d", &N);
    // ??
    Search(N);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^