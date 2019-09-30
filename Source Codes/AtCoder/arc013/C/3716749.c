#include <stdio.h>
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int main()
{
    int N, nim = 0, X[3], XM[2][3], M, tmp;
    scanf("%d", &N);
    REP(_, N)
    {
        scanf("%d %d %d", &X[0], &X[1], &X[2]);
        scanf("%d", &M);
        REP(i, 3) XM[0][i] = 1E9, XM[1][i] = 0;
        REP(_, M) REP(i, 3)
        {
            scanf("%d", &tmp);
            XM[0][i] = tmp < XM[0][i] ? tmp : XM[0][i];
            XM[1][i] = tmp > XM[1][i] ? tmp : XM[1][i];
        }
        REP(i, 3) nim ^= XM[0][i] ^ (X[i] - 1 - XM[1][i]);
    }
    puts(nim ? "WIN" : "LOSE");
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:11:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &X[0], &X[1], &X[2]);
         ^
./Main.c:12:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &M);
         ^
./Main.c:16:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &tmp);
             ^