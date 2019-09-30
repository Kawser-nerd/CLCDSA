#include <stdio.h>

int N, M;

void input() {
    scanf("%d%d", &N, &M);
}

void solve() {
    int n3;
    for(n3=0; n3<=N; ++n3) {
        int x = N - n3;
        int y = M - 3 * n3;
        int n2, n4;
        if(y % 2) continue;
        n2 = 2 * x - y / 2;
        n4 = y / 2 - x;
        if(n2 >= 0 && n4 >= 0) {
           printf("%d %d %d\n", n2, n3, n4); 
           return;
        }
    }
    printf("-1 -1 -1\n");
}

int main() {
    input();
    solve();
} ./Main.c: In function ‘input’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &N, &M);
     ^