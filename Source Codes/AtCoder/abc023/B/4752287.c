#include <stdio.h>
#include <string.h>
#define sizeN 101
// ??????????
void JudgeString (int N, char S[]) {
    if (N==1 && S[0]=='b') {
        printf("0\n");
        return;
    } else if (N==1 && S[0]!='b') {
        printf("-1\n");
        return;
    }
    // ??
    int n, K, len, mid;
    n = 0;
    K = (N-1)/2;
    len = strlen(S);
    mid = len/2;  // ?????
    int  left = mid-1, right = mid+1;
    while (left >= 0) {
        if (S[mid] == 'b') {
            if (n==0 && (S[left]!='a' || S[right]!='c')) {
                printf("-1\n");
                return;
            }
            if (n==1 &&  (S[left]!='c' || S[right]!='a')) {
                printf("-1\n");
                return;
            }
            if (n==2 && (S[left]!='b' || S[right]!='b')) {
                printf("-1\n");
                return;
            }
            left--; right++;
            n = (n+1)%3;
        } else {
            printf("-1\n");
            return;
        }
    }
    printf("%d\n",K);
}

int main(int argc, char const *argv[]) {
    // ??
    int N;
    char S[sizeN];
    // ??
    scanf("%d", &N);
    scanf("%s", S);
    // ??
    JudgeString(N, S);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:50:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", S);
     ^