#include <stdio.h>
#include <string.h>

int N, K;
char S[110];
char cop[110];

void input() {
    scanf("%d%d", &N,&K);
    scanf("%s", S);
    strcpy(cop, S);
}

void swap(int i, int j) {
    char tmp = S[i];
    S[i] = S[j];
    S[j] = tmp;
}

int chNum(int i, int j) {
    return (S[i]==cop[i]) - (S[j]==cop[i]) + (S[j]==cop[j]) - (S[i]==cop[j]);
}

void solve() {
    int i;
    for(i=0; i<N; ++i) {
        int minJ = i;
        int j;
        for(j=i; j<N; ++j) {
            if(S[j] < S[minJ] && (K>1||chNum(i,j)<=1) && (K>0||chNum(i,j)<=0)) {
                minJ = j;
            }
            else if(S[j] == S[minJ] && chNum(i,j) < chNum(i,minJ)) {
                minJ = j;
            }
        }
        K -= chNum(i, minJ);
        swap(i, minJ);
    }
    printf("%s\n", S);
}

int main() {
    input();
    solve();
} ./Main.c: In function ‘input’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &N,&K);
     ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^