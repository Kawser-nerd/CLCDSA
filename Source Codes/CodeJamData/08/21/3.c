#include <stdio.h>

int N, n, A, B, C, D, x0, y0, M;
int xy[200003][2];
int nxy[3][3];
long long ans;


int main(void) {
    FILE *fin = fopen("A.in", "r");
    FILE *fout = fopen("A.out", "w");
    int i, j, k, tmpx, tmpy;
    
    fscanf(fin, "%d", &N);
    for (i = 1; i <= N; i++) {
        for (j = 0; j < 200003; j++)
            xy[j][0] = xy[j][0] = -1;
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++)
                nxy[j][k] = 0;
        ans = 0;
        fscanf(fin, "%d %d %d %d %d %d %d %d", &n, &A, &B, &C, &D, &x0, &y0, &M);
        for (j = 0; j < n; j++) {
            k = (x0 + y0) % 200003;
            while (xy[k][0] > -1 && (xy[k][0] != x0 || xy[k][1] != y0)) {
                k++;
                k %= 200003;
            }
            if (xy[k][0] == -1) {
                xy[k][0] = x0;
                xy[k][1] = y0;
                tmpx = x0 % 3;
                tmpy = y0 % 3;
            }
            else
                tmpx = 3;
            if (tmpx < 3) {
                nxy[tmpx][tmpy]++;
                if (nxy[tmpx][tmpy] >= 3)
                    ans += (long long) (nxy[tmpx][tmpy]-1) * (nxy[tmpx][tmpy]-2) / 2;
                if (nxy[tmpx][(tmpy+1)%3] >= 1 && nxy[tmpx][(tmpy+2)%3] >= 1)
                    ans += (long long) nxy[tmpx][(tmpy+1)%3] * nxy[tmpx][(tmpy+2)%3];
                if (nxy[(tmpx+1)%3][tmpy] >= 1 && nxy[(tmpx+2)%3][tmpy] >= 1)
                    ans += (long long) nxy[(tmpx+1)%3][tmpy] * nxy[(tmpx+2)%3][tmpy];
                if (nxy[(tmpx+1)%3][(tmpy+1)%3] >= 1 && nxy[(tmpx+2)%3][(tmpy+2)%3] >= 1)
                    ans += (long long) nxy[(tmpx+1)%3][(tmpy+1)%3] * nxy[(tmpx+2)%3][(tmpy+2)%3];
                if (nxy[(tmpx+2)%3][(tmpy+1)%3] >= 1 && nxy[(tmpx+1)%3][(tmpy+2)%3] >= 1)
                    ans += (long long) nxy[(tmpx+2)%3][(tmpy+1)%3] * nxy[(tmpx+1)%3][(tmpy+2)%3];
            }
            x0 = ((long long) A * x0 + B) % M;
            y0 = ((long long) C * y0 + D) % M;
        }
        fprintf(fout, "Case #%d: %I64d\n", i, ans);
    }
    
    return 0;
}
