#include <stdio.h>

int T, N, M;
int A[100];
int B[100];

void input() {
    int i;
    scanf("%d%d", &T, &N);
    for(i=0; i<N; ++i) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    for(i=0; i<M; ++i) {
        scanf("%d", &B[i]);
    }
}

void solve() {
    int i, j;
    for(i=0; i<N; ++i) {
        for(j=0; j<M; ++j) {
            if(B[j]>=A[i] && B[j]<=A[i]+T) {
                B[j] = 0;
                break;
            }
        }
    }
    for(int i=0; i<M; ++i) {
        if(B[i] > 0) {
            puts("no");
            return;
        }
    }
    puts("yes");
}

int main() {
    input();
    solve();
} ./Main.c: In function ‘input’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &T, &N);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &A[i]);
         ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &M);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &B[i]);
         ^