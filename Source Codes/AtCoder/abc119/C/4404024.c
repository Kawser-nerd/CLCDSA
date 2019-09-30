#include <stdio.h>

int N, A, B, C, i, ans = 0;
int l[8];

int abs(int x) { if( x > 0 ) { return x; } return -x; }

int min3(int a, int b, int c) {
    int ans = a;
    if( ans > b) { ans = b;}
    if( ans > c) { ans = c;}
    return ans;
}

int min4(int a, int b, int c, int d) {
    int ans = a;
    if( ans > b) {ans = b;}
    if( ans > c) {ans = c;}
    if( ans > d) {ans = d;}
    return ans;
}

int dfs(int cur, int a, int b, int c) {
    if(cur == N) {
        if( min3(a, b, c) > 0 ){
            return abs(a-A) + abs(b-B) + abs(c-C) - 30;
        } else {
            return 32767; // int ??????
        }
    }
    int ret0 = dfs(cur + 1, a, b, c);
    int ret1 = dfs(cur + 1, a+l[cur], b, c) + 10;
    int ret2 = dfs(cur + 1, a, b+l[cur], c) + 10;
    int ret3 = dfs(cur + 1, a, b, c+l[cur]) + 10;
    return min4(ret0, ret1, ret2, ret3);
}

int main(void) 
{
    scanf("%d %d %d %d", &N, &A, &B, &C);
    for(i = 0; i < N; ++i){
        scanf("%d", &l[i]);
    }

    printf("%d\n", dfs(0, 0, 0, 0));
    return 0;

} ./Main.c: In function ‘main’:
./Main.c:40:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d", &N, &A, &B, &C);
     ^
./Main.c:42:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &l[i]);
         ^