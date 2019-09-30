#include <stdio.h>

int N;
int c[100];

void input() {
    int i;
    scanf("%d", &N);
    for(i=0; i<N; ++i) {
        scanf("%d", &c[i]);
    }
}

void solve() {
    double ans = 0;
    int cnt;
    int i, j;
    for(i=0; i<N; ++i) {
        cnt = 0;
        for(j=0; j<N; ++j) {
            if(i==j) continue;
            if(c[i]%c[j]==0) cnt++;
        }
        if(cnt == 0) ans += 1;
        else ans += (cnt/2+1)/(cnt+1.0);
    }
    printf("%lf\n", ans);
}

int main() {
    input();
    solve();
} ./Main.c: In function ‘input’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &c[i]);
         ^