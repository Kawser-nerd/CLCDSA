#include <stdio.h>
#include <limits.h>
#define sizeM 111111
#define min(a, b) (a<b ? a:b)
// ??
int N, M;
long totalScore = 0;
// Imos?
void Imos(int score[]) {
    // ??
    for (size_t i = 0; i < M; i++) {
        score[i+1] += score[i];
    }
    // ??????
    long min = LONG_MAX;
    for (size_t i = 0; i < M; i++) {
        min = min(min, score[i]);
    }
    // ??
    long ans = totalScore - min;
    printf("%ld\n", ans);
}

// ???
int main(int argc, char const *argv[]) {
    int l, r, s, score[sizeM];
    // ??
    scanf("%d %d", &N, &M);
    for (size_t i = 0; i < N; i++) {
        scanf("%d %d %d", &l, &r, &s);
        l --; r--;
        // ????????
        score[l] += s;
        score[r+1] -= s;
        totalScore += s;
    }
    // ??
    Imos(score);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^
./Main.c:30:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &l, &r, &s);
         ^